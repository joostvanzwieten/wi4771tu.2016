/**
 * \file integration.cxx
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

// Include header file to enable use of std::function
#include <functional>

// Abstract class Quadrature which cannot be instanciated 
class Quadrature
{
public:
    Quadrature()
    : n(0),
      weights(nullptr),
      points(nullptr)
    { }
    
    // Constructor
    Quadrature(int n)
    : n(n),
      weights(new double[n]),
      points(new double[n])
    { }
          
    // Destructor
    ~Quadrature()
    {
        delete[] weights;
        delete[] points;
        n = 0;
    }

    // Pure virtual factor (this function must be implemented in any
    // class derived from the abstract class Quadrature)
    inline virtual double factor(double a, double b) = 0;
    
    // Pure virtual mapping (this function must be implemented in any
    // class derived from the abstract class Quadrature)
    inline virtual double mapping(double xi, double a, double b) = 0;
    
    // Virtual integrator using function pointers (this function can
    // be overwritten by a re-implementation in the class derived from
    // the abstract class Quadrature; if the derived class does not
    // provide a re-implementation then the implementation from the
    // calss Quadrature is used instead)
    virtual double integrate(const double (*func)(const double x), double a, double b)
    {
        double integral(0);
        for (auto i=0; i<n; i++)
            integral += weights[i] * func(mapping(points[i],a,b));
        return factor(a,b) * integral;
    }

    // Virtual integrator: lambda expression
    virtual double integrate(std::function<double(double)> func, double a, double b)
    {
        double integral(0);
        for (auto i=0; i<n; i++)
            integral += weights[i] * func(mapping(points[i],a,b));
        return factor(a,b) * integral;
    }
    
protected:
    // Attributes
    double* weights;
    double* points;
    int n;
};

// Midpoint rule: overwrite the virtual integate functions since this
// method is so simple that it can be easily implemented without
// mapping the reference interval [-1,1] to the physical one [a,b]
class MidpointRule : public Quadrature
{
public:
    // Factor (not used!)
    inline virtual double factor(double a, double b) {return 1;}
    
    // Mapping (not used!)
    inline virtual double mapping(double xi, double a, double b) {return 0;}
    
    // Integrator: functor
    virtual double integrate(const double (*func)(const double x), double a, double b)
    {
        double m = 0.5*(a+b);
        return (b-a)*func(m);
    }

    // Integrator: lambda expression
    virtual double integrate(std::function<double(double)> func, double a, double b)
    {
        double m = 0.5*(a+b);
        return (b-a)*func(m);
    }   
};

// Simpson rule: overwrite the virtual integate functions since this
// method is so simple that it can be easily implemented without
// mapping the reference interval [-1,1] to the physical one [a,b]
class SimpsonRule : public Quadrature
{
public:
    // Factor (not used!)
    inline virtual double factor(double a, double b) {return 1;}
    
    // Mapping (not used!)
    inline virtual double mapping(double xi, double a, double b) {return 0;}
    
    // Integrator: functor
    double integrate(const double (*func)(const double x), double a, double b)
    {
        double m = 0.5*(a+b);
        return (b-a)/6.0*(func(a)+4.0*func(m)+func(b));
    }

    // Integrator: lambda expression
    double integrate(std::function<double(double)> func, double a, double b)
    {
        double m = 0.5*(a+b);
        return (b-a)/6.0*(func(a)+4.0*func(m)+func(b));
    }
};

// Rectangle rule: overwrite the virtual integate functions since this
// method is so simple that it can be easily implemented without
// mapping the reference interval [-1,1] to the physical one [a,b]
class RectangleRule : public Quadrature
{
public:
    // Constructor: we do not need the weights and points since the
    // rectangle rule is implemented explicitly in the integrate
    // functions. However, we do need the number of sub-rectangles.
    RectangleRule(int n)
    : Quadrature()
    { this->n = n;}
    
    // Factor (not used!)
    inline virtual double factor(double a, double b) {return 1;}
    
    // Mapping (not used!)
    inline virtual double mapping(double xi, double a, double b) {return 0;}
    
    // Integrator: functor
    double integrate(const double (*func)(const double x), double a, double b)
    {
        double integral(0);
        double h = (b-a)/(double)n;
        for (auto i=0; i<n; i++)
            integral += h*func(a+i*h);
        return integral;
    }

    // Integrator: lambda expression
    double integrate(std::function<double(double)> func, double a, double b)
    {
        double integral(0);
        double h = (b-a)/(double)n;
        for (auto i=0; i<n; i++)
            integral += h*func(a+i*h);
        return integral;
    }   
};

// Gauss rule
class GaussRule : public Quadrature
{
public:
    GaussRule(int n)
    : Quadrature(n)
    {
        switch(n)
        {
        case 1:
            weights[0] = { 2.0 };
            points[0]  = { 0.0 };
            break;
        case 2:
            weights[0] = { 1.0 };
            weights[1] = { 1.0 };
            points[0]  = { -0.57735026919 };
            points[1]  = {  0.57735026919 };
            break;
        case 3:
            weights[0] = { 5.0/9.0 };
            weights[1] = { 8.0/9.0 };
            weights[2] = { 5.0/9.0 };
            points[0]  = { -0.774596669241 };
            points[1]  = {  0.0 };
            points[2]  = {  0.774596669241 };
            break;
        default:
            std::cout << "Invalid parameter" << std::endl;
            exit(1);
        }
    }

    // Factor
    inline virtual double factor(double a, double b)
    {
        return (b-a)/2.0;
    }
    
    // Mapping from reference interval [-1,1] to [a,b]
    inline virtual double mapping(double xi, double a, double b)
    {
        return 0.5*(b-a)*xi+0.5*(a+b);
    }
};

// Define function to integrate
const double myfunc1(const double x) { return x; }

// Define function to integrate as lambda expression
auto myfunc2 = [](double x) { return x; };

// The global main function that is the designated start of the program
int main(){

    MidpointRule MPR;
    std::cout << "Midpoint rule:   " << MPR.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "Midpoint rule:   " << MPR.integrate(myfunc2, 0, 1) << std::endl;

    SimpsonRule SR;
    std::cout << "Simpson rule:    " << SR.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "Simpson rule:    " << SR.integrate(myfunc2, 0, 1) << std::endl;

    RectangleRule RR(4);
    std::cout << "Rectangle rule:  " << RR.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "Rectangle rule:  " << RR.integrate(myfunc2, 0, 1) << std::endl;
    
    GaussRule GR1(1);
    std::cout << "1-pt Gauss rule: " << GR1.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "1-pt Gauss rule: " << GR1.integrate(myfunc2, 0, 1) << std::endl;

    GaussRule GR2(2);
    std::cout << "2-pt Gauss rule: " << GR2.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "2-pt Gauss rule: " << GR2.integrate(myfunc2, 0, 1) << std::endl;

    GaussRule GR3(3);
    std::cout << "3-pt Gauss rule: " << GR3.integrate(myfunc1, 0, 1) << std::endl;
    std::cout << "3-pt Gauss rule: " << GR3.integrate(myfunc2, 0, 1) << std::endl;
    
    // Return code 0 to the operating system (=no error)
    return 0;
}
