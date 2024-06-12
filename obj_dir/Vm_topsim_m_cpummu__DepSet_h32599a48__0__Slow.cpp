// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim_m_cpummu.h"

VL_ATTR_COLD void Vm_topsim_m_cpummu___eval_static__TOP__m_topsim__DOT__core0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___eval_static__TOP__m_topsim__DOT__core0\n"); );
    // Body
    vlSelf->mmu__DOT__physical_addr = 0U;
    vlSelf->mmu__DOT__page_walk_fail = 0U;
    vlSelf->mmu__DOT__r_pw_state = 0U;
    vlSelf->mmu__DOT__L1_pte = 0U;
    vlSelf->mmu__DOT__L0_pte = 0U;
    vlSelf->mmu__DOT__r_mc_mode = 0U;
    vlSelf->mmu__DOT__r_tlb_addr = 0U;
    vlSelf->mmu__DOT__r_tlb_use = 0U;
    vlSelf->mmu__DOT__r_dram_was_busy = 0U;
    vlSelf->mmu__DOT__r_dram_took_cmd = 0U;
    vlSelf->mmu__DOT__r_data_was_busy = 0U;
    vlSelf->mmu__DOT__r_tlb_pte_addr = 0U;
    vlSelf->mmu__DOT__r_tlb_acs = 0U;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid = 0U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid = 0U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid = 0U;
    vlSelf->w_state = 0U;
    vlSelf->w_pc = 0x80700000U;
    vlSelf->w_pc_stip = 0U;
    vlSelf->p__DOT__mstatus = 0U;
    vlSelf->p__DOT__mtvec = 0U;
    vlSelf->p__DOT__mscratch = 0U;
    vlSelf->p__DOT__mepc = 0U;
    vlSelf->p__DOT__mcause = 0U;
    vlSelf->p__DOT__mtval = 0U;
    vlSelf->p__DOT__misa = 0x141105U;
    vlSelf->p__DOT__mie = 0U;
    vlSelf->p__DOT__mip = 0U;
    vlSelf->p__DOT__medeleg = 0U;
    vlSelf->p__DOT__mideleg = 0U;
    vlSelf->p__DOT__mcounteren = 0U;
    vlSelf->p__DOT__stvec = 0U;
    vlSelf->p__DOT__sscratch = 0U;
    vlSelf->p__DOT__sepc = 0U;
    vlSelf->p__DOT__scause = 0U;
    vlSelf->p__DOT__stval = 0U;
    vlSelf->p__DOT__satp = 0U;
    vlSelf->p__DOT__scounteren = 0U;
    vlSelf->w_load_res = 0U;
    vlSelf->w_reserved = 0U;
    vlSelf->p__DOT__priv = 3U;
    vlSelf->p__DOT__mtimecmp = 0ULL;
    vlSelf->p__DOT__r_was_clint_we = 0U;
    vlSelf->p__DOT__pending_tval = 0U;
    vlSelf->p__DOT__pending_exception = 0xffffffffU;
    vlSelf->p__DOT__r_cpc = 0U;
    vlSelf->p__DOT__r_ir_org = 0U;
    vlSelf->p__DOT__r_cinsn = 0U;
    vlSelf->w_ir = 0U;
    vlSelf->p__DOT__r_ir16 = 0U;
    vlSelf->p__DOT__r_ir16_v = 0U;
    vlSelf->p__DOT__r_opcode = 0U;
    vlSelf->p__DOT__r_rd = 0U;
    vlSelf->p__DOT__r_rs1 = 0U;
    vlSelf->p__DOT__r_rs2 = 0U;
    vlSelf->p__DOT__r_funct3 = 0U;
    vlSelf->p__DOT__r_funct5 = 0U;
    vlSelf->p__DOT__r_funct7 = 0U;
    vlSelf->p__DOT__r_funct12 = 0U;
    vlSelf->p__DOT__r_imm = 0U;
    vlSelf->p__DOT__r_op_AMO_SC = 0U;
    vlSelf->p__DOT__r_op_AMO_LR = 0U;
    vlSelf->p__DOT__r_op_LOAD = 0U;
    vlSelf->p__DOT__r_op_STORE = 0U;
    vlSelf->p__DOT__r_op_AMO = 0U;
    vlSelf->p__DOT__r_op_SYS = 0U;
    vlSelf->p__DOT__r_op_ECALL = 0U;
    vlSelf->p__DOT__r_op_SRET = 0U;
    vlSelf->p__DOT__r_op_MRET = 0U;
    vlSelf->p__DOT__r_op_CSR_MSTA = 0U;
    vlSelf->p__DOT__r_op_CSR_SSTA = 0U;
    vlSelf->p__DOT__r_rrs1 = 0U;
    vlSelf->p__DOT__r_rrs2 = 0U;
    vlSelf->p__DOT__r_rcsr = 0U;
    vlSelf->p__DOT__r_alu_in2 = 0U;
    vlSelf->p__DOT__r_alu_f7 = 0U;
    vlSelf->p__DOT__r_tkn = 0U;
    vlSelf->p__DOT__r_jmp_pc = 0U;
    vlSelf->p__DOT__r_mem_addr = 0U;
    vlSelf->p__DOT__r_wb_data = 0U;
    vlSelf->p__DOT__r_wb_data_csr = 0U;
    vlSelf->p__DOT__r_mem_rdata = 0U;
    vlSelf->p__DOT__r_atom_wdata = 0U;
    vlSelf->p__DOT__e_icount = 1ULL;
    vlSelf->p__DOT__r_if_done = 0U;
    vlSelf->p__DOT__r_if_irl = 0U;
    vlSelf->p__DOT__r_rcsr_t = 0U;
    vlSelf->p__DOT__irq_num = 0U;
    vlSelf->p__DOT__r_if_state = 0U;
    vlSelf->p__DOT__r_init_stage = 0U;
    vlSelf->p__DOT__r_insn_addr = 0U;
    vlSelf->p__DOT__r_mul_SS = 0ULL;
    vlSelf->p__DOT__r_mul_SU = 0ULL;
    vlSelf->p__DOT__r_mul_UU = 0ULL;
    vlSelf->p__DOT__r_data_ctrl = 0U;
    vlSelf->p__DOT__r_data_wdata = 0U;
    vlSelf->p__DOT__r_mstatus_t = 0U;
    vlSelf->p__DOT__r_priv_t = 3U;
    vlSelf->p__DOT__laurpc = 0U;
    vlSelf->p__DOT__closed = 0U;
    vlSelf->p__DOT__r_ipi_max_displays = 0U;
    vlSelf->w_ipi_taken = 0U;
    vlSelf->p__DOT__rim = 0U;
    vlSelf->p__DOT__r_data_we = 0U;
    vlSelf->p__DOT__r_data_en = 0U;
    vlSelf->p__DOT__r_tlb_req = 0U;
    vlSelf->p__DOT__ALU_IM__DOT__r_div_first = 1U;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend = 0U;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor = 0U;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor = 0U;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count = 0U;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___eval_initial__TOP__m_topsim__DOT__core0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___eval_initial__TOP__m_topsim__DOT__core0\n"); );
    // Body
    vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[0U] = 0ULL;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__i = 1U;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[1U] = 0ULL;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__i = 2U;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[2U] = 0ULL;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__i = 3U;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[3U] = 0ULL;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__i = 4U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__mem[0U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_r__DOT__i = 1U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__mem[1U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_r__DOT__i = 2U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__mem[2U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_r__DOT__i = 3U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__mem[3U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_r__DOT__i = 4U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__mem[0U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_w__DOT__i = 1U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__mem[1U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_w__DOT__i = 2U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__mem[2U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_w__DOT__i = 3U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__mem[3U] = 0ULL;
    vlSelf->mmu__DOT__TLB_data_w__DOT__i = 4U;
    vlSelf->p__DOT__f = VL_FOPEN_NN(std::string{"stip.txt"}
                                    , std::string{"w"});
    vlSelf->w_halt = 0U;
    vlSelf->p__DOT__w_core_odata = 0U;
    vlSelf->p__DOT__regs__DOT__mem[0U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 1U;
    vlSelf->p__DOT__regs__DOT__mem[1U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 2U;
    vlSelf->p__DOT__regs__DOT__mem[2U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 3U;
    vlSelf->p__DOT__regs__DOT__mem[3U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 4U;
    vlSelf->p__DOT__regs__DOT__mem[4U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 5U;
    vlSelf->p__DOT__regs__DOT__mem[5U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 6U;
    vlSelf->p__DOT__regs__DOT__mem[6U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 7U;
    vlSelf->p__DOT__regs__DOT__mem[7U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 8U;
    vlSelf->p__DOT__regs__DOT__mem[8U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 9U;
    vlSelf->p__DOT__regs__DOT__mem[9U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xaU;
    vlSelf->p__DOT__regs__DOT__mem[0xaU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xbU;
    vlSelf->p__DOT__regs__DOT__mem[0xbU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xcU;
    vlSelf->p__DOT__regs__DOT__mem[0xcU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xdU;
    vlSelf->p__DOT__regs__DOT__mem[0xdU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xeU;
    vlSelf->p__DOT__regs__DOT__mem[0xeU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0xfU;
    vlSelf->p__DOT__regs__DOT__mem[0xfU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x10U;
    vlSelf->p__DOT__regs__DOT__mem[0x10U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x11U;
    vlSelf->p__DOT__regs__DOT__mem[0x11U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x12U;
    vlSelf->p__DOT__regs__DOT__mem[0x12U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x13U;
    vlSelf->p__DOT__regs__DOT__mem[0x13U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x14U;
    vlSelf->p__DOT__regs__DOT__mem[0x14U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x15U;
    vlSelf->p__DOT__regs__DOT__mem[0x15U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x16U;
    vlSelf->p__DOT__regs__DOT__mem[0x16U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x17U;
    vlSelf->p__DOT__regs__DOT__mem[0x17U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x18U;
    vlSelf->p__DOT__regs__DOT__mem[0x18U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x19U;
    vlSelf->p__DOT__regs__DOT__mem[0x19U] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1aU;
    vlSelf->p__DOT__regs__DOT__mem[0x1aU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1bU;
    vlSelf->p__DOT__regs__DOT__mem[0x1bU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1cU;
    vlSelf->p__DOT__regs__DOT__mem[0x1cU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1dU;
    vlSelf->p__DOT__regs__DOT__mem[0x1dU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1eU;
    vlSelf->p__DOT__regs__DOT__mem[0x1eU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x1fU;
    vlSelf->p__DOT__regs__DOT__mem[0x1fU] = 0U;
    vlSelf->p__DOT__regs__DOT__i = 0x20U;
    vlSelf->p__DOT__regs__DOT__mem[0xaU] = vlSelf->w_hart_id;
    vlSelf->p__DOT__regs__DOT__mem[0xbU] = 0x600000U;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__RST_X = 1U;
    vlSelf->mmu__DOT__TLB_data_r__DOT__RST_X = 1U;
    vlSelf->mmu__DOT__TLB_data_w__DOT__RST_X = 1U;
    vlSelf->p__DOT__w_stall = 0U;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__0\n"); );
    // Init
    CData/*0:0*/ mmu__DOT____VdfgTmp_hdf96e1fa__0;
    QData/*63:0*/ mmu__DOT____VdfgTmp_h0821c8f5__0;
    QData/*63:0*/ mmu__DOT____VdfgTmp_hd62e4571__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h2aff9416__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h5ee52748__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h1f4b0050__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_hdc3ed8a3__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h1a37559d__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h8d9b33e2__0;
    QData/*39:0*/ mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0;
    QData/*39:0*/ mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0;
    QData/*39:0*/ mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0;
    QData/*63:0*/ p__DOT____VdfgTmp_hc363607f__0;
    IData/*31:0*/ p__DOT____VdfgTmp_h17b05525__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0;
    CData/*7:0*/ p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0;
    SData/*9:0*/ p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0;
    SData/*8:0*/ p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0;
    CData/*7:0*/ p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0;
    CData/*4:0*/ p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0;
    SData/*9:0*/ p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0;
    SData/*11:0*/ p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0;
    SData/*11:0*/ p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0;
    IData/*19:0*/ p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0;
    CData/*1:0*/ p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0;
    CData/*0:0*/ p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0;
    // Body
    vlSelf->mmu__DOT__w_hart_id = vlSelf->w_hart_id;
    vlSelf->mmu__DOT__w_pc = vlSelf->w_pc;
    vlSelf->mmu__DOT__w_ir = vlSelf->w_ir;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->p__DOT__r_halt = vlSelf->w_halt;
    vlSelf->p__DOT__state = vlSelf->w_state;
    vlSelf->p__DOT__pc = vlSelf->w_pc;
    vlSelf->p__DOT__pc_stip = vlSelf->w_pc_stip;
    vlSelf->p__DOT__reserved = vlSelf->w_reserved;
    vlSelf->p__DOT__load_res = vlSelf->w_load_res;
    vlSelf->p__DOT__r_ipi_taken = vlSelf->w_ipi_taken;
    vlSelf->p__DOT__regs__DOT__rd = vlSelf->p__DOT__r_rd;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct7 = vlSelf->p__DOT__r_alu_f7;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SS = vlSelf->p__DOT__r_mul_SS;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SU = vlSelf->p__DOT__r_mul_SU;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_UU = vlSelf->p__DOT__r_mul_UU;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_rslt 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt;
    vlSelf->p__DOT__ALU_B__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_B__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_B__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_C__DOT__w_rcsr = vlSelf->p__DOT__r_rcsr;
    vlSelf->p__DOT__ALU_C__DOT__w_rrs1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_C__DOT__w_imm = vlSelf->p__DOT__r_imm;
    vlSelf->p__DOT__ALU_C__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_A__DOT__w_in1 = vlSelf->p__DOT__r_rrs2;
    vlSelf->p__DOT__ALU_A__DOT__w_funct5 = vlSelf->p__DOT__r_funct5;
    vlSelf->mmu__DOT__L0_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L0_pte 
                                                 << 2U));
    vlSelf->p__DOT__w_vadr2 = ((IData)(2U) + vlSelf->w_pc);
    vlSelf->p__DOT__w_vadr1 = (0xfffffffcU & vlSelf->w_pc);
    vlSelf->p__DOT__w_core_pc = vlSelf->w_pc;
    vlSelf->p__DOT__w_init_stage = vlSelf->p__DOT__r_init_stage;
    vlSelf->p__DOT__w_mul_UU = ((QData)((IData)(vlSelf->p__DOT__r_rrs1)) 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ 
        = (0x1ffffffffULL & ((vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                              >> 0x1fU) - (QData)((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor))));
    vlSelf->p__DOT__w_executing_wfi = ((0x73U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                       & ((0U == (IData)(vlSelf->p__DOT__r_funct3)) 
                                          & (0x105U 
                                             == (IData)(vlSelf->p__DOT__r_funct12))));
    vlSelf->p__DOT__w_hart_id = vlSelf->w_hart_id;
    vlSelf->p__DOT__r_ir = vlSelf->w_ir;
    vlSelf->p__DOT__ALU_IM__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_IM__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_IM__DOT__w_sin2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__w_mem_addr = (((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                   | (IData)(vlSelf->p__DOT__r_op_STORE))
                                   ? (vlSelf->p__DOT__r_imm 
                                      + vlSelf->p__DOT__r_rrs1)
                                   : ((IData)(vlSelf->p__DOT__r_op_AMO)
                                       ? vlSelf->p__DOT__r_rrs1
                                       : 0U));
    vlSelf->w_insn_addr = vlSelf->p__DOT__r_insn_addr;
    vlSelf->w_data_addr = vlSelf->p__DOT__r_mem_addr;
    vlSelf->w_proc_data_we = vlSelf->p__DOT__r_data_we;
    vlSelf->w_data_ctrl = vlSelf->p__DOT__r_data_ctrl;
    vlSelf->w_priv = vlSelf->p__DOT__priv;
    vlSelf->w_satp = vlSelf->p__DOT__satp;
    vlSelf->w_mstatus = vlSelf->p__DOT__mstatus;
    vlSelf->w_mtimecmp = vlSelf->p__DOT__mtimecmp;
    p__DOT____VdfgTmp_hc363607f__0 = (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelf->p__DOT__r_rrs1 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs1)));
    vlSelf->mmu__DOT__w_tlb_wdata = (0x3ffffcU & (vlSelf->mmu__DOT__physical_addr 
                                                  >> 0xaU));
    vlSelf->p__DOT__w_rs2 = (0x1fU & (vlSelf->w_ir 
                                      >> 0x14U));
    vlSelf->w_data_wdata = vlSelf->p__DOT__r_data_wdata;
    vlSelf->w_hart_sc = vlSelf->p__DOT__r_op_AMO_SC;
    vlSelf->p__DOT__w_sin2 = vlSelf->p__DOT__r_rrs2;
    vlSelf->p__DOT__imm_gen0__DOT__imm_I = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xbU) 
                                            | (0x7ffU 
                                               & (vlSelf->w_ir 
                                                  >> 0x14U)));
    vlSelf->p__DOT__imm_gen0__DOT__imm_S = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xbU) 
                                            | ((0x7e0U 
                                                & (vlSelf->w_ir 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->w_ir 
                                                     >> 7U))));
    vlSelf->p__DOT__imm_gen0__DOT__imm_U = (0xfffff000U 
                                            & vlSelf->w_ir);
    vlSelf->p__DOT__imm_gen0__DOT__imm_B = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xcU) 
                                            | ((0x800U 
                                                & (vlSelf->w_ir 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->w_ir 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->w_ir 
                                                        >> 7U)))));
    vlSelf->p__DOT__imm_gen0__DOT__imm_J = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0x14U) 
                                            | ((0xff000U 
                                                & vlSelf->w_ir) 
                                               | ((0x800U 
                                                   & (vlSelf->w_ir 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->w_ir 
                                                        >> 0x14U)))));
    vlSelf->w_core_ir = vlSelf->w_ir;
    mmu__DOT____VdfgTmp_hdf96e1fa__0 = ((0U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    mmu__DOT____VdfgTmp_h0821c8f5__0 = (((QData)((IData)(
                                                         (vlSelf->p__DOT__mtimecmp 
                                                          >> 0x20U))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__r_data_wdata)));
    mmu__DOT____VdfgTmp_hd62e4571__0 = (((QData)((IData)(vlSelf->p__DOT__r_data_wdata)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__mtimecmp)));
    mmu__DOT____VdfgTmp_h2aff9416__0 = ((1U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    vlSelf->p__DOT__ALU_IM__DOT__w_shamt = (0x1fU & vlSelf->p__DOT__r_alu_in2);
    vlSelf->w_mip = vlSelf->p__DOT__mip;
    vlSelf->p__DOT__imm_gen0__DOT__opcode = (0x7fU 
                                             & vlSelf->w_ir);
    vlSelf->p__DOT__w_sin1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__w_rs1 = (0x1fU & (vlSelf->w_ir 
                                      >> 0xfU));
    vlSelf->w_tlb_req = vlSelf->p__DOT__r_tlb_req;
    vlSelf->p__DOT__mhartid = vlSelf->w_hart_id;
    p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0 
        = VL_LTS_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2);
    vlSelf->p__DOT__w_csr_addr = (0xfffU & ((0U != (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (IData)(vlSelf->p__DOT__r_funct12)
                                             : ((0U 
                                                 == (IData)(vlSelf->p__DOT__r_funct12))
                                                 ? 0x305U
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelf->p__DOT__r_funct12))
                                                  ? 0x41U
                                                  : 
                                                 ((0x102U 
                                                   == (IData)(vlSelf->p__DOT__r_funct12))
                                                   ? 0x141U
                                                   : 
                                                  ((0x302U 
                                                    == (IData)(vlSelf->p__DOT__r_funct12))
                                                    ? 0x341U
                                                    : 0U))))));
    vlSelf->p__DOT____VdfgTmp_h8573667a__0 = ((~ (IData)(vlSelf->p__DOT__r_op_AMO_SC)) 
                                              & (IData)(vlSelf->p__DOT__r_op_AMO));
    p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend) 
            << 1U) | (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor));
    vlSelf->p__DOT__w_take_int = ((5U != vlSelf->p__DOT__irq_num) 
                                  | ((~ (IData)(vlSelf->p__DOT__r_op_ECALL)) 
                                     & ((~ (IData)(vlSelf->p__DOT__r_op_SRET)) 
                                        & (1U >= (IData)(vlSelf->p__DOT__priv)))));
    vlSelf->p__DOT__w_nalign4 = (7U == (7U & (vlSelf->w_pc 
                                              >> 1U)));
    mmu__DOT____VdfgTmp_h1a37559d__0 = ((~ (IData)(vlSelf->mmu__DOT__page_walk_fail)) 
                                        & (5U == (IData)(vlSelf->mmu__DOT__r_pw_state)));
    if ((0x80000U & vlSelf->p__DOT__mstatus)) {
        vlSelf->mmu__DOT__L0_xwr = (7U & ((vlSelf->mmu__DOT__L0_pte 
                                           >> 1U) | 
                                          (1U & (vlSelf->mmu__DOT__L0_pte 
                                                 >> 3U))));
        vlSelf->mmu__DOT__L1_xwr = (7U & ((vlSelf->mmu__DOT__L1_pte 
                                           >> 1U) | 
                                          (1U & (vlSelf->mmu__DOT__L1_pte 
                                                 >> 3U))));
    } else {
        vlSelf->mmu__DOT__L0_xwr = (7U & (vlSelf->mmu__DOT__L0_pte 
                                          >> 1U));
        vlSelf->mmu__DOT__L1_xwr = (7U & (vlSelf->mmu__DOT__L1_pte 
                                          >> 1U));
    }
    vlSelf->p__DOT__w_mstatus_t = (0x6000U | vlSelf->p__DOT__mstatus);
    vlSelf->p__DOT__ALU_IM__DOT__w_div_signed = ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | (6U 
                                                    == (IData)(vlSelf->p__DOT__r_funct3)));
    vlSelf->mmu__DOT__r_tlb_acs = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                   | ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                      | (5U == (IData)(vlSelf->mmu__DOT__r_pw_state))));
    vlSelf->p__DOT__ALU_IM__DOT__w_div_req = ((IData)(vlSelf->p__DOT__r_alu_f7) 
                                              & ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                    | ((6U 
                                                        == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                       | (7U 
                                                          == (IData)(vlSelf->p__DOT__r_funct3))))));
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy = (0x20U 
                                                   > (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count));
    vlSelf->p__DOT__pending_interrupts = (vlSelf->p__DOT__mie 
                                          & vlSelf->p__DOT__mip);
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag = (vlSelf->p__DOT__r_insn_addr 
                                                 >> 0xeU);
    vlSelf->p__DOT__w_csr_we = ((IData)(vlSelf->p__DOT__r_op_SYS) 
                                & (0U != (IData)(vlSelf->p__DOT__r_funct3)));
    vlSelf->p__DOT__w_sstatus = ((0xfff21eccU & vlSelf->p__DOT__mstatus) 
                                 | (0xde133U & vlSelf->p__DOT__r_wb_data_csr));
    vlSelf->p__DOT__w_ex1 = (5U == (IData)(vlSelf->w_state));
    vlSelf->mmu__DOT__L1_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L1_pte 
                                                 << 2U));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_insn_addr 
                                                    >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag = (vlSelf->p__DOT__r_mem_addr 
                                                 >> 0xeU);
    vlSelf->mmu__DOT__w_isread = (0U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_mem_addr 
                                                    >> 0xcU));
    vlSelf->mmu__DOT__w_iswrite = (1U == (IData)(vlSelf->p__DOT__r_tlb_req));
    mmu__DOT____VdfgTmp_h5ee52748__0 = (1U & ((~ (vlSelf->p__DOT__satp 
                                                  >> 0x1fU)) 
                                              | (3U 
                                                 == (IData)(vlSelf->p__DOT__priv))));
    vlSelf->mmu__DOT__w_iscode = (2U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__w_tx_ready = vlSelf->w_tx_ready;
    vlSelf->mmu__DOT__RST_X = vlSelf->RST_X;
    vlSelf->mmu__DOT__w_dram_busy = vlSelf->w_dram_busy;
    vlSelf->mmu__DOT__w_data_busy = vlSelf->w_data_busy;
    vlSelf->p__DOT__w_oh_load_res = vlSelf->w_oh_load_res;
    vlSelf->p__DOT__w_oh_reserved = vlSelf->w_oh_reserved;
    vlSelf->p__DOT__w_oh_pc = vlSelf->w_oh_pc;
    vlSelf->p__DOT__w_plic_we = vlSelf->w_plic_we;
    vlSelf->p__DOT__w_wmip = vlSelf->w_wmip;
    vlSelf->p__DOT__w_ipi = vlSelf->w_ipi;
    vlSelf->mmu__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_data_data = vlSelf->w_data_data;
    vlSelf->p__DOT__w_mem_rdata = vlSelf->w_data_data;
    vlSelf->p__DOT__w_alu_c_rslt = ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                     ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_imm))
                                             : (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_imm))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? vlSelf->p__DOT__r_imm
                                             : 0U))
                                     : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_rrs1))
                                             : (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_rrs1))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? vlSelf->p__DOT__r_rrs1
                                             : 0U)));
    vlSelf->p__DOT__cause = ((0xffffffffU != vlSelf->p__DOT__pending_exception)
                              ? vlSelf->p__DOT__pending_exception
                              : (0x80000000U | vlSelf->p__DOT__irq_num));
    vlSelf->mmu__DOT__w_mem_wdata = ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))
                                      ? vlSelf->mmu__DOT__w_mc_wdata
                                      : vlSelf->p__DOT__r_data_wdata);
    if ((0U != (0xe0000U & vlSelf->p__DOT__mstatus))) {
        if (VL_UNLIKELY((0U != (0x20000U & vlSelf->p__DOT__mstatus)))) {
            VL_WRITEF("%x MSTATUS_MPRV mpp=%x --------------------\n",
                      64,vlSelf->w_mtime,32,(0x1800U 
                                             & vlSelf->p__DOT__mstatus));
        }
        if (VL_UNLIKELY((0U != (0x80000U & vlSelf->p__DOT__mstatus)))) {
            VL_WRITEF("%x MSTATUS_MXR --------------------------\n",
                      64,vlSelf->w_mtime);
        }
    }
    vlSelf->p__DOT__w_mstatus_nxt = ((0xffffffffU != vlSelf->p__DOT__pending_exception)
                                      ? vlSelf->p__DOT__r_mstatus_t
                                      : (((IData)(vlSelf->p__DOT__w_csr_we) 
                                          & (0x300U 
                                             == (IData)(vlSelf->p__DOT__r_funct12)))
                                          ? ((0xfff1e644U 
                                              & vlSelf->p__DOT__mstatus) 
                                             | (0xe19bbU 
                                                & vlSelf->p__DOT__r_wb_data_csr))
                                          : (((IData)(vlSelf->p__DOT__w_csr_we) 
                                              & (0x100U 
                                                 == (IData)(vlSelf->p__DOT__r_funct12)))
                                              ? ((0xfff1e644U 
                                                  & vlSelf->p__DOT__mstatus) 
                                                 | (0xe19bbU 
                                                    & vlSelf->p__DOT__w_sstatus))
                                              : vlSelf->p__DOT__r_mstatus_t)));
    vlSelf->p__DOT__w_alu_b_rslt = ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                     ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rrs1 
                                                >= vlSelf->p__DOT__r_alu_in2)
                                             : (vlSelf->p__DOT__r_rrs1 
                                                < vlSelf->p__DOT__r_alu_in2))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? VL_GTES_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2)
                                             : (IData)(p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0)))
                                     : ((~ ((IData)(vlSelf->p__DOT__r_funct3) 
                                            >> 1U)) 
                                        & ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                            ? (vlSelf->p__DOT__r_rrs1 
                                               != vlSelf->p__DOT__r_alu_in2)
                                            : (vlSelf->p__DOT__r_rrs1 
                                               == vlSelf->p__DOT__r_alu_in2))));
    vlSelf->p__DOT__w_mtime = vlSelf->w_mtime;
    vlSelf->mmu__DOT__CLK = vlSelf->CLK;
    vlSelf->p__DOT__CLK = vlSelf->CLK;
    vlSelf->CORE_RST_X = ((IData)(vlSelf->RST_X) & (IData)(vlSelf->w_init_done));
    vlSelf->mmu__DOT__w_dram_odata = vlSelf->w_dram_odata;
    vlSelf->w_insn_data = vlSelf->w_dram_odata;
    vlSelf->p__DOT__w_ir_org = ((3U == (IData)(vlSelf->p__DOT__r_if_state))
                                 ? ((IData)(vlSelf->p__DOT__r_ir16_v)
                                     ? ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_ir16))
                                     : ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_if_irl)))
                                 : vlSelf->w_dram_odata);
    vlSelf->p__DOT__regs__DOT__w_hart_id = vlSelf->p__DOT__w_hart_id;
    vlSelf->p__DOT__imm_gen0__DOT__w_inst = vlSelf->p__DOT__r_ir;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_dividend 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in1;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_divisor 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in2;
    vlSelf->p__DOT__ALU_B__DOT__w_sin2 = vlSelf->p__DOT__ALU_IM__DOT__w_sin2;
    vlSelf->p__DOT__ALU_C__DOT__r_rslt = vlSelf->p__DOT__w_alu_c_rslt;
    vlSelf->mmu__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->p__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->mmu__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->p__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->mmu__DOT__w_proc_data_we = vlSelf->w_proc_data_we;
    vlSelf->p__DOT__w_data_we = vlSelf->w_proc_data_we;
    vlSelf->mmu__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->p__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->mmu__DOT__w_priv = vlSelf->w_priv;
    vlSelf->p__DOT__w_priv = vlSelf->w_priv;
    vlSelf->mmu__DOT__w_satp = vlSelf->w_satp;
    vlSelf->p__DOT__w_satp = vlSelf->w_satp;
    vlSelf->mmu__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->p__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->mmu__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_deleg = ((1U >= (IData)(vlSelf->p__DOT__r_priv_t))
                                ? ((0U != (0x80000000U 
                                           & vlSelf->p__DOT__cause))
                                    ? ((0x1fU >= (0x1fU 
                                                  & vlSelf->p__DOT__cause))
                                        ? (1U & (vlSelf->p__DOT__mideleg 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->p__DOT__cause)))
                                        : 0U) : ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->p__DOT__cause))
                                                  ? 
                                                 (1U 
                                                  & (vlSelf->p__DOT__medeleg 
                                                     >> 
                                                     (0x1fU 
                                                      & vlSelf->p__DOT__cause)))
                                                  : 0U))
                                : 0U);
    vlSelf->p__DOT__w_mul_SS = (p__DOT____VdfgTmp_hc363607f__0 
                                * (((QData)((IData)(
                                                    (- (IData)(
                                                               (vlSelf->p__DOT__r_rrs2 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs2))));
    vlSelf->p__DOT__w_mul_SU = (p__DOT____VdfgTmp_hc363607f__0 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->p__DOT__regs__DOT__w_rs2 = vlSelf->p__DOT__w_rs2;
    vlSelf->p__DOT__w_rrs2 = ((0U == (IData)(vlSelf->p__DOT__w_rs2))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs2]);
    vlSelf->mmu__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->p__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->p__DOT__hart_sc = vlSelf->w_hart_sc;
    vlSelf->p__DOT__ALU_A__DOT__w_sin1 = vlSelf->p__DOT__w_sin2;
    vlSelf->p__DOT__w_core_ir = vlSelf->w_core_ir;
    vlSelf->p__DOT__w_mip = vlSelf->w_mip;
    vlSelf->p__DOT__w_op_priv = (IData)(((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                         & (0U == (0x7000U 
                                                   & vlSelf->w_ir))));
    vlSelf->p__DOT__w_op_csr = ((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                & (0U != (7U & (vlSelf->w_ir 
                                                >> 0xcU))));
    vlSelf->p__DOT__ALU_IM__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__ALU_B__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__regs__DOT__w_rs1 = vlSelf->p__DOT__w_rs1;
    vlSelf->p__DOT__w_rrs1 = ((0U == (IData)(vlSelf->p__DOT__w_rs1))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs1]);
    vlSelf->p__DOT__imm_gen0__DOT__imm_C = vlSelf->p__DOT__w_rs1;
    vlSelf->mmu__DOT__w_tlb_req = vlSelf->w_tlb_req;
    vlSelf->p__DOT__w_tlb_req = vlSelf->w_tlb_req;
    vlSelf->p__DOT__w_usestate = ((~ (IData)(vlSelf->p__DOT__r_ir16_v)) 
                                  & (IData)(vlSelf->p__DOT__w_nalign4));
    vlSelf->mmu__DOT__L0_success = (1U & (~ ((2U == (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                             | ((6U 
                                                 == (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                                | (((1U 
                                                     == (IData)(vlSelf->p__DOT__priv)) 
                                                    & ((~ 
                                                        (vlSelf->p__DOT__mstatus 
                                                         >> 0x12U)) 
                                                       & (IData)(
                                                                 (0x10U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L0_pte))))) 
                                                   | ((~ 
                                                       ((2U 
                                                         >= (IData)(vlSelf->p__DOT__r_tlb_req)) 
                                                        & ((IData)(vlSelf->mmu__DOT__L0_xwr) 
                                                           >> (IData)(vlSelf->p__DOT__r_tlb_req)))) 
                                                      | (IData)(
                                                                ((0U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L0_pte)) 
                                                                 & (0U 
                                                                    == (IData)(vlSelf->p__DOT__priv))))))))));
    vlSelf->p__DOT__w_sstatus_t = (0xde133U & vlSelf->p__DOT__w_mstatus_t);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_signed 
        = vlSelf->p__DOT__ALU_IM__DOT__w_div_signed;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed) 
            & (vlSelf->p__DOT__r_rrs1 >> 0x1fU)) ? 
           ((IData)(1U) + (~ vlSelf->p__DOT__r_rrs1))
            : vlSelf->p__DOT__r_rrs1);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed) 
            & (vlSelf->p__DOT__r_alu_in2 >> 0x1fU))
            ? ((IData)(1U) + (~ vlSelf->p__DOT__r_alu_in2))
            : vlSelf->p__DOT__r_alu_in2);
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt = (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed)
                                                                      ? 
                                                                     ((0U 
                                                                       == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                       ? (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))
                                                                       : 
                                                                      ((1U 
                                                                        == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                        ? (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))
                                                                        : 
                                                                       ((IData)(1U) 
                                                                        + 
                                                                        (~ (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))))))
                                                                      : (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed)
                                                                       ? 
                                                                      ((0U 
                                                                        == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                        ? (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)
                                                                        : 
                                                                       ((1U 
                                                                         == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                         ? 
                                                                        ((IData)(1U) 
                                                                         + 
                                                                         (~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))
                                                                         : 
                                                                        ((2U 
                                                                          == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                          ? 
                                                                         ((IData)(1U) 
                                                                          + 
                                                                          (~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))
                                                                          : (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt))))
                                                                       : (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy;
    vlSelf->p__DOT__w_exit_wfi = (((1U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                   & (0U != (0x222U 
                                             & vlSelf->p__DOT__pending_interrupts))) 
                                  | ((0U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                     & (0U != (0x111U 
                                               & vlSelf->p__DOT__pending_interrupts))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag;
    vlSelf->p__DOT__w_wb_r_enable = ((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                     | ((0x37U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                        | ((0x17U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                           | ((0x6fU 
                                               == (IData)(vlSelf->p__DOT__r_opcode)) 
                                              | ((0x67U 
                                                  == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                 | ((0x33U 
                                                     == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                    | ((0x13U 
                                                        == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                       | ((IData)(vlSelf->p__DOT__r_op_AMO) 
                                                          | (IData)(vlSelf->p__DOT__w_csr_we)))))))));
    vlSelf->p__DOT__w_wb_r_data = ((IData)(vlSelf->p__DOT__r_op_LOAD)
                                    ? vlSelf->w_data_data
                                    : ((IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)
                                        ? vlSelf->p__DOT__r_mem_rdata
                                        : ((IData)(vlSelf->p__DOT__w_csr_we)
                                            ? vlSelf->p__DOT__r_rcsr
                                            : vlSelf->p__DOT__r_wb_data)));
    vlSelf->p__DOT__w_data_t = ((0x300U == (IData)(vlSelf->p__DOT__r_funct12))
                                 ? vlSelf->p__DOT__r_wb_data_csr
                                 : vlSelf->p__DOT__w_sstatus);
    vlSelf->p__DOT__ALU_IM__DOT__w_le = vlSelf->p__DOT__w_ex1;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_init = ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                               & ((~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy)) 
                                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__r_div_first) 
                                                     & (IData)(vlSelf->p__DOT__w_ex1))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx;
    mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx];
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_rtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__L1_success = (1U & (~ ((2U == (IData)(vlSelf->mmu__DOT__L1_xwr)) 
                                             | ((6U 
                                                 == (IData)(vlSelf->mmu__DOT__L1_xwr)) 
                                                | (((1U 
                                                     == (IData)(vlSelf->p__DOT__priv)) 
                                                    & ((~ 
                                                        (vlSelf->p__DOT__mstatus 
                                                         >> 0x12U)) 
                                                       & (IData)(
                                                                 (0x10U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L1_pte))))) 
                                                   | ((~ 
                                                       ((2U 
                                                         >= (IData)(vlSelf->p__DOT__r_tlb_req)) 
                                                        & ((IData)(vlSelf->mmu__DOT__L1_xwr) 
                                                           >> (IData)(vlSelf->p__DOT__r_tlb_req)))) 
                                                      | (IData)(
                                                                ((0U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L1_pte)) 
                                                                 & (0U 
                                                                    == (IData)(vlSelf->p__DOT__priv))))))))));
    vlSelf->mmu__DOT__w_tlb_data_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_ridx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_r__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_w__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    vlSelf->mmu__DOT__w_tlb_data_w_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iswrite));
    vlSelf->mmu__DOT__L1_pte_write = (0x40U | (vlSelf->mmu__DOT__L1_pte 
                                               | ((IData)(vlSelf->mmu__DOT__w_iswrite)
                                                   ? 0x80U
                                                   : 0U)));
    vlSelf->mmu__DOT__L0_pte_write = (0x40U | (vlSelf->mmu__DOT__L0_pte 
                                               | ((IData)(vlSelf->mmu__DOT__w_iswrite)
                                                   ? 0x80U
                                                   : 0U)));
    vlSelf->mmu__DOT__L1_write = (1U & ((~ (vlSelf->mmu__DOT__L1_pte 
                                            >> 6U)) 
                                        | ((~ (vlSelf->mmu__DOT__L1_pte 
                                               >> 7U)) 
                                           & (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__L0_write = (1U & ((~ (vlSelf->mmu__DOT__L0_pte 
                                            >> 6U)) 
                                        | ((~ (vlSelf->mmu__DOT__L0_pte 
                                               >> 7U)) 
                                           & (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__w_insn_paddr = ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                       ? vlSelf->p__DOT__r_insn_addr
                                       : vlSelf->mmu__DOT__r_tlb_addr);
    vlSelf->mmu__DOT__w_tlb_inst_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->w_pagefault = ((IData)(vlSelf->mmu__DOT__page_walk_fail)
                            ? ((IData)(vlSelf->mmu__DOT__w_iscode)
                                ? 0xcU : ((IData)(vlSelf->mmu__DOT__w_isread)
                                           ? 0xdU : 0xfU))
                            : 0xffffffffU);
    mmu__DOT____VdfgTmp_hdc3ed8a3__0 = ((IData)(vlSelf->mmu__DOT__w_iscode) 
                                        | (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__v_addr = ((IData)(vlSelf->mmu__DOT__w_iscode)
                                 ? vlSelf->p__DOT__r_insn_addr
                                 : vlSelf->p__DOT__r_mem_addr);
    vlSelf->p__DOT__ALU_A__DOT__w_in2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__ALU_A__DOT__w_sin2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__w_alu_a_rslt = ((0x10U & (IData)(vlSelf->p__DOT__r_funct5))
                                     ? ((8U & (IData)(vlSelf->p__DOT__r_funct5))
                                         ? ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 ((vlSelf->p__DOT__r_rrs2 
                                                   > vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 ((vlSelf->p__DOT__r_rrs2 
                                                   < vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata))))
                                         : ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (VL_GTS_III(32, vlSelf->p__DOT__w_sin2, vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (VL_LTS_III(32, vlSelf->p__DOT__w_sin2, vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))))
                                     : ((8U & (IData)(vlSelf->p__DOT__r_funct5))
                                         ? ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  & vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  | vlSelf->p__DOT__w_mem_rdata))))
                                         : ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  ^ vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? vlSelf->p__DOT__r_rrs2
                                                  : 0U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? vlSelf->p__DOT__r_rrs2
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  + vlSelf->p__DOT__w_mem_rdata))))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_w__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->p__DOT__regs__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__RST_X = vlSelf->CORE_RST_X;
    vlSelf->mmu__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__decomp0__DOT__w_ic = vlSelf->p__DOT__w_ir_org;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm1 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 0xbU) 
                                               | ((0x400U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 2U)) 
                                                  | ((0x300U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         >> 1U)) 
                                                     | ((0x80U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 1U)) 
                                                        | ((0x40U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 1U)) 
                                                           | ((0x20U 
                                                               & (vlSelf->p__DOT__w_ir_org 
                                                                  << 3U)) 
                                                              | ((0x10U 
                                                                  & (vlSelf->p__DOT__w_ir_org 
                                                                     >> 7U)) 
                                                                 | (0xeU 
                                                                    & (vlSelf->p__DOT__w_ir_org 
                                                                       >> 2U)))))))));
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm3 = ((0x1c0U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 1U)) 
                                                | (0x38U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      >> 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm4 = ((0xc0U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 1U)) 
                                                | (0x3cU 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      >> 7U)));
    vlSelf->p__DOT__w_cinsn = (3U != (3U & vlSelf->p__DOT__w_ir_org));
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm4 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 9U) 
                                               | ((0x180U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 4U)) 
                                                  | ((0x40U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 1U)) 
                                                     | ((0x20U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 3U)) 
                                                        | (0x10U 
                                                           & (vlSelf->p__DOT__w_ir_org 
                                                              >> 2U))))));
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct2 = ((4U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     >> 0xaU)) 
                                                 | (3U 
                                                    & (vlSelf->p__DOT__w_ir_org 
                                                       >> 5U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_rd = (0x1fU 
                                             & (vlSelf->p__DOT__w_ir_org 
                                                >> 7U));
    p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0 = 
        ((2U & (vlSelf->p__DOT__w_ir_org >> 4U)) | 
         (1U & (vlSelf->p__DOT__w_ir_org >> 0xcU)));
    p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0 = 
        ((0x200U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | ((0x180U & (vlSelf->p__DOT__w_ir_org >> 2U)) 
            | ((0x40U & vlSelf->p__DOT__w_ir_org) | 
               ((0x20U & (vlSelf->p__DOT__w_ir_org 
                          >> 2U)) | ((0x10U & (vlSelf->p__DOT__w_ir_org 
                                               << 2U)) 
                                     | ((8U & (vlSelf->p__DOT__w_ir_org 
                                               >> 8U)) 
                                        | (7U & (vlSelf->p__DOT__w_ir_org 
                                                 >> 3U))))))));
    p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0 = 
        ((6U & (vlSelf->p__DOT__w_ir_org >> 6U)) | 
         (1U & (vlSelf->p__DOT__w_ir_org >> 0xcU)));
    p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0 = 
        ((0x40U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | ((0x38U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (4U & (vlSelf->p__DOT__w_ir_org >> 4U))));
    p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0 = 
        ((0xc0U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | (0x38U & (vlSelf->p__DOT__w_ir_org >> 7U)));
    p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0 = 
        ((0x3c0U & (vlSelf->p__DOT__w_ir_org >> 1U)) 
         | ((0x30U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | ((8U & (vlSelf->p__DOT__w_ir_org >> 2U)) 
               | (4U & (vlSelf->p__DOT__w_ir_org >> 4U)))));
    p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0 = 
        ((0x1c0U & (vlSelf->p__DOT__w_ir_org << 4U)) 
         | ((0x20U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (0x18U & (vlSelf->p__DOT__w_ir_org >> 2U))));
    p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0 = 
        ((0xc0U & (vlSelf->p__DOT__w_ir_org << 4U)) 
         | ((0x20U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (0x1cU & (vlSelf->p__DOT__w_ir_org >> 2U))));
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs2 = (8U | 
                                              (7U & 
                                               (vlSelf->p__DOT__w_ir_org 
                                                >> 2U)));
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs1 = (8U | 
                                              (7U & 
                                               (vlSelf->p__DOT__w_ir_org 
                                                >> 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c1_shamt = (0x1fU 
                                                & (vlSelf->p__DOT__w_ir_org 
                                                   >> 2U));
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct1 = (3U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 0xaU));
    vlSelf->p__DOT__regs__DOT__w_rdata2 = vlSelf->p__DOT__w_rrs2;
    vlSelf->p__DOT__regs__DOT__w_rdata1 = vlSelf->p__DOT__w_rrs1;
    vlSelf->p__DOT__w_imm = ((0x40U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                              ? ((0x20U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                  ? ((0x10U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                      ? ((8U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                          ? 0U : ((4U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? vlSelf->p__DOT__imm_gen0__DOT__imm_C
                                                     : 0U)
                                                    : 0U)))
                                      : ((8U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                          ? ((4U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                              ? ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_J
                                                   : 0U)
                                                  : 0U)
                                              : 0U)
                                          : ((4U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                              ? ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                   : 0U)
                                                  : 0U)
                                              : ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_B
                                                   : 0U)
                                                  : 0U))))
                                  : 0U) : ((0x20U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                            ? ((0x10U 
                                                & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_U
                                                       : 0U)
                                                      : 0U)
                                                     : 0U))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_S
                                                       : 0U)
                                                      : 0U))))
                                            : ((0x10U 
                                                & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_U
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                       : 0U)
                                                      : 0U)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                       : 0U)
                                                      : 0U))))));
    vlSelf->p__DOT__ALU_B__DOT__r_rslt = vlSelf->p__DOT__w_alu_b_rslt;
    vlSelf->p__DOT__r_rcsr_t = ((0x800U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                 ? ((0x400U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                     ? ((0x200U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                         ? ((0x100U 
                                             & (IData)(vlSelf->p__DOT__w_csr_addr))
                                             ? ((0x80U 
                                                 & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                 ? 0U
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : vlSelf->p__DOT__mhartid))
                                                      : 0U))
                                                    : 0U))))
                                             : 0U) : 
                                        ((0x100U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                          ? 0U : ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U)))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U))
                                                          : (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U)))))))))
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : (IData)(vlSelf->w_mtime))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? (IData)(vlSelf->w_mtime)
                                                          : (IData)(vlSelf->w_mtime)))))))))))
                                     : ((0x200U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                         ? ((0x100U 
                                             & (IData)(vlSelf->p__DOT__w_csr_addr))
                                             ? ((0x80U 
                                                 & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                 ? 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(
                                                                  (vlSelf->w_mtime 
                                                                   >> 0x20U)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(
                                                                  (vlSelf->w_mtime 
                                                                   >> 0x20U)))))))))
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(vlSelf->w_mtime))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(vlSelf->w_mtime)))))))))
                                             : 0U) : 0U))
                                 : ((0x400U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                     ? 0U : ((0x200U 
                                              & (IData)(vlSelf->p__DOT__w_csr_addr))
                                              ? ((0x100U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 
                                                 ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__mip))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mtval
                                                          : vlSelf->p__DOT__mcause)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mepc
                                                          : vlSelf->p__DOT__mscratch))))))
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__mcounteren)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mtvec
                                                          : vlSelf->p__DOT__mie))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mideleg
                                                          : vlSelf->p__DOT__medeleg)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 
                                                         (0x40000000U 
                                                          | vlSelf->p__DOT__misa)
                                                          : 
                                                         (((3U 
                                                            == 
                                                            (vlSelf->p__DOT__w_mstatus_t 
                                                             >> 0xdU)) 
                                                           | (3U 
                                                              == 
                                                              (vlSelf->p__DOT__w_mstatus_t 
                                                               >> 0xfU)))
                                                           ? 
                                                          (0x80006000U 
                                                           | vlSelf->p__DOT__mstatus)
                                                           : vlSelf->p__DOT__w_mstatus_t)))))))))
                                                  : 0U)
                                              : ((0x100U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 
                                                 ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__satp)))))))
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : 
                                                         (vlSelf->p__DOT__mip 
                                                          & vlSelf->p__DOT__mideleg)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__stval
                                                          : vlSelf->p__DOT__scause)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__sepc
                                                          : vlSelf->p__DOT__sscratch))))))
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__scounteren)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__stvec
                                                          : 
                                                         (vlSelf->p__DOT__mie 
                                                          & vlSelf->p__DOT__mideleg)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : 
                                                         (((3U 
                                                            == 
                                                            (vlSelf->p__DOT__w_sstatus_t 
                                                             >> 0xdU)) 
                                                           | (3U 
                                                              == 
                                                              (vlSelf->p__DOT__w_sstatus_t 
                                                               >> 0xfU)))
                                                           ? 
                                                          (0x80000000U 
                                                           | vlSelf->p__DOT__w_sstatus_t)
                                                           : vlSelf->p__DOT__w_sstatus_t)))))))))
                                                  : 0U))));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_dividend 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_divisor 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_rslt 
        = vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt = ((0U 
                                                == vlSelf->p__DOT__r_alu_in2)
                                                ? (0xffffffffULL 
                                                   | ((QData)((IData)(vlSelf->p__DOT__r_rrs1)) 
                                                      << 0x20U))
                                                : (
                                                   ((0xffffffffU 
                                                     == vlSelf->p__DOT__r_alu_in2) 
                                                    & (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed))
                                                    ? (QData)((IData)(vlSelf->p__DOT__r_rrs1))
                                                    : vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy;
    vlSelf->p__DOT__w_regfile_we = ((IData)(vlSelf->p__DOT__w_wb_r_enable) 
                                    & (9U == (IData)(vlSelf->w_state)));
    vlSelf->p__DOT__regs__DOT__w_wdata = vlSelf->p__DOT__w_wb_r_data;
    vlSelf->p__DOT__w_mod = (vlSelf->p__DOT__w_data_t 
                             ^ vlSelf->p__DOT__mstatus);
    p__DOT____VdfgTmp_h17b05525__0 = (vlSelf->p__DOT__w_mstatus_nxt 
                                      >> (IData)(vlSelf->p__DOT__r_priv_t));
    vlSelf->p__DOT__enable_interrupts = ((0U != vlSelf->p__DOT__pending_interrupts)
                                          ? ((3U == (IData)(vlSelf->p__DOT__r_priv_t))
                                              ? ((0U 
                                                  != 
                                                  (8U 
                                                   & vlSelf->p__DOT__w_mstatus_nxt))
                                                  ? 
                                                 (~ vlSelf->p__DOT__mideleg)
                                                  : 0U)
                                              : ((1U 
                                                  == (IData)(vlSelf->p__DOT__r_priv_t))
                                                  ? 
                                                 ((0U 
                                                   != 
                                                   (2U 
                                                    & vlSelf->p__DOT__w_mstatus_nxt))
                                                   ? 0xffffffffU
                                                   : 
                                                  (~ vlSelf->p__DOT__mideleg))
                                                  : 
                                                 ((0U 
                                                   == (IData)(vlSelf->p__DOT__r_priv_t))
                                                   ? 0xffffffffU
                                                   : 0U)))
                                          : 0U);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__w_div_init;
    vlSelf->p__DOT__w_ex1_busy = ((IData)(vlSelf->p__DOT__w_ex1) 
                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                     & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy) 
                                        | (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_init))));
    vlSelf->mmu__DOT__w_tlb_inst_r_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag);
    mmu__DOT____VdfgTmp_h8d9b33e2__0 = ((IData)(vlSelf->mmu__DOT__L1_success) 
                                        & (0U != (IData)(vlSelf->mmu__DOT__L1_xwr)));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_r_we;
    vlSelf->mmu__DOT__w_tlb_data_r_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag);
    vlSelf->mmu__DOT__w_tlb_data_w_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag);
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_w_we;
    if ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))) {
        vlSelf->mmu__DOT__w_mem_ctrl = vlSelf->mmu__DOT__w_mc_ctrl;
        vlSelf->w_mem_paddr = vlSelf->mmu__DOT__w_mc_addr;
    } else if (mmu__DOT____VdfgTmp_h5ee52748__0) {
        vlSelf->mmu__DOT__w_mem_ctrl = vlSelf->p__DOT__r_data_ctrl;
        vlSelf->w_mem_paddr = vlSelf->p__DOT__r_mem_addr;
    } else {
        vlSelf->mmu__DOT__w_mem_ctrl = ((0U == (3U 
                                                & (IData)(vlSelf->mmu__DOT__r_tlb_use)))
                                         ? ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                             ? 2U : 
                                            ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                              ? 2U : 
                                             ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                               ? 2U
                                               : (IData)(vlSelf->p__DOT__r_data_ctrl))))
                                         : (IData)(vlSelf->p__DOT__r_data_ctrl));
        vlSelf->w_mem_paddr = vlSelf->mmu__DOT__r_tlb_addr;
    }
    vlSelf->mmu__DOT__w_mem_paddr = vlSelf->w_mem_paddr;
    vlSelf->mmu__DOT__w_virt = (0xfU & (vlSelf->w_mem_paddr 
                                        >> 0x18U));
    vlSelf->mmu__DOT__w_offset = (0x7ffffffU & vlSelf->w_mem_paddr);
    vlSelf->mmu__DOT__w_dev = (vlSelf->w_mem_paddr 
                               >> 0x1cU);
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_inst_r_we;
    vlSelf->mmu__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->p__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->p__DOT__w_com = (((0xffffffffU != vlSelf->p__DOT__pending_exception) 
                              | ((0xffffffffU != vlSelf->w_pagefault) 
                                 | ((IData)(vlSelf->p__DOT__w_ex1) 
                                    & (IData)(vlSelf->p__DOT__r_op_ECALL)))) 
                             & ((0xaU != (IData)(vlSelf->w_state)) 
                                & ((0xbU != (IData)(vlSelf->w_state)) 
                                   & (0U != (IData)(vlSelf->w_state)))));
    vlSelf->mmu__DOT__w_use_tlb = ((0U == (IData)(vlSelf->mmu__DOT__r_mc_mode)) 
                                   & ((~ (IData)(mmu__DOT____VdfgTmp_h5ee52748__0)) 
                                      & ((IData)(mmu__DOT____VdfgTmp_hdc3ed8a3__0) 
                                         | (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__vpn1 = (vlSelf->mmu__DOT__v_addr 
                              >> 0x16U);
    vlSelf->mmu__DOT__vpn0 = (0x3ffU & (vlSelf->mmu__DOT__v_addr 
                                        >> 0xcU));
    vlSelf->mmu__DOT__L1_p_addr = ((0xffc00000U & (vlSelf->mmu__DOT__L1_pte 
                                                   << 2U)) 
                                   | (0x3fffffU & vlSelf->mmu__DOT__v_addr));
    vlSelf->mmu__DOT__L0_p_addr = ((0xfffff000U & (vlSelf->mmu__DOT__L0_pte 
                                                   << 2U)) 
                                   | (0xfffU & vlSelf->mmu__DOT__v_addr));
    vlSelf->mmu__DOT__L1_pte_addr = ((vlSelf->p__DOT__satp 
                                      << 0xcU) + (0xffcU 
                                                  & (vlSelf->mmu__DOT__v_addr 
                                                     >> 0x14U)));
    vlSelf->mmu__DOT__L0_pte_addr = (vlSelf->mmu__DOT__L1_paddr 
                                     + (0xffcU & (vlSelf->mmu__DOT__v_addr 
                                                  >> 0xaU)));
    vlSelf->p__DOT__ALU_A__DOT__r_rslt = vlSelf->p__DOT__w_alu_a_rslt;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__RST_X = vlSelf->p__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm1 = p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm2 = p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_nzuimm = p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm1 = p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm2 = p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_rd = vlSelf->p__DOT__decomp0__DOT__w_c0_rs2;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs2 = vlSelf->p__DOT__decomp0__DOT__w_c0_rs2;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs1 = vlSelf->p__DOT__decomp0__DOT__w_c0_rs1;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rd = vlSelf->p__DOT__decomp0__DOT__w_c0_rs1;
    p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0 = 
        (0x5013U | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                     << 0xfU) | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                 << 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_rs2 = vlSelf->p__DOT__decomp0__DOT__w_c1_shamt;
    vlSelf->p__DOT__decomp0__DOT__w_c2_shamt = vlSelf->p__DOT__decomp0__DOT__w_c1_shamt;
    vlSelf->p__DOT__decomp0__DOT__w_c2_nzuimm = ((0x20U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     >> 7U)) 
                                                 | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0 = 
        ((0xfe0U & ((- (IData)((1U & (vlSelf->p__DOT__w_ir_org 
                                      >> 0xcU)))) << 5U)) 
         | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm = (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->p__DOT__w_ir_org 
                                                                >> 0xcU)))) 
                                                 << 5U) 
                                                | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 8U) 
                                               | ((0xc0U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 1U)) 
                                                  | ((0x20U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 3U)) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                                                         << 3U) 
                                                        | (6U 
                                                           & (vlSelf->p__DOT__w_ir_org 
                                                              >> 2U))))));
    p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0 = 
        (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
          << 3U) | (4U & (vlSelf->p__DOT__w_ir_org 
                          >> 4U)));
    p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0 = 
        (0x63U | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                   << 0xaU) | ((0x300U & (vlSelf->p__DOT__w_ir_org 
                                          << 5U)) | 
                               (0x80U & (vlSelf->p__DOT__w_ir_org 
                                         >> 5U)))));
    vlSelf->p__DOT__imm_gen0__DOT__r_imm = vlSelf->p__DOT__w_imm;
    vlSelf->p__DOT__w_alu_im_rslt = ((1U & (IData)(vlSelf->p__DOT__r_alu_f7))
                                      ? ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                          ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0U 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? vlSelf->p__DOT__r_rrs1
                                                   : (IData)(
                                                             (vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                                              >> 0x20U)))
                                                  : 
                                                 ((0xffffffffU 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? 0U
                                                   : 
                                                  ((0U 
                                                    == vlSelf->p__DOT__r_alu_in2)
                                                    ? vlSelf->p__DOT__r_rrs1
                                                    : (IData)(
                                                              (vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                                               >> 0x20U)))))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0U 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? 0xffffffffU
                                                   : (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt))
                                                  : 
                                                 ((0xffffffffU 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? vlSelf->p__DOT__r_rrs1
                                                   : 
                                                  ((0U 
                                                    == vlSelf->p__DOT__r_alu_in2)
                                                    ? 0xffffffffU
                                                    : (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt)))))
                                          : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? (IData)(
                                                            (vlSelf->p__DOT__r_mul_UU 
                                                             >> 0x20U))
                                                  : (IData)(
                                                            (vlSelf->p__DOT__r_mul_SU 
                                                             >> 0x20U)))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? (IData)(
                                                            (vlSelf->p__DOT__r_mul_SS 
                                                             >> 0x20U))
                                                  : (IData)(vlSelf->p__DOT__r_mul_SS))))
                                      : ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                          ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  & vlSelf->p__DOT__r_alu_in2)
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  | vlSelf->p__DOT__r_alu_in2))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__r_alu_f7))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->p__DOT__w_sin1, (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt))
                                                   : 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   >> (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt)))
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  ^ vlSelf->p__DOT__r_alu_in2)))
                                          : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  < vlSelf->p__DOT__r_alu_in2)
                                                  : (IData)(p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  << (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt))
                                                  : 
                                                 ((0U 
                                                   != (IData)(vlSelf->p__DOT__r_alu_f7))
                                                   ? 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   - vlSelf->p__DOT__r_alu_in2)
                                                   : 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   + vlSelf->p__DOT__r_alu_in2))))));
    vlSelf->p__DOT__regs__DOT__w_we = vlSelf->p__DOT__w_regfile_we;
    vlSelf->p__DOT__w_sstatus_t1 = ((0xffffffdfU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x20U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 5U)));
    vlSelf->p__DOT__w_mstatus_t1 = ((0xffffff7fU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x80U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 7U)));
    vlSelf->p__DOT__w_interrupt_mask = (vlSelf->p__DOT__pending_interrupts 
                                        & vlSelf->p__DOT__enable_interrupts);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init;
    vlSelf->p__DOT__ALU_IM__DOT__w_busy = vlSelf->p__DOT__w_ex1_busy;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_inst_r_addr;
    vlSelf->mmu__DOT__w_tlb_inst_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx)));
    if (mmu__DOT____VdfgTmp_h8d9b33e2__0) {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L1_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L1_pte_addr;
    } else {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L0_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L0_pte_addr;
    }
    vlSelf->mmu__DOT__w_pte_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                  & (((IData)(mmu__DOT____VdfgTmp_h8d9b33e2__0) 
                                      & (IData)(vlSelf->mmu__DOT__L1_write)) 
                                     | ((IData)(vlSelf->mmu__DOT__L0_success) 
                                        & ((0U != (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                           & (IData)(vlSelf->mmu__DOT__L0_write)))));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_r_addr;
    vlSelf->mmu__DOT__w_tlb_data_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_w_addr;
    vlSelf->mmu__DOT__w_tlb_data_w_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->w_clint_we = (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                           & (IData)(vlSelf->p__DOT__r_data_we)) 
                          & ((((0x4000U == vlSelf->mmu__DOT__w_offset) 
                               | (0x4004U == vlSelf->mmu__DOT__w_offset)) 
                              & (0U == vlSelf->w_hart_id)) 
                             | (((0x4008U == vlSelf->mmu__DOT__w_offset) 
                                 | (0x400cU == vlSelf->mmu__DOT__w_offset)) 
                                & (1U == vlSelf->w_hart_id))));
    vlSelf->w_wmtimecmp = (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                            & ((0x4000U == vlSelf->mmu__DOT__w_offset) 
                               & (IData)(mmu__DOT____VdfgTmp_hdf96e1fa__0)))
                            ? mmu__DOT____VdfgTmp_h0821c8f5__0
                            : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                & ((0x4004U == vlSelf->mmu__DOT__w_offset) 
                                   & (IData)(mmu__DOT____VdfgTmp_hdf96e1fa__0)))
                                ? mmu__DOT____VdfgTmp_hd62e4571__0
                                : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                    & ((0x4008U == vlSelf->mmu__DOT__w_offset) 
                                       & (IData)(mmu__DOT____VdfgTmp_h2aff9416__0)))
                                    ? mmu__DOT____VdfgTmp_h0821c8f5__0
                                    : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                        & ((0x400cU 
                                            == vlSelf->mmu__DOT__w_offset) 
                                           & (IData)(mmu__DOT____VdfgTmp_h2aff9416__0)))
                                        ? mmu__DOT____VdfgTmp_hd62e4571__0
                                        : 0ULL))));
    vlSelf->w_proc_busy = (((IData)(vlSelf->mmu__DOT__w_use_tlb) 
                            & (7U > (IData)(vlSelf->mmu__DOT__r_pw_state))) 
                           | ((IData)(vlSelf->w_dram_busy) 
                              | (0U != (IData)(vlSelf->w_data_busy))));
    vlSelf->w_tlb_busy = ((6U != (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                          & (IData)(vlSelf->mmu__DOT__w_use_tlb));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm3 = vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm;
    if ((2U & vlSelf->p__DOT__w_ir_org)) {
        vlSelf->p__DOT__w_ir_t = ((1U & vlSelf->p__DOT__w_ir_org)
                                   ? vlSelf->p__DOT__w_ir_org
                                   : ((0x8000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x4000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x12027U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0) 
                                                      << 0x19U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                         << 0x14U) 
                                                        | (0xe00U 
                                                           & vlSelf->p__DOT__w_ir_org))))
                                               : (0x12023U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0) 
                                                      << 0x19U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                         << 0x14U) 
                                                        | (0xe00U 
                                                           & vlSelf->p__DOT__w_ir_org)))))
                                           : ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x13027U 
                                                  | ((0x1c000000U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 0x13U)) 
                                                     | ((0x2000000U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 0xdU)) 
                                                        | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                            << 0x14U) 
                                                           | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                                                              << 0xaU)))))
                                               : ((0U 
                                                   == (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd))
                                                    ? 0x100073U
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->p__DOT__w_ir_org)
                                                     ? 
                                                    (0xe7U 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 0xfU))
                                                     : 
                                                    (0x67U 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 0xfU))))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->p__DOT__w_ir_org)
                                                    ? 
                                                   (0x33U 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                        << 0x14U) 
                                                       | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                           << 0xfU) 
                                                          | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                             << 7U))))
                                                    : 
                                                   (0x33U 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                        << 0x14U) 
                                                       | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                          << 7U)))))))
                                       : ((0x4000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x12007U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U)))
                                               : (0x12003U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U))))
                                           : ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x13007U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U)))
                                               : (0x1013U 
                                                  | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                         << 0xfU) 
                                                        | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                           << 7U))))))));
    } else if ((1U & vlSelf->p__DOT__w_ir_org)) {
        vlSelf->p__DOT__w_ir_t = ((0x8000U & vlSelf->p__DOT__w_ir_org)
                                   ? ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0x1000U 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | ((0x7e000000U 
                                                     & (vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 
                                                        << 0x14U)) 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                        << 0xfU) 
                                                       | (IData)(p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0)))))
                                           : ((0x80000000U 
                                               & (vlSelf->p__DOT__w_ir_org 
                                                  << 0x13U)) 
                                              | ((0x7e000000U 
                                                  & (vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 
                                                     << 0x14U)) 
                                                 | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                     << 0xfU) 
                                                    | (IData)(p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0)))))
                                       : ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0x6fU 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->p__DOT__w_ir_org 
                                                           << 8U)) 
                                                       | (0xff000U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->p__DOT__w_ir_org 
                                                                            >> 0xcU)))) 
                                                             << 0xbU))))))
                                           : ((2U & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                               ? ((1U 
                                                   & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                      ? 
                                                     (0x807033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U))))
                                                      : 
                                                     (0x806033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U)))))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                      ? 
                                                     (0x804033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U))))
                                                      : 
                                                     (0x40000033U 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                          << 0x14U) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U)))))))
                                                   : 
                                                  (0x7013U 
                                                   | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0) 
                                                       << 0x14U) 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                          << 0xfU) 
                                                         | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                            << 7U)))))
                                               : ((1U 
                                                   & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                                   ? 
                                                  (0x40000000U 
                                                   | ((0x3e000000U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlSelf->p__DOT__w_ir_org 
                                                                         >> 0xcU)))) 
                                                          << 0x19U)) 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                          << 0x14U) 
                                                         | p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0)))
                                                   : 
                                                  (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0) 
                                                    << 0x14U) 
                                                   | p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0)))))
                                   : ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((2U == 
                                               (0x1fU 
                                                & (vlSelf->p__DOT__w_ir_org 
                                                   >> 7U)))
                                               ? (0x10113U 
                                                  | (vlSelf->p__DOT__decomp0__DOT__w_c1_imm4 
                                                     << 0x14U))
                                               : (0x37U 
                                                  | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                      << 0xcU) 
                                                     | (0xf80U 
                                                        & vlSelf->p__DOT__w_ir_org))))
                                           : (0x13U 
                                              | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                  << 0x14U) 
                                                 | (0xf80U 
                                                    & vlSelf->p__DOT__w_ir_org))))
                                       : ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0xefU 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->p__DOT__w_ir_org 
                                                           << 8U)) 
                                                       | (0xff000U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->p__DOT__w_ir_org 
                                                                            >> 0xcU)))) 
                                                             << 0xbU))))))
                                           : (0x13U 
                                              | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                  << 0x14U) 
                                                 | ((0xf8000U 
                                                     & (vlSelf->p__DOT__w_ir_org 
                                                        << 8U)) 
                                                    | (0xf80U 
                                                       & vlSelf->p__DOT__w_ir_org)))))));
    } else if ((0x8000U & vlSelf->p__DOT__w_ir_org)) {
        if ((0x4000U & vlSelf->p__DOT__w_ir_org)) {
            vlSelf->p__DOT__w_ir_t = ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x2027U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                            << 0x19U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                               << 0x14U) 
                                              | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                  << 0xfU) 
                                                 | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                    << 7U)))))
                                       : (0x2023U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                            << 0x19U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                               << 0x14U) 
                                              | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                  << 0xfU) 
                                                 | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                    << 7U))))));
        } else if ((0x2000U & vlSelf->p__DOT__w_ir_org)) {
            vlSelf->p__DOT__w_ir_t = (0x3027U | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                                  << 0x19U) 
                                                 | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                        << 0xfU) 
                                                       | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                          << 7U)))));
        }
    } else {
        vlSelf->p__DOT__w_ir_t = ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                   ? ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x2007U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U))))
                                       : (0x2003U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U)))))
                                   : ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x3007U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U))))
                                       : (0x10013U 
                                          | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0) 
                                              << 0x14U) 
                                             | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                << 7U)))));
    }
    vlSelf->p__DOT__ALU_IM__DOT__r_rslt = vlSelf->p__DOT__w_alu_im_rslt;
    vlSelf->p__DOT__w_sstatus_t2 = ((0xfffffeffU & vlSelf->p__DOT__w_sstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 8U));
    vlSelf->p__DOT__w_mstatus_t2 = ((0xffffe7ffU & vlSelf->p__DOT__w_mstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 0xbU));
    vlSelf->p__DOT__w_irq_t = (vlSelf->p__DOT__w_interrupt_mask 
                               & ((IData)(1U) + (~ vlSelf->p__DOT__w_interrupt_mask)));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_inst_r_oe;
    vlSelf->w_dram_wdata = ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                             ? vlSelf->mmu__DOT__w_pte_wdata
                             : vlSelf->mmu__DOT__w_mem_wdata);
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_r_oe;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_w_oe;
    vlSelf->mmu__DOT__w_tlb_hit = (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                    & (IData)(vlSelf->mmu__DOT__w_tlb_inst_r_oe)) 
                                   | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                       & (IData)(vlSelf->mmu__DOT__w_tlb_data_r_oe)) 
                                      | ((IData)(vlSelf->mmu__DOT__w_iswrite) 
                                         & (IData)(vlSelf->mmu__DOT__w_tlb_data_w_oe))));
    vlSelf->mmu__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->p__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->mmu__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->p__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->mmu__DOT__w_proc_busy = vlSelf->w_proc_busy;
    vlSelf->p__DOT__w_busy = vlSelf->w_proc_busy;
    vlSelf->p__DOT__w_if_state = ((1U & ((~ ((1U == (IData)(vlSelf->w_state)) 
                                             | (2U 
                                                == (IData)(vlSelf->w_state)))) 
                                         | (0xffffffffU 
                                            != vlSelf->w_pagefault)))
                                   ? 0U : (3U & (((0U 
                                                   == (IData)(vlSelf->p__DOT__r_if_state)) 
                                                  & ((~ (IData)(vlSelf->w_proc_busy)) 
                                                     & (IData)(vlSelf->p__DOT__w_nalign4)))
                                                  ? 
                                                 ((IData)(vlSelf->p__DOT__r_ir16_v)
                                                   ? 3U
                                                   : 1U)
                                                  : 
                                                 (((~ (IData)(vlSelf->w_proc_busy)) 
                                                   & (1U 
                                                      == (IData)(vlSelf->p__DOT__r_if_state)))
                                                   ? 2U
                                                   : 
                                                  (((~ (IData)(vlSelf->w_proc_busy)) 
                                                    & (2U 
                                                       == (IData)(vlSelf->p__DOT__r_if_state)))
                                                    ? 3U
                                                    : (IData)(vlSelf->p__DOT__r_if_state))))));
    vlSelf->p__DOT__w_state = ((1U & ((~ (IData)(vlSelf->CORE_RST_X)) 
                                      | (IData)(vlSelf->w_halt)))
                                ? 0U : ((IData)(vlSelf->p__DOT__w_com)
                                         ? 0xaU : (0xfU 
                                                   & ((((~ (IData)(vlSelf->p__DOT__w_ex1)) 
                                                        & (IData)(vlSelf->w_proc_busy)) 
                                                       | (IData)(vlSelf->p__DOT__w_ex1_busy))
                                                       ? (IData)(vlSelf->w_state)
                                                       : 
                                                      ((0xbU 
                                                        == (IData)(vlSelf->w_state))
                                                        ? 0U
                                                        : 
                                                       (((1U 
                                                          == (IData)(vlSelf->w_state)) 
                                                         & ((IData)(vlSelf->p__DOT__w_nalign4) 
                                                            & (3U 
                                                               != (IData)(vlSelf->p__DOT__r_if_state))))
                                                         ? 1U
                                                         : 
                                                        (((~ (IData)(vlSelf->p__DOT__r_op_AMO)) 
                                                          & ((~ (IData)(vlSelf->p__DOT__r_op_LOAD)) 
                                                             & ((~ (IData)(vlSelf->p__DOT__r_op_STORE)) 
                                                                & (IData)(vlSelf->p__DOT__w_ex1))))
                                                          ? 9U
                                                          : 
                                                         (((6U 
                                                            == (IData)(vlSelf->w_state)) 
                                                           & (IData)(vlSelf->p__DOT__r_op_STORE))
                                                           ? 8U
                                                           : 
                                                          (((6U 
                                                             == (IData)(vlSelf->w_state)) 
                                                            & (IData)(vlSelf->p__DOT__r_op_LOAD))
                                                            ? 9U
                                                            : 
                                                           ((IData)(1U) 
                                                            + (IData)(vlSelf->w_state)))))))))));
    if (((0xaU == (IData)(vlSelf->w_state)) & (~ (IData)(vlSelf->w_proc_busy)))) {
        if (((0xffffffffU != vlSelf->p__DOT__pending_exception) 
             | ((0U != vlSelf->p__DOT__w_interrupt_mask) 
                & (IData)(vlSelf->p__DOT__w_take_int)))) {
            vlSelf->p__DOT__r_tlb_flush = 1U;
        } else if (((IData)(vlSelf->p__DOT__r_op_SRET) 
                    | (IData)(vlSelf->p__DOT__r_op_MRET))) {
            vlSelf->p__DOT__r_tlb_flush = 1U;
        } else if (vlSelf->p__DOT__r_op_CSR_MSTA) {
            if (((0U != (0xe0000U & vlSelf->p__DOT__w_mod)) 
                 | ((0U != (0x20000U & vlSelf->p__DOT__mstatus)) 
                    & (0U != (0x1800U & vlSelf->p__DOT__w_mod))))) {
                vlSelf->p__DOT__r_tlb_flush = 1U;
            }
        } else if (vlSelf->p__DOT__r_op_CSR_SSTA) {
            if (((0U != (0xe0000U & vlSelf->p__DOT__w_mod)) 
                 | ((0U != (0x20000U & vlSelf->p__DOT__mstatus)) 
                    & (0U != (0x1800U & vlSelf->p__DOT__w_mod))))) {
                vlSelf->p__DOT__r_tlb_flush = 1U;
            }
        } else {
            vlSelf->p__DOT__r_tlb_flush = (((0x73U 
                                             == (IData)(vlSelf->p__DOT__r_opcode)) 
                                            & (0U == (IData)(vlSelf->p__DOT__r_funct3))) 
                                           & (9U == (IData)(vlSelf->p__DOT__r_funct7)));
        }
    } else {
        vlSelf->p__DOT__r_tlb_flush = 0U;
    }
    vlSelf->mmu__DOT__w_tlb_busy = vlSelf->w_tlb_busy;
    vlSelf->mmu__DOT__w_dram_we = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                   & ((IData)(vlSelf->p__DOT__r_data_we) 
                                      & ((8U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                         | (0U == (IData)(vlSelf->mmu__DOT__w_dev)))));
    mmu__DOT____VdfgTmp_h1f4b0050__0 = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                        & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->mmu__DOT__r_tlb_pte_addr = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                         ? vlSelf->mmu__DOT__L1_pte_addr
                                         : ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                             ? vlSelf->mmu__DOT__L0_pte_addr
                                             : ((5U 
                                                 == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                                 ? vlSelf->mmu__DOT__w_pte_waddr
                                                 : 0U)));
    if ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))) {
        vlSelf->w_dram_ctrl = vlSelf->mmu__DOT__w_mem_ctrl;
        vlSelf->w_dram_addr = vlSelf->mmu__DOT__w_mc_addr;
    } else if (mmu__DOT____VdfgTmp_h1f4b0050__0) {
        vlSelf->w_dram_ctrl = 2U;
        vlSelf->w_dram_addr = vlSelf->mmu__DOT__w_insn_paddr;
    } else {
        vlSelf->w_dram_ctrl = vlSelf->mmu__DOT__w_mem_ctrl;
        vlSelf->w_dram_addr = ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                ? vlSelf->p__DOT__r_mem_addr
                                : (((~ (IData)(vlSelf->mmu__DOT__w_tlb_hit)) 
                                    & (IData)(vlSelf->mmu__DOT__r_tlb_acs))
                                    ? vlSelf->mmu__DOT__r_tlb_pte_addr
                                    : vlSelf->w_mem_paddr));
    }
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__r_iw = vlSelf->p__DOT__w_ir_t;
    vlSelf->p__DOT__w_nop = ((0x53U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                             | ((7U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                                | (0x27U == (0x7fU 
                                             & vlSelf->p__DOT__w_ir_t))));
    vlSelf->p__DOT__w_sstatus_t3 = (0xfffffffdU & vlSelf->p__DOT__w_sstatus_t2);
    vlSelf->p__DOT__w_mstatus_t3 = (0xfffffff7U & vlSelf->p__DOT__w_mstatus_t2);
    vlSelf->mmu__DOT__w_dram_wdata = vlSelf->w_dram_wdata;
    vlSelf->p__DOT__w_d_en_t = ((6U == (IData)(vlSelf->p__DOT__w_state)) 
                                & ((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                   | (IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)));
    vlSelf->p__DOT__w_d_we_t = ((8U == (IData)(vlSelf->p__DOT__w_state)) 
                                & ((IData)(vlSelf->p__DOT__r_op_STORE) 
                                   | (((IData)(vlSelf->p__DOT__r_op_AMO) 
                                       & ((~ vlSelf->p__DOT__r_wb_data) 
                                          & (IData)(vlSelf->p__DOT__r_op_AMO_SC))) 
                                      | ((~ (IData)(vlSelf->p__DOT__r_op_AMO_LR)) 
                                         & (IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)))));
    vlSelf->w_tlb_flush = vlSelf->p__DOT__r_tlb_flush;
    vlSelf->w_dram_we_t = ((IData)(vlSelf->mmu__DOT__w_pte_we) 
                           | (IData)(vlSelf->mmu__DOT__w_dram_we));
    vlSelf->p__DOT__w_ir = ((IData)(vlSelf->p__DOT__w_nop)
                             ? 0x13U : ((IData)(vlSelf->p__DOT__w_cinsn)
                                         ? vlSelf->p__DOT__w_ir_t
                                         : vlSelf->p__DOT__w_ir_org));
    vlSelf->p__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_dram_we_t = vlSelf->w_dram_we_t;
    vlSelf->mmu__DOT__w_dram_ctrl = vlSelf->w_dram_ctrl;
    vlSelf->mmu__DOT__w_dram_addr = vlSelf->w_dram_addr;
    vlSelf->mmu__DOT__w_dram_aces = ((8U == (vlSelf->w_dram_addr 
                                             >> 0x1cU)) 
                                     | ((0U == (vlSelf->w_dram_addr 
                                                >> 0x1cU)) 
                                        | (9U == (vlSelf->w_dram_addr 
                                                  >> 0x1cU))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->w_data_le = ((~ (IData)(vlSelf->w_tlb_busy)) 
                         & ((~ (IData)(vlSelf->mmu__DOT__w_dram_aces)) 
                            & (IData)(vlSelf->mmu__DOT__w_isread)));
    vlSelf->w_data_we = ((~ (IData)(vlSelf->w_tlb_busy)) 
                         & ((~ (IData)(vlSelf->mmu__DOT__w_dram_aces)) 
                            & ((IData)(vlSelf->mmu__DOT__w_iswrite) 
                               | (IData)(vlSelf->p__DOT__r_data_we))));
    vlSelf->w_dram_le = ((IData)(vlSelf->mmu__DOT__w_dram_aces) 
                         & ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))
                             ? ((0U == (IData)(vlSelf->mmu__DOT__w_mc_aces)) 
                                & (0U != (vlSelf->mmu__DOT__w_mc_addr 
                                          >> 0x1cU)))
                             : ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                 ? (IData)(mmu__DOT____VdfgTmp_hdc3ed8a3__0)
                                 : (((~ (IData)(vlSelf->w_tlb_busy)) 
                                     & (0U != (3U & 
                                               ((IData)(vlSelf->mmu__DOT__r_tlb_use) 
                                                >> 1U))))
                                     ? 1U : (((~ (IData)(vlSelf->mmu__DOT__w_tlb_hit)) 
                                              & ((IData)(vlSelf->w_tlb_busy) 
                                                 & ((0U 
                                                     == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                                    | (2U 
                                                       == (IData)(vlSelf->mmu__DOT__r_pw_state)))))
                                              ? 1U : 0U)))));
    vlSelf->mmu__DOT__w_data_le = vlSelf->w_data_le;
    vlSelf->mmu__DOT__w_data_we = vlSelf->w_data_we;
    vlSelf->mmu__DOT__w_dram_le = vlSelf->w_dram_le;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__1(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__1\n"); );
    // Body
    vlSelf->p__DOT__w_oh_sc = vlSelf->w_oh_sc;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core1__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core1__0\n"); );
    // Init
    CData/*0:0*/ mmu__DOT____VdfgTmp_hdf96e1fa__0;
    QData/*63:0*/ mmu__DOT____VdfgTmp_h0821c8f5__0;
    QData/*63:0*/ mmu__DOT____VdfgTmp_hd62e4571__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h2aff9416__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h5ee52748__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h1f4b0050__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_hdc3ed8a3__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h1a37559d__0;
    CData/*0:0*/ mmu__DOT____VdfgTmp_h8d9b33e2__0;
    QData/*39:0*/ mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0;
    QData/*39:0*/ mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0;
    QData/*39:0*/ mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0;
    QData/*63:0*/ p__DOT____VdfgTmp_hc363607f__0;
    IData/*31:0*/ p__DOT____VdfgTmp_h17b05525__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0;
    CData/*7:0*/ p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0;
    SData/*9:0*/ p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0;
    SData/*8:0*/ p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0;
    CData/*7:0*/ p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0;
    CData/*4:0*/ p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0;
    SData/*9:0*/ p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0;
    SData/*11:0*/ p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0;
    SData/*11:0*/ p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0;
    IData/*19:0*/ p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0;
    CData/*6:0*/ p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0;
    CData/*1:0*/ p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0;
    CData/*0:0*/ p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0;
    // Body
    vlSelf->mmu__DOT__w_hart_id = vlSelf->w_hart_id;
    vlSelf->mmu__DOT__w_pc = vlSelf->w_pc;
    vlSelf->mmu__DOT__w_ir = vlSelf->w_ir;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_mem_addr 
                                                     >> 0xcU));
    vlSelf->p__DOT__r_halt = vlSelf->w_halt;
    vlSelf->p__DOT__state = vlSelf->w_state;
    vlSelf->p__DOT__pc = vlSelf->w_pc;
    vlSelf->p__DOT__pc_stip = vlSelf->w_pc_stip;
    vlSelf->p__DOT__reserved = vlSelf->w_reserved;
    vlSelf->p__DOT__load_res = vlSelf->w_load_res;
    vlSelf->p__DOT__r_ipi_taken = vlSelf->w_ipi_taken;
    vlSelf->p__DOT__regs__DOT__rd = vlSelf->p__DOT__r_rd;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct7 = vlSelf->p__DOT__r_alu_f7;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SS = vlSelf->p__DOT__r_mul_SS;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SU = vlSelf->p__DOT__r_mul_SU;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_UU = vlSelf->p__DOT__r_mul_UU;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_rslt 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt;
    vlSelf->p__DOT__ALU_B__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_B__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_B__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_C__DOT__w_rcsr = vlSelf->p__DOT__r_rcsr;
    vlSelf->p__DOT__ALU_C__DOT__w_rrs1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_C__DOT__w_imm = vlSelf->p__DOT__r_imm;
    vlSelf->p__DOT__ALU_C__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_A__DOT__w_in1 = vlSelf->p__DOT__r_rrs2;
    vlSelf->p__DOT__ALU_A__DOT__w_funct5 = vlSelf->p__DOT__r_funct5;
    vlSelf->mmu__DOT__L0_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L0_pte 
                                                 << 2U));
    vlSelf->p__DOT__w_vadr2 = ((IData)(2U) + vlSelf->w_pc);
    vlSelf->p__DOT__w_vadr1 = (0xfffffffcU & vlSelf->w_pc);
    vlSelf->p__DOT__w_core_pc = vlSelf->w_pc;
    vlSelf->p__DOT__w_init_stage = vlSelf->p__DOT__r_init_stage;
    vlSelf->p__DOT__w_mul_UU = ((QData)((IData)(vlSelf->p__DOT__r_rrs1)) 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ 
        = (0x1ffffffffULL & ((vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                              >> 0x1fU) - (QData)((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor))));
    vlSelf->p__DOT__w_executing_wfi = ((0x73U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                       & ((0U == (IData)(vlSelf->p__DOT__r_funct3)) 
                                          & (0x105U 
                                             == (IData)(vlSelf->p__DOT__r_funct12))));
    vlSelf->p__DOT__w_hart_id = vlSelf->w_hart_id;
    vlSelf->p__DOT__r_ir = vlSelf->w_ir;
    vlSelf->p__DOT__ALU_IM__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_IM__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_IM__DOT__w_sin2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__w_mem_addr = (((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                   | (IData)(vlSelf->p__DOT__r_op_STORE))
                                   ? (vlSelf->p__DOT__r_imm 
                                      + vlSelf->p__DOT__r_rrs1)
                                   : ((IData)(vlSelf->p__DOT__r_op_AMO)
                                       ? vlSelf->p__DOT__r_rrs1
                                       : 0U));
    vlSelf->w_insn_addr = vlSelf->p__DOT__r_insn_addr;
    vlSelf->w_data_addr = vlSelf->p__DOT__r_mem_addr;
    vlSelf->w_proc_data_we = vlSelf->p__DOT__r_data_we;
    vlSelf->w_data_ctrl = vlSelf->p__DOT__r_data_ctrl;
    vlSelf->w_priv = vlSelf->p__DOT__priv;
    vlSelf->w_satp = vlSelf->p__DOT__satp;
    vlSelf->w_mstatus = vlSelf->p__DOT__mstatus;
    vlSelf->w_mtimecmp = vlSelf->p__DOT__mtimecmp;
    p__DOT____VdfgTmp_hc363607f__0 = (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelf->p__DOT__r_rrs1 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs1)));
    vlSelf->mmu__DOT__w_tlb_wdata = (0x3ffffcU & (vlSelf->mmu__DOT__physical_addr 
                                                  >> 0xaU));
    vlSelf->p__DOT__w_rs2 = (0x1fU & (vlSelf->w_ir 
                                      >> 0x14U));
    vlSelf->w_data_wdata = vlSelf->p__DOT__r_data_wdata;
    vlSelf->w_hart_sc = vlSelf->p__DOT__r_op_AMO_SC;
    vlSelf->p__DOT__w_sin2 = vlSelf->p__DOT__r_rrs2;
    vlSelf->p__DOT__imm_gen0__DOT__imm_I = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xbU) 
                                            | (0x7ffU 
                                               & (vlSelf->w_ir 
                                                  >> 0x14U)));
    vlSelf->p__DOT__imm_gen0__DOT__imm_S = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xbU) 
                                            | ((0x7e0U 
                                                & (vlSelf->w_ir 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->w_ir 
                                                     >> 7U))));
    vlSelf->p__DOT__imm_gen0__DOT__imm_U = (0xfffff000U 
                                            & vlSelf->w_ir);
    vlSelf->p__DOT__imm_gen0__DOT__imm_B = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0xcU) 
                                            | ((0x800U 
                                                & (vlSelf->w_ir 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->w_ir 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->w_ir 
                                                        >> 7U)))));
    vlSelf->p__DOT__imm_gen0__DOT__imm_J = (((- (IData)(
                                                        (vlSelf->w_ir 
                                                         >> 0x1fU))) 
                                             << 0x14U) 
                                            | ((0xff000U 
                                                & vlSelf->w_ir) 
                                               | ((0x800U 
                                                   & (vlSelf->w_ir 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->w_ir 
                                                        >> 0x14U)))));
    vlSelf->w_core_ir = vlSelf->w_ir;
    mmu__DOT____VdfgTmp_hdf96e1fa__0 = ((0U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    mmu__DOT____VdfgTmp_h0821c8f5__0 = (((QData)((IData)(
                                                         (vlSelf->p__DOT__mtimecmp 
                                                          >> 0x20U))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__r_data_wdata)));
    mmu__DOT____VdfgTmp_hd62e4571__0 = (((QData)((IData)(vlSelf->p__DOT__r_data_wdata)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__mtimecmp)));
    mmu__DOT____VdfgTmp_h2aff9416__0 = ((1U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    vlSelf->p__DOT__ALU_IM__DOT__w_shamt = (0x1fU & vlSelf->p__DOT__r_alu_in2);
    vlSelf->w_mip = vlSelf->p__DOT__mip;
    vlSelf->p__DOT__imm_gen0__DOT__opcode = (0x7fU 
                                             & vlSelf->w_ir);
    vlSelf->p__DOT__w_sin1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__w_rs1 = (0x1fU & (vlSelf->w_ir 
                                      >> 0xfU));
    vlSelf->w_tlb_req = vlSelf->p__DOT__r_tlb_req;
    vlSelf->p__DOT__mhartid = vlSelf->w_hart_id;
    p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0 
        = VL_LTS_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2);
    vlSelf->p__DOT__w_csr_addr = (0xfffU & ((0U != (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (IData)(vlSelf->p__DOT__r_funct12)
                                             : ((0U 
                                                 == (IData)(vlSelf->p__DOT__r_funct12))
                                                 ? 0x305U
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelf->p__DOT__r_funct12))
                                                  ? 0x41U
                                                  : 
                                                 ((0x102U 
                                                   == (IData)(vlSelf->p__DOT__r_funct12))
                                                   ? 0x141U
                                                   : 
                                                  ((0x302U 
                                                    == (IData)(vlSelf->p__DOT__r_funct12))
                                                    ? 0x341U
                                                    : 0U))))));
    vlSelf->p__DOT____VdfgTmp_h8573667a__0 = ((~ (IData)(vlSelf->p__DOT__r_op_AMO_SC)) 
                                              & (IData)(vlSelf->p__DOT__r_op_AMO));
    p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend) 
            << 1U) | (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor));
    vlSelf->p__DOT__w_take_int = ((5U != vlSelf->p__DOT__irq_num) 
                                  | ((~ (IData)(vlSelf->p__DOT__r_op_ECALL)) 
                                     & ((~ (IData)(vlSelf->p__DOT__r_op_SRET)) 
                                        & (1U >= (IData)(vlSelf->p__DOT__priv)))));
    vlSelf->p__DOT__w_nalign4 = (7U == (7U & (vlSelf->w_pc 
                                              >> 1U)));
    mmu__DOT____VdfgTmp_h1a37559d__0 = ((~ (IData)(vlSelf->mmu__DOT__page_walk_fail)) 
                                        & (5U == (IData)(vlSelf->mmu__DOT__r_pw_state)));
    if ((0x80000U & vlSelf->p__DOT__mstatus)) {
        vlSelf->mmu__DOT__L0_xwr = (7U & ((vlSelf->mmu__DOT__L0_pte 
                                           >> 1U) | 
                                          (1U & (vlSelf->mmu__DOT__L0_pte 
                                                 >> 3U))));
        vlSelf->mmu__DOT__L1_xwr = (7U & ((vlSelf->mmu__DOT__L1_pte 
                                           >> 1U) | 
                                          (1U & (vlSelf->mmu__DOT__L1_pte 
                                                 >> 3U))));
    } else {
        vlSelf->mmu__DOT__L0_xwr = (7U & (vlSelf->mmu__DOT__L0_pte 
                                          >> 1U));
        vlSelf->mmu__DOT__L1_xwr = (7U & (vlSelf->mmu__DOT__L1_pte 
                                          >> 1U));
    }
    vlSelf->p__DOT__w_mstatus_t = (0x6000U | vlSelf->p__DOT__mstatus);
    vlSelf->p__DOT__ALU_IM__DOT__w_div_signed = ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | (6U 
                                                    == (IData)(vlSelf->p__DOT__r_funct3)));
    vlSelf->mmu__DOT__r_tlb_acs = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                   | ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                      | (5U == (IData)(vlSelf->mmu__DOT__r_pw_state))));
    vlSelf->p__DOT__ALU_IM__DOT__w_div_req = ((IData)(vlSelf->p__DOT__r_alu_f7) 
                                              & ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                    | ((6U 
                                                        == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                       | (7U 
                                                          == (IData)(vlSelf->p__DOT__r_funct3))))));
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy = (0x20U 
                                                   > (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count));
    vlSelf->p__DOT__pending_interrupts = (vlSelf->p__DOT__mie 
                                          & vlSelf->p__DOT__mip);
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag = (vlSelf->p__DOT__r_insn_addr 
                                                 >> 0xeU);
    vlSelf->p__DOT__w_csr_we = ((IData)(vlSelf->p__DOT__r_op_SYS) 
                                & (0U != (IData)(vlSelf->p__DOT__r_funct3)));
    vlSelf->p__DOT__w_sstatus = ((0xfff21eccU & vlSelf->p__DOT__mstatus) 
                                 | (0xde133U & vlSelf->p__DOT__r_wb_data_csr));
    vlSelf->p__DOT__w_ex1 = (5U == (IData)(vlSelf->w_state));
    vlSelf->mmu__DOT__L1_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L1_pte 
                                                 << 2U));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_insn_addr 
                                                    >> 0xcU));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag = (vlSelf->p__DOT__r_mem_addr 
                                                 >> 0xeU);
    vlSelf->mmu__DOT__w_isread = (0U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_mem_addr 
                                                    >> 0xcU));
    vlSelf->mmu__DOT__w_iswrite = (1U == (IData)(vlSelf->p__DOT__r_tlb_req));
    mmu__DOT____VdfgTmp_h5ee52748__0 = (1U & ((~ (vlSelf->p__DOT__satp 
                                                  >> 0x1fU)) 
                                              | (3U 
                                                 == (IData)(vlSelf->p__DOT__priv))));
    vlSelf->mmu__DOT__w_iscode = (2U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__w_tx_ready = vlSelf->w_tx_ready;
    vlSelf->mmu__DOT__RST_X = vlSelf->RST_X;
    vlSelf->mmu__DOT__w_dram_busy = vlSelf->w_dram_busy;
    vlSelf->mmu__DOT__w_data_busy = vlSelf->w_data_busy;
    vlSelf->p__DOT__w_oh_load_res = vlSelf->w_oh_load_res;
    vlSelf->p__DOT__w_oh_reserved = vlSelf->w_oh_reserved;
    vlSelf->p__DOT__w_oh_pc = vlSelf->w_oh_pc;
    vlSelf->p__DOT__w_wmip = vlSelf->w_wmip;
    vlSelf->p__DOT__w_plic_we = vlSelf->w_plic_we;
    vlSelf->p__DOT__w_ipi = vlSelf->w_ipi;
    vlSelf->mmu__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_data_data = vlSelf->w_data_data;
    vlSelf->p__DOT__w_mem_rdata = vlSelf->w_data_data;
    vlSelf->p__DOT__w_alu_c_rslt = ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                     ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_imm))
                                             : (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_imm))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? vlSelf->p__DOT__r_imm
                                             : 0U))
                                     : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_rrs1))
                                             : (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_rrs1))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? vlSelf->p__DOT__r_rrs1
                                             : 0U)));
    vlSelf->p__DOT__cause = ((0xffffffffU != vlSelf->p__DOT__pending_exception)
                              ? vlSelf->p__DOT__pending_exception
                              : (0x80000000U | vlSelf->p__DOT__irq_num));
    vlSelf->mmu__DOT__w_mem_wdata = ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))
                                      ? vlSelf->mmu__DOT__w_mc_wdata
                                      : vlSelf->p__DOT__r_data_wdata);
    if ((0U != (0xe0000U & vlSelf->p__DOT__mstatus))) {
        if (VL_UNLIKELY((0U != (0x20000U & vlSelf->p__DOT__mstatus)))) {
            VL_WRITEF("%x MSTATUS_MPRV mpp=%x --------------------\n",
                      64,vlSelf->w_mtime,32,(0x1800U 
                                             & vlSelf->p__DOT__mstatus));
        }
        if (VL_UNLIKELY((0U != (0x80000U & vlSelf->p__DOT__mstatus)))) {
            VL_WRITEF("%x MSTATUS_MXR --------------------------\n",
                      64,vlSelf->w_mtime);
        }
    }
    vlSelf->p__DOT__w_mstatus_nxt = ((0xffffffffU != vlSelf->p__DOT__pending_exception)
                                      ? vlSelf->p__DOT__r_mstatus_t
                                      : (((IData)(vlSelf->p__DOT__w_csr_we) 
                                          & (0x300U 
                                             == (IData)(vlSelf->p__DOT__r_funct12)))
                                          ? ((0xfff1e644U 
                                              & vlSelf->p__DOT__mstatus) 
                                             | (0xe19bbU 
                                                & vlSelf->p__DOT__r_wb_data_csr))
                                          : (((IData)(vlSelf->p__DOT__w_csr_we) 
                                              & (0x100U 
                                                 == (IData)(vlSelf->p__DOT__r_funct12)))
                                              ? ((0xfff1e644U 
                                                  & vlSelf->p__DOT__mstatus) 
                                                 | (0xe19bbU 
                                                    & vlSelf->p__DOT__w_sstatus))
                                              : vlSelf->p__DOT__r_mstatus_t)));
    vlSelf->p__DOT__w_alu_b_rslt = ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                     ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rrs1 
                                                >= vlSelf->p__DOT__r_alu_in2)
                                             : (vlSelf->p__DOT__r_rrs1 
                                                < vlSelf->p__DOT__r_alu_in2))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? VL_GTES_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2)
                                             : (IData)(p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0)))
                                     : ((~ ((IData)(vlSelf->p__DOT__r_funct3) 
                                            >> 1U)) 
                                        & ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                            ? (vlSelf->p__DOT__r_rrs1 
                                               != vlSelf->p__DOT__r_alu_in2)
                                            : (vlSelf->p__DOT__r_rrs1 
                                               == vlSelf->p__DOT__r_alu_in2))));
    vlSelf->p__DOT__w_mtime = vlSelf->w_mtime;
    vlSelf->mmu__DOT__CLK = vlSelf->CLK;
    vlSelf->p__DOT__CLK = vlSelf->CLK;
    vlSelf->CORE_RST_X = ((IData)(vlSelf->RST_X) & (IData)(vlSelf->w_init_done));
    vlSelf->mmu__DOT__w_dram_odata = vlSelf->w_dram_odata;
    vlSelf->w_insn_data = vlSelf->w_dram_odata;
    vlSelf->p__DOT__w_ir_org = ((3U == (IData)(vlSelf->p__DOT__r_if_state))
                                 ? ((IData)(vlSelf->p__DOT__r_ir16_v)
                                     ? ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_ir16))
                                     : ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_if_irl)))
                                 : vlSelf->w_dram_odata);
    vlSelf->p__DOT__regs__DOT__w_hart_id = vlSelf->p__DOT__w_hart_id;
    vlSelf->p__DOT__imm_gen0__DOT__w_inst = vlSelf->p__DOT__r_ir;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_dividend 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in1;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_divisor 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in2;
    vlSelf->p__DOT__ALU_B__DOT__w_sin2 = vlSelf->p__DOT__ALU_IM__DOT__w_sin2;
    vlSelf->p__DOT__ALU_C__DOT__r_rslt = vlSelf->p__DOT__w_alu_c_rslt;
    vlSelf->mmu__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->p__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->mmu__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->p__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->mmu__DOT__w_proc_data_we = vlSelf->w_proc_data_we;
    vlSelf->p__DOT__w_data_we = vlSelf->w_proc_data_we;
    vlSelf->mmu__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->p__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->mmu__DOT__w_priv = vlSelf->w_priv;
    vlSelf->p__DOT__w_priv = vlSelf->w_priv;
    vlSelf->mmu__DOT__w_satp = vlSelf->w_satp;
    vlSelf->p__DOT__w_satp = vlSelf->w_satp;
    vlSelf->mmu__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->p__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->mmu__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_deleg = ((1U >= (IData)(vlSelf->p__DOT__r_priv_t))
                                ? ((0U != (0x80000000U 
                                           & vlSelf->p__DOT__cause))
                                    ? ((0x1fU >= (0x1fU 
                                                  & vlSelf->p__DOT__cause))
                                        ? (1U & (vlSelf->p__DOT__mideleg 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->p__DOT__cause)))
                                        : 0U) : ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->p__DOT__cause))
                                                  ? 
                                                 (1U 
                                                  & (vlSelf->p__DOT__medeleg 
                                                     >> 
                                                     (0x1fU 
                                                      & vlSelf->p__DOT__cause)))
                                                  : 0U))
                                : 0U);
    vlSelf->p__DOT__w_mul_SS = (p__DOT____VdfgTmp_hc363607f__0 
                                * (((QData)((IData)(
                                                    (- (IData)(
                                                               (vlSelf->p__DOT__r_rrs2 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs2))));
    vlSelf->p__DOT__w_mul_SU = (p__DOT____VdfgTmp_hc363607f__0 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->p__DOT__regs__DOT__w_rs2 = vlSelf->p__DOT__w_rs2;
    vlSelf->p__DOT__w_rrs2 = ((0U == (IData)(vlSelf->p__DOT__w_rs2))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs2]);
    vlSelf->mmu__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->p__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->p__DOT__hart_sc = vlSelf->w_hart_sc;
    vlSelf->p__DOT__ALU_A__DOT__w_sin1 = vlSelf->p__DOT__w_sin2;
    vlSelf->p__DOT__w_core_ir = vlSelf->w_core_ir;
    vlSelf->p__DOT__w_mip = vlSelf->w_mip;
    vlSelf->p__DOT__w_op_priv = (IData)(((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                         & (0U == (0x7000U 
                                                   & vlSelf->w_ir))));
    vlSelf->p__DOT__w_op_csr = ((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                & (0U != (7U & (vlSelf->w_ir 
                                                >> 0xcU))));
    vlSelf->p__DOT__ALU_IM__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__ALU_B__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__regs__DOT__w_rs1 = vlSelf->p__DOT__w_rs1;
    vlSelf->p__DOT__w_rrs1 = ((0U == (IData)(vlSelf->p__DOT__w_rs1))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs1]);
    vlSelf->p__DOT__imm_gen0__DOT__imm_C = vlSelf->p__DOT__w_rs1;
    vlSelf->mmu__DOT__w_tlb_req = vlSelf->w_tlb_req;
    vlSelf->p__DOT__w_tlb_req = vlSelf->w_tlb_req;
    vlSelf->p__DOT__w_usestate = ((~ (IData)(vlSelf->p__DOT__r_ir16_v)) 
                                  & (IData)(vlSelf->p__DOT__w_nalign4));
    vlSelf->mmu__DOT__L0_success = (1U & (~ ((2U == (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                             | ((6U 
                                                 == (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                                | (((1U 
                                                     == (IData)(vlSelf->p__DOT__priv)) 
                                                    & ((~ 
                                                        (vlSelf->p__DOT__mstatus 
                                                         >> 0x12U)) 
                                                       & (IData)(
                                                                 (0x10U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L0_pte))))) 
                                                   | ((~ 
                                                       ((2U 
                                                         >= (IData)(vlSelf->p__DOT__r_tlb_req)) 
                                                        & ((IData)(vlSelf->mmu__DOT__L0_xwr) 
                                                           >> (IData)(vlSelf->p__DOT__r_tlb_req)))) 
                                                      | (IData)(
                                                                ((0U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L0_pte)) 
                                                                 & (0U 
                                                                    == (IData)(vlSelf->p__DOT__priv))))))))));
    vlSelf->p__DOT__w_sstatus_t = (0xde133U & vlSelf->p__DOT__w_mstatus_t);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_signed 
        = vlSelf->p__DOT__ALU_IM__DOT__w_div_signed;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed) 
            & (vlSelf->p__DOT__r_rrs1 >> 0x1fU)) ? 
           ((IData)(1U) + (~ vlSelf->p__DOT__r_rrs1))
            : vlSelf->p__DOT__r_rrs1);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed) 
            & (vlSelf->p__DOT__r_alu_in2 >> 0x1fU))
            ? ((IData)(1U) + (~ vlSelf->p__DOT__r_alu_in2))
            : vlSelf->p__DOT__r_alu_in2);
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt = (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed)
                                                                      ? 
                                                                     ((0U 
                                                                       == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                       ? (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))
                                                                       : 
                                                                      ((1U 
                                                                        == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                        ? (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))
                                                                        : 
                                                                       ((IData)(1U) 
                                                                        + 
                                                                        (~ (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))))))
                                                                      : (IData)(
                                                                                (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                                                >> 0x20U))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed)
                                                                       ? 
                                                                      ((0U 
                                                                        == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                        ? (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)
                                                                        : 
                                                                       ((1U 
                                                                         == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                         ? 
                                                                        ((IData)(1U) 
                                                                         + 
                                                                         (~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))
                                                                         : 
                                                                        ((2U 
                                                                          == (IData)(p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0))
                                                                          ? 
                                                                         ((IData)(1U) 
                                                                          + 
                                                                          (~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))
                                                                          : (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt))))
                                                                       : (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt)))));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy;
    vlSelf->p__DOT__w_exit_wfi = (((1U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                   & (0U != (0x222U 
                                             & vlSelf->p__DOT__pending_interrupts))) 
                                  | ((0U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                     & (0U != (0x111U 
                                               & vlSelf->p__DOT__pending_interrupts))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag;
    vlSelf->p__DOT__w_wb_r_enable = ((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                     | ((0x37U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                        | ((0x17U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                           | ((0x6fU 
                                               == (IData)(vlSelf->p__DOT__r_opcode)) 
                                              | ((0x67U 
                                                  == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                 | ((0x33U 
                                                     == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                    | ((0x13U 
                                                        == (IData)(vlSelf->p__DOT__r_opcode)) 
                                                       | ((IData)(vlSelf->p__DOT__r_op_AMO) 
                                                          | (IData)(vlSelf->p__DOT__w_csr_we)))))))));
    vlSelf->p__DOT__w_wb_r_data = ((IData)(vlSelf->p__DOT__r_op_LOAD)
                                    ? vlSelf->w_data_data
                                    : ((IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)
                                        ? vlSelf->p__DOT__r_mem_rdata
                                        : ((IData)(vlSelf->p__DOT__w_csr_we)
                                            ? vlSelf->p__DOT__r_rcsr
                                            : vlSelf->p__DOT__r_wb_data)));
    vlSelf->p__DOT__w_data_t = ((0x300U == (IData)(vlSelf->p__DOT__r_funct12))
                                 ? vlSelf->p__DOT__r_wb_data_csr
                                 : vlSelf->p__DOT__w_sstatus);
    vlSelf->p__DOT__ALU_IM__DOT__w_le = vlSelf->p__DOT__w_ex1;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_init = ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                               & ((~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy)) 
                                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__r_div_first) 
                                                     & (IData)(vlSelf->p__DOT__w_ex1))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx;
    mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx];
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_rtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__L1_success = (1U & (~ ((2U == (IData)(vlSelf->mmu__DOT__L1_xwr)) 
                                             | ((6U 
                                                 == (IData)(vlSelf->mmu__DOT__L1_xwr)) 
                                                | (((1U 
                                                     == (IData)(vlSelf->p__DOT__priv)) 
                                                    & ((~ 
                                                        (vlSelf->p__DOT__mstatus 
                                                         >> 0x12U)) 
                                                       & (IData)(
                                                                 (0x10U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L1_pte))))) 
                                                   | ((~ 
                                                       ((2U 
                                                         >= (IData)(vlSelf->p__DOT__r_tlb_req)) 
                                                        & ((IData)(vlSelf->mmu__DOT__L1_xwr) 
                                                           >> (IData)(vlSelf->p__DOT__r_tlb_req)))) 
                                                      | (IData)(
                                                                ((0U 
                                                                  == 
                                                                  (0x30U 
                                                                   & vlSelf->mmu__DOT__L1_pte)) 
                                                                 & (0U 
                                                                    == (IData)(vlSelf->p__DOT__priv))))))))));
    vlSelf->mmu__DOT__w_tlb_data_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_ridx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_r__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_w__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    vlSelf->mmu__DOT__w_tlb_data_w_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iswrite));
    vlSelf->mmu__DOT__L1_pte_write = (0x40U | (vlSelf->mmu__DOT__L1_pte 
                                               | ((IData)(vlSelf->mmu__DOT__w_iswrite)
                                                   ? 0x80U
                                                   : 0U)));
    vlSelf->mmu__DOT__L0_pte_write = (0x40U | (vlSelf->mmu__DOT__L0_pte 
                                               | ((IData)(vlSelf->mmu__DOT__w_iswrite)
                                                   ? 0x80U
                                                   : 0U)));
    vlSelf->mmu__DOT__L1_write = (1U & ((~ (vlSelf->mmu__DOT__L1_pte 
                                            >> 6U)) 
                                        | ((~ (vlSelf->mmu__DOT__L1_pte 
                                               >> 7U)) 
                                           & (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__L0_write = (1U & ((~ (vlSelf->mmu__DOT__L0_pte 
                                            >> 6U)) 
                                        | ((~ (vlSelf->mmu__DOT__L0_pte 
                                               >> 7U)) 
                                           & (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__w_insn_paddr = ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                       ? vlSelf->p__DOT__r_insn_addr
                                       : vlSelf->mmu__DOT__r_tlb_addr);
    vlSelf->mmu__DOT__w_tlb_inst_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->w_pagefault = ((IData)(vlSelf->mmu__DOT__page_walk_fail)
                            ? ((IData)(vlSelf->mmu__DOT__w_iscode)
                                ? 0xcU : ((IData)(vlSelf->mmu__DOT__w_isread)
                                           ? 0xdU : 0xfU))
                            : 0xffffffffU);
    mmu__DOT____VdfgTmp_hdc3ed8a3__0 = ((IData)(vlSelf->mmu__DOT__w_iscode) 
                                        | (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__v_addr = ((IData)(vlSelf->mmu__DOT__w_iscode)
                                 ? vlSelf->p__DOT__r_insn_addr
                                 : vlSelf->p__DOT__r_mem_addr);
    vlSelf->p__DOT__ALU_A__DOT__w_in2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__ALU_A__DOT__w_sin2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__w_alu_a_rslt = ((0x10U & (IData)(vlSelf->p__DOT__r_funct5))
                                     ? ((8U & (IData)(vlSelf->p__DOT__r_funct5))
                                         ? ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 ((vlSelf->p__DOT__r_rrs2 
                                                   > vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 ((vlSelf->p__DOT__r_rrs2 
                                                   < vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata))))
                                         : ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (VL_GTS_III(32, vlSelf->p__DOT__w_sin2, vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (VL_LTS_III(32, vlSelf->p__DOT__w_sin2, vlSelf->p__DOT__w_mem_rdata)
                                                   ? vlSelf->p__DOT__r_rrs2
                                                   : vlSelf->p__DOT__w_mem_rdata)))))
                                     : ((8U & (IData)(vlSelf->p__DOT__r_funct5))
                                         ? ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  & vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  | vlSelf->p__DOT__w_mem_rdata))))
                                         : ((4U & (IData)(vlSelf->p__DOT__r_funct5))
                                             ? ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  ^ vlSelf->p__DOT__w_mem_rdata)))
                                             : ((2U 
                                                 & (IData)(vlSelf->p__DOT__r_funct5))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? vlSelf->p__DOT__r_rrs2
                                                  : 0U)
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct5))
                                                  ? vlSelf->p__DOT__r_rrs2
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs2 
                                                  + vlSelf->p__DOT__w_mem_rdata))))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_w__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->p__DOT__regs__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__RST_X = vlSelf->CORE_RST_X;
    vlSelf->mmu__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__decomp0__DOT__w_ic = vlSelf->p__DOT__w_ir_org;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm1 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 0xbU) 
                                               | ((0x400U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 2U)) 
                                                  | ((0x300U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         >> 1U)) 
                                                     | ((0x80U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 1U)) 
                                                        | ((0x40U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 1U)) 
                                                           | ((0x20U 
                                                               & (vlSelf->p__DOT__w_ir_org 
                                                                  << 3U)) 
                                                              | ((0x10U 
                                                                  & (vlSelf->p__DOT__w_ir_org 
                                                                     >> 7U)) 
                                                                 | (0xeU 
                                                                    & (vlSelf->p__DOT__w_ir_org 
                                                                       >> 2U)))))))));
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm3 = ((0x1c0U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 1U)) 
                                                | (0x38U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      >> 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm4 = ((0xc0U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 1U)) 
                                                | (0x3cU 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      >> 7U)));
    vlSelf->p__DOT__w_cinsn = (3U != (3U & vlSelf->p__DOT__w_ir_org));
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm4 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 9U) 
                                               | ((0x180U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 4U)) 
                                                  | ((0x40U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 1U)) 
                                                     | ((0x20U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 3U)) 
                                                        | (0x10U 
                                                           & (vlSelf->p__DOT__w_ir_org 
                                                              >> 2U))))));
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct2 = ((4U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     >> 0xaU)) 
                                                 | (3U 
                                                    & (vlSelf->p__DOT__w_ir_org 
                                                       >> 5U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_rd = (0x1fU 
                                             & (vlSelf->p__DOT__w_ir_org 
                                                >> 7U));
    p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0 = 
        ((2U & (vlSelf->p__DOT__w_ir_org >> 4U)) | 
         (1U & (vlSelf->p__DOT__w_ir_org >> 0xcU)));
    p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0 = 
        ((0x200U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | ((0x180U & (vlSelf->p__DOT__w_ir_org >> 2U)) 
            | ((0x40U & vlSelf->p__DOT__w_ir_org) | 
               ((0x20U & (vlSelf->p__DOT__w_ir_org 
                          >> 2U)) | ((0x10U & (vlSelf->p__DOT__w_ir_org 
                                               << 2U)) 
                                     | ((8U & (vlSelf->p__DOT__w_ir_org 
                                               >> 8U)) 
                                        | (7U & (vlSelf->p__DOT__w_ir_org 
                                                 >> 3U))))))));
    p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0 = 
        ((6U & (vlSelf->p__DOT__w_ir_org >> 6U)) | 
         (1U & (vlSelf->p__DOT__w_ir_org >> 0xcU)));
    p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0 = 
        ((0x40U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | ((0x38U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (4U & (vlSelf->p__DOT__w_ir_org >> 4U))));
    p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0 = 
        ((0xc0U & (vlSelf->p__DOT__w_ir_org << 1U)) 
         | (0x38U & (vlSelf->p__DOT__w_ir_org >> 7U)));
    p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0 = 
        ((0x3c0U & (vlSelf->p__DOT__w_ir_org >> 1U)) 
         | ((0x30U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | ((8U & (vlSelf->p__DOT__w_ir_org >> 2U)) 
               | (4U & (vlSelf->p__DOT__w_ir_org >> 4U)))));
    p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0 = 
        ((0x1c0U & (vlSelf->p__DOT__w_ir_org << 4U)) 
         | ((0x20U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (0x18U & (vlSelf->p__DOT__w_ir_org >> 2U))));
    p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0 = 
        ((0xc0U & (vlSelf->p__DOT__w_ir_org << 4U)) 
         | ((0x20U & (vlSelf->p__DOT__w_ir_org >> 7U)) 
            | (0x1cU & (vlSelf->p__DOT__w_ir_org >> 2U))));
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs2 = (8U | 
                                              (7U & 
                                               (vlSelf->p__DOT__w_ir_org 
                                                >> 2U)));
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs1 = (8U | 
                                              (7U & 
                                               (vlSelf->p__DOT__w_ir_org 
                                                >> 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c1_shamt = (0x1fU 
                                                & (vlSelf->p__DOT__w_ir_org 
                                                   >> 2U));
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct1 = (3U 
                                                 & (vlSelf->p__DOT__w_ir_org 
                                                    >> 0xaU));
    vlSelf->p__DOT__regs__DOT__w_rdata2 = vlSelf->p__DOT__w_rrs2;
    vlSelf->p__DOT__regs__DOT__w_rdata1 = vlSelf->p__DOT__w_rrs1;
    vlSelf->p__DOT__w_imm = ((0x40U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                              ? ((0x20U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                  ? ((0x10U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                      ? ((8U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                          ? 0U : ((4U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? vlSelf->p__DOT__imm_gen0__DOT__imm_C
                                                     : 0U)
                                                    : 0U)))
                                      : ((8U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                          ? ((4U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                              ? ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_J
                                                   : 0U)
                                                  : 0U)
                                              : 0U)
                                          : ((4U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                              ? ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                   : 0U)
                                                  : 0U)
                                              : ((2U 
                                                  & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                   ? vlSelf->p__DOT__imm_gen0__DOT__imm_B
                                                   : 0U)
                                                  : 0U))))
                                  : 0U) : ((0x20U & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                            ? ((0x10U 
                                                & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_U
                                                       : 0U)
                                                      : 0U)
                                                     : 0U))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_S
                                                       : 0U)
                                                      : 0U))))
                                            : ((0x10U 
                                                & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                ? (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_U
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                       : 0U)
                                                      : 0U)))
                                                : (
                                                   (8U 
                                                    & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode))
                                                       ? vlSelf->p__DOT__imm_gen0__DOT__imm_I
                                                       : 0U)
                                                      : 0U))))));
    vlSelf->p__DOT__ALU_B__DOT__r_rslt = vlSelf->p__DOT__w_alu_b_rslt;
    vlSelf->p__DOT__r_rcsr_t = ((0x800U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                 ? ((0x400U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                     ? ((0x200U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                         ? ((0x100U 
                                             & (IData)(vlSelf->p__DOT__w_csr_addr))
                                             ? ((0x80U 
                                                 & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                 ? 0U
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : vlSelf->p__DOT__mhartid))
                                                      : 0U))
                                                    : 0U))))
                                             : 0U) : 
                                        ((0x100U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                          ? 0U : ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U)))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U))
                                                          : (IData)(
                                                                    (vlSelf->w_mtime 
                                                                     >> 0x20U)))))))))
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : (IData)(vlSelf->w_mtime))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? (IData)(vlSelf->w_mtime)
                                                          : (IData)(vlSelf->w_mtime)))))))))))
                                     : ((0x200U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                         ? ((0x100U 
                                             & (IData)(vlSelf->p__DOT__w_csr_addr))
                                             ? ((0x80U 
                                                 & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                 ? 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(
                                                                  (vlSelf->w_mtime 
                                                                   >> 0x20U)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(
                                                                  (vlSelf->w_mtime 
                                                                   >> 0x20U)))))))))
                                                 : 
                                                ((0x40U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 0U
                                                  : 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x10U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(vlSelf->w_mtime))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : (IData)(vlSelf->w_mtime)))))))))
                                             : 0U) : 0U))
                                 : ((0x400U & (IData)(vlSelf->p__DOT__w_csr_addr))
                                     ? 0U : ((0x200U 
                                              & (IData)(vlSelf->p__DOT__w_csr_addr))
                                              ? ((0x100U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 
                                                 ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 0U
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__mip))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mtval
                                                          : vlSelf->p__DOT__mcause)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mepc
                                                          : vlSelf->p__DOT__mscratch))))))
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__mcounteren)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mtvec
                                                          : vlSelf->p__DOT__mie))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__mideleg
                                                          : vlSelf->p__DOT__medeleg)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 
                                                         (0x40000000U 
                                                          | vlSelf->p__DOT__misa)
                                                          : 
                                                         (((3U 
                                                            == 
                                                            (vlSelf->p__DOT__w_mstatus_t 
                                                             >> 0xdU)) 
                                                           | (3U 
                                                              == 
                                                              (vlSelf->p__DOT__w_mstatus_t 
                                                               >> 0xfU)))
                                                           ? 
                                                          (0x80006000U 
                                                           | vlSelf->p__DOT__mstatus)
                                                           : vlSelf->p__DOT__w_mstatus_t)))))))))
                                                  : 0U)
                                              : ((0x100U 
                                                  & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                  ? 
                                                 ((0x80U 
                                                   & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                   ? 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 0U
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__satp)))))))
                                                   : 
                                                  ((0x40U 
                                                    & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                    ? 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : 
                                                         (vlSelf->p__DOT__mip 
                                                          & vlSelf->p__DOT__mideleg)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__stval
                                                          : vlSelf->p__DOT__scause)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__sepc
                                                          : vlSelf->p__DOT__sscratch))))))
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : vlSelf->p__DOT__scounteren)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? vlSelf->p__DOT__stvec
                                                          : 
                                                         (vlSelf->p__DOT__mie 
                                                          & vlSelf->p__DOT__mideleg)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->p__DOT__w_csr_addr))
                                                          ? 0U
                                                          : 
                                                         (((3U 
                                                            == 
                                                            (vlSelf->p__DOT__w_sstatus_t 
                                                             >> 0xdU)) 
                                                           | (3U 
                                                              == 
                                                              (vlSelf->p__DOT__w_sstatus_t 
                                                               >> 0xfU)))
                                                           ? 
                                                          (0x80000000U 
                                                           | vlSelf->p__DOT__w_sstatus_t)
                                                           : vlSelf->p__DOT__w_sstatus_t)))))))))
                                                  : 0U))));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_dividend 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_divisor 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_rslt 
        = vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt = ((0U 
                                                == vlSelf->p__DOT__r_alu_in2)
                                                ? (0xffffffffULL 
                                                   | ((QData)((IData)(vlSelf->p__DOT__r_rrs1)) 
                                                      << 0x20U))
                                                : (
                                                   ((0xffffffffU 
                                                     == vlSelf->p__DOT__r_alu_in2) 
                                                    & (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_signed))
                                                    ? (QData)((IData)(vlSelf->p__DOT__r_rrs1))
                                                    : vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy;
    vlSelf->p__DOT__w_regfile_we = ((IData)(vlSelf->p__DOT__w_wb_r_enable) 
                                    & (9U == (IData)(vlSelf->w_state)));
    vlSelf->p__DOT__regs__DOT__w_wdata = vlSelf->p__DOT__w_wb_r_data;
    vlSelf->p__DOT__w_mod = (vlSelf->p__DOT__w_data_t 
                             ^ vlSelf->p__DOT__mstatus);
    p__DOT____VdfgTmp_h17b05525__0 = (vlSelf->p__DOT__w_mstatus_nxt 
                                      >> (IData)(vlSelf->p__DOT__r_priv_t));
    vlSelf->p__DOT__enable_interrupts = ((0U != vlSelf->p__DOT__pending_interrupts)
                                          ? ((3U == (IData)(vlSelf->p__DOT__r_priv_t))
                                              ? ((0U 
                                                  != 
                                                  (8U 
                                                   & vlSelf->p__DOT__w_mstatus_nxt))
                                                  ? 
                                                 (~ vlSelf->p__DOT__mideleg)
                                                  : 0U)
                                              : ((1U 
                                                  == (IData)(vlSelf->p__DOT__r_priv_t))
                                                  ? 
                                                 ((0U 
                                                   != 
                                                   (2U 
                                                    & vlSelf->p__DOT__w_mstatus_nxt))
                                                   ? 0xffffffffU
                                                   : 
                                                  (~ vlSelf->p__DOT__mideleg))
                                                  : 
                                                 ((0U 
                                                   == (IData)(vlSelf->p__DOT__r_priv_t))
                                                   ? 0xffffffffU
                                                   : 0U)))
                                          : 0U);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__w_div_init;
    vlSelf->p__DOT__w_ex1_busy = ((IData)(vlSelf->p__DOT__w_ex1) 
                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                     & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy) 
                                        | (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_init))));
    vlSelf->mmu__DOT__w_tlb_inst_r_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag);
    mmu__DOT____VdfgTmp_h8d9b33e2__0 = ((IData)(vlSelf->mmu__DOT__L1_success) 
                                        & (0U != (IData)(vlSelf->mmu__DOT__L1_xwr)));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_r_we;
    vlSelf->mmu__DOT__w_tlb_data_r_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag);
    vlSelf->mmu__DOT__w_tlb_data_w_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag);
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_w_we;
    if ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))) {
        vlSelf->mmu__DOT__w_mem_ctrl = vlSelf->mmu__DOT__w_mc_ctrl;
        vlSelf->w_mem_paddr = vlSelf->mmu__DOT__w_mc_addr;
    } else if (mmu__DOT____VdfgTmp_h5ee52748__0) {
        vlSelf->mmu__DOT__w_mem_ctrl = vlSelf->p__DOT__r_data_ctrl;
        vlSelf->w_mem_paddr = vlSelf->p__DOT__r_mem_addr;
    } else {
        vlSelf->mmu__DOT__w_mem_ctrl = ((0U == (3U 
                                                & (IData)(vlSelf->mmu__DOT__r_tlb_use)))
                                         ? ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                             ? 2U : 
                                            ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                              ? 2U : 
                                             ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                               ? 2U
                                               : (IData)(vlSelf->p__DOT__r_data_ctrl))))
                                         : (IData)(vlSelf->p__DOT__r_data_ctrl));
        vlSelf->w_mem_paddr = vlSelf->mmu__DOT__r_tlb_addr;
    }
    vlSelf->mmu__DOT__w_mem_paddr = vlSelf->w_mem_paddr;
    vlSelf->mmu__DOT__w_virt = (0xfU & (vlSelf->w_mem_paddr 
                                        >> 0x18U));
    vlSelf->mmu__DOT__w_offset = (0x7ffffffU & vlSelf->w_mem_paddr);
    vlSelf->mmu__DOT__w_dev = (vlSelf->w_mem_paddr 
                               >> 0x1cU);
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_inst_r_we;
    vlSelf->mmu__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->p__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->p__DOT__w_com = (((0xffffffffU != vlSelf->p__DOT__pending_exception) 
                              | ((0xffffffffU != vlSelf->w_pagefault) 
                                 | ((IData)(vlSelf->p__DOT__w_ex1) 
                                    & (IData)(vlSelf->p__DOT__r_op_ECALL)))) 
                             & ((0xaU != (IData)(vlSelf->w_state)) 
                                & ((0xbU != (IData)(vlSelf->w_state)) 
                                   & (0U != (IData)(vlSelf->w_state)))));
    vlSelf->mmu__DOT__w_use_tlb = ((0U == (IData)(vlSelf->mmu__DOT__r_mc_mode)) 
                                   & ((~ (IData)(mmu__DOT____VdfgTmp_h5ee52748__0)) 
                                      & ((IData)(mmu__DOT____VdfgTmp_hdc3ed8a3__0) 
                                         | (IData)(vlSelf->mmu__DOT__w_iswrite))));
    vlSelf->mmu__DOT__vpn1 = (vlSelf->mmu__DOT__v_addr 
                              >> 0x16U);
    vlSelf->mmu__DOT__vpn0 = (0x3ffU & (vlSelf->mmu__DOT__v_addr 
                                        >> 0xcU));
    vlSelf->mmu__DOT__L1_p_addr = ((0xffc00000U & (vlSelf->mmu__DOT__L1_pte 
                                                   << 2U)) 
                                   | (0x3fffffU & vlSelf->mmu__DOT__v_addr));
    vlSelf->mmu__DOT__L0_p_addr = ((0xfffff000U & (vlSelf->mmu__DOT__L0_pte 
                                                   << 2U)) 
                                   | (0xfffU & vlSelf->mmu__DOT__v_addr));
    vlSelf->mmu__DOT__L1_pte_addr = ((vlSelf->p__DOT__satp 
                                      << 0xcU) + (0xffcU 
                                                  & (vlSelf->mmu__DOT__v_addr 
                                                     >> 0x14U)));
    vlSelf->mmu__DOT__L0_pte_addr = (vlSelf->mmu__DOT__L1_paddr 
                                     + (0xffcU & (vlSelf->mmu__DOT__v_addr 
                                                  >> 0xaU)));
    vlSelf->p__DOT__ALU_A__DOT__r_rslt = vlSelf->p__DOT__w_alu_a_rslt;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__RST_X = vlSelf->p__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm1 = p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm2 = p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_nzuimm = p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm1 = p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm2 = p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_rd = vlSelf->p__DOT__decomp0__DOT__w_c0_rs2;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs2 = vlSelf->p__DOT__decomp0__DOT__w_c0_rs2;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs1 = vlSelf->p__DOT__decomp0__DOT__w_c0_rs1;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rd = vlSelf->p__DOT__decomp0__DOT__w_c0_rs1;
    p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0 = 
        (0x5013U | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                     << 0xfU) | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                 << 7U)));
    vlSelf->p__DOT__decomp0__DOT__w_c2_rs2 = vlSelf->p__DOT__decomp0__DOT__w_c1_shamt;
    vlSelf->p__DOT__decomp0__DOT__w_c2_shamt = vlSelf->p__DOT__decomp0__DOT__w_c1_shamt;
    vlSelf->p__DOT__decomp0__DOT__w_c2_nzuimm = ((0x20U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     >> 7U)) 
                                                 | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0 = 
        ((0xfe0U & ((- (IData)((1U & (vlSelf->p__DOT__w_ir_org 
                                      >> 0xcU)))) << 5U)) 
         | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm = (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->p__DOT__w_ir_org 
                                                                >> 0xcU)))) 
                                                 << 5U) 
                                                | (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt));
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 = (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->p__DOT__w_ir_org 
                                                               >> 0xcU)))) 
                                                << 8U) 
                                               | ((0xc0U 
                                                   & (vlSelf->p__DOT__w_ir_org 
                                                      << 1U)) 
                                                  | ((0x20U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 3U)) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                                                         << 3U) 
                                                        | (6U 
                                                           & (vlSelf->p__DOT__w_ir_org 
                                                              >> 2U))))));
    p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0 = 
        (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
          << 3U) | (4U & (vlSelf->p__DOT__w_ir_org 
                          >> 4U)));
    p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0 = 
        (0x63U | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                   << 0xaU) | ((0x300U & (vlSelf->p__DOT__w_ir_org 
                                          << 5U)) | 
                               (0x80U & (vlSelf->p__DOT__w_ir_org 
                                         >> 5U)))));
    vlSelf->p__DOT__imm_gen0__DOT__r_imm = vlSelf->p__DOT__w_imm;
    vlSelf->p__DOT__w_alu_im_rslt = ((1U & (IData)(vlSelf->p__DOT__r_alu_f7))
                                      ? ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                          ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0U 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? vlSelf->p__DOT__r_rrs1
                                                   : (IData)(
                                                             (vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                                              >> 0x20U)))
                                                  : 
                                                 ((0xffffffffU 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? 0U
                                                   : 
                                                  ((0U 
                                                    == vlSelf->p__DOT__r_alu_in2)
                                                    ? vlSelf->p__DOT__r_rrs1
                                                    : (IData)(
                                                              (vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                                               >> 0x20U)))))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0U 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? 0xffffffffU
                                                   : (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt))
                                                  : 
                                                 ((0xffffffffU 
                                                   == vlSelf->p__DOT__r_alu_in2)
                                                   ? vlSelf->p__DOT__r_rrs1
                                                   : 
                                                  ((0U 
                                                    == vlSelf->p__DOT__r_alu_in2)
                                                    ? 0xffffffffU
                                                    : (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt)))))
                                          : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? (IData)(
                                                            (vlSelf->p__DOT__r_mul_UU 
                                                             >> 0x20U))
                                                  : (IData)(
                                                            (vlSelf->p__DOT__r_mul_SU 
                                                             >> 0x20U)))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? (IData)(
                                                            (vlSelf->p__DOT__r_mul_SS 
                                                             >> 0x20U))
                                                  : (IData)(vlSelf->p__DOT__r_mul_SS))))
                                      : ((4U & (IData)(vlSelf->p__DOT__r_funct3))
                                          ? ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  & vlSelf->p__DOT__r_alu_in2)
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  | vlSelf->p__DOT__r_alu_in2))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 ((0x20U 
                                                   & (IData)(vlSelf->p__DOT__r_alu_f7))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->p__DOT__w_sin1, (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt))
                                                   : 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   >> (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt)))
                                                  : 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  ^ vlSelf->p__DOT__r_alu_in2)))
                                          : ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  < vlSelf->p__DOT__r_alu_in2)
                                                  : (IData)(p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0))
                                              : ((1U 
                                                  & (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 
                                                 (vlSelf->p__DOT__r_rrs1 
                                                  << (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_shamt))
                                                  : 
                                                 ((0U 
                                                   != (IData)(vlSelf->p__DOT__r_alu_f7))
                                                   ? 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   - vlSelf->p__DOT__r_alu_in2)
                                                   : 
                                                  (vlSelf->p__DOT__r_rrs1 
                                                   + vlSelf->p__DOT__r_alu_in2))))));
    vlSelf->p__DOT__regs__DOT__w_we = vlSelf->p__DOT__w_regfile_we;
    vlSelf->p__DOT__w_sstatus_t1 = ((0xffffffdfU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x20U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 5U)));
    vlSelf->p__DOT__w_mstatus_t1 = ((0xffffff7fU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x80U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 7U)));
    vlSelf->p__DOT__w_interrupt_mask = (vlSelf->p__DOT__pending_interrupts 
                                        & vlSelf->p__DOT__enable_interrupts);
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init;
    vlSelf->p__DOT__ALU_IM__DOT__w_busy = vlSelf->p__DOT__w_ex1_busy;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_inst_r_addr;
    vlSelf->mmu__DOT__w_tlb_inst_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx)));
    if (mmu__DOT____VdfgTmp_h8d9b33e2__0) {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L1_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L1_pte_addr;
    } else {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L0_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L0_pte_addr;
    }
    vlSelf->mmu__DOT__w_pte_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                  & (((IData)(mmu__DOT____VdfgTmp_h8d9b33e2__0) 
                                      & (IData)(vlSelf->mmu__DOT__L1_write)) 
                                     | ((IData)(vlSelf->mmu__DOT__L0_success) 
                                        & ((0U != (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                           & (IData)(vlSelf->mmu__DOT__L0_write)))));
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_r_addr;
    vlSelf->mmu__DOT__w_tlb_data_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_w_addr;
    vlSelf->mmu__DOT__w_tlb_data_w_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->w_clint_we = (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                           & (IData)(vlSelf->p__DOT__r_data_we)) 
                          & ((((0x4000U == vlSelf->mmu__DOT__w_offset) 
                               | (0x4004U == vlSelf->mmu__DOT__w_offset)) 
                              & (0U == vlSelf->w_hart_id)) 
                             | (((0x4008U == vlSelf->mmu__DOT__w_offset) 
                                 | (0x400cU == vlSelf->mmu__DOT__w_offset)) 
                                & (1U == vlSelf->w_hart_id))));
    vlSelf->w_wmtimecmp = (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                            & ((0x4000U == vlSelf->mmu__DOT__w_offset) 
                               & (IData)(mmu__DOT____VdfgTmp_hdf96e1fa__0)))
                            ? mmu__DOT____VdfgTmp_h0821c8f5__0
                            : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                & ((0x4004U == vlSelf->mmu__DOT__w_offset) 
                                   & (IData)(mmu__DOT____VdfgTmp_hdf96e1fa__0)))
                                ? mmu__DOT____VdfgTmp_hd62e4571__0
                                : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                    & ((0x4008U == vlSelf->mmu__DOT__w_offset) 
                                       & (IData)(mmu__DOT____VdfgTmp_h2aff9416__0)))
                                    ? mmu__DOT____VdfgTmp_h0821c8f5__0
                                    : (((6U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                        & ((0x400cU 
                                            == vlSelf->mmu__DOT__w_offset) 
                                           & (IData)(mmu__DOT____VdfgTmp_h2aff9416__0)))
                                        ? mmu__DOT____VdfgTmp_hd62e4571__0
                                        : 0ULL))));
    vlSelf->w_proc_busy = (((IData)(vlSelf->mmu__DOT__w_use_tlb) 
                            & (7U > (IData)(vlSelf->mmu__DOT__r_pw_state))) 
                           | ((IData)(vlSelf->w_dram_busy) 
                              | (0U != (IData)(vlSelf->w_data_busy))));
    vlSelf->w_tlb_busy = ((6U != (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                          & (IData)(vlSelf->mmu__DOT__w_use_tlb));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm3 = vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm;
    if ((2U & vlSelf->p__DOT__w_ir_org)) {
        vlSelf->p__DOT__w_ir_t = ((1U & vlSelf->p__DOT__w_ir_org)
                                   ? vlSelf->p__DOT__w_ir_org
                                   : ((0x8000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x4000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x12027U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0) 
                                                      << 0x19U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                         << 0x14U) 
                                                        | (0xe00U 
                                                           & vlSelf->p__DOT__w_ir_org))))
                                               : (0x12023U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h395bfa7d__0) 
                                                      << 0x19U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                         << 0x14U) 
                                                        | (0xe00U 
                                                           & vlSelf->p__DOT__w_ir_org)))))
                                           : ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x13027U 
                                                  | ((0x1c000000U 
                                                      & (vlSelf->p__DOT__w_ir_org 
                                                         << 0x13U)) 
                                                     | ((0x2000000U 
                                                         & (vlSelf->p__DOT__w_ir_org 
                                                            << 0xdU)) 
                                                        | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                            << 0x14U) 
                                                           | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1) 
                                                              << 0xaU)))))
                                               : ((0U 
                                                   == (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd))
                                                    ? 0x100073U
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->p__DOT__w_ir_org)
                                                     ? 
                                                    (0xe7U 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 0xfU))
                                                     : 
                                                    (0x67U 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 0xfU))))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->p__DOT__w_ir_org)
                                                    ? 
                                                   (0x33U 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                        << 0x14U) 
                                                       | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                           << 0xfU) 
                                                          | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                             << 7U))))
                                                    : 
                                                   (0x33U 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                        << 0x14U) 
                                                       | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                          << 7U)))))))
                                       : ((0x4000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x12007U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U)))
                                               : (0x12003U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h76c906af__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U))))
                                           : ((0x2000U 
                                               & vlSelf->p__DOT__w_ir_org)
                                               ? (0x13007U 
                                                  | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h259cd8e2__0) 
                                                      << 0x14U) 
                                                     | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                        << 7U)))
                                               : (0x1013U 
                                                  | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                         << 0xfU) 
                                                        | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c2_rd) 
                                                           << 7U))))))));
    } else if ((1U & vlSelf->p__DOT__w_ir_org)) {
        vlSelf->p__DOT__w_ir_t = ((0x8000U & vlSelf->p__DOT__w_ir_org)
                                   ? ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0x1000U 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | ((0x7e000000U 
                                                     & (vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 
                                                        << 0x14U)) 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                        << 0xfU) 
                                                       | (IData)(p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0)))))
                                           : ((0x80000000U 
                                               & (vlSelf->p__DOT__w_ir_org 
                                                  << 0x13U)) 
                                              | ((0x7e000000U 
                                                  & (vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 
                                                     << 0x14U)) 
                                                 | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                     << 0xfU) 
                                                    | (IData)(p__DOT__decomp0__DOT____VdfgTmp_h805c9fc4__0)))))
                                       : ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0x6fU 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->p__DOT__w_ir_org 
                                                           << 8U)) 
                                                       | (0xff000U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->p__DOT__w_ir_org 
                                                                            >> 0xcU)))) 
                                                             << 0xbU))))))
                                           : ((2U & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                               ? ((1U 
                                                   & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                                   ? 
                                                  ((4U 
                                                    & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                      ? 
                                                     (0x807033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U))))
                                                      : 
                                                     (0x806033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U)))))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct2))
                                                      ? 
                                                     (0x804033U 
                                                      | ((0x700000U 
                                                          & (vlSelf->p__DOT__w_ir_org 
                                                             << 0x12U)) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U))))
                                                      : 
                                                     (0x40000033U 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                          << 0x14U) 
                                                         | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                             << 0xfU) 
                                                            | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                               << 7U)))))))
                                                   : 
                                                  (0x7013U 
                                                   | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0) 
                                                       << 0x14U) 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                          << 0xfU) 
                                                         | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                            << 7U)))))
                                               : ((1U 
                                                   & (IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_funct1))
                                                   ? 
                                                  (0x40000000U 
                                                   | ((0x3e000000U 
                                                       & ((- (IData)(
                                                                     (1U 
                                                                      & (vlSelf->p__DOT__w_ir_org 
                                                                         >> 0xcU)))) 
                                                          << 0x19U)) 
                                                      | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c1_shamt) 
                                                          << 0x14U) 
                                                         | p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0)))
                                                   : 
                                                  (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6af765de__0) 
                                                    << 0x14U) 
                                                   | p__DOT__decomp0__DOT____VdfgTmp_h63206ace__0)))))
                                   : ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                       ? ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? ((2U == 
                                               (0x1fU 
                                                & (vlSelf->p__DOT__w_ir_org 
                                                   >> 7U)))
                                               ? (0x10113U 
                                                  | (vlSelf->p__DOT__decomp0__DOT__w_c1_imm4 
                                                     << 0x14U))
                                               : (0x37U 
                                                  | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                      << 0xcU) 
                                                     | (0xf80U 
                                                        & vlSelf->p__DOT__w_ir_org))))
                                           : (0x13U 
                                              | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                  << 0x14U) 
                                                 | (0xf80U 
                                                    & vlSelf->p__DOT__w_ir_org))))
                                       : ((0x2000U 
                                           & vlSelf->p__DOT__w_ir_org)
                                           ? (0xefU 
                                              | ((0x80000000U 
                                                  & (vlSelf->p__DOT__w_ir_org 
                                                     << 0x13U)) 
                                                 | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h16bc65cd__0) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->p__DOT__w_ir_org 
                                                           << 8U)) 
                                                       | (0xff000U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & (vlSelf->p__DOT__w_ir_org 
                                                                            >> 0xcU)))) 
                                                             << 0xbU))))))
                                           : (0x13U 
                                              | ((vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm 
                                                  << 0x14U) 
                                                 | ((0xf8000U 
                                                     & (vlSelf->p__DOT__w_ir_org 
                                                        << 8U)) 
                                                    | (0xf80U 
                                                       & vlSelf->p__DOT__w_ir_org)))))));
    } else if ((0x8000U & vlSelf->p__DOT__w_ir_org)) {
        if ((0x4000U & vlSelf->p__DOT__w_ir_org)) {
            vlSelf->p__DOT__w_ir_t = ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x2027U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                            << 0x19U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                               << 0x14U) 
                                              | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                  << 0xfU) 
                                                 | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                    << 7U)))))
                                       : (0x2023U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                            << 0x19U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                               << 0x14U) 
                                              | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                  << 0xfU) 
                                                 | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                    << 7U))))));
        } else if ((0x2000U & vlSelf->p__DOT__w_ir_org)) {
            vlSelf->p__DOT__w_ir_t = (0x3027U | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h6ca8438a__0) 
                                                  << 0x19U) 
                                                 | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                                        << 0xfU) 
                                                       | ((IData)(p__DOT__decomp0__DOT____VdfgTmp_h2ed69c1e__0) 
                                                          << 7U)))));
        }
    } else {
        vlSelf->p__DOT__w_ir_t = ((0x4000U & vlSelf->p__DOT__w_ir_org)
                                   ? ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x2007U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U))))
                                       : (0x2003U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_h25e92702__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U)))))
                                   : ((0x2000U & vlSelf->p__DOT__w_ir_org)
                                       ? (0x3007U | 
                                          (((IData)(p__DOT__decomp0__DOT____VdfgTmp_hb55b7f53__0) 
                                            << 0x14U) 
                                           | (((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs1) 
                                               << 0xfU) 
                                              | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                 << 7U))))
                                       : (0x10013U 
                                          | (((IData)(p__DOT__decomp0__DOT____VdfgTmp_hc4954598__0) 
                                              << 0x14U) 
                                             | ((IData)(vlSelf->p__DOT__decomp0__DOT__w_c0_rs2) 
                                                << 7U)))));
    }
    vlSelf->p__DOT__ALU_IM__DOT__r_rslt = vlSelf->p__DOT__w_alu_im_rslt;
    vlSelf->p__DOT__w_sstatus_t2 = ((0xfffffeffU & vlSelf->p__DOT__w_sstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 8U));
    vlSelf->p__DOT__w_mstatus_t2 = ((0xffffe7ffU & vlSelf->p__DOT__w_mstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 0xbU));
    vlSelf->p__DOT__w_irq_t = (vlSelf->p__DOT__w_interrupt_mask 
                               & ((IData)(1U) + (~ vlSelf->p__DOT__w_interrupt_mask)));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_inst_r_oe;
    vlSelf->w_dram_wdata = ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                             ? vlSelf->mmu__DOT__w_pte_wdata
                             : vlSelf->mmu__DOT__w_mem_wdata);
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_r_oe;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_w_oe;
    vlSelf->mmu__DOT__w_tlb_hit = (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                    & (IData)(vlSelf->mmu__DOT__w_tlb_inst_r_oe)) 
                                   | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                       & (IData)(vlSelf->mmu__DOT__w_tlb_data_r_oe)) 
                                      | ((IData)(vlSelf->mmu__DOT__w_iswrite) 
                                         & (IData)(vlSelf->mmu__DOT__w_tlb_data_w_oe))));
    vlSelf->mmu__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->p__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->mmu__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->p__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->mmu__DOT__w_proc_busy = vlSelf->w_proc_busy;
    vlSelf->p__DOT__w_busy = vlSelf->w_proc_busy;
    vlSelf->p__DOT__w_if_state = ((1U & ((~ ((1U == (IData)(vlSelf->w_state)) 
                                             | (2U 
                                                == (IData)(vlSelf->w_state)))) 
                                         | (0xffffffffU 
                                            != vlSelf->w_pagefault)))
                                   ? 0U : (3U & (((0U 
                                                   == (IData)(vlSelf->p__DOT__r_if_state)) 
                                                  & ((~ (IData)(vlSelf->w_proc_busy)) 
                                                     & (IData)(vlSelf->p__DOT__w_nalign4)))
                                                  ? 
                                                 ((IData)(vlSelf->p__DOT__r_ir16_v)
                                                   ? 3U
                                                   : 1U)
                                                  : 
                                                 (((~ (IData)(vlSelf->w_proc_busy)) 
                                                   & (1U 
                                                      == (IData)(vlSelf->p__DOT__r_if_state)))
                                                   ? 2U
                                                   : 
                                                  (((~ (IData)(vlSelf->w_proc_busy)) 
                                                    & (2U 
                                                       == (IData)(vlSelf->p__DOT__r_if_state)))
                                                    ? 3U
                                                    : (IData)(vlSelf->p__DOT__r_if_state))))));
    vlSelf->p__DOT__w_state = ((1U & ((~ (IData)(vlSelf->CORE_RST_X)) 
                                      | (IData)(vlSelf->w_halt)))
                                ? 0U : ((IData)(vlSelf->p__DOT__w_com)
                                         ? 0xaU : (0xfU 
                                                   & ((((~ (IData)(vlSelf->p__DOT__w_ex1)) 
                                                        & (IData)(vlSelf->w_proc_busy)) 
                                                       | (IData)(vlSelf->p__DOT__w_ex1_busy))
                                                       ? (IData)(vlSelf->w_state)
                                                       : 
                                                      ((0xbU 
                                                        == (IData)(vlSelf->w_state))
                                                        ? 0U
                                                        : 
                                                       (((1U 
                                                          == (IData)(vlSelf->w_state)) 
                                                         & ((IData)(vlSelf->p__DOT__w_nalign4) 
                                                            & (3U 
                                                               != (IData)(vlSelf->p__DOT__r_if_state))))
                                                         ? 1U
                                                         : 
                                                        (((~ (IData)(vlSelf->p__DOT__r_op_AMO)) 
                                                          & ((~ (IData)(vlSelf->p__DOT__r_op_LOAD)) 
                                                             & ((~ (IData)(vlSelf->p__DOT__r_op_STORE)) 
                                                                & (IData)(vlSelf->p__DOT__w_ex1))))
                                                          ? 9U
                                                          : 
                                                         (((6U 
                                                            == (IData)(vlSelf->w_state)) 
                                                           & (IData)(vlSelf->p__DOT__r_op_STORE))
                                                           ? 8U
                                                           : 
                                                          (((6U 
                                                             == (IData)(vlSelf->w_state)) 
                                                            & (IData)(vlSelf->p__DOT__r_op_LOAD))
                                                            ? 9U
                                                            : 
                                                           ((IData)(1U) 
                                                            + (IData)(vlSelf->w_state)))))))))));
    if (((0xaU == (IData)(vlSelf->w_state)) & (~ (IData)(vlSelf->w_proc_busy)))) {
        if (((0xffffffffU != vlSelf->p__DOT__pending_exception) 
             | ((0U != vlSelf->p__DOT__w_interrupt_mask) 
                & (IData)(vlSelf->p__DOT__w_take_int)))) {
            vlSelf->p__DOT__r_tlb_flush = 1U;
        } else if (((IData)(vlSelf->p__DOT__r_op_SRET) 
                    | (IData)(vlSelf->p__DOT__r_op_MRET))) {
            vlSelf->p__DOT__r_tlb_flush = 1U;
        } else if (vlSelf->p__DOT__r_op_CSR_MSTA) {
            if (((0U != (0xe0000U & vlSelf->p__DOT__w_mod)) 
                 | ((0U != (0x20000U & vlSelf->p__DOT__mstatus)) 
                    & (0U != (0x1800U & vlSelf->p__DOT__w_mod))))) {
                vlSelf->p__DOT__r_tlb_flush = 1U;
            }
        } else if (vlSelf->p__DOT__r_op_CSR_SSTA) {
            if (((0U != (0xe0000U & vlSelf->p__DOT__w_mod)) 
                 | ((0U != (0x20000U & vlSelf->p__DOT__mstatus)) 
                    & (0U != (0x1800U & vlSelf->p__DOT__w_mod))))) {
                vlSelf->p__DOT__r_tlb_flush = 1U;
            }
        } else {
            vlSelf->p__DOT__r_tlb_flush = (((0x73U 
                                             == (IData)(vlSelf->p__DOT__r_opcode)) 
                                            & (0U == (IData)(vlSelf->p__DOT__r_funct3))) 
                                           & (9U == (IData)(vlSelf->p__DOT__r_funct7)));
        }
    } else {
        vlSelf->p__DOT__r_tlb_flush = 0U;
    }
    vlSelf->mmu__DOT__w_tlb_busy = vlSelf->w_tlb_busy;
    vlSelf->mmu__DOT__w_dram_we = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                   & ((IData)(vlSelf->p__DOT__r_data_we) 
                                      & ((8U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                         | (0U == (IData)(vlSelf->mmu__DOT__w_dev)))));
    mmu__DOT____VdfgTmp_h1f4b0050__0 = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                        & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->mmu__DOT__r_tlb_pte_addr = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                         ? vlSelf->mmu__DOT__L1_pte_addr
                                         : ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                             ? vlSelf->mmu__DOT__L0_pte_addr
                                             : ((5U 
                                                 == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                                 ? vlSelf->mmu__DOT__w_pte_waddr
                                                 : 0U)));
    if ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))) {
        vlSelf->w_dram_ctrl = vlSelf->mmu__DOT__w_mem_ctrl;
        vlSelf->w_dram_addr = vlSelf->mmu__DOT__w_mc_addr;
    } else if (mmu__DOT____VdfgTmp_h1f4b0050__0) {
        vlSelf->w_dram_ctrl = 2U;
        vlSelf->w_dram_addr = vlSelf->mmu__DOT__w_insn_paddr;
    } else {
        vlSelf->w_dram_ctrl = vlSelf->mmu__DOT__w_mem_ctrl;
        vlSelf->w_dram_addr = ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                ? vlSelf->p__DOT__r_mem_addr
                                : (((~ (IData)(vlSelf->mmu__DOT__w_tlb_hit)) 
                                    & (IData)(vlSelf->mmu__DOT__r_tlb_acs))
                                    ? vlSelf->mmu__DOT__r_tlb_pte_addr
                                    : vlSelf->w_mem_paddr));
    }
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X;
    vlSelf->p__DOT__decomp0__DOT__r_iw = vlSelf->p__DOT__w_ir_t;
    vlSelf->p__DOT__w_nop = ((0x53U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                             | ((7U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                                | (0x27U == (0x7fU 
                                             & vlSelf->p__DOT__w_ir_t))));
    vlSelf->p__DOT__w_sstatus_t3 = (0xfffffffdU & vlSelf->p__DOT__w_sstatus_t2);
    vlSelf->p__DOT__w_mstatus_t3 = (0xfffffff7U & vlSelf->p__DOT__w_mstatus_t2);
    vlSelf->mmu__DOT__w_dram_wdata = vlSelf->w_dram_wdata;
    vlSelf->p__DOT__w_d_en_t = ((6U == (IData)(vlSelf->p__DOT__w_state)) 
                                & ((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                   | (IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)));
    vlSelf->p__DOT__w_d_we_t = ((8U == (IData)(vlSelf->p__DOT__w_state)) 
                                & ((IData)(vlSelf->p__DOT__r_op_STORE) 
                                   | (((IData)(vlSelf->p__DOT__r_op_AMO) 
                                       & ((~ vlSelf->p__DOT__r_wb_data) 
                                          & (IData)(vlSelf->p__DOT__r_op_AMO_SC))) 
                                      | ((~ (IData)(vlSelf->p__DOT__r_op_AMO_LR)) 
                                         & (IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)))));
    vlSelf->w_tlb_flush = vlSelf->p__DOT__r_tlb_flush;
    vlSelf->w_dram_we_t = ((IData)(vlSelf->mmu__DOT__w_pte_we) 
                           | (IData)(vlSelf->mmu__DOT__w_dram_we));
    vlSelf->p__DOT__w_ir = ((IData)(vlSelf->p__DOT__w_nop)
                             ? 0x13U : ((IData)(vlSelf->p__DOT__w_cinsn)
                                         ? vlSelf->p__DOT__w_ir_t
                                         : vlSelf->p__DOT__w_ir_org));
    vlSelf->p__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_dram_we_t = vlSelf->w_dram_we_t;
    vlSelf->mmu__DOT__w_dram_ctrl = vlSelf->w_dram_ctrl;
    vlSelf->mmu__DOT__w_dram_addr = vlSelf->w_dram_addr;
    vlSelf->mmu__DOT__w_dram_aces = ((8U == (vlSelf->w_dram_addr 
                                             >> 0x1cU)) 
                                     | ((0U == (vlSelf->w_dram_addr 
                                                >> 0x1cU)) 
                                        | (9U == (vlSelf->w_dram_addr 
                                                  >> 0x1cU))));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->w_data_le = ((~ (IData)(vlSelf->w_tlb_busy)) 
                         & ((~ (IData)(vlSelf->mmu__DOT__w_dram_aces)) 
                            & (IData)(vlSelf->mmu__DOT__w_isread)));
    vlSelf->w_data_we = ((~ (IData)(vlSelf->w_tlb_busy)) 
                         & ((~ (IData)(vlSelf->mmu__DOT__w_dram_aces)) 
                            & ((IData)(vlSelf->mmu__DOT__w_iswrite) 
                               | (IData)(vlSelf->p__DOT__r_data_we))));
    vlSelf->w_dram_le = ((IData)(vlSelf->mmu__DOT__w_dram_aces) 
                         & ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))
                             ? ((0U == (IData)(vlSelf->mmu__DOT__w_mc_aces)) 
                                & (0U != (vlSelf->mmu__DOT__w_mc_addr 
                                          >> 0x1cU)))
                             : ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                 ? (IData)(mmu__DOT____VdfgTmp_hdc3ed8a3__0)
                                 : (((~ (IData)(vlSelf->w_tlb_busy)) 
                                     & (0U != (3U & 
                                               ((IData)(vlSelf->mmu__DOT__r_tlb_use) 
                                                >> 1U))))
                                     ? 1U : (((~ (IData)(vlSelf->mmu__DOT__w_tlb_hit)) 
                                              & ((IData)(vlSelf->w_tlb_busy) 
                                                 & ((0U 
                                                     == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                                    | (2U 
                                                       == (IData)(vlSelf->mmu__DOT__r_pw_state)))))
                                              ? 1U : 0U)))));
    vlSelf->mmu__DOT__w_data_le = vlSelf->w_data_le;
    vlSelf->mmu__DOT__w_data_we = vlSelf->w_data_we;
    vlSelf->mmu__DOT__w_dram_le = vlSelf->w_dram_le;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___ctor_var_reset(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___ctor_var_reset\n"); );
    // Body
    vlSelf->CLK = 0;
    vlSelf->RST_X = 0;
    vlSelf->w_hart_id = 0;
    vlSelf->w_grant = 0;
    vlSelf->w_ipi = 0;
    vlSelf->w_core_ir = 0;
    vlSelf->w_state = 0;
    vlSelf->w_mem_paddr = 0;
    vlSelf->w_data_we = 0;
    vlSelf->w_data_le = 0;
    vlSelf->w_data_busy = 0;
    vlSelf->w_data_wdata = 0;
    vlSelf->w_data_data = 0;
    vlSelf->w_mtime = 0;
    vlSelf->w_tlb_req = 0;
    vlSelf->w_tlb_busy = 0;
    vlSelf->w_mip = 0;
    vlSelf->w_wmip = 0;
    vlSelf->w_plic_we = 0;
    vlSelf->w_tx_ready = 0;
    vlSelf->w_dram_addr = 0;
    vlSelf->w_dram_wdata = 0;
    vlSelf->w_dram_odata = 0;
    vlSelf->w_dram_we_t = 0;
    vlSelf->w_dram_busy = 0;
    vlSelf->w_dram_ctrl = 0;
    vlSelf->w_dram_le = 0;
    vlSelf->w_init_done = 0;
    vlSelf->w_pc = 0;
    vlSelf->w_ir = 0;
    vlSelf->w_pc_stip = 0;
    vlSelf->w_reserved = 0;
    vlSelf->w_load_res = 0;
    vlSelf->w_hart_sc = 0;
    vlSelf->w_oh_reserved = 0;
    vlSelf->w_oh_load_res = 0;
    vlSelf->w_oh_sc = 0;
    vlSelf->w_oh_pc = 0;
    vlSelf->w_ipi_taken = 0;
    vlSelf->w_halt = 0;
    vlSelf->w_insn_data = 0;
    vlSelf->w_insn_addr = 0;
    vlSelf->w_data_addr = 0;
    vlSelf->w_data_ctrl = 0;
    vlSelf->w_proc_data_we = 0;
    vlSelf->w_mtimecmp = 0;
    vlSelf->w_wmtimecmp = 0;
    vlSelf->w_clint_we = 0;
    vlSelf->w_priv = 0;
    vlSelf->w_satp = 0;
    vlSelf->w_mstatus = 0;
    vlSelf->w_pagefault = 0;
    vlSelf->w_tlb_flush = 0;
    vlSelf->w_proc_busy = 0;
    vlSelf->CORE_RST_X = 0;
    vlSelf->mmu__DOT__CLK = 0;
    vlSelf->mmu__DOT__RST_X = 0;
    vlSelf->mmu__DOT__w_hart_id = 0;
    vlSelf->mmu__DOT__w_grant = 0;
    vlSelf->mmu__DOT__w_pc = 0;
    vlSelf->mmu__DOT__w_ir = 0;
    vlSelf->mmu__DOT__w_tx_ready = 0;
    vlSelf->mmu__DOT__w_insn_addr = 0;
    vlSelf->mmu__DOT__w_data_addr = 0;
    vlSelf->mmu__DOT__w_data_wdata = 0;
    vlSelf->mmu__DOT__w_proc_data_we = 0;
    vlSelf->mmu__DOT__w_data_we = 0;
    vlSelf->mmu__DOT__w_data_le = 0;
    vlSelf->mmu__DOT__w_data_busy = 0;
    vlSelf->mmu__DOT__w_data_ctrl = 0;
    vlSelf->mmu__DOT__w_insn_data = 0;
    vlSelf->mmu__DOT__w_priv = 0;
    vlSelf->mmu__DOT__w_satp = 0;
    vlSelf->mmu__DOT__w_mstatus = 0;
    vlSelf->mmu__DOT__w_pagefault = 0;
    vlSelf->mmu__DOT__w_tlb_req = 0;
    vlSelf->mmu__DOT__w_tlb_flush = 0;
    vlSelf->mmu__DOT__w_proc_busy = 0;
    vlSelf->mmu__DOT__w_mtimecmp = 0;
    vlSelf->mmu__DOT__w_wmtimecmp = 0;
    vlSelf->mmu__DOT__w_clint_we = 0;
    vlSelf->mmu__DOT__w_mem_paddr = 0;
    vlSelf->mmu__DOT__w_tlb_busy = 0;
    vlSelf->mmu__DOT__w_dram_addr = 0;
    vlSelf->mmu__DOT__w_dram_wdata = 0;
    vlSelf->mmu__DOT__w_dram_odata = 0;
    vlSelf->mmu__DOT__w_dram_we_t = 0;
    vlSelf->mmu__DOT__w_dram_busy = 0;
    vlSelf->mmu__DOT__w_dram_ctrl = 0;
    vlSelf->mmu__DOT__w_dram_le = 0;
    vlSelf->mmu__DOT__physical_addr = 0;
    vlSelf->mmu__DOT__page_walk_fail = 0;
    vlSelf->mmu__DOT__r_pw_state = 0;
    vlSelf->mmu__DOT__L1_pte = 0;
    vlSelf->mmu__DOT__L0_pte = 0;
    vlSelf->mmu__DOT__r_mc_mode = 0;
    vlSelf->mmu__DOT__w_mc_addr = 0;
    vlSelf->mmu__DOT__w_mc_wdata = 0;
    vlSelf->mmu__DOT__w_mc_we = 0;
    vlSelf->mmu__DOT__w_mc_ctrl = 0;
    vlSelf->mmu__DOT__w_mc_aces = 0;
    vlSelf->mmu__DOT__w_mem_wdata = 0;
    vlSelf->mmu__DOT__w_iscode = 0;
    vlSelf->mmu__DOT__w_isread = 0;
    vlSelf->mmu__DOT__w_iswrite = 0;
    vlSelf->mmu__DOT__v_addr = 0;
    vlSelf->mmu__DOT__vpn1 = 0;
    vlSelf->mmu__DOT__L1_pte_addr = 0;
    vlSelf->mmu__DOT__L1_xwr = 0;
    vlSelf->mmu__DOT__L1_paddr = 0;
    vlSelf->mmu__DOT__L1_p_addr = 0;
    vlSelf->mmu__DOT__L1_write = 0;
    vlSelf->mmu__DOT__L1_success = 0;
    vlSelf->mmu__DOT__vpn0 = 0;
    vlSelf->mmu__DOT__L0_pte_addr = 0;
    vlSelf->mmu__DOT__L0_xwr = 0;
    vlSelf->mmu__DOT__L0_paddr = 0;
    vlSelf->mmu__DOT__L0_p_addr = 0;
    vlSelf->mmu__DOT__L0_write = 0;
    vlSelf->mmu__DOT__L0_success = 0;
    vlSelf->mmu__DOT__L1_pte_write = 0;
    vlSelf->mmu__DOT__L0_pte_write = 0;
    vlSelf->mmu__DOT__w_pte_we = 0;
    vlSelf->mmu__DOT__w_pte_waddr = 0;
    vlSelf->mmu__DOT__w_pte_wdata = 0;
    vlSelf->mmu__DOT__r_tlb_addr = 0;
    vlSelf->mmu__DOT__r_tlb_use = 0;
    vlSelf->mmu__DOT__w_tlb_inst_r_addr = 0;
    vlSelf->mmu__DOT__w_tlb_data_r_addr = 0;
    vlSelf->mmu__DOT__w_tlb_data_w_addr = 0;
    vlSelf->mmu__DOT__w_tlb_inst_r_oe = 0;
    vlSelf->mmu__DOT__w_tlb_data_r_oe = 0;
    vlSelf->mmu__DOT__w_tlb_data_w_oe = 0;
    vlSelf->mmu__DOT__w_use_tlb = 0;
    vlSelf->mmu__DOT__w_tlb_hit = 0;
    vlSelf->mmu__DOT__r_dram_was_busy = 0;
    vlSelf->mmu__DOT__r_dram_took_cmd = 0;
    vlSelf->mmu__DOT__r_data_was_busy = 0;
    vlSelf->mmu__DOT__w_tlb_inst_r_we = 0;
    vlSelf->mmu__DOT__w_tlb_data_r_we = 0;
    vlSelf->mmu__DOT__w_tlb_data_w_we = 0;
    vlSelf->mmu__DOT__w_tlb_wdata = 0;
    vlSelf->mmu__DOT__r_tlb_pte_addr = 0;
    vlSelf->mmu__DOT__r_tlb_acs = 0;
    vlSelf->mmu__DOT__w_insn_paddr = 0;
    vlSelf->mmu__DOT__w_mem_ctrl = 0;
    vlSelf->mmu__DOT__w_dev = 0;
    vlSelf->mmu__DOT__w_virt = 0;
    vlSelf->mmu__DOT__w_offset = 0;
    vlSelf->mmu__DOT__w_dram_we = 0;
    vlSelf->mmu__DOT__w_dram_aces = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__CLK = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__RST_X = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_flush = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_we = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_waddr = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_raddr = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_idata = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_odata = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_oe = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[__Vi0] = 0;
    }
    vlSelf->mmu__DOT__TLB_inst_r__DOT__i = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_widx = 0;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_wtag = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__CLK = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__RST_X = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_flush = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_we = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_waddr = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_raddr = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_idata = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_odata = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_oe = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mmu__DOT__TLB_data_r__DOT__mem[__Vi0] = 0;
    }
    vlSelf->mmu__DOT__TLB_data_r__DOT__i = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_widx = 0;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_wtag = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__CLK = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__RST_X = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_flush = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_we = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_waddr = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_raddr = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_idata = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_odata = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_oe = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mmu__DOT__TLB_data_w__DOT__mem[__Vi0] = 0;
    }
    vlSelf->mmu__DOT__TLB_data_w__DOT__i = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_ridx = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_rtag = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_widx = 0;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_wtag = 0;
    vlSelf->p__DOT__CLK = 0;
    vlSelf->p__DOT__RST_X = 0;
    vlSelf->p__DOT__w_stall = 0;
    vlSelf->p__DOT__w_hart_id = 0;
    vlSelf->p__DOT__w_ipi = 0;
    vlSelf->p__DOT__r_halt = 0;
    vlSelf->p__DOT__w_insn_addr = 0;
    vlSelf->p__DOT__w_data_addr = 0;
    vlSelf->p__DOT__w_insn_data = 0;
    vlSelf->p__DOT__w_data_data = 0;
    vlSelf->p__DOT__w_data_wdata = 0;
    vlSelf->p__DOT__w_data_we = 0;
    vlSelf->p__DOT__w_data_ctrl = 0;
    vlSelf->p__DOT__w_priv = 0;
    vlSelf->p__DOT__w_satp = 0;
    vlSelf->p__DOT__w_mstatus = 0;
    vlSelf->p__DOT__w_mtime = 0;
    vlSelf->p__DOT__w_mtimecmp = 0;
    vlSelf->p__DOT__w_wmtimecmp = 0;
    vlSelf->p__DOT__w_clint_we = 0;
    vlSelf->p__DOT__w_mip = 0;
    vlSelf->p__DOT__w_wmip = 0;
    vlSelf->p__DOT__w_plic_we = 0;
    vlSelf->p__DOT__w_busy = 0;
    vlSelf->p__DOT__w_pagefault = 0;
    vlSelf->p__DOT__w_tlb_req = 0;
    vlSelf->p__DOT__w_tlb_flush = 0;
    vlSelf->p__DOT__w_core_pc = 0;
    vlSelf->p__DOT__w_core_ir = 0;
    vlSelf->p__DOT__w_core_odata = 0;
    vlSelf->p__DOT__w_init_stage = 0;
    vlSelf->p__DOT__state = 0;
    vlSelf->p__DOT__pc = 0;
    vlSelf->p__DOT__r_ir = 0;
    vlSelf->p__DOT__pc_stip = 0;
    vlSelf->p__DOT__reserved = 0;
    vlSelf->p__DOT__load_res = 0;
    vlSelf->p__DOT__hart_sc = 0;
    vlSelf->p__DOT__w_oh_reserved = 0;
    vlSelf->p__DOT__w_oh_load_res = 0;
    vlSelf->p__DOT__w_oh_sc = 0;
    vlSelf->p__DOT__w_oh_pc = 0;
    vlSelf->p__DOT__w_grant = 0;
    vlSelf->p__DOT__r_ipi_taken = 0;
    vlSelf->p__DOT__mstatus = 0;
    vlSelf->p__DOT__mtvec = 0;
    vlSelf->p__DOT__mscratch = 0;
    vlSelf->p__DOT__mepc = 0;
    vlSelf->p__DOT__mcause = 0;
    vlSelf->p__DOT__mtval = 0;
    vlSelf->p__DOT__mhartid = 0;
    vlSelf->p__DOT__misa = 0;
    vlSelf->p__DOT__mie = 0;
    vlSelf->p__DOT__mip = 0;
    vlSelf->p__DOT__medeleg = 0;
    vlSelf->p__DOT__mideleg = 0;
    vlSelf->p__DOT__mcounteren = 0;
    vlSelf->p__DOT__stvec = 0;
    vlSelf->p__DOT__sscratch = 0;
    vlSelf->p__DOT__sepc = 0;
    vlSelf->p__DOT__scause = 0;
    vlSelf->p__DOT__stval = 0;
    vlSelf->p__DOT__satp = 0;
    vlSelf->p__DOT__scounteren = 0;
    vlSelf->p__DOT__priv = 0;
    vlSelf->p__DOT__mtimecmp = 0;
    vlSelf->p__DOT__r_was_clint_we = 0;
    vlSelf->p__DOT__pending_tval = 0;
    vlSelf->p__DOT__pending_exception = 0;
    vlSelf->p__DOT__r_cpc = 0;
    vlSelf->p__DOT__r_ir_org = 0;
    vlSelf->p__DOT__r_cinsn = 0;
    vlSelf->p__DOT__r_ir16 = 0;
    vlSelf->p__DOT__r_ir16_v = 0;
    vlSelf->p__DOT__r_opcode = 0;
    vlSelf->p__DOT__r_rd = 0;
    vlSelf->p__DOT__r_rs1 = 0;
    vlSelf->p__DOT__r_rs2 = 0;
    vlSelf->p__DOT__r_funct3 = 0;
    vlSelf->p__DOT__r_funct5 = 0;
    vlSelf->p__DOT__r_funct7 = 0;
    vlSelf->p__DOT__r_funct12 = 0;
    vlSelf->p__DOT__r_imm = 0;
    vlSelf->p__DOT__r_op_AMO_SC = 0;
    vlSelf->p__DOT__r_op_AMO_LR = 0;
    vlSelf->p__DOT__r_op_LOAD = 0;
    vlSelf->p__DOT__r_op_STORE = 0;
    vlSelf->p__DOT__r_op_AMO = 0;
    vlSelf->p__DOT__r_op_SYS = 0;
    vlSelf->p__DOT__r_op_ECALL = 0;
    vlSelf->p__DOT__r_op_SRET = 0;
    vlSelf->p__DOT__r_op_MRET = 0;
    vlSelf->p__DOT__r_op_CSR_MSTA = 0;
    vlSelf->p__DOT__r_op_CSR_SSTA = 0;
    vlSelf->p__DOT__r_rrs1 = 0;
    vlSelf->p__DOT__r_rrs2 = 0;
    vlSelf->p__DOT__r_rcsr = 0;
    vlSelf->p__DOT__r_alu_in2 = 0;
    vlSelf->p__DOT__r_alu_f7 = 0;
    vlSelf->p__DOT__r_tkn = 0;
    vlSelf->p__DOT__r_jmp_pc = 0;
    vlSelf->p__DOT__r_mem_addr = 0;
    vlSelf->p__DOT__r_wb_data = 0;
    vlSelf->p__DOT__r_wb_data_csr = 0;
    vlSelf->p__DOT__r_mem_rdata = 0;
    vlSelf->p__DOT__r_atom_wdata = 0;
    vlSelf->p__DOT__e_icount = 0;
    vlSelf->p__DOT__r_if_done = 0;
    vlSelf->p__DOT__r_if_irl = 0;
    vlSelf->p__DOT__r_rcsr_t = 0;
    vlSelf->p__DOT__irq_num = 0;
    vlSelf->p__DOT__r_if_state = 0;
    vlSelf->p__DOT__w_wb_r_data = 0;
    vlSelf->p__DOT__w_wb_r_enable = 0;
    vlSelf->p__DOT__w_interrupt_mask = 0;
    vlSelf->p__DOT__w_irq_t = 0;
    vlSelf->p__DOT__w_state = 0;
    vlSelf->p__DOT__r_init_stage = 0;
    vlSelf->p__DOT__w_vadr1 = 0;
    vlSelf->p__DOT__w_vadr2 = 0;
    vlSelf->p__DOT__w_nalign4 = 0;
    vlSelf->p__DOT__w_usestate = 0;
    vlSelf->p__DOT__w_if_state = 0;
    vlSelf->p__DOT__r_insn_addr = 0;
    vlSelf->p__DOT__w_ir_org = 0;
    vlSelf->p__DOT__w_cinsn = 0;
    vlSelf->p__DOT__w_ir_t = 0;
    vlSelf->p__DOT__w_nop = 0;
    vlSelf->p__DOT__w_ir = 0;
    vlSelf->p__DOT__w_imm = 0;
    vlSelf->p__DOT__w_rs1 = 0;
    vlSelf->p__DOT__w_rs2 = 0;
    vlSelf->p__DOT__w_rrs1 = 0;
    vlSelf->p__DOT__w_rrs2 = 0;
    vlSelf->p__DOT__w_regfile_we = 0;
    vlSelf->p__DOT__w_op_priv = 0;
    vlSelf->p__DOT__w_op_csr = 0;
    vlSelf->p__DOT__w_sin1 = 0;
    vlSelf->p__DOT__w_sin2 = 0;
    vlSelf->p__DOT__w_mul_SS = 0;
    vlSelf->p__DOT__w_mul_SU = 0;
    vlSelf->p__DOT__w_mul_UU = 0;
    vlSelf->p__DOT__w_mem_addr = 0;
    vlSelf->p__DOT__r_mul_SS = 0;
    vlSelf->p__DOT__r_mul_SU = 0;
    vlSelf->p__DOT__r_mul_UU = 0;
    vlSelf->p__DOT__w_alu_im_rslt = 0;
    vlSelf->p__DOT__w_alu_b_rslt = 0;
    vlSelf->p__DOT__w_alu_c_rslt = 0;
    vlSelf->p__DOT__w_ex1 = 0;
    vlSelf->p__DOT__w_ex1_busy = 0;
    vlSelf->p__DOT__r_data_ctrl = 0;
    vlSelf->p__DOT__w_mem_rdata = 0;
    vlSelf->p__DOT__r_lrpc = 0;
    vlSelf->p__DOT__r_lrmtime = 0;
    vlSelf->p__DOT__w_alu_a_rslt = 0;
    vlSelf->p__DOT__r_data_wdata = 0;
    vlSelf->p__DOT__r_mstatus_t = 0;
    vlSelf->p__DOT__r_priv_t = 0;
    vlSelf->p__DOT__w_mstatus_nxt = 0;
    vlSelf->p__DOT__pending_interrupts = 0;
    vlSelf->p__DOT__enable_interrupts = 0;
    vlSelf->p__DOT__cause = 0;
    vlSelf->p__DOT__w_deleg = 0;
    vlSelf->p__DOT__w_executing_wfi = 0;
    vlSelf->p__DOT__w_exit_wfi = 0;
    vlSelf->p__DOT__w_csr_addr = 0;
    vlSelf->p__DOT__w_sstatus_t = 0;
    vlSelf->p__DOT__w_mstatus_t = 0;
    vlSelf->p__DOT__w_csr_we = 0;
    vlSelf->p__DOT__w_sstatus = 0;
    vlSelf->p__DOT__w_sstatus_t1 = 0;
    vlSelf->p__DOT__w_sstatus_t2 = 0;
    vlSelf->p__DOT__w_sstatus_t3 = 0;
    vlSelf->p__DOT__w_mstatus_t1 = 0;
    vlSelf->p__DOT__w_mstatus_t2 = 0;
    vlSelf->p__DOT__w_mstatus_t3 = 0;
    vlSelf->p__DOT__laurpc = 0;
    vlSelf->p__DOT__f = 0;
    vlSelf->p__DOT__closed = 0;
    vlSelf->p__DOT__w_take_int = 0;
    vlSelf->p__DOT__r_ipi_max_displays = 0;
    vlSelf->p__DOT__rim = 0;
    vlSelf->p__DOT__r_tlb_flush = 0;
    vlSelf->p__DOT__w_data_t = 0;
    vlSelf->p__DOT__w_mod = 0;
    vlSelf->p__DOT__w_com = 0;
    vlSelf->p__DOT__r_com = 0;
    vlSelf->p__DOT__w_d_we_t = 0;
    vlSelf->p__DOT__w_d_en_t = 0;
    vlSelf->p__DOT__r_data_we = 0;
    vlSelf->p__DOT__r_data_en = 0;
    vlSelf->p__DOT__r_tlb_req = 0;
    vlSelf->p__DOT____VdfgTmp_h8573667a__0 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_ic = 0;
    vlSelf->p__DOT__decomp0__DOT__r_iw = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_rs2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_rd = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_uimm2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c0_nzuimm = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_funct2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rs2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_rd = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_nzimm = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_shamt = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm3 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c1_imm4 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_rs2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_rd = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm1 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm2 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm3 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_uimm4 = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_nzuimm = 0;
    vlSelf->p__DOT__decomp0__DOT__w_c2_shamt = 0;
    vlSelf->p__DOT__imm_gen0__DOT__w_inst = 0;
    vlSelf->p__DOT__imm_gen0__DOT__r_imm = 0;
    vlSelf->p__DOT__imm_gen0__DOT__opcode = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_I = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_S = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_B = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_U = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_J = 0;
    vlSelf->p__DOT__imm_gen0__DOT__imm_C = 0;
    vlSelf->p__DOT__regs__DOT__CLK = 0;
    vlSelf->p__DOT__regs__DOT__w_rs1 = 0;
    vlSelf->p__DOT__regs__DOT__w_rs2 = 0;
    vlSelf->p__DOT__regs__DOT__w_rdata1 = 0;
    vlSelf->p__DOT__regs__DOT__w_rdata2 = 0;
    vlSelf->p__DOT__regs__DOT__w_we = 0;
    vlSelf->p__DOT__regs__DOT__rd = 0;
    vlSelf->p__DOT__regs__DOT__w_wdata = 0;
    vlSelf->p__DOT__regs__DOT__w_hart_id = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->p__DOT__regs__DOT__mem[__Vi0] = 0;
    }
    vlSelf->p__DOT__regs__DOT__i = 0;
    vlSelf->p__DOT__ALU_IM__DOT__CLK = 0;
    vlSelf->p__DOT__ALU_IM__DOT__RST_X = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_le = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_in1 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_in2 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct3 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_funct7 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__r_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_busy = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SS = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SU = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_UU = 0;
    vlSelf->p__DOT__ALU_IM__DOT__r_div_first = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_sin1 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_sin2 = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_shamt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_req = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_init = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_signed = 0;
    vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_signed = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_dividend = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_divisor = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__CLK = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__RST_X = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_init = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_dividend = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_divisor = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_rslt = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_busy = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count = 0;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ = 0;
    vlSelf->p__DOT__ALU_B__DOT__w_in1 = 0;
    vlSelf->p__DOT__ALU_B__DOT__w_in2 = 0;
    vlSelf->p__DOT__ALU_B__DOT__w_funct3 = 0;
    vlSelf->p__DOT__ALU_B__DOT__r_rslt = 0;
    vlSelf->p__DOT__ALU_B__DOT__w_sin1 = 0;
    vlSelf->p__DOT__ALU_B__DOT__w_sin2 = 0;
    vlSelf->p__DOT__ALU_C__DOT__w_rcsr = 0;
    vlSelf->p__DOT__ALU_C__DOT__w_rrs1 = 0;
    vlSelf->p__DOT__ALU_C__DOT__w_imm = 0;
    vlSelf->p__DOT__ALU_C__DOT__w_funct3 = 0;
    vlSelf->p__DOT__ALU_C__DOT__r_rslt = 0;
    vlSelf->p__DOT__ALU_A__DOT__w_in1 = 0;
    vlSelf->p__DOT__ALU_A__DOT__w_in2 = 0;
    vlSelf->p__DOT__ALU_A__DOT__w_funct5 = 0;
    vlSelf->p__DOT__ALU_A__DOT__r_rslt = 0;
    vlSelf->p__DOT__ALU_A__DOT__w_sin1 = 0;
    vlSelf->p__DOT__ALU_A__DOT__w_sin2 = 0;
}
