Homework 4: Points & Triangles
==============================

In this homework assignment you are going to create a `Point` class, which
represents a point in a two-dimensional space, and a `Triangle` class, which is
represented by three `Point`s.  Both classes should support translation and
rotation and the `Triangle` class should be able to compute its area.

In the following description and code examples all possible occurrences of the
keyword `const` are omitted, as are all possible occurrences of reference
arguments, marked with an `&`.  It is your task to mark relevant functions,
arguments and return values as `const` and to pass relevant arguments by
reference.  Please comment briefly — in general, not per function — why you
decided to add `const` and `&` or not.  Write this as a comment in the source
file [src/points-triangles.cxx].

After each step, e.g. you have implemented a new operator in the `Point` class,
test your implementation by writing one or more tests in the function `main`.
This is part of the assignment.  Make sure that all relevant parts of your code
are tested.  You may use assertions, but remember that comparing floating
point numbers might be difficult due to rounding errors.  The `distance`
function of the `Point` class, see below, might come in handy.

This assignment requires the use of some mathematical functions.  By including
`cmath` the following functions and constants are available:

    double std::abs(double);     // absolute value
    double sqrt(double);         // square root
    double pow(double, double);  // power, arguments: base, exponent
    double sin(double);          // sine, argument in radians
    double cos(double);          // cosine, argument in radians
    const double M_PI;           // pi

Note that the function and constant definitions given above are simplified.

Start with creating the `Point` class in [src/points-triangles.cxx].  The
outline of the `Point` class is as follows:

    class Point
    {
    public:
        // constructors
        // operators
        // methods

        double x;
        double y;
    };

1.  Create a default constructor, i.e. a constructor without arguments, that
    initialises attributes `x` and `y` with zero.

2.  Create a constructor that takes two `double` arguments and initialises
    attributes `x` and `y` with the two arguments.

3.  Create binary operators `+` and `-` that operate on another `Point` and
    return new `Point`s with the sum or difference of the attributes `x` and
    `y`.  The code outline is as follows:

        class Point
        {
        public:
            ...

            Point operator+(Point other) { ... }
            Point operator-(Point other) { ... }

            ...
        };

5.  Create binary operators `+=` and `-=` with the same behaviour as the
    previous operators `+` and `-` defined above, with the difference that
    the operators `+=` and `-=` modify the attributes in-place.  The operators
    should return the current instance, i.e. `*this`.  The code outline is as
    follows:

        class Point
        {
        public:
            ...

            Point &operator+=(Point other) { ... }
            Point &operator-=(Point other) { ... }

            ...
        };

    With these operators defined we can now write `b += a` instead of `b = b +
    a` where `a` and `b` are instances of class `Point`.  Example:

        int main()
        {
            Point a = {1, 2};
            Point b = {3, 4};
            Point c = {3, 4};
            b += a;    // result: b.x = 4, b.y = 6
            c = c + a; // result: c.x = 4, c.y = 6
            return 0;
        }

6.  Create two `distance` functions that compute and return the Euclidean
    distance between this instance and the origin, if no arguments are given,
    or between this instance and another `Point`.  The code outline is as
    follows:

        class Point
        {
        public:
            ...

            double distance() { ... }
            double distance(Point other) { ... }

            ...
        };

7.  Create a `rotated` function that computes and returns a new `Point` rotated
    with `angle` radians in *anticlockwise direction* around the origin or
    around another `Point` if a second argument is passed.  The code outline is
    as follows:

        class Point
        {
        public:
            ...

            Point rotated(double angle) { ... }
            Point rotated(double angle, Point other) { ... }

            ...
        };

    Hint: The following pseudocode computes computes the anticlockwise rotation
    of a point `(old_x, old_y)` by `angle` radians:

        new_x = old_x*cos(angle) - old_y*sin(angle)
        new_y = old_x*sin(angle) + old_y*cos(angle)

8.  Create a `rotate` function that applies rotation *in-place* with `angle`
    radians around the origin or around another `Point` if a second argument is
    passed.  The difference between `rotated` and `rotate` is similar to
    operators `+` and `+=`.  The function `rotate` should return the current
    instance, i.e. `*this`.  The code outline is as follows:

        class Point
        {
        public:
            ...

            Point &rotate(double angle) { ... }
            Point &rotate(double angle, Point other) { ... }

            ...
        };

    Both functions should return a reference — note the `&` in the return
    type — to the current instance, i.e. `*this`.

This concludes the `Point` class.  Proceed with the `Triangle` class.  The
outline of the `Triangle` class is as follows:

    class Triangle
    {
    public:
        // constructors
        // operators
        // methods

        Point a, b, c;
    };

1.  Create a default constructor, i.e. a constructor without arguments, that
    initialises attributes `a`, `b` and `c` with their default value.

2.  Create a constructor that takes three `Point` arguments and initialises
    attributes `a`, `b` and `c` with the three arguments.  Use constructor
    delegation for the initialisation of the attributes.

3.  Create a function `translated` that takes one `Point` argument and returns
    a new `Triangle` with all attributes translated by the argument.  The
    outline of the function is as follows:

        class Triangle
        {
        public:
            ...

            Triangle translated(Point t) { ... }

            ...
        };

4.  Create the in-place version of `translated`, called `translate`.  The
    outline of the function is as follows:

        class Triangle
        {
        public:
            ...

            Triangle &translate(Point t) { ... }

            ...
        };

    Remember to return `*this`;

5.  Create a function `rotated` that returns a new `Triangle` with all
    attributes rotated by argument `angle`.  If a second argument of class
    `Point` is given, then this defines the point of rotation.  The functions
    have the following outline:

        class Triangle
        {
        public:
            ...

            Triangle rotated(double angle) { ... }
            Triangle rotated(double angle, Point other) { ... }

            ...
        };

6.  Create the in-place version of `rotated`, called `rotate`.  The outline of
    the function is as follows:

        class Triangle
        {
        public:
            ...

            Triangle &rotate(double angle) { ... }
            Triangle &rotate(double angle, Point other) { ... }

            ...
        };

    Remember to return `*this`.

    This allows you to chain in-place translation and rotation functions, e.g.

        int main()
        {
            Triangle t = {{0, 0}, {0, 1}, {1, 0}};
            t.translate({2, 3}).rotate(M_PI/2, {-1, -3}).translate({5, 6});
        }

7.  Create a function `area` that computes the area of the `Triangle`.

        class Triangle
        {
        public:
            ...

            double area() { ... }

            ...
        };

    Hint: The [shoelace formula] can be used to compute areas of polygons,
    including triangles.

[src/points-triangles.cxx]: src/points-triangles.cxx
[shoelace formula]: https://en.wikipedia.org/wiki/Shoelace_formula
