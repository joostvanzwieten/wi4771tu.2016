Homework 5: Copy & Move
=======================

In this homework assignment you are going to analyse under which circumstances
which constructors and operators are called, based on a simple `Container`
class wrapping a dynamically allocated array.

In this assignment you have to create the source and cmake files yourself.

Container class
---------------

Start with creating the `Container` class.  The outline is as follows:

    #include <iostream>

    class Container
    {
    public:
        // constructors
        // destructor
        // operators

        void print(const std::string &info) const
        {
            // print the address of this instance, the attributes `length` and
            // `data` and the `info` string
            std::cout << "  " << this << " " << length << " " << data << "  "
                << info << std::endl;
        }

    private:
        int length;
        double *data;
    };

Add the following constructors, destructor and operators to the `Container`
class:

1.  Create a default constructor, i.e. one that takes no arguments, that
    initialises the attribute `length` with `0` and attribute `data` with
    `nullptr`.

2.  Create a constructor that takes one `int` argument that holds the length of
    this container.  Attribute `data` should be initialised with a dynamically
    allocated array of `double`s of length `length`.

3.  Create a constructor that takes an `std::initializer_list<double>`.  The
    list contains values for the `data` array.  Use constructor delegation to
    set the `length` of this container and allocate `data`.  Then copy all
    elements of the list to `data`.

4.  Create a copy constructor that takes a `Container` argument.

5.  Create a move constructor that takes a `Container` argument.

6.  Create a destructor that `delete[]`s the `data` attribute.  Note that it is
    safe to `delete[]` an array if the address (to the first element of the
    array) is `nullptr`.

7.  Create a copy assignment operator.

8.  Create a move assignment operator.

9.  Create an `operator+` that takes one `Container` argument.  This operator
    should return a new `Container` with the pointwise sum of all elements of
    this instance (the left hand side) and the argument (the right hand side).

At the end of each function (constructor, destructor, operator) body, but
before a `return` statement if present, add a statement `print("description of
the function");`, where the string argument of `print` should describe the
function uniquely.  An example:

    class Container
    {
    public:
        Container() { print("default constructor"); }

        ...
    private:
        int length;
        double *data;
    };

Note that the constructor in the example above is incomplete!

Analysis
--------

Use the following function `main` to analyse the behaviour of your `Container`
class.

    int main()
    {
        std::cout << "Container a({ 1, 2, 3 });" << std::endl;
        Container a({ 1, 2, 3 });
        std::cout << "  a has address " << &a << std::endl;
        std::cout << "Container b = { 4, 5, 6 };" << std::endl;
        Container b = { 4, 5, 6 };
        std::cout << "  b has address " << &b << std::endl;
        std::cout << "Container c(a);" << std::endl;
        Container c(a);
        std::cout << "  c has address " << &c << std::endl;
        std::cout << "Container d = a + b;" << std::endl;
        Container d = a + b;
        std::cout << "  d has address " << &d << std::endl;
        std::cout << "Container e;" << std::endl;
        Container e;
        std::cout << "  e has address " << &e << std::endl;
        std::cout << "e = a + b;" << std::endl;
        e = a + b;
        std::cout << "Container f(std::move(a + b));" << std::endl;
        Container f(std::move(a + b));
        std::cout << "  f has address " << &f << std::endl;
        std::cout << "Container g = a + b + c;" << std::endl;
        Container g = a + b + c;
        std::cout << "  g has address " << &g << std::endl;
        std::cout << "Container h;" << std::endl;
        Container h;
        std::cout << "  h has address " << &h << std::endl;
        std::cout << "h = a + b + c;" << std::endl;
        h = a + b + c;
        std::cout << "Container i = { a + b + c };" << std::endl;
        Container i = { a + b + c };
        std::cout << "  i has address " << &i << std::endl;
        std::cout << "end" << std::endl;

        return 0;
    }

Explain after each statement, excluding the statements starting with
`std::cout`, what happens.  An example:

    e = a + b;
    // `a + b`: call `operator+`, which creates a new instance using the
    //     constructor `Container(length)`
    // `e = (a + b)`: call the copy assignment operator

Confirm your analysis by running the application and update your analysis if
necessary.
