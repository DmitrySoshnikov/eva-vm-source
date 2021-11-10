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
 * Garbage Collector.
 */

#ifndef EvaCollector_h
#define EvaCollector_h

/**
 * Garbage collector implementing Mark-Sweep algorithm.
 */
struct EvaCollector {
  /**
   * Main collection cycle.
   */
  void gc(const std::set<Traceable *> &roots) {
    // Implement here...
  }

  /**
   * Marking phase (trace).
   */
  void mark(const std::set<Traceable *> &roots) {
    // Implement here...
  }

  /**
   * Returns all pointers within this object.
   */
  std::set<Traceable *> getPointers(const Traceable *object) {
    // Implement here...
  }

  /**
   * Sweep phase (reclaim).
   */
  void sweep() {
    // Implement here...
  }
};

#endif