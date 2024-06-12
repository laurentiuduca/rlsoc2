// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vm_topsim__Syms.h"
#include "Vm_topsim.h"
#include "Vm_topsim___024root.h"
#include "Vm_topsim_m_cpummu.h"

// FUNCTIONS
Vm_topsim__Syms::~Vm_topsim__Syms()
{
}

Vm_topsim__Syms::Vm_topsim__Syms(VerilatedContext* contextp, const char* namep, Vm_topsim* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__m_topsim__DOT__core0{this, Verilated::catName(namep, "m_topsim.core0")}
    , TOP__m_topsim__DOT__core1{this, Verilated::catName(namep, "m_topsim.core1")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__m_topsim__DOT__core0 = &TOP__m_topsim__DOT__core0;
    TOP.__PVT__m_topsim__DOT__core1 = &TOP__m_topsim__DOT__core1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__m_topsim__DOT__core0.__Vconfigure(true);
    TOP__m_topsim__DOT__core1.__Vconfigure(false);
}
