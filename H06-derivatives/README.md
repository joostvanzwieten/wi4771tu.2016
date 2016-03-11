Homework 6: Derivatives
=======================

In this homework assignment you are going to write classes that are able to
compute approximate derivatives of functions of one variable using [finite
difference] schemes.

In this assignment you have to create the source and cmake files yourself.
Include at least header file `functional` in your source file.

1.  Create a 'base' class `Derivative` with the following pure virtual method

        virtual double differentiate(
            std::function<double(double)> func, double x) = 0;

    and an attribute `h` of type `double`.  This attribute should be in the
    `public` section or the `protected` section, **not** the `private` section.
    Add a constructor that allows one to specify `h` during initialisation.
    Use `1e-8` as a default value.

2.  For a given spacing `h` the following pseudocode computes an approximation
    to the derivative of `func` at `x` using the central difference scheme (see
    also [finite difference]):

        (func(x+h) - func(x-h)) / (2*h)

    Create a class `CentralDifference`, deriving from `Derivative`, that
    implements a `differentiate` function based on the central difference
    scheme.  You can inherit the constructors from the base class by adding
    `using Derivative::Derivative;` to the derived class, e.g.

        class CentralDifference: public Derivative
        {
        public:
            using Derivative::Derivative;

            ...
        };

3.  For a given spacing `h` the following pseudocode computes an approximation
    to the derivative of `func` at `x` using the forward difference scheme
    ([see also finite difference]):

        (func(x+h) - func(x)) / h

    Create a class `ForwardDifference`, deriving from `Derivative`, that
    implements a `differentiate` function based on the forward difference
    scheme.  Inherit the constructors from the base class by adding `using
    Derivative::Derivative;` to the derived class.

4.  Write a function `main()` that tests your implementation of the central and
    forward difference schemes for (at least) two different functions
    whose derivative you know.  Implement the first as a classical function,
    i.e. of the form

        double test1(double x)
        {
            return ...;
        }

    and the second as a lambda function.  Test both functions using both finite
    difference schemes.

[finite difference]: https://en.wikipedia.org/wiki/Finite_difference
