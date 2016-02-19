/**
 * \file variables-constants.cxx
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

// Include header file for type support library
#include <typeinfo>

// The global main function that is the designated start of the program
int main(){

    // Integer variable
    int a = 10;

    // Integer constant
    const int b = 20;

    a = b;
    // b = 42; // does not work

    // Another integer variable
    int A = b;
    
    // Another integer constant
    const int B = a;

    // Yet another set of integer constants
    const int c = 20;
    const int d(20);
    const int e = {20};

    // Yet another set of integer variables
    int f = 10;
    int g(10);
    int h = {10};
    int i;
    i=10;

    // Mixing types
    float F = 1.7;
    double D = 0.7;

    std::cout << typeid(F).name() << std::endl;
    std::cout << typeid(D).name() << std::endl;
    std::cout << typeid(F+D).name() << std::endl;

    // Automatic determination of type
    auto X = F+D;
    std::cout << typeid(X).name() << std::endl;

    // Type casting
    auto Y = F+(float)D;
    std::cout << typeid(Y).name() << std::endl;

    auto Z = (int) ((double)F+(float)D);
    std::cout << typeid(Z).name() << std::endl;

    // Mixing types (that hardly make sense)
    char  x = 'a';
    float y = 1.7;
    auto  z = x+y;
    std::cout << typeid(z).name() << std::endl;

  // Return code 0 to the operating system (=no error)
  return 0;
}
