# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H01-swap
project (H01-swap)

# Create an executable named 'swap' from the source file 'swap.cxx'
add_executable(swap src/swap.cxx)
