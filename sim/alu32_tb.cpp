#include "Valu32.h"               // ALU model from Verilator
#include "verilated.h"            // Core Verilator support
#include "verilated_vcd_c.h"      // VCD trace support for GTKWave
#include <iostream>               // For console printing

vluint64_t main_time = 0;         // Tracks simulation time
double sc_time_stamp() { return main_time; }  // Needed by Verilator

void test_op(Valu32* alu, VerilatedVcdC* tfp, uint32_t a, uint32_t b, uint8_t opcode) {
    alu->a = a;
    alu->b = b;
    alu->opcode = opcode;

    alu->eval();                  // Run simulation logic
    tfp->dump(main_time);        // Save waveform
    main_time += 10;             // Move time forward

    std::cout << "OP " << int(opcode)
              << ": A=" << a << ", B=" << b
              << " → R=" << alu->result
              << " Z=" << alu->zero
              << " N=" << alu->negative
              << " C=" << alu->carry_out
              << " OV=" << alu->overflow << std::endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Valu32* alu = new Valu32;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    alu->trace(tfp, 99);
    tfp->open("sim/dump.vcd");

    test_op(alu, tfp, 10, 20, 0);         // ADD
    test_op(alu, tfp, 30, 10, 1);         // SUB
    test_op(alu, tfp, 0xFFFF, 0xF0F0, 2); // AND
    test_op(alu, tfp, 0xAAAA, 0x5555, 3); // OR

    tfp->close();
    delete alu;
    return 0;
}