# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 04-passing-arguments
project (04-passing-arguments)

# Create an executable named 'passing-arguments' from the source file 'passing-arguments.cxx'
add_executable(passing-arguments src/passing-arguments.cxx)
target_compile_features(passing-arguments PRIVATE cxx_auto_type)
#target_compile_features(passing-arguments PRIVATE cxx_trailing_return_types)
