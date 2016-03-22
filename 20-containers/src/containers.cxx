/**
 * \file containers.cxx
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

// Include container classes
#include<array>
#include<vector>

// Include algorithms
#include<algorithm>

#include <cassert>

// Stream output: the iterator way
template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T,N>& C)
{
    os << "Array container: {";
    for (auto it=C.cbegin(); it!=C.cend(); ++it)
        os << *it << ((it+1)!=C.cend() ? "," : "");
    os << "}";
    return os;
}

// Stream output: the iterator way
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& C)
{
    os << "Vector container: {";
    for (auto it=C.cbegin(); it!=C.cend(); ++it)
        os << *it << ((it+1)!=C.cend() ? "," : "");
    os << "}";
    return os;
}

// The global main function that is the designated start of the program
int main(){

    // const std::size_t size = 10;
    // typedef std::array<int,size> container;
    typedef std::vector<int> container;

    // Object
    container C;
    C.reserve(20);

    C.push_back(42);
    C.push_back(11);
    C.push_back(1);
    C.push_back(30);
    C.push_back(60);
    
    // Information about the vector container
    std::cout << "size:    " << (int) C.size() << std::endl;
    std::cout << "capacity:" << (int) C.capacity() << std::endl;
    std::cout << "max_size:" << (int) C.max_size() << std::endl; 
    
    // Init
    //for (auto i=0; i<size; i++)
    //    C[i] = i;

    // Output
    std::cout << C << std::endl;

    std::sort(C.begin(), C.end());

    std::cout << C << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
