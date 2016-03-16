Homework 9: Symbolic differentiation
====================================

In this homework assignment you are going to create a set of function types
that support symbolic (exact) differentiation.  The outline of the function
type is as follows:

    struct Function
    {
        static const double eval(double x) { ... };
        typedef ... derivative;
    };

The function type has a static method `eval` that takes one `double` argument
and returns the value represented by this function.  The `derivative` type is
another function type the represents the derivative of this function.

This function type can be used as follows:

    Function::eval(1.25); // evaluate `Function` at `1.25`
    Function::derivative::eval(1.25); // evalute the derivative of `Function`
                                      // at `1.25`

1.  Create a function type `template<int value> ConstInt` with an `eval` method
    that returns the integer constant `value` and with an appropriate
    `derivative` function type.

    Example usage:

        typedef ConstInt<4> a; // represents the function a(x) = 4

2.  Create `Add` and `Mul` function type templates that take two function types
    as template parameters.

    Example usage:  Given two function types `f` and `g`, the sum of `f` and
    `g` is given by

        typedef Add<f, g> h; // represents the function h(x) = f(x) + g(x)

    In some cases the compiler cannot determine whether a member of a template
    argument is a type or a variable or function.  You can explicitly instruct
    the compiler that a member is a type by prefixing `typename` to the member.
    To illustrate this, consider the following example with template parameter
    `F` — we assume this parameter is a function type, but the compiler does
    not know this — and function type templates `G` and `H`:

        template<typename F>
        struct G
        {
            ...
            typedef H<typename F::derivative> derivative;
        };

3.  Create a function type `template<int exponent> Monomial`.  The `eval`
    method should return the `exponent`-th power of its argument.  You may
    assume that the exponent is a non-negative number.  The derivative should
    be valid for *all* non-negative exponents!

4.  Create a `Neg` function type template that takes one function type as a
    template argument.  The `eval` method should return the additive inverse of
    the evaluated function template argument.

    Example usage:  Given a function type `f`, the additive inverse of `f` is
    given by

        typedef Neg<f> g; // represents the function g(x) = -f(x)

5.  Create function types `Sin` and `Cos` that represent the sine and cosine
    functions, respectively.

    A C++ compiler reads a file line by line from top to bottom.  You may use a
    class or function only if it has been declared earlier, i.e. above, perhaps
    in an `#include` directive.  If two classes refer to each other you need to
    'forward declare' the class that has not been declared yet.  In this
    particular case the following should be sufficient:

        class Cos; // forward declaration
        class Sin
        {
            ...
        };
        class Cos
        {
            ...
        };

6.  Create a function `main` that tests all function types and their
    derivatives.
