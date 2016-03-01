# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 12-auto-decltype
project (12-auto-decltype)

# Create an executable named 'auto-decltype' from the source file 'auto-decltype.cxx'
add_executable(auto-decltype src/auto-decltype.cxx)
target_compile_features(auto-decltype PRIVATE cxx_auto_type)

# C++11: Automatic function return type
target_compile_features(auto-decltype PRIVATE cxx_trailing_return_types)

# C++14: Deduced return types
target_compile_features(auto-decltype PRIVATE cxx_return_type_deduction)
