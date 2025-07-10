// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu32.h for the primary calling header

#ifndef VERILATED_VALU32___024ROOT_H_
#define VERILATED_VALU32___024ROOT_H_  // guard

#include "verilated.h"


class Valu32__Syms;

class alignas(VL_CACHE_LINE_BYTES) Valu32___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(opcode,4,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(negative,0,0);
    VL_OUT8(carry_out,0,0);
    VL_OUT8(overflow,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Valu32__Syms* const vlSymsp;

    // CONSTRUCTORS
    Valu32___024root(Valu32__Syms* symsp, const char* v__name);
    ~Valu32___024root();
    VL_UNCOPYABLE(Valu32___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
