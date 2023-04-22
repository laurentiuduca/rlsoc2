/* Modified by Laurentiu-Cristian Duca, 2021-12-20
 * - memory model similar to dram memory controller with DRAM_SIM
 * or simple memory model
 * - debug with RAM_DEBUG
 * - allow ICARUS simulation
 */
/**************************************************************************************************/
/**** RVSoC (Mini Kuroda/RISC-V)                       since 2018-08-07   ArchLab. TokyoTech   ****/
/**** top module and simulation module v0.01                                                   ****/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**************************************************************************************************/
`ifdef ICARUS
module m_topsim();
    reg CLK = 0;
    reg RST_X;

    initial forever #50 CLK = ~CLK;

    initial begin
        #50  RST_X = 0;
        #300 RST_X = 1;
    end
`ifdef laur0
    initial begin
	$dumpfile("signals.vcd");
        $dumpvars(0, m_topsim);
    end
`endif
`else
module m_topsim(CLK, RST_X);
    input reg CLK, RST_X;
`endif

    wire w_halt;

    wire w_finish;

    wire [31:0] w_insn_data, w_insn_addr;
    wire [31:0] w_data_data, w_data_wdata, w_data_addr;
    wire        w_data_we;
    wire [2:0]  w_data_ctrl;

    wire [31:0] w_priv, w_satp, w_mstatus;
    wire [63:0] w_mtime, w_mtimecmp, w_wmtimecmp;
    wire        w_clint_we;
    wire [31:0] w_mip, w_wmip;
    wire        w_plic_we;
    wire        w_busy;
    wire [31:0] w_pagefault;
    wire [1:0]  w_tlb_req;
    wire        w_tlb_flush;
    wire        w_txd;
    wire        w_rxd;
    wire        w_init_done;
    wire        w_init_stage;

    wire        CORE_RST_X = RST_X & w_init_done;

`ifndef ARTYA7
    wire [15:0] ddr2_dq;
    wire [1:0]  ddr2_dqs_n;
    wire [1:0]  ddr2_dqs_p;
    wire [12:0] ddr2_addr;
    wire [2:0]  ddr2_ba;
    wire        ddr2_ras_n;
    wire        ddr2_cas_n;
    wire        ddr2_we_n;
    wire        ddr2_ck_p;
    wire        ddr2_ck_n;
    wire        ddr2_cke;
    wire        ddr2_cs_n;
    wire [1:0]  ddr2_dm;
    wire        ddr2_odt;
`else
    wire ref_clk;
    wire [15:0] ddr3_dq;
    wire [1:0]  ddr3_dqs_n;
    wire [1:0]  ddr3_dqs_p;
    wire [13:0] ddr3_addr;
    wire [2:0]  ddr3_ba;
    wire        ddr3_ras_n;
    wire        ddr3_cas_n;
    wire        ddr3_we_n;
    wire        ddr3_ck_p;
    wire        ddr3_ck_n;
    wire        ddr3_reset_n;
    wire        ddr3_cke;
    wire        ddr3_cs_n;
    wire [1:0]  ddr3_dm;
    wire        ddr3_odt;
`endif

    wire [15:0] w_led;

    /**********************************************************************************************/

    wire [2:0] w_init_state;
    wire w_pl_init_we;

    /**********************************************************************************************/
    m_mmu mmu(
        .CLK            (CLK),
        .RST_X          (RST_X),
        .w_insn_addr    (w_insn_addr),
        .w_data_addr    (w_data_addr),
        .w_data_wdata   (w_data_wdata),
        .w_data_we      (w_data_we),
        .w_data_ctrl    (w_data_ctrl),
        .w_insn_data    (w_insn_data),
        .w_data_data    (w_data_data),
        .r_finish       (w_finish),
        .w_priv         (w_priv),
        .w_satp         (w_satp),
        .w_mstatus      (w_mstatus),
        .w_mtime        (w_mtime),
        .w_mtimecmp     (w_mtimecmp),
        .w_wmtimecmp    (w_wmtimecmp),
        .w_clint_we     (w_clint_we),
        .w_mip          (w_mip),
        .w_wmip         (w_wmip),
        .w_plic_we      (w_plic_we),
        .w_proc_busy    (w_busy),
        .w_pagefault    (w_pagefault),
        .w_tlb_req      (w_tlb_req),
        .w_tlb_flush    (w_tlb_flush),
        .w_txd          (w_txd),
        .w_rxd          (w_rxd),
        .w_init_done    (w_init_done),
        // input clk, rst (active-low)
        .mig_clk        (1'b0),
        .mig_rst_x      (1'b0),
        // memory interface ports
`ifndef ARTYA7
        .ddr2_dq        (ddr2_dq),
        .ddr2_dqs_n     (ddr2_dqs_n),
        .ddr2_dqs_p     (ddr2_dqs_p),
        .ddr2_addr      (ddr2_addr),
        .ddr2_ba        (ddr2_ba),
        .ddr2_ras_n     (ddr2_ras_n),
        .ddr2_cas_n     (ddr2_cas_n),
        .ddr2_we_n      (ddr2_we_n),
        .ddr2_ck_p      (ddr2_ck_p),
        .ddr2_ck_n      (ddr2_ck_n),
        .ddr2_cke       (ddr2_cke),
        .ddr2_cs_n      (ddr2_cs_n),
        .ddr2_dm        (ddr2_dm),
        .ddr2_odt       (ddr2_odt),
`else
	.ref_clk        (ref_clk),
        .ddr3_dq        (ddr3_dq),
        .ddr3_dqs_n     (ddr3_dqs_n),
        .ddr3_dqs_p     (ddr3_dqs_p),
        .ddr3_addr      (ddr3_addr),
        .ddr3_ba        (ddr3_ba),
        .ddr3_ras_n     (ddr3_ras_n),
        .ddr3_cas_n     (ddr3_cas_n),
        .ddr3_we_n      (ddr3_we_n),
        .ddr3_ck_p      (ddr3_ck_p),
        .ddr3_ck_n      (ddr3_ck_n),
	.ddr3_reset_n   (ddr3_reset_n),
        .ddr3_cke       (ddr3_cke),
        .ddr3_cs_n      (ddr3_cs_n),
        .ddr3_dm        (ddr3_dm),
        .ddr3_odt       (ddr3_odt),
`endif
        // output clk, rst (active-low)
        .o_clk          (),
        .o_rst_x        (),
        .w_led          (w_led),
        .w_init_stage   (w_init_stage),
        .w_checksum     (),
        .w_debug_btnd   (1'b0),
	.w_init_state   (w_init_state),
	.w_pl_init_we   (w_pl_init_we)
    );

    m_RVCoreM p(
        .CLK            (CLK),
        .RST_X          (CORE_RST_X),
        .w_stall        (1'b0),
        .r_halt         (w_halt),
        .w_insn_addr    (w_insn_addr),
        .w_data_addr    (w_data_addr),
        .w_insn_data    (w_insn_data),
        .w_data_data    (w_data_data),
        .w_data_wdata   (w_data_wdata),
        .w_data_we      (w_data_we),
        .w_data_ctrl    (w_data_ctrl),
        .w_priv         (w_priv),
        .w_satp         (w_satp),
        .w_mstatus      (w_mstatus),
        .w_mtime        (w_mtime),
        .w_mtimecmp     (w_mtimecmp),
        .w_wmtimecmp    (w_wmtimecmp),
        .w_clint_we     (w_clint_we),
        .w_mip          (w_mip),
        .w_wmip         (w_wmip),
        .w_plic_we      (w_plic_we),
        .w_busy         (w_busy),
        .w_pagefault    (w_pagefault),
        .w_tlb_req      (w_tlb_req),
        .w_tlb_flush    (w_tlb_flush),
        .w_core_pc      (),
        .w_core_ir      (),
        .w_core_odata   (),
        .w_init_stage   (w_init_stage)
    );

    /**********************************************************************************************/
    always@(posedge CLK) if (w_halt) begin $write("HALT detect! at PC:%x\n", p.pc); $finish(); end
    reg r_finish = 0;
    always@(posedge CLK) r_finish <= w_finish;
    always@(posedge CLK) if (r_finish) begin
        $write("FINISH!\n");
        $finish();
    end

    /**********************************************************************************************/
    // LOAD linux
    integer i,j;
    //integer k;
    reg  [7:0] mem_bbl [0:`BBL_SIZE-1];
    reg  [7:0] mem_disk[0:`DISK_SIZE-1];
    initial begin
`ifndef VERILATOR
    #1
`endif
`ifdef LINUX
        $write("Load image file: %s\n", `IMAGE_FILE);
        $readmemh(`IMAGE_FILE, mem_disk);
        j=`BBL_SIZE;

        for(i=0;i<`DISK_SIZE;i=i+1) begin
`ifdef DRAM_SIM
`ifdef SKIP_CACHE
	    mmu.idbmem.idbmem.mem[j]=mem_disk[i];
`else
	    mmu.idbmem.cache_ctrl.idbmem.mem[j]=mem_disk[i];
`endif
`else
	    mmu.idbmem.idbmem.mem[j]=mem_disk[i];
`endif // DRAM_SIM
            j=j+1;
        end
`endif // LINUX
        $write("Running %s\n", {`HEX_DIR,`HEXFILE});
        $readmemh({`HEX_DIR,`HEXFILE}, mem_bbl);
        j=0;

        for(i=0;i<`BBL_SIZE;i=i+1) begin
`ifdef DRAM_SIM
`ifdef SKIP_CACHE
            mmu.idbmem.idbmem.mem[j]=mem_bbl[i];
`else
	    mmu.idbmem.cache_ctrl.idbmem.mem[j]=mem_bbl[i];
`endif
`else
	    mmu.idbmem.idbmem.mem[j]=mem_bbl[i];
`endif // DRAM_SIM
            j=j+1;
        end
        $write("-------------------------------------------------------------------\n");
    end

/**********************************************************************************************/

endmodule

