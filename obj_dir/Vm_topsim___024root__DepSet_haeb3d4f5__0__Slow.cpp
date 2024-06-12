// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim___024root.h"

VL_ATTR_COLD void Vm_topsim___024root___eval_static__TOP(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->m_topsim__DOT__mtime = 0ULL;
    vlSelf->m_topsim__DOT__r_plic_aces_t = 0U;
    vlSelf->m_topsim__DOT__r_plic_odata = 0U;
    vlSelf->m_topsim__DOT__r_clint_odata = 0U;
    vlSelf->m_topsim__DOT__r_consf_cnts = 0U;
    vlSelf->m_topsim__DOT__r_char_value = 0U;
    vlSelf->m_topsim__DOT__r_uart_we = 0U;
    vlSelf->m_topsim__DOT__r_uart_data = 0U;
    vlSelf->m_topsim__DOT__r_mem_paddr = 0U;
    vlSelf->m_topsim__DOT__r_data_le = 0U;
    vlSelf->m_topsim__DOT__r_data_we = 0U;
    vlSelf->m_topsim__DOT__r_data_busy = 0U;
    vlSelf->m_topsim__DOT__r_dev = 0U;
    vlSelf->m_topsim__DOT__r_virt = 0U;
    vlSelf->m_topsim__DOT__r_max_displays = 0U;
    vlSelf->m_topsim__DOT__r_ipi = 0U;
    vlSelf->m_topsim__DOT__r_wait_ready = 1U;
    vlSelf->m_topsim__DOT__r_finish = 0U;
    vlSelf->m_topsim__DOT__r_consf_head = 0U;
    vlSelf->m_topsim__DOT__r_consf_tail = 0U;
    vlSelf->m_topsim__DOT__r_consf_en = 0U;
    vlSelf->m_topsim__DOT__r_key_we = 0U;
    vlSelf->m_topsim__DOT__r_key_data = 0U;
    vlSelf->m_topsim__DOT__r_sd_init_we = 0U;
    vlSelf->m_topsim__DOT__r_sd_init_data = 0U;
    vlSelf->m_topsim__DOT__r_init_state = 5U;
    vlSelf->m_topsim__DOT__r_initaddr = 0U;
    vlSelf->m_topsim__DOT__r_initaddr3 = 0U;
    vlSelf->m_topsim__DOT__r_checksum = 0U;
    vlSelf->m_topsim__DOT__r_sd_checksum = 0U;
    vlSelf->m_topsim__DOT__r_bbl_done = 0U;
    vlSelf->m_topsim__DOT__r_bblsd_done = 0U;
    vlSelf->m_topsim__DOT__r_disk_done = 0U;
    vlSelf->m_topsim__DOT__r_initaddr2 = 0x800000U;
    vlSelf->m_topsim__DOT__r_zero_we = 0U;
    vlSelf->m_topsim__DOT__r_zero_done = 0U;
    vlSelf->m_topsim__DOT__r_zeroaddr = 0U;
    vlSelf->m_topsim__DOT__r_set_dram_le = 0U;
    vlSelf->m_topsim__DOT__old_w_mtime = 0ULL;
    vlSelf->m_topsim__DOT__old_mem_paddr = 0U;
    vlSelf->m_topsim__DOT__old_data_data = 0U;
    vlSelf->m_topsim__DOT__old_pc0 = 0U;
    vlSelf->m_topsim__DOT__rcnt = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__grant = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__state = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1_aux = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data0 = 0U;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data1 = 0U;
    vlSelf->m_topsim__DOT__ploader__DOT__waddr = 0U;
    vlSelf->m_topsim__DOT__w_file_we = 0U;
    vlSelf->m_topsim__DOT__rf__DOT__c = 0U;
    vlSelf->m_topsim__DOT__rf__DOT__oldc = 1U;
    vlSelf->m_topsim__DOT__rf__DOT__boot_done = 0U;
    vlSelf->m_topsim__DOT__rf__DOT__wait_delay = 0ULL;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata1 = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata2 = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_stall = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__state_next = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__state = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__read_request = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__write_request = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_cnt = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_odata = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0U;
}

VL_ATTR_COLD void Vm_topsim___024root___eval_final(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vm_topsim___024root___eval_triggers__stl(Vm_topsim___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__stl(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___eval_stl(Vm_topsim___024root* vlSelf);

VL_ATTR_COLD void Vm_topsim___024root___eval_settle(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vm_topsim___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if ((0x64U < vlSelf->__VstlIterCount)) {
#ifdef VL_DEBUG
                Vm_topsim___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("maintn.v", 65, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vm_topsim___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__stl(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__ico(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__act(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge m_topsim.pll_clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge CLK)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge m_topsim.core0.CLK)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge m_topsim.core1.CLK)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__nba(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge m_topsim.pll_clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge CLK)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge m_topsim.core0.CLK)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge m_topsim.core1.CLK)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vm_topsim___024root___ctor_var_reset(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->CLK = 0;
    vlSelf->RST_X = 0;
    vlSelf->m_topsim__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__RST_X = 0;
    vlSelf->m_topsim__DOT__pll_clk = 0;
    vlSelf->m_topsim__DOT__w_txd = 0;
    vlSelf->m_topsim__DOT__w_rxd = 0;
    vlSelf->m_topsim__DOT__clk_sdram = 0;
    vlSelf->m_topsim__DOT__MAX7219_CLK = 0;
    vlSelf->m_topsim__DOT__MAX7219_DATA = 0;
    vlSelf->m_topsim__DOT__MAX7219_LOAD = 0;
    vlSelf->m_topsim__DOT__w_init_done = 0;
    vlSelf->m_topsim__DOT__bus_core_ir_0 = 0;
    vlSelf->m_topsim__DOT__bus_core_ir_1 = 0;
    vlSelf->m_topsim__DOT__bus_cpustate0 = 0;
    vlSelf->m_topsim__DOT__bus_cpustate1 = 0;
    vlSelf->m_topsim__DOT__w_bus_cpustate = 0;
    vlSelf->m_topsim__DOT__w_mem_paddr = 0;
    vlSelf->m_topsim__DOT__bus_mem_paddr0 = 0;
    vlSelf->m_topsim__DOT__bus_mem_paddr1 = 0;
    vlSelf->m_topsim__DOT__w_data_we = 0;
    vlSelf->m_topsim__DOT__bus_data_we0 = 0;
    vlSelf->m_topsim__DOT__bus_data_we1 = 0;
    vlSelf->m_topsim__DOT__w_data_le = 0;
    vlSelf->m_topsim__DOT__bus_data_le0 = 0;
    vlSelf->m_topsim__DOT__bus_data_le1 = 0;
    vlSelf->m_topsim__DOT__bus_data_busy0 = 0;
    vlSelf->m_topsim__DOT__bus_data_busy1 = 0;
    vlSelf->m_topsim__DOT__w_data_wdata = 0;
    vlSelf->m_topsim__DOT__bus_data_wdata0 = 0;
    vlSelf->m_topsim__DOT__bus_data_wdata1 = 0;
    vlSelf->m_topsim__DOT__w_data_data = 0;
    vlSelf->m_topsim__DOT__bus_data_data0 = 0;
    vlSelf->m_topsim__DOT__bus_data_data1 = 0;
    vlSelf->m_topsim__DOT__w_mtimecmp0 = 0;
    vlSelf->m_topsim__DOT__w_mtimecmp1 = 0;
    vlSelf->m_topsim__DOT__w_wmtimecmp0 = 0;
    vlSelf->m_topsim__DOT__w_wmtimecmp1 = 0;
    vlSelf->m_topsim__DOT__w_clint_we0 = 0;
    vlSelf->m_topsim__DOT__w_clint_we1 = 0;
    vlSelf->m_topsim__DOT__w_tlb_req = 0;
    vlSelf->m_topsim__DOT__bus_tlb_req0 = 0;
    vlSelf->m_topsim__DOT__bus_tlb_req1 = 0;
    vlSelf->m_topsim__DOT__w_tlb_busy = 0;
    vlSelf->m_topsim__DOT__bus_tlb_busy0 = 0;
    vlSelf->m_topsim__DOT__bus_tlb_busy1 = 0;
    vlSelf->m_topsim__DOT__w_mip = 0;
    vlSelf->m_topsim__DOT__w_wmip = 0;
    vlSelf->m_topsim__DOT__bus_mip0 = 0;
    vlSelf->m_topsim__DOT__bus_wmip0 = 0;
    vlSelf->m_topsim__DOT__bus_mip1 = 0;
    vlSelf->m_topsim__DOT__bus_wmip1 = 0;
    vlSelf->m_topsim__DOT__w_plic_we = 0;
    vlSelf->m_topsim__DOT__bus_plic_we0 = 0;
    vlSelf->m_topsim__DOT__bus_plic_we1 = 0;
    vlSelf->m_topsim__DOT__w_dram_addr = 0;
    vlSelf->m_topsim__DOT__bus_dram_addr0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_addr1 = 0;
    vlSelf->m_topsim__DOT__w_dram_wdata = 0;
    vlSelf->m_topsim__DOT__bus_dram_wdata0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_wdata1 = 0;
    vlSelf->m_topsim__DOT__w_dram_odata = 0;
    vlSelf->m_topsim__DOT__bus_dram_odata0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_odata1 = 0;
    vlSelf->m_topsim__DOT__w_dram_we_t = 0;
    vlSelf->m_topsim__DOT__bus_dram_we_t0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_we_t1 = 0;
    vlSelf->m_topsim__DOT__w_dram_busy = 0;
    vlSelf->m_topsim__DOT__bus_dram_busy0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_busy1 = 0;
    vlSelf->m_topsim__DOT__w_dram_ctrl = 0;
    vlSelf->m_topsim__DOT__bus_dram_ctrl0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_ctrl1 = 0;
    vlSelf->m_topsim__DOT__w_dram_le = 0;
    vlSelf->m_topsim__DOT__bus_dram_le0 = 0;
    vlSelf->m_topsim__DOT__bus_dram_le1 = 0;
    vlSelf->m_topsim__DOT__w_pc0 = 0;
    vlSelf->m_topsim__DOT__w_pc1 = 0;
    vlSelf->m_topsim__DOT__w_ir0 = 0;
    vlSelf->m_topsim__DOT__w_ir1 = 0;
    vlSelf->m_topsim__DOT__w_pc_stip0 = 0;
    vlSelf->m_topsim__DOT__w_pc_stip1 = 0;
    vlSelf->m_topsim__DOT__w_load_res0 = 0;
    vlSelf->m_topsim__DOT__w_load_res1 = 0;
    vlSelf->m_topsim__DOT__w_reserved0 = 0;
    vlSelf->m_topsim__DOT__w_reserved1 = 0;
    vlSelf->m_topsim__DOT__w_hart_sc0 = 0;
    vlSelf->m_topsim__DOT__w_hart_sc1 = 0;
    vlSelf->m_topsim__DOT__w_grant = 0;
    vlSelf->m_topsim__DOT__bus_ipi = 0;
    vlSelf->m_topsim__DOT__w_ipi_taken0 = 0;
    vlSelf->m_topsim__DOT__w_ipi_taken1 = 0;
    vlSelf->m_topsim__DOT__mtime = 0;
    vlSelf->m_topsim__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__w_tx_ready = 0;
    vlSelf->m_topsim__DOT__w_plic_aces = 0;
    vlSelf->m_topsim__DOT__r_plic_aces_t = 0;
    vlSelf->m_topsim__DOT__r_plic_odata = 0;
    vlSelf->m_topsim__DOT__r_clint_odata = 0;
    vlSelf->m_topsim__DOT__r_consf_cnts = 0;
    vlSelf->m_topsim__DOT__r_char_value = 0;
    vlSelf->m_topsim__DOT__r_uart_we = 0;
    vlSelf->m_topsim__DOT__r_uart_data = 0;
    vlSelf->m_topsim__DOT__w_key_we = 0;
    vlSelf->m_topsim__DOT__w_key_data = 0;
    vlSelf->m_topsim__DOT__w_dev = 0;
    vlSelf->m_topsim__DOT__w_virt = 0;
    vlSelf->m_topsim__DOT__w_offset = 0;
    vlSelf->m_topsim__DOT__r_mem_paddr = 0;
    vlSelf->m_topsim__DOT__r_data_le = 0;
    vlSelf->m_topsim__DOT__r_data_we = 0;
    vlSelf->m_topsim__DOT__r_data_busy = 0;
    vlSelf->m_topsim__DOT__r_dev = 0;
    vlSelf->m_topsim__DOT__r_virt = 0;
    vlSelf->m_topsim__DOT__r_data_data = 0;
    vlSelf->m_topsim__DOT__w_isread = 0;
    vlSelf->m_topsim__DOT__w_iswrite = 0;
    vlSelf->m_topsim__DOT__r_max_displays = 0;
    vlSelf->m_topsim__DOT__r_ipi = 0;
    vlSelf->m_topsim__DOT__r_wait_ready = 0;
    vlSelf->m_topsim__DOT__r_finish = 0;
    vlSelf->m_topsim__DOT__w_pl_init_addr = 0;
    vlSelf->m_topsim__DOT__w_pl_init_data = 0;
    vlSelf->m_topsim__DOT__w_pl_init_done = 0;
    vlSelf->m_topsim__DOT__w_pl_init_we = 0;
    vlSelf->m_topsim__DOT__r_consf_head = 0;
    vlSelf->m_topsim__DOT__r_consf_tail = 0;
    vlSelf->m_topsim__DOT__r_consf_en = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->m_topsim__DOT__cons_fifo[__Vi0] = 0;
    }
    vlSelf->m_topsim__DOT__w_file_we = 0;
    vlSelf->m_topsim__DOT__r_key_we = 0;
    vlSelf->m_topsim__DOT__r_key_data = 0;
    vlSelf->m_topsim__DOT__i = 0;
    vlSelf->m_topsim__DOT__r_sd_init_we = 0;
    vlSelf->m_topsim__DOT__r_sd_init_data = 0;
    vlSelf->m_topsim__DOT__r_init_state = 0;
    vlSelf->m_topsim__DOT__r_initaddr = 0;
    vlSelf->m_topsim__DOT__r_initaddr3 = 0;
    vlSelf->m_topsim__DOT__r_checksum = 0;
    vlSelf->m_topsim__DOT__r_sd_checksum = 0;
    vlSelf->m_topsim__DOT__w_checksum = 0;
    vlSelf->m_topsim__DOT__w_sd_checksum = 0;
    vlSelf->m_topsim__DOT__r_bbl_done = 0;
    vlSelf->m_topsim__DOT__r_bblsd_done = 0;
    vlSelf->m_topsim__DOT__r_disk_done = 0;
    vlSelf->m_topsim__DOT__r_initaddr2 = 0;
    vlSelf->m_topsim__DOT__w_zero_we = 0;
    vlSelf->m_topsim__DOT__r_zero_we = 0;
    vlSelf->m_topsim__DOT__r_zero_done = 0;
    vlSelf->m_topsim__DOT__r_zeroaddr = 0;
    vlSelf->m_topsim__DOT__w_init_state = 0;
    vlSelf->m_topsim__DOT__r_set_dram_le = 0;
    vlSelf->m_topsim__DOT__calib_done = 0;
    vlSelf->m_topsim__DOT__w_dram_addr_t = 0;
    vlSelf->m_topsim__DOT__w_dram_addr_t2 = 0;
    vlSelf->m_topsim__DOT__w_dram_wdata_t = 0;
    vlSelf->m_topsim__DOT__w_dram_ctrl_t = 0;
    vlSelf->m_topsim__DOT__w_wr_en = 0;
    vlSelf->m_topsim__DOT__sdram_fail = 0;
    vlSelf->m_topsim__DOT__w_late_refresh = 0;
    vlSelf->m_topsim__DOT__w_mem_state = 0;
    vlSelf->m_topsim__DOT__old_w_mtime = 0;
    vlSelf->m_topsim__DOT__old_mem_paddr = 0;
    vlSelf->m_topsim__DOT__old_data_data = 0;
    vlSelf->m_topsim__DOT__old_pc0 = 0;
    vlSelf->m_topsim__DOT__rcnt = 0;
    vlSelf->m_topsim__DOT__ba__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__ba__DOT__RST_X = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_grant = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_init_done = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_tx_ready = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_mem_paddr = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_we = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_le = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_busy = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_wdata = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_data = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_req = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_busy = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_mip = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_wmip = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_plic_aces = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_plic_aces_t = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_plic_we = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_addr = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_wdata = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_odata = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_we_t = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_busy = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_ctrl = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_le = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_wmip0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_wmip1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__grant = 0;
    vlSelf->m_topsim__DOT__ba__DOT__state = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_pending_req1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_core_ir = 0;
    vlSelf->m_topsim__DOT__ba__DOT__w_bus_cpustate = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1_aux = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data0 = 0;
    vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data1 = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__RST_X = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__DATA = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__WE = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__TXD = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__READY = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__cmd = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__waitnum = 0;
    vlSelf->m_topsim__DOT__UartTx0__DOT__cnt = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__RST_X = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__RXD = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__ADDR = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__DATA = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__WE = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__DONE = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_WE = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_DATA = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__waddr = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__SER_EN = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__RST_X = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__RXD = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__DATA = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__EN = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__stage = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__cnt_start = 0;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__waitcnt = 0;
    vlSelf->m_topsim__DOT__rf__DOT__clk = 0;
    vlSelf->m_topsim__DOT__rf__DOT__r_consf_en = 0;
    vlSelf->m_topsim__DOT__rf__DOT__we = 0;
    vlSelf->m_topsim__DOT__rf__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__rf__DOT__min_time = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->m_topsim__DOT__rf__DOT__fifo[__Vi0] = 0;
    }
    vlSelf->m_topsim__DOT__rf__DOT__c = 0;
    vlSelf->m_topsim__DOT__rf__DOT__oldc = 0;
    vlSelf->m_topsim__DOT__rf__DOT__fid = 0;
    vlSelf->m_topsim__DOT__rf__DOT__fcmd = 0;
    vlSelf->m_topsim__DOT__rf__DOT__n = 0;
    vlSelf->m_topsim__DOT__rf__DOT__i = 0;
    VL_ZERO_RESET_W(800, vlSelf->m_topsim__DOT__rf__DOT__line);
    vlSelf->m_topsim__DOT__rf__DOT__boot_done = 0;
    vlSelf->m_topsim__DOT__rf__DOT__wait_delay = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_rd_en = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_wr_en = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_addr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_data = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_data = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_busy = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_ctrl = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__sys_state = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_bus_cpustate = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__mem_state = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_late_refresh = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__clk = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__rst_x = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__clk_sdram = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_init_calib_complete = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__sdram_fail = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_we = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_rd = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_busy = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_mask = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_ctrl = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata1 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata2 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_addr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_odata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata_ui = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_stall = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__state_next = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__state = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_refreshcnt = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__read_request = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__write_request = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__i = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__j = 0;
    for (int __Vi0 = 0; __Vi0 < 8388608; ++__Vi0) {
        vlSelf->m_topsim__DOT__dram_con__DOT__mem_bbl[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 67108864; ++__Vi0) {
        vlSelf->m_topsim__DOT__dram_con__DOT__mem_disk[__Vi0] = 0;
    }
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_addr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_odata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_we = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_le = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_wdata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mask = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_stall = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_refresh = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__CLK = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_addr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_odata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_we = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_le = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_wdata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mask = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_stall = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mtime = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_refresh = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_mask = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_cnt = 0;
    for (int __Vi0 = 0; __Vi0 < 8388608; ++__Vi0) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[__Vi0] = 0;
    }
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_odata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_refresh_cnt = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_maddr = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data3 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data2 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data1 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_data0 = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_wdata = 0;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__state = 0;
    vlSelf->__VstlIterCount = 0;
    vlSelf->__VicoIterCount = 0;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__pll_clk = 0;
    vlSelf->__Vtrigrprev__TOP__CLK = 0;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core0__CLK = 0;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core1__CLK = 0;
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
