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
 * Eva value.
 */

#ifndef EvaValue_h
#define EvaValue_h

#include <list>
#include <string>
#include <vector>

/**
 * Eva value type.
 */
enum class EvaValueType {
  NUMBER,
  BOOLEAN,
  OBJECT,
};

/**
 * Object type.
 */
enum class ObjectType {
  STRING,
  CODE,
  NATIVE,
  FUNCTION,
  CELL,
  CLASS,
  INSTANCE,
};

// ----------------------------------------------------------------

/**
 * Base traceable object.
 */
struct Traceable {
  /**
   * Whether the object was marked during the trace.
   */
  bool marked;

  /**
   * Allocated size.
   */
  size_t size;

  /**
   * Allocator.
   */
  static void* operator new(size_t size) {
    // Implement here...
  }

  /**
   * Deallocator.
   */
  static void operator delete(void* object, std::size_t sz) {
    // Implement here...
  }

  /**
   * Clean up for all objects.
   */
  static void cleanup() {
    // Implement here...
  }

  /**
   * Printes memory stats
   */
  static void printStats() {
    // Implement here...
  }

  /**
   * Total number of allocated bytes.
   */
  static size_t bytesAllocated;

  /**
   * List of all allocated objects.
   */
  static std::list<Traceable*> objects;
};

/**
 * Total bytes allocated.
 */
size_t Traceable::bytesAllocated{0};

/**
 * List of all allocated objects.
 */
std::list<Traceable*> Traceable::objects{};

// ----------------------------------------------------------------

/**
 * Base object.
 */
struct Object : public Traceable {
  Object(ObjectType type) : type(type) {}
  ObjectType type;
};

// ----------------------------------------------------------------

/**
 * String object.
 */
struct StringObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

using NativeFn = std::function<void()>;

/**
 * Native function.
 */
struct NativeObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

/**
 * Eva value (tagged union).
 */
struct EvaValue {
  EvaValueType type;
  union {
    double number;
    bool boolean;
    Object* object;
  };
};

// ----------------------------------------------------------------

/**
 * Class object.
 */
struct ClassObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

/**
 * Instance object.
 */
struct InstanceObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

struct LocalVar {
  // Implement here...
};

/**
 * Code object.
 *
 * Contains compiling bytecode, locals and other
 * state needed for function execution.
 */
struct CodeObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

/**
 * Heap-allocated cell.
 *
 * Used to capture closured variables.
 */
struct CellObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------

/**
 * Function object.
 */
struct FunctionObject : public Object {
  // Implement here...
};

// ----------------------------------------------------------------
// Constructors:

#define NUMBER(value) ((EvaValue){EvaValueType::NUMBER, .number = value})

// Implement here...

// ----------------------------------------------------------------
// Accessors:

#define AS_NUMBER(evaValue) ((double)(evaValue).number)

// Implement here...

// ----------------------------------------------------------------
// Testers:

#define IS_NUMBER(evaValue) ((evaValue).type == EvaValueType::NUMBER)

// Implement here...

// ----------------------------------------------------------------

/**
 * String representation used in constants for debug.
 */
std::string evaValueToTypeString(const EvaValue& evaValue) {
  // Implement here...
}

/**
 * String representation used in constants for debug.
 */
std::string evaValueToConstantString(const EvaValue& evaValue) {
  // Implement here...
}

/**
 * Output stream.
 */
std::ostream& operator<<(std::ostream& os, const EvaValue& evaValue) {
  return os << "EvaValue (" << evaValueToTypeString(evaValue)
            << "): " << evaValueToConstantString(evaValue);
}

#endif