/**
 * \file copy-move.cxx
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

// Class encapsulating array and its lengths
class Container
{
public:
    // Constructor
    explicit Container(int length)
    : length(length),
      data(new double[length])
    {
        std::clog << "Constructor(int length) called" << std::endl;
    }
    
    // Unified initialization Constructor
    explicit Container(std::initializer_list<double> list)
    : Container((int)list.size())
    {
        std::uninitialized_copy(list.begin(), list.end(), data);
        std::clog << "Constructor(std::initializer_list<double> list) called" << std::endl;
    }
  
    // Copy Constructor
    //Container(const Container& c) = delete;
    explicit Container(const Container& c)
    : Container(c.length)
    {
        for (auto i=0; i<c.length; i++)
            data[i] = c.data[i];
        std::clog << "Copy constructor" << std::endl;
        }

    // Move Constructor
    //Container(Container&& c) = delete;
    Container(Container&& c)
    : length(c.length), data(c.data)
    {
        c.length = 0;
        c.data = nullptr;
        std::clog << "Move constructor" << std::endl;
    }
  
    // Destructor
    ~Container()
    {
        delete[] data;
        length = 0;
        std::clog << "Destructor called" << std::endl;
    }

    // Copy assignment
    Container& operator=(const Container& other)
    {
        if (this != &other)
            {
                delete[] data;
                length = other.length;
                data   = new double(other.length);
                for (auto i=0; i<other.length; i++)
                    data[i] = other.data[i];
            }
        std::clog << "Copy assignment operator" << std::endl;
        return *this;
    }

    // Move assignment
    Container& operator=(Container&& other)
    {
        if (this != &other)
            {
                delete[] data;
                length = other.length;
                data   = other.data;
                other.length = 0;
                other.data   = nullptr;
            }
        std::clog << "Move assignment operator" << std::endl;
        return *this;
    }

    // Print container content
    void print()
    {
        std::cout << "Container: ";
        for (auto i=0; i<length; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    
    // Print container info
    void info()
    {
        std::cout << "Length of data pointer:  " << length << std::endl;
        std::cout << "Address of data pointer: " << &data << std::endl;
        std::cout << "Data pointer:            " << data << std::endl;
    }
    
private:
    // Attributes
    double* data;
    int length;
};

// The global main function that is the designated start of the program
int main(){

    Container a ( {1, 2, 3, 4} );
    a.info();
    a.print();
     
    // Conversion constructor is no longer available due to the use of
    // explicit specifier in constructor
    //Container b = {1, 2, 3, 4};
    //b.info(); b.print();
    
    Container c ( 3 );
    c.info();
    c.print();

    // Conversion constructor is no longer available due to the use of
    // explicit specifier in constructor
    //Container d = 3;
    //d.info();
    //d.print();

    // User-defined copy constructor
    Container e(a);
    e.info();
    e.print();

    // User-defined move constructor
    Container f(std::move(a));
    f.info();
    f.print();

    // Container a should be empty now!
    a.info();
    a.print();

    // User-defined copy assignment operator
    Container g(0); g = e;
    g.info();
    g.print();

    // User-defined move assignment operator
    Container h(0); h = std::move(f);
    h.info();
    h.print();

    // Container f should be empty now!
    f.info();
    f.print();
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
