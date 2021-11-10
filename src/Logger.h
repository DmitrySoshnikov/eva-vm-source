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
 * Logger and error reporter.
 */

#ifndef Logger_h
#define Logger_h

#include <sstream>

class ErrorLogMessage : public std::basic_ostringstream<char> {
 public:
  ~ErrorLogMessage() {
    std::cerr << "Fatal error: " << str().c_str();
    exit(EXIT_FAILURE);
  }
};

#define DIE ErrorLogMessage()

#define log(value) std::cout << #value << " = " << (value) << "\n";

#endif