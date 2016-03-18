# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H10-add-vectors
project (H10-add-vectors)

# Create an executable named 'add-vectors' from the source file 'add-vectors.cxx'
add_executable(add-vectors src/add-vectors.cxx)
target_compile_features(add-vectors PRIVATE
    cxx_auto_type cxx_variadic_templates)
