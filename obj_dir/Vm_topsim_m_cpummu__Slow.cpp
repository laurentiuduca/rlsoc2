// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim__Syms.h"
#include "Vm_topsim_m_cpummu.h"

// Parameter definitions for Vm_topsim_m_cpummu
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_inst_r__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_inst_r__DOT__D_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_inst_r__DOT__ENTRY;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_r__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_r__DOT__D_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_r__DOT__ENTRY;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_w__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_w__DOT__D_WIDTH;
constexpr IData/*31:0*/ Vm_topsim_m_cpummu::mmu__DOT__TLB_data_w__DOT__ENTRY;


void Vm_topsim_m_cpummu___ctor_var_reset(Vm_topsim_m_cpummu* vlSelf);

Vm_topsim_m_cpummu::Vm_topsim_m_cpummu(Vm_topsim__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vm_topsim_m_cpummu___ctor_var_reset(this);
}

void Vm_topsim_m_cpummu::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vm_topsim_m_cpummu::~Vm_topsim_m_cpummu() {
}
