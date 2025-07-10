// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu32.h for the primary calling header

#include "Valu32__pch.h"
#include "Valu32___024root.h"

VL_INLINE_OPT void Valu32___024root___ico_sequent__TOP__0(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->carry_out = 0U;
    if ((1U & (~ ((IData)(vlSelf->opcode) >> 4U)))) {
        if ((1U & (~ ((IData)(vlSelf->opcode) >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->opcode) >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode) 
                              >> 1U)))) {
                    vlSelf->carry_out = (1U & ((1U 
                                                & (IData)(vlSelf->opcode))
                                                ? (IData)(
                                                          (1ULL 
                                                           & (((QData)((IData)(vlSelf->a)) 
                                                               - (QData)((IData)(vlSelf->b))) 
                                                              >> 0x20U)))
                                                : (IData)(
                                                          (1ULL 
                                                           & (((QData)((IData)(vlSelf->a)) 
                                                               + (QData)((IData)(vlSelf->b))) 
                                                              >> 0x20U)))));
                }
            }
        }
    }
    vlSelf->result = 0U;
    vlSelf->overflow = 0U;
    vlSelf->result = ((0x10U & (IData)(vlSelf->opcode))
                       ? 0U : ((8U & (IData)(vlSelf->opcode))
                                ? ((4U & (IData)(vlSelf->opcode))
                                    ? ((2U & (IData)(vlSelf->opcode))
                                        ? ((1U & (IData)(vlSelf->opcode))
                                            ? vlSelf->a
                                            : (VL_LTS_III(32, vlSelf->a, vlSelf->b)
                                                ? 1U
                                                : 0U))
                                        : ((1U & (IData)(vlSelf->opcode))
                                            ? (VL_GTS_III(32, vlSelf->a, vlSelf->b)
                                                ? 1U
                                                : 0U)
                                            : ((vlSelf->a 
                                                != vlSelf->b)
                                                ? 1U
                                                : 0U)))
                                    : ((2U & (IData)(vlSelf->opcode))
                                        ? ((1U & (IData)(vlSelf->opcode))
                                            ? ((vlSelf->a 
                                                == vlSelf->b)
                                                ? 1U
                                                : 0U)
                                            : ((vlSelf->a 
                                                < vlSelf->b)
                                                ? 1U
                                                : 0U))
                                        : ((1U & (IData)(vlSelf->opcode))
                                            ? (VL_LTS_III(32, vlSelf->a, vlSelf->b)
                                                ? 1U
                                                : 0U)
                                            : VL_SHIFTRS_III(32,32,5, vlSelf->a, 
                                                             (0x1fU 
                                                              & vlSelf->b)))))
                                : ((4U & (IData)(vlSelf->opcode))
                                    ? ((2U & (IData)(vlSelf->opcode))
                                        ? ((1U & (IData)(vlSelf->opcode))
                                            ? (vlSelf->a 
                                               >> (0x1fU 
                                                   & vlSelf->b))
                                            : (vlSelf->a 
                                               << (0x1fU 
                                                   & vlSelf->b)))
                                        : ((1U & (IData)(vlSelf->opcode))
                                            ? (~ (vlSelf->a 
                                                  | vlSelf->b))
                                            : (vlSelf->a 
                                               ^ vlSelf->b)))
                                    : ((2U & (IData)(vlSelf->opcode))
                                        ? ((1U & (IData)(vlSelf->opcode))
                                            ? (vlSelf->a 
                                               | vlSelf->b)
                                            : (vlSelf->a 
                                               & vlSelf->b))
                                        : ((1U & (IData)(vlSelf->opcode))
                                            ? (vlSelf->a 
                                               - vlSelf->b)
                                            : (vlSelf->a 
                                               + vlSelf->b))))));
    vlSelf->zero = (0U == vlSelf->result);
    vlSelf->negative = (vlSelf->result >> 0x1fU);
    vlSelf->overflow = ((0U == (IData)(vlSelf->opcode))
                         ? (((vlSelf->a >> 0x1fU) == 
                             (vlSelf->b >> 0x1fU)) 
                            & ((vlSelf->result >> 0x1fU) 
                               != (vlSelf->a >> 0x1fU)))
                         : ((1U == (IData)(vlSelf->opcode)) 
                            & (((vlSelf->a >> 0x1fU) 
                                != (vlSelf->b >> 0x1fU)) 
                               & ((vlSelf->result >> 0x1fU) 
                                  != (vlSelf->a >> 0x1fU)))));
}

void Valu32___024root___eval_ico(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Valu32___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Valu32___024root___eval_triggers__ico(Valu32___024root* vlSelf);

bool Valu32___024root___eval_phase__ico(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Valu32___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Valu32___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Valu32___024root___eval_act(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_act\n"); );
}

void Valu32___024root___eval_nba(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_nba\n"); );
}

void Valu32___024root___eval_triggers__act(Valu32___024root* vlSelf);

bool Valu32___024root___eval_phase__act(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Valu32___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Valu32___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Valu32___024root___eval_phase__nba(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Valu32___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu32___024root___dump_triggers__ico(Valu32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu32___024root___dump_triggers__nba(Valu32___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu32___024root___dump_triggers__act(Valu32___024root* vlSelf);
#endif  // VL_DEBUG

void Valu32___024root___eval(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Valu32___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/alu32.v", 5, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Valu32___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Valu32___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/alu32.v", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Valu32___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/alu32.v", 5, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Valu32___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Valu32___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Valu32___024root___eval_debug_assertions(Valu32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu32___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->opcode & 0xe0U))) {
        Verilated::overWidthError("opcode");}
}
#endif  // VL_DEBUG
