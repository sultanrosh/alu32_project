#include "Valu32.h"               // ALU model from Verilator
#include "verilated.h"            // Core Verilator support
#include "verilated_vcd_c.h"      // VCD trace support for GTKWave
#include <iostream>               // For console printing

// Verilator requires this global time variable
vluint64_t main_time = 0;

// Verilator calls this to get the current simulation time
double sc_time_stamp() { return main_time; }

// Run a single test case with given inputs and opcode
void test_op(Valu32* alu, VerilatedVcdC* tfp, uint32_t a, uint32_t b, uint8_t opcode) {
    alu->a = a;
    alu->b = b;
    alu->opcode = opcode;

    alu->eval();                     // Simulate logic
    tfp->dump(main_time);           // Dump waveform at current time
    main_time += 1000;              // Increase simulation time (e.g., 1ns if timescale is 1ps)

    // Print results to console
    std::cout << "OP " << int(opcode)
              << ": A=" << a << ", B=" << b
              << " → R=" << alu->result
              << " Z=" << alu->zero
              << " N=" << alu->negative
              << " C=" << alu->carry_out
              << " OV=" << alu->overflow << std::endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // Required for Verilator

    Valu32* alu = new Valu32;            // Instantiate ALU
    VerilatedVcdC* tfp = new VerilatedVcdC; // Create waveform trace object

    Verilated::traceEverOn(true);       // Enable tracing
    alu->trace(tfp, 99);                // Attach trace to ALU
    tfp->open("sim/dump.vcd");          // Create VCD file

    // --- TEST CASES ---
    test_op(alu, tfp, 10, 20, 0);           // ADD
    test_op(alu, tfp, 30, 10, 1);           // SUB
    test_op(alu, tfp, 0xFFFF, 0xF0F0, 2);   // AND
    test_op(alu, tfp, 0xAAAA, 0x5555, 3);   // OR
    test_op(alu, tfp, 0xAAAA, 0x5555, 4);   // XOR
    test_op(alu, tfp, 0xFFFFFFFF, 0xFFFFFFFF, 5); // NOR
    test_op(alu, tfp, 0x00000010, 0x00000002, 6); // SLL (Shift Left)
    test_op(alu, tfp, 0x00000080, 0x00000004, 7); // SRL (Logical Right)
    test_op(alu, tfp, 0xFFFFFFF0, 0x00000004, 8); // SRA (Arithmetic Right)

    // Edge cases
    test_op(alu, tfp, 1, 1, 0);           // ADD: 1+1 = 2
    test_op(alu, tfp, 0xFFFFFFFF, 1, 0);  // ADD overflow
    test_op(alu, tfp, 16, 32, 1);         // SUB: -16
    test_op(alu, tfp, 0x80000000, 1, 1);  // SUB: edge with MSB

    tfp->close();         // Close VCD
    delete alu;           // Cleanup
    return 0;
}
