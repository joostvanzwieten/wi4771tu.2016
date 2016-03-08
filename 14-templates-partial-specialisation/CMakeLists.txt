# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 14-templates-partial-specialisation
project (14-templates-partial-specialisation)

# Create an executable named 'templates-partial-specialisation' from the source file 'templates-partial-specialisation.cxx'
add_executable(templates-partial-specialisation src/templates-partial-specialisation.cxx)
target_compile_features(templates-partial-specialisation PRIVATE cxx_auto_type)

# C++11: Automatic function return type
target_compile_features(templates-partial-specialisation PRIVATE cxx_trailing_return_types)

# C++14: Deduced return types
target_compile_features(templates-partial-specialisation PRIVATE cxx_return_type_deduction)