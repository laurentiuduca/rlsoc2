// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VM_TOPSIM__SYMS_H_
#define VERILATED_VM_TOPSIM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vm_topsim.h"

// INCLUDE MODULE CLASSES
#include "Vm_topsim___024root.h"
#include "Vm_topsim_m_cpummu.h"

// SYMS CLASS (contains all model state)
class Vm_topsim__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vm_topsim* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vm_topsim___024root            TOP;
    Vm_topsim_m_cpummu             TOP__m_topsim__DOT__core0;
    Vm_topsim_m_cpummu             TOP__m_topsim__DOT__core1;

    // CONSTRUCTORS
    Vm_topsim__Syms(VerilatedContext* contextp, const char* namep, Vm_topsim* modelp);
    ~Vm_topsim__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
