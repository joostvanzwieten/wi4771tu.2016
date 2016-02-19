/**
 * \file pointers.cxx
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
    int i = 1;
    std::cout << "Integer i of type "
              << typeid(i).name()
              << " is stored at " << &i << std::endl;

    // Another integer variable
    int j = i;
    std::cout << "Integer j of type "
              << typeid(j).name()
              << " is stored at " << &j << std::endl;

    // Address-of operator (&)
    auto address = &i;
    std::cout << "Address-of operator:  " << typeid(address).name() << std::endl;

    // Dereference operator (*)
    std::cout << "Dereference operator: " << *address << std::endl;
    
    // Integer pointer
    int *p = &i;
    std::cout << "Pointer p of type "
              << typeid(p).name()
              << " is stored at " << &p << std::endl;

    // Output
    std::cout <<   "i = " << i
              << "\nj = " << j
              << "\np = " << *p << std::endl;

    // Now change value of variable i
    i = 2;

    // Output again
    std::cout <<   "i = " << i
              << "\nj = " << j
              << "\np = " << *p << std::endl;

    // Dereference pointer and change its value
    *p = 3;

    // Output again
    std::cout <<   "i = " << i
              << "\nj = " << j
              << "\np = " << *p << std::endl;

    // Change pointer
    p = p+1;

    // Output again
    std::cout <<   "i = " << i
              << "\nj = " << j
              << "\np = " << *p << std::endl;
    
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
