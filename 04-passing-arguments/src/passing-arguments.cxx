/**
 * \file passing-arguments.cxx
 *
 * This file is part of the course wi4771tu:
 * Object Oriented Scientific Programming in C++
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// \brief addOne_Value_Value
// \param[in]  a  pass variable by value
// \return        return variable by value
int addOne_Value_Value(int a)
{
    return a+1;
}

// \brief addOne_Reference_Value
// \param[in]  a  pass variable by constant reference
// \return        return variable by value
int addOne_Reference_Value(const int &a)
{
    return a+1;
}

// \brief addOne_Value
// \param[in]  a  pass variable by value
void addOne_Value(int a)
{
    a++;
}

// \brief addOneReference
// \param[in]  a  pass variable by reference
// /param[out] a  return variable by reference
void addOne_Reference(int &a)
{
    a++;
}

// The global main function that is the designated start of the program
int main(){

    // Integer variable
    int i = 1;
    int j = 0;
    std::cout << "[Initialisation]         Value of i=" << i
              << " j=" << j << std::endl;
    
    // Call addOne function passing variable i by value
    j = addOne_Value_Value(i);
    std::cout << "[addOne_Value_Value]     Value of i=" << i
              << " j=" << j << std::endl;
    
    // Call addOne function passing variable i by reference
    j = addOne_Reference_Value(i);
    std::cout << "[addOne_Reference_Value] Value of i=" << i
              << " j=" << j << std::endl;
    
    // Call addOne function passing variable i by value
    addOne_Value(i);
    std::cout << "[addOne_Value]           Value of i=" << i << std::endl;

    // Call addOne function passing variable i by reference
    addOne_Reference(i);
    std::cout << "[addOne_Reference]       Value of i=" << i << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
