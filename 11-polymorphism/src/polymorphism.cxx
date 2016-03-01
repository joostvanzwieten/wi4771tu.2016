/**
 * \file polymorphism.cxx
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

// Class Calc provides member functions to compute the sum of two and
// three integer values using static polymorphism (=function
// overloading)
class Calc{
public:
    int sum(int a, int b)
    {
        std::clog << "Calc::sum(a,b)" << std::endl;
        return a+b;
    }
    
    int sum(int a, int b, int c)
    {
        std::clog << "Calc::sum(a,b,c)" << std::endl;
        return sum(sum(a,b),c);
    }
};

// Abstract class BaseCalc provides member functions to compute the
// sum of three integer values using dynamic polymorphism (=function
// overwriting)
class BaseCalc{
public:
    virtual int sum2(int a, int b)
    {
        std::clog << "BaseCalc::sum2(a,b)" << std::endl;
        return a+b;
    }
    
    int sum3(int a, int b, int c)
    {
        std::clog << "BaseCalc::sum3(a,b,c)" << std::endl;
        return sum2(sum2(a,b),c);
    }
};

// Class DerivedCalc is derived from the abstract class BaseCalc and
// provides member function to compute the sum of two integer
// values. It inherits the functionality to compute the sum of three
// integer values from the base class
class DerivedCalc: public BaseCalc{
public:
    int sum2(int a, int b)
    {
        std::clog << "DerivedCalc::sum2(a,b)" << std::endl;
        return a+b;
    }
};

// The global main function that is the designated start of the program
int main(){

    Calc C;
    std::cout << C.sum(1,2) << std::endl;
    std::cout << C.sum(1,2,3) << std::endl;
    
    DerivedCalc D;
    std::cout << D.sum2(1,2) << std::endl;
    std::cout << D.sum3(1,2,3) << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
