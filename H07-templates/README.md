Homework 7: Templates
=====================

In this homework assignment you are going to work with function and class
templates.  What follows is a list of unrelated exercises in increasing
difficulty.  You have to create the source and cmake files yourself.  Please
put everything in a single source file and create a function `main` that tests
all the exercises.

1.  Create a function template `add_simple` that takes two arguments of the
    same type and returns the sum of the two arguments.  The single template
    argument defines the type of the function arguments and the return type.
    Test your implementation using at least two different types, e.g. two
    `int`s and two `double`s.

    You may, but don't have to, use the following code to test your
    implementation:

        #include <iostream>
        #include <typeinfo>
        #define PRINT_EXPRESSION(expr) std::cout << #expr << ": " << (expr) \
            << " (type: " << typeid(expr).name() << ")" << std::endl

        int main()
        {
            PRINT_EXPRESSION(add_simple(1, 2));
            PRINT_EXPRESSION(add_simple(1.5, 2.2));
            return 0;
        }

    The `PRINT_EXPRESSION` macro prints the expression as a string, the result
    of the expression and the type of the result.

2.  Create a function template `add` that takes two arguments of possibly
    different types and returns the sum of the two arguments.  The two template
    arguments define the types of the two function arguments.  Test your
    implementation using a mixture of at least two different types, e.g. `int`
    and `double`.

3.  Create a function template `is_int` that takes one argument, where the type
    of this argument is defined by the template argument, and returns a `bool`.
    The function `is_int` should return `true` if the argument is an `int` and
    `false` otherwise.  Use template specialisation.

4.  Create a class template `Number` with one public `const` attribute `value`
    of type `T`, which is the single template parameter.  Add a constructor
    that takes a value of type `T` and initialises the attribute with this
    value.  Add four template binary arithmetic operators `+`, `-`, `*` and `/`
    where the right hand side is a `Number` of a different type `U`.  The
    operators should return the result of the arithmetic operation applied to
    the `value` attributes of the left and right hand side as a `Number` with
    the type of the resulting value.  For example

        Number<int>(2) * Number<double>(1.2)

    should return a `Number<double>` with `value` equal to `2.4`.  To prevent
    possible issues with deducing the return type of these operators, place the
    definition of the operators *below* the definition of the `value`
    attribute.

5.  Create a [Fibonacci number] generator with templates but without functions
    in the following way.  Create a struct template `fibonacci` with one
    template parameter `int n`.  The struct should have a `static const int
    value` attribute holding the `n`-th [Fibonacci number].  The `value`
    attribute of the `m`-th `fibonacci` struct can be accessed — without
    creating an instance of the struct — by `fibonacci<m>::value`, where `m` is
    an integer that is known at compile time.

    **Hint:** use template specialisation to specify the first two Fibonacci
    numbers.

    **Hint:** The following example shows a struct with a static
    *attribute `value` without* templates:

        struct example
        {
            static const int value = 1;
        };

        #include <iostream>
        int main()
        {
            std::cout << example::value << std::endl;
            return 0;
        }

[Fibonacci number]: https://en.wikipedia.org/wiki/Fibonacci_number
