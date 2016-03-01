# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 11-polymorphism
project (11-polymorphism)

# Create an executable named 'polymorphism' from the source file 'polymorphism.cxx'
add_executable(polymorphism src/polymorphism.cxx)
target_compile_features(polymorphism PRIVATE cxx_auto_type)

