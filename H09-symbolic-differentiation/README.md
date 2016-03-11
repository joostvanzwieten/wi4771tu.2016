Homework 9: Symbolic differentiation
====================================

In this homework assignment you are going to create a set of function traits
that support symbolic (exact) differentiation.  The outline of the function
trait is as follows:

    struct Function
    {
        static const double eval(double x) { ... };
        typedef ... derivative;
    };

The function trait has a static method `eval` that takes one `double` argument
and returns the value represented by this function.  The `derivative` type is
another function trait the represents the derivative of this function.

This function trait can be used as follows:

    Function::eval(1.25); // evaluate `Function` at `1.25`
    Function::derivative::eval(1.25); // evalute the derivative of `Function`
                                      // at `1.25`

1.  Create a function trait `template<int value> ConstInt` with an `eval`
    method that returns the integer constant `value` and with an appropriate
    `derivative` function trait.

    Example usage:

        typedef ConstInt<4> a; // represents the function a(x) = 4

2.  Create `Add` and `Mul` function trait templates that take two function
    traits as template parameters.

    Example usage:  Given two function traits `f` and `g`, the sum of `f` and
    `g` is given by

        typedef Add< f, g > h; // represents the function h(x) = f(x) + g(x)

    In some cases the compiler cannot determine whether a member of a template
    argument is a type or a variable or function.  You can explicitly instruct
    the compiler that a member is a type by prefixing `typename` to the member.
    To illustrate this, consider the following example with template parameter
    `F` --- we assume this parameter is a function trait, but the compiler does
    not know this --- and function trait templates `G` and `H`:

        template<typename F>
        struct G
        {
            ...
            typedef H< typename F::derivative > derivative;
        };

3.  Create a function trait `template<int exponent> Monomial`.  The `eval`
    method should return the `exponent`-th power of its argument.  You may
    assume that the exponent is a non-negative number.  The derivative should
    be valid for *all* non-negative exponents!

4.  Create a `Neg` function trait template that takes one function trait as a
    template argument.  The `eval` method should return the additive inverse of
    the evaluated function template argument.

    Example usage:  Given a function trait `f`, the additive inverse of `f` is
    given by

        typedef Neg< f > g; // represents the function g(x) = -f(x)

5.  Create function traits `Sin` and `Cos` that represent the sine and cosine
    functions, respectively.

6.  Create a function `main` that tests all function traits and their
    derivatives.
