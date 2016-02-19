# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 08-dot-product-struct2
project (08-dot-product-struct2)

# Create an executable named 'dot-product-struct2' from the source file 'dot-product-struct2.cxx'
add_executable(dot-product-struct2 src/dot-product-struct2.cxx)
target_compile_features(dot-product-struct2 PRIVATE cxx_auto_type)
target_compile_features(dot-product-struct2 PRIVATE cxx_uniform_initialization)
