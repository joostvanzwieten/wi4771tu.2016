Assignment: Heat equation
=========================

In this assignment you are going to create a numerical solver for the [heat
equation] in an arbitrary number of dimensions.

[heat equation]: https://en.wikipedia.org/wiki/Heat_equation

Part 1: Vector class
--------------------

Create a `template<typename T> class Vector` class with the following
functionality:

*   The element type of the `Vector` class is specified via a template
    parameter `T`.

*   The `Vector` class can be constructed in the following ways:

    *   a default constructor that sets the length to zero,

    *   a constructor that takes a length as an argument,

    *   a constructor that takes another `Vector` as an argument and copies the
        elements of the argument to this `Vector` and

    *   a constructor that takes an initialiser list representing the contents
        of this `Vector`.

*   The `Vector` supports the copy and move assignment operators.  It is
    allowed to change the length of the `Vector` upon assignment, e.g. given
    two `Vector`s `a` and `b`,

        Vector<int> a(5);
        Vector<int> b = { 1, 2, 3, 4 };

    the following should be valid

        a = b;

*   The `Vector` class supports a pointwise sum and difference with another
    `Vector` via the binary operators `+` and `-`, respectively.  The element
    type of the resulting `Vector` is equal to the type of the pointwise
    operation.  If the `Vector`s have different lengths an exception should be
    thrown.

*   The `Vector` class supports left and right multiplication with a scalar.
    The element type of the resuling `Vector` is equal to the type of the
    pointwise multiplication.

Create a function `dot` that computes the [inner product] of two vectors.  The
function has the following signature:

    template<typename T>
    T dot(const Vector<T>& l, const Vector<T>& r)
    {
        ...
    }

[inner product]: https://en.wikipedia.org/wiki/Dot_product

Part 2: Matrix classes
----------------------

Implement a `template<typename T> Matrix` class template that represents a
sparse matrix.  The `Matrix` class has the following properties:

*   The shape of the `Matrix` can be passed via a constructor.

        Matrix<double> M(10, 20); // initialise M with 10 rows and 20 columns

    It is not allowed to change the shape afterwards.

*   Entries can be added in the following way:

        Matrix<double> M(10, 10)
        M[{0,0}] = 1.0; // set value at row 0, column 0 to 1.0
        M[{1,2}] = 2.0; // set value at row 1, column 2 to 2.0

*   The `Matrix` class has a `matvec` method that computes and returns the
    matrix-vector product with some vector.

Hint:  Hint: You might want to use the `map` class template from the C++
standard library, which provides an elegant way to handle arbitrary data (e.g.,
the matrix entries) with a unique key value (e.g., the row/column position),
and use `array<int, 2>` as the map key type.

Part 3: Conjugate Gradient method
---------------------------------

Create a function named `cg` that solves a linear system using the [Conjugate
Gradient method], given in pseudocode by

    p_0 = r_0 = b - A x_0
    for k = 0, 1, ..., maxiter-1
        alpha_k = dot(r_k, r_k) / dot(A p_k, p_k)
        x_(k+1) = x_k + alpha_k p
        r_(k+1) = r_k - alpha_k A p
        if dot(r_(k+1), r_(k+1)) < tol*tol
            stop
        beta_k = dot(r_(k+1), r_(k+1)) / dot(r_k, r_k)
        p_(k+1) = r_(k+1) + beta_k p_k

Here, `A` is a symmetric positive definite matrix, `x_k`, `r_k` and `p_k` are
vectors, `dot` is the standard l2-inner product, `tol` is an absolute tolerance
for the residual and `maxiter` is the maximum allowed number of iterations.

The `cg` function should have the following signature

    template<typename T>
    int cg(
        const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, I maxiter)
    {
        ...
    }

The third argument serves both as the initial guess (`x_0` in the pseudocode)
and as the result (`x_k+1` in the pseudocode, where `k` is the last iteration).
The function should return the number of iterations used to achieve the desired
tolerance if the Conjugate Gradient method converged within `maxiter`,
otherwise `-1`.

[Conjugate Gradient method]: https://en.wikipedia.org/wiki/Conjugate_gradient_method

Part 4: Finite difference discretisation of the heat equation
-------------------------------------------------------------

The [heat equation] is

    ∂u
    -- - α ∆u = 0 ,
    ∂t

where the heat `u` is a function of time `t` and space and `∆` is the Laplace
operator, in an `n`-dimensional space given by

               2
          n-1 ∂
    ∆ := ∑    --- .
          i=0   2
              ∂x
                i

First order finite difference discretisation:

                    Δt    n-1
    w      = w    + -- α ∑    (-2 w      + w         - w        )
     n+1,j    n,j   Δx    i=0 (    n+1,j    n+1,j+s     n+1,j+s )
                              (                    i           i)

[Backward Euler method]: https://en.wikipedia.org/wiki/Backward_Euler_method
