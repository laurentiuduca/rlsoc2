// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vm_topsim.h for the primary calling header

#include "verilated.h"

#include "Vm_topsim__Syms.h"
#include "Vm_topsim___024root.h"

// Parameter definitions for Vm_topsim___024root
constexpr IData/*31:0*/ Vm_topsim___024root::m_topsim__DOT__dram_con__DOT__idbmem__DOT__MEM_SIZE;
constexpr IData/*31:0*/ Vm_topsim___024root::m_topsim__DOT__dram_con__DOT__idbmem__DOT__idbmem__DOT__MEM_SIZE;


void Vm_topsim___024root___ctor_var_reset(Vm_topsim___024root* vlSelf);

Vm_topsim___024root::Vm_topsim___024root(Vm_topsim__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vm_topsim___024root___ctor_var_reset(this);
}

void Vm_topsim___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vm_topsim___024root::~Vm_topsim___024root() {
}
