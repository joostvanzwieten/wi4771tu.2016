# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 07-dot-product-struct
project (07-dot-product-struct)

# Create an executable named 'dot-product-struct' from the source file 'dot-product-struct.cxx'
add_executable(dot-product-struct src/dot-product-struct.cxx)
target_compile_features(dot-product-struct PRIVATE cxx_auto_type)
