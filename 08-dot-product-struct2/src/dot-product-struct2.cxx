/**
 * \file dot-product-struct2.cxx
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

// Include header file for initializer list
#include <initializer_list>

// Include header file for memory
#include <memory>

// Structure encapsulating array and its lengths
struct Vector
{
    // Constructor
    Vector()
    { }
    
    // Constructor (does not allow uniform initialisation)
    Vector(int length)
    :length(length)
    {
        array = new double[length];
    }

    // Constructor (with initialiser list and delegate constructor)
    Vector(std::initializer_list<double> list)
    : Vector((int)list.size())
    {
        std::uninitialized_copy(list.begin(), list.end(), array);
    }
    
    // Destructor
    ~Vector()
    {
        delete[] array;
        length = 0;
    }
    
    // Attributes
    double* array;
    int length = 0;

    // Dot product implemented as member function
    double dot_product(const Vector& b)
    {
        // Throw exception if the vectors have different length
        if (length!=b.length) throw "Vectors have different size!";

        // Calculate the dot product
        double d=0;
        for (auto i=0; i<length; i++)
            d += array[i]*b.array[i];
        return d;
    }   
    
    // Dot product implemented as operator
    double operator*(const Vector& b) const
    {
        // Throw exception if the vectors have different length
        if (length!=b.length) throw "Vectors have different size!";

        // Calculate the dot product
        double d=0;
        for (auto i=0; i<length; i++)
            d += array[i]*b.array[i];
        return d;
    }

    // Addition implemented as operator
    Vector& operator+(const Vector& b)
    {
        // Throw exception if the vectors have different length
        if (length!=b.length) throw "Vectors have different size!";

        // Add two vectors
        for (auto i=0; i<length; i++)
            array[i] += b.array[i];
        
        return *this;
    }
    
    // ()-operator
    const double operator()(int index) const
    {
        if (length<index) throw "Index exceeds vector length";
        
        return array[index];
    }

};

// Dot product implemented as external function
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

    Vector a;
    
    // Construct vector structures
    Vector x = { 1, 2, 3, 4, 5 };
    Vector y = { 2, 4, 6, 8, 10};
    Vector z = { 1, 3, 5, 7};

    try
    {
        std::cout << dot_product(x, y) << std::endl;
        std::cout << x.dot_product(y)  << std::endl;
        std::cout << x*y               << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }

        try
    {
        std::cout << dot_product(x, z) << std::endl;
        std::cout << x.dot_product(z)  << std::endl;
        std::cout << x*z               << std::endl;
    } catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
