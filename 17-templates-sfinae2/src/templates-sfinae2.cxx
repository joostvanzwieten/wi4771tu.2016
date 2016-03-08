/**
 * \file templates-sfinae2.cxx
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

// Include header file for initializer list
#include <initializer_list>

// Include header file for memory
#include <memory>

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
class Vector {
private:
    T* data;
    int n;
    
public:
    // Default constructor
    Vector()
    : data(nullptr), n(0) {}

    // Constructor (sets length and allocates data)
    Vector(int n)
    : data(new T[n]), n(n) {}

    // Constructor (using initializer list)
    Vector(std::initializer_list<T> list)
    : Vector((int)list.size())
    {
        std::uninitialized_copy(list.begin(), list.end(), data);
    }
    
    // Destructor
    ~Vector()
    {
        n=0;
        delete[] data;
    }

    // Add another vector
    Vector<T>& operator+=(const Vector<T>& other)
    {
        for (auto i=0; i<n; i++)
            data[i] += other.data[i];
        return *this;
    }

    // Multiply with a scalar
    Vector<T>& operator*=(T scalar)
    {
        for (auto i=0; i<n; i++)
            data[i] += scalar;
        return *this;
    }

    template<typename U=T>
    typename std::enable_if<is_complex<U>::value, U>::type
    dot(const Vector<T>& other) const
    {
        T d=0;
        for (auto i=0; i<n; i++)
            d += data[i]*std::conj(other.data[i]);
        return d;
    }

    template<typename U=T>
    typename std::enable_if<!is_complex<U>::value, U>::type
    dot(const Vector<T>& other) const
    {
        T d=0;
        for (auto i=0; i<n; i++)
            d += data[i]*other.data[i];
        return d;
    }
    
};

// The global main function that is the designated start of the program
int main(){

    // Real-valued vectors
    Vector<int>    x = { 1,2,3,4,5} ;
    Vector<float>  y = { 1,2,3,4,5} ;
    Vector<double> z = { 1,2,3,4,5} ;

    std::cout << x.dot(x) << std::endl;
    std::cout << y.dot(y) << std::endl;
    std::cout << z.dot(z) << std::endl;

    // Complex valued vectors
    Vector<std::complex<int> >    a = { {1,1} };
    Vector<std::complex<float> >  b = { {1,1} };
    Vector<std::complex<double> > c = { {1,1} };
    
    std::cout << a.dot(a) << std::endl; // calls specialised implementation
    std::cout << b.dot(b) << std::endl; // calls specialised implementation
    std::cout << c.dot(c) << std::endl; // calls specialised implementation
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
