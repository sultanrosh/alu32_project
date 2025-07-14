# ALU32_Project

[![Verilog](https://img.shields.io/badge/Language-Verilog-blue.svg)](https://en.wikipedia.org/wiki/Verilog)
[![Simulated With](https://img.shields.io/badge/Simulated%20With-Verilator-green.svg)](https://www.veripool.org/wiki/verilator)
[![Platform](https://img.shields.io/badge/Platform-WSL%20%7C%20Ubuntu-orange.svg)](https://learn.microsoft.com/en-us/windows/wsl/)

---

## Project Overview

This project implements a **32-bit Arithmetic Logic Unit (ALU)** in Verilog. It supports arithmetic and logic operations and is verified using a Verilator C++ testbench, with output visualized in GTKWave and terminal logs.

---

## Ubuntu (WSL) Installation Steps

To get started on Windows:

1. Open PowerShell as Administrator:

```bash
wsl --install
```

2. Restart your system and launch **Ubuntu** from the Start Menu.
3. Install tools inside Ubuntu:

```bash
sudo apt update
sudo apt install verilator gtkwave build-essential git
```

---

## Fixes if Ubuntu Fails to Download

If WSL doesn't install properly:

1. Enable WSL and Virtual Machine Platform:

```bash
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

2. Restart and then set WSL 2 as default:

```bash
wsl --set-default-version 2
```

3. Reinstall Ubuntu:

```bash
wsl --install -d Ubuntu
```

---

## Creating the Project in Ubuntu

Inside your Ubuntu terminal:

```bash
cd ~
mkdir alu32_project
cd alu32_project
touch alu32.sv alu_opcodes.vh alu32_tb.cpp
code .
```

> Ensure the VSCode extension "Remote - WSL" is installed to use `code .`

---

## Connecting to GitHub using SSH Keys

To enable SSH-based push/pull for this and future projects:

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
cat ~/.ssh/id_ed25519.pub
```

1. Copy the SSH key and go to: https://github.com/settings/ssh/new  
2. Paste the key, name it, and save.

### Pushing the Project

```bash
git init
git add .
git commit -m "Initial commit"
git remote add origin git@github.com:yourusername/alu32_project.git
git branch -M main
git push -u origin main
```

---

## ALU32 Verilog and Testbench Explanation

### ALU Logic (`alu32.sv`)

- Performs operations based on 5-bit `opcode`
- Examples:
  - `00000`: Addition
  - `00001`: Subtraction
  - `00010`: Bitwise AND
  - `00011`: Bitwise OR
- Outputs:
  - `result[31:0]`: Result of operation
  - `carry_out`: Unsigned overflow
  - `overflow`: Signed overflow
  - `zero`: Result == 0
  - `negative`: MSB == 1

```verilog
assign {carry_add, sum} = a + b;
assign {carry_sub, diff} = a - b;
```

---

### Testbench (`alu32_tb.cpp`)

- Written in C++ using Verilator
- Applies test cases to the ALU module
- Dumps `wave.vcd` for waveform viewing

Key function:

```cpp
void test_op(...) {
    alu->a = a;
    alu->b = b;
    alu->opcode = opcode;
    alu->eval();
    tfp->dump(main_time);
    main_time += 1000;
}
```

---

## GTKWave Screenshot & Explanation

### GTKWave Output (Rendered from simulation)

<img width="1918" height="1017" alt="GTKWave" src="https://github.com/user-attachments/assets/8a787913-9a3b-4870-bac7-5b8e35528bc5" />

```

### Description

- Shows how each opcode affects outputs like `result`, `carry_out`, `zero`, and `overflow`
- For `opcode=00` with `a=0xA` and `b=0x14`, the result is `0x1E` → expected `ADD` result
- For `opcode=01` with `a=0xFFFFFFFF` and `b=1`, `result=0x00000000`, and `zero=1`
- Confirms arithmetic correctness and flag logic

---

## Terminal Output Screenshot & Explanation

### Terminal Output Snapshot

<img width="762" height="285" alt="terminal" src="https://github.com/user-attachments/assets/783e3526-95df-4ed4-8547-6326a4d22ec3" />

```

### Description

- Each line includes:
  - `A`: Operand A
  - `B`: Operand B
  - `R`: Result
  - `Z`: Zero flag
  - `N`: Negative flag
  - `C`: Carry-out
  - `OV`: Overflow

#### Example:

```
OP 0: A=10, B=20 → R=30  Z= N= C= OV=
```

- `R=30` is correct for `ADD`
- If `R=0`, then `Z=1` confirms zero flag detection
- Large negative values confirm signed overflow is handled

---

## Directory Structure

```
alu32_project/
├── alu32.sv
├── alu_opcodes.vh
├── alu32_tb.cpp
├── wave.vcd
├── gtkwave_output.png
├── terminal_output.png
```

---

## License

MIT License. Free to use and modify with credit.



---

## Verilog Syntax Explanations

### Core Arithmetic/Logical Operation Syntax

```verilog
assign {carry_add, sum} = a + b;
```

- This line performs a 32-bit addition and captures the overflow.
- `{carry_add, sum}` creates a 33-bit bus:
  - `carry_add`: MSB, carries out if result exceeds 32 bits
  - `sum`: Lower 32 bits of the result

```verilog
assign zero = (result == 0);
assign negative = result[31];
```

- These set the flags:
  - `zero`: High if result is 0
  - `negative`: High if MSB is 1 (2's complement negative)

```verilog
assign overflow = (a[31] == b[31]) && (result[31] != a[31]);
```

- Detects signed overflow (only happens when adding two numbers with the same sign produces a result with the opposite sign)

---

## C++ Testbench Syntax Breakdown

### Header Includes

```cpp
#include "Valu32.h"               // Verilated model of ALU
#include "verilated.h"            // Core Verilator support
#include "verilated_vcd_c.h"      // VCD waveform tracing
#include <iostream>               // Console output
```

### Simulation Time Tracking

```cpp
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }
```

- Required by Verilator to know the current simulation timestamp

### Test Operation Function

```cpp
void test_op(Valu32* alu, VerilatedVcdC* tfp, uint32_t a, uint32_t b, uint8_t opcode) {
    alu->a = a;
    alu->b = b;
    alu->opcode = opcode;
    alu->eval();              // Evaluate ALU logic
    tfp->dump(main_time);     // Dump wave data
    main_time += 1000;        // Advance simulation time by 1ns
}
```

- This function applies one operation to the ALU and captures the results

### Main Function

```cpp
int main() {
    Verilated::traceEverOn(true);  // Enable waveform tracing
    Valu32* alu = new Valu32;      // Create ALU instance
    VerilatedVcdC* tfp = new VerilatedVcdC;
    alu->trace(tfp, 99);           // Trace 99 levels deep
    tfp->open("wave.vcd");

    test_op(alu, tfp, 10, 20, 0x00); // Test: ADD 10 + 20

    tfp->close();
    delete alu;
    return 0;
}
```

---

## Fixing Squiggly Line Errors in VSCode (IntelliSense)

You may see red squiggles on `#include "Valu32.h"` or other Verilator headers. Here's how to fix it:

### 1. Create `c_cpp_properties.json`

Inside `.vscode/c_cpp_properties.json`, add:

```json
{
  "configurations": [
    {
      "name": "Linux",
      "includePath": [
        "${workspaceFolder}/obj_dir",
        "/usr/include",
        "/usr/share/verilator/include"
      ],
      "defines": [],
      "compilerPath": "/usr/bin/g++",
      "cStandard": "c11",
      "cppStandard": "c++17",
      "intelliSenseMode": "linux-gcc-x64"
    }
  ],
  "version": 4
}
```

### 2. Regenerate Verilator Files

Make sure Verilator generates `Valu32.h` and `obj_dir/` folder:

```bash
verilator -Wall --cc alu32.sv --exe alu32_tb.cpp --trace
make -C obj_dir -f Valu32.mk
```

Then run the testbench:

```bash
./obj_dir/Valu32
```

---

## Summary

- This README combines setup instructions, Verilog syntax breakdowns, testbench logic, and squiggly-line fixes
- All example waveforms and terminal outputs are explained for your GTKWave simulation
- VSCode IntelliSense issues are resolved using proper JSON include paths



