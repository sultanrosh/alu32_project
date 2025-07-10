// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu32__Syms.h"


void Valu32___024root__trace_chg_0_sub_0(Valu32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Valu32___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root__trace_chg_0\n"); );
    // Init
    Valu32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu32___024root*>(voidSelf);
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Valu32___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Valu32___024root__trace_chg_0_sub_0(Valu32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->a),32);
    bufp->chgIData(oldp+1,(vlSelf->b),32);
    bufp->chgCData(oldp+2,(vlSelf->opcode),5);
    bufp->chgIData(oldp+3,(vlSelf->result),32);
    bufp->chgBit(oldp+4,(vlSelf->zero));
    bufp->chgBit(oldp+5,(vlSelf->negative));
    bufp->chgBit(oldp+6,(vlSelf->carry_out));
    bufp->chgBit(oldp+7,(vlSelf->overflow));
    bufp->chgIData(oldp+8,((vlSelf->a + vlSelf->b)),32);
    bufp->chgIData(oldp+9,((vlSelf->a - vlSelf->b)),32);
    bufp->chgBit(oldp+10,((1U & (IData)((1ULL & (((QData)((IData)(vlSelf->a)) 
                                                  + (QData)((IData)(vlSelf->b))) 
                                                 >> 0x20U))))));
    bufp->chgBit(oldp+11,((1U & (IData)((1ULL & (((QData)((IData)(vlSelf->a)) 
                                                  - (QData)((IData)(vlSelf->b))) 
                                                 >> 0x20U))))));
}

void Valu32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root__trace_cleanup\n"); );
    // Init
    Valu32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu32___024root*>(voidSelf);
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
