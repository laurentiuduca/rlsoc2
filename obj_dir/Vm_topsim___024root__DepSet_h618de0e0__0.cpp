// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim__Syms.h"
#include "Vm_topsim___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__ico(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vm_topsim___024root___eval_triggers__ico(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vm_topsim___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vm_topsim___024root___ico_sequent__TOP__0(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->m_topsim__DOT__CLK = vlSelf->CLK;
    vlSelf->m_topsim__DOT__RST_X = vlSelf->RST_X;
    vlSymsp->TOP__m_topsim__DOT__core0.RST_X = vlSelf->RST_X;
    vlSymsp->TOP__m_topsim__DOT__core1.RST_X = vlSelf->RST_X;
    vlSelf->m_topsim__DOT__pll_clk = vlSelf->CLK;
    vlSelf->m_topsim__DOT__ba__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__UartTx0__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__dram_con__DOT__rst_x = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__ploader__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__ba__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__UartTx0__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__rf__DOT__clk = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__ploader__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__dram_con__DOT__clk = vlSelf->m_topsim__DOT__pll_clk;
    vlSymsp->TOP__m_topsim__DOT__core0.CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSymsp->TOP__m_topsim__DOT__core1.CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__RST_X 
        = vlSelf->m_topsim__DOT__ploader__DOT__RST_X;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__CLK 
        = vlSelf->m_topsim__DOT__ploader__DOT__CLK;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__CLK 
        = vlSelf->m_topsim__DOT__dram_con__DOT__clk;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__CLK 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__CLK;
}

void Vm_topsim_m_cpummu___ico_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf);

void Vm_topsim___024root___eval_ico(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vm_topsim___024root___ico_sequent__TOP__0(vlSelf);
        Vm_topsim_m_cpummu___ico_sequent__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core0));
        Vm_topsim_m_cpummu___ico_sequent__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core1));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__act(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG

void Vm_topsim___024root___eval_triggers__act(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->m_topsim__DOT__pll_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__pll_clk)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->CLK) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__CLK)));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSymsp->TOP__m_topsim__DOT__core0.CLK) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core0__CLK)));
    vlSelf->__VactTriggered.at(3U) = ((IData)(vlSymsp->TOP__m_topsim__DOT__core1.CLK) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core1__CLK)));
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__pll_clk 
        = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->__Vtrigrprev__TOP__CLK = vlSelf->CLK;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core0__CLK 
        = vlSymsp->TOP__m_topsim__DOT__core0.CLK;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core1__CLK 
        = vlSymsp->TOP__m_topsim__DOT__core1.CLK;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vm_topsim___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__0(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*55:0*/ m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0;
    CData/*3:0*/ __Vdly__m_topsim__DOT__r_data_busy;
    IData/*31:0*/ __Vdly__m_topsim__DOT__r_ipi;
    CData/*4:0*/ __Vdly__m_topsim__DOT__r_consf_head;
    CData/*0:0*/ __Vdly__m_topsim__DOT__r_consf_en;
    CData/*5:0*/ __Vdly__m_topsim__DOT__r_consf_cnts;
    IData/*31:0*/ __Vdly__m_topsim__DOT__r_initaddr2;
    IData/*31:0*/ __Vdly__m_topsim__DOT__r_initaddr;
    CData/*0:0*/ __Vdly__m_topsim__DOT__r_zero_we;
    IData/*31:0*/ __Vdly__m_topsim__DOT__r_zeroaddr;
    CData/*7:0*/ __Vdly__m_topsim__DOT__ba__DOT__state;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux;
    CData/*0:0*/ __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux;
    IData/*31:0*/ __Vdly__m_topsim__DOT__ba__DOT__grant;
    IData/*31:0*/ __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum;
    CData/*0:0*/ __Vdly__m_topsim__DOT__w_tx_ready;
    SData/*8:0*/ __Vdly__m_topsim__DOT__UartTx0__DOT__cmd;
    CData/*3:0*/ __Vdly__m_topsim__DOT__UartTx0__DOT__cnt;
    IData/*31:0*/ __Vdly__m_topsim__DOT__ploader__DOT__waddr;
    SData/*11:0*/ __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start;
    CData/*3:0*/ __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_refreshcnt;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_addr;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr;
    CData/*2:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl;
    CData/*0:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_stall;
    CData/*7:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__state;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui;
    CData/*0:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__read_request;
    CData/*0:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__write_request;
    CData/*7:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__state_next;
    CData/*7:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr;
    IData/*31:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata;
    CData/*3:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask;
    CData/*7:0*/ __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt;
    IData/*22:0*/ __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0;
    IData/*22:0*/ __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1;
    IData/*22:0*/ __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2;
    IData/*22:0*/ __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3;
    // Body
    if (VL_UNLIKELY(vlSelf->m_topsim__DOT__r_finish)) {
        VL_WRITEF("FINISH!\n");
        VL_FINISH_MT("maintn.v", 412, "");
    }
    if (VL_UNLIKELY((1U > (IData)(vlSelf->m_topsim__DOT__r_init_state)))) {
        VL_WRITEF("r_init_state=%1#\n",3,vlSelf->m_topsim__DOT__r_init_state);
    }
    __Vdly__m_topsim__DOT__dram_con__DOT__r_refreshcnt 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt;
    __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start 
        = vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start;
    __Vdly__m_topsim__DOT__r_zero_we = vlSelf->m_topsim__DOT__r_zero_we;
    __Vdly__m_topsim__DOT__r_zeroaddr = vlSelf->m_topsim__DOT__r_zeroaddr;
    __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage 
        = vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage;
    __Vdly__m_topsim__DOT__r_data_busy = vlSelf->m_topsim__DOT__r_data_busy;
    __Vdly__m_topsim__DOT__ploader__DOT__waddr = vlSelf->m_topsim__DOT__ploader__DOT__waddr;
    __Vdly__m_topsim__DOT__r_initaddr = vlSelf->m_topsim__DOT__r_initaddr;
    __Vdly__m_topsim__DOT__r_initaddr2 = vlSelf->m_topsim__DOT__r_initaddr2;
    __Vdly__m_topsim__DOT__r_consf_head = vlSelf->m_topsim__DOT__r_consf_head;
    __Vdly__m_topsim__DOT__r_consf_en = vlSelf->m_topsim__DOT__r_consf_en;
    __Vdly__m_topsim__DOT__r_consf_cnts = vlSelf->m_topsim__DOT__r_consf_cnts;
    __Vdly__m_topsim__DOT__dram_con__DOT__state_next 
        = vlSelf->m_topsim__DOT__dram_con__DOT__state_next;
    __Vdly__m_topsim__DOT__dram_con__DOT__write_request 
        = vlSelf->m_topsim__DOT__dram_con__DOT__write_request;
    __Vdly__m_topsim__DOT__dram_con__DOT__read_request 
        = vlSelf->m_topsim__DOT__dram_con__DOT__read_request;
    __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui;
    __Vdly__m_topsim__DOT__dram_con__DOT__state = vlSelf->m_topsim__DOT__dram_con__DOT__state;
    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr = vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr;
    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = vlSelf->m_topsim__DOT__dram_con__DOT__r_stall;
    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl = vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl;
    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr = vlSelf->m_topsim__DOT__dram_con__DOT__r_addr;
    __Vdly__m_topsim__DOT__UartTx0__DOT__cnt = vlSelf->m_topsim__DOT__UartTx0__DOT__cnt;
    __Vdly__m_topsim__DOT__UartTx0__DOT__cmd = vlSelf->m_topsim__DOT__UartTx0__DOT__cmd;
    __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum = vlSelf->m_topsim__DOT__UartTx0__DOT__waitnum;
    __Vdly__m_topsim__DOT__w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt;
    __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask;
    __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr;
    __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state;
    __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0 = 0U;
    __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1 = 0U;
    __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2 = 0U;
    __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3 = 0U;
    __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 
        = vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux;
    __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 
        = vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0;
    __Vdly__m_topsim__DOT__ba__DOT__state = vlSelf->m_topsim__DOT__ba__DOT__state;
    __Vdly__m_topsim__DOT__ba__DOT__grant = vlSelf->m_topsim__DOT__ba__DOT__grant;
    __Vdly__m_topsim__DOT__r_ipi = vlSelf->m_topsim__DOT__r_ipi;
    if (vlSelf->m_topsim__DOT__w_file_we) {
        vlSelf->m_topsim__DOT__w_file_we = 0U;
    }
    if (VL_UNLIKELY((((IData)(vlSelf->m_topsim__DOT__rf__DOT__boot_done) 
                      & (~ (IData)(vlSelf->m_topsim__DOT__r_consf_en))) 
                     & (~ (IData)((0U != vlSelf->m_topsim__DOT__rf__DOT__wait_delay)))))) {
        vlSelf->m_topsim__DOT__rf__DOT__oldc = vlSelf->m_topsim__DOT__rf__DOT__c;
        vlSelf->m_topsim__DOT__rf__DOT__fid = VL_FOPEN_NN(
                                                          std::string{"fid.txt"}
                                                          , 
                                                          std::string{"r"});
        if (VL_UNLIKELY((0U == vlSelf->m_topsim__DOT__rf__DOT__fid))) {
            VL_WRITEF("ERROR: fid.txt not opened\n");
            VL_FINISH_MT("read_file.v", 86, "");
        }
        vlSelf->m_topsim__DOT__rf__DOT__c = (vlSelf->m_topsim__DOT__rf__DOT__fid ? fgetc(VL_CVT_I_FP(vlSelf->m_topsim__DOT__rf__DOT__fid)) : -1);
        if (VL_UNLIKELY(((vlSelf->m_topsim__DOT__rf__DOT__c 
                          != vlSelf->m_topsim__DOT__rf__DOT__oldc) 
                         & (0xffffffffU != vlSelf->m_topsim__DOT__rf__DOT__c)))) {
            VL_WRITEF("new command='%c'=%11d\n",32,
                      vlSelf->m_topsim__DOT__rf__DOT__c,
                      32,vlSelf->m_topsim__DOT__rf__DOT__c);
            vlSelf->m_topsim__DOT__w_file_we = 1U;
            vlSelf->m_topsim__DOT__rf__DOT__oldc = vlSelf->m_topsim__DOT__rf__DOT__c;
            vlSelf->m_topsim__DOT__rf__DOT__fcmd = VL_FOPEN_NN(
                                                               std::string{"fcmd.txt"}
                                                               , 
                                                               std::string{"r"});
            if (VL_UNLIKELY((0U == vlSelf->m_topsim__DOT__rf__DOT__fcmd))) {
                VL_WRITEF("ERROR: fcmd.txt not opened\n");
                VL_FINISH_MT("read_file.v", 97, "");
            }
            vlSelf->m_topsim__DOT__rf__DOT__line[0U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[1U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[2U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[3U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[4U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[5U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[6U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[7U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[8U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[9U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xaU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xbU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xcU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xdU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xeU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0xfU] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x10U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x11U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x12U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x13U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x14U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x15U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x16U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x17U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__line[0x18U] = 0U;
            vlSelf->m_topsim__DOT__rf__DOT__n = VL_FGETS_IXI(800, &(vlSelf->m_topsim__DOT__rf__DOT__line), vlSelf->m_topsim__DOT__rf__DOT__fcmd);
            VL_WRITEF("read_file.v fgets n=%11d line='%s'\n",
                      32,vlSelf->m_topsim__DOT__rf__DOT__n,
                      800,vlSelf->m_topsim__DOT__rf__DOT__line.data());
            vlSelf->m_topsim__DOT__rf__DOT__i = ((IData)(1U) 
                                                 + 
                                                 ((IData)(0x64U) 
                                                  - vlSelf->m_topsim__DOT__rf__DOT__n));
            while (VL_GTS_III(32, 0x65U, vlSelf->m_topsim__DOT__rf__DOT__i)) {
                if ((0U != ((0x31fU >= (0x3ffU & ((IData)(0x320U) 
                                                  - 
                                                  VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))
                             ? (0xffU & (((0U == (0x1fU 
                                                  & ((IData)(0x320U) 
                                                     - 
                                                     VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))
                                           ? 0U : (
                                                   vlSelf->m_topsim__DOT__rf__DOT__line[
                                                   (((IData)(7U) 
                                                     + 
                                                     (0x3ffU 
                                                      & ((IData)(0x320U) 
                                                         - 
                                                         VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x320U) 
                                                        - 
                                                        VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)))))) 
                                         | (vlSelf->m_topsim__DOT__rf__DOT__line[
                                            (0x1fU 
                                             & (((IData)(0x320U) 
                                                 - 
                                                 VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)) 
                                                >> 5U))] 
                                            >> (0x1fU 
                                                & ((IData)(0x320U) 
                                                   - 
                                                   VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))))
                             : 0U))) {
                    vlSelf->m_topsim__DOT__rf__DOT__fifo[(0x1fU 
                                                          & (vlSelf->m_topsim__DOT__rf__DOT__i 
                                                             - 
                                                             ((IData)(1U) 
                                                              + 
                                                              ((IData)(4U) 
                                                               - vlSelf->m_topsim__DOT__rf__DOT__n))))] 
                        = ((0x31fU >= (0x3ffU & ((IData)(0x320U) 
                                                 - 
                                                 VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))
                            ? (0xffU & (((0U == (0x1fU 
                                                 & ((IData)(0x320U) 
                                                    - 
                                                    VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))
                                          ? 0U : (vlSelf->m_topsim__DOT__rf__DOT__line[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x3ffU 
                                                     & ((IData)(0x320U) 
                                                        - 
                                                        VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x320U) 
                                                       - 
                                                       VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)))))) 
                                        | (vlSelf->m_topsim__DOT__rf__DOT__line[
                                           (0x1fU & 
                                            (((IData)(0x320U) 
                                              - VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i)) 
                                             >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x320U) 
                                                  - 
                                                  VL_MULS_III(32, (IData)(8U), vlSelf->m_topsim__DOT__rf__DOT__i))))))
                            : 0U);
                }
                vlSelf->m_topsim__DOT__rf__DOT__i = 
                    ((IData)(1U) + vlSelf->m_topsim__DOT__rf__DOT__i);
            }
            VL_FCLOSE_I(vlSelf->m_topsim__DOT__rf__DOT__fcmd); vlSelf->m_topsim__DOT__rf__DOT__fcmd = 0;
        }
        VL_FCLOSE_I(vlSelf->m_topsim__DOT__rf__DOT__fid); vlSelf->m_topsim__DOT__rf__DOT__fid = 0;
    }
    if ((((0x40008000U == vlSelf->m_topsim__DOT__r_mem_paddr) 
          & (IData)(vlSelf->m_topsim__DOT__r_data_we)) 
         & (2U == (vlSelf->m_topsim__DOT__w_data_wdata 
                   >> 0x10U)))) {
        vlSelf->m_topsim__DOT__r_finish = 1U;
    }
    vlSelf->m_topsim__DOT__rf__DOT__wait_delay = ((0xf4240ULL 
                                                   <= vlSelf->m_topsim__DOT__rf__DOT__wait_delay)
                                                   ? 0ULL
                                                   : 
                                                  (1ULL 
                                                   + vlSelf->m_topsim__DOT__rf__DOT__wait_delay));
    __Vdly__m_topsim__DOT__dram_con__DOT__r_refreshcnt 
        = ((0x33U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))
            ? 0U : ((IData)(1U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt));
    if ((((~ (IData)(vlSelf->m_topsim__DOT__w_dram_busy)) 
          & (~ (IData)(vlSelf->m_topsim__DOT__r_zero_done))) 
         & (IData)(vlSelf->m_topsim__DOT__calib_done))) {
        __Vdly__m_topsim__DOT__r_zero_we = 1U;
    } else if (((IData)(vlSelf->m_topsim__DOT__w_dram_busy) 
                & (IData)(vlSelf->m_topsim__DOT__r_zero_we))) {
        __Vdly__m_topsim__DOT__r_zeroaddr = ((IData)(4U) 
                                             + vlSelf->m_topsim__DOT__r_zeroaddr);
        __Vdly__m_topsim__DOT__r_zero_we = 0U;
    }
    if ((0x800000U <= vlSelf->m_topsim__DOT__r_zeroaddr)) {
        vlSelf->m_topsim__DOT__r_zero_done = 1U;
    }
    __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start 
        = ((IData)(vlSelf->RST_X) ? ((IData)(vlSelf->m_topsim__DOT__w_rxd)
                                      ? 0U : (0xfffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start))))
            : 0U);
    if (VL_UNLIKELY(((0x4f463080ULL <= vlSelf->m_topsim__DOT__w_mtime) 
                     & (~ (IData)(vlSelf->m_topsim__DOT__rf__DOT__boot_done))))) {
        VL_WRITEF("read_file.v, w_mtime=%20# consider boot_done\n",
                  64,vlSelf->m_topsim__DOT__w_mtime);
        vlSelf->m_topsim__DOT__rf__DOT__boot_done = 1U;
    }
    vlSelf->m_topsim__DOT__r_key_data = vlSelf->m_topsim__DOT__w_key_data;
    vlSelf->m_topsim__DOT__r_key_we = vlSelf->m_topsim__DOT__w_key_we;
    vlSelf->m_topsim__DOT__rf__DOT__we = vlSelf->m_topsim__DOT__w_file_we;
    if (((IData)(vlSelf->m_topsim__DOT__w_pl_init_we) 
         & (2U == (IData)(vlSelf->m_topsim__DOT__r_init_state)))) {
        __Vdly__m_topsim__DOT__r_initaddr = ((IData)(4U) 
                                             + vlSelf->m_topsim__DOT__r_initaddr);
    }
    if ((0x800000U <= vlSelf->m_topsim__DOT__r_initaddr)) {
        vlSelf->m_topsim__DOT__r_bbl_done = 1U;
    }
    if (((IData)(vlSelf->m_topsim__DOT__w_pl_init_we) 
         & (4U == (IData)(vlSelf->m_topsim__DOT__r_init_state)))) {
        __Vdly__m_topsim__DOT__r_initaddr2 = ((IData)(4U) 
                                              + vlSelf->m_topsim__DOT__r_initaddr2);
    }
    if ((0x800000U <= vlSelf->m_topsim__DOT__r_initaddr2)) {
        vlSelf->m_topsim__DOT__r_disk_done = 1U;
    }
    if (vlSelf->RST_X) {
        vlSelf->m_topsim__DOT__mtime = (1ULL + vlSelf->m_topsim__DOT__mtime);
        vlSelf->m_topsim__DOT__r_checksum = (((~ (IData)(vlSelf->m_topsim__DOT__w_init_done)) 
                                              & (IData)(vlSelf->m_topsim__DOT__w_pl_init_we))
                                              ? (vlSelf->m_topsim__DOT__r_checksum 
                                                 + vlSelf->m_topsim__DOT__w_pl_init_data)
                                              : vlSelf->m_topsim__DOT__r_checksum);
    } else {
        vlSelf->m_topsim__DOT__r_checksum = 0U;
    }
    if (((((0x70000004U == vlSelf->m_topsim__DOT__r_mem_paddr) 
           & (0U != (IData)(vlSelf->m_topsim__DOT__r_consf_cnts))) 
          & (IData)(vlSelf->m_topsim__DOT__r_data_le)) 
         & (2U == (IData)(vlSelf->m_topsim__DOT__r_data_busy)))) {
        __Vdly__m_topsim__DOT__r_consf_head = (0x1fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->m_topsim__DOT__r_consf_head)));
        __Vdly__m_topsim__DOT__r_consf_en = ((1U >= (IData)(vlSelf->m_topsim__DOT__r_consf_cnts))
                                              ? 0U : 1U);
        vlSelf->m_topsim__DOT__r_char_value = vlSelf->m_topsim__DOT__cons_fifo
            [vlSelf->m_topsim__DOT__r_consf_head];
        __Vdly__m_topsim__DOT__r_consf_cnts = (0x3fU 
                                               & ((IData)(vlSelf->m_topsim__DOT__r_consf_cnts) 
                                                  - (IData)(1U)));
    } else if (VL_UNLIKELY(vlSelf->m_topsim__DOT__w_file_we)) {
        VL_WRITEF("\nw_file_we\n\n");
        if (VL_UNLIKELY((0U != (IData)(vlSelf->m_topsim__DOT__r_consf_cnts)))) {
            VL_WRITEF("warning: w_file_we and r_consf_cnts = %2# with r_consf_en=%1#\n",
                      6,vlSelf->m_topsim__DOT__r_consf_cnts,
                      1,(IData)(vlSelf->m_topsim__DOT__r_consf_en));
        } else {
            vlSelf->m_topsim__DOT__i = 0U;
            __Vdly__m_topsim__DOT__r_consf_cnts = (0x3fU 
                                                   & vlSelf->m_topsim__DOT__rf__DOT__n);
            while (VL_LTS_III(32, vlSelf->m_topsim__DOT__i, vlSelf->m_topsim__DOT__rf__DOT__n)) {
                vlSelf->m_topsim__DOT__cons_fifo[(0x1fU 
                                                  & ((IData)(vlSelf->m_topsim__DOT__r_consf_tail) 
                                                     + vlSelf->m_topsim__DOT__i))] 
                    = vlSelf->m_topsim__DOT__rf__DOT__fifo
                    [(0x1fU & vlSelf->m_topsim__DOT__i)];
                vlSelf->m_topsim__DOT__i = ((IData)(1U) 
                                            + vlSelf->m_topsim__DOT__i);
            }
            __Vdly__m_topsim__DOT__r_consf_en = 1U;
            vlSelf->m_topsim__DOT__r_consf_tail = (0x1fU 
                                                   & ((IData)(vlSelf->m_topsim__DOT__r_consf_tail) 
                                                      + vlSelf->m_topsim__DOT__rf__DOT__n));
        }
    }
    if (vlSelf->RST_X) {
        if (vlSelf->m_topsim__DOT__w_tx_ready) {
            vlSelf->m_topsim__DOT__w_txd = 1U;
            __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum = 0U;
            if (VL_UNLIKELY(vlSelf->m_topsim__DOT__r_uart_we)) {
                VL_WRITEF("%c",8,vlSelf->m_topsim__DOT__r_uart_data);
                __Vdly__m_topsim__DOT__w_tx_ready = 0U;
                __Vdly__m_topsim__DOT__UartTx0__DOT__cmd 
                    = ((IData)(vlSelf->m_topsim__DOT__r_uart_data) 
                       << 1U);
                __Vdly__m_topsim__DOT__UartTx0__DOT__cnt = 0xaU;
            }
        } else if ((2U <= vlSelf->m_topsim__DOT__UartTx0__DOT__waitnum)) {
            vlSelf->m_topsim__DOT__w_txd = (1U & (IData)(vlSelf->m_topsim__DOT__UartTx0__DOT__cmd));
            __Vdly__m_topsim__DOT__w_tx_ready = (1U 
                                                 == (IData)(vlSelf->m_topsim__DOT__UartTx0__DOT__cnt));
            __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum = 1U;
            __Vdly__m_topsim__DOT__UartTx0__DOT__cmd 
                = (0x100U | (0xffU & ((IData)(vlSelf->m_topsim__DOT__UartTx0__DOT__cmd) 
                                      >> 1U)));
            __Vdly__m_topsim__DOT__UartTx0__DOT__cnt 
                = (0xfU & ((IData)(vlSelf->m_topsim__DOT__UartTx0__DOT__cnt) 
                           - (IData)(1U)));
        } else {
            __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum 
                = ((IData)(1U) + vlSelf->m_topsim__DOT__UartTx0__DOT__waitnum);
        }
    } else {
        vlSelf->m_topsim__DOT__w_txd = 1U;
        __Vdly__m_topsim__DOT__w_tx_ready = 1U;
        __Vdly__m_topsim__DOT__UartTx0__DOT__cmd = 0x1ffU;
        __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum = 0U;
        __Vdly__m_topsim__DOT__UartTx0__DOT__cnt = 0U;
    }
    if ((0U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        if (vlSelf->m_topsim__DOT__dram_con__DOT__r_rd) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr)))) {
                VL_WRITEF("unaligned read: w_addr=%x\n",
                          32,vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            }
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 1U;
            vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr 
                = vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr;
        } else if (vlSelf->m_topsim__DOT__dram_con__DOT__r_we) {
            if (VL_UNLIKELY((0U != (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr)))) {
                VL_WRITEF("unaligned write: w_addr=%x\n",
                          32,vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            }
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 2U;
            vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr 
                = vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr;
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata;
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask 
                = vlSelf->m_topsim__DOT__dram_con__DOT__r_mask;
        } else if (vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh) {
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 3U;
            vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt = 0U;
        }
    } else if ((1U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_odata 
            = ((vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem
                [(0x7fffffU & ((IData)(3U) + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr))] 
                << 0x18U) | ((vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem
                              [(0x7fffffU & ((IData)(2U) 
                                             + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr))] 
                              << 0x10U) | ((vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem
                                            [(0x7fffffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr))] 
                                            << 8U) 
                                           | vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem
                                           [(0x7fffffU 
                                             & vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr)])));
        __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0U;
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0U;
    } else if ((0xaU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        if ((0U >= vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_cnt)) {
            vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_cnt 
                = ((IData)(1U) + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_cnt);
        } else {
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0xbU;
        }
    } else if ((0xbU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0U;
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0U;
    } else if ((2U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        if ((1U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask))) {
            __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0 
                = (0xffU & vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata);
            __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0 = 1U;
            __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0 
                = (0x7fffffU & vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr);
        }
        __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0U;
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0U;
        if ((2U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask))) {
            __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1 
                = (0xffU & (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                            >> 8U));
            __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1 = 1U;
            __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1 
                = (0x7fffffU & ((IData)(1U) + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr));
        }
        if ((4U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask))) {
            __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2 
                = (0xffU & (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                            >> 0x10U));
            __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2 = 1U;
            __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2 
                = (0x7fffffU & ((IData)(2U) + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr));
        }
        if ((8U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask))) {
            __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3 
                = (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                   >> 0x18U);
            __Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3 = 1U;
            __Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3 
                = (0x7fffffU & ((IData)(3U) + vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr));
        }
    } else if ((3U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state))) {
        if ((3U <= (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt))) {
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0U;
            vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0U;
        } else {
            __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt)));
        }
    }
    if (vlSelf->RST_X) {
        if (vlSelf->m_topsim__DOT__w_init_done) {
            if ((0U == (IData)(vlSelf->m_topsim__DOT__ba__DOT__state))) {
                if (VL_UNLIKELY(vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy)) {
                    VL_WRITEF("------------- sys-busy in state0\n");
                    VL_FINISH_MT("busarbiter.v", 107, "");
                }
                if (((1U == vlSelf->m_topsim__DOT__ba__DOT__grant) 
                     & (0x2fU == (0x7fU & vlSelf->m_topsim__DOT__bus_core_ir_1)))) {
                    if (((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                         | (IData)(vlSelf->m_topsim__DOT__bus_data_we1))) {
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    }
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we0)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we0;
                        vlSelf->m_topsim__DOT__bus_dram_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                        vlSelf->m_topsim__DOT__bus_data_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                            = vlSelf->m_topsim__DOT__bus_dram_addr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                            = vlSelf->m_topsim__DOT__bus_data_wdata0;
                    }
                } else if (((0U == vlSelf->m_topsim__DOT__ba__DOT__grant) 
                            & (0x2fU == (0x7fU & vlSelf->m_topsim__DOT__bus_core_ir_0)))) {
                    if (((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                         | (IData)(vlSelf->m_topsim__DOT__bus_data_we0))) {
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 
                            = vlSelf->m_topsim__DOT__bus_dram_le0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 
                            = vlSelf->m_topsim__DOT__bus_data_le0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 
                            = vlSelf->m_topsim__DOT__bus_data_we0;
                        vlSelf->m_topsim__DOT__bus_dram_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                        vlSelf->m_topsim__DOT__bus_data_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                            = vlSelf->m_topsim__DOT__bus_dram_addr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                            = vlSelf->m_topsim__DOT__bus_data_wdata0;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    }
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we1)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    }
                } else if (vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1) {
                    __Vdly__m_topsim__DOT__ba__DOT__grant = 1U;
                    __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1_aux;
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we0)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we0;
                        vlSelf->m_topsim__DOT__bus_dram_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                        vlSelf->m_topsim__DOT__bus_data_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                            = vlSelf->m_topsim__DOT__bus_dram_addr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                            = vlSelf->m_topsim__DOT__bus_data_wdata0;
                    }
                } else if (vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0) {
                    __Vdly__m_topsim__DOT__ba__DOT__grant = 0U;
                    __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0_aux;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 
                        = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0_aux;
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we1)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    }
                } else if (((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                              | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                             | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_data_we1))) {
                    __Vdly__m_topsim__DOT__ba__DOT__grant = 1U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 
                        = vlSelf->m_topsim__DOT__bus_dram_le1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 
                        = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 
                        = vlSelf->m_topsim__DOT__bus_data_le1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 
                        = vlSelf->m_topsim__DOT__bus_data_we1;
                    vlSelf->m_topsim__DOT__bus_dram_busy1 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                    vlSelf->m_topsim__DOT__bus_data_busy1 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                        = vlSelf->m_topsim__DOT__bus_dram_addr1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                        = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                        = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                        = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                        = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we0)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le0;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we0;
                        vlSelf->m_topsim__DOT__bus_dram_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                        vlSelf->m_topsim__DOT__bus_data_busy0 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                            = vlSelf->m_topsim__DOT__bus_dram_addr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                            = vlSelf->m_topsim__DOT__bus_data_wdata0;
                    }
                } else if (((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                              | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                             | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_data_we0))) {
                    __Vdly__m_topsim__DOT__ba__DOT__grant = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 
                        = vlSelf->m_topsim__DOT__bus_dram_le0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 
                        = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 
                        = vlSelf->m_topsim__DOT__bus_data_le0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 
                        = vlSelf->m_topsim__DOT__bus_data_we0;
                    vlSelf->m_topsim__DOT__bus_dram_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                    vlSelf->m_topsim__DOT__bus_data_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                        = vlSelf->m_topsim__DOT__bus_dram_addr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                        = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                        = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                        = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                        = vlSelf->m_topsim__DOT__bus_data_wdata0;
                    __Vdly__m_topsim__DOT__ba__DOT__state = 1U;
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we1)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    }
                }
            } else if ((1U == (IData)(vlSelf->m_topsim__DOT__ba__DOT__state))) {
                if (vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy) {
                    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 2U;
                    } else {
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 2U;
                    }
                }
                if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we1)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    }
                } else if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                              | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                             | (IData)(vlSelf->m_topsim__DOT__bus_data_we0)) 
                            & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0)))) {
                    __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 1U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
                        = vlSelf->m_topsim__DOT__bus_dram_le0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
                        = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
                        = vlSelf->m_topsim__DOT__bus_data_le0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
                        = vlSelf->m_topsim__DOT__bus_data_we0;
                    vlSelf->m_topsim__DOT__bus_dram_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                    vlSelf->m_topsim__DOT__bus_data_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                        = vlSelf->m_topsim__DOT__bus_dram_addr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                        = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                        = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                        = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                        = vlSelf->m_topsim__DOT__bus_data_wdata0;
                }
            } else if ((2U == (IData)(vlSelf->m_topsim__DOT__ba__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy)))) {
                    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata0 
                            = vlSelf->m_topsim__DOT__w_dram_odata;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data0 
                            = vlSelf->m_topsim__DOT__w_data_data;
                        vlSelf->m_topsim__DOT__bus_dram_busy0 = 0U;
                        vlSelf->m_topsim__DOT__bus_data_busy0 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 0U;
                    } else {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata1 
                            = vlSelf->m_topsim__DOT__w_dram_odata;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data1 
                            = vlSelf->m_topsim__DOT__w_data_data;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 = 0U;
                        vlSelf->m_topsim__DOT__bus_data_busy1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__state = 0U;
                    }
                }
                if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
                    if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                            | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1)) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_le1)) 
                          | (IData)(vlSelf->m_topsim__DOT__bus_data_we1)) 
                         & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1)))) {
                        __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1 = 1U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
                        vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
                            = vlSelf->m_topsim__DOT__bus_dram_we_t1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_le1;
                        __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
                            = vlSelf->m_topsim__DOT__bus_data_we1;
                        vlSelf->m_topsim__DOT__bus_dram_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t1));
                        vlSelf->m_topsim__DOT__bus_data_busy1 
                            = ((IData)(vlSelf->m_topsim__DOT__bus_data_le1) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_data_we1));
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 
                            = vlSelf->m_topsim__DOT__bus_dram_addr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 
                            = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 
                            = vlSelf->m_topsim__DOT__bus_dram_wdata1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 
                            = vlSelf->m_topsim__DOT__bus_mem_paddr1;
                        vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 
                            = vlSelf->m_topsim__DOT__bus_data_wdata1;
                    }
                } else if ((((((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                               | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0)) 
                              | (IData)(vlSelf->m_topsim__DOT__bus_data_le0)) 
                             | (IData)(vlSelf->m_topsim__DOT__bus_data_we0)) 
                            & (~ (IData)(vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0)))) {
                    __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0 = 1U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
                    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
                        = vlSelf->m_topsim__DOT__bus_dram_le0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
                        = vlSelf->m_topsim__DOT__bus_dram_we_t0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
                        = vlSelf->m_topsim__DOT__bus_data_le0;
                    __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
                        = vlSelf->m_topsim__DOT__bus_data_we0;
                    vlSelf->m_topsim__DOT__bus_dram_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_dram_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_dram_we_t0));
                    vlSelf->m_topsim__DOT__bus_data_busy0 
                        = ((IData)(vlSelf->m_topsim__DOT__bus_data_le0) 
                           | (IData)(vlSelf->m_topsim__DOT__bus_data_we0));
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 
                        = vlSelf->m_topsim__DOT__bus_dram_addr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 
                        = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 
                        = vlSelf->m_topsim__DOT__bus_dram_wdata0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 
                        = vlSelf->m_topsim__DOT__bus_mem_paddr0;
                    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 
                        = vlSelf->m_topsim__DOT__bus_data_wdata0;
                }
            }
        }
    } else {
        __Vdly__m_topsim__DOT__ba__DOT__grant = 0U;
    }
    vlSelf->m_topsim__DOT__r_clint_odata = (((6U == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                             & ((0U 
                                                 == vlSelf->m_topsim__DOT__w_offset) 
                                                | (4U 
                                                   == vlSelf->m_topsim__DOT__w_offset)))
                                             ? vlSelf->m_topsim__DOT__r_ipi
                                             : (((6U 
                                                  == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                 & (0xbff8U 
                                                    == vlSelf->m_topsim__DOT__w_offset))
                                                 ? (IData)(vlSelf->m_topsim__DOT__w_mtime)
                                                 : 
                                                (((6U 
                                                   == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                  & (0xbffcU 
                                                     == vlSelf->m_topsim__DOT__w_offset))
                                                  ? (IData)(
                                                            (vlSelf->m_topsim__DOT__w_mtime 
                                                             >> 0x20U))
                                                  : 
                                                 (((6U 
                                                    == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                   & (0x4000U 
                                                      == vlSelf->m_topsim__DOT__w_offset))
                                                   ? (IData)(vlSelf->m_topsim__DOT__w_mtimecmp0)
                                                   : 
                                                  (((6U 
                                                     == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                    & (0x4004U 
                                                       == vlSelf->m_topsim__DOT__w_offset))
                                                    ? (IData)(
                                                              (vlSelf->m_topsim__DOT__w_mtimecmp0 
                                                               >> 0x20U))
                                                    : 
                                                   (((6U 
                                                      == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                     & (0x4008U 
                                                        == vlSelf->m_topsim__DOT__w_offset))
                                                     ? (IData)(vlSelf->m_topsim__DOT__w_mtimecmp1)
                                                     : 
                                                    (((6U 
                                                       == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
                                                      & (0x400cU 
                                                         == vlSelf->m_topsim__DOT__w_offset))
                                                      ? (IData)(
                                                                (vlSelf->m_topsim__DOT__w_mtimecmp1 
                                                                 >> 0x20U))
                                                      : 0U)))))));
    if (((((6U == (IData)(vlSelf->m_topsim__DOT__r_dev)) 
           & ((0U == vlSelf->m_topsim__DOT__w_offset) 
              | (4U == vlSelf->m_topsim__DOT__w_offset))) 
          & (IData)(vlSelf->m_topsim__DOT__r_data_we)) 
         & (2U == (IData)(vlSelf->m_topsim__DOT__r_data_busy)))) {
        if ((0U == vlSelf->m_topsim__DOT__w_offset)) {
            if ((0U == vlSelf->m_topsim__DOT__w_data_wdata)) {
                if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
                    vlSelf->m_topsim__DOT__r_max_displays 
                        = ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
                    VL_WRITEF("t=%8x clear ipi core0 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                              64,vlSelf->m_topsim__DOT__w_mtime,
                              32,vlSelf->m_topsim__DOT__w_grant,
                              32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                              32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                              32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                              32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
                }
                __Vdly__m_topsim__DOT__r_ipi = (0xfffefffeU 
                                                & vlSelf->m_topsim__DOT__r_ipi);
            } else {
                if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
                    VL_WRITEF("t=%8x send ipi to core0 w_data_wdata=%x w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                              64,vlSelf->m_topsim__DOT__w_mtime,
                              32,vlSelf->m_topsim__DOT__w_data_wdata,
                              32,vlSelf->m_topsim__DOT__w_grant,
                              32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                              32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                              32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                              32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
                    vlSelf->m_topsim__DOT__r_max_displays 
                        = ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
                }
                __Vdly__m_topsim__DOT__r_ipi = ((2U 
                                                 == vlSelf->m_topsim__DOT__w_data_wdata)
                                                 ? 
                                                (0x10001U 
                                                 | (0xfffefffeU 
                                                    & vlSelf->m_topsim__DOT__r_ipi))
                                                 : 
                                                (1U 
                                                 | (0xfffefffeU 
                                                    & vlSelf->m_topsim__DOT__r_ipi)));
                if (VL_UNLIKELY((0U != (1U & vlSelf->m_topsim__DOT__r_ipi)))) {
                    VL_WRITEF("-------- %x: core0 already had ipi pc0=%x pc1=%x\n",
                              64,vlSelf->m_topsim__DOT__w_mtime,
                              32,vlSelf->m_topsim__DOT__w_pc0,
                              32,vlSelf->m_topsim__DOT__w_pc1);
                }
            }
        } else if ((0U == vlSelf->m_topsim__DOT__w_data_wdata)) {
            if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
                VL_WRITEF("t=%8x clear ipi core1 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                          64,vlSelf->m_topsim__DOT__w_mtime,
                          32,vlSelf->m_topsim__DOT__w_grant,
                          32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                          32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                          32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                          32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
                vlSelf->m_topsim__DOT__r_max_displays 
                    = ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
            }
            __Vdly__m_topsim__DOT__r_ipi = (0xfffdfffdU 
                                            & vlSelf->m_topsim__DOT__r_ipi);
        } else {
            if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
                VL_WRITEF("t=%8x send ipi to core1 w_data_wdata=%x w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                          64,vlSelf->m_topsim__DOT__w_mtime,
                          32,vlSelf->m_topsim__DOT__w_data_wdata,
                          32,vlSelf->m_topsim__DOT__w_grant,
                          32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                          32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                          32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                          32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
                vlSelf->m_topsim__DOT__r_max_displays 
                    = ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
            }
            __Vdly__m_topsim__DOT__r_ipi = ((2U == vlSelf->m_topsim__DOT__w_data_wdata)
                                             ? (0x20002U 
                                                | (0xfffdfffdU 
                                                   & vlSelf->m_topsim__DOT__r_ipi))
                                             : (2U 
                                                | (0xfffdfffdU 
                                                   & vlSelf->m_topsim__DOT__r_ipi)));
            if (VL_UNLIKELY((0U != (2U & vlSelf->m_topsim__DOT__r_ipi)))) {
                VL_WRITEF("-------- %x: core1 already had ipi pc0=%x pc1=%x\n",
                          64,vlSelf->m_topsim__DOT__w_mtime,
                          32,vlSelf->m_topsim__DOT__w_pc0,
                          32,vlSelf->m_topsim__DOT__w_pc1);
            }
        }
    } else if (vlSelf->m_topsim__DOT__w_ipi_taken0) {
        if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
            VL_WRITEF("t=%8x clear ipi core0 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                      64,vlSelf->m_topsim__DOT__w_mtime,
                      32,vlSelf->m_topsim__DOT__w_grant,
                      32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                      32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                      32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                      32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
            vlSelf->m_topsim__DOT__r_max_displays = 
                ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
        }
        __Vdly__m_topsim__DOT__r_ipi = (0xfffefffeU 
                                        & vlSelf->m_topsim__DOT__r_ipi);
    } else if (vlSelf->m_topsim__DOT__w_ipi_taken1) {
        if (VL_UNLIKELY((0x14U > vlSelf->m_topsim__DOT__r_max_displays))) {
            VL_WRITEF("t=%8x clear ipi core1 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x\n",
                      64,vlSelf->m_topsim__DOT__w_mtime,
                      32,vlSelf->m_topsim__DOT__w_grant,
                      32,vlSymsp->TOP__m_topsim__DOT__core0.p__DOT__r_cpc,
                      32,vlSymsp->TOP__m_topsim__DOT__core0.w_ir,
                      32,vlSymsp->TOP__m_topsim__DOT__core1.p__DOT__r_cpc,
                      32,vlSymsp->TOP__m_topsim__DOT__core1.w_ir);
            vlSelf->m_topsim__DOT__r_max_displays = 
                ((IData)(1U) + vlSelf->m_topsim__DOT__r_max_displays);
        }
        __Vdly__m_topsim__DOT__r_ipi = (0xfffdfffdU 
                                        & vlSelf->m_topsim__DOT__r_ipi);
    }
    vlSelf->m_topsim__DOT__r_zero_we = __Vdly__m_topsim__DOT__r_zero_we;
    vlSelf->m_topsim__DOT__r_zeroaddr = __Vdly__m_topsim__DOT__r_zeroaddr;
    vlSelf->m_topsim__DOT__r_initaddr = __Vdly__m_topsim__DOT__r_initaddr;
    vlSelf->m_topsim__DOT__r_initaddr2 = __Vdly__m_topsim__DOT__r_initaddr2;
    vlSelf->m_topsim__DOT__r_consf_head = __Vdly__m_topsim__DOT__r_consf_head;
    vlSelf->m_topsim__DOT__r_consf_en = __Vdly__m_topsim__DOT__r_consf_en;
    vlSelf->m_topsim__DOT__r_consf_cnts = __Vdly__m_topsim__DOT__r_consf_cnts;
    vlSelf->m_topsim__DOT__UartTx0__DOT__waitnum = __Vdly__m_topsim__DOT__UartTx0__DOT__waitnum;
    vlSelf->m_topsim__DOT__UartTx0__DOT__cmd = __Vdly__m_topsim__DOT__UartTx0__DOT__cmd;
    vlSelf->m_topsim__DOT__UartTx0__DOT__cnt = __Vdly__m_topsim__DOT__UartTx0__DOT__cnt;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state 
        = __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr 
        = __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask 
        = __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt 
        = __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt;
    if (__Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[__Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0] 
            = __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v0;
    }
    if (__Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[__Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1] 
            = __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v1;
    }
    if (__Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[__Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2] 
            = __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v2;
    }
    if (__Vdlyvset__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[__Vdlyvdim0__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3] 
            = __Vdlyvval__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem__v3;
    }
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
        = __Vdly__m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata;
    vlSelf->m_topsim__DOT__ba__DOT__state = __Vdly__m_topsim__DOT__ba__DOT__state;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0 
        = __Vdly__m_topsim__DOT__ba__DOT__r_pending_req0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le0_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we0_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1 
        = __Vdly__m_topsim__DOT__ba__DOT__r_pending_req1;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_le1_aux;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1_aux 
        = __Vdly__m_topsim__DOT__ba__DOT__r_ba_data_we1_aux;
    vlSelf->m_topsim__DOT__ba__DOT__grant = __Vdly__m_topsim__DOT__ba__DOT__grant;
    vlSelf->m_topsim__DOT__r_ipi = __Vdly__m_topsim__DOT__r_ipi;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_mtime = (IData)(
                                                            (vlSelf->m_topsim__DOT__mtime 
                                                             >> 0U));
    vlSelf->m_topsim__DOT__w_checksum = vlSelf->m_topsim__DOT__r_checksum;
    vlSelf->m_topsim__DOT__rf__DOT__r_consf_en = vlSelf->m_topsim__DOT__r_consf_en;
    vlSelf->m_topsim__DOT__UartTx0__DOT__TXD = vlSelf->m_topsim__DOT__w_txd;
    if ((((((0x40008000U == vlSelf->m_topsim__DOT__r_mem_paddr) 
            & (IData)(vlSelf->m_topsim__DOT__r_data_we)) 
           & (1U == (vlSelf->m_topsim__DOT__w_data_wdata 
                     >> 0x10U))) & (IData)(vlSelf->m_topsim__DOT__w_tx_ready)) 
         & (IData)(vlSelf->m_topsim__DOT__r_wait_ready))) {
        vlSelf->m_topsim__DOT__r_uart_we = 1U;
        vlSelf->m_topsim__DOT__r_uart_data = (0xffU 
                                              & vlSelf->m_topsim__DOT__w_data_wdata);
    } else {
        vlSelf->m_topsim__DOT__r_uart_we = 0U;
        vlSelf->m_topsim__DOT__r_uart_data = 0U;
    }
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data3 
        = (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
           >> 0x18U);
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data2 
        = (0xffU & (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                    >> 0x10U));
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data1 
        = (0xffU & (vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata 
                    >> 8U));
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data0 
        = (0xffU & vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata);
    if (vlSelf->RST_X) {
        if (((~ (IData)(vlSelf->m_topsim__DOT__w_pl_init_done)) 
             & (IData)(vlSelf->m_topsim__DOT__ploader__DOT__SER_EN))) {
            vlSelf->m_topsim__DOT__w_pl_init_data = 
                (((IData)(vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA) 
                  << 0x18U) | (vlSelf->m_topsim__DOT__w_pl_init_data 
                               >> 8U));
            vlSelf->m_topsim__DOT__w_pl_init_addr = vlSelf->m_topsim__DOT__ploader__DOT__waddr;
            vlSelf->m_topsim__DOT__w_pl_init_we = (3U 
                                                   == 
                                                   (3U 
                                                    & vlSelf->m_topsim__DOT__ploader__DOT__waddr));
            __Vdly__m_topsim__DOT__ploader__DOT__waddr 
                = ((IData)(1U) + vlSelf->m_topsim__DOT__ploader__DOT__waddr);
        } else {
            vlSelf->m_topsim__DOT__w_pl_init_we = 0U;
            if ((0x800000U <= vlSelf->m_topsim__DOT__ploader__DOT__waddr)) {
                vlSelf->m_topsim__DOT__w_pl_init_done = 1U;
            }
        }
    } else {
        vlSelf->m_topsim__DOT__w_pl_init_data = 0U;
        __Vdly__m_topsim__DOT__ploader__DOT__waddr = 0U;
        vlSelf->m_topsim__DOT__w_pl_init_addr = 0U;
        vlSelf->m_topsim__DOT__w_pl_init_we = 0U;
        vlSelf->m_topsim__DOT__w_pl_init_done = 0U;
    }
    if (vlSelf->RST_X) {
        if (((((((((0U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state)) 
                   | (0x32U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
                  | (0x33U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
                 | (0xaU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
                | (0xbU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
               | (0xcU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
              | (0xdU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) 
             | (0x64U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state)))) {
            if ((0U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if (((IData)(vlSelf->m_topsim__DOT__w_dram_le) 
                     & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xaU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 1U;
                } else if (((IData)(vlSelf->m_topsim__DOT__w_dram_we_t) 
                            & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                        = ((0U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                            ? (0xffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                            : ((1U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                                ? (0xffffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                                : vlSelf->m_topsim__DOT__w_dram_wdata_t));
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x14U;
                } else if (((0xc8U < vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt) 
                            & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x32U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh = 1U;
                }
            } else if ((0x32U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if (((~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__read_request)) 
                     & (IData)(vlSelf->m_topsim__DOT__w_dram_le))) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__read_request = 1U;
                } else if (((~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__write_request)) 
                            & (IData)(vlSelf->m_topsim__DOT__w_dram_we_t))) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                        = ((0U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                            ? (0xffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                            : ((1U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                                ? (0xffffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                                : vlSelf->m_topsim__DOT__w_dram_wdata_t));
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__write_request = 1U;
                }
                if (vlSelf->m_topsim__DOT__dram_con__DOT__w_busy) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh = 0U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x33U;
                }
            } else if ((0x33U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if (vlSelf->m_topsim__DOT__dram_con__DOT__w_busy) {
                    if (((~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__read_request)) 
                         & (IData)(vlSelf->m_topsim__DOT__w_dram_le))) {
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                            = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                            = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                            = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                        __Vdly__m_topsim__DOT__dram_con__DOT__read_request = 1U;
                    } else if (((~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__write_request)) 
                                & (IData)(vlSelf->m_topsim__DOT__w_dram_we_t))) {
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                            = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                            = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                            = ((0U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                                ? (0xffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                                : ((1U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                                    ? (0xffffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                                    : vlSelf->m_topsim__DOT__w_dram_wdata_t));
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                            = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                        __Vdly__m_topsim__DOT__dram_con__DOT__write_request = 1U;
                    }
                } else if (vlSelf->m_topsim__DOT__dram_con__DOT__read_request) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__read_request = 0U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xaU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 1U;
                } else if (vlSelf->m_topsim__DOT__dram_con__DOT__write_request) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__write_request = 0U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x14U;
                } else if (vlSelf->m_topsim__DOT__w_dram_le) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xaU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 1U;
                } else if (vlSelf->m_topsim__DOT__w_dram_we_t) {
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_addr 
                        = vlSelf->m_topsim__DOT__w_dram_addr_t2;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                        = (0xfffffffcU & vlSelf->m_topsim__DOT__w_dram_addr_t2);
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                        = ((0U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                            ? (0xffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                            : ((1U == (3U & (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl_t)))
                                ? (0xffffU & vlSelf->m_topsim__DOT__w_dram_wdata_t)
                                : vlSelf->m_topsim__DOT__w_dram_wdata_t));
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl 
                        = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
                    __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 1U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x14U;
                } else {
                    if (VL_UNLIKELY(vlSelf->m_topsim__DOT__dram_con__DOT__r_stall)) {
                        VL_WRITEF("TN_DRAM_REFRESH bug r_stall not null ------------\n");
                    }
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0U;
                }
            } else if ((0xaU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if (vlSelf->m_topsim__DOT__dram_con__DOT__w_busy) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 0U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xbU;
                }
            } else if ((0xbU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata1 
                        = vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata;
                    if ((((0U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr)) 
                          | (0U == (3U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))) 
                         | ((2U >= (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr)) 
                            & (1U == (3U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))))) {
                        __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x64U;
                    } else {
                        __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                            = ((IData)(4U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
                        __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xcU;
                        vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 1U;
                    }
                }
            } else if ((0xcU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if (vlSelf->m_topsim__DOT__dram_con__DOT__w_busy) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 0U;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0xdU;
                }
            } else if ((0xdU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata2 
                        = (0xffffffU & vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x64U;
                }
            } else {
                __Vdly__m_topsim__DOT__dram_con__DOT__state = 0U;
                __Vdly__m_topsim__DOT__dram_con__DOT__r_stall = 0U;
            }
        } else if ((0x14U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            if ((0U == (3U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))) {
                if ((0U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 1U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui;
                } else if ((1U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 2U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 8U);
                } else if ((2U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 4U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x10U);
                } else if ((3U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 8U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x18U);
                }
                __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
            } else if ((1U == (3U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))) {
                if ((0U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 3U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
                } else if ((1U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 6U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 8U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
                } else if ((2U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0xcU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x10U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
                } else if ((3U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 8U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x18U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x1fU;
                }
            } else if ((2U == (3U & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))) {
                if ((0U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0xfU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui;
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
                } else if ((1U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0xeU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 8U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x28U;
                } else if ((2U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0xcU;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x10U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x29U;
                } else if ((3U == (3U & vlSelf->m_topsim__DOT__dram_con__DOT__r_addr))) {
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 8U;
                    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                        = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                           << 0x18U);
                    __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x2aU;
                }
            }
            vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x15U;
        } else if ((0x15U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            if (vlSelf->m_topsim__DOT__dram_con__DOT__w_busy) {
                vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 0U;
                __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x16U;
            }
        } else if ((0x16U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            if ((1U & (~ (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__w_busy)))) {
                __Vdly__m_topsim__DOT__dram_con__DOT__state 
                    = vlSelf->m_topsim__DOT__dram_con__DOT__state_next;
            }
        } else if ((0x1fU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                = ((IData)(4U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 1U;
            vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                   >> 8U);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x15U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
        } else if ((0x28U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                = ((IData)(4U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 1U;
            vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                   >> 0x18U);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x15U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
        } else if ((0x29U == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                = ((IData)(4U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 3U;
            vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                   >> 0x10U);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x15U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
        } else if ((0x2aU == (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__state))) {
            __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr 
                = ((IData)(4U) + vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 7U;
            vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata 
                = (vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
                   >> 8U);
            vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 1U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state = 0x15U;
            __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0x64U;
        }
    } else {
        __Vdly__m_topsim__DOT__dram_con__DOT__read_request = 0U;
        __Vdly__m_topsim__DOT__dram_con__DOT__write_request = 0U;
        vlSelf->m_topsim__DOT__w_late_refresh = 0U;
        __Vdly__m_topsim__DOT__dram_con__DOT__state = 0U;
        __Vdly__m_topsim__DOT__dram_con__DOT__state_next = 0U;
    }
    if (vlSelf->RST_X) {
        if ((0U == (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage))) {
            __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage 
                = (((IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start) 
                    == (0x1fffU & ((IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__waitcnt) 
                                   >> 1U))) ? 1U : 
                   (0xfU & (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage)));
            vlSelf->m_topsim__DOT__ploader__DOT__SER_EN = 0U;
        } else if (((IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt) 
                    != (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__waitcnt))) {
            vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt 
                = (0x1fffU & ((IData)(1U) + (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt)));
            vlSelf->m_topsim__DOT__ploader__DOT__SER_EN = 0U;
        } else {
            __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage 
                = ((9U == (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage))));
            vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA 
                = (((IData)(vlSelf->m_topsim__DOT__w_rxd) 
                    << 7U) | (0x7fU & ((IData)(vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA) 
                                       >> 1U)));
            vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt = 1U;
            vlSelf->m_topsim__DOT__ploader__DOT__SER_EN 
                = ((8U == (IData)(vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage))
                    ? 1U : 0U);
        }
    } else {
        __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage = 0U;
        vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt = 1U;
        vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA = 0U;
        vlSelf->m_topsim__DOT__ploader__DOT__SER_EN = 0U;
    }
    vlSelf->m_topsim__DOT__bus_data_data0 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data0;
    vlSelf->m_topsim__DOT__bus_data_data1 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy1 
        = vlSelf->m_topsim__DOT__bus_dram_busy1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy1 
        = vlSelf->m_topsim__DOT__bus_data_busy1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy0 
        = vlSelf->m_topsim__DOT__bus_dram_busy0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy0 
        = vlSelf->m_topsim__DOT__bus_data_busy0;
    if ((0U != vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__bus_wmip1 = vlSelf->m_topsim__DOT__w_wmip;
        vlSelf->m_topsim__DOT__bus_plic_we1 = vlSelf->m_topsim__DOT__w_plic_we;
    }
    vlSelf->m_topsim__DOT__w_grant = vlSelf->m_topsim__DOT__ba__DOT__grant;
    vlSelf->m_topsim__DOT__bus_dram_odata0 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata0;
    vlSelf->m_topsim__DOT__bus_dram_odata1 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata1;
    vlSelf->m_topsim__DOT__bus_ipi = vlSelf->m_topsim__DOT__r_ipi;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mtime 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_mtime;
    vlSelf->m_topsim__DOT__ploader__DOT__waddr = __Vdly__m_topsim__DOT__ploader__DOT__waddr;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui 
        = __Vdly__m_topsim__DOT__dram_con__DOT__r_wdata_ui;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt 
        = __Vdly__m_topsim__DOT__dram_con__DOT__r_refreshcnt;
    vlSelf->m_topsim__DOT__dram_con__DOT__read_request 
        = __Vdly__m_topsim__DOT__dram_con__DOT__read_request;
    vlSelf->m_topsim__DOT__dram_con__DOT__write_request 
        = __Vdly__m_topsim__DOT__dram_con__DOT__write_request;
    vlSelf->m_topsim__DOT__dram_con__DOT__state_next 
        = __Vdly__m_topsim__DOT__dram_con__DOT__state_next;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_busy = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_odata;
    vlSelf->m_topsim__DOT__dram_con__DOT__state = __Vdly__m_topsim__DOT__dram_con__DOT__state;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr = __Vdly__m_topsim__DOT__dram_con__DOT__r_maddr;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_stall = __Vdly__m_topsim__DOT__dram_con__DOT__r_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl = __Vdly__m_topsim__DOT__dram_con__DOT__r_ctrl;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_addr = __Vdly__m_topsim__DOT__dram_con__DOT__r_addr;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data0 
        = vlSelf->m_topsim__DOT__bus_data_data0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_data_data 
        = vlSelf->m_topsim__DOT__bus_data_data0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data1 
        = vlSelf->m_topsim__DOT__bus_data_data1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_data_data 
        = vlSelf->m_topsim__DOT__bus_data_data1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_wmip1 = vlSelf->m_topsim__DOT__bus_wmip1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we1 = vlSelf->m_topsim__DOT__bus_plic_we1;
    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__bus_plic_we0 = vlSelf->m_topsim__DOT__w_plic_we;
        vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we0 
            = vlSelf->m_topsim__DOT__bus_plic_we0;
        vlSelf->m_topsim__DOT__bus_wmip0 = vlSelf->m_topsim__DOT__w_wmip;
        vlSelf->m_topsim__DOT__ba__DOT__bus_wmip0 = vlSelf->m_topsim__DOT__bus_wmip0;
        vlSelf->m_topsim__DOT__w_dram_ctrl = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0;
        vlSelf->m_topsim__DOT__ba__DOT__w_dram_ctrl 
            = vlSelf->m_topsim__DOT__w_dram_ctrl;
        vlSelf->m_topsim__DOT__w_dram_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0;
        vlSelf->m_topsim__DOT__ba__DOT__w_dram_wdata 
            = vlSelf->m_topsim__DOT__w_dram_wdata;
        vlSelf->m_topsim__DOT__w_dram_addr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0;
    } else {
        vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we0 
            = vlSelf->m_topsim__DOT__bus_plic_we0;
        vlSelf->m_topsim__DOT__ba__DOT__bus_wmip0 = vlSelf->m_topsim__DOT__bus_wmip0;
        vlSelf->m_topsim__DOT__w_dram_ctrl = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1;
        vlSelf->m_topsim__DOT__ba__DOT__w_dram_ctrl 
            = vlSelf->m_topsim__DOT__w_dram_ctrl;
        vlSelf->m_topsim__DOT__w_dram_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1;
        vlSelf->m_topsim__DOT__ba__DOT__w_dram_wdata 
            = vlSelf->m_topsim__DOT__w_dram_wdata;
        vlSelf->m_topsim__DOT__w_dram_addr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1;
    }
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_addr = vlSelf->m_topsim__DOT__w_dram_addr;
    vlSelf->m_topsim__DOT__w_dram_addr_t = ((9U == 
                                             (vlSelf->m_topsim__DOT__w_dram_addr 
                                              >> 0x1cU))
                                             ? ((IData)(0x800000U) 
                                                + (0x3ffffffU 
                                                   & vlSelf->m_topsim__DOT__w_dram_addr))
                                             : (0x3ffffffU 
                                                & vlSelf->m_topsim__DOT__w_dram_addr));
    vlSelf->m_topsim__DOT__ba__DOT__w_grant = vlSelf->m_topsim__DOT__w_grant;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata0 
        = vlSelf->m_topsim__DOT__bus_dram_odata0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata1 
        = vlSelf->m_topsim__DOT__bus_dram_odata1;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mtime 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mtime;
    vlSelf->m_topsim__DOT__ploader__DOT__ADDR = vlSelf->m_topsim__DOT__w_pl_init_addr;
    vlSelf->m_topsim__DOT__ploader__DOT__WE = vlSelf->m_topsim__DOT__w_pl_init_we;
    vlSelf->m_topsim__DOT__ploader__DOT__DONE = vlSelf->m_topsim__DOT__w_pl_init_done;
    vlSelf->m_topsim__DOT__ploader__DOT__DATA = vlSelf->m_topsim__DOT__w_pl_init_data;
    vlSelf->m_topsim__DOT__UartTx0__DOT__WE = vlSelf->m_topsim__DOT__r_uart_we;
    vlSelf->m_topsim__DOT__UartTx0__DOT__DATA = vlSelf->m_topsim__DOT__r_uart_data;
    vlSelf->m_topsim__DOT__w_data_wdata = ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)
                                            ? vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0
                                            : vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1);
    vlSelf->m_topsim__DOT__ba__DOT__w_data_wdata = vlSelf->m_topsim__DOT__w_data_wdata;
    vlSelf->m_topsim__DOT__r_wait_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    if ((0U == (IData)(vlSelf->m_topsim__DOT__r_data_busy))) {
        vlSelf->m_topsim__DOT__r_dev = vlSelf->m_topsim__DOT__w_dev;
        vlSelf->m_topsim__DOT__r_virt = vlSelf->m_topsim__DOT__w_virt;
        vlSelf->m_topsim__DOT__r_mem_paddr = vlSelf->m_topsim__DOT__w_mem_paddr;
        vlSelf->m_topsim__DOT__r_data_le = vlSelf->m_topsim__DOT__w_data_le;
        vlSelf->m_topsim__DOT__r_data_we = vlSelf->m_topsim__DOT__w_data_we;
        if (((IData)(vlSelf->m_topsim__DOT__w_data_we) 
             | (IData)(vlSelf->m_topsim__DOT__w_data_le))) {
            __Vdly__m_topsim__DOT__r_data_busy = 1U;
        }
    } else if ((2U > (IData)(vlSelf->m_topsim__DOT__r_data_busy))) {
        __Vdly__m_topsim__DOT__r_data_busy = 2U;
    } else {
        vlSelf->m_topsim__DOT__r_data_le = 0U;
        vlSelf->m_topsim__DOT__r_data_we = 0U;
        if (vlSelf->m_topsim__DOT__w_tx_ready) {
            __Vdly__m_topsim__DOT__r_data_busy = 0U;
        }
    }
    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__w_dram_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0;
        vlSelf->m_topsim__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0;
        vlSelf->m_topsim__DOT__w_data_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0;
        vlSelf->m_topsim__DOT__w_data_we = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0;
        vlSelf->m_topsim__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0;
    } else {
        vlSelf->m_topsim__DOT__w_dram_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1;
        vlSelf->m_topsim__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1;
        vlSelf->m_topsim__DOT__w_data_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1;
        vlSelf->m_topsim__DOT__w_data_we = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1;
        vlSelf->m_topsim__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1;
    }
    vlSelf->m_topsim__DOT__dram_con__DOT__r_late_refresh 
        = vlSelf->m_topsim__DOT__w_late_refresh;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_stall 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata;
    vlSelf->m_topsim__DOT__w_mem_state = vlSelf->m_topsim__DOT__dram_con__DOT__state;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_le 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_rd;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_refresh 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_addr 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mask 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_mask;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_wdata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_we 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_le = vlSelf->m_topsim__DOT__w_dram_le;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_rd_en = vlSelf->m_topsim__DOT__w_dram_le;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_wr_en = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__w_wr_en = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__w_dram_busy = vlSelf->m_topsim__DOT__dram_con__DOT__r_stall;
    m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0 
        = (0xffffffffffffffULL & ((((QData)((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata2)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata1))) 
                                  >> (0x18U & (vlSelf->m_topsim__DOT__dram_con__DOT__r_addr 
                                               << 3U))));
    vlSelf->m_topsim__DOT__w_dram_addr_t2 = ((1U == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                              ? vlSelf->m_topsim__DOT__r_zeroaddr
                                              : ((2U 
                                                  == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                                  ? vlSelf->m_topsim__DOT__r_initaddr
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                                   ? vlSelf->m_topsim__DOT__r_initaddr3
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                                    ? vlSelf->m_topsim__DOT__r_initaddr2
                                                    : vlSelf->m_topsim__DOT__w_dram_addr_t))));
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start 
        = __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage 
        = __Vdly__m_topsim__DOT__ploader__DOT__serc__DOT__stage;
    vlSelf->m_topsim__DOT__r_data_busy = __Vdly__m_topsim__DOT__r_data_busy;
    vlSelf->m_topsim__DOT__w_tx_ready = __Vdly__m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_stall 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_odata;
    vlSelf->m_topsim__DOT__dram_con__DOT__mem_state 
        = vlSelf->m_topsim__DOT__w_mem_state;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_le 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_le;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_refresh 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_refresh;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_addr 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_addr;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mask 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mask;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_wdata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_wdata;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_we 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_busy = vlSelf->m_topsim__DOT__w_dram_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_busy = vlSelf->m_topsim__DOT__w_dram_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_odata = (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0);
    vlSelf->m_topsim__DOT__dram_con__DOT__i_addr = vlSelf->m_topsim__DOT__w_dram_addr_t2;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__DATA 
        = vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA;
    vlSelf->m_topsim__DOT__w_key_data = vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__EN 
        = vlSelf->m_topsim__DOT__ploader__DOT__SER_EN;
    vlSelf->m_topsim__DOT__w_key_we = ((IData)(vlSelf->m_topsim__DOT__ploader__DOT__SER_EN) 
                                       & (IData)(vlSelf->m_topsim__DOT__w_pl_init_done));
    vlSelf->m_topsim__DOT__ba__DOT__w_data_le = vlSelf->m_topsim__DOT__w_data_le;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_we = vlSelf->m_topsim__DOT__w_data_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_busy = vlSelf->m_topsim__DOT__r_data_busy;
    vlSelf->m_topsim__DOT__ba__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__w_mem_paddr;
    vlSelf->m_topsim__DOT__w_dev = (vlSelf->m_topsim__DOT__w_mem_paddr 
                                    >> 0x1cU);
    vlSelf->m_topsim__DOT__w_virt = (0xfU & (vlSelf->m_topsim__DOT__w_mem_paddr 
                                             >> 0x18U));
    vlSelf->m_topsim__DOT__w_offset = (0x7ffffffU & vlSelf->m_topsim__DOT__w_mem_paddr);
    vlSelf->m_topsim__DOT__ba__DOT__w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__UartTx0__DOT__READY = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy = (1U 
                                                  & ((~ (IData)(vlSelf->m_topsim__DOT__w_tx_ready)) 
                                                     | ((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_stall) 
                                                        | (0U 
                                                           != (IData)(vlSelf->m_topsim__DOT__r_data_busy)))));
    vlSymsp->TOP__m_topsim__DOT__core0.w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSymsp->TOP__m_topsim__DOT__core1.w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__w_dram_odata = ((0U == (3U 
                                                   & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))
                                            ? ((4U 
                                                & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl))
                                                ? (0xffU 
                                                   & (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0))
                                                : (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (IData)(
                                                                          (m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0 
                                                                           >> 7U))))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0))))
                                            : ((1U 
                                                == 
                                                (3U 
                                                 & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl)))
                                                ? (
                                                   (4U 
                                                    & (IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl))
                                                    ? 
                                                   (0xffffU 
                                                    & (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0))
                                                    : 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (IData)(
                                                                           (m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0 
                                                                            >> 0xfU))))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0))))
                                                : vlSelf->m_topsim__DOT__dram_con__DOT__w_odata));
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_DATA = vlSelf->m_topsim__DOT__w_key_data;
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_WE = vlSelf->m_topsim__DOT__w_key_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_odata = vlSelf->m_topsim__DOT__w_dram_odata;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_data = vlSelf->m_topsim__DOT__w_dram_odata;
    if ((6U == (IData)(vlSelf->m_topsim__DOT__r_dev))) {
        vlSelf->m_topsim__DOT__r_data_data = vlSelf->m_topsim__DOT__r_clint_odata;
    } else if ((5U == (IData)(vlSelf->m_topsim__DOT__r_dev))) {
        vlSelf->m_topsim__DOT__r_data_data = vlSelf->m_topsim__DOT__r_plic_odata;
    } else if ((7U == (IData)(vlSelf->m_topsim__DOT__r_dev))) {
        if ((0x70000000U == vlSelf->m_topsim__DOT__r_mem_paddr)) {
            vlSelf->m_topsim__DOT__r_data_data = vlSelf->m_topsim__DOT__r_consf_cnts;
        } else if (VL_LIKELY((0x70000004U == vlSelf->m_topsim__DOT__r_mem_paddr))) {
            vlSelf->m_topsim__DOT__r_data_data = vlSelf->m_topsim__DOT__r_char_value;
        } else {
            vlSelf->m_topsim__DOT__r_data_data = 0U;
            VL_WRITEF("HVC_BASE_TADDR r_data_data <= 0 ------------------------------------\n");
        }
    } else {
        vlSelf->m_topsim__DOT__r_data_data = vlSelf->m_topsim__DOT__w_dram_odata;
    }
    vlSelf->m_topsim__DOT__w_data_data = vlSelf->m_topsim__DOT__r_data_data;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_data = vlSelf->m_topsim__DOT__w_data_data;
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__1(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->m_topsim__DOT__w_ipi_taken0 = vlSymsp->TOP__m_topsim__DOT__core0.w_ipi_taken;
    vlSelf->m_topsim__DOT__w_pc_stip0 = vlSymsp->TOP__m_topsim__DOT__core0.w_pc_stip;
    vlSelf->m_topsim__DOT__bus_data_wdata0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_wdata;
    vlSelf->m_topsim__DOT__bus_tlb_req0 = vlSymsp->TOP__m_topsim__DOT__core0.w_tlb_req;
    vlSelf->m_topsim__DOT__bus_mip0 = vlSymsp->TOP__m_topsim__DOT__core0.w_mip;
    vlSelf->m_topsim__DOT__w_load_res0 = vlSymsp->TOP__m_topsim__DOT__core0.w_load_res;
    vlSelf->m_topsim__DOT__w_reserved0 = vlSymsp->TOP__m_topsim__DOT__core0.w_reserved;
    vlSelf->m_topsim__DOT__w_pc0 = vlSymsp->TOP__m_topsim__DOT__core0.w_pc;
    vlSelf->m_topsim__DOT__bus_mem_paddr0 = vlSymsp->TOP__m_topsim__DOT__core0.w_mem_paddr;
    vlSelf->m_topsim__DOT__bus_tlb_busy0 = vlSymsp->TOP__m_topsim__DOT__core0.w_tlb_busy;
    vlSelf->m_topsim__DOT__w_hart_sc0 = vlSymsp->TOP__m_topsim__DOT__core0.w_hart_sc;
    vlSelf->m_topsim__DOT__bus_dram_wdata0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_wdata;
    vlSelf->m_topsim__DOT__w_ir0 = vlSymsp->TOP__m_topsim__DOT__core0.w_ir;
    vlSelf->m_topsim__DOT__bus_dram_we_t0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_we_t;
    vlSelf->m_topsim__DOT__bus_dram_ctrl0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_ctrl;
    vlSelf->m_topsim__DOT__bus_core_ir_0 = vlSymsp->TOP__m_topsim__DOT__core0.w_core_ir;
    vlSelf->m_topsim__DOT__bus_dram_addr0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_addr;
    vlSelf->m_topsim__DOT__bus_cpustate0 = vlSymsp->TOP__m_topsim__DOT__core0.w_state;
    vlSelf->m_topsim__DOT__bus_data_le0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_le;
    vlSelf->m_topsim__DOT__bus_data_we0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_we;
    vlSelf->m_topsim__DOT__bus_dram_le0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_le;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata0 
        = vlSelf->m_topsim__DOT__bus_data_wdata0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req0 = vlSelf->m_topsim__DOT__bus_tlb_req0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip0 = vlSelf->m_topsim__DOT__bus_mip0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr0 
        = vlSelf->m_topsim__DOT__bus_mem_paddr0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy0 = vlSelf->m_topsim__DOT__bus_tlb_busy0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata0 
        = vlSelf->m_topsim__DOT__bus_dram_wdata0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t0 
        = vlSelf->m_topsim__DOT__bus_dram_we_t0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl0 
        = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir0 = vlSelf->m_topsim__DOT__bus_core_ir_0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr0 
        = vlSelf->m_topsim__DOT__bus_dram_addr0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate0 = vlSelf->m_topsim__DOT__bus_cpustate0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le0 = vlSelf->m_topsim__DOT__bus_data_le0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we0 = vlSelf->m_topsim__DOT__bus_data_we0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le0 = vlSelf->m_topsim__DOT__bus_dram_le0;
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__2(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->m_topsim__DOT__w_ipi_taken1 = vlSymsp->TOP__m_topsim__DOT__core1.w_ipi_taken;
    vlSelf->m_topsim__DOT__w_pc_stip1 = vlSymsp->TOP__m_topsim__DOT__core1.w_pc_stip;
    vlSelf->m_topsim__DOT__bus_data_wdata1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_wdata;
    vlSelf->m_topsim__DOT__bus_tlb_req1 = vlSymsp->TOP__m_topsim__DOT__core1.w_tlb_req;
    vlSelf->m_topsim__DOT__bus_mip1 = vlSymsp->TOP__m_topsim__DOT__core1.w_mip;
    vlSelf->m_topsim__DOT__w_load_res1 = vlSymsp->TOP__m_topsim__DOT__core1.w_load_res;
    vlSelf->m_topsim__DOT__w_reserved1 = vlSymsp->TOP__m_topsim__DOT__core1.w_reserved;
    vlSelf->m_topsim__DOT__w_pc1 = vlSymsp->TOP__m_topsim__DOT__core1.w_pc;
    vlSelf->m_topsim__DOT__bus_mem_paddr1 = vlSymsp->TOP__m_topsim__DOT__core1.w_mem_paddr;
    vlSelf->m_topsim__DOT__bus_tlb_busy1 = vlSymsp->TOP__m_topsim__DOT__core1.w_tlb_busy;
    vlSelf->m_topsim__DOT__w_hart_sc1 = vlSymsp->TOP__m_topsim__DOT__core1.w_hart_sc;
    vlSelf->m_topsim__DOT__bus_dram_wdata1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_wdata;
    vlSelf->m_topsim__DOT__w_ir1 = vlSymsp->TOP__m_topsim__DOT__core1.w_ir;
    vlSelf->m_topsim__DOT__bus_dram_we_t1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_we_t;
    vlSelf->m_topsim__DOT__bus_dram_ctrl1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_ctrl;
    vlSelf->m_topsim__DOT__bus_core_ir_1 = vlSymsp->TOP__m_topsim__DOT__core1.w_core_ir;
    vlSelf->m_topsim__DOT__bus_dram_addr1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_addr;
    vlSelf->m_topsim__DOT__bus_cpustate1 = vlSymsp->TOP__m_topsim__DOT__core1.w_state;
    vlSelf->m_topsim__DOT__bus_data_le1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_le;
    vlSelf->m_topsim__DOT__bus_data_we1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_we;
    vlSelf->m_topsim__DOT__bus_dram_le1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_le;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata1 
        = vlSelf->m_topsim__DOT__bus_data_wdata1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req1 = vlSelf->m_topsim__DOT__bus_tlb_req1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip1 = vlSelf->m_topsim__DOT__bus_mip1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_load_res 
        = vlSelf->m_topsim__DOT__w_load_res1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_reserved 
        = vlSelf->m_topsim__DOT__w_reserved1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_pc = vlSelf->m_topsim__DOT__w_pc1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr1 
        = vlSelf->m_topsim__DOT__bus_mem_paddr1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy1 = vlSelf->m_topsim__DOT__bus_tlb_busy1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_sc = vlSelf->m_topsim__DOT__w_hart_sc1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata1 
        = vlSelf->m_topsim__DOT__bus_dram_wdata1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t1 
        = vlSelf->m_topsim__DOT__bus_dram_we_t1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl1 
        = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir1 = vlSelf->m_topsim__DOT__bus_core_ir_1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr1 
        = vlSelf->m_topsim__DOT__bus_dram_addr1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate1 = vlSelf->m_topsim__DOT__bus_cpustate1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le1 = vlSelf->m_topsim__DOT__bus_data_le1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we1 = vlSelf->m_topsim__DOT__bus_data_we1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le1 = vlSelf->m_topsim__DOT__bus_dram_le1;
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__4(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSymsp->TOP__m_topsim__DOT__core0.w_grant = vlSelf->m_topsim__DOT__w_grant;
    vlSymsp->TOP__m_topsim__DOT__core0.w_dram_busy 
        = vlSelf->m_topsim__DOT__bus_dram_busy0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_data_busy 
        = vlSelf->m_topsim__DOT__bus_data_busy0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_dram_odata 
        = vlSelf->m_topsim__DOT__bus_dram_odata0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_plic_we = vlSelf->m_topsim__DOT__bus_plic_we0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_wmip = vlSelf->m_topsim__DOT__bus_wmip0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_ipi = vlSelf->m_topsim__DOT__bus_ipi;
    vlSymsp->TOP__m_topsim__DOT__core1.w_grant = vlSelf->m_topsim__DOT__w_grant;
    vlSymsp->TOP__m_topsim__DOT__core1.w_dram_busy 
        = vlSelf->m_topsim__DOT__bus_dram_busy1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_data_busy 
        = vlSelf->m_topsim__DOT__bus_data_busy1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_dram_odata 
        = vlSelf->m_topsim__DOT__bus_dram_odata1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_plic_we = vlSelf->m_topsim__DOT__bus_plic_we1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_wmip = vlSelf->m_topsim__DOT__bus_wmip1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_ipi = vlSelf->m_topsim__DOT__bus_ipi;
    vlSelf->m_topsim__DOT__w_dram_ctrl_t = ((IData)(vlSelf->m_topsim__DOT__w_init_done)
                                             ? (IData)(vlSelf->m_topsim__DOT__w_dram_ctrl)
                                             : 2U);
    vlSelf->m_topsim__DOT__w_dram_wdata_t = ((1U == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                              ? 0U : 
                                             ((IData)(vlSelf->m_topsim__DOT__w_init_done)
                                               ? vlSelf->m_topsim__DOT__w_dram_wdata
                                               : ((3U 
                                                   == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                                   ? vlSelf->m_topsim__DOT__r_sd_init_data
                                                   : vlSelf->m_topsim__DOT__w_pl_init_data)));
    vlSelf->m_topsim__DOT__w_mtime = vlSelf->m_topsim__DOT__mtime;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_ctrl = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_data = vlSelf->m_topsim__DOT__w_dram_wdata_t;
    vlSelf->m_topsim__DOT__ba__DOT__w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSelf->m_topsim__DOT__rf__DOT__w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSymsp->TOP__m_topsim__DOT__core0.w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSymsp->TOP__m_topsim__DOT__core1.w_mtime = vlSelf->m_topsim__DOT__w_mtime;
}

VL_INLINE_OPT void Vm_topsim___024root___nba_sequent__TOP__5(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_load_res 
        = vlSelf->m_topsim__DOT__w_load_res0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_sc = vlSelf->m_topsim__DOT__w_hart_sc0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_reserved 
        = vlSelf->m_topsim__DOT__w_reserved0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_pc = vlSelf->m_topsim__DOT__w_pc0;
}

void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__1(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__2(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim___024root___nba_sequent__TOP__3(Vm_topsim___024root* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__3(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__2(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__4(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__3(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core1__0(Vm_topsim_m_cpummu* vlSelf);
void Vm_topsim___024root___nba_comb__TOP__0(Vm_topsim___024root* vlSelf);

void Vm_topsim___024root___eval_nba(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vm_topsim___024root___nba_sequent__TOP__0(vlSelf);
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core0));
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core1));
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__1((&vlSymsp->TOP__m_topsim__DOT__core0));
        Vm_topsim___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__1((&vlSymsp->TOP__m_topsim__DOT__core1));
        Vm_topsim___024root___nba_sequent__TOP__2(vlSelf);
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__2((&vlSymsp->TOP__m_topsim__DOT__core0));
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vm_topsim___024root___nba_sequent__TOP__3(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__3((&vlSymsp->TOP__m_topsim__DOT__core0));
        Vm_topsim___024root___nba_sequent__TOP__4(vlSelf);
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__2((&vlSymsp->TOP__m_topsim__DOT__core1));
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core0__4((&vlSymsp->TOP__m_topsim__DOT__core0));
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core0));
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vm_topsim___024root___nba_sequent__TOP__5(vlSelf);
        Vm_topsim_m_cpummu___nba_sequent__TOP__m_topsim__DOT__core1__3((&vlSymsp->TOP__m_topsim__DOT__core1));
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(3U))) {
        Vm_topsim_m_cpummu___nba_comb__TOP__m_topsim__DOT__core1__0((&vlSymsp->TOP__m_topsim__DOT__core1));
    }
    if (((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U)) 
         | vlSelf->__VnbaTriggered.at(3U))) {
        Vm_topsim___024root___nba_comb__TOP__0(vlSelf);
    }
}
