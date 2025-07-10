TOP = alu32
SRC = rtl/alu32.v
TB  = sim/alu32_tb.cpp

all: build run

build:
	verilator --cc $(SRC) --exe $(TB) --top-module $(TOP) --build --trace -Irtl -CFLAGS -std=c++17

run:
	./obj_dir/V$(TOP)

wave:
	gtkwave sim/dump.vcd &

clean:
	rm -rf obj_dir sim/dump.vcd


