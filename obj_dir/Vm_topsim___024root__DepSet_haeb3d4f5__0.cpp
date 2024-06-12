// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim___024root.h"

void Vm_topsim___024root___eval_act(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__3(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__3\n"); );
    // Body
    if ((vlSelf->m_topsim__DOT__old_w_mtime != vlSelf->m_topsim__DOT__w_mtime)) {
        vlSelf->m_topsim__DOT__old_w_mtime = vlSelf->m_topsim__DOT__w_mtime;
        if (VL_UNLIKELY((0ULL == VL_MODDIV_QQQ(64, vlSelf->m_topsim__DOT__w_mtime, 0x989680ULL)))) {
            VL_WRITEF("w_mtime=%20# ENABLE_TIMER=          1330000000\n",
                      64,vlSelf->m_topsim__DOT__w_mtime);
        }
    }
}

VL_INLINE_OPT void Vm_topsim___024root___nba_comb__TOP__0(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_comb__TOP__0\n"); );
    // Body
    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__w_tlb_req = vlSelf->m_topsim__DOT__bus_tlb_req0;
        vlSelf->m_topsim__DOT__w_mip = vlSelf->m_topsim__DOT__bus_mip0;
        vlSelf->m_topsim__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__bus_tlb_busy0;
        vlSelf->m_topsim__DOT__ba__DOT__w_core_ir = vlSelf->m_topsim__DOT__bus_core_ir_0;
        vlSelf->m_topsim__DOT__w_bus_cpustate = vlSelf->m_topsim__DOT__bus_cpustate0;
    } else {
        vlSelf->m_topsim__DOT__w_tlb_req = vlSelf->m_topsim__DOT__bus_tlb_req1;
        vlSelf->m_topsim__DOT__w_mip = vlSelf->m_topsim__DOT__bus_mip1;
        vlSelf->m_topsim__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__bus_tlb_busy1;
        vlSelf->m_topsim__DOT__ba__DOT__w_core_ir = vlSelf->m_topsim__DOT__bus_core_ir_1;
        vlSelf->m_topsim__DOT__w_bus_cpustate = vlSelf->m_topsim__DOT__bus_cpustate1;
    }
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_req = vlSelf->m_topsim__DOT__w_tlb_req;
    vlSelf->m_topsim__DOT__w_isread = (0U == (IData)(vlSelf->m_topsim__DOT__w_tlb_req));
    vlSelf->m_topsim__DOT__w_iswrite = (1U == (IData)(vlSelf->m_topsim__DOT__w_tlb_req));
    vlSelf->m_topsim__DOT__ba__DOT__w_mip = vlSelf->m_topsim__DOT__w_mip;
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__w_tlb_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_bus_cpustate 
        = vlSelf->m_topsim__DOT__w_bus_cpustate;
    vlSelf->m_topsim__DOT__ba__DOT__w_bus_cpustate 
        = vlSelf->m_topsim__DOT__w_bus_cpustate;
}

void Vm_topsim___024root___eval_triggers__ico(Vm_topsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__ico(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG
void Vm_topsim___024root___eval_ico(Vm_topsim___024root* vlSelf);
void Vm_topsim___024root___eval_triggers__act(Vm_topsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__act(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__nba(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG
void Vm_topsim___024root___eval_nba(Vm_topsim___024root* vlSelf);

void Vm_topsim___024root___eval(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<4> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vm_topsim___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if ((0x64U < vlSelf->__VicoIterCount)) {
#ifdef VL_DEBUG
                Vm_topsim___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("maintn.v", 65, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vm_topsim___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vm_topsim___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if ((0x64U < vlSelf->__VactIterCount)) {
#ifdef VL_DEBUG
                    Vm_topsim___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("maintn.v", 65, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vm_topsim___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if ((0x64U < __VnbaIterCount)) {
#ifdef VL_DEBUG
                Vm_topsim___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("maintn.v", 65, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vm_topsim___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vm_topsim___024root___eval_debug_assertions(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((vlSelf->RST_X & 0xfeU))) {
        Verilated::overWidthError("RST_X");}
}
#endif  // VL_DEBUG
