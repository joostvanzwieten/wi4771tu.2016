# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 19-templates-variadic
project (19-templates-variadic)

# Create an executable named 'templates-variadic' from the source file 'templates-variadic.cxx'
add_executable(templates-variadic src/templates-variadic.cxx)
target_compile_features(templates-variadic PRIVATE cxx_auto_type)
target_compile_features(templates-variadic PRIVATE cxx_variadic_templates)

# C++14: Deduced return types
target_compile_features(templates-variadic PRIVATE cxx_return_type_deduction)