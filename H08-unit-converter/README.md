Homework 8: Unit-converter
==========================

In this homework assignment you are going to work with traits to
realise a unit conversion system for length (km, m, cm) at compile
time. Please put everything in a single source file and create a
function `main` that tests all the exercises.

1.  Enumerations in C++ are an elegant way to group values

        enum class Unit { km, m, cm };

    It is possible to create instances thereof like

        Unit u = Unit::km;
        Unit v = Unit::m;

    Implement the above enumeration `Unit`.

2.  Implement a `Measure` trait with two template parameters one for
    the length `value` (stored as integer) and one for the `Unit` in
    which the length is given

        template<int v, Unit u>
        struct Measure
        {
            // your implementation
        };

    Take care that the `Measure` trait stores these information internally.

3.  Write a `Measure_add` trait that takes two `Measure` traits as
    template parameters, converts them to the common smaller unit and
    adds them together.

    The `Measure_add` trait should provide exactly the same internal
    structure as the `Measure` trait. That is, if `Measure` has two
    attributes `value` and `unit` then `Measure_add` should have the
    same attributes.

    **Hint:** You might want to implement additional traits, e.g., to
    check if two `Measure`s have the same `unit`, and therefore, no
    conversion is necessary and/or a trait that calculates the factor
    by which the `Measure` with the higher `unit` needs to be
    multiplied to convert it into the lower `unit`.

4.  Test your implementation for different measures, e.g.,

        int main()
        {
            std::cout << Measure_add< Measure<10,Unit::m>, Measure<20,Unit::m> >::value  << std::endl;
            std::cout << Measure_add< Measure<10,Unit::m>, Measure<20,Unit::cm> >::value << std::endl;

            return 0;
        }

**Note:** In this assignment you should not instantiate any objects of
the structs. The entire calculation (addition+conversion) should be
done at compile time. It can be helpful to consider the type traits
implemented in the Standard C++ Library to selectively enable/disable
specialised implementation.
