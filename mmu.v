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
    input  wire [31:0]  w_insn_addr, w_data_addr,
    input  wire [31:0]  w_data_wdata,
    input  wire         w_data_we,
    input  wire  [2:0]  w_data_ctrl,
    output wire [31:0]  w_insn_data,
    input  wire [31:0]  w_priv, w_satp, w_mstatus,
    input  wire [63:0]  w_mtime, w_mtimecmp,
    input  wire [31:0]  w_mip,
    output wire [31:0]  w_wmip,
    output wire         w_plic_we,
    output wire         w_proc_busy,
    output wire [31:0]  w_pagefault,
    input  wire  [1:0]  w_tlb_req,
    input  wire         w_tlb_flush,
    input  wire         w_rxd,
    input wire         w_init_done,
    input  wire         mig_clk,
    input  wire         mig_rst_x,
    output wire         o_clk,
    output wire         o_rst_x,
    output wire [31:0]  w_checksum,
`ifdef LAUR_MEM_RB
    output wire [31:0]  w_verify_checksum,
`endif
    input  wire         w_debug_btnd,
    //--------------------------------------------------------------------------------------------//
    input wire          w_tx_ready,
    output wire [31:0]  w_mem_paddr,
    output wire         w_mem_we,
    input wire [31:0]   w_pl_init_data,
    input wire          w_pl_init_we,
    output wire         w_tlb_busy,
    output wire [31:0]  w_dram_addr,
    output wire [31:0]  w_dram_wdata,
    input wire  [31:0]  w_dram_odata,
    output wire         w_dram_we_t,
    input wire          w_dram_busy,
    output wire [2:0]   w_dram_ctrl,
    input wire          w_set_dram_le,
    output wire         w_dram_le
    );

    /***** Address translation ********************************************************************/
    reg  [31:0] physical_addr       = 0;
    reg         page_walk_fail      = 0;

    // Page walk state
    reg  [2:0]  r_pw_state          = 0;

    // Page table entry
    reg  [31:0] L1_pte              = 0;
    reg  [31:0] L0_pte              = 0;

    /***** Other Registers ************************************************************************/
    // Device checker
    reg   [3:0] r_dev               = 0;
    reg   [3:0] r_virt              = 0;
    reg   [31:0] r_mem_paddr        = 0;

    // PLIC
    reg  [31:0] plic_served_irq     = 0;
    reg  [31:0] plic_pending_irq    = 0;
    reg  [31:0] r_plic_odata        = 0;

    // CLINT
    reg  [31:0] r_clint_odata       = 0;

    /***** Micro Controller ***********************************************************************/
    reg   [1:0] r_mc_mode           = 0;
    reg  [31:0] r_mc_qnum           = 0;
    reg  [31:0] r_mc_qsel           = 0;

    reg  [31:0] r_mc_done           = 0;

    /**********************************************************************************************/

    wire [31:0] w_mc_addr;
    wire [31:0] w_mc_wdata;
    wire        w_mc_we;
    wire  [2:0] w_mc_ctrl;
    wire  [1:0] w_mc_aces;

    wire [31:0] w_mem_wdata = (r_mc_mode!=0) ? w_mc_wdata  : w_data_wdata;
    assign        w_mem_we    = (r_mc_mode!=0) ? w_mc_we     : w_data_we;


    /***********************************        Page walk       ***********************************/
    wire        w_iscode        = (w_tlb_req == `ACCESS_CODE);
    wire        w_isread        = (w_tlb_req == `ACCESS_READ);
    wire        w_iswrite       = (w_tlb_req == `ACCESS_WRITE);
    wire [31:0] v_addr          = w_iscode ? w_insn_addr : w_data_addr;

    // Level 1
    wire [31:0] vpn1            = {22'b0, v_addr[31:22]};
    wire [31:0] L1_pte_addr     = {w_satp[19:0], 12'b0} + {vpn1, 2'b0};
    wire  [2:0] L1_xwr          = w_mstatus[19] ? (L1_pte[3:1] | L1_pte[5:3]) : L1_pte[3:1];
    wire [31:0] L1_paddr        = {L1_pte[29:10], 12'h0};
    wire [31:0] L1_p_addr       = {L1_paddr[31:22], v_addr[21:0]};
    wire        L1_write        = !L1_pte[6] || (!L1_pte[7] && w_iswrite);
    wire        L1_success      = !(L1_xwr ==2 || L1_xwr == 6 ||
                                    (w_priv == `PRIV_S && (L1_pte[4] && !w_mstatus[18])) ||
                                    (w_priv == `PRIV_U && !L1_pte[4]) ||
                                    (L1_xwr[w_tlb_req] == 0));

    // Level 0
    wire [31:0] vpn0            = {22'b0, v_addr[21:12]};
    wire [31:0] L0_pte_addr     = {L1_pte[29:10], 12'b0} + {vpn0, 2'b0};
    wire  [2:0] L0_xwr          = w_mstatus[19] ? (L0_pte[3:1] | L0_pte[5:3]) : L0_pte[3:1];
    wire [31:0] L0_paddr        = {L0_pte[29:10], 12'h0};
    wire [31:0] L0_p_addr       = {L0_paddr[31:12], v_addr[11:0]};
    wire        L0_write        = !L0_pte[6] || (!L0_pte[7] && w_iswrite);
    wire        L0_success      = !(L0_xwr ==2 || L0_xwr == 6 ||
                                    (w_priv == `PRIV_S && (L0_pte[4] && !w_mstatus[18])) ||
                                    (w_priv == `PRIV_U && !L0_pte[4]) ||
                                    (L0_xwr[w_tlb_req] == 0));

    // update pte
    wire [31:0] L1_pte_write    = L1_pte | `PTE_A_MASK | (w_iswrite ? `PTE_D_MASK : 0);
    wire [31:0] L0_pte_write    = L0_pte | `PTE_A_MASK | (w_iswrite ? `PTE_D_MASK : 0);
    wire        w_pte_we        = (r_pw_state==5) && (((L1_xwr != 0 && L1_success) && L1_write) ||
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

    // PAGE WALK state
    always@(posedge CLK) begin
        if(r_pw_state == 0) begin
            // PAGE WALK START
            if(!w_dram_busy && w_use_tlb) begin
                // tlb miss
                if(!w_tlb_hit) begin
                    r_pw_state <= 1;
                end
                else begin
                    r_pw_state <= 7;
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
        else if(r_pw_state == 1 && !w_dram_busy) begin
            L1_pte      <= w_dram_odata;
            r_pw_state  <= 2;
        end
        else if(r_pw_state == 2) begin
            r_pw_state  <= 3;
        end
        // Level 0
        else if(r_pw_state == 3 && !w_dram_busy) begin
            L0_pte      <= w_dram_odata;
            r_pw_state  <= 4;
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
            r_pw_state      <= 0;
            physical_addr   <= 0;
            page_walk_fail  <= 0;
        end
        else if(r_pw_state == 7) begin
            r_pw_state <= 0;
            r_tlb_use <= 0;
            //$write("hoge!, %x, %x\n", page_walk_fail, r_tlb_use);
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

    //wire w_tlb_i_use = w_tlb_inst_r_oe && w_iscode;
    //wire w_tlb_r_use = w_tlb_data_r_oe && w_isread;
    //wire w_tlb_w_use = w_tlb_data_w_oe && w_iswrite;
    /*wire [31:0] w_tlb_data_addr = (w_tlb_w_use) ?   {w_tlb_data_w_addr[21:2], w_data_addr[11:0]} :
                                                    {w_tlb_data_r_addr[21:2], w_data_addr[11:0]};*/


    wire [31:0] w_insn_paddr =  (w_priv == `PRIV_M || w_satp[31] == 0) ? w_insn_addr :
                                r_tlb_addr;

    assign w_mem_paddr  =  (r_mc_mode != 0)                        ? w_mc_addr     :
                                (w_priv == `PRIV_M || w_satp[31] == 0)  ? w_data_addr   : r_tlb_addr;
//                                (r_pw_state == 5)                       ? r_tlb_addr    :
//                                (r_tlb_acs)                             ? r_tlb_pte_addr:
//                                                                          w_data_addr;

    wire [2:0]  w_mem_ctrl   =  (r_mc_mode != 0)                        ? w_mc_ctrl         :
                                (w_priv == `PRIV_M || w_satp[31] == 0)  ? w_data_ctrl       :
                                (r_tlb_use[1:0]!=0)                     ? w_data_ctrl       :
                                (r_pw_state == 0)                       ? `FUNCT3_LW____    :
                                (r_pw_state == 2)                       ? `FUNCT3_LW____    :
                                (r_pw_state == 5)                       ? `FUNCT3_SW____    :
                                w_data_ctrl;

    wire  [3:0] w_dev       = w_mem_paddr[31:28];// & 32'hf0000000;
    wire  [3:0] w_virt      = w_mem_paddr[27:24];// & 32'h0f000000;
    wire [27:0] w_offset    = w_mem_paddr & 28'h7ffffff;

    //always@(posedge CLK) w_virt <= w_mem_paddr & 32'h0f000000;

    assign w_dram_wdata         = (r_pw_state == 5) ? w_pte_wdata : w_mem_wdata;
    wire      w_dram_we       = (w_mem_we && !w_tlb_busy
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
                    (w_dram_busy)  ? 0 :
`ifdef LAUR_MEM_RB
                    (w_set_dram_le) ? 1 :
`endif
                    (!w_dram_aces) ? 0 :
                    (r_mc_mode!=0) ? (w_mc_aces==`ACCESS_READ && w_mc_addr[31:28] != 0) :
                    (w_priv == `PRIV_M || w_satp[31] == 0) ? (w_iscode || w_isread) :
                    (r_tlb_use[2:1]!=0) ? 1 :
                    (w_tlb_busy && !w_tlb_hit && (r_pw_state == 0 || r_pw_state==2)) ? 1 : 0;


    /***********************************         Console        ***********************************/
    wire        w_cons_we   = (r_mc_mode != 0) ? (w_mem_we && w_mem_paddr[31:12] == 20'h4000a) :
                            (w_mem_we && !w_tlb_busy && w_dev == `VIRTIO_BASE_TADDR && w_virt == 0);
    wire [31:0] w_cons_data;
    wire [31:0] w_cons_addr = (r_mc_mode != 0) ? w_mem_paddr : {4'b0, w_offset};
    wire        w_cons_req;
    wire [31:0] w_cons_qnum;
    wire [31:0] w_cons_qsel;

    /***********************************           image        ***********************************/
//    wire        w_imag_we       = w_mem_we && r_mc_mode != 0 && w_dram_addr[31:28] == 4'h9;
    wire        w_imag_we       = w_mem_we && r_mc_mode != 0 && w_mem_paddr[31:28] == 4'h9;
    
    /***********************************          VirtIO        ***********************************/
`define LAUR_WRITE_TIME
`ifdef LAUR_WRITE_TIME
    reg [31:0] old_w_mtime=0;
    always @(posedge CLK) begin
	    if(old_w_mtime != w_mtime) begin
		old_w_mtime = w_mtime;
		if(w_mtime % 32'd10000000 == 32'd0) begin
			$write("w_mtime=%d ENABLE_TIMER=%d\n", w_mtime, `ENABLE_TIMER);
		end
	    end
    end
`endif
    /***********************************          VirtIO        ***********************************/

    reg  [31:0] r_mc_arg = 0;
    wire [31:0] w_mc_arg = r_mc_arg;

    wire w_key_req=0;
    wire [31:0] w_cons_irq=0;
    wire        w_cons_irq_oe=0;
    wire [31:0] w_virt_irq      = w_cons_irq;
    wire        w_virt_irq_oe   = w_cons_irq_oe | w_key_req;

`ifdef laur0
    m_RVuc mc(CLK, (r_mc_mode!=0), w_dram_busy, w_mc_addr, w_mc_arg, w_mc_wdata,
                w_mc_we, w_mc_ctrl, w_mc_aces);


    m_console   console(CLK, 1'b1, w_cons_we, w_cons_addr, w_mem_wdata, plic_pending_irq, w_cons_data,
                        w_cons_irq, w_cons_irq_oe, r_mc_mode, w_cons_req, w_cons_qnum, w_cons_qsel, w_key_req);
`endif

    /***********************************           BUSY         ***********************************/
    assign w_tlb_busy = 
                    !(w_use_tlb)                            ? 0 :
                    (r_pw_state == 7)                       ? 0 : 1;
/*                    (r_pw_state != 0)                       ? 1 :
                    ((w_iscode && w_tlb_inst_r_oe) ||
                    (w_isread && w_tlb_data_r_oe)  ||
                    (w_iswrite && w_tlb_data_w_oe))         ? 0 : 1;*/
    
    wire w_mc_busy =    (r_mc_mode != 0) ? 1 : 0;


    assign w_proc_busy = w_tlb_busy || w_mc_busy || w_dram_busy || !w_tx_ready;
    /**********************************************************************************************/

    always@(posedge CLK) begin
        r_dev   <= w_dev;
        r_virt  <= w_virt;
        r_mem_paddr <= w_mem_paddr;
    end
/**************************************************************************************************/
    
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
