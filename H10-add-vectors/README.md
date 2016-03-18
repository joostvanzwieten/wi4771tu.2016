Homework 11: Add vectors
========================

In this homework assignment you are going to create two versions of a function
that adds a variable amount of `std::vectors`, all with the same length.  The
first version adds vectors in pairs using a for loop for each add, the second
adds elements in pairs using a single for loop.

The `CMakeLists.txt` and and outline of the source is present.

1.  Create function template `add_vectors_simple` that takes two or more
    `std::vector<V>` arguments, where `V` is template parameter of the
    function.  The function should add the arguments in the following way.
    First add the last two arguments and let the result be a new
    `std::vector<V>`.  Then add the second to last argument to this vector.
    Proceed with this recursion until all arguments have been added.  Return
    the result.

    The function can be used as follows:

        int n = 100;
        std::vector<double> a(n);
        std::vector<double> b(n);
        std::vector<double> c(n);
        std::vector<double> d = add_vectors_simple(a, b, c);

    You may assume that all vectors have the same length.

2.  Create a function template `add_elems(i, ...)` that adds all `i`-th
    elements of the vector arguments.  The first argument `i` is an index, the
    remaining arguments are `std::vector<V>`s, where `V` is a template
    parameter of `add_elems`.  The function can be used as follows:

        int n = ...;
        std::vector<double> a(n);
        std::vector<double> b(n);
        std::vector<double> c(n);
        int i = ...;
        add_elems(i, a, b, c); // same as a[i] + b[i] + c[i]

3.  Implement a function template `add_vectors_singleloop` that adds the
    `std::vector` arguments in a single loop.  Use the `add_elems` function
    defined above.  The behaviour should be the same as for
    `add_vectors_simple`.

3.  Compare the performance of `add_vectors_simple` and
    `add_vectors_singleloop`.  Run your program first with argument `simple`
    and then with `singleloop` and compare the difference in run time.  In
    linux you may use the shell command `time` to measure the time used by a
    program:

        time ./add-vectors single
        time ./add-vectors singleloop

    Explain the results.
