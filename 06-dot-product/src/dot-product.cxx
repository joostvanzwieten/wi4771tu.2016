/**
 * \file dot-product.cxx
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

// Include cassert header file from standard library
#define NDEBUG
#include <cassert>

// Include header file for standard exception handling
#include <exception>

// Compute dot product using assert to check that both vectors have the same length
double dot_product_assert(double* a, int n, double* b, int m)
{
    // Ensure that both vectors have the same length
    assert(n==m);

    // Calculate the dot product
    double d=0;
    for (auto i=0; i<n; i++)
        d += a[i]*b[i];
    return d;
}

// Compute dot product, whereby an exception is thrown of both vectors have different length
double dot_product_exception(double* a, int n, double* b, int m)
{
    // Throw exception if the vectors have different length
    if (n!=m) throw "Vectors have different size!";
    
    // Calculate the dot product
    double d=0;
    for (auto i=0; i<n; i++)
        d += a[i]*b[i];
    return d;
}

// The global main function that is the designated start of the program
int main(){

    // Declare and initialise vectors
    double x[5] = { 1, 2, 3, 4, 5 };
    double y[5] = { 2, 4, 6, 8, 10};
    double z[4] = { 1, 3, 5, 7};

    std::cout << dot_product_assert(x, 5, y, 5) << std::endl;
    std::cout << dot_product_assert(x, 5, z, 4) << std::endl;

    std::cout << dot_product_exception(x, 5, y, 5) << std::endl;
    std::cout << dot_product_exception(x, 5, z, 4) << std::endl;
    
    try
    {
        std::cout << dot_product_exception(x, 5, y, 5) << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }

        try
    {
        std::cout << dot_product_exception(x, 5, z, 4) << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
