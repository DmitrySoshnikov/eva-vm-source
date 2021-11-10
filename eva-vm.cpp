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
 * Eva VM executable.
 */

#include <fstream>
#include <iostream>
#include <string>

#include "src/Logger.h"
#include "src/vm/EvaVM.h"
#include "src/vm/EvaValue.h"

void printHelp() {
  std::cout << "\nUsage: eva-vm [options]\n\n"
            << "Options:\n"
            << "    -e, --expression  Expression to parse\n"
            << "    -f, --file        File to parse\n\n";
}

/**
 * Eva VM main executable.
 */
int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printHelp();
    return 0;
  }

  /**
   * Expression mode.
   */
  std::string mode = argv[1];

  /**
   * Program to execute.
   */
  std::string program;

  /**
   * Simple expression.
   */
  if (mode == "-e") {
    program = argv[2];
  }

  /**
   * Eva file.
   */
  else if (mode == "-f") {
    // Read the file:
    std::ifstream programFile(argv[2]);
    std::stringstream buffer;
    buffer << programFile.rdbuf() << "\n";

    // Program:
    program = buffer.str();
  }

  /**
   * VM instance.
   */
  EvaVM vm;

  /**
   * Evaluation result.
   */
  auto result = vm.exec(program);

  std::cout << "\n";
  log(result);
  std::cout << "\n";

  return 0;
}