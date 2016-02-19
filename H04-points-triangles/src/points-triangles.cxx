/*

    Comment on `const` and `&` here.  See ../README.md.

 */

// Support for precompiled header files (only under MS Visual Studio)
#ifdef _MSC_VER
#include "stdafx.h"
#endif

#include <cmath>
#include <ostream>
#include <iomanip>

class Point
{
public:
    // constructors
    // operators
    // methods

    double x;
    double y;
};

class Triangle
{
public:
    // constructors
    // operators
    // methods

    Point a, b, c;
};

// ostream operator for `Point`s
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    // remember current flags, precision
    auto flags = os.flags();
    auto current_precision = os.precision();
    // output numers with fixed point and three decimal precision
    os.setf(std::ios::fixed, std::ios::floatfield);
    os.precision(3);
    // output point `p`
    os << "(" << std::setw(6) << std::setfill(' ') << p.x
        << "," << std::setw(6) << std::setfill(' ') << p.y << ")";
    // restore current flags, precision
    os.flags(flags);
    os.precision(current_precision);
    return os;
}

// ostream operator for `Triangle`s
std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    return os << "Triangle< " << t.a << ", " << t.b << ", " << t.c <<  " >";
}


#include <iostream>
using namespace std;

int main()
{
    // example, replace with your tests

    Point p;
    Triangle t;

    // set point `p` to (1, 2)
    p.x = 1;
    p.y = 2;

    // set triangle `t` to (1, 2), (3, 4), (5, 6)
    t.a.x = 1;
    t.a.y = 2;
    t.b.x = 3;
    t.b.y = 4;
    t.c.x = 5;
    t.c.y = 6;

    // print point `p` and triangle `t`
    cout << p << endl;
    cout << t << endl;
}
