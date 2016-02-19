/**
 * \file hello.cxx
 *
 * This file is part of the course wi4771tu:
 * Object Oriented Scientific Programming in C++
 *
 * \author Matthias Moller
 *
 */

// Support for precompiled header files (only under MS Visual Studio)
#ifdef _MSC_VER
#include "stdafx.h"
#endif

// Include header file for standard input/output stream library
#include <iostream>

// The global main function that is the designated start of the program
int main(){

  // Write the string 'Hello World' to the default output stream and
  // terminate with a new line (that is what std::endl does)
  std::cout << "Hello world!" << std::endl;

  // Return code 0 to the operating system (=no error)
  return 0;
}
