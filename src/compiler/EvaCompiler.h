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
 * Eva compiler.
 */

#ifndef EvaCompiler_h
#define EvaCompiler_h

#include <map>
#include <set>
#include <string>

#include "../disassembler/EvaDisassembler.h"
#include "../parser/EvaParser.h"
#include "../vm/EvaValue.h"
#include "../vm/Global.h"
#include "Scope.h"

// -----------------------------------------------------------------

/**
 * Compiler class, emits bytecode, records constant pool, vars, etc.
 */
class EvaCompiler {
 public:
  EvaCompiler(std::shared_ptr<Global> global)
      : global(global),
        disassembler(std::make_unique<EvaDisassembler>(global)) {}

  /**
   * Main compile API.
   */
  void compile(const Exp& exp) {
    // Implement here...
  }

  /**
   * Scope analysis.
   */
  void analyze(const Exp& exp, std::shared_ptr<Scope> scope) {
    // Implement here...
  }

  /**
   * Main compile loop.
   */
  void gen(const Exp& exp) {
    switch (exp.type) {
      /**
       * ----------------------------------------------
       * Numbers.
       */
      case ExpType::NUMBER:
        // Implement here...
        break;

      /**
       * ----------------------------------------------
       * Strings.
       */
      case ExpType::STRING:
        // Implement here...
        break;

      /**
       * ----------------------------------------------
       * Symbols (variables, operators).
       */
      case ExpType::SYMBOL:
        /**
         * Boolean.
         */
        if (exp.string == "true" || exp.string == "false") {
          // Implement here...
        } else {
          // Variables:
          // Implement here...
        }
        break;

      /**
       * ----------------------------------------------
       * Lists.
       */
      case ExpType::LIST:
        auto tag = exp.list[0];

        /**
         * ----------------------------------------------
         * Special cases.
         */
        if (tag.type == ExpType::SYMBOL) {
          auto op = tag.string;

          // Implement here...

        }

        // --------------------------------------------
        // Lambda function calls:
        //
        // ((lambda (x) (* x x)) 2)

        else {
          // Implement here...
        }

        break;
    }
  }

  /**
   * Disassemble code objects.
   */
  void disassembleBytecode() {
    for (auto& co_ : codeObjects_) {
      disassembler->disassemble(co_);
    }
  }

  /**
   * Returns main function (entry point).
   */
  FunctionObject* getMainFunction() { return main; }

  /**
   * Returns all constant traceable objects.
   */
  std::set<Traceable*>& getConstantObjects() { return constantObjects_; }

 private:
  /**
   * Global object.
   */
  std::shared_ptr<Global> global;

  /**
   * Disassembler.
   */
  std::unique_ptr<EvaDisassembler> disassembler;

  /**
   * Compiles a function.
   */
  void compileFunction(const Exp& exp, const std::string fnName,
                       const Exp& params, const Exp& body) {
    // Implement here...
  }

  /**
   * Creates a new code object.
   */
  EvaValue createCodeObjectValue(const std::string& name, size_t arity = 0) {
    // Implement here...
  }

  /**
   * Enters a new block.
   */
  void blockEnter() { co->scopeLevel++; }

  /**
   * Exits a block.
   */
  void blockExit() {
    // Implement here...
  }

  /**
   * Whether it's the global scope.
   */
  bool isGlobalScope() { return co->name == "main" && co->scopeLevel == 1; }

  /**
   * Whether it's the global scope.
   */
  bool isFunctionBody() { return co->name != "main" && co->scopeLevel == 1; }

  /**
   * Whether the expression is a declaration.
   */
  bool isDeclaration(const Exp& exp) {
    return isVarDeclaration(exp) || isFunctionDeclaration(exp) ||
           isClassDeclaration(exp);
  }

  /**
   * (class ...)
   */
  bool isClassDeclaration(const Exp& exp) { return isTaggedList(exp, "class"); }

  /**
   * (prop ...)
   */
  bool isProp(const Exp& exp) { return isTaggedList(exp, "prop"); }

  /**
   * (var <name> <value>)
   */
  bool isVarDeclaration(const Exp& exp) { return isTaggedList(exp, "var"); }

  /**
   * (lambda ...)
   */
  bool isLambda(const Exp& exp) { return isTaggedList(exp, "lambda"); }

  /**
   * (def <name> ...)
   */
  bool isFunctionDeclaration(const Exp& exp) {
    return isTaggedList(exp, "def");
  }

  /**
   * (begin ...)
   */
  bool isBlock(const Exp& exp) { return isTaggedList(exp, "begin"); }

  /**
   * Tagged lists.
   */
  bool isTaggedList(const Exp& exp, const std::string& tag) {
    return exp.type == ExpType::LIST && exp.list[0].type == ExpType::SYMBOL &&
           exp.list[0].string == tag;
  }

  /**
   * Pop the variables of the current scope,
   * returns number of vars used.
   */
  size_t getVarsCountOnScopeExit() {
    // Implement here...
  }

  /**
   * Returns current bytecode offset.
   */
  uint16_t getOffset() { return (uint16_t)co->code.size(); }

  /**
   * Allocates a numeric constant.
   */
  size_t numericConstIdx(double value) {
    // Implement here...
  }

  /**
   * Allocates a string constant.
   */
  size_t stringConstIdx(const std::string& value) {
    // Implement here...
  }

  /**
   * Allocates a boolean constant.
   */
  size_t booleanConstIdx(bool value) {
    // Implement here...
  }

  /**
   * Emits data to the bytecode.
   */
  void emit(uint8_t code) { co->code.push_back(code); }

  /**
   * Writes byte at offset.
   */
  void writeByteAtOffset(size_t offset, uint8_t value) {
    co->code[offset] = value;
  }

  /**
   * Patches jump address.
   */
  void patchJumpAddress(size_t offset, uint16_t value) {
    writeByteAtOffset(offset, (value >> 8) & 0xff);
    writeByteAtOffset(offset + 1, value & 0xff);
  }

  /**
   * Returns a class object by name.
   */
  ClassObject* getClassByName(const std::string& name) {
    // Implement here...
  }

  /**
   * Scope info.
   */
  std::map<const Exp*, std::shared_ptr<Scope>> scopeInfo_;

  /**
   * Scopes stack.
   */
  std::stack<std::shared_ptr<Scope>> scopeStack_;

  /**
   * Compiling code object.
   */
  CodeObject* co;

  /**
   * Main entry point (function).
   */
  FunctionObject* main;

  /**
   * All code objects.
   */
  std::vector<CodeObject*> codeObjects_;

  /**
   * All objects from the constant pools of all code objects.
   */
  std::set<Traceable*> constantObjects_;

  /**
   * Currently compiling class object.
   */
  ClassObject* classObject_;

  /**
   * All class objects.
   */
  std::vector<ClassObject*> classObjects_;

  /**
   * Compare ops map.
   */
  static std::map<std::string, uint8_t> compareOps_;
};

/**
 * Compare ops map.
 */
std::map<std::string, uint8_t> EvaCompiler::compareOps_ = {
    {"<", 0}, {">", 1}, {"==", 2}, {">=", 3}, {"<=", 4}, {"!=", 5},
};

#endif