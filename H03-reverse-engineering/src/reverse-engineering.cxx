/**
 * \file reverse=engineering.cxx
 *
 * This file is part of the course wi4771tu:
 * Object Oriented Scientific Programming in C++
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

    int a = 1;
    int b = 2;
    int c = 3;
    const int d = 42;

    {
        auto b = ++a + c++;
        auto e = b;
        c += ++b;
    }

    int *p = &a;
    int *q = &b;

    ++(*q);
    *p += a++ + (*p)++;

    int A[] = {1, 2, 3, 4, 5};
    int *r = A;

    int e(*(r+3));

    double f = 0;
    int g;
    for (g = 0; g < 5; g++)
        f += A[g] / 5;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "g = " << g << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
