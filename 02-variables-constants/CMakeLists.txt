# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 02-variables-constants
project (02-variables-constants)

# Create an executable named 'variables-constants' from the source file 'variables-constants.cxx'
add_executable(variables-constants src/variables-constants.cxx)
target_compile_features(variables-constants PRIVATE cxx_auto_type)
target_compile_features(variables-constants PRIVATE cxx_aggregate_default_initializers)