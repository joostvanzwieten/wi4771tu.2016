# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 13-templates
project (13-templates)

# Create an executable named 'templates' from the source file 'templates.cxx'
add_executable(templates src/templates.cxx)
target_compile_features(templates PRIVATE cxx_auto_type)

# C++11: Automatic function return type
target_compile_features(templates PRIVATE cxx_trailing_return_types)

# C++14: Deduced return types
target_compile_features(templates PRIVATE cxx_return_type_deduction)