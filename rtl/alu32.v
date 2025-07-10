`include "alu_opcodes.vh"  
// Includes the file with opcode macro definitions (e.g., `ALU_ADD`, `ALU_SUB`, etc.)
// The backtick ` is the Verilog preprocessor directive symbol, similar to #include in C/C++.

module alu32 (
    input  logic [31:0] a,            // 32-bit input operand A
    input  logic [31:0] b,            // 32-bit input operand B
    input  logic [4:0]  opcode,       // 5-bit operation code that selects ALU operation (up to 32 ops)
    output logic [31:0] result,       // 32-bit result of the operation
    output logic        zero,         // Flag: result is zero
    output logic        negative,     // Flag: result is negative (MSB = 1)
    output logic        carry_out,    // Flag: carry out from addition or subtraction
    output logic        overflow      // Flag: signed overflow in addition/subtraction
);
// `logic` is used instead of `wire` to allow assignment in procedural blocks (e.g., always_comb)

    logic [31:0] sum;                 // Temporary variable to store result of addition
    logic [31:0] diff;                // Temporary variable to store result of subtraction
    logic        carry_add;           // Carry-out from addition
    logic        carry_sub;           // Carry-out from subtraction

    assign {carry_add, sum}  = a + b;
// Performs 32-bit addition. The result is 33 bits: upper bit (carry_out) is assigned to carry_add,
// and lower 32 bits are assigned to sum.
// Curly braces `{}` are used to concatenate values. So `{carry_add, sum}` means pack into a 33-bit value.

    assign {carry_sub, diff} = a - b;
// Same as above, but for subtraction. Note: carry_sub behaves like borrow flag.

    always_comb begin
// `always_comb` is synthesizable and triggers whenever any input in the block changes.
// It ensures purely combinational logic, replacing `always @(*)` in SystemVerilog.

        result     = 32'b0;           // Initialize result to all 0s. '32'b0' = 32-bit binary zero
        carry_out  = 1'b0;            // Initialize carry_out to 0. '1'b0' = 1-bit binary zero
        overflow   = 1'b0;            // Initialize overflow flag

        case (opcode)
        // Begin a case statement to select the operation based on the 5-bit opcode

            `ALU_ADD:   begin result = sum;       carry_out = carry_add; end
            // Add: Assign precomputed sum, set carry_out from addition

            `ALU_SUB:   begin result = diff;      carry_out = carry_sub; end
            // Subtract: Assign precomputed difference, set carry_out from subtraction

            `ALU_AND:   result = a & b;
            // Bitwise AND: Each bit of result = a[i] AND b[i]

            `ALU_OR:    result = a | b;
            // Bitwise OR: Each bit of result = a[i] OR b[i]

            `ALU_XOR:   result = a ^ b;
            // Bitwise XOR: Each bit of result = a[i] XOR b[i]

            `ALU_NOR:   result = ~(a | b);
            // Bitwise NOR: First compute OR, then bitwise NOT

            `ALU_SLL:   result = a << b[4:0];
            // Logical Shift Left: shift `a` left by amount in b[4:0]
            // `<<` shifts bits to the left, padding with zeros on the right

            `ALU_SRL:   result = a >> b[4:0];
            // Logical Shift Right: shift `a` right by b[4:0] (zero-fill)
            // `>>` shifts bits right, padding with zeros on the left

            `ALU_SRA:   result = $signed(a) >>> b[4:0];
            // Arithmetic Shift Right: sign-extend the shifted bits
            // `>>>` is arithmetic right shift operator (preserves sign)
            // `$signed()` casts a to a signed number before shifting

            `ALU_SLT:   result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            // Set Less Than (signed): If a < b, result = 1 else 0
            // `? :` is the ternary operator: condition ? true_value : false_value
            // `32'd1` means 32-bit decimal 1

            `ALU_SLTU:  result = (a < b) ? 32'd1 : 32'd0;
            // Set Less Than Unsigned: compares `a` and `b` as unsigned numbers

            `ALU_EQ:    result = (a == b) ? 32'd1 : 32'd0;
            // Equality check: If a == b, result = 1 else 0

            `ALU_NEQ:   result = (a != b) ? 32'd1 : 32'd0;
            // Not equal check

            `ALU_GT:    result = ($signed(a) > $signed(b)) ? 32'd1 : 32'd0;
            // Greater than (signed)

            `ALU_LT:    result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            // Less than (signed) — similar to `ALU_SLT`

            `ALU_PASS:  result = a;
            // Pass-through: return operand `a` unchanged

            default:    result = 32'bx;
            // If opcode doesn't match any case, result is undefined (all x)

        endcase

        zero     = (result == 32'b0);
        // Set zero flag if result is all zeros

        negative = result[31];
        // Set negative flag based on MSB of result (sign bit in 2's complement)

        overflow = (opcode == `ALU_ADD) ? ((a[31] == b[31]) && (result[31] != a[31])) :
                   (opcode == `ALU_SUB) ? ((a[31] != b[31]) && (result[31] != a[31])) : 1'b0;
        // Overflow flag logic:
        // For addition: overflow if inputs had same sign but result has different sign
        // For subtraction: overflow if inputs had opposite sign and result sign mismatches with a
        // Otherwise, overflow is zero
    end

endmodule
