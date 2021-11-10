/**
 * Eva programming language.
 *
 * VM implementation.
 *
 * Course info: http://dmitrysoshnikov.com/courses/virtual-machine/
 *
 * (C) 2021-present Dmitry Soshnikov <dmitry.soshnikov@gmail.com>
 */

/**
 * Instruciton set architecture (ISA) for Eva VM.
 */

#ifndef OpCode_h
#define OpCode_h

/**
 * Stops the program.
 */
#define OP_HALT 0x00

/**
 * Pushes a const onto the stack.
 */
#define OP_CONST 0x01

/**
 * Math instruction.
 */
#define OP_ADD 0x02
#define OP_SUB 0x03
#define OP_MUL 0x04
#define OP_DIV 0x05

/**
 * Comparison.
 */
#define OP_COMPARE 0x06

/**
 * Control flow: jump if the value on the stack is false.
 */
#define OP_JMP_IF_FALSE 0x07

/**
 * Unconditional jump.
 */
#define OP_JMP 0x08

/**
 * Returns a global variable.
 */
#define OP_GET_GLOBAL 0x09

/**
 * Sets global variable value.
 */
#define OP_SET_GLOBAL 0x0A

/**
 * Pops a value from the stack.
 */
#define OP_POP 0x0B

/**
 * Returns a local variable.
 */
#define OP_GET_LOCAL 0x0C

/**
 * Sets a local variable value.
 */
#define OP_SET_LOCAL 0x0D

/**
 * Exits scope.
 */
#define OP_SCOPE_EXIT 0x0E

/**
 * Function call.
 */
#define OP_CALL 0x0F

/**
 * Return from a function.
 */
#define OP_RETURN 0x10

/**
 * Returns a cell value.
 */
#define OP_GET_CELL 0x11

/**
 * Sets a cell value.
 */
#define OP_SET_CELL 0x12

/**
 * Loads a cell onto the stack.
 */
#define OP_LOAD_CELL 0x13

/**
 * Makes a function.
 */
#define OP_MAKE_FUNCTION 0x14

/**
 * Create a new instance of a class.
 */
#define OP_NEW 0x15

/**
 * Property access.
 */
#define OP_GET_PROP 0x16

/**
 * Property write.
 */
#define OP_SET_PROP 0x17

// -----------------------------------------------------------

std::string opcodeToString(uint8_t opcode) {
  // Implement here...
}

#endif