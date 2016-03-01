/**
 * \file auto-decltype.cxx
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

// Class Calc_Cpp11 makes use of the automatic function return type
// introduced with C++11, whereby the compiler must be explicitly
// instructed how to deduce the return type
class Calc_Cpp11 {
public:
    auto sum(int a, int b) -> decltype(a+b)
    {
        return a+b;
    }

    auto sum(int a, int b, int c) -> decltype(sum(sum(a,b),c))
    {
        return sum(sum(a,b),c);
    }
};

// Class Calc_Cpp14 makes use of the automatic return type deduction
// (without explicitly instructing the compiler how to deduce the
// return type) introduced with C++14

class Calc_Cpp14 {
public:
    auto sum(int a, int b)
    {
        return a+b;
    }

    auto sum(int a, int b, int c)
    {
        return sum(sum(a,b),c);
    }
};

#if (__GNUC__ >= 5)
// Class Calc_Cpp17 makes use of the automatic type deduction which
// might become available with C++17
class Calc_Cpp17 {
public:
    auto sum(auto a, auto b)
    {
        return a+b;
    }

    auto sum(auto a, auto b, auto c)
    {
        return sum(sum(a,b),c);
    }
};
#endif

// Class Calc_TMP makes use of template meta programming
class Calc_TMP {
public:
    template<typename A, typename B>
    auto sum(A a, B b)
    {
        return a+b;
    }
    
    template<typename A, typename B, typename C>
    auto sum(A a, B b, C c)
    {
        return sum<decltype(sum<A,B>(a,b)),C>(sum<A,B>(a,b),c);
    }
};

// The global main function that is the designated start of the program
int main(){

    Calc_Cpp11 Cpp11;
    std::cout << Cpp11.sum(1,2) << std::endl;
    std::cout << Cpp11.sum(1,2,3) << std::endl;

    Calc_Cpp14 Cpp14;
    std::cout << Cpp14.sum(1,2) << std::endl;
    std::cout << Cpp14.sum(1,2,3) << std::endl;

#if (__GNUC__ >= 5)
    Calc_Cpp17 Cpp17;
    std::cout << Cpp17.sum(1,2) << std::endl;
    std::cout << Cpp17.sum(1,2,3) << std::endl;

    std::cout << Cpp17.sum(1.2,2) << std::endl;
    std::cout << Cpp17.sum(1.2,2,3.1) << std::endl;

    std::cout << Cpp17.sum(1.2,2.8) << std::endl;
    std::cout << Cpp17.sum(1.2,2.1,3.7) << std::endl;
#endif

    Calc_TMP TMP;
    std::cout << TMP.sum<int,int>(1,2) << std::endl;
    std::cout << TMP.sum<int,int,int>(1,2,3) << std::endl;

    std::cout << TMP.sum<double,int>(1.2,2) << std::endl;
    std::cout << TMP.sum<double,int,double>(1.2,2,3.1) << std::endl;

    std::cout << TMP.sum<double,double>(1.2,2.8) << std::endl;
    std::cout << TMP.sum<double,double,double>(1.2,2.1,3.7) << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
