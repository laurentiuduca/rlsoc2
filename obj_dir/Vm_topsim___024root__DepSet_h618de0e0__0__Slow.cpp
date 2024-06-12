// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim__Syms.h"
#include "Vm_topsim___024root.h"

VL_ATTR_COLD void Vm_topsim___024root___eval_static__TOP(Vm_topsim___024root* vlSelf);
VL_ATTR_COLD void Vm_topsim_m_cpummu___eval_static__TOP__m_topsim__DOT__core0(Vm_topsim_m_cpummu* vlSelf);

VL_ATTR_COLD void Vm_topsim___024root___eval_static(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_static\n"); );
    // Body
    Vm_topsim___024root___eval_static__TOP(vlSelf);
    Vm_topsim_m_cpummu___eval_static__TOP__m_topsim__DOT__core0((&vlSymsp->TOP__m_topsim__DOT__core0));
    Vm_topsim_m_cpummu___eval_static__TOP__m_topsim__DOT__core0((&vlSymsp->TOP__m_topsim__DOT__core1));
}

VL_ATTR_COLD void Vm_topsim___024root___eval_initial__TOP(Vm_topsim___024root* vlSelf);
VL_ATTR_COLD void Vm_topsim_m_cpummu___eval_initial__TOP__m_topsim__DOT__core0(Vm_topsim_m_cpummu* vlSelf);

VL_ATTR_COLD void Vm_topsim___024root___eval_initial(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_initial\n"); );
    // Body
    Vm_topsim___024root___eval_initial__TOP(vlSelf);
    Vm_topsim_m_cpummu___eval_initial__TOP__m_topsim__DOT__core0((&vlSymsp->TOP__m_topsim__DOT__core0));
    Vm_topsim_m_cpummu___eval_initial__TOP__m_topsim__DOT__core0((&vlSymsp->TOP__m_topsim__DOT__core1));
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__pll_clk 
        = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->__Vtrigrprev__TOP__CLK = vlSelf->CLK;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core0__CLK 
        = vlSymsp->TOP__m_topsim__DOT__core0.CLK;
    vlSelf->__Vtrigrprev__TOP__m_topsim__DOT__core1__CLK 
        = vlSymsp->TOP__m_topsim__DOT__core1.CLK;
}

VL_ATTR_COLD void Vm_topsim___024root___eval_initial__TOP(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_hae308c8e__0;
    VlWide<7>/*223:0*/ __Vtemp_h0c347c7e__0;
    // Body
    vlSymsp->TOP__m_topsim__DOT__core0.w_hart_id = 0U;
    vlSymsp->TOP__m_topsim__DOT__core1.w_hart_id = 1U;
    vlSelf->m_topsim__DOT__r_consf_en = 0U;
    vlSelf->m_topsim__DOT__r_consf_head = 0U;
    vlSelf->m_topsim__DOT__r_consf_tail = 0U;
    vlSelf->m_topsim__DOT__r_consf_cnts = 0U;
    vlSelf->m_topsim__DOT__w_plic_we = 0U;
    vlSelf->m_topsim__DOT__w_wmip = 0U;
    vlSelf->m_topsim__DOT__w_zero_we = 0U;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__waitcnt = 2U;
    VL_WRITEF("Load image file: ../binary/init_disk.txt\n");
    __Vtemp_hae308c8e__0[0U] = 0x2e747874U;
    __Vtemp_hae308c8e__0[1U] = 0x6469736bU;
    __Vtemp_hae308c8e__0[2U] = 0x6e69745fU;
    __Vtemp_hae308c8e__0[3U] = 0x72792f69U;
    __Vtemp_hae308c8e__0[4U] = 0x62696e61U;
    __Vtemp_hae308c8e__0[5U] = 0x2e2e2fU;
    VL_READMEM_N(true, 8, 67108864, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_hae308c8e__0)
                 ,  &(vlSelf->m_topsim__DOT__dram_con__DOT__mem_disk)
                 , 0, ~0ULL);
    vlSelf->m_topsim__DOT__dram_con__DOT__j = 0x800000U;
    vlSelf->m_topsim__DOT__dram_con__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4000000U, vlSelf->m_topsim__DOT__dram_con__DOT__i)) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[(0x7fffffU 
                                                                             & vlSelf->m_topsim__DOT__dram_con__DOT__j)] 
            = vlSelf->m_topsim__DOT__dram_con__DOT__mem_disk
            [(0x3ffffffU & vlSelf->m_topsim__DOT__dram_con__DOT__i)];
        vlSelf->m_topsim__DOT__dram_con__DOT__j = ((IData)(1U) 
                                                   + vlSelf->m_topsim__DOT__dram_con__DOT__j);
        vlSelf->m_topsim__DOT__dram_con__DOT__i = ((IData)(1U) 
                                                   + vlSelf->m_topsim__DOT__dram_con__DOT__i);
    }
    VL_WRITEF("Running ./../binary/init_kernel.txt\n");
    __Vtemp_h0c347c7e__0[0U] = 0x2e747874U;
    __Vtemp_h0c347c7e__0[1U] = 0x726e656cU;
    __Vtemp_h0c347c7e__0[2U] = 0x745f6b65U;
    __Vtemp_h0c347c7e__0[3U] = 0x2f696e69U;
    __Vtemp_h0c347c7e__0[4U] = 0x6e617279U;
    __Vtemp_h0c347c7e__0[5U] = 0x2e2f6269U;
    __Vtemp_h0c347c7e__0[6U] = 0x2e2f2eU;
    VL_READMEM_N(true, 8, 8388608, 0, VL_CVT_PACK_STR_NW(7, __Vtemp_h0c347c7e__0)
                 ,  &(vlSelf->m_topsim__DOT__dram_con__DOT__mem_bbl)
                 , 0, ~0ULL);
    vlSelf->m_topsim__DOT__dram_con__DOT__j = 0U;
    vlSelf->m_topsim__DOT__dram_con__DOT__i = 0U;
    while (VL_GTS_III(32, 0x800000U, vlSelf->m_topsim__DOT__dram_con__DOT__i)) {
        vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__mem[(0x7fffffU 
                                                                             & vlSelf->m_topsim__DOT__dram_con__DOT__j)] 
            = vlSelf->m_topsim__DOT__dram_con__DOT__mem_bbl
            [(0x7fffffU & vlSelf->m_topsim__DOT__dram_con__DOT__i)];
        vlSelf->m_topsim__DOT__dram_con__DOT__j = ((IData)(1U) 
                                                   + vlSelf->m_topsim__DOT__dram_con__DOT__j);
        vlSelf->m_topsim__DOT__dram_con__DOT__i = ((IData)(1U) 
                                                   + vlSelf->m_topsim__DOT__dram_con__DOT__i);
    }
    VL_WRITEF("-------------------------------------------------------------------\n");
    vlSelf->m_topsim__DOT__rf__DOT__min_time = 0x4f463080ULL;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vm_topsim___024root___dump_triggers__stl(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vm_topsim___024root___eval_triggers__stl(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vm_topsim___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vm_topsim___024root___stl_sequent__TOP__0(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___stl_sequent__TOP__0\n"); );
    // Init
    QData/*55:0*/ m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0;
    // Body
    vlSelf->m_topsim__DOT__CLK = vlSelf->CLK;
    vlSelf->m_topsim__DOT__w_ipi_taken0 = vlSymsp->TOP__m_topsim__DOT__core0.w_ipi_taken;
    vlSelf->m_topsim__DOT__w_pc_stip0 = vlSymsp->TOP__m_topsim__DOT__core0.w_pc_stip;
    vlSelf->m_topsim__DOT__w_ir0 = vlSymsp->TOP__m_topsim__DOT__core0.w_ir;
    vlSelf->m_topsim__DOT__w_ipi_taken1 = vlSymsp->TOP__m_topsim__DOT__core1.w_ipi_taken;
    vlSelf->m_topsim__DOT__w_pc_stip1 = vlSymsp->TOP__m_topsim__DOT__core1.w_pc_stip;
    vlSelf->m_topsim__DOT__w_ir1 = vlSymsp->TOP__m_topsim__DOT__core1.w_ir;
    vlSelf->m_topsim__DOT__ba__DOT__w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_busy = vlSelf->m_topsim__DOT__r_data_busy;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy0 
        = vlSelf->m_topsim__DOT__bus_data_busy0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_busy1 
        = vlSelf->m_topsim__DOT__bus_data_busy1;
    vlSelf->m_topsim__DOT__ba__DOT__w_wmip = vlSelf->m_topsim__DOT__w_wmip;
    vlSelf->m_topsim__DOT__ba__DOT__w_plic_aces = vlSelf->m_topsim__DOT__w_plic_aces;
    vlSelf->m_topsim__DOT__ba__DOT__r_plic_aces_t = vlSelf->m_topsim__DOT__r_plic_aces_t;
    vlSelf->m_topsim__DOT__ba__DOT__w_plic_we = vlSelf->m_topsim__DOT__w_plic_we;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy0 
        = vlSelf->m_topsim__DOT__bus_dram_busy0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_busy1 
        = vlSelf->m_topsim__DOT__bus_dram_busy1;
    vlSelf->m_topsim__DOT__UartTx0__DOT__DATA = vlSelf->m_topsim__DOT__r_uart_data;
    vlSelf->m_topsim__DOT__UartTx0__DOT__WE = vlSelf->m_topsim__DOT__r_uart_we;
    vlSelf->m_topsim__DOT__UartTx0__DOT__TXD = vlSelf->m_topsim__DOT__w_txd;
    vlSelf->m_topsim__DOT__UartTx0__DOT__READY = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__ploader__DOT__ADDR = vlSelf->m_topsim__DOT__w_pl_init_addr;
    vlSelf->m_topsim__DOT__ploader__DOT__DATA = vlSelf->m_topsim__DOT__w_pl_init_data;
    vlSelf->m_topsim__DOT__ploader__DOT__WE = vlSelf->m_topsim__DOT__w_pl_init_we;
    vlSelf->m_topsim__DOT__ploader__DOT__DONE = vlSelf->m_topsim__DOT__w_pl_init_done;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__DATA 
        = vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__EN 
        = vlSelf->m_topsim__DOT__ploader__DOT__SER_EN;
    vlSelf->m_topsim__DOT__rf__DOT__r_consf_en = vlSelf->m_topsim__DOT__r_consf_en;
    vlSelf->m_topsim__DOT__rf__DOT__we = vlSelf->m_topsim__DOT__w_file_we;
    vlSelf->m_topsim__DOT__dram_con__DOT__sys_state 
        = vlSelf->m_topsim__DOT__r_init_state;
    vlSelf->m_topsim__DOT__dram_con__DOT__r_late_refresh 
        = vlSelf->m_topsim__DOT__w_late_refresh;
    vlSelf->m_topsim__DOT__dram_con__DOT__clk_sdram 
        = vlSelf->m_topsim__DOT__clk_sdram;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_init_calib_complete 
        = vlSelf->m_topsim__DOT__calib_done;
    vlSelf->m_topsim__DOT__dram_con__DOT__sdram_fail 
        = vlSelf->m_topsim__DOT__sdram_fail;
    vlSelf->m_topsim__DOT__w_init_state = vlSelf->m_topsim__DOT__r_init_state;
    vlSelf->m_topsim__DOT__w_checksum = vlSelf->m_topsim__DOT__r_checksum;
    vlSelf->m_topsim__DOT__w_sd_checksum = vlSelf->m_topsim__DOT__r_sd_checksum;
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
    vlSelf->m_topsim__DOT__ba__DOT__w_sys_busy = (1U 
                                                  & ((~ (IData)(vlSelf->m_topsim__DOT__w_tx_ready)) 
                                                     | ((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_stall) 
                                                        | (0U 
                                                           != (IData)(vlSelf->m_topsim__DOT__r_data_busy)))));
    vlSymsp->TOP__m_topsim__DOT__core0.w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSymsp->TOP__m_topsim__DOT__core1.w_tx_ready = vlSelf->m_topsim__DOT__w_tx_ready;
    vlSelf->m_topsim__DOT__ploader__DOT__RXD = vlSelf->m_topsim__DOT__w_rxd;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_addr 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_maddr;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_we 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_we;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_le 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_rd;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_wdata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_wdata;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mask 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_mask;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_refresh 
        = vlSelf->m_topsim__DOT__dram_con__DOT__r_refresh;
    vlSelf->m_topsim__DOT__w_key_data = vlSelf->m_topsim__DOT__ploader__DOT__SER_DATA;
    vlSelf->m_topsim__DOT__w_mem_state = vlSelf->m_topsim__DOT__dram_con__DOT__state;
    vlSelf->m_topsim__DOT__w_key_we = ((IData)(vlSelf->m_topsim__DOT__ploader__DOT__SER_EN) 
                                       & (IData)(vlSelf->m_topsim__DOT__w_pl_init_done));
    vlSelf->m_topsim__DOT__w_load_res0 = vlSymsp->TOP__m_topsim__DOT__core0.w_load_res;
    vlSelf->m_topsim__DOT__w_reserved0 = vlSymsp->TOP__m_topsim__DOT__core0.w_reserved;
    vlSelf->m_topsim__DOT__w_pc0 = vlSymsp->TOP__m_topsim__DOT__core0.w_pc;
    vlSelf->m_topsim__DOT__w_load_res1 = vlSymsp->TOP__m_topsim__DOT__core1.w_load_res;
    vlSelf->m_topsim__DOT__w_reserved1 = vlSymsp->TOP__m_topsim__DOT__core1.w_reserved;
    vlSelf->m_topsim__DOT__w_pc1 = vlSymsp->TOP__m_topsim__DOT__core1.w_pc;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_mtime = (IData)(
                                                            (vlSelf->m_topsim__DOT__mtime 
                                                             >> 0U));
    vlSelf->m_topsim__DOT__w_dram_busy = vlSelf->m_topsim__DOT__dram_con__DOT__r_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_busy = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__r_odata;
    if ((0U != vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__bus_wmip1 = vlSelf->m_topsim__DOT__w_wmip;
        vlSelf->m_topsim__DOT__bus_plic_we1 = vlSelf->m_topsim__DOT__w_plic_we;
    }
    vlSelf->m_topsim__DOT__bus_ipi = vlSelf->m_topsim__DOT__r_ipi;
    vlSelf->m_topsim__DOT__bus_cpustate0 = vlSymsp->TOP__m_topsim__DOT__core0.w_state;
    vlSelf->m_topsim__DOT__bus_cpustate1 = vlSymsp->TOP__m_topsim__DOT__core1.w_state;
    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__w_data_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le0;
        vlSelf->m_topsim__DOT__w_data_we = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we0;
        vlSelf->m_topsim__DOT__w_data_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata0;
        vlSelf->m_topsim__DOT__w_dram_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le0;
        vlSelf->m_topsim__DOT__bus_plic_we0 = vlSelf->m_topsim__DOT__w_plic_we;
        vlSelf->m_topsim__DOT__bus_wmip0 = vlSelf->m_topsim__DOT__w_wmip;
        vlSelf->m_topsim__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t0;
        vlSelf->m_topsim__DOT__w_dram_ctrl = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl0;
        vlSelf->m_topsim__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr0;
        vlSelf->m_topsim__DOT__w_dram_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata0;
        vlSelf->m_topsim__DOT__w_dram_addr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr0;
        vlSelf->m_topsim__DOT__w_bus_cpustate = vlSelf->m_topsim__DOT__bus_cpustate0;
    } else {
        vlSelf->m_topsim__DOT__w_data_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_le1;
        vlSelf->m_topsim__DOT__w_data_we = vlSelf->m_topsim__DOT__ba__DOT__r_ba_data_we1;
        vlSelf->m_topsim__DOT__w_data_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_wdata1;
        vlSelf->m_topsim__DOT__w_dram_le = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_le1;
        vlSelf->m_topsim__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__ba__DOT__r_ba_dram_we_t1;
        vlSelf->m_topsim__DOT__w_dram_ctrl = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_ctrl1;
        vlSelf->m_topsim__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_mem_paddr1;
        vlSelf->m_topsim__DOT__w_dram_wdata = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_wdata1;
        vlSelf->m_topsim__DOT__w_dram_addr = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_addr1;
        vlSelf->m_topsim__DOT__w_bus_cpustate = vlSelf->m_topsim__DOT__bus_cpustate1;
    }
    vlSelf->m_topsim__DOT__RST_X = vlSelf->RST_X;
    vlSelf->m_topsim__DOT__w_grant = vlSelf->m_topsim__DOT__ba__DOT__grant;
    vlSelf->m_topsim__DOT__bus_data_data1 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data1;
    vlSelf->m_topsim__DOT__bus_data_data0 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_data_data0;
    vlSymsp->TOP__m_topsim__DOT__core0.RST_X = vlSelf->RST_X;
    vlSymsp->TOP__m_topsim__DOT__core1.RST_X = vlSelf->RST_X;
    m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0 
        = (0xffffffffffffffULL & ((((QData)((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata2)) 
                                    << 0x20U) | (QData)((IData)(vlSelf->m_topsim__DOT__dram_con__DOT__r_dram_odata1))) 
                                  >> (0x18U & (vlSelf->m_topsim__DOT__dram_con__DOT__r_addr 
                                               << 3U))));
    vlSelf->m_topsim__DOT__w_mtime = vlSelf->m_topsim__DOT__mtime;
    vlSelf->m_topsim__DOT__pll_clk = vlSelf->CLK;
    vlSymsp->TOP__m_topsim__DOT__core0.w_dram_busy 
        = vlSelf->m_topsim__DOT__bus_dram_busy0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_data_busy 
        = vlSelf->m_topsim__DOT__bus_data_busy0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_dram_busy 
        = vlSelf->m_topsim__DOT__bus_dram_busy1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_data_busy 
        = vlSelf->m_topsim__DOT__bus_data_busy1;
    vlSelf->m_topsim__DOT__w_init_done = (5U == (IData)(vlSelf->m_topsim__DOT__r_init_state));
    vlSelf->m_topsim__DOT__bus_dram_odata0 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata0;
    vlSelf->m_topsim__DOT__bus_dram_odata1 = vlSelf->m_topsim__DOT__ba__DOT__r_bus_dram_odata1;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__RXD 
        = vlSelf->m_topsim__DOT__ploader__DOT__RXD;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_addr 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_addr;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_we 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_we;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_le 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_le;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_wdata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_wdata;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mask 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mask;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_refresh 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_refresh;
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_DATA = vlSelf->m_topsim__DOT__w_key_data;
    vlSelf->m_topsim__DOT__dram_con__DOT__mem_state 
        = vlSelf->m_topsim__DOT__w_mem_state;
    vlSelf->m_topsim__DOT__ploader__DOT__KEY_WE = vlSelf->m_topsim__DOT__w_key_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_le = vlSelf->m_topsim__DOT__w_data_le;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_we = vlSelf->m_topsim__DOT__w_data_we;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_wdata = vlSelf->m_topsim__DOT__w_data_wdata;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_load_res 
        = vlSelf->m_topsim__DOT__w_load_res0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_reserved 
        = vlSelf->m_topsim__DOT__w_reserved0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_pc = vlSelf->m_topsim__DOT__w_pc0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_load_res 
        = vlSelf->m_topsim__DOT__w_load_res1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_reserved 
        = vlSelf->m_topsim__DOT__w_reserved1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_pc = vlSelf->m_topsim__DOT__w_pc1;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mtime 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_mtime;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_busy = vlSelf->m_topsim__DOT__w_dram_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__o_busy = vlSelf->m_topsim__DOT__w_dram_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_stall 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_busy;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__w_dram_odata;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_le = vlSelf->m_topsim__DOT__w_dram_le;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_rd_en = vlSelf->m_topsim__DOT__w_dram_le;
    vlSelf->m_topsim__DOT__ba__DOT__bus_wmip1 = vlSelf->m_topsim__DOT__bus_wmip1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_wmip = vlSelf->m_topsim__DOT__bus_wmip1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we1 = vlSelf->m_topsim__DOT__bus_plic_we1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_plic_we = vlSelf->m_topsim__DOT__bus_plic_we1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_plic_we0 = vlSelf->m_topsim__DOT__bus_plic_we0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_plic_we = vlSelf->m_topsim__DOT__bus_plic_we0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_wmip0 = vlSelf->m_topsim__DOT__bus_wmip0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_wmip = vlSelf->m_topsim__DOT__bus_wmip0;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_we_t = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_wr_en = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__w_wr_en = vlSelf->m_topsim__DOT__w_dram_we_t;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_ctrl = vlSelf->m_topsim__DOT__w_dram_ctrl;
    vlSymsp->TOP__m_topsim__DOT__core0.w_ipi = vlSelf->m_topsim__DOT__bus_ipi;
    vlSymsp->TOP__m_topsim__DOT__core1.w_ipi = vlSelf->m_topsim__DOT__bus_ipi;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate0 = vlSelf->m_topsim__DOT__bus_cpustate0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_cpustate1 = vlSelf->m_topsim__DOT__bus_cpustate1;
    vlSelf->m_topsim__DOT__ba__DOT__w_mem_paddr = vlSelf->m_topsim__DOT__w_mem_paddr;
    vlSelf->m_topsim__DOT__w_dev = (vlSelf->m_topsim__DOT__w_mem_paddr 
                                    >> 0x1cU);
    vlSelf->m_topsim__DOT__w_virt = (0xfU & (vlSelf->m_topsim__DOT__w_mem_paddr 
                                             >> 0x18U));
    vlSelf->m_topsim__DOT__w_offset = (0x7ffffffU & vlSelf->m_topsim__DOT__w_mem_paddr);
    vlSelf->m_topsim__DOT__ba__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__UartTx0__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__dram_con__DOT__rst_x = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__ploader__DOT__RST_X = vlSelf->m_topsim__DOT__RST_X;
    vlSelf->m_topsim__DOT__ba__DOT__w_dram_wdata = vlSelf->m_topsim__DOT__w_dram_wdata;
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
    vlSymsp->TOP__m_topsim__DOT__core0.w_grant = vlSelf->m_topsim__DOT__w_grant;
    vlSymsp->TOP__m_topsim__DOT__core1.w_grant = vlSelf->m_topsim__DOT__w_grant;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data1 
        = vlSelf->m_topsim__DOT__bus_data_data1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_data_data 
        = vlSelf->m_topsim__DOT__bus_data_data1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_data0 
        = vlSelf->m_topsim__DOT__bus_data_data0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_data_data 
        = vlSelf->m_topsim__DOT__bus_data_data0;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_odata = (IData)(m_topsim__DOT__dram_con__DOT____VdfgTmp_hf1319f6c__0);
    vlSelf->m_topsim__DOT__ba__DOT__w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSelf->m_topsim__DOT__rf__DOT__w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSymsp->TOP__m_topsim__DOT__core0.w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSymsp->TOP__m_topsim__DOT__core1.w_mtime = vlSelf->m_topsim__DOT__w_mtime;
    vlSelf->m_topsim__DOT__ba__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__UartTx0__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__rf__DOT__clk = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__ploader__DOT__CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSelf->m_topsim__DOT__dram_con__DOT__clk = vlSelf->m_topsim__DOT__pll_clk;
    vlSymsp->TOP__m_topsim__DOT__core0.CLK = vlSelf->m_topsim__DOT__pll_clk;
    vlSymsp->TOP__m_topsim__DOT__core1.CLK = vlSelf->m_topsim__DOT__pll_clk;
    if (vlSelf->m_topsim__DOT__w_init_done) {
        vlSelf->m_topsim__DOT__ba__DOT__w_init_done = 1U;
        vlSelf->m_topsim__DOT__w_dram_ctrl_t = vlSelf->m_topsim__DOT__w_dram_ctrl;
    } else {
        vlSelf->m_topsim__DOT__ba__DOT__w_init_done = 0U;
        vlSelf->m_topsim__DOT__w_dram_ctrl_t = 2U;
    }
    if ((1U == (IData)(vlSelf->m_topsim__DOT__r_init_state))) {
        vlSelf->m_topsim__DOT__w_dram_wdata_t = 0U;
        vlSelf->m_topsim__DOT__w_dram_addr_t2 = vlSelf->m_topsim__DOT__r_zeroaddr;
    } else {
        vlSelf->m_topsim__DOT__w_dram_wdata_t = ((IData)(vlSelf->m_topsim__DOT__w_init_done)
                                                  ? vlSelf->m_topsim__DOT__w_dram_wdata
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelf->m_topsim__DOT__r_init_state))
                                                   ? vlSelf->m_topsim__DOT__r_sd_init_data
                                                   : vlSelf->m_topsim__DOT__w_pl_init_data));
        vlSelf->m_topsim__DOT__w_dram_addr_t2 = ((2U 
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
                                                    : vlSelf->m_topsim__DOT__w_dram_addr_t)));
    }
    vlSymsp->TOP__m_topsim__DOT__core0.w_init_done 
        = vlSelf->m_topsim__DOT__w_init_done;
    vlSymsp->TOP__m_topsim__DOT__core1.w_init_done 
        = vlSelf->m_topsim__DOT__w_init_done;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata0 
        = vlSelf->m_topsim__DOT__bus_dram_odata0;
    vlSymsp->TOP__m_topsim__DOT__core0.w_dram_odata 
        = vlSelf->m_topsim__DOT__bus_dram_odata0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_odata1 
        = vlSelf->m_topsim__DOT__bus_dram_odata1;
    vlSymsp->TOP__m_topsim__DOT__core1.w_dram_odata 
        = vlSelf->m_topsim__DOT__bus_dram_odata1;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_mtime 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_mtime;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_stall 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_stall;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__w_odata 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__w_odata;
    vlSelf->m_topsim__DOT__dram_con__DOT__w_bus_cpustate 
        = vlSelf->m_topsim__DOT__w_bus_cpustate;
    vlSelf->m_topsim__DOT__ba__DOT__w_bus_cpustate 
        = vlSelf->m_topsim__DOT__w_bus_cpustate;
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__RST_X 
        = vlSelf->m_topsim__DOT__ploader__DOT__RST_X;
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
    vlSelf->m_topsim__DOT__ploader__DOT__serc__DOT__CLK 
        = vlSelf->m_topsim__DOT__ploader__DOT__CLK;
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__CLK 
        = vlSelf->m_topsim__DOT__dram_con__DOT__clk;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_ctrl = vlSelf->m_topsim__DOT__w_dram_ctrl_t;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_data = vlSelf->m_topsim__DOT__w_dram_wdata_t;
    vlSelf->m_topsim__DOT__dram_con__DOT__i_addr = vlSelf->m_topsim__DOT__w_dram_addr_t2;
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
    vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__CLK 
        = vlSelf->m_topsim__DOT__dram_con__DOT__idbmem__DOT__CLK;
    vlSelf->m_topsim__DOT__w_data_data = vlSelf->m_topsim__DOT__r_data_data;
    vlSelf->m_topsim__DOT__ba__DOT__w_data_data = vlSelf->m_topsim__DOT__w_data_data;
}

VL_ATTR_COLD void Vm_topsim___024root___stl_sequent__TOP__1(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___stl_sequent__TOP__1\n"); );
    // Body
    vlSelf->m_topsim__DOT__bus_data_wdata0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_wdata;
    vlSelf->m_topsim__DOT__w_hart_sc0 = vlSymsp->TOP__m_topsim__DOT__core0.w_hart_sc;
    vlSelf->m_topsim__DOT__bus_core_ir_0 = vlSymsp->TOP__m_topsim__DOT__core0.w_core_ir;
    vlSelf->m_topsim__DOT__bus_mip0 = vlSymsp->TOP__m_topsim__DOT__core0.w_mip;
    vlSelf->m_topsim__DOT__bus_tlb_req0 = vlSymsp->TOP__m_topsim__DOT__core0.w_tlb_req;
    vlSelf->m_topsim__DOT__bus_mem_paddr0 = vlSymsp->TOP__m_topsim__DOT__core0.w_mem_paddr;
    vlSelf->m_topsim__DOT__bus_tlb_busy0 = vlSymsp->TOP__m_topsim__DOT__core0.w_tlb_busy;
    vlSelf->m_topsim__DOT__bus_dram_wdata0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_wdata;
    vlSelf->m_topsim__DOT__bus_dram_we_t0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_we_t;
    vlSelf->m_topsim__DOT__bus_dram_ctrl0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_ctrl;
    vlSelf->m_topsim__DOT__bus_dram_addr0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_addr;
    vlSelf->m_topsim__DOT__bus_data_le0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_le;
    vlSelf->m_topsim__DOT__bus_data_we0 = vlSymsp->TOP__m_topsim__DOT__core0.w_data_we;
    vlSelf->m_topsim__DOT__bus_dram_le0 = vlSymsp->TOP__m_topsim__DOT__core0.w_dram_le;
    vlSelf->m_topsim__DOT__bus_data_wdata1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_wdata;
    vlSelf->m_topsim__DOT__w_hart_sc1 = vlSymsp->TOP__m_topsim__DOT__core1.w_hart_sc;
    vlSelf->m_topsim__DOT__bus_core_ir_1 = vlSymsp->TOP__m_topsim__DOT__core1.w_core_ir;
    vlSelf->m_topsim__DOT__bus_mip1 = vlSymsp->TOP__m_topsim__DOT__core1.w_mip;
    vlSelf->m_topsim__DOT__bus_tlb_req1 = vlSymsp->TOP__m_topsim__DOT__core1.w_tlb_req;
    vlSelf->m_topsim__DOT__bus_mem_paddr1 = vlSymsp->TOP__m_topsim__DOT__core1.w_mem_paddr;
    vlSelf->m_topsim__DOT__bus_tlb_busy1 = vlSymsp->TOP__m_topsim__DOT__core1.w_tlb_busy;
    vlSelf->m_topsim__DOT__bus_dram_wdata1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_wdata;
    vlSelf->m_topsim__DOT__bus_dram_we_t1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_we_t;
    vlSelf->m_topsim__DOT__bus_dram_ctrl1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_ctrl;
    vlSelf->m_topsim__DOT__bus_dram_addr1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_addr;
    vlSelf->m_topsim__DOT__bus_data_le1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_le;
    vlSelf->m_topsim__DOT__bus_data_we1 = vlSymsp->TOP__m_topsim__DOT__core1.w_data_we;
    vlSelf->m_topsim__DOT__bus_dram_le1 = vlSymsp->TOP__m_topsim__DOT__core1.w_dram_le;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata0 
        = vlSelf->m_topsim__DOT__bus_data_wdata0;
    vlSymsp->TOP__m_topsim__DOT__core1.w_oh_sc = vlSelf->m_topsim__DOT__w_hart_sc0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir0 = vlSelf->m_topsim__DOT__bus_core_ir_0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip0 = vlSelf->m_topsim__DOT__bus_mip0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req0 = vlSelf->m_topsim__DOT__bus_tlb_req0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr0 
        = vlSelf->m_topsim__DOT__bus_mem_paddr0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy0 = vlSelf->m_topsim__DOT__bus_tlb_busy0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata0 
        = vlSelf->m_topsim__DOT__bus_dram_wdata0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t0 
        = vlSelf->m_topsim__DOT__bus_dram_we_t0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl0 
        = vlSelf->m_topsim__DOT__bus_dram_ctrl0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr0 
        = vlSelf->m_topsim__DOT__bus_dram_addr0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le0 = vlSelf->m_topsim__DOT__bus_data_le0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we0 = vlSelf->m_topsim__DOT__bus_data_we0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le0 = vlSelf->m_topsim__DOT__bus_dram_le0;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_wdata1 
        = vlSelf->m_topsim__DOT__bus_data_wdata1;
    vlSymsp->TOP__m_topsim__DOT__core0.w_oh_sc = vlSelf->m_topsim__DOT__w_hart_sc1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_core_ir1 = vlSelf->m_topsim__DOT__bus_core_ir_1;
    if ((0U == vlSelf->m_topsim__DOT__ba__DOT__grant)) {
        vlSelf->m_topsim__DOT__ba__DOT__w_core_ir = vlSelf->m_topsim__DOT__bus_core_ir_0;
        vlSelf->m_topsim__DOT__w_mip = vlSelf->m_topsim__DOT__bus_mip0;
        vlSelf->m_topsim__DOT__w_tlb_req = vlSelf->m_topsim__DOT__bus_tlb_req0;
        vlSelf->m_topsim__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__bus_tlb_busy0;
    } else {
        vlSelf->m_topsim__DOT__ba__DOT__w_core_ir = vlSelf->m_topsim__DOT__bus_core_ir_1;
        vlSelf->m_topsim__DOT__w_mip = vlSelf->m_topsim__DOT__bus_mip1;
        vlSelf->m_topsim__DOT__w_tlb_req = vlSelf->m_topsim__DOT__bus_tlb_req1;
        vlSelf->m_topsim__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__bus_tlb_busy1;
    }
    vlSelf->m_topsim__DOT__ba__DOT__bus_mip1 = vlSelf->m_topsim__DOT__bus_mip1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_req1 = vlSelf->m_topsim__DOT__bus_tlb_req1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_mem_paddr1 
        = vlSelf->m_topsim__DOT__bus_mem_paddr1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_tlb_busy1 = vlSelf->m_topsim__DOT__bus_tlb_busy1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_wdata1 
        = vlSelf->m_topsim__DOT__bus_dram_wdata1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_we_t1 
        = vlSelf->m_topsim__DOT__bus_dram_we_t1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_ctrl1 
        = vlSelf->m_topsim__DOT__bus_dram_ctrl1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_addr1 
        = vlSelf->m_topsim__DOT__bus_dram_addr1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_le1 = vlSelf->m_topsim__DOT__bus_data_le1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_data_we1 = vlSelf->m_topsim__DOT__bus_data_we1;
    vlSelf->m_topsim__DOT__ba__DOT__bus_dram_le1 = vlSelf->m_topsim__DOT__bus_dram_le1;
    vlSelf->m_topsim__DOT__ba__DOT__w_mip = vlSelf->m_topsim__DOT__w_mip;
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_req = vlSelf->m_topsim__DOT__w_tlb_req;
    vlSelf->m_topsim__DOT__w_isread = (0U == (IData)(vlSelf->m_topsim__DOT__w_tlb_req));
    vlSelf->m_topsim__DOT__w_iswrite = (1U == (IData)(vlSelf->m_topsim__DOT__w_tlb_req));
    vlSelf->m_topsim__DOT__ba__DOT__w_tlb_busy = vlSelf->m_topsim__DOT__w_tlb_busy;
}

VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__0(Vm_topsim_m_cpummu* vlSelf);
VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core1__0(Vm_topsim_m_cpummu* vlSelf);
VL_ATTR_COLD void Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__1(Vm_topsim_m_cpummu* vlSelf);

VL_ATTR_COLD void Vm_topsim___024root___eval_stl(Vm_topsim___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_topsim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_topsim___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vm_topsim___024root___stl_sequent__TOP__0(vlSelf);
        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__0((&vlSymsp->TOP__m_topsim__DOT__core0));
        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core1__0((&vlSymsp->TOP__m_topsim__DOT__core1));
        Vm_topsim___024root___stl_sequent__TOP__1(vlSelf);
        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__1((&vlSymsp->TOP__m_topsim__DOT__core1));
        Vm_topsim_m_cpummu___stl_sequent__TOP__m_topsim__DOT__core0__1((&vlSymsp->TOP__m_topsim__DOT__core0));
    }
}
