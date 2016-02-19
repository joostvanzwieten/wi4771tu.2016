# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 02-variables-constants
project (02-variables-constants)

# Create an executable named 'variables-constants' from the source file 'variables-constants.cxx'
add_executable(variables-constants src/variables-constants.cxx)
target_compile_features(variables-constants PRIVATE cxx_auto_type)
