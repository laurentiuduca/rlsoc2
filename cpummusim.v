`include "define.vh"

module m_cpummusim(
    input wire CLK, RST_X,
    input wire [31:0] w_hart_id,
    input  wire [31:0] w_ipi,
    output wire [31:0] w_mem_paddr,
    output wire w_mem_we,
    output wire [31:0] w_data_wdata,
    input wire [31:0] w_data_data,
    output wire [63:0] w_mtime,
    output wire [63:0] w_mtimecmp,
    input wire [63:0] w_wmtimecmp,
    output wire [2:0] w_pw_state,
    output wire [1:0]  w_tlb_req,
    output wire        w_tlb_busy,
    output wire [31:0] w_mip,
    input wire [31:0]  w_wmip,
    input wire w_proc_busy,
    output wire [31:0] w_dram_addr,
    output wire [31:0] w_dram_wdata,
    input wire  [31:0] w_dram_odata,
    output wire w_dram_we_t,
    input wire w_dram_busy,
    output wire [2:0]   w_dram_ctrl,
    output wire         w_dram_le,
    input wire        w_init_done,
    input wire        w_plic_we,
    input wire        w_clint_we
    );

    wire w_halt;

    wire [31:0] w_insn_data, w_insn_addr;
    wire [31:0] w_data_addr;
    wire        w_data_we;
    wire [2:0]  w_data_ctrl;

    wire [31:0] w_priv, w_satp, w_mstatus;
    wire        w_busy;
    wire [31:0] w_pagefault;
    wire        w_tlb_flush;

    wire        CORE_RST_X = RST_X & w_init_done;

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
        .w_pagefault    (w_pagefault),
        .w_tlb_req      (w_tlb_req),
        .w_tlb_flush    (w_tlb_flush),

        //-------------------------------------------------------------------------------------------------------//
        .w_mem_paddr(w_mem_paddr),
        .w_mem_we(w_mem_we),
        .r_pw_state(w_pw_state),
        .w_tlb_busy(w_tlb_busy),
        .w_dram_addr(w_dram_addr),
        .w_dram_wdata(w_dram_wdata),
        .w_dram_odata(w_dram_odata),
        .w_dram_we_t(w_dram_we_t),
        .w_dram_busy(w_dram_busy),
        .w_dram_ctrl(w_dram_ctrl),
        .w_dram_le(w_dram_le)
    );

    m_RVCoreM p(
        .CLK            (CLK),
        .RST_X          (CORE_RST_X),
        .w_stall        (1'b0),
        .w_hart_id      (w_hart_id),
        .w_ipi          (w_ipi),
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
        .w_busy         (w_proc_busy),
        .w_pagefault    (w_pagefault),
        .w_tlb_req      (w_tlb_req),
        .w_tlb_flush    (w_tlb_flush),
        .w_core_pc      (),
        .w_core_ir      (),
        .w_core_odata   (),
        .w_init_stage   ()
    );

    /**********************************************************************************************/
    always@(posedge CLK) if (w_halt) begin $write("HALT detect! at PC:%x\n", p.pc); $finish(); end
endmodule