/**
 * \file templates-partial-specialisation.cxx
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

// Generic (fully templated) implementation
template<typename T, typename I>
class Demo
{
public:
    static void info()
    {
        std::cout << "Generic implementation of info() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }

    static void test()
    {
        std::cout << "Generic implementation of test() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }
};

// Full class specialisation for float-long
template<>
class Demo<float,long>
{
public:
    static void info()
    {
        std::cout << "Fully specialised class implementation of info() for T=float and I=long" << std::endl;
    }
};

// Full function specialisation for double-long
template<>
void Demo<double,long>::info()
{
    std::cout << "Fully specialised function implementation of info() for T=double and I=long" << std::endl;
}


// Partial class specialisation for double-*
template<typename I>
class Demo<double,I>
{
public:
    static void info()
    {
        std::cout << "Partially specialised implementation of info() for T=double and I="
                  << typeid(I).name() << std::endl;
    }
    static void test()
    {
        std::cout << "Partially specialised implementation of test() for T=double and I="
                  << typeid(I).name() << std::endl;
    }
};

// The global main function that is the designated start of the program
int main(){

    Demo<float,int>::info();
    Demo<float,int>::test();
    
    Demo<float,long>::info();
    //Demo<float,long>::test(); // compiler error

    Demo<double,long>::info();
    Demo<double,long>::test();
    
    Demo<double,int>::info();
    Demo<double,int>::test();
        
    // Return code 0 to the operating system (=no error)
    return 0;
}
