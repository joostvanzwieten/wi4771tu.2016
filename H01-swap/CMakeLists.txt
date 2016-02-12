# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: H01-swap
project (H01-swap)

# Create an executable named 'swap' from the source file 'swap.cxx'
add_executable(swap src/swap.cxx)