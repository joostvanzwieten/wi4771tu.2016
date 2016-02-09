# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 03-pointers
project (03-pointers)

# Create an executable named 'pointers' from the source file 'pointers.cxx'
add_executable(pointers src/pointers.cxx)
target_compile_features(pointers PRIVATE cxx_auto_type)
