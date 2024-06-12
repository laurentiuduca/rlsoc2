// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim_m_cpummu.h"

VL_INLINE_OPT void Vm_topsim_m_cpummu___ico_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___ico_sequent__TOP__m_topsim__DOT__core0__0\n"); );
    // Body
    vlSelf->mmu__DOT__RST_X = vlSelf->RST_X;
    vlSelf->CORE_RST_X = ((IData)(vlSelf->RST_X) & (IData)(vlSelf->w_init_done));
    vlSelf->mmu__DOT__CLK = vlSelf->CLK;
    vlSelf->p__DOT__CLK = vlSelf->CLK;
    vlSelf->p__DOT__RST_X = vlSelf->CORE_RST_X;
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
    vlSelf->mmu__DOT__TLB_inst_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_r__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->mmu__DOT__TLB_data_w__DOT__CLK = vlSelf->mmu__DOT__CLK;
    vlSelf->p__DOT__regs__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__CLK = vlSelf->p__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__RST_X = vlSelf->p__DOT__RST_X;
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
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__RST_X;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__CLK 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__CLK;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__RST_X 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__RST_X;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__0\n"); );
    // Body
    vlSelf->p__DOT__w_data_data = vlSelf->w_data_data;
    vlSelf->mmu__DOT__w_tx_ready = vlSelf->w_tx_ready;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__1(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__1\n"); );
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
    CData/*1:0*/ p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0;
    CData/*0:0*/ p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0;
    CData/*3:0*/ __Vdly__mmu__DOT__r_pw_state;
    CData/*0:0*/ __Vdly__mmu__DOT__r_dram_was_busy;
    IData/*31:0*/ __Vdly__mmu__DOT__L1_pte;
    IData/*31:0*/ __Vdly__mmu__DOT__L0_pte;
    CData/*0:0*/ __Vdly__mmu__DOT__page_walk_fail;
    CData/*0:0*/ __Vdly__mmu__DOT__r_dram_took_cmd;
    CData/*0:0*/ __Vdly__mmu__DOT__r_data_was_busy;
    CData/*1:0*/ __Vdlyvdim0__mmu__DOT__TLB_inst_r__DOT__mem__v0;
    QData/*39:0*/ __Vdlyvval__mmu__DOT__TLB_inst_r__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__mmu__DOT__TLB_inst_r__DOT__mem__v0;
    CData/*1:0*/ __Vdlyvdim0__mmu__DOT__TLB_data_r__DOT__mem__v0;
    QData/*39:0*/ __Vdlyvval__mmu__DOT__TLB_data_r__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__mmu__DOT__TLB_data_r__DOT__mem__v0;
    CData/*1:0*/ __Vdlyvdim0__mmu__DOT__TLB_data_w__DOT__mem__v0;
    QData/*39:0*/ __Vdlyvval__mmu__DOT__TLB_data_w__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__mmu__DOT__TLB_data_w__DOT__mem__v0;
    CData/*0:0*/ __Vdly__w_reserved;
    IData/*31:0*/ __Vdly__w_load_res;
    IData/*31:0*/ __Vdly__w_pc;
    IData/*31:0*/ __Vdly__p__DOT__mip;
    IData/*31:0*/ __Vdly__p__DOT__r_ipi_max_displays;
    CData/*3:0*/ __Vdly__p__DOT__r_was_clint_we;
    QData/*63:0*/ __Vdly__p__DOT__mtimecmp;
    IData/*31:0*/ __Vdly__p__DOT__mstatus;
    CData/*1:0*/ __Vdly__p__DOT__priv;
    IData/*31:0*/ __Vdly__p__DOT__stvec;
    IData/*31:0*/ __Vdly__p__DOT__mtvec;
    IData/*31:0*/ __Vdly__p__DOT__mie;
    CData/*4:0*/ __Vdlyvdim0__p__DOT__regs__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__p__DOT__regs__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__p__DOT__regs__DOT__mem__v0;
    // Body
    if (VL_UNLIKELY((0U != (0x111U & (vlSelf->p__DOT__mip 
                                      & vlSelf->p__DOT__mie))))) {
        VL_WRITEF("(mip & mie & (`MIP_UEIP | `MIP_UTIP | `MIP_USIP))\n");
        VL_FINISH_MT("rvcorem.v", 550, "");
    }
    __Vdlyvset__mmu__DOT__TLB_inst_r__DOT__mem__v0 = 0U;
    __Vdlyvset__mmu__DOT__TLB_data_w__DOT__mem__v0 = 0U;
    __Vdlyvset__mmu__DOT__TLB_data_r__DOT__mem__v0 = 0U;
    __Vdlyvset__p__DOT__regs__DOT__mem__v0 = 0U;
    if (VL_UNLIKELY(vlSelf->w_halt)) {
        VL_WRITEF("HALT detect! at PC:%x\n",32,vlSelf->w_pc);
        VL_FINISH_MT("cpummu.v", 163, "");
    }
    __Vdly__mmu__DOT__r_data_was_busy = vlSelf->mmu__DOT__r_data_was_busy;
    __Vdly__mmu__DOT__r_dram_took_cmd = vlSelf->mmu__DOT__r_dram_took_cmd;
    __Vdly__mmu__DOT__r_dram_was_busy = vlSelf->mmu__DOT__r_dram_was_busy;
    __Vdly__mmu__DOT__page_walk_fail = vlSelf->mmu__DOT__page_walk_fail;
    __Vdly__mmu__DOT__L0_pte = vlSelf->mmu__DOT__L0_pte;
    __Vdly__mmu__DOT__r_pw_state = vlSelf->mmu__DOT__r_pw_state;
    __Vdly__mmu__DOT__L1_pte = vlSelf->mmu__DOT__L1_pte;
    if ((((IData)(vlSelf->p__DOT__w_ex1) & (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req)) 
         & (~ (IData)(vlSelf->p__DOT__w_ex1_busy)))) {
        if (((4U == (IData)(vlSelf->p__DOT__r_funct3)) 
             | (5U == (IData)(vlSelf->p__DOT__r_funct3)))) {
            if (VL_UNLIKELY((vlSelf->p__DOT__w_alu_im_rslt 
                             != (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt)))) {
                VL_WRITEF("CAUTION! DIV FAIL! %x/%x true:%x unit:%x %x\n",
                          32,vlSelf->p__DOT__r_rrs1,
                          32,vlSelf->p__DOT__r_alu_in2,
                          32,vlSelf->p__DOT__w_alu_im_rslt,
                          32,(IData)((vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                      >> 0x20U)),32,
                          (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt));
                VL_FINISH_MT("rvcorem.v", 1155, "");
            }
        }
        if (((6U == (IData)(vlSelf->p__DOT__r_funct3)) 
             | (7U == (IData)(vlSelf->p__DOT__r_funct3)))) {
            if (VL_UNLIKELY((vlSelf->p__DOT__w_alu_im_rslt 
                             != (IData)((vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                         >> 0x20U))))) {
                VL_WRITEF("CAUTION! REM FAIL! %x/%x true:%x unit:%x %x\n",
                          32,vlSelf->p__DOT__r_rrs1,
                          32,vlSelf->p__DOT__r_alu_in2,
                          32,vlSelf->p__DOT__w_alu_im_rslt,
                          32,(IData)((vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt 
                                      >> 0x20U)),32,
                          (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_rslt));
                VL_FINISH_MT("rvcorem.v", 1166, "");
            }
        }
    }
    __Vdly__w_load_res = vlSelf->w_load_res;
    __Vdly__w_reserved = vlSelf->w_reserved;
    __Vdly__w_pc = vlSelf->w_pc;
    __Vdly__p__DOT__r_was_clint_we = vlSelf->p__DOT__r_was_clint_we;
    __Vdly__p__DOT__r_ipi_max_displays = vlSelf->p__DOT__r_ipi_max_displays;
    __Vdly__p__DOT__mtvec = vlSelf->p__DOT__mtvec;
    __Vdly__p__DOT__stvec = vlSelf->p__DOT__stvec;
    __Vdly__p__DOT__mtimecmp = vlSelf->p__DOT__mtimecmp;
    __Vdly__p__DOT__mie = vlSelf->p__DOT__mie;
    __Vdly__p__DOT__mip = vlSelf->p__DOT__mip;
    __Vdly__p__DOT__priv = vlSelf->p__DOT__priv;
    __Vdly__p__DOT__mstatus = vlSelf->p__DOT__mstatus;
    if (vlSelf->CORE_RST_X) {
        if (vlSelf->p__DOT__ALU_IM__DOT__w_div_init) {
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor 
                = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_divisor;
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                = (QData)((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_dividend));
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count = 0U;
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend 
                = (vlSelf->p__DOT__r_rrs1 >> 0x1fU);
        } else {
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor 
                = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor;
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                = ((1U & (IData)((vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ 
                                  >> 0x20U))) ? (vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                                                 << 1U)
                    : (((QData)((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ)) 
                        << 0x20U) | (QData)((IData)(
                                                    (1U 
                                                     | ((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt) 
                                                        << 1U))))));
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count)));
            vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend 
                = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend;
        }
    } else {
        vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor = 0U;
        vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt = 0ULL;
        vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count = 0U;
        vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend = 0U;
    }
    if (vlSelf->p__DOT__w_regfile_we) {
        if ((0U != (IData)(vlSelf->p__DOT__r_rd))) {
            __Vdlyvval__p__DOT__regs__DOT__mem__v0 
                = vlSelf->p__DOT__w_wb_r_data;
            __Vdlyvset__p__DOT__regs__DOT__mem__v0 = 1U;
            __Vdlyvdim0__p__DOT__regs__DOT__mem__v0 
                = vlSelf->p__DOT__r_rd;
        }
    }
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor 
        = ((IData)(vlSelf->CORE_RST_X) & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_init)
                                           ? (vlSelf->p__DOT__r_alu_in2 
                                              >> 0x1fU)
                                           : (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor)));
    if (vlSelf->mmu__DOT__w_tlb_inst_r_we) {
        __Vdlyvval__mmu__DOT__TLB_inst_r__DOT__mem__v0 
            = (((QData)((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag)) 
                << 0x16U) | (QData)((IData)(vlSelf->mmu__DOT__w_tlb_wdata)));
        __Vdlyvset__mmu__DOT__TLB_inst_r__DOT__mem__v0 = 1U;
        __Vdlyvdim0__mmu__DOT__TLB_inst_r__DOT__mem__v0 
            = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx;
    }
    if (vlSelf->mmu__DOT__w_tlb_data_w_we) {
        __Vdlyvval__mmu__DOT__TLB_data_w__DOT__mem__v0 
            = (((QData)((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag)) 
                << 0x16U) | (QData)((IData)(vlSelf->mmu__DOT__w_tlb_wdata)));
        __Vdlyvset__mmu__DOT__TLB_data_w__DOT__mem__v0 = 1U;
        __Vdlyvdim0__mmu__DOT__TLB_data_w__DOT__mem__v0 
            = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    }
    if (vlSelf->mmu__DOT__w_tlb_data_r_we) {
        __Vdlyvval__mmu__DOT__TLB_data_r__DOT__mem__v0 
            = (((QData)((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag)) 
                << 0x16U) | (QData)((IData)(vlSelf->mmu__DOT__w_tlb_wdata)));
        __Vdlyvset__mmu__DOT__TLB_data_r__DOT__mem__v0 = 1U;
        __Vdlyvdim0__mmu__DOT__TLB_data_r__DOT__mem__v0 
            = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->w_reserved) 
                       & (vlSelf->w_oh_load_res == vlSelf->w_load_res)) 
                      & (IData)(vlSelf->w_oh_sc)) & (IData)(vlSelf->w_oh_reserved)))) {
        VL_WRITEF("-------- %0#: reserved disabled for mhartid=%1x pc=%x lrpc=%x oh_pc=%x load_res=%x lrmtime=%x\n",
                  64,vlSelf->w_mtime,32,vlSelf->p__DOT__mhartid,
                  32,vlSelf->w_pc,32,vlSelf->p__DOT__r_lrpc,
                  32,vlSelf->w_oh_pc,32,vlSelf->w_load_res,
                  32,vlSelf->p__DOT__r_lrmtime);
        __Vdly__w_reserved = 0U;
    } else if (((9U == (IData)(vlSelf->w_state)) & 
                ((IData)(vlSelf->p__DOT__r_op_AMO) 
                 & (IData)(vlSelf->p__DOT__r_op_AMO_LR)))) {
        __Vdly__w_load_res = vlSelf->p__DOT__r_mem_addr;
        __Vdly__w_reserved = 1U;
        vlSelf->p__DOT__r_lrpc = vlSelf->w_pc;
        vlSelf->p__DOT__r_lrmtime = (IData)(vlSelf->w_mtime);
    } else if ((((9U == (IData)(vlSelf->w_state)) & (IData)(vlSelf->p__DOT__r_op_AMO)) 
                & (IData)(vlSelf->p__DOT__r_op_AMO_SC))) {
        __Vdly__w_reserved = 0U;
    }
    vlSelf->p__DOT__r_data_en = vlSelf->p__DOT__w_d_en_t;
    vlSelf->p__DOT__r_init_stage = (0U == (IData)(vlSelf->p__DOT__w_state));
    vlSelf->p__DOT__r_data_we = vlSelf->p__DOT__w_d_we_t;
    if (vlSelf->p__DOT__ALU_IM__DOT__w_div_init) {
        vlSelf->p__DOT__ALU_IM__DOT__r_div_first = 0U;
    } else if ((1U & (~ (IData)(vlSelf->p__DOT__w_ex1)))) {
        vlSelf->p__DOT__ALU_IM__DOT__r_div_first = 1U;
    }
    if (vlSelf->w_tlb_flush) {
        vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid = 0U;
        vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid = 0U;
        vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid = 0U;
    }
    if (vlSelf->mmu__DOT__w_tlb_data_r_we) {
        vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid 
            = ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid) 
               | (0xfU & ((IData)(1U) << (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx))));
    }
    if (vlSelf->mmu__DOT__w_tlb_data_w_we) {
        vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid 
            = ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid) 
               | (0xfU & ((IData)(1U) << (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx))));
    }
    if (vlSelf->mmu__DOT__w_tlb_inst_r_we) {
        vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid 
            = ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid) 
               | (0xfU & ((IData)(1U) << (IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx))));
    }
    if ((7U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_atom_wdata = vlSelf->p__DOT__w_alu_a_rslt;
        vlSelf->p__DOT__r_mem_rdata = vlSelf->p__DOT__w_mem_rdata;
    }
    if ((6U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_data_wdata = vlSelf->p__DOT__r_rrs2;
    } else if ((7U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_data_wdata = vlSelf->p__DOT__w_alu_a_rslt;
    }
    vlSelf->p__DOT__r_tlb_req = (((1U == (IData)(vlSelf->p__DOT__w_state)) 
                                  & (1U != (IData)(vlSelf->p__DOT__w_if_state)))
                                  ? 2U : ((IData)(vlSelf->p__DOT__w_d_en_t)
                                           ? 0U : ((IData)(vlSelf->p__DOT__w_d_we_t)
                                                    ? 1U
                                                    : 3U)));
    vlSelf->p__DOT__r_data_ctrl = ((IData)(vlSelf->p__DOT__r_op_AMO)
                                    ? 2U : (IData)(vlSelf->p__DOT__r_funct3));
    if ((((1U == (IData)(vlSelf->w_state)) & (1U == (IData)(vlSelf->p__DOT__r_if_state))) 
         & (~ (IData)(vlSelf->w_proc_busy)))) {
        vlSelf->p__DOT__r_if_irl = (vlSelf->w_insn_data 
                                    >> 0x10U);
    }
    if (((0xbU == (IData)(vlSelf->w_state)) & (~ (IData)(vlSelf->w_proc_busy)))) {
        if ((((0xffffffffU == vlSelf->p__DOT__pending_exception) 
              | ((0xffffffffU != vlSelf->p__DOT__pending_exception) 
                 & (0U != (0x80000000U & vlSelf->p__DOT__pending_exception)))) 
             | ((0xffffffffU != vlSelf->p__DOT__pending_exception) 
                & (IData)(vlSelf->p__DOT__r_op_ECALL)))) {
            vlSelf->p__DOT__e_icount = (1ULL + vlSelf->p__DOT__e_icount);
        }
    }
    if ((2U == (IData)(vlSelf->w_state))) {
        if ((1U & (~ (IData)(vlSelf->w_proc_busy)))) {
            vlSelf->p__DOT__r_ir16 = (vlSelf->p__DOT__w_ir_org 
                                      >> 0x10U);
        }
    }
    if ((3U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_rs1 = (0x1fU & (vlSelf->w_ir 
                                          >> 0xfU));
        vlSelf->p__DOT__r_rs2 = (0x1fU & (vlSelf->w_ir 
                                          >> 0x14U));
        vlSelf->p__DOT__r_funct5 = (vlSelf->w_ir >> 0x1bU);
        vlSelf->p__DOT__r_op_CSR_MSTA = ((IData)(vlSelf->p__DOT__w_op_csr) 
                                         & (0x300U 
                                            == (vlSelf->w_ir 
                                                >> 0x14U)));
        vlSelf->p__DOT__r_op_CSR_SSTA = ((IData)(vlSelf->p__DOT__w_op_csr) 
                                         & (0x100U 
                                            == (vlSelf->w_ir 
                                                >> 0x14U)));
        vlSelf->p__DOT__r_op_MRET = ((IData)(vlSelf->p__DOT__w_op_priv) 
                                     & (0x302U == (vlSelf->w_ir 
                                                   >> 0x14U)));
        vlSelf->p__DOT__r_op_STORE = (0x23U == (0x7fU 
                                                & vlSelf->w_ir));
        vlSelf->p__DOT__r_op_LOAD = (3U == (0x7fU & vlSelf->w_ir));
        vlSelf->p__DOT__r_op_SRET = ((IData)(vlSelf->p__DOT__w_op_priv) 
                                     & (0x102U == (vlSelf->w_ir 
                                                   >> 0x14U)));
    }
    if ((4U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_mul_SU = vlSelf->p__DOT__w_mul_SU;
        vlSelf->p__DOT__r_mul_SS = vlSelf->p__DOT__w_mul_SS;
        vlSelf->p__DOT__r_mul_UU = vlSelf->p__DOT__w_mul_UU;
    }
    if ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (((~ (IData)(vlSelf->w_dram_busy)) & (IData)(vlSelf->mmu__DOT__w_use_tlb))) {
            if (vlSelf->mmu__DOT__w_tlb_hit) {
                __Vdly__mmu__DOT__r_pw_state = 6U;
                vlSelf->mmu__DOT__r_tlb_addr = ((4U 
                                                 == 
                                                 (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->mmu__DOT__w_iswrite))))
                                                 ? 
                                                ((0xfffff000U 
                                                  & (vlSelf->mmu__DOT__w_tlb_inst_r_addr 
                                                     << 0xaU)) 
                                                 | (0xfffU 
                                                    & vlSelf->w_insn_addr))
                                                 : 
                                                ((2U 
                                                  == 
                                                  (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->mmu__DOT__w_iswrite))))
                                                  ? 
                                                 ((0xfffff000U 
                                                   & (vlSelf->mmu__DOT__w_tlb_data_r_addr 
                                                      << 0xaU)) 
                                                  | (0xfffU 
                                                     & vlSelf->w_data_addr))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                                     << 2U) 
                                                    | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                                        << 1U) 
                                                       | (IData)(vlSelf->mmu__DOT__w_iswrite))))
                                                   ? 
                                                  ((0xfffff000U 
                                                    & (vlSelf->mmu__DOT__w_tlb_data_w_addr 
                                                       << 0xaU)) 
                                                   | (0xfffU 
                                                      & vlSelf->w_data_addr))
                                                   : 0U)));
                vlSelf->mmu__DOT__r_tlb_use = (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                                << 2U) 
                                               | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                                   << 1U) 
                                                  | (IData)(vlSelf->mmu__DOT__w_iswrite)));
            } else {
                __Vdly__mmu__DOT__r_pw_state = 1U;
                __Vdly__mmu__DOT__r_dram_was_busy = 0U;
            }
        }
    } else if ((1U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (((IData)(vlSelf->mmu__DOT__r_dram_was_busy) 
             & (~ (IData)(vlSelf->w_dram_busy)))) {
            __Vdly__mmu__DOT__L1_pte = vlSelf->w_dram_odata;
            __Vdly__mmu__DOT__r_pw_state = 2U;
            __Vdly__mmu__DOT__r_dram_was_busy = 0U;
        } else if (vlSelf->w_dram_busy) {
            __Vdly__mmu__DOT__r_dram_was_busy = 1U;
        }
    } else if ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (VL_UNLIKELY(((IData)(vlSelf->w_dram_busy) 
                         & (~ ((3U == vlSelf->w_priv) 
                               | (~ (vlSelf->w_satp 
                                     >> 0x1fU))))))) {
            VL_WRITEF("dram_busy in pw_state 2\n");
        }
        if ((1U & (~ (IData)(vlSelf->w_dram_busy)))) {
            __Vdly__mmu__DOT__r_pw_state = 3U;
            __Vdly__mmu__DOT__r_dram_was_busy = 0U;
        }
    } else if ((3U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (((IData)(vlSelf->mmu__DOT__r_dram_was_busy) 
             & (~ (IData)(vlSelf->w_dram_busy)))) {
            __Vdly__mmu__DOT__L0_pte = vlSelf->w_dram_odata;
            __Vdly__mmu__DOT__r_pw_state = 4U;
            __Vdly__mmu__DOT__r_dram_was_busy = 0U;
        } else if (vlSelf->w_dram_busy) {
            __Vdly__mmu__DOT__r_dram_was_busy = 1U;
        }
    } else if ((4U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if ((1U & vlSelf->mmu__DOT__L1_pte)) {
            if ((0U != (IData)(vlSelf->mmu__DOT__L1_xwr))) {
                if (vlSelf->mmu__DOT__L1_success) {
                    vlSelf->mmu__DOT__physical_addr 
                        = vlSelf->mmu__DOT__L1_p_addr;
                    __Vdly__mmu__DOT__page_walk_fail = 0U;
                } else {
                    vlSelf->mmu__DOT__physical_addr = 0U;
                    __Vdly__mmu__DOT__page_walk_fail = 1U;
                }
            } else if ((1U & vlSelf->mmu__DOT__L0_pte)) {
                if (VL_LIKELY((0U != (IData)(vlSelf->mmu__DOT__L0_xwr)))) {
                    if (vlSelf->mmu__DOT__L0_success) {
                        vlSelf->mmu__DOT__physical_addr 
                            = vlSelf->mmu__DOT__L0_p_addr;
                        __Vdly__mmu__DOT__page_walk_fail = 0U;
                    } else {
                        vlSelf->mmu__DOT__physical_addr = 0U;
                        __Vdly__mmu__DOT__page_walk_fail = 1U;
                    }
                } else {
                    VL_WRITEF("r_pw_state == 4 and no if met\n");
                    VL_FINISH_MT("mmu.v", 218, "");
                }
            } else {
                vlSelf->mmu__DOT__physical_addr = 0U;
                __Vdly__mmu__DOT__page_walk_fail = 1U;
            }
        } else {
            vlSelf->mmu__DOT__physical_addr = 0U;
            __Vdly__mmu__DOT__page_walk_fail = 1U;
        }
        __Vdly__mmu__DOT__r_pw_state = 5U;
    } else if ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (VL_UNLIKELY(vlSelf->mmu__DOT__page_walk_fail)) {
            VL_WRITEF("~ fault=%x ia=%x da=%x vaddr=%x hart=%x grant=%x pc=%x ir=%x\n",
                      32,vlSelf->w_pagefault,32,vlSelf->w_insn_addr,
                      32,vlSelf->w_data_addr,32,vlSelf->mmu__DOT__v_addr,
                      32,vlSelf->w_hart_id,32,vlSelf->w_grant,
                      32,vlSelf->w_pc,32,vlSelf->w_ir);
            if (VL_UNLIKELY(vlSelf->mmu__DOT__w_pte_we)) {
                VL_WRITEF("-----pte-we in pagefault-----\n");
            }
        }
        __Vdly__mmu__DOT__r_pw_state = 0U;
        vlSelf->mmu__DOT__physical_addr = 0U;
        if (VL_UNLIKELY(vlSelf->w_dram_busy)) {
            VL_WRITEF("dram busy in r_pw_state 5\n");
            VL_FINISH_MT("mmu.v", 239, "");
        }
        __Vdly__mmu__DOT__page_walk_fail = 0U;
    } else if ((6U == (IData)(vlSelf->mmu__DOT__r_pw_state))) {
        if (((IData)(vlSelf->mmu__DOT__w_dram_aces) 
             & ((IData)(vlSelf->w_dram_le) | (IData)(vlSelf->mmu__DOT__w_dram_we)))) {
            if (vlSelf->w_dram_busy) {
                __Vdly__mmu__DOT__r_pw_state = 7U;
                vlSelf->mmu__DOT__r_tlb_use = 0U;
                __Vdly__mmu__DOT__r_dram_took_cmd = 1U;
            }
        } else if (VL_LIKELY(((IData)(vlSelf->w_data_le) 
                              | (IData)(vlSelf->w_data_we)))) {
            if ((0U != (IData)(vlSelf->w_data_busy))) {
                __Vdly__mmu__DOT__r_pw_state = 7U;
                vlSelf->mmu__DOT__r_tlb_use = 0U;
                __Vdly__mmu__DOT__r_data_was_busy = 1U;
            }
        } else {
            VL_WRITEF("mmu state 6 and nothing to do\n");
            VL_FINISH_MT("mmu.v", 258, "");
        }
    } else if (((7U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                & (((~ (IData)(vlSelf->w_dram_busy)) 
                    & (IData)(vlSelf->mmu__DOT__r_dram_took_cmd)) 
                   | ((IData)(vlSelf->mmu__DOT__r_data_was_busy) 
                      & (0U == (IData)(vlSelf->w_data_busy)))))) {
        __Vdly__mmu__DOT__r_pw_state = 0U;
        vlSelf->mmu__DOT__r_tlb_use = 0U;
        __Vdly__mmu__DOT__r_dram_took_cmd = 0U;
        __Vdly__mmu__DOT__r_data_was_busy = 0U;
    }
    if ((0U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_mstatus_t = vlSelf->p__DOT__mstatus;
    } else if ((9U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_mstatus_t = (((IData)(vlSelf->p__DOT__r_op_SYS) 
                                        & (0U == (IData)(vlSelf->p__DOT__r_funct3)))
                                        ? ((0x102U 
                                            == (IData)(vlSelf->p__DOT__r_funct12))
                                            ? (0xfffffeffU 
                                               & (0x20U 
                                                  | ((vlSelf->p__DOT__mstatus 
                                                      & (~ 
                                                         ((IData)(1U) 
                                                          << 
                                                          (1U 
                                                           & (vlSelf->p__DOT__mstatus 
                                                              >> 8U))))) 
                                                     | ((1U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 5U)) 
                                                        << 
                                                        (1U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 8U))))))
                                            : ((0x302U 
                                                == (IData)(vlSelf->p__DOT__r_funct12))
                                                ? (0xffffe7ffU 
                                                   & (0x80U 
                                                      | ((vlSelf->p__DOT__mstatus 
                                                          & (~ 
                                                             ((IData)(1U) 
                                                              << 
                                                              (3U 
                                                               & (vlSelf->p__DOT__mstatus 
                                                                  >> 0xbU))))) 
                                                         | ((1U 
                                                             & (vlSelf->p__DOT__mstatus 
                                                                >> 7U)) 
                                                            << 
                                                            (3U 
                                                             & (vlSelf->p__DOT__mstatus 
                                                                >> 0xbU))))))
                                                : vlSelf->p__DOT__mstatus))
                                        : vlSelf->p__DOT__mstatus);
    }
    if ((0U != (IData)(vlSelf->w_state))) {
        if ((9U == (IData)(vlSelf->w_state))) {
            vlSelf->p__DOT__r_priv_t = (3U & (((IData)(vlSelf->p__DOT__r_op_SYS) 
                                               & (0U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)))
                                               ? ((0x102U 
                                                   == (IData)(vlSelf->p__DOT__r_funct12))
                                                   ? 
                                                  (1U 
                                                   & (vlSelf->p__DOT__mstatus 
                                                      >> 8U))
                                                   : 
                                                  ((0x302U 
                                                    == (IData)(vlSelf->p__DOT__r_funct12))
                                                    ? 
                                                   (vlSelf->p__DOT__mstatus 
                                                    >> 0xbU)
                                                    : (IData)(vlSelf->p__DOT__priv)))
                                               : (IData)(vlSelf->p__DOT__priv)));
        }
    }
    vlSelf->p__DOT__r_com = ((((0xaU != (IData)(vlSelf->w_state)) 
                               & (0xbU != (IData)(vlSelf->w_state))) 
                              & (0U != (IData)(vlSelf->w_state)))
                              ? (7U & (((0xffffffffU 
                                         != vlSelf->p__DOT__pending_exception) 
                                        << 2U) | ((
                                                   (0xffffffffU 
                                                    != vlSelf->w_pagefault) 
                                                   << 1U) 
                                                  | ((5U 
                                                      == (IData)(vlSelf->w_state)) 
                                                     & (IData)(vlSelf->p__DOT__r_op_ECALL)))))
                              : 0U);
    vlSelf->p__DOT__r_insn_addr = (((IData)(vlSelf->p__DOT__w_nalign4) 
                                    & (IData)(vlSelf->p__DOT__r_ir16_v))
                                    ? vlSelf->p__DOT__w_vadr2
                                    : (((2U == (IData)(vlSelf->p__DOT__w_if_state)) 
                                        | (3U == (IData)(vlSelf->p__DOT__w_if_state)))
                                        ? vlSelf->p__DOT__w_vadr2
                                        : ((IData)(vlSelf->p__DOT__w_usestate)
                                            ? vlSelf->p__DOT__w_vadr1
                                            : vlSelf->w_pc)));
    if ((4U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_alu_f7 = (0x7fU & ((0x13U 
                                              == (IData)(vlSelf->p__DOT__r_opcode))
                                              ? ((0U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3))
                                                  ? 0U
                                                  : 
                                                 (0x20U 
                                                  & (IData)(vlSelf->p__DOT__r_funct7)))
                                              : (IData)(vlSelf->p__DOT__r_funct7)));
    }
    if ((1U == (IData)(vlSelf->w_state))) {
        if (VL_UNLIKELY(vlSelf->w_plic_we)) {
            VL_WRITEF("----rvcorem w_plic_we mip <= %x state=%x\n",
                      32,vlSelf->w_wmip,4,(IData)(vlSelf->w_state));
            __Vdly__p__DOT__mip = ((0xffU & __Vdly__p__DOT__mip) 
                                   | (0xffffff00U & vlSelf->w_wmip));
        }
        if ((0U != (vlSelf->w_ipi & ((0x1fU >= vlSelf->p__DOT__mhartid)
                                      ? ((IData)(1U) 
                                         << vlSelf->p__DOT__mhartid)
                                      : 0U)))) {
            if ((1U & (~ (IData)(vlSelf->w_ipi_taken)))) {
                if ((0U != ((vlSelf->w_ipi >> 0x10U) 
                            & ((0x1fU >= vlSelf->p__DOT__mhartid)
                                ? ((IData)(1U) << vlSelf->p__DOT__mhartid)
                                : 0U)))) {
                    __Vdly__p__DOT__mip = ((0xfffffff0U 
                                            & __Vdly__p__DOT__mip) 
                                           | (0xfU 
                                              & (2U 
                                                 | vlSelf->p__DOT__mip)));
                    if (VL_UNLIKELY((0xaU > vlSelf->p__DOT__r_ipi_max_displays))) {
                        VL_WRITEF("core%1x got ipi=%x ssip priv=%x mie=%x mtvec=%x time=%x pc=%x\n",
                                  32,vlSelf->p__DOT__mhartid,
                                  32,vlSelf->w_ipi,
                                  2,(IData)(vlSelf->p__DOT__priv),
                                  32,vlSelf->p__DOT__mie,
                                  32,vlSelf->p__DOT__mtvec,
                                  64,vlSelf->w_mtime,
                                  32,vlSelf->w_pc);
                        __Vdly__p__DOT__r_ipi_max_displays 
                            = ((IData)(1U) + vlSelf->p__DOT__r_ipi_max_displays);
                    }
                } else {
                    __Vdly__p__DOT__mip = ((0xfffffff0U 
                                            & __Vdly__p__DOT__mip) 
                                           | (0xfU 
                                              & (8U 
                                                 | vlSelf->p__DOT__mip)));
                    if (VL_UNLIKELY((0xaU > vlSelf->p__DOT__r_ipi_max_displays))) {
                        VL_WRITEF("core%1x got ipi=%x msip priv=%x mie=%x mtvec=%x pc=%x\n",
                                  32,vlSelf->p__DOT__mhartid,
                                  32,vlSelf->w_ipi,
                                  2,(IData)(vlSelf->p__DOT__priv),
                                  32,vlSelf->p__DOT__mie,
                                  32,vlSelf->p__DOT__mtvec,
                                  32,vlSelf->w_pc);
                        __Vdly__p__DOT__r_ipi_max_displays 
                            = ((IData)(1U) + vlSelf->p__DOT__r_ipi_max_displays);
                    }
                }
                vlSelf->w_ipi_taken = 1U;
            }
        } else {
            vlSelf->w_ipi_taken = 0U;
        }
    } else if (((((0xbU == (IData)(vlSelf->w_state)) 
                  & (~ (IData)(vlSelf->w_proc_busy))) 
                 & ((0U != vlSelf->p__DOT__w_interrupt_mask) 
                    & (IData)(vlSelf->p__DOT__w_take_int))) 
                & ((1U == vlSelf->p__DOT__irq_num) 
                   | (3U == vlSelf->p__DOT__irq_num)))) {
        __Vdly__p__DOT__mip = (0xfffffff0U & __Vdly__p__DOT__mip);
        if (VL_UNLIKELY((0xaU > vlSelf->p__DOT__r_ipi_max_displays))) {
            VL_WRITEF("core%1x got clear ipi\n",32,
                      vlSelf->p__DOT__mhartid);
            __Vdly__p__DOT__r_ipi_max_displays = ((IData)(1U) 
                                                  + vlSelf->p__DOT__r_ipi_max_displays);
        }
    }
    if (((7U == (IData)(vlSelf->w_state)) | (9U == (IData)(vlSelf->w_state)))) {
        if (VL_UNLIKELY(vlSelf->w_plic_we)) {
            VL_WRITEF("----rvcorem w_plic_we mip <= %x state=%x\n",
                      32,vlSelf->w_wmip,4,(IData)(vlSelf->w_state));
            __Vdly__p__DOT__mip = ((0xffU & __Vdly__p__DOT__mip) 
                                   | (0xffffff00U & vlSelf->w_wmip));
        }
    }
    if (vlSelf->w_clint_we) {
        __Vdly__p__DOT__r_was_clint_we = ((2U > (IData)(vlSelf->p__DOT__r_was_clint_we))
                                           ? (0xfU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->p__DOT__r_was_clint_we)))
                                           : 1U);
        __Vdly__p__DOT__mip = (0xffffff0fU & __Vdly__p__DOT__mip);
        if (VL_UNLIKELY(((1U == (IData)(vlSelf->p__DOT__r_was_clint_we)) 
                         & (vlSelf->w_mtime > vlSelf->w_wmtimecmp)))) {
            VL_WRITEF("warning: w_mtime=%0# > w_wmtimecmp=%0#\n",
                      64,vlSelf->w_mtime,64,vlSelf->w_mtimecmp);
        }
        __Vdly__p__DOT__mtimecmp = vlSelf->w_wmtimecmp;
    } else if ((1U == (IData)(vlSelf->w_state))) {
        if (((2U == (IData)(vlSelf->p__DOT__r_was_clint_we)) 
             & (vlSelf->w_mtime >= vlSelf->p__DOT__mtimecmp))) {
            __Vdly__p__DOT__mip = (0x20U | (0xffffff0fU 
                                            & __Vdly__p__DOT__mip));
            __Vdly__p__DOT__r_was_clint_we = 0U;
        }
    } else if (((((((0xbU == (IData)(vlSelf->w_state)) 
                    & (~ (IData)(vlSelf->w_proc_busy))) 
                   & (0xffffffffU == vlSelf->p__DOT__pending_exception)) 
                  & (0U != vlSelf->p__DOT__w_interrupt_mask)) 
                 & (IData)(vlSelf->p__DOT__w_take_int)) 
                & (5U == vlSelf->p__DOT__irq_num))) {
        __Vdly__p__DOT__mip = (0xffffff0fU & __Vdly__p__DOT__mip);
    }
    if (((0xbU == (IData)(vlSelf->w_state)) & (~ (IData)(vlSelf->w_proc_busy)))) {
        if ((0xffffffffU != vlSelf->p__DOT__pending_exception)) {
            if ((0U != vlSelf->p__DOT__w_deleg)) {
                vlSelf->p__DOT__scause = vlSelf->p__DOT__cause;
                vlSelf->p__DOT__sepc = vlSelf->w_pc;
                vlSelf->p__DOT__stval = vlSelf->p__DOT__pending_tval;
                __Vdly__p__DOT__mstatus = vlSelf->p__DOT__w_sstatus_t3;
                __Vdly__p__DOT__priv = 1U;
            } else {
                vlSelf->p__DOT__mcause = vlSelf->p__DOT__cause;
                vlSelf->p__DOT__mepc = vlSelf->w_pc;
                vlSelf->p__DOT__mtval = vlSelf->p__DOT__pending_tval;
                __Vdly__p__DOT__mstatus = vlSelf->p__DOT__w_mstatus_t3;
                __Vdly__p__DOT__priv = 3U;
            }
        } else if (((0U != vlSelf->p__DOT__w_interrupt_mask) 
                    & (IData)(vlSelf->p__DOT__w_take_int))) {
            if ((5U == vlSelf->p__DOT__irq_num)) {
                if ((0U == vlSelf->w_hart_id)) {
                    if (VL_UNLIKELY((0xbebc200ULL > vlSelf->w_mtime))) {
                        VL_FWRITEF(vlSelf->p__DOT__f,"%0# %x\n",
                                   64,vlSelf->w_mtime,
                                   32,vlSelf->w_pc);
                    } else if (VL_UNLIKELY((1U & (~ (IData)(
                                                            (0U 
                                                             != vlSelf->p__DOT__closed)))))) {
                        VL_FCLOSE_I(vlSelf->p__DOT__f); vlSelf->p__DOT__f = 0;
                        vlSelf->p__DOT__closed = 1U;
                    }
                }
                vlSelf->w_pc_stip = vlSelf->w_pc;
            }
            if (VL_UNLIKELY((2U == vlSelf->p__DOT__irq_num))) {
                VL_WRITEF("irq_num=2, pc=%x\n",32,vlSelf->w_pc);
                VL_FINISH_MT("rvcorem.v", 798, "");
            }
            if ((0U != vlSelf->p__DOT__w_deleg)) {
                vlSelf->p__DOT__scause = vlSelf->p__DOT__cause;
                vlSelf->p__DOT__sepc = ((IData)(vlSelf->p__DOT__r_tkn)
                                         ? vlSelf->p__DOT__r_jmp_pc
                                         : ((IData)(vlSelf->p__DOT__r_cinsn)
                                             ? ((IData)(2U) 
                                                + vlSelf->w_pc)
                                             : ((IData)(4U) 
                                                + vlSelf->w_pc)));
                vlSelf->p__DOT__stval = vlSelf->p__DOT__pending_tval;
                __Vdly__p__DOT__mstatus = vlSelf->p__DOT__w_sstatus_t3;
                __Vdly__p__DOT__priv = 1U;
            } else {
                if (VL_UNLIKELY((5U == vlSelf->p__DOT__irq_num))) {
                    VL_WRITEF("irq_num `MIP_STIP_SHIFT will be in privm\n");
                    VL_FINISH_MT("rvcorem.v", 814, "");
                }
                vlSelf->p__DOT__mcause = vlSelf->p__DOT__cause;
                vlSelf->p__DOT__mepc = ((IData)(vlSelf->p__DOT__r_tkn)
                                         ? vlSelf->p__DOT__r_jmp_pc
                                         : ((IData)(vlSelf->p__DOT__r_cinsn)
                                             ? ((IData)(2U) 
                                                + vlSelf->w_pc)
                                             : ((IData)(4U) 
                                                + vlSelf->w_pc)));
                vlSelf->p__DOT__mtval = vlSelf->p__DOT__pending_tval;
                __Vdly__p__DOT__mstatus = vlSelf->p__DOT__w_mstatus_t3;
                __Vdly__p__DOT__priv = 3U;
            }
        }
    } else if (((0xaU == (IData)(vlSelf->w_state)) 
                & (~ (IData)(vlSelf->w_proc_busy)))) {
        if (((0x73U == (IData)(vlSelf->p__DOT__r_opcode)) 
             & (0U == (IData)(vlSelf->p__DOT__r_funct3)))) {
            if ((2U != (IData)(vlSelf->p__DOT__r_funct12))) {
                if ((0x102U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__mstatus = (0xfffffeffU 
                                               & (0x20U 
                                                  | ((vlSelf->p__DOT__mstatus 
                                                      & (~ 
                                                         ((IData)(1U) 
                                                          << 
                                                          (1U 
                                                           & (vlSelf->p__DOT__mstatus 
                                                              >> 8U))))) 
                                                     | ((1U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 5U)) 
                                                        << 
                                                        (1U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 8U))))));
                    __Vdly__p__DOT__priv = (1U & (vlSelf->p__DOT__mstatus 
                                                  >> 8U));
                } else if ((0x302U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__mstatus = (0xffffe7ffU 
                                               & (0x80U 
                                                  | ((vlSelf->p__DOT__mstatus 
                                                      & (~ 
                                                         ((IData)(1U) 
                                                          << 
                                                          (3U 
                                                           & (vlSelf->p__DOT__mstatus 
                                                              >> 0xbU))))) 
                                                     | ((1U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 7U)) 
                                                        << 
                                                        (3U 
                                                         & (vlSelf->p__DOT__mstatus 
                                                            >> 0xbU))))));
                    __Vdly__p__DOT__priv = (3U & (vlSelf->p__DOT__mstatus 
                                                  >> 0xbU));
                }
            }
        } else if (vlSelf->p__DOT__w_csr_we) {
            if (((((((((0x105U == (IData)(vlSelf->p__DOT__r_funct12)) 
                       | (0x106U == (IData)(vlSelf->p__DOT__r_funct12))) 
                      | (0x140U == (IData)(vlSelf->p__DOT__r_funct12))) 
                     | (0x141U == (IData)(vlSelf->p__DOT__r_funct12))) 
                    | (0x142U == (IData)(vlSelf->p__DOT__r_funct12))) 
                   | (0x143U == (IData)(vlSelf->p__DOT__r_funct12))) 
                  | (0x305U == (IData)(vlSelf->p__DOT__r_funct12))) 
                 | (0x306U == (IData)(vlSelf->p__DOT__r_funct12)))) {
                if ((0x105U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__stvec = (0xfffffffcU 
                                             & vlSelf->p__DOT__r_wb_data_csr);
                } else if ((0x106U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__scounteren = (5U 
                                                  & vlSelf->p__DOT__r_wb_data_csr);
                } else if ((0x140U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__sscratch = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x141U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__sepc = (0xfffffffeU 
                                            & vlSelf->p__DOT__r_wb_data_csr);
                } else if ((0x142U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__scause = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x143U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__stval = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x305U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__mtvec = (0xfffffffcU 
                                             & vlSelf->p__DOT__r_wb_data_csr);
                } else {
                    vlSelf->p__DOT__mcounteren = (5U 
                                                  & vlSelf->p__DOT__r_wb_data_csr);
                }
            } else if (((((((((0x340U == (IData)(vlSelf->p__DOT__r_funct12)) 
                              | (0x341U == (IData)(vlSelf->p__DOT__r_funct12))) 
                             | (0x342U == (IData)(vlSelf->p__DOT__r_funct12))) 
                            | (0x343U == (IData)(vlSelf->p__DOT__r_funct12))) 
                           | (0x104U == (IData)(vlSelf->p__DOT__r_funct12))) 
                          | (0x144U == (IData)(vlSelf->p__DOT__r_funct12))) 
                         | (0x302U == (IData)(vlSelf->p__DOT__r_funct12))) 
                        | (0x303U == (IData)(vlSelf->p__DOT__r_funct12)))) {
                if ((0x340U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__mscratch = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x341U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__mepc = (0xfffffffeU 
                                            & vlSelf->p__DOT__r_wb_data_csr);
                } else if ((0x342U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__mcause = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x343U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__mtval = vlSelf->p__DOT__r_wb_data_csr;
                } else if ((0x104U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__mie = ((vlSelf->p__DOT__mie 
                                            & (~ vlSelf->p__DOT__mideleg)) 
                                           | (vlSelf->p__DOT__r_wb_data_csr 
                                              & vlSelf->p__DOT__mideleg));
                } else if ((0x144U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    __Vdly__p__DOT__mip = ((vlSelf->p__DOT__mip 
                                            & (~ vlSelf->p__DOT__mideleg)) 
                                           | (vlSelf->p__DOT__r_wb_data_csr 
                                              & vlSelf->p__DOT__mideleg));
                } else if ((0x302U == (IData)(vlSelf->p__DOT__r_funct12))) {
                    vlSelf->p__DOT__medeleg = ((0xffff0000U 
                                                & vlSelf->p__DOT__medeleg) 
                                               | (0xffffU 
                                                  & vlSelf->p__DOT__r_wb_data_csr));
                } else {
                    vlSelf->p__DOT__mideleg = ((0xfffffdddU 
                                                & vlSelf->p__DOT__mideleg) 
                                               | (0x222U 
                                                  & vlSelf->p__DOT__r_wb_data_csr));
                }
            } else if ((0x304U == (IData)(vlSelf->p__DOT__r_funct12))) {
                __Vdly__p__DOT__mie = ((0xfffffd55U 
                                        & vlSelf->p__DOT__mie) 
                                       | (0x2aaU & vlSelf->p__DOT__r_wb_data_csr));
            } else if ((0x344U == (IData)(vlSelf->p__DOT__r_funct12))) {
                __Vdly__p__DOT__mip = ((0xffffffd5U 
                                        & vlSelf->p__DOT__mip) 
                                       | (0x2aU & vlSelf->p__DOT__r_wb_data_csr));
            } else if ((0x180U == (IData)(vlSelf->p__DOT__r_funct12))) {
                vlSelf->p__DOT__satp = vlSelf->p__DOT__r_wb_data_csr;
            } else if ((0x300U == (IData)(vlSelf->p__DOT__r_funct12))) {
                __Vdly__p__DOT__mstatus = ((0xfff1e644U 
                                            & vlSelf->p__DOT__mstatus) 
                                           | (0xe19bbU 
                                              & vlSelf->p__DOT__r_wb_data_csr));
            } else if ((0x100U == (IData)(vlSelf->p__DOT__r_funct12))) {
                __Vdly__p__DOT__mstatus = ((0xfff1e644U 
                                            & vlSelf->p__DOT__mstatus) 
                                           | (0xe19bbU 
                                              & vlSelf->p__DOT__w_sstatus));
            }
        }
    }
    if (((1U == (IData)(vlSelf->w_state)) & (0xffffffffU 
                                             == vlSelf->w_pagefault))) {
        vlSelf->p__DOT__r_cpc = vlSelf->w_pc;
    }
    if (__Vdlyvset__mmu__DOT__TLB_inst_r__DOT__mem__v0) {
        vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[__Vdlyvdim0__mmu__DOT__TLB_inst_r__DOT__mem__v0] 
            = __Vdlyvval__mmu__DOT__TLB_inst_r__DOT__mem__v0;
    }
    if (__Vdlyvset__mmu__DOT__TLB_data_w__DOT__mem__v0) {
        vlSelf->mmu__DOT__TLB_data_w__DOT__mem[__Vdlyvdim0__mmu__DOT__TLB_data_w__DOT__mem__v0] 
            = __Vdlyvval__mmu__DOT__TLB_data_w__DOT__mem__v0;
    }
    if (__Vdlyvset__mmu__DOT__TLB_data_r__DOT__mem__v0) {
        vlSelf->mmu__DOT__TLB_data_r__DOT__mem[__Vdlyvdim0__mmu__DOT__TLB_data_r__DOT__mem__v0] 
            = __Vdlyvval__mmu__DOT__TLB_data_r__DOT__mem__v0;
    }
    if (__Vdlyvset__p__DOT__regs__DOT__mem__v0) {
        vlSelf->p__DOT__regs__DOT__mem[__Vdlyvdim0__p__DOT__regs__DOT__mem__v0] 
            = __Vdlyvval__p__DOT__regs__DOT__mem__v0;
    }
    vlSelf->mmu__DOT__r_dram_was_busy = __Vdly__mmu__DOT__r_dram_was_busy;
    vlSelf->mmu__DOT__r_dram_took_cmd = __Vdly__mmu__DOT__r_dram_took_cmd;
    vlSelf->mmu__DOT__r_data_was_busy = __Vdly__mmu__DOT__r_data_was_busy;
    vlSelf->mmu__DOT__page_walk_fail = __Vdly__mmu__DOT__page_walk_fail;
    vlSelf->mmu__DOT__L0_pte = __Vdly__mmu__DOT__L0_pte;
    vlSelf->mmu__DOT__r_pw_state = __Vdly__mmu__DOT__r_pw_state;
    vlSelf->mmu__DOT__L1_pte = __Vdly__mmu__DOT__L1_pte;
    vlSelf->p__DOT__r_ipi_max_displays = __Vdly__p__DOT__r_ipi_max_displays;
    vlSelf->p__DOT__r_was_clint_we = __Vdly__p__DOT__r_was_clint_we;
    vlSelf->p__DOT__mtimecmp = __Vdly__p__DOT__mtimecmp;
    vlSelf->p__DOT__mie = __Vdly__p__DOT__mie;
    vlSelf->p__DOT__mip = __Vdly__p__DOT__mip;
    vlSelf->p__DOT__mstatus = __Vdly__p__DOT__mstatus;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_rslt 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_differ 
        = (0x1ffffffffULL & ((vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_uint_rslt 
                              >> 0x1fU) - (QData)((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_divisor))));
    vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy = (0x20U 
                                                   > (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__r_count));
    p__DOT__ALU_IM__DOT__divunit__DOT____VdfgTmp_hbfa8a25c__0 
        = (((IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_dividend) 
            << 1U) | (IData)(vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_sign_divisor));
    vlSelf->p__DOT__w_init_stage = vlSelf->p__DOT__r_init_stage;
    vlSelf->w_proc_data_we = vlSelf->p__DOT__r_data_we;
    mmu__DOT____VdfgTmp_hdf96e1fa__0 = ((0U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    mmu__DOT____VdfgTmp_h2aff9416__0 = ((1U == vlSelf->w_hart_id) 
                                        & (IData)(vlSelf->p__DOT__r_data_we));
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SU = vlSelf->p__DOT__r_mul_SU;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_SS = vlSelf->p__DOT__r_mul_SS;
    vlSelf->p__DOT__ALU_IM__DOT__w_mul_UU = vlSelf->p__DOT__r_mul_UU;
    vlSelf->w_data_wdata = vlSelf->p__DOT__r_data_wdata;
    vlSelf->p__DOT__ALU_A__DOT__w_funct5 = vlSelf->p__DOT__r_funct5;
    vlSelf->w_tlb_req = vlSelf->p__DOT__r_tlb_req;
    vlSelf->mmu__DOT__w_isread = (0U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__w_iswrite = (1U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->mmu__DOT__w_iscode = (2U == (IData)(vlSelf->p__DOT__r_tlb_req));
    vlSelf->w_data_ctrl = vlSelf->p__DOT__r_data_ctrl;
    vlSelf->p__DOT__r_if_state = vlSelf->p__DOT__w_if_state;
    vlSelf->mmu__DOT__w_tlb_wdata = (0x3ffffcU & (vlSelf->mmu__DOT__physical_addr 
                                                  >> 0xaU));
    vlSelf->mmu__DOT__L0_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L0_pte 
                                                 << 2U));
    mmu__DOT____VdfgTmp_h1a37559d__0 = ((~ (IData)(vlSelf->mmu__DOT__page_walk_fail)) 
                                        & (5U == (IData)(vlSelf->mmu__DOT__r_pw_state)));
    vlSelf->mmu__DOT__r_tlb_acs = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                   | ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                                      | (5U == (IData)(vlSelf->mmu__DOT__r_pw_state))));
    vlSelf->mmu__DOT__L1_paddr = (0xfffff000U & (vlSelf->mmu__DOT__L1_pte 
                                                 << 2U));
    vlSelf->p__DOT__ALU_IM__DOT__w_funct7 = vlSelf->p__DOT__r_alu_f7;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_waddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_raddr = (0xfffffU 
                                                  & (vlSelf->p__DOT__r_insn_addr 
                                                     >> 0xcU));
    vlSelf->w_insn_addr = vlSelf->p__DOT__r_insn_addr;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag = (vlSelf->p__DOT__r_insn_addr 
                                                 >> 0xeU);
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_insn_addr 
                                                    >> 0xcU));
    if ((1U & (~ ((~ (IData)(vlSelf->CORE_RST_X)) | (IData)(vlSelf->w_halt))))) {
        if ((0xffffffffU == vlSelf->w_pagefault)) {
            if (((0xbU == (IData)(vlSelf->w_state)) 
                 & (~ (IData)(vlSelf->w_proc_busy)))) {
                vlSelf->p__DOT__r_ir16_v = (1U & (~ 
                                                  ((((0xffffffffU 
                                                      != vlSelf->p__DOT__pending_exception) 
                                                     | ((0U 
                                                         != vlSelf->p__DOT__w_interrupt_mask) 
                                                        & (IData)(vlSelf->p__DOT__w_take_int))) 
                                                    | (IData)(vlSelf->p__DOT__r_tkn)) 
                                                   | (~ (IData)(vlSelf->p__DOT__r_cinsn)))));
            }
        }
    }
    vlSelf->p__DOT__r_ipi_taken = vlSelf->w_ipi_taken;
    vlSelf->p__DOT__pc_stip = vlSelf->w_pc_stip;
    vlSelf->w_mtimecmp = vlSelf->p__DOT__mtimecmp;
    mmu__DOT____VdfgTmp_h0821c8f5__0 = (((QData)((IData)(
                                                         (vlSelf->p__DOT__mtimecmp 
                                                          >> 0x20U))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__r_data_wdata)));
    mmu__DOT____VdfgTmp_hd62e4571__0 = (((QData)((IData)(vlSelf->p__DOT__r_data_wdata)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->p__DOT__mtimecmp)));
    vlSelf->w_mip = vlSelf->p__DOT__mip;
    vlSelf->p__DOT__pending_interrupts = (vlSelf->p__DOT__mie 
                                          & vlSelf->p__DOT__mip);
    vlSelf->w_satp = vlSelf->p__DOT__satp;
    vlSelf->w_mstatus = vlSelf->p__DOT__mstatus;
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
    if ((0xaU == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__irq_num = (((((((((1U == vlSelf->p__DOT__w_irq_t) 
                                          | (2U == vlSelf->p__DOT__w_irq_t)) 
                                         | (4U == vlSelf->p__DOT__w_irq_t)) 
                                        | (8U == vlSelf->p__DOT__w_irq_t)) 
                                       | (0x10U == vlSelf->p__DOT__w_irq_t)) 
                                      | (0x20U == vlSelf->p__DOT__w_irq_t)) 
                                     | (0x40U == vlSelf->p__DOT__w_irq_t)) 
                                    | (0x80U == vlSelf->p__DOT__w_irq_t))
                                    ? ((1U == vlSelf->p__DOT__w_irq_t)
                                        ? 0U : ((2U 
                                                 == vlSelf->p__DOT__w_irq_t)
                                                 ? 1U
                                                 : 
                                                ((4U 
                                                  == vlSelf->p__DOT__w_irq_t)
                                                  ? 2U
                                                  : 
                                                 ((8U 
                                                   == vlSelf->p__DOT__w_irq_t)
                                                   ? 3U
                                                   : 
                                                  ((0x10U 
                                                    == vlSelf->p__DOT__w_irq_t)
                                                    ? 4U
                                                    : 
                                                   ((0x20U 
                                                     == vlSelf->p__DOT__w_irq_t)
                                                     ? 5U
                                                     : 
                                                    ((0x40U 
                                                      == vlSelf->p__DOT__w_irq_t)
                                                      ? 6U
                                                      : 7U)))))))
                                    : (((((((((0x100U 
                                               == vlSelf->p__DOT__w_irq_t) 
                                              | (0x200U 
                                                 == vlSelf->p__DOT__w_irq_t)) 
                                             | (0x400U 
                                                == vlSelf->p__DOT__w_irq_t)) 
                                            | (0x800U 
                                               == vlSelf->p__DOT__w_irq_t)) 
                                           | (0x1000U 
                                              == vlSelf->p__DOT__w_irq_t)) 
                                          | (0x2000U 
                                             == vlSelf->p__DOT__w_irq_t)) 
                                         | (0x4000U 
                                            == vlSelf->p__DOT__w_irq_t)) 
                                        | (0x8000U 
                                           == vlSelf->p__DOT__w_irq_t))
                                        ? ((0x100U 
                                            == vlSelf->p__DOT__w_irq_t)
                                            ? 8U : 
                                           ((0x200U 
                                             == vlSelf->p__DOT__w_irq_t)
                                             ? 9U : 
                                            ((0x400U 
                                              == vlSelf->p__DOT__w_irq_t)
                                              ? 0xaU
                                              : ((0x800U 
                                                  == vlSelf->p__DOT__w_irq_t)
                                                  ? 0xbU
                                                  : 
                                                 ((0x1000U 
                                                   == vlSelf->p__DOT__w_irq_t)
                                                   ? 0xcU
                                                   : 
                                                  ((0x2000U 
                                                    == vlSelf->p__DOT__w_irq_t)
                                                    ? 0xdU
                                                    : 
                                                   ((0x4000U 
                                                     == vlSelf->p__DOT__w_irq_t)
                                                     ? 0xeU
                                                     : 0xfU)))))))
                                        : (((((((((0x10000U 
                                                   == vlSelf->p__DOT__w_irq_t) 
                                                  | (0x20000U 
                                                     == vlSelf->p__DOT__w_irq_t)) 
                                                 | (0x40000U 
                                                    == vlSelf->p__DOT__w_irq_t)) 
                                                | (0x80000U 
                                                   == vlSelf->p__DOT__w_irq_t)) 
                                               | (0x100000U 
                                                  == vlSelf->p__DOT__w_irq_t)) 
                                              | (0x200000U 
                                                 == vlSelf->p__DOT__w_irq_t)) 
                                             | (0x400000U 
                                                == vlSelf->p__DOT__w_irq_t)) 
                                            | (0x800000U 
                                               == vlSelf->p__DOT__w_irq_t))
                                            ? ((0x10000U 
                                                == vlSelf->p__DOT__w_irq_t)
                                                ? 0x10U
                                                : (
                                                   (0x20000U 
                                                    == vlSelf->p__DOT__w_irq_t)
                                                    ? 0x11U
                                                    : 
                                                   ((0x40000U 
                                                     == vlSelf->p__DOT__w_irq_t)
                                                     ? 0x12U
                                                     : 
                                                    ((0x80000U 
                                                      == vlSelf->p__DOT__w_irq_t)
                                                      ? 0x13U
                                                      : 
                                                     ((0x100000U 
                                                       == vlSelf->p__DOT__w_irq_t)
                                                       ? 0x14U
                                                       : 
                                                      ((0x200000U 
                                                        == vlSelf->p__DOT__w_irq_t)
                                                        ? 0x15U
                                                        : 
                                                       ((0x400000U 
                                                         == vlSelf->p__DOT__w_irq_t)
                                                         ? 0x16U
                                                         : 0x17U)))))))
                                            : (((((
                                                   ((((0x1000000U 
                                                       == vlSelf->p__DOT__w_irq_t) 
                                                      | (0x2000000U 
                                                         == vlSelf->p__DOT__w_irq_t)) 
                                                     | (0x4000000U 
                                                        == vlSelf->p__DOT__w_irq_t)) 
                                                    | (0x8000000U 
                                                       == vlSelf->p__DOT__w_irq_t)) 
                                                   | (0x10000000U 
                                                      == vlSelf->p__DOT__w_irq_t)) 
                                                  | (0x20000000U 
                                                     == vlSelf->p__DOT__w_irq_t)) 
                                                 | (0x40000000U 
                                                    == vlSelf->p__DOT__w_irq_t)) 
                                                | (0x80000000U 
                                                   == vlSelf->p__DOT__w_irq_t))
                                                ? (
                                                   (0x1000000U 
                                                    == vlSelf->p__DOT__w_irq_t)
                                                    ? 0x18U
                                                    : 
                                                   ((0x2000000U 
                                                     == vlSelf->p__DOT__w_irq_t)
                                                     ? 0x19U
                                                     : 
                                                    ((0x4000000U 
                                                      == vlSelf->p__DOT__w_irq_t)
                                                      ? 0x1aU
                                                      : 
                                                     ((0x8000000U 
                                                       == vlSelf->p__DOT__w_irq_t)
                                                       ? 0x1bU
                                                       : 
                                                      ((0x10000000U 
                                                        == vlSelf->p__DOT__w_irq_t)
                                                        ? 0x1cU
                                                        : 
                                                       ((0x20000000U 
                                                         == vlSelf->p__DOT__w_irq_t)
                                                         ? 0x1dU
                                                         : 
                                                        ((0x40000000U 
                                                          == vlSelf->p__DOT__w_irq_t)
                                                          ? 0x1eU
                                                          : 0x1fU)))))))
                                                : 0x20U))));
    }
    if ((1U & ((~ (IData)(vlSelf->CORE_RST_X)) | (IData)(vlSelf->w_halt)))) {
        __Vdly__w_pc = 0x80700000U;
    } else if ((0xffffffffU != vlSelf->w_pagefault)) {
        vlSelf->p__DOT__pending_tval = ((1U == (IData)(vlSelf->w_state))
                                         ? vlSelf->w_pc
                                         : (((6U != (IData)(vlSelf->w_state)) 
                                             & (8U 
                                                != (IData)(vlSelf->w_state)))
                                             ? 0U : vlSelf->p__DOT__r_mem_addr));
    } else if (((0xbU == (IData)(vlSelf->w_state)) 
                & (~ (IData)(vlSelf->w_proc_busy)))) {
        if ((0xffffffffU != vlSelf->p__DOT__pending_exception)) {
            __Vdly__w_pc = ((0U != vlSelf->p__DOT__w_deleg)
                             ? vlSelf->p__DOT__stvec
                             : vlSelf->p__DOT__mtvec);
        } else if (((0U != vlSelf->p__DOT__w_interrupt_mask) 
                    & (IData)(vlSelf->p__DOT__w_take_int))) {
            __Vdly__w_pc = ((0U != vlSelf->p__DOT__w_deleg)
                             ? vlSelf->p__DOT__stvec
                             : vlSelf->p__DOT__mtvec);
        } else if (vlSelf->p__DOT__w_executing_wfi) {
            if (vlSelf->p__DOT__w_exit_wfi) {
                __Vdly__w_pc = ((IData)(4U) + vlSelf->w_pc);
            }
        } else {
            __Vdly__w_pc = ((IData)(vlSelf->p__DOT__r_tkn)
                             ? vlSelf->p__DOT__r_jmp_pc
                             : ((IData)(vlSelf->p__DOT__r_cinsn)
                                 ? ((IData)(2U) + vlSelf->w_pc)
                                 : ((IData)(4U) + vlSelf->w_pc)));
        }
    } else if ((0U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__pending_tval = 0U;
    }
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy;
    vlSelf->mmu__DOT__w_proc_data_we = vlSelf->w_proc_data_we;
    vlSelf->p__DOT__w_data_we = vlSelf->w_proc_data_we;
    vlSelf->mmu__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->p__DOT__w_data_wdata = vlSelf->w_data_wdata;
    vlSelf->mmu__DOT__w_tlb_req = vlSelf->w_tlb_req;
    vlSelf->p__DOT__w_tlb_req = vlSelf->w_tlb_req;
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
    mmu__DOT____VdfgTmp_hdc3ed8a3__0 = ((IData)(vlSelf->mmu__DOT__w_iscode) 
                                        | (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->p__DOT__w_data_ctrl = vlSelf->w_data_ctrl;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_idata = vlSelf->mmu__DOT__w_tlb_wdata;
    vlSelf->mmu__DOT__w_tlb_inst_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->mmu__DOT__w_tlb_data_r_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_isread));
    vlSelf->mmu__DOT__w_tlb_data_w_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                         & (IData)(vlSelf->mmu__DOT__w_iswrite));
    vlSelf->mmu__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->p__DOT__w_insn_addr = vlSelf->w_insn_addr;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx;
    mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_inst_r__DOT__mem[vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx];
    vlSelf->mmu__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_mtimecmp = vlSelf->w_mtimecmp;
    vlSelf->p__DOT__w_mip = vlSelf->w_mip;
    vlSelf->mmu__DOT__w_satp = vlSelf->w_satp;
    vlSelf->p__DOT__w_satp = vlSelf->w_satp;
    vlSelf->mmu__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->p__DOT__w_mstatus = vlSelf->w_mstatus;
    vlSelf->p__DOT__w_sstatus_t = (0xde133U & vlSelf->p__DOT__w_mstatus_t);
    vlSelf->p__DOT__w_exit_wfi = (((1U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                   & (0U != (0x222U 
                                             & vlSelf->p__DOT__pending_interrupts))) 
                                  | ((0U >= (IData)(vlSelf->p__DOT__r_priv_t)) 
                                     & (0U != (0x111U 
                                               & vlSelf->p__DOT__pending_interrupts))));
    vlSelf->p__DOT__stvec = __Vdly__p__DOT__stvec;
    vlSelf->p__DOT__mtvec = __Vdly__p__DOT__mtvec;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_busy 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_busy;
    if ((3U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_rd = (0x1fU & (vlSelf->w_ir 
                                         >> 7U));
    }
    vlSelf->p__DOT__regs__DOT__rd = vlSelf->p__DOT__r_rd;
    if ((4U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_alu_in2 = ((0x13U == (IData)(vlSelf->p__DOT__r_opcode))
                                      ? vlSelf->p__DOT__r_imm
                                      : vlSelf->p__DOT__w_rrs2);
    }
    vlSelf->p__DOT__ALU_B__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_IM__DOT__w_in2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_IM__DOT__w_sin2 = vlSelf->p__DOT__r_alu_in2;
    vlSelf->p__DOT__ALU_IM__DOT__w_shamt = (0x1fU & vlSelf->p__DOT__r_alu_in2);
    if ((3U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_op_AMO_LR = (2U == (vlSelf->w_ir 
                                              >> 0x1bU));
        vlSelf->p__DOT__r_rrs2 = vlSelf->p__DOT__w_rrs2;
    }
    vlSelf->p__DOT__ALU_A__DOT__w_in1 = vlSelf->p__DOT__r_rrs2;
    vlSelf->p__DOT__w_sin2 = vlSelf->p__DOT__r_rrs2;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_inst_r_we;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_r_we;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_we = vlSelf->mmu__DOT__w_tlb_data_w_we;
    vlSelf->mmu__DOT__w_tlb_inst_r_addr = (0x3fffffU 
                                           & (IData)(mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0));
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch = 
        ((0x3ffffU & (IData)((mmu__DOT__TLB_inst_r__DOT____VdfgTmp_h859f30cf__0 
                              >> 0x16U))) == vlSelf->mmu__DOT__TLB_inst_r__DOT__w_rtag);
    if ((0x7fU == (IData)(vlSelf->p__DOT__r_opcode))) {
        vlSelf->w_halt = 1U;
    }
    if ((3U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_op_AMO = (0x2fU == (0x7fU 
                                              & vlSelf->w_ir));
        vlSelf->p__DOT__r_op_SYS = (0x73U == (0x7fU 
                                              & vlSelf->w_ir));
        vlSelf->p__DOT__r_op_ECALL = ((IData)(vlSelf->p__DOT__w_op_priv) 
                                      & (0U == (vlSelf->w_ir 
                                                >> 0x14U)));
    }
    if ((4U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_mem_addr = vlSelf->p__DOT__w_mem_addr;
    }
    vlSelf->mmu__DOT__w_mem_wdata = ((0U != (IData)(vlSelf->mmu__DOT__r_mc_mode))
                                      ? vlSelf->mmu__DOT__w_mc_wdata
                                      : vlSelf->p__DOT__r_data_wdata);
    if ((0xffffffffU != vlSelf->w_pagefault)) {
        vlSelf->p__DOT__pending_exception = vlSelf->w_pagefault;
    } else if ((0U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__pending_exception = 0xffffffffU;
        vlSelf->p__DOT__r_tkn = 0U;
    } else if ((5U == (IData)(vlSelf->w_state))) {
        if ((0x40U & (IData)(vlSelf->p__DOT__r_opcode))) {
            if (VL_LIKELY((0x20U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                if ((0x10U & (IData)(vlSelf->p__DOT__r_opcode))) {
                    if (VL_UNLIKELY((8U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    } else if (VL_UNLIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                            if ((0U == (IData)(vlSelf->p__DOT__r_funct3))) {
                                if ((0U == (IData)(vlSelf->p__DOT__r_funct12))) {
                                    vlSelf->p__DOT__r_wb_data_csr 
                                        = ((IData)(8U) 
                                           + (IData)(vlSelf->p__DOT__priv));
                                    vlSelf->p__DOT__pending_exception 
                                        = ((IData)(8U) 
                                           + (IData)(vlSelf->p__DOT__priv));
                                } else if ((1U != (IData)(vlSelf->p__DOT__r_funct12))) {
                                    if ((2U == (IData)(vlSelf->p__DOT__r_funct12))) {
                                        vlSelf->p__DOT__r_tkn = 1U;
                                        vlSelf->p__DOT__r_jmp_pc 
                                            = vlSelf->p__DOT__r_rcsr;
                                    } else if ((0x102U 
                                                == (IData)(vlSelf->p__DOT__r_funct12))) {
                                        vlSelf->p__DOT__r_tkn = 1U;
                                        vlSelf->p__DOT__r_jmp_pc 
                                            = vlSelf->p__DOT__r_rcsr;
                                    } else if ((0x302U 
                                                == (IData)(vlSelf->p__DOT__r_funct12))) {
                                        vlSelf->p__DOT__r_tkn = 1U;
                                        vlSelf->p__DOT__r_jmp_pc 
                                            = vlSelf->p__DOT__r_rcsr;
                                    } else if ((0x105U 
                                                != (IData)(vlSelf->p__DOT__r_funct12))) {
                                        if ((9U == (IData)(vlSelf->p__DOT__r_funct7))) {
                                            vlSelf->p__DOT__r_tkn = 0U;
                                        }
                                    }
                                }
                            } else {
                                vlSelf->p__DOT__r_wb_data_csr 
                                    = vlSelf->p__DOT__w_alu_c_rslt;
                            }
                        } else {
                            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                            vlSelf->p__DOT__r_tkn = 0U;
                            vlSelf->p__DOT__r_jmp_pc = 0U;
                            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                      32,(IData)(vlSelf->w_mtime),
                                      32,vlSelf->w_pc,
                                      7,(IData)(vlSelf->p__DOT__r_opcode),
                                      32,vlSelf->w_ir,
                                      32,vlSelf->p__DOT__mhartid);
                            VL_FINISH_MT("rvcorem.v", 389, "");
                        }
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else if ((8U & (IData)(vlSelf->p__DOT__r_opcode))) {
                    if (VL_LIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                            if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                                vlSelf->p__DOT__r_tkn = 1U;
                                vlSelf->p__DOT__r_wb_data 
                                    = ((IData)(vlSelf->p__DOT__r_cinsn)
                                        ? ((IData)(2U) 
                                           + vlSelf->w_pc)
                                        : ((IData)(4U) 
                                           + vlSelf->w_pc));
                                vlSelf->p__DOT__r_jmp_pc 
                                    = (vlSelf->w_pc 
                                       + vlSelf->p__DOT__r_imm);
                            } else {
                                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                                vlSelf->p__DOT__r_tkn = 0U;
                                vlSelf->p__DOT__r_jmp_pc = 0U;
                                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                          32,(IData)(vlSelf->w_mtime),
                                          32,vlSelf->w_pc,
                                          7,(IData)(vlSelf->p__DOT__r_opcode),
                                          32,vlSelf->w_ir,
                                          32,vlSelf->p__DOT__mhartid);
                                VL_FINISH_MT("rvcorem.v", 389, "");
                            }
                        } else {
                            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                            vlSelf->p__DOT__r_tkn = 0U;
                            vlSelf->p__DOT__r_jmp_pc = 0U;
                            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                      32,(IData)(vlSelf->w_mtime),
                                      32,vlSelf->w_pc,
                                      7,(IData)(vlSelf->p__DOT__r_opcode),
                                      32,vlSelf->w_ir,
                                      32,vlSelf->p__DOT__mhartid);
                            VL_FINISH_MT("rvcorem.v", 389, "");
                        }
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else if ((4U & (IData)(vlSelf->p__DOT__r_opcode))) {
                    if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                            vlSelf->p__DOT__r_tkn = 1U;
                            vlSelf->p__DOT__r_wb_data 
                                = ((IData)(vlSelf->p__DOT__r_cinsn)
                                    ? ((IData)(2U) 
                                       + vlSelf->w_pc)
                                    : ((IData)(4U) 
                                       + vlSelf->w_pc));
                            vlSelf->p__DOT__r_jmp_pc 
                                = (vlSelf->p__DOT__r_rrs1 
                                   + vlSelf->p__DOT__r_imm);
                        } else {
                            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                            vlSelf->p__DOT__r_tkn = 0U;
                            vlSelf->p__DOT__r_jmp_pc = 0U;
                            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                      32,(IData)(vlSelf->w_mtime),
                                      32,vlSelf->w_pc,
                                      7,(IData)(vlSelf->p__DOT__r_opcode),
                                      32,vlSelf->w_ir,
                                      32,vlSelf->p__DOT__mhartid);
                            VL_FINISH_MT("rvcorem.v", 389, "");
                        }
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        vlSelf->p__DOT__r_tkn = vlSelf->p__DOT__w_alu_b_rslt;
                        vlSelf->p__DOT__r_jmp_pc = 
                            (vlSelf->w_pc + vlSelf->p__DOT__r_imm);
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            }
        } else if ((0x20U & (IData)(vlSelf->p__DOT__r_opcode))) {
            if ((0x10U & (IData)(vlSelf->p__DOT__r_opcode))) {
                if (VL_UNLIKELY((8U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                } else if ((4U & (IData)(vlSelf->p__DOT__r_opcode))) {
                    if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                            vlSelf->p__DOT__r_wb_data 
                                = vlSelf->p__DOT__r_imm;
                        } else {
                            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                            vlSelf->p__DOT__r_tkn = 0U;
                            vlSelf->p__DOT__r_jmp_pc = 0U;
                            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                      32,(IData)(vlSelf->w_mtime),
                                      32,vlSelf->w_pc,
                                      7,(IData)(vlSelf->p__DOT__r_opcode),
                                      32,vlSelf->w_ir,
                                      32,vlSelf->p__DOT__mhartid);
                            VL_FINISH_MT("rvcorem.v", 389, "");
                        }
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        vlSelf->p__DOT__r_wb_data = vlSelf->p__DOT__w_alu_im_rslt;
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else if ((8U & (IData)(vlSelf->p__DOT__r_opcode))) {
                if (VL_LIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                            if (vlSelf->p__DOT__r_op_AMO_SC) {
                                vlSelf->p__DOT__r_wb_data 
                                    = (1U & (~ ((vlSelf->p__DOT__r_rrs1 
                                                 == vlSelf->w_load_res) 
                                                & (IData)(vlSelf->w_reserved))));
                            }
                        } else {
                            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                            vlSelf->p__DOT__r_tkn = 0U;
                            vlSelf->p__DOT__r_jmp_pc = 0U;
                            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                      32,(IData)(vlSelf->w_mtime),
                                      32,vlSelf->w_pc,
                                      7,(IData)(vlSelf->p__DOT__r_opcode),
                                      32,vlSelf->w_ir,
                                      32,vlSelf->p__DOT__mhartid);
                            VL_FINISH_MT("rvcorem.v", 389, "");
                        }
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else if (VL_UNLIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->p__DOT__r_opcode))))) {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            }
        } else if ((0x10U & (IData)(vlSelf->p__DOT__r_opcode))) {
            if (VL_UNLIKELY((8U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            } else if ((4U & (IData)(vlSelf->p__DOT__r_opcode))) {
                if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                        vlSelf->p__DOT__r_wb_data = 
                            (vlSelf->w_pc + vlSelf->p__DOT__r_imm);
                    } else {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                if (VL_LIKELY((1U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    vlSelf->p__DOT__r_wb_data = vlSelf->p__DOT__w_alu_im_rslt;
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            }
        } else if ((8U & (IData)(vlSelf->p__DOT__r_opcode))) {
            if (VL_LIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
                    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->p__DOT__r_opcode))))) {
                        VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                        vlSelf->p__DOT__r_tkn = 0U;
                        vlSelf->p__DOT__r_jmp_pc = 0U;
                        VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                                  32,(IData)(vlSelf->w_mtime),
                                  32,vlSelf->w_pc,7,
                                  (IData)(vlSelf->p__DOT__r_opcode),
                                  32,vlSelf->w_ir,32,
                                  vlSelf->p__DOT__mhartid);
                        VL_FINISH_MT("rvcorem.v", 389, "");
                    }
                } else {
                    VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                    vlSelf->p__DOT__r_tkn = 0U;
                    vlSelf->p__DOT__r_jmp_pc = 0U;
                    VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                              32,(IData)(vlSelf->w_mtime),
                              32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                              32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                    VL_FINISH_MT("rvcorem.v", 389, "");
                }
            } else {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            }
        } else if (VL_UNLIKELY((4U & (IData)(vlSelf->p__DOT__r_opcode)))) {
            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
            vlSelf->p__DOT__r_tkn = 0U;
            vlSelf->p__DOT__r_jmp_pc = 0U;
            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                      32,(IData)(vlSelf->w_mtime),32,
                      vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                      32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
            VL_FINISH_MT("rvcorem.v", 389, "");
        } else if (VL_LIKELY((2U & (IData)(vlSelf->p__DOT__r_opcode)))) {
            if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->p__DOT__r_opcode))))) {
                VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
                vlSelf->p__DOT__r_tkn = 0U;
                vlSelf->p__DOT__r_jmp_pc = 0U;
                VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                          32,(IData)(vlSelf->w_mtime),
                          32,vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                          32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
                VL_FINISH_MT("rvcorem.v", 389, "");
            }
        } else {
            VL_WRITEF("UNKNOWN OPCODE DETECT!!\n");
            vlSelf->p__DOT__r_tkn = 0U;
            vlSelf->p__DOT__r_jmp_pc = 0U;
            VL_WRITEF("TC:%08x PC:%08x OPCODE=%7b, ir=%8x hartid=%x\nSimulation Stopped...\n",
                      32,(IData)(vlSelf->w_mtime),32,
                      vlSelf->w_pc,7,(IData)(vlSelf->p__DOT__r_opcode),
                      32,vlSelf->w_ir,32,vlSelf->p__DOT__mhartid);
            VL_FINISH_MT("rvcorem.v", 389, "");
        }
    }
    if ((4U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_rcsr = vlSelf->p__DOT__r_rcsr_t;
    }
    if ((3U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_imm = vlSelf->p__DOT__w_imm;
        vlSelf->p__DOT__r_rrs1 = vlSelf->p__DOT__w_rrs1;
        vlSelf->p__DOT__r_funct7 = (vlSelf->w_ir >> 0x19U);
        vlSelf->p__DOT__r_opcode = (0x7fU & vlSelf->w_ir);
        vlSelf->p__DOT__r_op_AMO_SC = (3U == (vlSelf->w_ir 
                                              >> 0x1bU));
        vlSelf->p__DOT__r_funct12 = (vlSelf->w_ir >> 0x14U);
        vlSelf->p__DOT__r_funct3 = (7U & (vlSelf->w_ir 
                                          >> 0xcU));
    }
    if ((2U == (IData)(vlSelf->w_state))) {
        vlSelf->p__DOT__r_cinsn = vlSelf->p__DOT__w_cinsn;
        vlSelf->w_ir = vlSelf->p__DOT__w_ir;
    }
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_divisor 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in2;
    vlSelf->p__DOT__ALU_B__DOT__w_sin2 = vlSelf->p__DOT__ALU_IM__DOT__w_sin2;
    vlSelf->p__DOT__ALU_A__DOT__w_sin1 = vlSelf->p__DOT__w_sin2;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_inst_r_addr;
    vlSelf->mmu__DOT__w_tlb_inst_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_inst_r__DOT__w_ridx)));
    vlSelf->w_load_res = __Vdly__w_load_res;
    vlSelf->w_reserved = __Vdly__w_reserved;
    vlSelf->w_pagefault = ((IData)(vlSelf->mmu__DOT__page_walk_fail)
                            ? ((IData)(vlSelf->mmu__DOT__w_iscode)
                                ? 0xcU : ((IData)(vlSelf->mmu__DOT__w_isread)
                                           ? 0xdU : 0xfU))
                            : 0xffffffffU);
    vlSelf->w_pc = __Vdly__w_pc;
    vlSelf->p__DOT__priv = __Vdly__p__DOT__priv;
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_inst_r_oe;
    vlSelf->p__DOT__r_halt = vlSelf->w_halt;
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
    vlSelf->w_data_addr = vlSelf->p__DOT__r_mem_addr;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag = (vlSelf->p__DOT__r_mem_addr 
                                                 >> 0xeU);
    vlSelf->mmu__DOT__v_addr = ((IData)(vlSelf->mmu__DOT__w_iscode)
                                 ? vlSelf->p__DOT__r_insn_addr
                                 : vlSelf->p__DOT__r_mem_addr);
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx = (3U 
                                                 & (vlSelf->p__DOT__r_mem_addr 
                                                    >> 0xcU));
    vlSelf->p__DOT__load_res = vlSelf->w_load_res;
    vlSelf->p__DOT__reserved = vlSelf->w_reserved;
    vlSelf->mmu__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->p__DOT__w_pagefault = vlSelf->w_pagefault;
    vlSelf->mmu__DOT__w_pc = vlSelf->w_pc;
    vlSelf->p__DOT__pc = vlSelf->w_pc;
    vlSelf->p__DOT__w_vadr2 = ((IData)(2U) + vlSelf->w_pc);
    vlSelf->p__DOT__w_vadr1 = (0xfffffffcU & vlSelf->w_pc);
    vlSelf->p__DOT__w_core_pc = vlSelf->w_pc;
    vlSelf->p__DOT__w_nalign4 = (7U == (7U & (vlSelf->w_pc 
                                              >> 1U)));
    vlSelf->p__DOT__w_sstatus = ((0xfff21eccU & vlSelf->p__DOT__mstatus) 
                                 | (0xde133U & vlSelf->p__DOT__r_wb_data_csr));
    vlSelf->w_priv = vlSelf->p__DOT__priv;
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
    vlSelf->p__DOT__w_take_int = ((5U != vlSelf->p__DOT__irq_num) 
                                  | ((~ (IData)(vlSelf->p__DOT__r_op_ECALL)) 
                                     & ((~ (IData)(vlSelf->p__DOT__r_op_SRET)) 
                                        & (1U >= (IData)(vlSelf->p__DOT__priv)))));
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
    mmu__DOT____VdfgTmp_h5ee52748__0 = (1U & ((~ (vlSelf->p__DOT__satp 
                                                  >> 0x1fU)) 
                                              | (3U 
                                                 == (IData)(vlSelf->p__DOT__priv))));
    vlSelf->mmu__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->p__DOT__w_data_addr = vlSelf->w_data_addr;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_wtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_rtag = vlSelf->mmu__DOT__TLB_data_r__DOT__w_rtag;
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
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_widx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_ridx = vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx;
    mmu__DOT__TLB_data_r__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_r__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    mmu__DOT__TLB_data_w__DOT____VdfgTmp_h859f30cf__0 
        = vlSelf->mmu__DOT__TLB_data_w__DOT__mem[vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx];
    vlSelf->p__DOT__w_usestate = ((~ (IData)(vlSelf->p__DOT__r_ir16_v)) 
                                  & (IData)(vlSelf->p__DOT__w_nalign4));
    vlSelf->p__DOT__cause = ((0xffffffffU != vlSelf->p__DOT__pending_exception)
                              ? vlSelf->p__DOT__pending_exception
                              : (0x80000000U | vlSelf->p__DOT__irq_num));
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
    vlSelf->mmu__DOT__w_priv = vlSelf->w_priv;
    vlSelf->p__DOT__w_priv = vlSelf->w_priv;
    mmu__DOT____VdfgTmp_h8d9b33e2__0 = ((IData)(vlSelf->mmu__DOT__L1_success) 
                                        & (0U != (IData)(vlSelf->mmu__DOT__L1_xwr)));
    vlSelf->mmu__DOT__w_insn_paddr = ((IData)(mmu__DOT____VdfgTmp_h5ee52748__0)
                                       ? vlSelf->p__DOT__r_insn_addr
                                       : vlSelf->mmu__DOT__r_tlb_addr);
    vlSelf->mmu__DOT__w_use_tlb = ((0U == (IData)(vlSelf->mmu__DOT__r_mc_mode)) 
                                   & ((~ (IData)(mmu__DOT____VdfgTmp_h5ee52748__0)) 
                                      & ((IData)(mmu__DOT____VdfgTmp_hdc3ed8a3__0) 
                                         | (IData)(vlSelf->mmu__DOT__w_iswrite))));
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
    if (mmu__DOT____VdfgTmp_h8d9b33e2__0) {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L1_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L1_pte_addr;
    } else {
        vlSelf->mmu__DOT__w_pte_wdata = vlSelf->mmu__DOT__L0_pte_write;
        vlSelf->mmu__DOT__w_pte_waddr = vlSelf->mmu__DOT__L0_pte_addr;
    }
    vlSelf->mmu__DOT__r_tlb_pte_addr = ((0U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                         ? vlSelf->mmu__DOT__L1_pte_addr
                                         : ((2U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                             ? vlSelf->mmu__DOT__L0_pte_addr
                                             : ((5U 
                                                 == (IData)(vlSelf->mmu__DOT__r_pw_state))
                                                 ? vlSelf->mmu__DOT__w_pte_waddr
                                                 : 0U)));
    vlSelf->mmu__DOT__w_pte_we = ((IData)(mmu__DOT____VdfgTmp_h1a37559d__0) 
                                  & (((IData)(mmu__DOT____VdfgTmp_h8d9b33e2__0) 
                                      & (IData)(vlSelf->mmu__DOT__L1_write)) 
                                     | ((IData)(vlSelf->mmu__DOT__L0_success) 
                                        & ((0U != (IData)(vlSelf->mmu__DOT__L0_xwr)) 
                                           & (IData)(vlSelf->mmu__DOT__L0_write)))));
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
    vlSelf->w_tlb_busy = ((6U != (IData)(vlSelf->mmu__DOT__r_pw_state)) 
                          & (IData)(vlSelf->mmu__DOT__w_use_tlb));
    vlSelf->p__DOT__ALU_C__DOT__w_imm = vlSelf->p__DOT__r_imm;
    vlSelf->p__DOT__ALU_C__DOT__w_rcsr = vlSelf->p__DOT__r_rcsr;
    vlSelf->p__DOT__ALU_B__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__ALU_C__DOT__w_rrs1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__w_mul_UU = ((QData)((IData)(vlSelf->p__DOT__r_rrs1)) 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->p__DOT__ALU_IM__DOT__w_in1 = vlSelf->p__DOT__r_rrs1;
    vlSelf->p__DOT__w_mem_addr = (((IData)(vlSelf->p__DOT__r_op_LOAD) 
                                   | (IData)(vlSelf->p__DOT__r_op_STORE))
                                   ? (vlSelf->p__DOT__r_imm 
                                      + vlSelf->p__DOT__r_rrs1)
                                   : ((IData)(vlSelf->p__DOT__r_op_AMO)
                                       ? vlSelf->p__DOT__r_rrs1
                                       : 0U));
    p__DOT____VdfgTmp_hc363607f__0 = (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelf->p__DOT__r_rrs1 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs1)));
    vlSelf->p__DOT__w_sin1 = vlSelf->p__DOT__r_rrs1;
    p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0 
        = VL_LTS_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2);
    vlSelf->w_hart_sc = vlSelf->p__DOT__r_op_AMO_SC;
    vlSelf->p__DOT____VdfgTmp_h8573667a__0 = ((~ (IData)(vlSelf->p__DOT__r_op_AMO_SC)) 
                                              & (IData)(vlSelf->p__DOT__r_op_AMO));
    vlSelf->p__DOT__w_data_t = ((0x300U == (IData)(vlSelf->p__DOT__r_funct12))
                                 ? vlSelf->p__DOT__r_wb_data_csr
                                 : vlSelf->p__DOT__w_sstatus);
    vlSelf->p__DOT__ALU_IM__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_B__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__ALU_C__DOT__w_funct3 = vlSelf->p__DOT__r_funct3;
    vlSelf->p__DOT__w_executing_wfi = ((0x73U == (IData)(vlSelf->p__DOT__r_opcode)) 
                                       & ((0U == (IData)(vlSelf->p__DOT__r_funct3)) 
                                          & (0x105U 
                                             == (IData)(vlSelf->p__DOT__r_funct12))));
    if ((4U & (IData)(vlSelf->p__DOT__r_funct3))) {
        if ((2U & (IData)(vlSelf->p__DOT__r_funct3))) {
            if ((1U & (IData)(vlSelf->p__DOT__r_funct3))) {
                vlSelf->p__DOT__w_alu_c_rslt = (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_imm));
                vlSelf->p__DOT__w_alu_b_rslt = (vlSelf->p__DOT__r_rrs1 
                                                >= vlSelf->p__DOT__r_alu_in2);
            } else {
                vlSelf->p__DOT__w_alu_c_rslt = (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_imm);
                vlSelf->p__DOT__w_alu_b_rslt = (vlSelf->p__DOT__r_rrs1 
                                                < vlSelf->p__DOT__r_alu_in2);
            }
        } else if ((1U & (IData)(vlSelf->p__DOT__r_funct3))) {
            vlSelf->p__DOT__w_alu_c_rslt = vlSelf->p__DOT__r_imm;
            vlSelf->p__DOT__w_alu_b_rslt = VL_GTES_III(32, vlSelf->p__DOT__r_rrs1, vlSelf->p__DOT__r_alu_in2);
        } else {
            vlSelf->p__DOT__w_alu_c_rslt = 0U;
            vlSelf->p__DOT__w_alu_b_rslt = p__DOT__ALU_B__DOT____VdfgExtracted_h2e4ff39a__0;
        }
    } else {
        vlSelf->p__DOT__w_alu_c_rslt = ((2U & (IData)(vlSelf->p__DOT__r_funct3))
                                         ? ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? (vlSelf->p__DOT__r_rcsr 
                                                & (~ vlSelf->p__DOT__r_rrs1))
                                             : (vlSelf->p__DOT__r_rcsr 
                                                | vlSelf->p__DOT__r_rrs1))
                                         : ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                             ? vlSelf->p__DOT__r_rrs1
                                             : 0U));
        vlSelf->p__DOT__w_alu_b_rslt = ((~ ((IData)(vlSelf->p__DOT__r_funct3) 
                                            >> 1U)) 
                                        & ((1U & (IData)(vlSelf->p__DOT__r_funct3))
                                            ? (vlSelf->p__DOT__r_rrs1 
                                               != vlSelf->p__DOT__r_alu_in2)
                                            : (vlSelf->p__DOT__r_rrs1 
                                               == vlSelf->p__DOT__r_alu_in2)));
    }
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
    vlSelf->p__DOT__ALU_IM__DOT__w_div_signed = ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | (6U 
                                                    == (IData)(vlSelf->p__DOT__r_funct3)));
    vlSelf->p__DOT__ALU_IM__DOT__w_div_req = ((IData)(vlSelf->p__DOT__r_alu_f7) 
                                              & ((4U 
                                                  == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                 | ((5U 
                                                     == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                    | ((6U 
                                                        == (IData)(vlSelf->p__DOT__r_funct3)) 
                                                       | (7U 
                                                          == (IData)(vlSelf->p__DOT__r_funct3))))));
    vlSelf->p__DOT__w_csr_we = ((IData)(vlSelf->p__DOT__r_op_SYS) 
                                & (0U != (IData)(vlSelf->p__DOT__r_funct3)));
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
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_r_addr;
    vlSelf->mmu__DOT__w_tlb_data_r_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_odata = vlSelf->mmu__DOT__w_tlb_data_w_addr;
    vlSelf->mmu__DOT__w_tlb_data_w_oe = ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__w_tagmatch) 
                                         & ((IData)(vlSelf->mmu__DOT__TLB_data_w__DOT__r_valid) 
                                            >> (IData)(vlSelf->mmu__DOT__TLB_data_r__DOT__w_ridx)));
    vlSelf->w_dram_wdata = ((5U == (IData)(vlSelf->mmu__DOT__r_pw_state))
                             ? vlSelf->mmu__DOT__w_pte_wdata
                             : vlSelf->mmu__DOT__w_mem_wdata);
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
    vlSelf->mmu__DOT__w_tlb_busy = vlSelf->w_tlb_busy;
    vlSelf->mmu__DOT__w_dram_we = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                   & ((IData)(vlSelf->p__DOT__r_data_we) 
                                      & ((8U == (IData)(vlSelf->mmu__DOT__w_dev)) 
                                         | (0U == (IData)(vlSelf->mmu__DOT__w_dev)))));
    mmu__DOT____VdfgTmp_h1f4b0050__0 = ((~ (IData)(vlSelf->w_tlb_busy)) 
                                        & (IData)(vlSelf->mmu__DOT__w_iscode));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_dividend 
        = vlSelf->p__DOT__ALU_IM__DOT__w_in1;
    vlSelf->p__DOT__w_mul_SS = (p__DOT____VdfgTmp_hc363607f__0 
                                * (((QData)((IData)(
                                                    (- (IData)(
                                                               (vlSelf->p__DOT__r_rrs2 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(vlSelf->p__DOT__r_rrs2))));
    vlSelf->p__DOT__w_mul_SU = (p__DOT____VdfgTmp_hc363607f__0 
                                * (QData)((IData)(vlSelf->p__DOT__r_rrs2)));
    vlSelf->p__DOT__ALU_IM__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__ALU_B__DOT__w_sin1 = vlSelf->p__DOT__w_sin1;
    vlSelf->p__DOT__hart_sc = vlSelf->w_hart_sc;
    vlSelf->p__DOT__w_mod = (vlSelf->p__DOT__w_data_t 
                             ^ vlSelf->p__DOT__mstatus);
    vlSelf->p__DOT__ALU_C__DOT__r_rslt = vlSelf->p__DOT__w_alu_c_rslt;
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
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_r_oe;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_oe = vlSelf->mmu__DOT__w_tlb_data_w_oe;
    vlSelf->mmu__DOT__w_tlb_hit = (((IData)(vlSelf->mmu__DOT__w_iscode) 
                                    & (IData)(vlSelf->mmu__DOT__w_tlb_inst_r_oe)) 
                                   | (((IData)(vlSelf->mmu__DOT__w_isread) 
                                       & (IData)(vlSelf->mmu__DOT__w_tlb_data_r_oe)) 
                                      | ((IData)(vlSelf->mmu__DOT__w_iswrite) 
                                         & (IData)(vlSelf->mmu__DOT__w_tlb_data_w_oe))));
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
    vlSelf->mmu__DOT__w_dram_wdata = vlSelf->w_dram_wdata;
    vlSelf->mmu__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->p__DOT__w_clint_we = vlSelf->w_clint_we;
    vlSelf->mmu__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->p__DOT__w_wmtimecmp = vlSelf->w_wmtimecmp;
    vlSelf->w_dram_we_t = ((IData)(vlSelf->mmu__DOT__w_pte_we) 
                           | (IData)(vlSelf->mmu__DOT__w_dram_we));
    vlSelf->p__DOT__ALU_B__DOT__r_rslt = vlSelf->p__DOT__w_alu_b_rslt;
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
    vlSelf->mmu__DOT__w_ir = vlSelf->w_ir;
    vlSelf->p__DOT__r_ir = vlSelf->w_ir;
    vlSelf->p__DOT__w_rs2 = (0x1fU & (vlSelf->w_ir 
                                      >> 0x14U));
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
    vlSelf->p__DOT__imm_gen0__DOT__opcode = (0x7fU 
                                             & vlSelf->w_ir);
    vlSelf->p__DOT__w_rs1 = (0x1fU & (vlSelf->w_ir 
                                      >> 0xfU));
    vlSelf->w_state = vlSelf->p__DOT__w_state;
    vlSelf->mmu__DOT__w_dram_we_t = vlSelf->w_dram_we_t;
    vlSelf->mmu__DOT__w_dram_ctrl = vlSelf->w_dram_ctrl;
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
    vlSelf->p__DOT__w_sstatus_t1 = ((0xffffffdfU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x20U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 5U)));
    vlSelf->p__DOT__w_mstatus_t1 = ((0xffffff7fU & vlSelf->p__DOT__w_mstatus_nxt) 
                                    | (0x80U & (p__DOT____VdfgTmp_h17b05525__0 
                                                << 7U)));
    vlSelf->p__DOT__w_interrupt_mask = (vlSelf->p__DOT__pending_interrupts 
                                        & vlSelf->p__DOT__enable_interrupts);
    vlSelf->p__DOT__imm_gen0__DOT__w_inst = vlSelf->p__DOT__r_ir;
    vlSelf->p__DOT__regs__DOT__w_rs2 = vlSelf->p__DOT__w_rs2;
    vlSelf->p__DOT__w_rrs2 = ((0U == (IData)(vlSelf->p__DOT__w_rs2))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs2]);
    vlSelf->p__DOT__w_core_ir = vlSelf->w_core_ir;
    vlSelf->p__DOT__w_op_priv = (IData)(((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                         & (0U == (0x7000U 
                                                   & vlSelf->w_ir))));
    vlSelf->p__DOT__w_op_csr = ((0x73U == (IData)(vlSelf->p__DOT__imm_gen0__DOT__opcode)) 
                                & (0U != (7U & (vlSelf->w_ir 
                                                >> 0xcU))));
    vlSelf->p__DOT__regs__DOT__w_rs1 = vlSelf->p__DOT__w_rs1;
    vlSelf->p__DOT__w_rrs1 = ((0U == (IData)(vlSelf->p__DOT__w_rs1))
                               ? 0U : vlSelf->p__DOT__regs__DOT__mem
                              [vlSelf->p__DOT__w_rs1]);
    vlSelf->p__DOT__imm_gen0__DOT__imm_C = vlSelf->p__DOT__w_rs1;
    vlSelf->mmu__DOT__w_dram_addr = vlSelf->w_dram_addr;
    vlSelf->mmu__DOT__w_dram_aces = ((8U == (vlSelf->w_dram_addr 
                                             >> 0x1cU)) 
                                     | ((0U == (vlSelf->w_dram_addr 
                                                >> 0x1cU)) 
                                        | (9U == (vlSelf->w_dram_addr 
                                                  >> 0x1cU))));
    vlSelf->p__DOT__ALU_IM__DOT__r_rslt = vlSelf->p__DOT__w_alu_im_rslt;
    vlSelf->p__DOT__w_sstatus_t2 = ((0xfffffeffU & vlSelf->p__DOT__w_sstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 8U));
    vlSelf->p__DOT__w_mstatus_t2 = ((0xffffe7ffU & vlSelf->p__DOT__w_mstatus_t1) 
                                    | ((IData)(vlSelf->p__DOT__r_priv_t) 
                                       << 0xbU));
    vlSelf->p__DOT__w_irq_t = (vlSelf->p__DOT__w_interrupt_mask 
                               & ((IData)(1U) + (~ vlSelf->p__DOT__w_interrupt_mask)));
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
    vlSelf->p__DOT__state = vlSelf->w_state;
    vlSelf->p__DOT__w_regfile_we = ((IData)(vlSelf->p__DOT__w_wb_r_enable) 
                                    & (9U == (IData)(vlSelf->w_state)));
    vlSelf->p__DOT__w_ex1 = (5U == (IData)(vlSelf->w_state));
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
    vlSelf->p__DOT__w_sstatus_t3 = (0xfffffffdU & vlSelf->p__DOT__w_sstatus_t2);
    vlSelf->p__DOT__w_mstatus_t3 = (0xfffffff7U & vlSelf->p__DOT__w_mstatus_t2);
    vlSelf->p__DOT__imm_gen0__DOT__r_imm = vlSelf->p__DOT__w_imm;
    vlSelf->p__DOT__regs__DOT__w_we = vlSelf->p__DOT__w_regfile_we;
    vlSelf->p__DOT__ALU_IM__DOT__w_le = vlSelf->p__DOT__w_ex1;
    vlSelf->p__DOT__w_com = (((0xffffffffU != vlSelf->p__DOT__pending_exception) 
                              | ((0xffffffffU != vlSelf->w_pagefault) 
                                 | ((IData)(vlSelf->p__DOT__w_ex1) 
                                    & (IData)(vlSelf->p__DOT__r_op_ECALL)))) 
                             & ((0xaU != (IData)(vlSelf->w_state)) 
                                & ((0xbU != (IData)(vlSelf->w_state)) 
                                   & (0U != (IData)(vlSelf->w_state)))));
    vlSelf->p__DOT__ALU_IM__DOT__w_div_init = ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                               & ((~ (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy)) 
                                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__r_div_first) 
                                                     & (IData)(vlSelf->p__DOT__w_ex1))));
    vlSelf->mmu__DOT__w_data_le = vlSelf->w_data_le;
    vlSelf->mmu__DOT__w_data_we = vlSelf->w_data_we;
    vlSelf->mmu__DOT__w_dram_le = vlSelf->w_dram_le;
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__w_div_init;
    vlSelf->p__DOT__w_ex1_busy = ((IData)(vlSelf->p__DOT__w_ex1) 
                                  & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_req) 
                                     & ((IData)(vlSelf->p__DOT__ALU_IM__DOT__w_divunit_busy) 
                                        | (IData)(vlSelf->p__DOT__ALU_IM__DOT__w_div_init))));
    vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__divcore__DOT__w_init 
        = vlSelf->p__DOT__ALU_IM__DOT__divunit__DOT__w_init;
    vlSelf->p__DOT__ALU_IM__DOT__w_busy = vlSelf->p__DOT__w_ex1_busy;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__2(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__2\n"); );
    // Body
    vlSelf->p__DOT__w_oh_load_res = vlSelf->w_oh_load_res;
    vlSelf->p__DOT__w_oh_reserved = vlSelf->w_oh_reserved;
    vlSelf->p__DOT__w_oh_pc = vlSelf->w_oh_pc;
    vlSelf->p__DOT__w_oh_sc = vlSelf->w_oh_sc;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__3(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__3\n"); );
    // Body
    vlSelf->p__DOT__w_mem_rdata = vlSelf->w_data_data;
    vlSelf->p__DOT__ALU_A__DOT__w_in2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__ALU_A__DOT__w_sin2 = vlSelf->p__DOT__w_mem_rdata;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__4(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__4\n"); );
    // Body
    vlSelf->mmu__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_grant = vlSelf->w_grant;
    vlSelf->mmu__DOT__w_dram_busy = vlSelf->w_dram_busy;
    vlSelf->mmu__DOT__w_data_busy = vlSelf->w_data_busy;
    vlSelf->mmu__DOT__w_dram_odata = vlSelf->w_dram_odata;
    vlSelf->w_insn_data = vlSelf->w_dram_odata;
    vlSelf->p__DOT__w_plic_we = vlSelf->w_plic_we;
    vlSelf->p__DOT__w_wmip = vlSelf->w_wmip;
    vlSelf->p__DOT__w_ipi = vlSelf->w_ipi;
    vlSelf->p__DOT__w_mtime = vlSelf->w_mtime;
    vlSelf->mmu__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__w_insn_data = vlSelf->w_insn_data;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core0__0\n"); );
    // Init
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
    // Body
    vlSelf->p__DOT__w_wb_r_data = ((IData)(vlSelf->p__DOT__r_op_LOAD)
                                    ? vlSelf->w_data_data
                                    : ((IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)
                                        ? vlSelf->p__DOT__r_mem_rdata
                                        : ((IData)(vlSelf->p__DOT__w_csr_we)
                                            ? vlSelf->p__DOT__r_rcsr
                                            : vlSelf->p__DOT__r_wb_data)));
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
    vlSelf->w_proc_busy = (((IData)(vlSelf->mmu__DOT__w_use_tlb) 
                            & (7U > (IData)(vlSelf->mmu__DOT__r_pw_state))) 
                           | ((IData)(vlSelf->w_dram_busy) 
                              | (0U != (IData)(vlSelf->w_data_busy))));
    vlSelf->p__DOT__w_ir_org = ((3U == (IData)(vlSelf->p__DOT__r_if_state))
                                 ? ((IData)(vlSelf->p__DOT__r_ir16_v)
                                     ? ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_ir16))
                                     : ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_if_irl)))
                                 : vlSelf->w_dram_odata);
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
    vlSelf->p__DOT__regs__DOT__w_wdata = vlSelf->p__DOT__w_wb_r_data;
    vlSelf->p__DOT__ALU_A__DOT__r_rslt = vlSelf->p__DOT__w_alu_a_rslt;
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
    vlSelf->p__DOT__w_cinsn = (3U != (3U & vlSelf->p__DOT__w_ir_org));
    vlSelf->w_tlb_flush = vlSelf->p__DOT__r_tlb_flush;
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
    vlSelf->p__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
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
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->p__DOT__decomp0__DOT__r_iw = vlSelf->p__DOT__w_ir_t;
    vlSelf->p__DOT__w_nop = ((0x53U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                             | ((7U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                                | (0x27U == (0x7fU 
                                             & vlSelf->p__DOT__w_ir_t))));
    vlSelf->p__DOT__w_ir = ((IData)(vlSelf->p__DOT__w_nop)
                             ? 0x13U : ((IData)(vlSelf->p__DOT__w_cinsn)
                                         ? vlSelf->p__DOT__w_ir_t
                                         : vlSelf->p__DOT__w_ir_org));
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__2(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__2\n"); );
    // Body
    vlSelf->p__DOT__w_mem_rdata = vlSelf->w_data_data;
    vlSelf->mmu__DOT__w_grant = vlSelf->w_grant;
    vlSelf->p__DOT__w_grant = vlSelf->w_grant;
    vlSelf->mmu__DOT__w_dram_busy = vlSelf->w_dram_busy;
    vlSelf->mmu__DOT__w_data_busy = vlSelf->w_data_busy;
    vlSelf->mmu__DOT__w_dram_odata = vlSelf->w_dram_odata;
    vlSelf->w_insn_data = vlSelf->w_dram_odata;
    vlSelf->p__DOT__w_plic_we = vlSelf->w_plic_we;
    vlSelf->p__DOT__w_wmip = vlSelf->w_wmip;
    vlSelf->p__DOT__w_ipi = vlSelf->w_ipi;
    vlSelf->p__DOT__w_mtime = vlSelf->w_mtime;
    vlSelf->p__DOT__ALU_A__DOT__w_in2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->p__DOT__ALU_A__DOT__w_sin2 = vlSelf->p__DOT__w_mem_rdata;
    vlSelf->mmu__DOT__w_insn_data = vlSelf->w_insn_data;
    vlSelf->p__DOT__w_insn_data = vlSelf->w_insn_data;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__3(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__3\n"); );
    // Body
    vlSelf->p__DOT__w_oh_load_res = vlSelf->w_oh_load_res;
    vlSelf->p__DOT__w_oh_sc = vlSelf->w_oh_sc;
    vlSelf->p__DOT__w_oh_reserved = vlSelf->w_oh_reserved;
    vlSelf->p__DOT__w_oh_pc = vlSelf->w_oh_pc;
}

VL_INLINE_OPT void Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core1__0(Vm_topsim_m_cpummu* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core1__0\n"); );
    // Init
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
    // Body
    vlSelf->p__DOT__w_wb_r_data = ((IData)(vlSelf->p__DOT__r_op_LOAD)
                                    ? vlSelf->w_data_data
                                    : ((IData)(vlSelf->p__DOT____VdfgTmp_h8573667a__0)
                                        ? vlSelf->p__DOT__r_mem_rdata
                                        : ((IData)(vlSelf->p__DOT__w_csr_we)
                                            ? vlSelf->p__DOT__r_rcsr
                                            : vlSelf->p__DOT__r_wb_data)));
    vlSelf->w_proc_busy = (((IData)(vlSelf->mmu__DOT__w_use_tlb) 
                            & (7U > (IData)(vlSelf->mmu__DOT__r_pw_state))) 
                           | ((IData)(vlSelf->w_dram_busy) 
                              | (0U != (IData)(vlSelf->w_data_busy))));
    vlSelf->p__DOT__w_ir_org = ((3U == (IData)(vlSelf->p__DOT__r_if_state))
                                 ? ((IData)(vlSelf->p__DOT__r_ir16_v)
                                     ? ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_ir16))
                                     : ((vlSelf->w_dram_odata 
                                         << 0x10U) 
                                        | (IData)(vlSelf->p__DOT__r_if_irl)))
                                 : vlSelf->w_dram_odata);
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
    vlSelf->p__DOT__regs__DOT__w_wdata = vlSelf->p__DOT__w_wb_r_data;
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
    vlSelf->p__DOT__w_cinsn = (3U != (3U & vlSelf->p__DOT__w_ir_org));
    vlSelf->p__DOT__ALU_A__DOT__r_rslt = vlSelf->p__DOT__w_alu_a_rslt;
    vlSelf->w_tlb_flush = vlSelf->p__DOT__r_tlb_flush;
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
    vlSelf->p__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
    vlSelf->mmu__DOT__w_tlb_flush = vlSelf->w_tlb_flush;
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
    vlSelf->mmu__DOT__TLB_inst_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_r__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->mmu__DOT__TLB_data_w__DOT__w_flush = vlSelf->mmu__DOT__w_tlb_flush;
    vlSelf->p__DOT__decomp0__DOT__r_iw = vlSelf->p__DOT__w_ir_t;
    vlSelf->p__DOT__w_nop = ((0x53U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                             | ((7U == (0x7fU & vlSelf->p__DOT__w_ir_t)) 
                                | (0x27U == (0x7fU 
                                             & vlSelf->p__DOT__w_ir_t))));
    vlSelf->p__DOT__w_ir = ((IData)(vlSelf->p__DOT__w_nop)
                             ? 0x13U : ((IData)(vlSelf->p__DOT__w_cinsn)
                                         ? vlSelf->p__DOT__w_ir_t
                                         : vlSelf->p__DOT__w_ir_org));
}
