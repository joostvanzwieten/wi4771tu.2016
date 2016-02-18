# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H04-points-triangles
project (H04-points-triangles)

# Create an executable named 'points-triangles' from the source file 'points-triangles.cxx'
add_executable(points-triangles src/points-triangles.cxx)

target_compile_features(points-triangles PRIVATE cxx_auto_type cxx_delegating_constructors)
