# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 06-dot-product
project (06-dot-product)

# Create an executable named 'dot-product' from the source file 'dot-product.cxx'
add_executable(dot-product src/dot-product.cxx)
target_compile_features(dot-product PRIVATE cxx_auto_type)
