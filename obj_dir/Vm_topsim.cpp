// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vm_topsim.h"
#include "Vm_topsim__Syms.h"

//============================================================
// Constructors

Vm_topsim::Vm_topsim(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vm_topsim__Syms(contextp(), _vcname__, this)}
    , CLK{vlSymsp->TOP.CLK}
    , RST_X{vlSymsp->TOP.RST_X}
    , __PVT__m_topsim__DOT__core0{vlSymsp->TOP.__PVT__m_topsim__DOT__core0}
    , __PVT__m_topsim__DOT__core1{vlSymsp->TOP.__PVT__m_topsim__DOT__core1}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vm_topsim::Vm_topsim(const char* _vcname__)
    : Vm_topsim(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vm_topsim::~Vm_topsim() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vm_topsim___024root___eval_debug_assertions(Vm_topsim___024root* vlSelf);
#endif  // VL_DEBUG
void Vm_topsim___024root___eval_static(Vm_topsim___024root* vlSelf);
void Vm_topsim___024root___eval_initial(Vm_topsim___024root* vlSelf);
void Vm_topsim___024root___eval_settle(Vm_topsim___024root* vlSelf);
void Vm_topsim___024root___eval(Vm_topsim___024root* vlSelf);

void Vm_topsim::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vm_topsim::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vm_topsim___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vm_topsim___024root___eval_static(&(vlSymsp->TOP));
        Vm_topsim___024root___eval_initial(&(vlSymsp->TOP));
        Vm_topsim___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vm_topsim___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
}

//============================================================
// Events and timing
bool Vm_topsim::eventsPending() { return false; }

uint64_t Vm_topsim::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vm_topsim::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vm_topsim___024root___eval_final(Vm_topsim___024root* vlSelf);

VL_ATTR_COLD void Vm_topsim::final() {
    Vm_topsim___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vm_topsim::hierName() const { return vlSymsp->name(); }
const char* Vm_topsim::modelName() const { return "Vm_topsim"; }
unsigned Vm_topsim::threads() const { return 1; }
