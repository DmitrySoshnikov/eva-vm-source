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
 * Scope analysis.
 */

#ifndef Scope_h
#define Scope_h

#include <map>
#include <set>

/**
 * Scope type.
 */
enum class ScopeType {
  GLOBAL,
  FUNCTION,
  BLOCK,
  CLASS,
};

/**
 * Allocation type.
 */
enum class AllocType {
  GLOBAL,
  LOCAL,
  CELL,
};

/**
 * Scope structure.
 */
struct Scope {
  Scope(ScopeType type, std::shared_ptr<Scope> parent)
      : type(type), parent(parent) {}

  /**
   * Registers a local.
   */
  void addLocal(const std::string& name) {
    // Implement here...
  }

  /**
   * Registers an own cell.
   */
  void addCell(const std::string& name) {
    // Implement here...
  }

  /**
   * Registers a free var (parent cell).
   */
  void addFree(const std::string& name) {
    // Implement here...
  }

  /**
   * Potentially promotes a variable from local to cell.
   */
  void maybePromote(const std::string& name) {
    // Implement here...
  }

  /**
   * Promotes a variable from local (stack) to cell (heap).
   */
  void promote(const std::string& name, Scope* ownerScope) {
    // Implement here...
  }

  /**
   * Resolves a variable in the scope chain.
   *
   * Initially a variable is treated as local, however if during
   * the resolution we passed the own function boundary, it is
   * free, and hence should be promoted to a cell, unless global.
   */
  std::pair<Scope*, AllocType> resolve(const std::string& name,
                                       AllocType allocType) {
    // Implement here...
  }

  /**
   * Returns get opcode based on allocation type.
   */
  int getNameGetter(const std::string& name) {
    // Implement here...
  }

  /**
   * Returns set opcode based on allocation type.
   */
  int getNameSetter(const std::string& name) {
    // Implement here...
  }

  /**
   * Scope type.
   */
  ScopeType type;

  /**
   * Parent scope.
   */
  std::shared_ptr<Scope> parent;

  /**
   * Allocation info.
   */
  std::map<std::string, AllocType> allocInfo;

  /**
   * Set of free vars.
   */
  std::set<std::string> free;

  /**
   * Set of own cells.
   */
  std::set<std::string> cells;
};

#endif