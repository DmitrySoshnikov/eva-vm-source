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
 * Global object.
 */

#ifndef Global_h
#define Global_h

/**
 * Global var.
 */
struct GlobalVar {
  // Implement here...
};

/**
 * Global object.
 */
struct Global {
  /**
   * Returns a global.
   */
  GlobalVar& get(size_t index) { return globals[index]; }

  /**
   * Sets a global.
   */
  void set(size_t index, const EvaValue& value) {
    // Implement here...
  }

  /**
   * Registers a global.
   */
  void define(const std::string& name) {
    // Implement here...
  }

  /**
   * Adds a native function.
   */
  void addNativeFunction(const std::string& name, std::function<void()> fn,
                         size_t arity) {
    // Implement here...
  }

  /**
   * Adds a global constant.
   */
  void addConst(const std::string& name, double value) {
    // Implement here...
  }

  /**
   * Get global index.
   */
  int getGlobalIndex(const std::string& name) {
    // Implement here...
  }

  /**
   * Whether a global variable exists.
   */
  bool exists(const std::string& name) { return getGlobalIndex(name) != -1; }

  /**
   * Global variables and functions.
   */
  std::vector<GlobalVar> globals;
};

#endif