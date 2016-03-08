/**
 * \file templates-sfinae
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

// Inlcude header file for type traits
#include <type_traits>

// Generic implementation
template<typename T, typename I>
class Demo
{
public:

    template<typename J=I>
    typename std::enable_if<std::is_same<J,int>::value, void>::type
    static info()
    {
        std::cout << "Partially specialised implementation of info() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }

    template<typename J=I>
    typename std::enable_if<!std::is_same<J,int>::value, void>::type
    static info()
    {
        std::cout << "Generic implementation of info() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }

    template<typename J=I>
    typename std::enable_if<std::is_same<J,int>::value, void>::type
    static test()
    {
        std::cout << "Partially specialised implementation of test() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }

    template<typename J=I>
    typename std::enable_if<!std::is_same<J,int>::value, void>::type
    static test()
    {
        std::cout << "Generic implementation of test() for T=" << typeid(T).name()
                  << " I=" << typeid(I).name() << std::endl;
    }
};

// The global main function that is the designated start of the program
int main(){

    Demo<float,const int>::info();
    Demo<double,int>::info();
    Demo<float,long>::info();
    Demo<double,long>::info();


    // Return code 0 to the operating system (=no error)
    return 0;
}
