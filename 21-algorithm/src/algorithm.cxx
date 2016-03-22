/**
 * \file algorithm.cxx
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
#include<vector>

// Include algorithms
#include<algorithm>

// Stream output: iterator way
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& C)
{
    os << "Vector container: {";
    for (auto it=C.cbegin(); it!=C.cend(); ++it)
        os << *it << ",";
    os << "}";
    return os;
}

// The global main function that is the designated start of the program
int main(){

    const std::size_t size = 10;
    typedef std::vector<int> container;
    
    // Objects
    container C1,C2;

    // Information about the vector container
    std::cout << "size:    " << (int) C1.size() << std::endl;
    std::cout << "capacity:" << (int) C1.capacity() << std::endl;
    std::cout << "max_size:" << (int) C1.max_size() << std::endl;
    
    // Fill container (by appending data)
    for (auto i=0; i<size; i++)
        C1.push_back(std::rand()%100);

    std::cout << C1 << std::endl;

    // Information about the vector container
    std::cout << "size:    " << (int) C2.size() << std::endl;
    std::cout << "capacity:" << (int) C2.capacity() << std::endl;
    std::cout << "max_size:" << (int) C2.max_size() << std::endl;

    // Fill container (by appending data)
    for (auto i=0; i<size; i++)
        C2.push_back(std::rand()%200);
    
    std::cout << C2 << std::endl;

    // Sort both containers
    std::sort(C1.begin(), C1.end());
    std::sort(C2.begin(), C2.end());

    std::cout << C1 << std::endl;
    std::cout << C2 << std::endl;

    // Swap both containers
    std::swap(C1,C2);

    std::cout << C1 << std::endl;
    std::cout << C2 << std::endl;
    
    // Count number of occurance of 42
    auto m = std::count(C1.cbegin(), C1.cend(), 42);
    std::cout << "Occurance of 42: " << m << std::endl;
    
    // Count number of occurance of >42
    auto n = std::count_if(C1.cbegin(), C1.cend(), [](int i){return i>42;} );
    std::cout << "Occurance of >42: " << n << std::endl;
    
    // Find position of 42
    auto p = std::find(C1.cbegin(), C1.cend(), 42);
    std::cout << "Iterator =42: " << *p << std::endl;
    
    // Find position of >42
    auto q = std::find_if(C1.cbegin(), C1.cend(), [](int i){return i>42;} );
    std::cout << "Iterator >42: " << *q << std::endl;

    // Merge both vectors (the function template std::back_inserted
    // constructs a std::back_insert_iterator for the given container
    // so that std::merge can append data to the result vector C)
    container C;
    auto r = std::merge(C1.cbegin(), C1.cend(),
                        C2.cbegin(), C2.cend(),
                        std::back_inserter(C));

    // Information about the vector container
    std::cout << "size:    " << (int) C.size() << std::endl;
    std::cout << "capacity:" << (int) C.capacity() << std::endl;
    std::cout << "max_size:" << (int) C.max_size() << std::endl;
    std::cout << C << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
