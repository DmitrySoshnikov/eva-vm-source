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
 * Eva Virtual Machine.
 */

#ifndef EvaVM_h
#define EvaVM_h

#include <array>
#include <stack>
#include <string>
#include <vector>

#include "../Logger.h"
#include "../bytecode/OpCode.h"
#include "../compiler/EvaCompiler.h"
#include "../gc/EvaCollector.h"
#include "../parser/EvaParser.h"
#include "EvaValue.h"
#include "Global.h"

using syntax::EvaParser;

/**
 * Reads the current byte in the bytecode
 * and advances the ip pointer.
 */
#define READ_BYTE()  // Implement here...

/**
 * Reads a short word (2 bytes).
 */
#define READ_SHORT()  // Implement here...

/**
 * Converts bytecode index to a pointer.
 */
#define TO_ADDRESS(index) (&fn->co->code[index])

/**
 * Gets a constant from the pool.
 */
#define GET_CONST() (fn->co->constants[READ_BYTE()])

/**
 * Stack top (stack overflow after exceeding).
 */
#define STACK_LIMIT 512

/**
 * Memory threshold after which GC is triggered.
 */
#define GC_TRESHOLD 1024

/**
 * Runtime allocation, can call GC.
 */
#define MEM(allocator, ...)  // Implement here...

/**
 * Binary operation.
 */
#define BINARY_OP(op)  // Implement here...

/**
 * Generic values comparison.
 */
#define COMPARE_VALUES(op, v1, v2)  // Implement here...

// --------------------------------------------------

/**
 * Stack frame for function calls.
 */
struct Frame {
  // Implement here...
};

// --------------------------------------------------

/**
 * Eva Virtual Machine.
 */
class EvaVM {
 public:
  EvaVM()
      : global(std::make_shared<Global>()),
        parser(std::make_unique<EvaParser>()),
        compiler(std::make_unique<EvaCompiler>(global)),
        collector(std::make_unique<EvaCollector>()) {
    setGlobalVariables();
  }

  /**
   * VM shutdown.
   */
  ~EvaVM() { Traceable::cleanup(); }

  //----------------------------------------------------
  // Stack operations:

  /**
   * Pushes a value onto the stack.
   */
  void push(const EvaValue& value) {
    // Implement here...
  }

  /**
   * Pops a value from the stack.
   */
  EvaValue pop() {
    // Implement here...
  }

  /**
   * Peeks an element from the stack.
   */
  EvaValue peek(size_t offset = 0) {
    // Implement here...
  }

  /**
   * Pops multiple values from the stack.
   */
  void popN(size_t count) {
    // Implement here...
  }

  //----------------------------------------------------
  // GC operations:

  /**
   * Obtains GC roots: variables on the stack, globals, constants.
   */
  std::set<Traceable*> getGCRoots() {
    // Implement here...
  }

  /**
   * Returns stack GC roots.
   */
  std::set<Traceable*> getStackGCRoots() {
    // Implement here...
  }

  /**
   * Returns GC roots for constants.
   */
  std::set<Traceable*> getConstantGCRoots() {
    // Implement here...
  }

  /**
   * Returns global GC roots.
   */
  std::set<Traceable*> getGlobalGCRoots() {
    // Implement here...
  }

  /**
   * Spawns a potential GC cycle.
   */
  void maybeGC() {
    // Implement here...
  }

  //----------------------------------------------------
  // Program execution

  /**
   * Executes a program.
   */
  EvaValue exec(const std::string& program) {
    // 1. Parse the program
    auto ast = parser->parse("(begin " + program + ")");

    // 2. Compile program to Eva bytecode
    compiler->compile(ast);

    // Start from the main entry point:
    fn = compiler->getMainFunction();

    // Implement here...

    return eval();
  }

  /**
   * Main eval loop.
   */
  EvaValue eval() {
    for (;;) {
      // Implement here...
    }
  }

  /**
   * Sets up global variables and function.
   */
  void setGlobalVariables() {
    // Implement here...
  }

  /**
   * Global object.
   */
  std::shared_ptr<Global> global;

  /**
   * Parser.
   */
  std::unique_ptr<EvaParser> parser;

  /**
   * Compiler.
   */
  std::unique_ptr<EvaCompiler> compiler;

  /**
   * Garbage collector.
   */
  std::unique_ptr<EvaCollector> collector;

  /**
   * Instruction pointer (aka Program counter).
   */
  uint8_t* ip;

  /**
   * Stack pointer.
   */
  EvaValue* sp;

  /**
   * Base pointer (aka Frame pointer).
   */
  EvaValue* bp;

  /**
   * Operands stack.
   */
  std::array<EvaValue, STACK_LIMIT> stack;

  /**
   * Separate stack for calls. Keeps return addresses.
   */
  std::stack<Frame> callStack;

  /**
   * Currently executing function.
   */
  FunctionObject* fn;

  // --------------------------------------------------
  // Debug functions:

  /**
   * Dumps current stack.
   */
  void dumpStack() {
    // Implement here...
  }
};

#endif