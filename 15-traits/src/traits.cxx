/**
 * \file traits
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

template<typename T>
struct is_int
{
    const static bool value = false;
};

template<>
struct is_int<int>
{
    const static bool value = true;
};

// The global main function that is the designated start of the program
int main(){

    std::cout << is_int<int>::value << std::endl;
    std::cout << is_int<double>::value << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
