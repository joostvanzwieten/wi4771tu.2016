# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 09-copy-move
project (09-copy-move)

# Create an executable named 'copy-move' from the source file 'copy-move.cxx'
add_executable(copy-move src/copy-move.cxx)
target_compile_features(copy-move PRIVATE cxx_auto_type)
target_compile_features(copy-move PRIVATE cxx_uniform_initialization)
