/**
 * \file dot-product-struct.cxx
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

// Include header file for standard exception handling
#include <exception>

// Structure encapsulating array and its lengths
struct Vector
{
    // Attributes
    double* array;
    int length = 0;
};

double dot_product(const Vector& a, const Vector& b)
{
    // Throw exception if the vectors have different length
    if (a.length!=b.length) throw "Vectors have different size!";
    
    // Calculate the dot product
    double d=0;
    for (auto i=0; i<a.length; i++)
        d += a.array[i]*b.array[i];
    return d;
}

// The global main function that is the designated start of the program
int main(){

    // Declare vector structures
    Vector x,y,z;

    // Initialise vectors
    x.array = new double[5] { 1, 2, 3, 4, 5 }; x.length=5;
    y.array = new double[5] { 2, 4, 6, 8, 10}; y.length=5;
    z.array = new double[4] { 1, 3, 5, 7};     z.length=4;

     try
    {
        std::cout << dot_product(x, y) << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }

        try
    {
        std::cout << dot_product(x, z) << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
