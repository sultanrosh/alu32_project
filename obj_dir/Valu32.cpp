// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Valu32__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Valu32::Valu32(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Valu32__Syms(contextp(), _vcname__, this)}
    , opcode{vlSymsp->TOP.opcode}
    , zero{vlSymsp->TOP.zero}
    , negative{vlSymsp->TOP.negative}
    , carry_out{vlSymsp->TOP.carry_out}
    , overflow{vlSymsp->TOP.overflow}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Valu32::Valu32(const char* _vcname__)
    : Valu32(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Valu32::~Valu32() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Valu32___024root___eval_debug_assertions(Valu32___024root* vlSelf);
#endif  // VL_DEBUG
void Valu32___024root___eval_static(Valu32___024root* vlSelf);
void Valu32___024root___eval_initial(Valu32___024root* vlSelf);
void Valu32___024root___eval_settle(Valu32___024root* vlSelf);
void Valu32___024root___eval(Valu32___024root* vlSelf);

void Valu32::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu32::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Valu32___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Valu32___024root___eval_static(&(vlSymsp->TOP));
        Valu32___024root___eval_initial(&(vlSymsp->TOP));
        Valu32___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Valu32___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Valu32::eventsPending() { return false; }

uint64_t Valu32::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Valu32::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Valu32___024root___eval_final(Valu32___024root* vlSelf);

VL_ATTR_COLD void Valu32::final() {
    Valu32___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Valu32::hierName() const { return vlSymsp->name(); }
const char* Valu32::modelName() const { return "Valu32"; }
unsigned Valu32::threads() const { return 1; }
void Valu32::prepareClone() const { contextp()->prepareClone(); }
void Valu32::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Valu32::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Valu32___024root__trace_decl_types(VerilatedVcd* tracep);

void Valu32___024root__trace_init_top(Valu32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Valu32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu32___024root*>(voidSelf);
    Valu32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Valu32___024root__trace_decl_types(tracep);
    Valu32___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Valu32___024root__trace_register(Valu32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Valu32::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Valu32::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Valu32___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
