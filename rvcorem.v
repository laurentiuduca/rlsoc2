// modified: Laurentiu-Cristian Duca, date: 20240322
// spdx license identifier MIT


/**************************************************************************************************/
/**** RVSoC                                            since 2018-08-07   ArchLab. TokyoTech   ****/
/**** The Processor v0.01                                                                      ****/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/***** 2 read 1 write port, register file                                                     *****/
/**************************************************************************************************/
module m_regfile (CLK, w_rs1, w_rs2, w_rdata1, w_rdata2, w_we, rd, w_wdata, w_hart_id, w_a0);
    input  wire        CLK;
    input  wire [ 4:0] w_rs1, w_rs2;
    output wire [31:0] w_rdata1, w_rdata2;
    input  wire        w_we;
    input  wire [ 4:0] rd;
    input  wire [31:0] w_wdata;
    input  wire [31:0] w_hart_id;
    output wire [31:0] w_a0;

    reg [31:0] mem [0:31];

    assign w_rdata1 = (w_rs1 == 0) ? 0 : mem[w_rs1];
    assign w_rdata2 = (w_rs2 == 0) ? 0 : mem[w_rs2];

    always @(posedge CLK) begin
        if(w_we) begin
            if(rd!=0) mem[rd] <= w_wdata;
        end
    end

    assign w_a0 = mem[10];

    integer i;
    initial begin
        for(i=0; i<32; i=i+1) mem[i] = 0;
        `ifdef NUTTX_FLAT
        mem[10] = w_hart_id;
        `else
        `ifdef LINUX
        mem[10] = w_hart_id;
        //mem[11] = `D_INITD_ADDR + `D_START_PC;
	    mem[11] = `D_INITD_ADDR;
        `endif
        `endif
    end
endmodule
/**************************************************************************************************/

/***** main processor                                                                         *****/
/**************************************************************************************************/
module m_RVCoreM(CLK, RST_X, w_stall, w_hart_id, w_ipi, r_halt, w_insn_addr, w_data_addr, w_insn_data, w_data_data,
                w_data_wdata, w_data_we, w_data_ctrl, w_priv, w_satp, w_mstatus, w_mtime,
                w_mtimecmp, w_wmtimecmp, w_clint_we, w_mip, w_plic_we, w_busy, w_pagefault,
                w_tlb_req, w_tlb_flush, w_core_pc, w_core_ir, w_core_odata, w_init_stage, state, pc, r_ir,
                reserved, load_res, hart_sc, w_oh_reserved, w_oh_load_res, w_oh_sc, w_oh_pc, w_grant, r_ipi_taken, r_extint_taken,
                w_a0);
    input  wire         CLK, RST_X, w_stall;
    input  wire [31:0] w_ipi;
    input  wire [31:0]  w_hart_id;
    input  wire [31:0]  w_insn_data, w_data_data;
    input  wire [63:0]  w_wmtimecmp;
    input  wire         w_clint_we;
    input  wire         w_plic_we;
    input  wire         w_busy;
    input  wire [31:0]  w_pagefault;

    output reg          r_halt;         // register, set if the processor is halted
    output wire [31:0]  w_core_odata;   // constant 0
    output wire [31:0]  w_data_wdata;   // from r_data_wdata
    output wire [31:0]  w_insn_addr;    // from r_insn_addr
    output wire [2:0]   w_data_ctrl;    // from r_data_ctrl
    output wire [31:0]  w_data_addr;    // from r_mem_addr
    input wire [63:0]  w_mtime;        
    output wire [63:0]  w_mtimecmp;     // from register mtimecmp
    output wire [31:0]  w_priv;         // from register priv
    output wire [31:0]  w_satp;         // from register satp
    output wire [31:0]  w_mstatus;      // from register mstatus
    output wire [31:0]  w_mip;          // from register mip
    output wire [31:0]  w_core_pc;      // from register pc
    output wire [31:0]  w_core_ir;      // from r_ir
    output wire         w_init_stage;   // from r_init_stage
    output wire  [1:0]  w_tlb_req;      // from r_tlb_req
    output wire         w_data_we;      // from r_data_we, write enable for DRAM memory
    output wire         w_tlb_flush;    // from r_tlb_flush

    output wire [31:0]  w_a0;

    /***** registers and CPU architecture state ***************************************************/
    output reg   [3:0] state   = 0;            // State for Multi cycle Processor
    output reg  [31:0] pc             = `D_START_PC;  // Program Counter

    reg  [31:0] mstatus        = 0;            ///// CSRs
    reg  [31:0] mtvec          = 0;            //
    reg  [31:0] mscratch       = 0;            //
    reg  [31:0] mepc           = 0;            //
    reg  [31:0] mcause         = 0;            //
    reg  [31:0] mtval          = 0;            //
    wire  [31:0] mhartid        = w_hart_id;            //
    reg  [31:0] misa           = 32'h00141105; // RV32acim, Machine ISA register (MISA)
    reg  [31:0] mie            = 0;            //
    reg  [31:0] mip            = 0;            //
    reg  [31:0] medeleg        = 0;            //
    reg  [31:0] mideleg        = 0;            //
    reg  [31:0] mcounteren     = 0;            //
    reg  [31:0] stvec          = 0;            //
    reg  [31:0] sscratch       = 0;            //
    reg  [31:0] sepc           = 0;            //
    reg  [31:0] scause         = 0;            //
    reg  [31:0] stval          = 0;            //
    reg  [31:0] satp           = 0;            //
    reg  [31:0] scounteren     = 0;            //
    
    output reg  [31:0] load_res= 0;            // For aomic LR/SC
    output reg  reserved       = 0;            // For aomic LR/SC
    output wire hart_sc           ;
    input wire w_oh_reserved, w_oh_sc;
    input wire [31:0] w_oh_load_res;
    input wire [31:0] w_oh_pc;
    input wire [31:0] w_grant;
    assign hart_sc = r_op_AMO_SC;

    reg   [1:0] priv           = `PRIV_M;      // Mode
    //reg  [63:0] w_mtime          = 1;            // w_mtime
    reg  [63:0] mtimecmp       = 64'hffffffff_ffffffff; 
    reg  [3:0] r_was_clint_we  = 0;
    reg  [31:0] pending_tval   = 0;            //
    reg  [31:0] pending_exception = ~0;        //

    /***** CPU Stage registers ********************************************************************/
    reg  [31:0] r_cpc          = 0;            // IF: current PC, the program counter of this insn
    reg  [31:0] r_ir_org       = 0;            // IF: NOTE! not used

    reg         r_cinsn        = 0;            // CV: set if the fetched insn is a compressed one
    output reg  [31:0] r_ir    = 0;            // CV: 32-bit fetched insn
    reg  [15:0] r_ir16         = 0;
    reg         r_ir16_v       = 0;

    reg   [6:0] r_opcode       = 0;            // ID: 
    reg   [4:0] r_rd           = 0;            // ID: 
    reg   [4:0] r_rs1          = 0;            // ID: 
    reg   [4:0] r_rs2          = 0;            // ID: 
    reg   [2:0] r_funct3       = 0;            // ID: 
    reg   [4:0] r_funct5       = 0;            // ID: 
    reg   [6:0] r_funct7       = 0;            // ID: 
    reg  [11:0] r_funct12      = 0;            // ID: 
    reg  [31:0] r_imm          = 0;            // ID: 
    reg         r_op_AMO_SC    = 0;            // ID: these are used for the fast control
    reg         r_op_AMO_LR    = 0;
    reg         r_op_LOAD      = 0;
    reg         r_op_STORE     = 0;
    reg         r_op_AMO       = 0;
    reg         r_op_SYS       = 0;
    reg         r_op_ECALL     = 0;
    reg         r_op_SRET      = 0;
    reg         r_op_MRET      = 0;
    reg         r_op_CSR_MSTA  = 0;
    reg         r_op_CSR_SSTA  = 0; 

    reg  [31:0] r_rrs1         = 0;            // OF:
    reg  [31:0] r_rrs2         = 0;            // OF:
    reg  [31:0] r_rcsr         = 0;            // OF:
    reg  [31:0] r_alu_in2      = 0;            // OF:
    reg   [6:0] r_alu_f7       = 0;            // OF:

    reg         r_tkn          = 0;            // E1:         // flag for branck taken or untaken
    reg  [31:0] r_jmp_pc       = 0;            // E1:
    reg  [31:0] r_mem_addr     = 0;            // E1:
    reg  [31:0] r_wb_data      = 0;            // E1:
    reg  [31:0] r_wb_data_csr  = 0;            // E1:

    reg  [31:0] r_mem_rdata    = 0;            // LD:
    reg  [31:0] r_atom_wdata   = 0;            // E2:

    /***** Other Registers ************************************************************************/
    reg  [63:0] e_icount    = 1;
    reg         r_if_done   = 0;
    reg  [15:0] r_if_irl    = 0;
    reg  [31:0] r_rcsr_t    = 0;
    reg  [31:0] irq_num     = 0;
    reg   [1:0] r_if_state  = 0; /* state in IF state */

    // WB Stage
    wire [31:0] w_wb_r_data;
    wire        w_wb_r_enable;
    wire [31:0] w_interrupt_mask;
    wire [31:0] w_irq_t;
    wire [3:0]  w_state;
    
    /***********************************           INI          ***********************************/
    reg r_init_stage=0;
    always@(posedge CLK) r_init_stage <= (w_state==`S_INI);
                                        
    assign w_init_stage = r_init_stage;

    /***********************************           IF           ***********************************/
    `ifdef CINSN_OLD
    wire [31:0] w_vadr1 = {pc[31:2], 2'b0}; // address of the first  2-byte
    wire [31:0] w_vadr2 = pc + 2;           // address of the second 2-byte
    //wire        w_nalign4 = (pc[3:1]==3'b111);   // set when pc is not_align_4byte
    wire        w_nalign4 = (pc[1:0]!=0);   // set when pc is not_align_4byte
    wire        w_usestate = (w_nalign4 && !r_ir16_v);

    always@(posedge CLK) begin
        if(state==`S_IF && r_if_state==1 && !w_busy) r_if_irl <= w_insn_data[31:16];
        if(state==`S_IF && w_pagefault==~0) begin r_cpc <= pc; end
    end

    wire [1:0] w_if_state = ((!(state==`S_IF || state==`S_CVT)) || w_pagefault!=~0) ? 0 :
                            (r_if_state==0 && w_nalign4 && !w_busy)                 ? (r_ir16_v) ? 3 : 1 :
                            (r_if_state==1 &&              !w_busy)                 ? 2 :
                            (r_if_state==2 &&              !w_busy)                 ? 3 : r_if_state;
    
    always@(posedge CLK) r_if_state <= w_if_state;

    reg [31:0] r_insn_addr=0;
    always@(posedge CLK) begin
        r_insn_addr <=  (w_nalign4 && r_ir16_v) ? w_vadr2 :
                        (w_if_state==2 || w_if_state==3) ? w_vadr2 :
                        (w_usestate) ? w_vadr1 : pc;
    end
    assign w_insn_addr = r_insn_addr;
      
    wire [31:0] w_ir_org = (r_if_state == 3) ? (r_ir16_v) ? {w_insn_data[15:0], r_ir16} :
                                                            {w_insn_data[15:0], r_if_irl} :
                                                            w_insn_data;
    `else
    assign w_insn_addr = pc;
    wire [31:0] w_ir_org = w_insn_data;
    `endif

    /***********************************           CVT          ***********************************/
    wire w_cinsn = (w_ir_org[1:0] != 2'b11); // flag to indicate a compressed instruction
    
    wire [31:0] w_ir_t;
    m_decomp decomp0(w_ir_org, w_ir_t);

    wire w_nop = (w_ir_t[6:0]==`OPCODE_OP_FP___ ||  
                  w_ir_t[6:0]==`OPCODE_LOAD_FP_ ||  w_ir_t[6:0]==`OPCODE_STORE_FP);

    wire [31:0] w_ir = (w_nop) ? `RV32_NOP : (w_cinsn) ? w_ir_t : w_ir_org; // instruction
    always@(posedge CLK) if(state == `S_CVT) begin 
        r_ir    <= w_ir;
        r_cinsn <= w_cinsn;
        if(!w_busy) r_ir16  <= w_ir_org[31:16];
    end

    /***********************************         ID & OF        ***********************************/
    wire [31:0] w_imm;
    m_imm_gen imm_gen0(r_ir, w_imm);

    wire [4:0] w_rs1 = r_ir[19:15];
    wire [4:0] w_rs2 = r_ir[24:20];
                      
    wire [31:0] w_rrs1, w_rrs2;
    wire w_regfile_we = (w_wb_r_enable && state==`S_WB);
    m_regfile regs(CLK, w_rs1, w_rs2, w_rrs1, w_rrs2, w_regfile_we, r_rd, w_wb_r_data, w_hart_id, w_a0);

    always @(posedge CLK) if(state == `S_ID) begin
        r_rrs1    <= w_rrs1;      // operand which is read from register file
        r_rrs2    <= w_rrs2;      // operand which is read from register file
        r_opcode  <= r_ir[ 6: 0];
        r_rd      <= r_ir[11: 7];
        r_rs1     <= r_ir[19:15];
        r_rs2     <= r_ir[24:20];
        r_funct3  <= r_ir[14:12];
        r_funct5  <= r_ir[31:27];
        r_funct7  <= r_ir[31:25];
        r_funct12 <= r_ir[31:20];
        r_imm     <= w_imm;
    end

    wire w_op_priv = (r_ir[ 6: 0]==`OPCODE_SYSTEM__ && r_ir[14:12]==`FUNCT3_PRIV__);
    wire w_op_csr  = (r_ir[ 6: 0]==`OPCODE_SYSTEM__ && r_ir[14:12]!=`FUNCT3_PRIV__);
    always @(posedge CLK) if(state == `S_ID) begin      ////// ID stage
        r_op_AMO_SC   <= (r_ir[31:27]==`FUNCT5_AMO_SC__); // r_funct5 ==
        r_op_AMO_LR   <= (r_ir[31:27]==`FUNCT5_AMO_LR__); // r_funct5 ==
        r_op_LOAD     <= (r_ir[ 6: 0]==`OPCODE_LOAD____); // r_opcdde ==
        r_op_STORE    <= (r_ir[ 6: 0]==`OPCODE_STORE___); // r_opcdde ==
        r_op_AMO      <= (r_ir[ 6: 0]==`OPCODE_AMO_____); // r_opcdde ==
        r_op_SYS      <= (r_ir[ 6: 0]==`OPCODE_SYSTEM__); // r_opcdde ==
        r_op_ECALL    <= (w_op_priv && r_ir[31:20]==`FUNCT12_ECALL_);
        r_op_SRET     <= (w_op_priv && r_ir[31:20]==`FUNCT12_SRET__);
        r_op_MRET     <= (w_op_priv && r_ir[31:20]==`FUNCT12_MRET__);
        r_op_CSR_MSTA <= (w_op_csr  && r_ir[31:20]==`CSR_MSTATUS);
        r_op_CSR_SSTA <= (w_op_csr  && r_ir[31:20]==`CSR_SSTATUS);
    end
    
    /*********************************** OF ( & compute mem addr & mul) **************************/
    wire signed [31:0] w_sin1 = r_rrs1;
    wire signed [31:0] w_sin2 = r_rrs2;

    wire [63:0] w_mul_SS = {{32{w_sin1[31]}},w_sin1} * {{32{w_sin2[31]}},w_sin2}; // Note!!
    wire [63:0] w_mul_SU = {{32{w_sin1[31]}},w_sin1} * {32'b0, r_rrs2};
    wire [63:0] w_mul_UU = {32'b0, r_rrs1} * {32'b0, r_rrs2};

    wire [31:0] w_mem_addr = (r_op_LOAD || r_op_STORE) ? r_rrs1+r_imm : (r_op_AMO) ? r_rrs1 : 0;
    
    reg [63:0]  r_mul_SS =0;
    reg [63:0]  r_mul_SU =0;
    reg [63:0]  r_mul_UU =0;
    always @(posedge CLK) if(state == `S_OF) begin
        r_mem_addr <= w_mem_addr; // memory address for Load, Store and Atomic
        r_mul_SS   <= w_mul_SS;
        r_mul_SU   <= w_mul_SU;
        r_mul_UU   <= w_mul_UU;
        r_rcsr     <= r_rcsr_t;
        r_alu_in2  <= (r_opcode==`OPCODE_OP_IMM__) ? r_imm : w_rrs2;
        r_alu_f7   <= (r_opcode==`OPCODE_OP_IMM__) ?
                      ((r_funct3==`FUNCT3_ADD___) ? 0 : r_funct7 & 7'h20) : r_funct7;
    end
    
    /***********************************           EX1          ***********************************/
    wire [31:0] w_alu_im_rslt;
    wire        w_alu_b_rslt;
    wire [31:0] w_alu_c_rslt;
    wire        w_ex1 = (state == `S_EX1);
    wire        w_ex1_busy;

    m_alu_im ALU_IM(CLK, RST_X, w_ex1, r_rrs1, r_alu_in2, r_funct3, r_alu_f7, w_alu_im_rslt,
                    w_ex1_busy, r_mul_SS, r_mul_SU, r_mul_UU);
    m_alu_b  ALU_B(r_rrs1, r_alu_in2, r_funct3, w_alu_b_rslt);
    m_alu_c  ALU_C(r_rcsr, r_rrs1, r_imm, r_funct3, w_alu_c_rslt);

    always @(posedge CLK) begin
        if(w_pagefault != ~0) begin
            pending_exception <= w_pagefault;
        end
        else if(state == `S_INI) begin
            pending_exception <= ~0;
            r_tkn             <= 0;
        end
        else if(state == `S_EX1) begin
            case(r_opcode)
                `OPCODE_LUI_____ : begin r_wb_data  <= r_imm;          end
                `OPCODE_AUIPC___ : begin r_wb_data  <= pc + r_imm;     end
                `OPCODE_OP______ : begin r_wb_data  <= w_alu_im_rslt;  end
                `OPCODE_OP_IMM__ : begin r_wb_data  <= w_alu_im_rslt;  end
                `OPCODE_LOAD____ : begin end
                `OPCODE_STORE___ : begin end
                `OPCODE_JAL_____ : begin
                    r_tkn       <= 1;
                    r_wb_data   <= (r_cinsn) ? pc+2 : pc+4;
                    r_jmp_pc    <= pc + r_imm;
                end
                `OPCODE_JALR____ : begin
                    r_tkn       <= 1;
                    r_wb_data   <= (r_cinsn) ? pc+2 : pc+4;
                    r_jmp_pc    <= r_rrs1 + r_imm;
                end
                `OPCODE_AMO_____ : begin
                    if(r_op_AMO_SC) begin
                        r_wb_data <= !((r_rrs1==load_res) && reserved);
                    end
                end
                `OPCODE_BRANCH__ : begin
                    r_tkn       <= w_alu_b_rslt;
                    r_jmp_pc    <= pc + r_imm;
                end
                `OPCODE_MISC_MEM : begin end
                `OPCODE_SYSTEM__ : begin
                    if(r_funct3 == `FUNCT3_PRIV__) begin
                        case (r_funct12)
                            `FUNCT12_ECALL_ : begin
                                // `CAUSE_USER_ECALL + 3 = `CAUSE_MACHINE_ECALL                                
                                r_wb_data_csr       <= `CAUSE_USER_ECALL + priv;
                                pending_exception   <= `CAUSE_USER_ECALL + priv;
                            end
                            `FUNCT12_EBREAK : begin end
                            `FUNCT12_URET__ : begin
                                r_tkn       <= 1;
                                r_jmp_pc    <= r_rcsr;
                            end
                            `FUNCT12_SRET__ : begin
                                r_tkn       <= 1;
                                r_jmp_pc    <= r_rcsr;
                            end
                            `FUNCT12_MRET__ : begin
                                r_tkn       <= 1;
                                r_jmp_pc    <= r_rcsr;
                            end
                            `FUNCT12_WFI___ : begin end
                            default: begin
                                if(r_funct7==`FUNCT7_SFENCE_VMA) r_tkn <= 0;
                            end
                        endcase
                    end else begin
                        r_wb_data_csr <= w_alu_c_rslt;
                    end
                end

                default : begin
                    r_tkn       <= 0;
                    r_jmp_pc    <= 0;
`ifdef SIM_MODE
                    $write("UNKNOWN OPCODE DETECT!!\n");
                    $write("TC:%08h PC:%08x OPCODE=%7b, ir=%8x hartid=%x\n", w_mtime[31:0], pc, r_opcode, r_ir, mhartid);
                    $write("Simulation Stopped...\n");
                    $finish();
`endif
                end
           endcase
        end
    end

    /***********************************           LD           ***********************************/
    reg [2:0] r_data_ctrl=0;
    always @(posedge CLK) r_data_ctrl <= (r_op_AMO) ? 3'h2 : r_funct3;
    
    assign w_data_ctrl = r_data_ctrl;
    assign w_data_addr = r_mem_addr;
    
    wire [31:0] w_mem_rdata = w_data_data;
    reg [31:0] r_lrpc=0, r_lrmtime=0, r_lrsc_displays=0;
    always@(posedge CLK) begin
        if(state == `S_FIN && (r_op_AMO && r_op_AMO_LR) && !w_busy) begin
            load_res <= r_mem_addr;
            reserved <= 1;
            r_lrpc <= pc;
            r_lrmtime <= w_mtime;
            if(r_lrsc_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                r_lrsc_displays <= r_lrsc_displays + 1;
                //$display("-------- %0d: amo-lr start mhartid=%1x r_mem_addr=%x", w_mtime, mhartid, r_mem_addr);
            end
        end else if(state == `S_FIN && r_op_AMO && r_op_AMO_SC /*&& !r_wb_data[0]*/ && !w_busy) begin
            reserved <= 0;
            if(r_lrsc_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                r_lrsc_displays <= r_lrsc_displays + 1;
                //$display("-------- %0d: amo-sc success=%0x mhartid=%1x load_res=%x", w_mtime, reserved?1:0, mhartid, load_res);
            end
        end
        `ifndef USE_SINGLE_CORE
        else if(reserved && (w_oh_load_res == load_res) && w_oh_sc && w_oh_reserved && 
            ((r_op_AMO && r_op_AMO_SC && state < `S_EX1) || !r_op_AMO_SC)) begin
            reserved <= 0;
            //$display("-------- %0d: reserved disabled for mhartid=%1x pc=%x lrpc=%x oh_pc=%x load_res=%x lrmtime=%0d", 
            //    w_mtime, mhartid, pc, r_lrpc, w_oh_pc, load_res, r_lrmtime);
        end
        `endif

    end

    /***********************************           EX2          ***********************************/
    wire [31:0] w_alu_a_rslt;
    m_alu_a ALU_A (r_rrs2, w_mem_rdata, r_funct5, w_alu_a_rslt);

    always @(posedge CLK) if(state == `S_EX2) begin
        r_mem_rdata  <= w_mem_rdata;
        r_atom_wdata <= w_alu_a_rslt;
    end

    /***********************************           SD           ***********************************/
    reg [31:0] r_data_wdata=0;
    always@(posedge CLK) begin /***** Note!! *****/
        if     (state==`S_LD ) r_data_wdata <= r_rrs2;
        else if(state==`S_EX2) r_data_wdata <= w_alu_a_rslt;
    end
    
    assign w_data_wdata = r_data_wdata;

    /***********************************           WB           ***********************************/
    assign w_wb_r_data =    (r_op_LOAD)                ? w_mem_rdata : /** regfile write data **/
                            (r_op_AMO && !r_op_AMO_SC) ? r_mem_rdata :
                            (r_op_SYS && r_funct3!=`FUNCT3_PRIV__) ? r_rcsr : r_wb_data;

    assign w_wb_r_enable =  (r_op_LOAD)                    ? 1 : /** regfile write enable **/
                            (r_opcode == `OPCODE_LUI_____) ? 1 :
                            (r_opcode == `OPCODE_AUIPC___) ? 1 :
                            (r_opcode == `OPCODE_JAL_____) ? 1 :
                            (r_opcode == `OPCODE_JALR____) ? 1 :
                            (r_opcode == `OPCODE_OP______) ? 1 :
                            (r_opcode == `OPCODE_OP_IMM__) ? 1 :
                            (r_op_AMO)                     ? 1 :
                            (r_op_SYS && r_funct3!=`FUNCT3_PRIV__) ? 1 : 0;

    reg [31:0] r_mstatus_t = 0;
    reg  [1:0] r_priv_t    = `PRIV_M;

    always@(posedge CLK) begin
        if(state==`S_INI) r_mstatus_t <= mstatus;
        else if(state == `S_WB) begin
            if(r_op_SYS && r_funct3 == `FUNCT3_PRIV__) begin
                case (r_funct12)
                    `FUNCT12_SRET__ : begin
                        r_mstatus_t <= (((mstatus & ~(1<<mstatus[8])) | (mstatus[5] << mstatus[8])) | 32'h20) & ~32'h100;
                        r_priv_t    <= mstatus[`MSTATUS_SPP_SHIFT];
                    end
                    `FUNCT12_MRET__ : begin
                        r_mstatus_t <= (((mstatus & ~(1 << mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT])) 
                                         | (mstatus[`MSTATUS_MPIE_SHIFT] << mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT])) 
                                        | `MSTATUS_MPIE) & ~`MSTATUS_MPP;
                        r_priv_t    <= mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT];
                    end
                    default: begin
                        r_mstatus_t <= mstatus;
                        r_priv_t    <= priv;
                    end
                endcase
            end
            else begin
                r_mstatus_t <= mstatus;
                r_priv_t    <= priv;
            end
        end
    end

    /***********************************           COM            ***********************************/
    wire [31:0] w_mstatus_nxt;

    wire [31:0] pending_interrupts = mip & mie;
    wire [31:0] enable_interrupts  = (pending_interrupts) ? (r_priv_t == `PRIV_M) ? ((w_mstatus_nxt & `MSTATUS_MIE) ? ~mideleg : 0) :
                                                            (r_priv_t == `PRIV_S) ? ((w_mstatus_nxt & `MSTATUS_SIE) ? (~mideleg | mideleg) : ~mideleg) :
                                                            (r_priv_t == `PRIV_U) ? ~0 : 0 : 0;
    assign w_interrupt_mask = pending_interrupts & enable_interrupts;
    assign w_irq_t          = w_interrupt_mask & (~w_interrupt_mask+1);

    always@(posedge CLK) begin
        if(state == `S_COM) begin
            case (w_irq_t)
                32'h00000001: irq_num <= 0;
                32'h00000002: irq_num <= 1;
                32'h00000004: irq_num <= 2;
                32'h00000008: irq_num <= 3;
                32'h00000010: irq_num <= 4;
                32'h00000020: irq_num <= 5;
                32'h00000040: irq_num <= 6;
                32'h00000080: irq_num <= 7;
                32'h00000100: irq_num <= 8;
                32'h00000200: irq_num <= 9;
                32'h00000400: irq_num <= 10;
                32'h00000800: irq_num <= 11;
                32'h00001000: irq_num <= 12;
                32'h00002000: irq_num <= 13;
                32'h00004000: irq_num <= 14;
                32'h00008000: irq_num <= 15;
                32'h00010000: irq_num <= 16;
                32'h00020000: irq_num <= 17;
                32'h00040000: irq_num <= 18;
                32'h00080000: irq_num <= 19;
                32'h00100000: irq_num <= 20;
                32'h00200000: irq_num <= 21;
                32'h00400000: irq_num <= 22;
                32'h00800000: irq_num <= 23;
                32'h01000000: irq_num <= 24;
                32'h02000000: irq_num <= 25;
                32'h04000000: irq_num <= 26;
                32'h08000000: irq_num <= 27;
                32'h10000000: irq_num <= 28;
                32'h20000000: irq_num <= 29;
                32'h40000000: irq_num <= 30;
                32'h80000000: irq_num <= 31;
                default:      irq_num <= 32;
            endcase
        end
    end

    wire [31:0] cause = (pending_exception != ~0) ? pending_exception : (`CAUSE_INTERRUPT | irq_num);
    wire [31:0] w_deleg = (r_priv_t <= `PRIV_S) ? ((cause & `CAUSE_INTERRUPT) ? (mideleg >> (cause & 32'h1f)) & 1 :
                                                                                (medeleg >> (cause & 32'h1f)) & 1) : 0;

    // wfi keeps pc constant
    wire w_executing_wfi = ((r_opcode==`OPCODE_SYSTEM__) && (r_funct3 == `FUNCT3_PRIV__) && (r_funct12== `FUNCT12_WFI___));
    wire w_exit_wfi =                        |( (mip & mie & (`MIP_MEIP | `MIP_MTIP | `MIP_MSIP))  |
                      ((r_priv_t <= `PRIV_S) && (mip & mie & (`MIP_SEIP | `MIP_STIP | `MIP_SSIP))) |
                      ((r_priv_t <= `PRIV_U) && (mip & mie & (`MIP_UEIP | `MIP_UTIP | `MIP_USIP))) );

    always @(posedge CLK) begin /////// update program counter
        if(mip & mie & (`MIP_UEIP | `MIP_UTIP | `MIP_USIP)) begin
            $display("(mip & mie & (`MIP_UEIP | `MIP_UTIP | `MIP_USIP))");
            $finish;
        end
        if(!RST_X || r_halt) begin pc <= `D_START_PC; end
        else if(w_pagefault != ~32'h0) begin  pending_tval <= (state==`S_IF) ? pc : (state!=`S_LD && state!=`S_SD) ? 0 : r_mem_addr; end
        else if(state==`S_FIN && !w_busy) begin
            if(pending_exception != ~0)             begin pc <= (w_deleg) ? stvec : mtvec; end   // raise Exception
            else if(w_interrupt_mask && w_take_int) begin pc <= (w_deleg) ? stvec : mtvec; end   // Interrupt HERE
            else if(w_executing_wfi)  begin
                if(w_exit_wfi) begin
                    pc <= pc + 4; 
                end
            end else                      begin pc <= (r_tkn) ? r_jmp_pc : (r_cinsn) ? pc + 2 : pc + 4; end
            r_ir16_v    <= !((pending_exception != ~0) || (w_interrupt_mask && w_take_int) || (r_tkn) || (!r_cinsn));
        end
        else if(state==`S_INI) begin
            pending_tval <= 0;
        end
    end

    /***********************************           FIN          ***********************************/
    always@(posedge CLK) begin
        if(state == `S_FIN && !w_busy) begin 
            if((pending_exception == ~0) ||
               (pending_exception != ~0 && (pending_exception & `CAUSE_INTERRUPT)) ||
               (pending_exception != ~0 && r_op_ECALL)) begin
                e_icount <= e_icount + 1;
            end
        end
    end

    /***********************************           CSR          ***********************************/
    wire [11:0] w_csr_addr = (r_funct3  != `FUNCT3_PRIV__ )  ? r_funct12 :
                             (r_funct12 == `FUNCT12_ECALL_)  ? `CSR_MTVEC:
                             (r_funct12 == `FUNCT12_URET__)  ? `CSR_UEPC :
                             (r_funct12 == `FUNCT12_SRET__)  ? `CSR_SEPC :
                             (r_funct12 == `FUNCT12_MRET__)  ? `CSR_MEPC : 0;
    
    /* mstatus[14:13]=FS[1:0].  The FS field encodes the status of the floating-point unit, 
        including the CSR fcsr and floating-point data registers f0–f31. FS=0=> is off
        XS field encodes the status of additional user-mode extensions and associated state. XS=0 => is off
        FS[1:0] WARL field and the XS[1:0] read-only field are used to reduce the cost of context save
        and restore by setting and tracking the current state of the floating-point unit and any other user-
        mode extensions respectivel
    */
    // SSTATUS_MASK0=h000de133=> sstatus has MXR, SUM, XS, FS, SPP, SPIE, SIE
    // h6000 => FS
    wire [31:0] w_sstatus_t = (mstatus | 32'h6000) & 32'h000de133;
    wire [31:0] w_mstatus_t = (mstatus | 32'h6000);

    always@(*) begin /***** read CSR register, for OF stage  *****/
        case(w_csr_addr)
            12'h3A0         : r_rcsr_t = 0;
            12'h3B0         : r_rcsr_t = 0;
            `CSR_FFLAGS     : r_rcsr_t = 0;
            `CSR_FRM        : r_rcsr_t = 0;
            `CSR_FCSR       : r_rcsr_t = 0;
            `CSR_SIE        : r_rcsr_t = mie & mideleg;
            `CSR_STVEC      : r_rcsr_t = stvec;
            `CSR_SCOUNTEREN : r_rcsr_t = scounteren;
            `CSR_SSCRATCH   : r_rcsr_t = sscratch;
            `CSR_SEPC       : r_rcsr_t = sepc;
            `CSR_SCAUSE     : r_rcsr_t = scause;
            `CSR_STVAL      : r_rcsr_t = stval;
            `CSR_SIP        : r_rcsr_t = mip & mideleg;
            `CSR_SATP       : r_rcsr_t = satp;

            `CSR_MEDELEG    : r_rcsr_t = medeleg;
            `CSR_MIDELEG    : r_rcsr_t = mideleg;
            `CSR_MIE        : r_rcsr_t = mie;
            `CSR_MTVEC      : r_rcsr_t = mtvec;
            `CSR_MCOUNTEREN : r_rcsr_t = mcounteren;
            `CSR_MSCRATCH   : r_rcsr_t = mscratch;
            `CSR_MEPC       : r_rcsr_t = mepc;
            `CSR_MCAUSE     : r_rcsr_t = mcause;
            `CSR_MTVAL      : r_rcsr_t = mtval;
            `CSR_MIP        : r_rcsr_t = mip;
            `CSR_MISA       : r_rcsr_t = misa | 32'h40000000;

            `CSR_MCYCLE     : r_rcsr_t = w_mtime[31:0];
            `CSR_MINSTRET   : r_rcsr_t = w_mtime[31:0];
            `CSR_CYCLE      : r_rcsr_t = w_mtime[31:0];
            `CSR_INSTRET    : r_rcsr_t = w_mtime[31:0];
            `CSR_TIME       : r_rcsr_t = w_mtime[31:0];

            `CSR_MCYCLEH    : r_rcsr_t = w_mtime[63:32];
            `CSR_MINSTRETH  : r_rcsr_t = w_mtime[63:32];
            `CSR_CYCLEH     : r_rcsr_t = w_mtime[63:32];
            `CSR_INSTRETH   : r_rcsr_t = w_mtime[63:32];
            `CSR_TIMEH      : r_rcsr_t = w_mtime[63:32];

            // h80000000 => SD
            // w_mstatus_t[31:13]==3 => FS, w_mstatus_t[31:15]==3 => XS
            /* The SD bit is a read-only bit that summarizes whether either the FS field or XS field signals the
                presence of some dirty state that will require saving extended user context to memory. If both XS
                and FS are hardwired to zero, then SD=mstatus[31] is also always zero
                The FS field encodes the status of the floating-point unit, including
                the CSR fcsr and floating-point data registers f0–f31
            */
            `CSR_SSTATUS    : r_rcsr_t = (w_sstatus_t[31:13]==3 | w_sstatus_t[31:15]==3) ? (w_sstatus_t | 32'h80000000) : w_sstatus_t;
            `CSR_MSTATUS    : r_rcsr_t = (w_mstatus_t[31:13]==3 | w_mstatus_t[31:15]==3) ? (w_mstatus_t | 32'h80000000) : w_mstatus_t;
            `CSR_MHARTID    : r_rcsr_t = mhartid;
            default         : r_rcsr_t = 0;
        endcase
    end


    wire        w_csr_we    = (r_op_SYS) && (r_funct3 != `FUNCT3_PRIV__);
    // SSTATUS_MASK =  32'h000de133 see above
    wire [31:0] w_sstatus   = (mstatus & ~`SSTATUS_MASK) | (r_wb_data_csr & `SSTATUS_MASK);

    // t1 sets mpie, t2 sets mpp, t3 clears mie
    wire [31:0] w_sstatus_t1 = (w_mstatus_nxt & ~`MSTATUS_SPIE) | (((w_mstatus_nxt >> r_priv_t) & 1) << `MSTATUS_SPIE_SHIFT);
    wire [31:0] w_sstatus_t2 = (w_sstatus_t1  & ~`MSTATUS_SPP) | (r_priv_t << `MSTATUS_SPP_SHIFT);
    wire [31:0] w_sstatus_t3 = (w_sstatus_t2  & ~`MSTATUS_SIE);
    wire [31:0] w_mstatus_t1 = (w_mstatus_nxt & ~`MSTATUS_MPIE) | (((w_mstatus_nxt >> r_priv_t) & 1) << `MSTATUS_MPIE_SHIFT);
    wire [31:0] w_mstatus_t2 = (w_mstatus_t1  & ~`MSTATUS_MPP) | (r_priv_t << `MSTATUS_MPP_SHIFT);
    wire [31:0] w_mstatus_t3 = (w_mstatus_t2  & ~`MSTATUS_MIE);

`ifdef LAUR_DEBUG_AFTER_CSRW_SATP
    reg was_csrw_satp = 0;
    reg [31:0] old_insn_addr;
`endif

    wire w_take_int = 
                      `ifdef NUTTX_FLAT
                      1;
                      `else
                      (irq_num == `MIP_STIP_SHIFT) ?  (priv <= `PRIV_S) && !r_op_ECALL && !r_op_SRET: 
                      (irq_num == `MIP_SEIP_SHIFT) ?  (priv <= `PRIV_S) : 1;
                      `endif
    reg [31:0] r_ipi_max_displays=0, r_extint_max_displays=0;
    output reg r_ipi_taken=0, r_extint_taken=0;

    always@(posedge CLK) begin /***** write CSR registers *****/
        if(state == `S_IF) begin
            if(w_plic_we) begin
                if(r_extint_taken == 0) begin
                    if(r_extint_max_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                        r_extint_max_displays <= r_extint_max_displays + 1;
                        $display("core%1x w_plic_we mip <= m/seip", mhartid);
                    end
                    `ifdef NUTTX_FLAT
                    mip[31:8] <= `MIP_MEIP >> 8;
                    $display("nuttx-flat mip[31:8]<=%x", `MIP_MEIP >> 8);
                    `else
                    mip[31:8] <= `MIP_SEIP >> 8;
                    `endif
                    r_extint_taken <= 1;
                end
            end else
                r_extint_taken <= 0;
        end else 
        `ifdef NUTTX_FLAT
        if((state == `S_FIN && !w_busy) && (w_interrupt_mask && w_take_int) &&
            (irq_num == `MIP_MEIP_SHIFT)) begin
        `else
        if((state == `S_FIN && !w_busy) && (w_interrupt_mask && w_take_int) &&
            (irq_num == `MIP_SEIP_SHIFT)) begin
        `endif
                        mip[31:8] <= 0;
                        //if(r_extint_max_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                        //        r_extint_max_displays <= r_extint_max_displays + 1;
                                $display("core%1x got clear extint", mhartid);
                        //end
        end

        if(state == `S_IF) begin
                if(w_ipi & (1<<mhartid)) begin
                    if(r_ipi_taken == 0) begin
                        if((w_ipi >> 16) & (1<<mhartid)) begin
                            if(r_ipi_max_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                                r_ipi_max_displays <= r_ipi_max_displays + 1;
                                $display("core%1x got ipi=%x ssip priv=%x mie=%x mtvec=%x time=%x pc=%x", 
                                    mhartid, w_ipi, priv, mie, mtvec, w_mtime, pc);
                            end
                            mip[3:0] <= mip[3:0] | `MIP_SSIP;
                        end else begin
                            if(r_ipi_max_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                                r_ipi_max_displays <= r_ipi_max_displays + 1;
                                $display("core%1x got ipi=%x msip priv=%x mie=%x mtvec=%x pc=%x", 
                                    mhartid, w_ipi, priv, mie, mtvec, pc);
                            end
                            mip[3:0] <= mip[3:0] | `MIP_MSIP;
                        end
                        r_ipi_taken <= 1;
                        //if(!w_executing_wfi)
                        //    $display("-------- %x: core%x received ipi while not w_executing_wfi pc=%x oh_pc=%x", w_mtime, mhartid, pc, w_oh_pc); 
                    end
                end else begin
                    r_ipi_taken <= 0;
                end
        end else if((state == `S_FIN && !w_busy) && (w_interrupt_mask && w_take_int) &&
                    (irq_num == `MIP_SSIP_SHIFT || irq_num == `MIP_MSIP_SHIFT)) begin
                        mip[3:0] <= 0;
                        if(r_ipi_max_displays < (`IPI_MAX_DISPLAYS >> 1)) begin
                                r_ipi_max_displays <= r_ipi_max_displays + 1;
                                $display("core%1x got clear ipi", mhartid);
                        end
        end

            if(w_clint_we && state == `S_SD && !w_busy) begin
                //if(w_mtime >= 460000000)
                    //$display("%0d: core%1x sets mtimecmp=%x pc=%x state=%x", w_mtime, mhartid, w_wmtimecmp, pc, state);
                mtimecmp    <= w_wmtimecmp;
                mip[7:4] <= 0;
                if(r_was_clint_we < 2)
                    r_was_clint_we <= r_was_clint_we + 1;
                else
                    r_was_clint_we <= 1;
                if(r_was_clint_we == 1 && w_mtime > w_wmtimecmp) begin
                    $display("warning: w_mtime=%0d > w_wmtimecmp=%0d", w_mtime, w_mtimecmp);
                    //$finish;
                end
            end else if(state == `S_IF) begin
                if(r_was_clint_we==2 && (w_mtime >= mtimecmp)) begin
                    `ifdef NUTTX_FLAT
                    mip[7:4] <= `MIP_MTIP >> 4;
                    `else
                    mip[7:4] <= `MIP_STIP >> 4;
                    `endif
                    r_was_clint_we <= 0;
                    //$display("%0d: core%1x sets m/stip pc=%x state=%x", w_mtime, mhartid, pc, state);
                end
            end else 
            `ifdef NUTTX_FLAT
            if (state == `S_FIN && !w_busy && pending_exception == ~0 && 
                w_interrupt_mask && w_take_int && irq_num == `MIP_MTIP_SHIFT) begin
            `else
            if (state == `S_FIN && !w_busy && pending_exception == ~0 && 
                w_interrupt_mask && w_take_int && irq_num == `MIP_STIP_SHIFT) begin
            `endif
                mip[7:4] <= 0; // however is disabled by w_sstatus_t3
            end

        if(state == `S_FIN && !w_busy) begin
            if(pending_exception != ~0) begin
                //if(!r_op_ECALL)
                //    $display("pending exception");
                if(w_deleg) begin
                    scause  <= cause;
                    sepc    <= pc;
                    stval   <= pending_tval;
                    mstatus <= w_sstatus_t3;
                    priv    <= `PRIV_S;
                end else begin
                    mcause  <= cause;
                    mepc    <= pc;
                    mtval   <= pending_tval;
                    mstatus <= w_mstatus_t3;
                    priv    <= `PRIV_M;
                end
            end
            else if(w_interrupt_mask && w_take_int) begin
                if(irq_num == `MIP_MTIP_SHIFT) begin
                    //$display("mtip pc=%x hart=%x w_interrupt_mask=%x mip=%x mie=%x", 
                    //    pc, w_hart_id, w_interrupt_mask, mip, mie);
                end else if(irq_num == `MIP_MEIP_SHIFT) begin
                    $display("meip pc=%x hart=%x w_interrupt_mask=%x mip=%x mie=%x cause=%x mtvec=%x", 
                        pc, w_hart_id, w_interrupt_mask, mip, mie, cause, mtvec);
                end
                if(w_deleg) begin
                    scause  <= cause;
                    sepc    <= (r_tkn) ? r_jmp_pc : (r_cinsn) ? pc + 2 : pc + 4;
                    stval   <= pending_tval;
                    mstatus <= w_sstatus_t3;
                    priv    <= `PRIV_S;
                end else begin
                    mcause  <= cause;
                    mepc    <= (r_tkn) ? r_jmp_pc : (r_cinsn) ? pc + 2 : pc + 4;
                    mtval   <= pending_tval;
                    mstatus <= w_mstatus_t3;
                    priv    <= `PRIV_M;
                    if(irq_num == `MIP_STIP_SHIFT) begin
                        $display("irq_num `MIP_STIP_SHIFT will be in privm");
                        $finish;
                    end
                end
            end
        end

        else if(state == `S_COM && !w_busy) begin /***** COM stage *****/
            if(r_opcode == `OPCODE_SYSTEM__ && r_funct3 == `FUNCT3_PRIV__) begin
                case (r_funct12)
                    `FUNCT12_URET__ : begin
                    end
                    `FUNCT12_SRET__ : begin
                        mstatus <= (((mstatus & ~(1<<mstatus[`MSTATUS_SPP_SHIFT])) | 
                                    (mstatus[`MSTATUS_SPIE_SHIFT] << mstatus[`MSTATUS_SPP_SHIFT])) 
                                    | `MSTATUS_SPIE) & ~`MSTATUS_SPP;
                        priv    <= mstatus[`MSTATUS_SPP_SHIFT];
                        //$display("sret priv<=%x pc=%x", mstatus[`MSTATUS_SPP_SHIFT], pc);
                    end
                    `FUNCT12_MRET__ : begin
                        mstatus <= (((mstatus & ~(1 << mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT])) |
                                     (mstatus[`MSTATUS_MPIE_SHIFT] << mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT])) 
                                     | `MSTATUS_MPIE) & ~`MSTATUS_MPP;
                        priv    <= mstatus[`MSTATUS_MPP_SHIFT+1:`MSTATUS_MPP_SHIFT];
                    end
                endcase
            end
            else if(w_csr_we) begin
                case(r_funct12)
		            `CSR_STVEC      : stvec      <= r_wb_data_csr & ~3;
                    `CSR_SCOUNTEREN : scounteren <= r_wb_data_csr & 5;
                    `CSR_SSCRATCH   : sscratch   <= r_wb_data_csr;
                    `CSR_SEPC       : sepc       <= r_wb_data_csr & ~1;
                    `CSR_SCAUSE     : scause     <= r_wb_data_csr;
                    `CSR_STVAL      : stval      <= r_wb_data_csr;

                    `CSR_MTVEC      : mtvec      <= r_wb_data_csr & ~3;
                    `CSR_MCOUNTEREN : mcounteren <= r_wb_data_csr & 5;
                    `CSR_MSCRATCH   : mscratch   <= r_wb_data_csr;
                    `CSR_MEPC       : mepc       <= r_wb_data_csr & ~1;
                    `CSR_MCAUSE     : mcause     <= r_wb_data_csr;
                    `CSR_MTVAL      : mtval      <= r_wb_data_csr;

                    `CSR_SIE        : mie        <= (mie & ~mideleg) | (r_wb_data_csr & mideleg);
                    `CSR_SIP        : mip        <= (mip & ~mideleg) | (r_wb_data_csr & mideleg);

		            `CSR_MEDELEG    : begin 
		    			medeleg    <= (medeleg & ~`WCSR_MASK1) | (r_wb_data_csr & `WCSR_MASK1);
				    end
                    `CSR_MIDELEG    : mideleg    <= (mideleg & ~`WCSR_MASK2) | (r_wb_data_csr & `WCSR_MASK2);
                    `CSR_MIE        : mie        <= (mie & ~`WCSR_MASK3) | (r_wb_data_csr & `WCSR_MASK3);
                    `CSR_MIP        : mip        <= (mip & ~`WCSR_MASK4) | (r_wb_data_csr & `WCSR_MASK4);

		            `CSR_SATP       : begin 
		    			satp       <= r_wb_data_csr; 
					    `ifdef LAUR_DEBUG_AFTER_CSRW_SATP
					        if(r_wb_data_csr[31]) begin
						        $write("satp write: \ttime:%08x pc=%x r_insn_addr=%x w_insn_data=%x satp<=%x pending_exception=%x stvec=%x mtvec=%x w_deleg=%x w_busy=%x\n",
                                                        w_mtime, pc, r_insn_addr, w_insn_data, r_wb_data_csr, pending_exception, stvec, mtvec, w_deleg, w_busy);
						    was_csrw_satp <= 1;
						    old_insn_addr <= r_insn_addr;
					        end
					    `endif
		    		end	

                     /* MASK_STATUS (`MSTATUS_MASK & ~`MSTATUS_FS) = h000e79bb & ~h6000 = h000e19bb = 
                            MXR SUM MPRV MPP SPP MPIE SPIE MIE SIE
                            The MPRV (Modify PRiVilege) bit modifies the privilege level at which loads and stores execute
                            in all privilege modes. When MPRV=0, loads and stores behave as normal, using the translation
                            and protection mechanisms of the current privilege mode. When MPRV=1, load and store memory
                            addresses are translated and protected, and endianness is applied, as though the current privilege
                            mode were set to MPP. Instruction address-translation and protection are unaffected by the setting
                            of MPRV. MPRV is hardwired to 0 if U-mode is not supported.
                     */
                    `CSR_MSTATUS    : mstatus    <= (mstatus & ~`MASK_STATUS) | (r_wb_data_csr & `MASK_STATUS);
                    `CSR_SSTATUS    : mstatus    <= (mstatus & ~`MASK_STATUS) | (w_sstatus & `MASK_STATUS);
                endcase
            end
        end
    end

`ifdef LAUR_DEBUG_AFTER_CSRW_SATP
    always @(posedge CLK) begin
	    if(was_csrw_satp && (old_insn_addr != r_insn_addr)) begin
		$write("new insn addr: \ttime:%08x pc=%x r_insn_addr=%x w_insn_data=%x satp=%x pending_exception=%x stvec=%x mtvec=%x w_deleg=%x w_busy=%x\n",
                                                        w_mtime, pc, r_insn_addr, w_insn_data, satp, pending_exception, stvec, mtvec, w_deleg, w_busy);
		old_insn_addr <= r_insn_addr;
        was_csrw_satp <= 0;
	    end
    end
`endif

    assign w_mstatus_nxt =  (pending_exception != ~0)             ? r_mstatus_t :
                        (w_csr_we && r_funct12 == `CSR_MSTATUS) ? (mstatus & ~`MASK_STATUS) | (r_wb_data_csr & `MASK_STATUS) :
                        (w_csr_we && r_funct12 == `CSR_SSTATUS) ? (mstatus & ~`MASK_STATUS) | (w_sstatus & `MASK_STATUS) : r_mstatus_t;

    /***********************************       TLB FLUSH!       ***********************************/
    reg  r_tlb_flush;
    wire [31:0] w_data_t = (r_funct12==`CSR_MSTATUS) ? r_wb_data_csr : w_sstatus;
    wire [31:0] w_mod    = w_data_t ^ mstatus;
    
    assign w_tlb_flush   = r_tlb_flush; // generate this signal to flush TLBs 
    reg reg_tlb_flush=0;
    always @(posedge CLK)
        reg_tlb_flush <= r_tlb_flush;

    always@(*) begin
        if(state==`S_COM && !w_busy) begin
            if(pending_exception != ~0 || (w_interrupt_mask && w_take_int)) r_tlb_flush <= 1;
            else if(r_op_SRET || r_op_MRET) r_tlb_flush <= 1;
            else if(r_op_CSR_MSTA) begin
                if((w_mod & (`MSTATUS_MPRV | `MSTATUS_SUM | `MSTATUS_MXR)) != 0 ||
                   ((mstatus & `MSTATUS_MPRV) && (w_mod & `MSTATUS_MPP) != 0)) begin
                    r_tlb_flush <= 1;
                end else begin
                    //$display("r_tlb_flush remains %x ---------------------", r_tlb_flush);
                    // avoid latch warning
                    r_tlb_flush <= reg_tlb_flush;
                    if(r_tlb_flush != reg_tlb_flush)
                        $display("---- 1 r_tlb_flush != reg_tlb_flush");
                end
            end
            else if(r_op_CSR_SSTA) begin
                if((w_mod & (`MSTATUS_MPRV | `MSTATUS_SUM | `MSTATUS_MXR)) != 0 ||
                   ((mstatus & `MSTATUS_MPRV) && (w_mod & `MSTATUS_MPP) != 0)) begin
                    r_tlb_flush <= 1;
                end else begin
                    //$display("r_tlb_flush remains %x ---------------------", r_tlb_flush);
                    // avoid latch warning
                    r_tlb_flush <= reg_tlb_flush;
                    if(r_tlb_flush != reg_tlb_flush)
                        $display("---- 2 r_tlb_flush != reg_tlb_flush");
                end
            end else if ((r_opcode == `OPCODE_SYSTEM__ && r_funct3 == `FUNCT3_PRIV__ && r_funct7==`FUNCT7_SFENCE_VMA))
                         //(r_opcode == `OPCODE_MISC_MEM && (r_funct3 == `FUNCT3_FENCE_ || r_funct3 == `FUNCT3_FENCEI)))
                begin
                //if(r_opcode == `OPCODE_MISC_MEM)
                    //$display ("%08x, fence opcode=%x", w_mtime, r_opcode);
                // sfence.vma is called write after satp write in setup_vm_final by local_flush_tlb_all()
                r_tlb_flush <= 1;
            end
            else r_tlb_flush <= 0;
        end 
        else r_tlb_flush <= 0;

        if((mstatus & (`MSTATUS_MPRV | `MSTATUS_SUM | `MSTATUS_MXR)) != 0) begin
            if(mstatus & `MSTATUS_MPRV)
                $display("%x MSTATUS_MPRV mpp=%x --------------------", w_mtime, mstatus&(3 << `MSTATUS_MPP_SHIFT));
            //if(mstatus & `MSTATUS_SUM)
                //$display("%x MSTATUS_SUM", w_mtime);
            if(mstatus & `MSTATUS_MXR)
                $display("%x MSTATUS_MXR --------------------------", w_mtime);
        end
    end

    /***********************************      STATE UPDATE      ***********************************/
    wire w_com = ((pending_exception!=~0 || w_pagefault!=~0 || (state==`S_EX1 && r_op_ECALL)) 
                  && state!=`S_COM && state!=`S_FIN && state!=`S_INI);

    assign w_state = (!RST_X | r_halt)                                         ? 0      : // `S_INI
                     (w_com)                                                   ? `S_COM :
                     ((w_busy) || (w_ex1 && w_ex1_busy))                       ? state  :
                     (state==`S_FIN)                                           ? `S_INI :
                     `ifdef CINSN_OLD
                     (state==`S_IF  && w_nalign4 && r_if_state!=3)             ? `S_IF  : // Note
                     `endif
                     (state==`S_EX1 && !r_op_AMO && !r_op_LOAD && !r_op_STORE) ? `S_WB  :
                     (state==`S_LD  && r_op_STORE)                             ? `S_SD  :
                     (state==`S_LD  && r_op_LOAD)                              ? `S_WB  : state+1;
         
    always @(posedge CLK) state <= w_state;

    reg [2:0] r_com;
    always @(posedge CLK) r_com <= (state!=`S_COM && state!=`S_FIN && state!=`S_INI) ? {pending_exception!=~0, w_pagefault!=~0, (state==`S_EX1 && r_op_ECALL)} : 0;

    /**********************************************************************************************/
    wire w_d_we_t = (w_state==`S_SD && (r_op_STORE || 
                                        (r_op_AMO &&  r_op_AMO_SC && !r_wb_data[0]) || 
                                        (r_op_AMO && !r_op_AMO_LR && !r_op_AMO_SC)));
    wire w_d_en_t = (w_state==`S_LD && (r_op_LOAD || (r_op_AMO && (!r_op_AMO_SC))));

         
    reg       r_data_we=0;
    reg       r_data_en=0; /* memory, read enable */
    reg [1:0] r_tlb_req=0;
    always @(posedge CLK) begin
        r_data_we <= w_d_we_t;
        r_data_en <= w_d_en_t;
        r_tlb_req <= `ifdef CINSN_OLD
                     (w_state==`S_IF && w_if_state!=1) ? `ACCESS_CODE  :     //// Note!!
                     `else
                     (w_state==`S_IF)                  ? `ACCESS_CODE  : 
                     `endif
                     (w_d_en_t)                        ? `ACCESS_READ  :
                     (w_d_we_t)                        ? `ACCESS_WRITE : `ACCESS_NONE;
    end

    assign w_tlb_req  = r_tlb_req;
    assign w_data_we  = r_data_we;
    assign w_priv     = priv;
    assign w_satp     = satp;
    assign w_mstatus  = mstatus;
    //assign w_mtime    = w_mtime;
    assign w_mtimecmp = mtimecmp;
    assign w_mip      = mip;

    /**********************************************************************************************/
    initial r_halt = 0;
    always @(posedge CLK) if(r_opcode==`OPCODE_HALT____) r_halt <= 1;  //w_opcode

    assign w_core_pc = pc;
    assign w_core_ir = r_ir;
    assign w_core_odata = 0;
endmodule
/**************************************************************************************************/


/**************************************************************************************************/
/* 32bit-32cycle divider (signed or unsigned)                                                     */
/**************************************************************************************************/
module m_div_unit(CLK, RST_X, w_init, w_signed, w_dividend, w_divisor, w_rslt, w_busy);
    input  wire         CLK, RST_X;
    input  wire         w_init, w_signed;
    input  wire [31:0]  w_dividend, w_divisor;
    output wire [63:0]  w_rslt;
    output wire         w_busy;

    reg         w_sign_dividend=0, w_sign_divisor=0;

    wire [31:0] w_uint_dividend, w_uint_divisor;
    wire [63:0] w_uint_rslt;

    m_div_unit_core divcore(CLK, RST_X, w_init, w_uint_dividend,
                            w_uint_divisor, w_uint_rslt, w_busy);

    assign w_uint_dividend  = (w_signed & w_dividend[31]) ? ~w_dividend + 1 : w_dividend;
    assign w_uint_divisor   = (w_signed & w_divisor[31])  ? ~w_divisor  + 1 : w_divisor;
    assign w_rslt[63:32]    = 
        (~w_signed)?                   w_uint_rslt[63:32]     :
        ({w_sign_dividend, w_sign_divisor} == 2'b00) ?  w_uint_rslt[63:32]     :
        ({w_sign_dividend, w_sign_divisor} == 2'b01) ?  w_uint_rslt[63:32]     :
        ({w_sign_dividend, w_sign_divisor} == 2'b10) ? ~w_uint_rslt[63:32] + 1 :
                                                       ~w_uint_rslt[63:32] + 1;
    assign w_rslt[31: 0]    = 
        (~w_signed)?                     w_uint_rslt[31: 0]   :
        ({w_sign_dividend, w_sign_divisor} == 2'b00) ?  w_uint_rslt[31: 0]     :
        ({w_sign_dividend, w_sign_divisor} == 2'b01) ? ~w_uint_rslt[31: 0] + 1 :
        ({w_sign_dividend, w_sign_divisor} == 2'b10) ? ~w_uint_rslt[31: 0] + 1 :
                                                        w_uint_rslt[31: 0];
        
    always @(posedge CLK) begin
      if(!RST_X) begin
          w_sign_dividend   <= 0;
          w_sign_divisor    <= 0;
      end else begin
          w_sign_dividend   <= (w_init) ? w_dividend[31] : w_sign_dividend;
          w_sign_divisor    <= (w_init) ? w_divisor[31] : w_sign_divisor;
      end
    end
endmodule

/**************************************************************************************************/
module m_div_unit_core(CLK, RST_X, w_init, w_dividend, w_divisor, r_rslt, w_busy);
    input  wire        CLK, RST_X;
    input  wire        w_init;
    input  wire [31:0] w_dividend, w_divisor;
    output reg  [63:0] r_rslt;
    output wire        w_busy;

    reg  [31:0] r_divisor=0;
    reg   [5:0] r_count=0;
    
    wire [32:0] w_differ;

    assign w_busy   = (r_count < 32);
    assign w_differ = r_rslt[63:31] - {1'b0, r_divisor};

    always @(posedge CLK) begin
        if(!RST_X) begin
            r_divisor   <= 0;
            r_rslt      <= 0;
            r_count     <= 0;
        end else if(w_init) begin
            r_divisor   <= w_divisor;
            r_rslt      <= {32'h0, w_dividend};
            r_count     <= 0;
        end else begin
            r_divisor   <= r_divisor;
            r_rslt      <= (w_differ[32]) ? {r_rslt[62:0], 1'h0} :
                                            {w_differ[31:0], r_rslt[30:0], 1'h1};
            r_count     <= r_count + 1;
        end
    end
endmodule

/***** ALU module                                                                             *****/
/**************************************************************************************************/
module m_alu_im(CLK, RST_X, w_le, w_in1, w_in2, w_funct3, w_funct7, r_rslt, w_busy,
                w_mul_SS, w_mul_SU, w_mul_UU);
    input  wire         CLK, RST_X;
    input  wire         w_le;
    input  wire [31:0]  w_in1, w_in2;
    input  wire  [2:0]  w_funct3;
    input  wire  [6:0]  w_funct7;
    output reg  [31:0]  r_rslt;
    output wire         w_busy;
    input  wire [63:0]  w_mul_SS;
    input  wire [63:0]  w_mul_SU;
    input  wire [63:0]  w_mul_UU;

    reg  r_div_first = 1;

    wire signed [31:0] w_sin1 = w_in1;
    wire signed [31:0] w_sin2 = w_in2;

    wire  [4:0] w_shamt  = w_in2[4:0];

//    wire [63:0] w_mul_SS = {{32{w_sin1[31]}},w_sin1} * {{32{w_sin2[31]}},w_sin2};
//    wire [63:0] w_mul_SU = {{32{w_sin1[31]}},w_sin1} * {32'b0, w_in2};
//    wire [63:0] w_mul_UU = {32'b0, w_in1} * {32'b0, w_in2};

    wire        w_divunit_busy;
    wire [63:0] w_divunit_rslt;

    wire w_div_req          =   (w_funct7[0] &&
                                 (w_funct3 == `FUNCT3_DIV___ || w_funct3 == `FUNCT3_DIVU__ ||
                                  w_funct3 == `FUNCT3_REM___ || w_funct3 == `FUNCT3_REMU__));
    wire w_div_init         =   w_div_req && w_le && !w_divunit_busy && r_div_first; 
    wire w_div_signed       =   (w_funct3 == `FUNCT3_DIV___ || w_funct3 == `FUNCT3_REM___);

    m_div_unit divunit(CLK, RST_X, w_div_init,
                        w_div_signed, w_in1, w_in2, w_divunit_rslt, w_divunit_busy);
    assign w_busy = w_le && w_div_req && (w_divunit_busy || w_div_init);

    wire [63:0] w_div_rslt =    (w_in2 == 0) ? {w_in1, 32'hffffffff} :
                                (w_in2==32'hffffffff &&
                                (w_funct3 == `FUNCT3_DIV___ || w_funct3 == `FUNCT3_REM___))
                                ? {32'h0, w_in1} : w_divunit_rslt;

    // For Div unit
    always@(posedge CLK) begin
        if(w_div_init) begin
            r_div_first <= 0;
        end
        else if(!w_le) begin
            r_div_first <= 1;
        end
        if(w_le && w_div_req && !w_busy) begin
            if(w_funct3 == `FUNCT3_DIV___ || w_funct3 == `FUNCT3_DIVU__) begin
                if(r_rslt == w_div_rslt[31:0]) begin
                end
                else begin
`ifdef SIM_MODE
                    $write("CAUTION! DIV FAIL! %x/%x true:%x unit:%x %x\n",
                            w_in1, w_in2, r_rslt, w_div_rslt[63:32], w_div_rslt[31:0]);
                    $finish();
`endif
                end
            end
            if(w_funct3 == `FUNCT3_REM___ || w_funct3 == `FUNCT3_REMU__) begin
                if(r_rslt == w_div_rslt[63:32]) begin
                end
                else begin
`ifdef SIM_MODE
                    $write("CAUTION! REM FAIL! %x/%x true:%x unit:%x %x\n",
                            w_in1, w_in2, r_rslt, w_div_rslt[63:32], w_div_rslt[31:0]);
                    $finish();
`endif
                end
            end
        end
    end

    always@(*) begin
        if(!w_funct7[0]) begin
            case (w_funct3)
                `FUNCT3_ADD___ : r_rslt = (w_funct7) ? w_in1 - w_in2 : w_in1 + w_in2;
                `FUNCT3_SLL___ : r_rslt = w_in1 << w_shamt;
                `FUNCT3_SLT___ : r_rslt = {31'b0, w_sin1 < w_sin2};
                `FUNCT3_SLTU__ : r_rslt = {31'b0, w_in1 < w_in2};
                `FUNCT3_XOR___ : r_rslt = w_in1 ^ w_in2;
                `FUNCT3_SRL___ : begin
                                    if(w_funct7[5]) r_rslt = w_sin1 >>> w_shamt;
                                    else            r_rslt = w_in1 >> w_shamt;
                                end
                `FUNCT3_OR____ : r_rslt = w_in1 | w_in2;
                `FUNCT3_AND___ : r_rslt = w_in1 & w_in2;
                default        : r_rslt = 0;
            endcase
        end else begin
            case (w_funct3)
                `FUNCT3_MUL___ : r_rslt = w_mul_SS[31:0];
                `FUNCT3_MULH__ : r_rslt = w_mul_SS[63:32];
                `FUNCT3_MULHSU : r_rslt = w_mul_SU[63:32];
                `FUNCT3_MULHU_ : r_rslt = w_mul_UU[63:32];
                
                `FUNCT3_DIV___ : begin
                                    if(w_in2==32'hffffffff) r_rslt = w_in1;
                                    else if(w_in2==0)       r_rslt = 32'hffffffff;
                                    else                    r_rslt = w_div_rslt[31:0];
                                end
                `FUNCT3_DIVU__ : begin
                                    if(w_in2==0)    r_rslt = 32'hffffffff;
                                    else            r_rslt = w_div_rslt[31:0];
                                end
                `FUNCT3_REM___ : begin
                                    if(w_in2==32'hffffffff) r_rslt = 0;
                                    else if(w_in2==0)       r_rslt = w_in1;
                                    else                    r_rslt = w_div_rslt[63:32];
                                end
                `FUNCT3_REMU__ : begin
                                    if(w_in2==0)    r_rslt = w_in1;
                                    else            r_rslt = w_div_rslt[63:32];
                                end
                default        : r_rslt = 0;
            endcase
        end
    end
endmodule

/***** ALU for Branch                                                                         *****/
/**************************************************************************************************/
module m_alu_b(w_in1, w_in2, w_funct3, r_rslt);
    input wire [31:0]  w_in1, w_in2;
    input wire  [2:0]  w_funct3;
    output reg         r_rslt;

    wire signed [31:0] w_sin1 = w_in1;
    wire signed [31:0] w_sin2 = w_in2;

    always@(*) begin
        case(w_funct3)
            `FUNCT3_BEQ___ : r_rslt = w_in1 == w_in2;
            `FUNCT3_BNE___ : r_rslt = w_in1 != w_in2;
            `FUNCT3_BLT___ : r_rslt = w_sin1 < w_sin2;
            `FUNCT3_BGE___ : r_rslt = w_sin1 >= w_sin2;
            `FUNCT3_BLTU__ : r_rslt = w_in1 < w_in2;
            `FUNCT3_BGEU__ : r_rslt = w_in1 >= w_in2;
            default        : r_rslt = 0;
        endcase
    end
endmodule

/***** ALU for Atomic                                                                         *****/
/**************************************************************************************************/
module m_alu_a(w_in1, w_in2, w_funct5, r_rslt);
    input wire [31:0]  w_in1, w_in2;
    input wire  [4:0]  w_funct5;
    output reg [31:0]  r_rslt;

    wire signed [31:0] w_sin1 = w_in1;
    wire signed [31:0] w_sin2 = w_in2;

    always@(*) begin
        case(w_funct5)
            `FUNCT5_AMO_LR__ : r_rslt = 0;
            `FUNCT5_AMO_SC__ : r_rslt = w_in1;
            `FUNCT5_AMO_SWAP : r_rslt = w_in1;
            `FUNCT5_AMO_ADD_ : r_rslt = w_in1 + w_in2;
            `FUNCT5_AMO_AND_ : r_rslt = w_in1 & w_in2;
            `FUNCT5_AMO_OR__ : r_rslt = w_in1 | w_in2;
            `FUNCT5_AMO_XOR_ : r_rslt = w_in1 ^ w_in2;
            `FUNCT5_AMO_MIN_ : r_rslt = (w_sin1 < w_sin2) ? w_in1 : w_in2;
            `FUNCT5_AMO_MINU : r_rslt = (w_in1 < w_in2) ? w_in1 : w_in2;
            `FUNCT5_AMO_MAX_ : r_rslt = (w_sin1 > w_sin2) ? w_in1 : w_in2;
            `FUNCT5_AMO_MAXU : r_rslt = (w_in1 > w_in2) ? w_in1 : w_in2;
            default          : r_rslt = 0;
        endcase
    end
endmodule

/***** ALU for CSR                                                                            *****/
/**************************************************************************************************/
module m_alu_c(w_rcsr, w_rrs1, w_imm, w_funct3, r_rslt);
    input wire [31:0] w_rcsr, w_rrs1, w_imm;
    input wire  [2:0] w_funct3;
    output reg [31:0] r_rslt;

    always@(*) begin
        case(w_funct3)
            `FUNCT3_CSRRW_ : r_rslt = w_rrs1;
            `FUNCT3_CSRRS_ : r_rslt = w_rcsr | w_rrs1;
            `FUNCT3_CSRRC_ : r_rslt = w_rcsr & (~w_rrs1);
            `FUNCT3_CSRRWI : r_rslt = w_imm;
            `FUNCT3_CSRRSI : r_rslt = w_rcsr | w_imm;
            `FUNCT3_CSRRCI : r_rslt = w_rcsr & (~w_imm);
            default        : r_rslt = 0;
        endcase
    end
endmodule

/***** Imm generateor                                                                         *****/
/**************************************************************************************************/
module m_imm_gen(w_inst, r_imm);
    input  wire [31:0]  w_inst;
    output reg  [31:0]  r_imm;
    
    wire [6:0] opcode = w_inst[6:0];
    wire [31:0] imm_I = { {21{w_inst[31]}}, w_inst[30:25], w_inst[24:20] };
    wire [31:0] imm_S = { {21{w_inst[31]}}, w_inst[30:25], w_inst[11:8], w_inst[7] };
    wire [31:0] imm_B = { {20{w_inst[31]}}, w_inst[7],w_inst[30:25] ,w_inst[11:8], 1'b0 };
    wire [31:0] imm_U = { w_inst[31:12], 12'b0 };
    wire [31:0] imm_J = { {12{w_inst[31]}}, w_inst[19:12], w_inst[20], w_inst[30:25], w_inst[24:21], 1'b0 };
    wire [31:0] imm_C = { 27'b0, w_inst[19:15] };
    
    always @(*) begin
        case (opcode)
            `OPCODE_OP_IMM__ : r_imm = imm_I;
            `OPCODE_STORE___ : r_imm = imm_S;
            `OPCODE_LOAD____ : r_imm = imm_I;
            `OPCODE_LUI_____ : r_imm = imm_U;
            `OPCODE_BRANCH__ : r_imm = imm_B;
            `OPCODE_AUIPC___ : r_imm = imm_U;
            `OPCODE_JAL_____ : r_imm = imm_J;
            `OPCODE_JALR____ : r_imm = imm_I;
            `OPCODE_SYSTEM__ : r_imm = imm_C;
            default          : r_imm = 0;
        endcase
    end
endmodule
/**************************************************************************************************/

/***** ALU for I                                                                              *****/
/**************************************************************************************************/
module m_alu_i (w_in1, w_in2, w_funct3, w_funct7, r_rslt);
    input wire [31:0]   w_in1, w_in2;
    input wire  [2:0]   w_funct3;
    input wire  [6:0]   w_funct7;
    output reg [31:0]   r_rslt;
    
    wire signed [31:0] w_sin1 = w_in1;
    wire signed [31:0] w_sin2 = w_in2;
    
    wire [4:0] w_shamt = w_in2[4:0];
    
    always@(*) begin
        case (w_funct3)
            `FUNCT3_ADD___ : r_rslt = (w_funct7) ? w_in1 - w_in2 : w_in1 + w_in2;
            `FUNCT3_SLL___ : r_rslt = w_in1 << w_shamt;
            `FUNCT3_SLT___ : r_rslt = {31'b0, w_sin1 < w_sin2};
            `FUNCT3_SLTU__ : r_rslt = {31'b0, w_in1 < w_in2};
            `FUNCT3_XOR___ : r_rslt = w_in1 ^ w_in2;
            `FUNCT3_SRL___ : begin
                                if(w_funct7[5]) r_rslt = w_sin1 >>> w_shamt;
                                else            r_rslt = w_in1   >> w_shamt;
                            end
            `FUNCT3_OR____ : r_rslt = w_in1 | w_in2;
            `FUNCT3_AND___ : r_rslt = w_in1 & w_in2;
            default        : begin
`ifdef SIM_MODE
                $write("ILLEGAL INSTRUCTION! in alu_i: w_funct3=%x\n", w_funct3);
`endif
                r_rslt = 0;
`ifdef SIM_MODE
                if(w_funct3 != 3'hz)
                    $finish();
`endif
            end
        endcase
    end
endmodule

/**************************************************************************************************/
module m_decomp(w_ic, r_iw);
    input  wire [31:0] w_ic;
    output reg  [31:0] r_iw;

    // C0
    wire [ 4:0] w_c0_rs1   ={2'b01, w_ic[9:7]};
    wire [ 4:0] w_c0_rs2   ={2'b01, w_ic[4:2]};
    wire [ 4:0] w_c0_rd    ={2'b01, w_ic[4:2]};
    wire [31:0] w_c0_uimm1 ={25'b0, w_ic[5], w_ic[12:10], w_ic[6], 2'b0};
    wire [31:0] w_c0_uimm2 ={24'b0, w_ic[6:5], w_ic[12:10], 3'b0};
    wire [31:0] w_c0_nzuimm={22'b0, w_ic[10:7], w_ic[12:11], w_ic[5], w_ic[6], 2'b0};

    // C1
    wire [ 1:0] w_c1_funct1=w_ic[11:10];
    wire [ 2:0] w_c1_funct2={w_ic[12], w_ic[6:5]};
    wire [ 4:0] w_c1_rs1   ={2'b01, w_ic[9:7]};
    wire [ 4:0] w_c1_rs2   ={2'b01, w_ic[4:2]};
    wire [ 4:0] w_c1_rd    ={2'b01, w_ic[9:7]};
    wire [31:0] w_c1_nzimm ={{27{w_ic[12]}}, w_ic[6:2]};
    wire [ 4:0] w_c1_shamt =w_c1_nzimm[4:0];
    wire [31:0] w_c1_imm1  ={{21{w_ic[12]}}, w_ic[8], w_ic[10:9], w_ic[6], w_ic[7], w_ic[2], w_ic[11], w_ic[5:3],1'b0};
    wire [31:0] w_c1_imm2  ={{25{w_ic[12]}}, w_ic[6:5], w_ic[2], w_ic[11:10], w_ic[4:3], 1'b0};
    wire [31:0] w_c1_imm3  ={{27{w_ic[12]}}, w_ic[6:2]};
    wire [31:0] w_c1_imm4  ={{23{w_ic[12]}}, w_ic[4:3], w_ic[5], w_ic[2], w_ic[6], 4'b0};

    // C2
    wire [ 4:0] w_c2_rs2   =w_ic[6:2];
    wire [ 4:0] w_c2_rd    =w_ic[11:7];
    wire [31:0] w_c2_uimm1 ={23'b0, w_ic[4:2], w_ic[12], w_ic[6:5], 3'b0};
    wire [31:0] w_c2_uimm2 ={24'b0, w_ic[3:2], w_ic[12], w_ic[6:4], 2'b0};
    wire [31:0] w_c2_uimm3 ={22'b0, w_ic[9:7], w_ic[12:10], 3'b0};
    wire [31:0] w_c2_uimm4 ={23'b0, w_ic[8:7], w_ic[12:9], 2'b0};
    wire [31:0] w_c2_nzuimm={26'b0, w_ic[12], w_ic[6:2]};
    wire [ 4:0] w_c2_shamt =w_c2_nzuimm[4:0];

    always @(*) begin
        case ({w_ic[1:0], w_ic[15:13]})
            // C0
            {2'b00, 3'b000}: r_iw={w_c0_nzuimm[11:0],  5'd2, `FUNCT3_ADD___, w_c0_rd, `OPCODE_OP_IMM__};                      // C.ADDI4SPN
            {2'b00, 3'b001}: r_iw={w_c0_uimm2[11:0], w_c0_rs1, `FUNCT3_LD____, w_c0_rd, `OPCODE_LOAD_FP_};                    // C.FLD
            {2'b00, 3'b010}: r_iw={w_c0_uimm1[11:0], w_c0_rs1, `FUNCT3_LW____, w_c0_rd, `OPCODE_LOAD____};                    // C.LW
            {2'b00, 3'b011}: r_iw={w_c0_uimm1[11:0], w_c0_rs1, `FUNCT3_LW____, w_c0_rd, `OPCODE_LOAD_FP_};                    // C.FLW
            {2'b00, 3'b101}: r_iw={w_c0_uimm1[11:5], w_c0_rs2, w_c0_rs1, `FUNCT3_SD____, w_c0_uimm1[4:0], `OPCODE_STORE_FP};  // C.FSD
            {2'b00, 3'b110}: r_iw={w_c0_uimm1[11:5], w_c0_rs2, w_c0_rs1, `FUNCT3_SW____, w_c0_uimm1[4:0], `OPCODE_STORE___};  // C.SW
            {2'b00, 3'b111}: r_iw={w_c0_uimm1[11:5], w_c0_rs2, w_c0_rs1, `FUNCT3_SW____, w_c0_uimm1[4:0], `OPCODE_STORE_FP};  // C.FSW
            // C1
            {2'b01, 3'b000}: r_iw={w_c1_nzimm[11:0], w_ic[11:7], `FUNCT3_ADD___, w_ic[11:7], `OPCODE_OP_IMM__};               // C.ADDI
            {2'b01, 3'b001}: r_iw={w_c1_imm1[20], w_c1_imm1[10:1], w_c1_imm1[11], w_c1_imm1[19:12], 5'd1, `OPCODE_JAL_____};  // C.JAL
            {2'b01, 3'b010}: r_iw={w_c1_imm3[11:0], 5'd0, `FUNCT3_ADD___, w_ic[11:7], `OPCODE_OP_IMM__};                      // C.LI
            {2'b01, 3'b011}:
              begin
                  if (w_ic[11:7] == 2) r_iw={w_c1_imm4[11:0], 5'd2, `FUNCT3_ADD___, 5'd2, `OPCODE_OP_IMM__};                    // C.ADDI16SP
                  else               r_iw={w_c1_nzimm[19:0], w_ic[11:7], `OPCODE_LUI_____};                                     // C.LUI
              end
            {2'b01, 3'b101}: r_iw={w_c1_imm1[20], w_c1_imm1[10:1], w_c1_imm1[11], w_c1_imm1[19:12], 5'd0, `OPCODE_JAL_____};  // C.J
            {2'b01, 3'b110}: r_iw={w_c1_imm2[12], w_c1_imm2[10:5], 5'd0, w_c1_rs1, `FUNCT3_BEQ___, w_c1_imm2[4:1], w_c1_imm2[11], `OPCODE_BRANCH__}; // C.BEQZ
            {2'b01, 3'b111}: r_iw={w_c1_imm2[12], w_c1_imm2[10:5], 5'd0, w_c1_rs1, `FUNCT3_BNE___, w_c1_imm2[4:1], w_c1_imm2[11], `OPCODE_BRANCH__}; // C.BNEZ
            {2'b01, 3'b100}:
              begin
                  case (w_c1_funct1)
                      2'd0: r_iw={w_c1_nzimm[11:0], w_c1_rd, `FUNCT3_SRL___, w_c1_rd, `OPCODE_OP_IMM__};                        // C.SRLI
                      2'd1: r_iw={2'b01, w_c1_nzimm[9:0], w_c1_rd, `FUNCT3_SRL___, w_c1_rd, `OPCODE_OP_IMM__};                  // C.SRAI
                      2'd2: r_iw={w_c1_nzimm[11:0], w_c1_rd, `FUNCT3_AND___, w_c1_rd, `OPCODE_OP_IMM__};                        // C.ANDI
                      2'd3:
                        begin
                            case (w_c1_funct2)
                                3'd0: r_iw={7'b0100000, w_c1_rs2, w_c1_rd, `FUNCT3_ADD___, w_c1_rd, `OPCODE_OP______};            // C.SUB
                                3'd1: r_iw={7'b0, w_c1_rs2, w_c1_rd, `FUNCT3_XOR___, w_c1_rd, `OPCODE_OP______};                  // C.XOR
                                3'd2: r_iw={7'b0, w_c1_rs2, w_c1_rd, `FUNCT3_OR____, w_c1_rd, `OPCODE_OP______};                  // C.OR
                                3'd3: r_iw={7'b0, w_c1_rs2, w_c1_rd, `FUNCT3_AND___, w_c1_rd, `OPCODE_OP______};                  // C.AND
                                default: r_iw=`ILLEGAL_INST;
                            endcase
                        end
                  endcase
              end
            // C2
            {2'b10, 3'b000}: r_iw={7'b0, w_c2_shamt, w_c2_rd, `FUNCT3_SLL___, w_c2_rd, `OPCODE_OP_IMM__};                     // C.SLLI
            {2'b10, 3'b001}: r_iw={w_c2_uimm1[11:0],  5'd2, `FUNCT3_LD____, w_c2_rd, `OPCODE_LOAD_FP_};                       // C.FLDSP
            {2'b10, 3'b010}: r_iw={w_c2_uimm2[11:0],  5'd2, `FUNCT3_LW____, w_c2_rd, `OPCODE_LOAD____};                       // C.LWSP
            {2'b10, 3'b011}: r_iw={w_c2_uimm2[11:0],  5'd2, `FUNCT3_LW____, w_c2_rd, `OPCODE_LOAD_FP_};                       // C.FLWSP
            {2'b10, 3'b101}: r_iw={w_c2_uimm3[11:5], w_c2_rs2, 5'd2, `FUNCT3_SD____, w_c2_uimm3[4:0], `OPCODE_STORE_FP};      // C.FSDSP
            {2'b10, 3'b110}: r_iw={w_c2_uimm4[11:5], w_c2_rs2, 5'd2, `FUNCT3_SW____, w_c2_uimm4[4:0], `OPCODE_STORE___};      // C.SWSP
            {2'b10, 3'b111}: r_iw={w_c2_uimm4[11:5], w_c2_rs2, 5'd2, `FUNCT3_SW____, w_c2_uimm4[4:0], `OPCODE_STORE_FP};      // C.FSWSP
            {2'b10, 3'b100}:
              /*              begin
               if (w_ic[12]) begin
               if (w_c2_rd == 0 && w_c2_rs2 == 0) r_iw={`FUNCT12_EBREAK, 13'b0, `OPCODE_SYSTEM__};                       // C.EBREAK
               if (w_c2_rd != 0 && w_c2_rs2 == 0) r_iw={12'b0, w_c2_rd, 3'b0, 5'd1, `OPCODE_JALR____};                   // C.JALR
               if (w_c2_rd != 0 && w_c2_rs2 != 0) r_iw={7'b0, w_c2_rs2, w_c2_rd, `FUNCT3_ADD___, w_c2_rd, `OPCODE_OP______};  // C.ADD
                end else begin
               if (w_c2_rd != 0 && w_c2_rs2 == 0) r_iw={12'b0, w_c2_rd, 8'b0, `OPCODE_JALR____};                         // C.JR
               if (w_c2_rd != 0 && w_c2_rs2 != 0) r_iw={7'b0, w_c2_rs2, 5'd0, `FUNCT3_ADD___, w_c2_rd, `OPCODE_OP______};// C.MV
                end
            end*/
              if (w_c2_rs2 == 0) begin
                  if (w_c2_rd == 0) r_iw={`FUNCT12_EBREAK, 13'b0, `OPCODE_SYSTEM__}; // C.EBREAK
                  else if (w_ic[12]) r_iw={12'b0, w_c2_rd, 3'b0, 5'd1, `OPCODE_JALR____}; // C.JALR
                  else r_iw={12'b0, w_c2_rd, 8'b0, `OPCODE_JALR____}; // C.JR
              end
              else begin
                  if(w_ic[12]) r_iw={7'b0, w_c2_rs2, w_c2_rd, `FUNCT3_ADD___, w_c2_rd, `OPCODE_OP______};  // C.ADD
                  else r_iw={7'b0, w_c2_rs2, 5'd0, `FUNCT3_ADD___, w_c2_rd, `OPCODE_OP______};// C.MV
              end

            // 32bit
            {2'b11, 3'b000}: r_iw=w_ic;
            {2'b11, 3'b001}: r_iw=w_ic;
            {2'b11, 3'b010}: r_iw=w_ic;
            {2'b11, 3'b011}: r_iw=w_ic;
            {2'b11, 3'b100}: r_iw=w_ic;
            {2'b11, 3'b101}: r_iw=w_ic;
            {2'b11, 3'b110}: r_iw=w_ic;
            {2'b11, 3'b111}: r_iw=w_ic;
            default        : begin
                //$display("r_iw default -------------------------------- %x", {w_ic[1:0], w_ic[15:13]});
                // not defined; it is reserved by riscv authors
                // remove latch warning
                `ifdef CINSN_OLD
                `else
                r_iw=w_ic;
                `endif
            end
        endcase
    end
endmodule
/**************************************************************************************************/
