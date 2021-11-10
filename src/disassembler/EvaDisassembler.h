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
 * Eva disassembler.
 */

#ifndef EvaDisassembler_h
#define EvaDisassembler_h

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

#include "../bytecode/OpCode.h"
#include "../vm/EvaValue.h"
#include "../vm/Global.h"

/**
 * Eva disassembler.
 */
class EvaDisassembler {
 public:
  EvaDisassembler(std::shared_ptr<Global> global) : global(global) {}
  /**
   * Disassembles a code unit.
   */
  void disassemble(CodeObject* co) {
    // Implement here...
  }

 private:
  /**
   * Disassembles individual instruction.
   */
  size_t disassembleInstruction(CodeObject* co, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles simple instruction.
   */
  size_t disassembleSimple(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles a word.
   */
  size_t disassembleWord(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles const instruction: OP_CONST <index>
   */
  size_t disassembleConst(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles global variable instruction.
   */
  size_t disassembleGlobal(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles local variable instruction.
   */
  size_t disassembleLocal(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles property instruction.
   */
  size_t disassembleProperty(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles cell instruction.
   */
  size_t disassembleCell(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles make function.
   */
  size_t disassembleMakeFunction(CodeObject* co, uint8_t opcode,
                                 size_t offset) {
    // Implement here...
  }

  /**
   * Dumps raw memory from the bytecode.
   */
  void dumpBytes(CodeObject* co, size_t offset, size_t count) {
    // Implement here...
  }

  /**
   * Prints opcode.
   */
  void printOpCode(uint8_t opcode) {
    std::cout << std::left << std::setfill(' ') << std::setw(20)
              << opcodeToString(opcode) << " ";
  }

  /**
   * Disassembles compare instruction.
   */
  size_t disassembleCompare(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Disassembles conditional jump.
   */
  size_t disassembleJump(CodeObject* co, uint8_t opcode, size_t offset) {
    // Implement here...
  }

  /**
   * Reads a word at offset.
   */
  uint16_t readWordAtOffset(CodeObject* co, size_t offset) {
    return (uint16_t)((co->code[offset] << 8) | co->code[offset + 1]);
  }

  /**
   * Global object.
   */
  std::shared_ptr<Global> global;

  static std::array<std::string, 6> inverseCompareOps_;
};

std::array<std::string, 6> EvaDisassembler::inverseCompareOps_ = {
    "<", ">", "==", ">=", "<=", "!=",
};

#endif