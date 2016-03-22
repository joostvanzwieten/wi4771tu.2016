# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 21-algorithm
project (21-algorithm)

# Create an executable named 'algorithm' from the source file 'algorithm.cxx'
add_executable(algorithm src/algorithm.cxx)
target_compile_features(algorithm PRIVATE cxx_auto_type)
