// author: Laurentiu-Cristian Duca, date: 2023-05-25
// - removed microcontroller and moved peripheral logic outside
// spdx license identifier MIT
/* Modified by Laurentiu-Cristian Duca, 2021-12-20
 * - LAUR_MEM_RB memory read-back flag after BBL write
 * - SIM_MAIN flag for simulation in XSIM
 * - read_file module instantiation for interactive shell in SIM_MODE
 * - debug mc_mode code under the flag LAUR_SHOW_MC_MODE
 */
/**************************************************************************************************/
/**** RVSoC (Mini Kuroda/RISC-V)                       since 2018-08-07   ArchLab. TokyoTech   ****/
/**** Memory Controller v0.01                                                                  ****/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**************************************************************************************************/
module m_mmu(
    input  wire         CLK, RST_X,
    input wire [31:0] w_hart_id,
    input wire [31:0] w_grant,
    input wire [31:0] w_pc,
    input wire [31:0] w_ir,
    input wire w_tx_ready,
    input  wire [31:0]  w_insn_addr,
    input  wire [31:0]  w_data_addr,
    input  wire [31:0]  w_data_wdata,
    input  wire         w_proc_data_we,
    output  wire         w_data_we,
    output wire         w_data_le,
    input wire  [3:0]   w_data_busy,
    input  wire  [2:0]  w_data_ctrl,
    output wire [31:0]  w_insn_data,
    input  wire [31:0]  w_priv, w_satp, w_mstatus,
    output wire [31:0]  w_pagefault,
    input  wire  [1:0]  w_tlb_req,
    input  wire         w_tlb_flush,
    output wire         w_proc_busy,

    input wire [63:0] w_mtimecmp,
    output wire [63:0] w_wmtimecmp,
    output wire        w_clint_we,
    //--------------------------------------------------------------------------------------------//
    output wire [31:0]  w_mem_paddr,
    output wire         w_tlb_busy,
    output wire [31:0]  w_dram_addr,
    output wire [31:0]  w_dram_wdata,
    input wire  [31:0]  w_dram_odata,
    output wire         w_dram_we_t,
    input wire          w_dram_busy,
    output wire [2:0]   w_dram_ctrl,
    output wire         w_dram_le
    );

    /***** Address translation ********************************************************************/
    reg  [31:0] physical_addr       = 0;
    reg         page_walk_fail      = 0;

    // Page walk state
    reg  [3:0]  r_pw_state          = 0;

    // Page table entry
    reg  [31:0] L1_pte              = 0;
    reg  [31:0] L0_pte              = 0;

    /***** Micro Controller ***********************************************************************/
    reg   [1:0] r_mc_mode           = 0;

    /**********************************************************************************************/

    wire [31:0] w_mc_addr;
    wire [31:0] w_mc_wdata;
    wire        w_mc_we;
    wire  [2:0] w_mc_ctrl;
    wire  [1:0] w_mc_aces;

    wire [31:0] w_mem_wdata = (r_mc_mode!=0) ? w_mc_wdata  : w_data_wdata;


    /***********************************        Page walk       ***********************************/
    wire        w_iscode        = (w_tlb_req == `ACCESS_CODE);
    wire        w_isread        = (w_tlb_req == `ACCESS_READ);
    wire        w_iswrite       = (w_tlb_req == `ACCESS_WRITE);
    wire [31:0] v_addr          = w_iscode ? w_insn_addr : w_data_addr;

    /* 
        mstatus[18]=SUM permit Supervisor User Memory access
        mstatus[19]=MXR
        When MXR=0, only loads from pages marked readable (R=1 in Figure 4.17) will succeed.
        When MXR=1, loads from pages marked either readable or executable (R=1 or X=1) will succeed 
    */

    /* pte
       31 20  19 10  9 8 7 6 5 4 3 2 1 0
       PPN[1] PPN[0] RSW D A G U X W R V
        12     10     2  1 1 1 1 1 1 1 1
    */
    /*  virtual address
        31 22  21 12  11        0
        VPN[1] VPN[0] Page offset
         10     10    12
    */
    /*  physical address
        33 22   21 12 11        0
        PPN[1] PPN[0] Page offset
         12      10   12
    */
    // Level 1
    wire [31:0] vpn1            = {22'b0, v_addr[31:22]};
    wire [31:0] L1_pte_addr     = {w_satp[19:0], 12'b0} + {vpn1, 2'b0};
    wire  [2:0] L1_xwr          = w_mstatus[`MSTATUS_MXR_SHIFT] ? (L1_pte[3:1] | {2'b0, L1_pte[3]}) : L1_pte[3:1];
    wire [31:0] L1_paddr        = {L1_pte[29:10], 12'h0};
    wire [31:0] L1_p_addr       = {L1_paddr[31:22], v_addr[21:0]};
    wire        L1_write        = !L1_pte[6] || (!L1_pte[7] && w_iswrite);
    wire        L1_success      = !(L1_xwr ==2 || L1_xwr == 6 ||
                                    (w_priv == `PRIV_S && (L1_pte[4] && !w_mstatus[`MSTATUS_SUM_SHIFT] && !L1_pte[5])) ||
                                    (w_priv == `PRIV_U && !L1_pte[4] && !L1_pte[5]) ||
                                    (L1_xwr[w_tlb_req] == 0));

    // Level 0
    wire [31:0] vpn0            = {22'b0, v_addr[21:12]};
    wire [31:0] L0_pte_addr     = {L1_pte[29:10], 12'b0} + {vpn0, 2'b0};
    wire  [2:0] L0_xwr          = w_mstatus[`MSTATUS_MXR_SHIFT] ? (L0_pte[3:1] | {2'b0, L0_pte[3]}) : L0_pte[3:1];
    wire [31:0] L0_paddr        = {L0_pte[29:10], 12'h0};
    wire [31:0] L0_p_addr       = {L0_paddr[31:12], v_addr[11:0]};
    wire        L0_write        = !L0_pte[6] || (!L0_pte[7] && w_iswrite);
    wire        L0_success      = !(L0_xwr ==2 || L0_xwr == 6 ||
                                    (w_priv == `PRIV_S && (L0_pte[4] && !w_mstatus[`MSTATUS_SUM_SHIFT]) && !L0_pte[5]) ||
                                    (w_priv == `PRIV_U && !L0_pte[4] && !L0_pte[5]) ||
                                    (L0_xwr[w_tlb_req] == 0));

    // update pte
    wire [31:0] L1_pte_write    = L1_pte | `PTE_A_MASK | (w_iswrite ? `PTE_D_MASK : 0);
    wire [31:0] L0_pte_write    = L0_pte | `PTE_A_MASK | (w_iswrite ? `PTE_D_MASK : 0);
    wire        w_pte_we        = (r_pw_state==5) && !page_walk_fail && 
                                        (((L1_xwr != 0 && L1_success) && L1_write) ||
                                         ((L0_xwr != 0 && L0_success) && L0_write));
    wire [31:0] w_pte_waddr     = (L1_xwr != 0 && L1_success) ? L1_pte_addr : L0_pte_addr;
    wire [31:0] w_pte_wdata     = (L1_xwr != 0 && L1_success) ? L1_pte_write : L0_pte_write;

    assign w_pagefault          = !page_walk_fail ? ~32'h0 : (w_iscode) ? `CAUSE_FETCH_PAGE_FAULT :
                                    (w_isread) ? `CAUSE_LOAD_PAGE_FAULT : `CAUSE_STORE_PAGE_FAULT;

    reg  [31:0] r_tlb_addr = 0;
    reg   [2:0] r_tlb_use  = 0;
    wire [21:0] w_tlb_inst_r_addr, w_tlb_data_r_addr, w_tlb_data_w_addr;
    wire        w_tlb_inst_r_oe, w_tlb_data_r_oe, w_tlb_data_w_oe;
    wire        w_use_tlb = (r_mc_mode==0 && (w_iscode || w_isread || w_iswrite)
                                          && (!(w_priv == `PRIV_M || w_satp[31] == 0)));
    wire        w_tlb_hit = ((w_iscode && w_tlb_inst_r_oe) ||
                            (w_isread && w_tlb_data_r_oe)  ||
                            (w_iswrite && w_tlb_data_w_oe));

    reg r_dram_was_busy=0, r_dram_took_cmd=0, r_data_was_busy=0;

    // PAGE WALK state
    always@(posedge CLK) begin
        if(r_pw_state == 0) begin
            // PAGE WALK START
            if(!w_dram_busy && w_use_tlb) begin
                // tlb miss
                if(!w_tlb_hit) begin
                        r_pw_state <= 1;
                        r_dram_was_busy <= 0;
                end
                else begin
                    r_pw_state <= 6;
                    case ({w_iscode, w_isread, w_iswrite})
                        3'b100 : r_tlb_addr <= {w_tlb_inst_r_addr[21:2], w_insn_addr[11:0]};
                        3'b010 : r_tlb_addr <= {w_tlb_data_r_addr[21:2], w_data_addr[11:0]};
                        3'b001 : r_tlb_addr <= {w_tlb_data_w_addr[21:2], w_data_addr[11:0]};
                        default: r_tlb_addr <= 0;
                    endcase
                    r_tlb_use <= {w_iscode, w_isread, w_iswrite};
                end
            end
        end
        // Level 1
        else if(r_pw_state == 1) begin
            if(r_dram_was_busy && !w_dram_busy) begin
                L1_pte      <= w_dram_odata;
                r_pw_state  <= 2;
                r_dram_was_busy <= 0;
            end else if(w_dram_busy)
                r_dram_was_busy <= 1;
        end
        else if(r_pw_state == 2) begin
            if(w_dram_busy && !(w_priv == `PRIV_M || w_satp[31] == 0)) begin
                $display("dram_busy in pw_state 2");
            end
            if(!w_dram_busy) begin
                r_pw_state <= 3;
                r_dram_was_busy <= 0;
            end
        end
        // Level 0
        else if(r_pw_state == 3) begin
            if(r_dram_was_busy && !w_dram_busy) begin
                L0_pte      <= w_dram_odata;
                r_pw_state  <= 4;
                r_dram_was_busy <= 0;
            end else if(w_dram_busy)
                r_dram_was_busy <= 1;
        end
        // Success?
        else if(r_pw_state == 4) begin
            if(!L1_pte[0]) begin
                physical_addr   <= 0;
                page_walk_fail  <= 1;
            end
            else if(L1_xwr) begin
                physical_addr   <= (L1_success) ? L1_p_addr : 0;
                page_walk_fail  <= (L1_success) ? 0 : 1;
            end
            else if(!L0_pte[0]) begin
                physical_addr   <= 0;
                page_walk_fail  <= 1;
            end
            else if(L0_xwr) begin
                physical_addr   <= (L0_success) ? L0_p_addr : 0;
                page_walk_fail  <= (L0_success) ? 0 : 1;
            end
            r_pw_state  <= 5;
        end
        // Update pte
        else if(r_pw_state == 5) begin
                if(page_walk_fail || !w_pte_we || !w_dram_busy) begin
                    r_pw_state      <= 0;
                    physical_addr   <= 0;
                    page_walk_fail  <= 0;
                    if(r_dram_was_busy) begin
                        $display("---- !dram_busy in pw_state 5");
                        r_dram_was_busy <= 0;
                    end
                    if(page_walk_fail) begin
                        $display("~ fault=%x ia=%x da=%x vaddr=%x grant=%x pc=%x ir=%x", 
                            w_pagefault, w_insn_addr, w_data_addr, v_addr, w_grant, w_pc, w_ir);
                        if(w_pte_we) begin
                            $display("-----pte-we in pagefault-----");
                            //$finish;
                        end
                    end
                end else
                if(w_dram_busy && !(w_priv == `PRIV_M || w_satp[31] == 0)) begin
                    $display("dram_busy in pw_state 5");
                    r_dram_was_busy <= 1;
                end
        end
        else if(r_pw_state == 6) begin
            if(w_dram_aces && (w_dram_le || w_dram_we)) begin
                if(w_dram_busy) begin
                    r_pw_state <= 7;
                    r_tlb_use <= 0;
                    r_dram_took_cmd <= 1;
                end
            end else if(w_data_le || w_data_we) begin
                if(w_data_busy) begin
                    r_pw_state <= 7;
                    r_tlb_use <= 0;
                    r_data_was_busy <= 1;
                end
            end else begin
                $display("mmu state 6 and nothing to do");
                $finish();
            end
        end
        else if(r_pw_state == 7 && 
                ((!w_dram_busy && r_dram_took_cmd) || 
                (r_data_was_busy && w_data_busy==0))) begin
            r_pw_state <= 0;
            r_tlb_use <= 0;
            r_dram_took_cmd <= 0;
            r_data_was_busy <= 0;
        end
    end
    
    /***********************************           TLB          ***********************************/
    wire        w_tlb_inst_r_we   = (r_pw_state == 5 && !page_walk_fail && w_iscode);
    wire        w_tlb_data_r_we   = (r_pw_state == 5 && !page_walk_fail && w_isread);
    wire        w_tlb_data_w_we   = (r_pw_state == 5 && !page_walk_fail && w_iswrite);
    wire [21:0] w_tlb_wdata       = {physical_addr[31:12], 2'b0};

    m_tlb#(20, 22, `TLB_SIZE) TLB_inst_r (CLK, 1'b1, w_tlb_flush, w_tlb_inst_r_we,
                                            w_insn_addr[31:12], w_insn_addr[31:12], w_tlb_wdata,
                                            w_tlb_inst_r_addr, w_tlb_inst_r_oe);

    m_tlb#(20, 22, `TLB_SIZE) TLB_data_r (CLK, 1'b1, w_tlb_flush, w_tlb_data_r_we,
                                            w_data_addr[31:12], w_data_addr[31:12], w_tlb_wdata,
                                            w_tlb_data_r_addr, w_tlb_data_r_oe);

    m_tlb#(20, 22, `TLB_SIZE) TLB_data_w (CLK, 1'b1, w_tlb_flush, w_tlb_data_w_we,
                                            w_data_addr[31:12], w_data_addr[31:12], w_tlb_wdata,
                                            w_tlb_data_w_addr, w_tlb_data_w_oe);

    /***********************************          Memory        ***********************************/
    reg  [31:0] r_tlb_pte_addr = 0;
    reg         r_tlb_acs = 0;
    always@(*)begin
        case (r_pw_state)
            0:      begin r_tlb_pte_addr <= L1_pte_addr;    r_tlb_acs = 1; end
            2:      begin r_tlb_pte_addr <= L0_pte_addr;    r_tlb_acs = 1; end
            5:      begin r_tlb_pte_addr <= w_pte_waddr;    r_tlb_acs = 1; end
            default:begin r_tlb_pte_addr <= 0;              r_tlb_acs = 0; end
        endcase
    end

    wire [31:0] w_insn_paddr =  (w_priv == `PRIV_M || w_satp[31] == 0) ? w_insn_addr :
                                r_tlb_addr;

    assign w_mem_paddr  =  (r_mc_mode != 0)                        ? w_mc_addr     :
                                (w_priv == `PRIV_M || w_satp[31] == 0)  ? w_data_addr   : r_tlb_addr;

    wire [2:0]  w_mem_ctrl   =  (r_mc_mode != 0)                        ? w_mc_ctrl         :
                                (w_priv == `PRIV_M || w_satp[31] == 0)  ? w_data_ctrl       :
                                (r_tlb_use[1:0]!=0)                     ? w_data_ctrl       :
                                (r_pw_state == 0)                       ? `FUNCT3_LW____    :
                                (r_pw_state == 2)                       ? `FUNCT3_LW____    :
                                (r_pw_state == 5)                       ? `FUNCT3_SW____    :
                                w_data_ctrl;

    wire  [3:0] w_dev       = w_mem_paddr[31:28];// & 32'hf0000000;
    wire  [3:0] w_virt      = w_mem_paddr[27:24];// & 32'h0f000000;
    wire [27:0] w_offset    = w_mem_paddr & 32'h7ffffff;

    assign w_dram_wdata         = (r_pw_state == 5) ? w_pte_wdata : w_mem_wdata;
    
    wire      w_dram_we       = (w_proc_data_we && !w_tlb_busy
                                    && (w_dev == `MEM_BASE_TADDR || w_dev == 0));

    assign w_dram_addr          =   (r_mc_mode!=0)              ? w_mc_addr         :
                                (w_iscode && !w_tlb_busy)   ? w_insn_paddr      :
                                (w_priv == `PRIV_M || w_satp[31] == 0) ? w_data_addr :
                                (r_tlb_acs && !w_tlb_hit)   ? r_tlb_pte_addr    : w_mem_paddr;

    assign          w_dram_ctrl =   (r_mc_mode!=0)              ? (w_mem_ctrl)      :
                                (w_iscode && !w_tlb_busy)   ? `FUNCT3_LW____    : w_mem_ctrl;
    assign      w_insn_data =   w_dram_odata;

    wire        w_dram_aces = (w_dram_addr[31:28] == 8 || w_dram_addr[31:28] == 0 || w_dram_addr[31:28] == 9);

    assign        w_dram_le   =
                    //(w_dram_busy)  ? 0 :
                    (!w_dram_aces) ? 0 :
                    (r_mc_mode!=0) ? (w_mc_aces==`ACCESS_READ && w_mc_addr[31:28] != 0) :
                    (w_priv == `PRIV_M || w_satp[31] == 0) ? (w_iscode || w_isread) :
                    (r_tlb_use[2:1]!=0 && !w_tlb_busy) ? 1 :
                    (w_tlb_busy && !w_tlb_hit && (r_pw_state == 0 || r_pw_state==2)) ? 1 : 0;

    
    assign      w_data_le = w_isread && !w_tlb_busy && !w_dram_aces;
    assign      w_data_we = (w_iswrite || w_proc_data_we) && !w_tlb_busy && !w_dram_aces;

    /***********************************           BUSY         ***********************************/
    assign w_tlb_busy = 
                    !(w_use_tlb)                            ? 0 :
                    (r_pw_state == 6)                       ? 0 : 1;

    assign w_dram_we_t =   w_pte_we || w_dram_we;

    //assign w_proc_busy = w_tlb_busy || w_dram_busy;
    assign w_proc_busy = (w_use_tlb && (r_pw_state < 7)) || w_dram_busy || (w_data_busy) || !w_tx_ready;
    /**************************************************************************************************/
    
    assign w_wmtimecmp  = (w_dev == `CLINT_BASE_TADDR && (w_offset==28'h4000 && w_hart_id == 0) && w_proc_data_we) ?
                                {w_mtimecmp[63:32], w_data_wdata} :
                           (w_dev == `CLINT_BASE_TADDR && (w_offset==28'h4004 && w_hart_id == 0) && w_proc_data_we) ?
                                {w_data_wdata, w_mtimecmp[31:0]} : 
                           (w_dev == `CLINT_BASE_TADDR && (w_offset==28'h4008 && w_hart_id == 1) && w_proc_data_we) ?
                                {w_mtimecmp[63:32], w_data_wdata} :
                           (w_dev == `CLINT_BASE_TADDR && (w_offset==28'h400c && w_hart_id == 1) && w_proc_data_we) ?
                                {w_data_wdata, w_mtimecmp[31:0]} : 0;
    assign w_clint_we   = ((w_dev == `CLINT_BASE_TADDR) && w_proc_data_we && 
                           ((w_offset==28'h4000 || w_offset==28'h4004) && (w_hart_id == 0))) ||
                           ((w_dev == `CLINT_BASE_TADDR) && w_proc_data_we && 
                           ((w_offset==28'h4008 || w_offset==28'h400c) && (w_hart_id == 1)));

    always @(posedge CLK)
        if(w_dev == `CLINT_BASE_TADDR && w_offset[27:4]==24'h400) begin
            $display("core%1x w_data_wdata=%x sets wmtimecmp=%0d w_offset=%x w_proc_data_we=%x w_iswrite=%x, w_clint_we%x w_use_tlb=%1x w_proc_busy=%x r_pw_state=%x", 
                w_hart_id, w_data_wdata, w_wmtimecmp, w_offset, w_proc_data_we, w_iswrite, w_clint_we, w_use_tlb, w_proc_busy, r_pw_state);
        end

endmodule
/**************************************************************************************************/
/*** Simple Direct Mapped Cache for TLB                                                         ***/
/**************************************************************************************************/
module m_tlb#(parameter ADDR_WIDTH = 20, D_WIDTH = 20, ENTRY = 4)
            (CLK, RST_X, w_flush, w_we, w_waddr, w_raddr, w_idata, w_odata, w_oe);
    input  wire                     CLK, RST_X;
    input  wire                     w_flush, w_we;
    input  wire [ADDR_WIDTH-1:0]    w_waddr, w_raddr;
    input  wire    [D_WIDTH-1:0]    w_idata;
    output wire    [D_WIDTH-1:0]    w_odata;
    output wire                     w_oe;             //output enable

    reg                               [ENTRY-1:0]   r_valid = 0;
    reg  [(ADDR_WIDTH-$clog2(ENTRY)+D_WIDTH)-1:0]   mem [0:ENTRY-1];
    integer i;
    initial for(i=0; i<ENTRY; i=i+1) mem[i] = 0;

    // READ
    wire              [$clog2(ENTRY)-1:0]   w_ridx;
    wire [(ADDR_WIDTH-$clog2(ENTRY))-1:0]   w_rtag;
    assign {w_rtag, w_ridx} = w_raddr;

    wire w_tagmatch = (mem[w_ridx][(ADDR_WIDTH-$clog2(ENTRY)+D_WIDTH)-1:D_WIDTH] == w_rtag);

    assign w_odata  = mem[w_ridx][D_WIDTH-1:0];
    assign w_oe     = (w_tagmatch && r_valid[w_ridx]);

    // WRITE
    wire              [$clog2(ENTRY)-1:0]   w_widx;
    wire [(ADDR_WIDTH-$clog2(ENTRY))-1:0]   w_wtag;
    assign {w_wtag, w_widx} = w_waddr;

    always  @(posedge  CLK)  begin
        // FLUSH
        if (!RST_X || w_flush) begin
            r_valid <= 0;
        end
        if (w_we) begin
            mem[w_widx] <= {w_wtag, w_idata};
            r_valid[w_widx] <= 1;
        end
    end
endmodule // m_tlb

/**************************************************************************************************/
