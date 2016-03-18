/**
 * \file complex-conjugate.cxx
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

// Include header file for complex number support
#include <complex>

// Inlcude header file for type traits
#include <type_traits>

template<typename T>
struct is_complex : std::integral_constant<bool,
                                           std::is_same<T,std::complex<short int> >::value     ||
                                           std::is_same<T,std::complex<int> >::value           ||
                                           std::is_same<T,std::complex<long int> >::value      ||
                                           std::is_same<T,std::complex<long long int> >::value ||
                                           std::is_same<T,std::complex<float> >::value         ||
                                           std::is_same<T,std::complex<double> >::value        ||
                                           std::is_same<T,std::complex<long double> >::value
                                           > {};


template<typename T>
typename std::enable_if<is_complex<T>::value, T>::type
static conj(T t)
{
    return T(t.real(), -t.imag());
}

template<typename T>
typename std::enable_if<!is_complex<T>::value, std::complex<T> >::type
static conj(T t)
{
    return T(t);
}


// The global main function that is the designated start of the program
int main(){

    std::complex<float> c(1,1);

    std::cout << c << std::endl;
    std::cout << conj(c) << std::endl;
    std::cout << std::conj(c) << std::endl;

    float f(1);
    std::cout << f << std::endl;
    std::cout << conj(f) << std::endl;
    std::cout << std::conj(f) << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
