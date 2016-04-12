Assignment: Heat equation
=========================

In this assignment you are going to create a numerical solver for the [heat
equation] in an arbitrary number of dimensions.

[heat equation]: https://en.wikipedia.org/wiki/Heat_equation

Introduction
------------

Notation of inline equations: `a^b` means `a` to the power `b` and `a_b` means
`a` sub `b`.

Consider the following initial boundary value problem:

    { ∂u
    { -- - α ∆u = 0             on Ω,
    { ∂t
    {
    { u(x,t) = 0                ∀ x ∈ ∂Ω,
    {
    {           n-1
    { u(x,0) = ∏    sin(πx ),   ∀ x ∈ Ω,
    {           k=0    (  k)

where `n` is the number of dimensions of the domain, `Ω = [0,1]^n` is the domain
(the unit square in 2D or the unit cube in 3D), `∂Ω` is the boundary of the
domain, `u` is the temperature as a function of space `x ∈ ℝ^n` and time `t` and
`∆` is the [Laplace operator], in an `n`-dimensional space given by

               2
          n-1 ∂
    ∆ := ∑    --- .
          k=0   2
              ∂x
                k

The exact solution to above initial boundary value problem is given by

                 2                       2
              -nπ αt  n-1             -nπ αt
    u(x,t) = e       ∏    sin(πx ) = e       u(x,0)
                      k=0    (  k)

We are going to apply a finite difference discretisation.  We create a mesh of
`m^n` equidistant interior nodes, `m` nodes per dimension, hence the distance
between two nodes is `∆x = 1/(m+1)`.  All nodes are labeled from `0` to `m^n`
(excluding) such that node `j+1` is the neighbour of node `j` in dimension `0`,
node `j+m` is the neighbour of node `j` in dimension `1`, and in general, node
`j+m^k` is the neighbour of node `j` in dimension `k`.  The following
illustrates a two-dimensional mesh with `m=3`:

    x
     1
    ↑

    1    ┏━━━━┯━━━━┯━━━━┯━━━━┓
         ┃    │    │    │    ┃
         ┃    │    │    │    ┃
    0.75 ┠────6────7────8────┨
         ┃    │    │    │    ┃
         ┃    │    │    │    ┃
    0.5  ┠────3────4────5────┨
         ┃    │    │    │    ┃
         ┃    │    │    │    ┃
    0.25 ┠────0────1────2────┨
         ┃    │    │    │    ┃
         ┃    │    │    │    ┃
    0    ┗━━━━┷━━━━┷━━━━┷━━━━┛
         0   0.25 0.5  0.75  1  → x
                                   0

Approximating the [Laplace operator] with a second order central [finite
difference] discretisation and the remaining semi-discrete differential equation
with the [Backward Euler method] gives the following system of equations

    M w    = w
       l+1    l

where vector `w_l ∈ ℝ^{m^n}` is the discrete approximation of the heat `u` at
`t=l ∆t`, with vector component `i` refering to node `i`.  The matrix `M` is
given by

                  ∆t   n-1                           n
    M   = I   - α --- ∑    D      ∀ i, j ∈ {0,1,...,m },
     ij    ij       2  k=0  kij
                  ∆x

where `I` is the identity matrix and `D_k` is the discrete approximation of the
second order derivative in dimension `k ∈ {0,1,...,n-1}`:

           { -2   if j = i
           {
    D    = {  1   if j is a left neighbour of i in dimension k
     kij   {
           {  1   if j is a right neighbour of i in dimension k

**Note:** Not all nodes have left or right neighbours in every dimension.  In
the example mesh given above node `0` has only right neighbours: node `1` in
dimension `0` and node `3` in dimension `1`.  Node `5` has two left
neighbours (node `4` in dimension `0` and node `2` in dimension `1`), but only
one right neighbour: node `8` in dimension `1`.

Given a diffusion coefficient `α`, a time step size `∆t` and a number of points
`m` the following prodedure can be used to obtain the numerical solution at time
`t`, which should be a multiple of `∆t`:

1.  Create the initial solution vector `w_0` by sampling the initial condition
    `u(x,0)` at the interior nodes:

        w   = w(x ,0).
         0i      i

2.  For `l = 0, 1, ..., (t/∆t)-1`: solve the following linear problem for
    `w_{l+1}`:

        M w    = w .
           l+1    l

[Laplace operator]: https://en.wikipedia.org/wiki/Laplace_operator
[finite difference]: https://en.wikipedia.org/wiki/Finite_difference
[Backward Euler method]: https://en.wikipedia.org/wiki/Backward_Euler_method

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

**Hint:** You might want to use the `map` class template from the C++ standard
library, which provides an elegant way to handle arbitrary data (e.g., the
matrix entries) with a unique key value (e.g., the row/column position), and
use `array<int, 2>` as the map key type.

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

Create a `class Heat1D` solver that represents the 1D initial boundary value
problem given above and has the following functionality:

*   The constructor should take three arguments: the diffusion coefficient
    `alpha`, the number of points per dimension `m` and the timestep `dt`.  The
    constructor should create the iteration matrix `M` given in the introduction
    and store the result as an attribute with type `Matrix<double>`.

*   The class has a method `Vector<double> exact(double t) const` that returns
    the exact solution at time `t` evaluated at all interior grid points.

*   The class has a method `Vector<double> solve(double t_end) const` that
    solves the initial boundary value problem given in the introduction using
    the procedure given at the end of the introduction until `t_end` and returns
    the numerical solution at the last time step.

Test your implementation by creating a solver with diffusion coefficient
`alpha=0.3125`, time step `dt=0.001` and `m=99`, solve the problem until `t=1`
and compare the numerical solution with the exact solution.  To verify the
matrix `M`, set `alpha=0.3125`, `dt=0.1`, `m=3` and compare with

    [ 2.0 -0.5     ]
    [-0.5  2.0 -0.5]
    [     -0.5  2.0]

All zero entries have been left out.

Create a `class Heat2D` solver that represents the 2D initial boundary value
problem given above with the same functionality as `Heat1D`.  Test your
implementation by creating a solver with diffusion coefficient `alpha=0.3125`,
time step `dt=0.001` and `m=99`, solve the problem until `t=0.5` and compare
the numerical solution with the exact solution.  To verify the matrix `M`, set
`alpha=0.3125`, `dt=0.1`, `m=3` and compare with

    [ 3.0 -0.5      -0.5                         ]
    [-0.5  3.0 -0.5      -0.5                    ]
    [     -0.5  3.0           -0.5               ]
    [-0.5            3.0 -0.5      -0.5          ]
    [     -0.5      -0.5  3.0 -0.5      -0.5     ]
    [          -0.5      -0.5  3.0           -0.5]
    [               -0.5            3.0 -0.5     ]
    [                    -0.5      -0.5  3.0 -0.5]
    [                         -0.5      -0.5  3.0]

If there is enough time create a `template<int n> class Heat` with the same
functionality as the `Heat1D` and `Heat2D` classes.  The template parameter `n`
specifies the number of dimensions of the problem.  Test your implementation for
one, two and three dimensions.
