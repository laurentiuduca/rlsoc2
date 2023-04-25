`include "define.vh"

module m_cpummusim(
    input wire CLK, RST_X,
    input wire w_tx_ready,
    output wire [31:0] w_mem_paddr,
    output wire w_mem_we,
    output wire [31:0] w_data_wdata,
    input wire [31:0] w_pl_init_data,
    input wire w_pl_init_we,
    input wire w_rxd,
    input wire [31:0] w_data_data,
    output wire [63:0] w_mtime,
    output wire [63:0] w_mtimecmp,
    output wire [1:0]  w_tlb_req,
    output wire        w_tlb_busy,
    output wire [31:0] w_mip,
    output wire [31:0] w_dram_addr,
    output wire [31:0] w_dram_wdata,
    input wire  [31:0] w_dram_odata,
    output wire w_dram_we_t,
    input wire w_dram_busy,
    output wire [2:0]   w_dram_ctrl,
    input wire          w_set_dram_le,
    output wire         w_dram_le,
    input wire        w_init_done,
    input wire [63:0] w_wmtimecmp,
    input wire        w_clint_we
    );

    wire w_halt;

    wire [31:0] w_insn_data, w_insn_addr;
    wire [31:0] w_data_addr;
    wire        w_data_we;
    wire [2:0]  w_data_ctrl;

    wire [31:0] w_priv, w_satp, w_mstatus;
    wire [31:0] w_wmip;
    wire        w_plic_we;
    wire        w_busy;
    wire [31:0] w_pagefault;
    wire        w_tlb_flush;
    wire        w_init_stage;

    wire        CORE_RST_X = RST_X & w_init_done;
    /**********************************************************************************************/

    wire [2:0] w_init_state;

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
        .w_priv         (w_priv),
        .w_satp         (w_satp),
        .w_mstatus      (w_mstatus),
        .w_mtime        (w_mtime),
        .w_mtimecmp     (w_mtimecmp),
        .w_mip          (w_mip),
        .w_wmip         (w_wmip),
        .w_plic_we      (w_plic_we),
        .w_proc_busy    (w_busy),
        .w_pagefault    (w_pagefault),
        .w_tlb_req      (w_tlb_req),
        .w_tlb_flush    (w_tlb_flush),
        .w_rxd          (w_rxd),
        .w_init_done    (w_init_done),
        // input clk, rst (active-low)
        .mig_clk        (1'b0),
        .mig_rst_x      (1'b0),

        // output clk, rst (active-low)
        .o_clk          (),
        .o_rst_x        (),
        .w_checksum     (),
        .w_debug_btnd   (1'b0),

        //-------------------------------------------------------------------------------------------------------//
        .w_tx_ready(w_tx_ready),
        .w_mem_paddr(w_mem_paddr),
        .w_mem_we(w_mem_we),
        .w_pl_init_data(w_pl_init_data),
        .w_pl_init_we(w_pl_init_we),
        .w_tlb_busy(w_tlb_busy),
        .w_dram_addr(w_dram_addr),
        .w_dram_wdata(w_dram_wdata),
        .w_dram_odata(w_dram_odata),
        .w_dram_we_t(w_dram_we_t),
        .w_dram_busy(w_dram_busy),
        .w_dram_ctrl(w_dram_ctrl),
        .w_set_dram_le(w_set_dram_le),
        .w_dram_le(w_dram_le)
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
endmodule