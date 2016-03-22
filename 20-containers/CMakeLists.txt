# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 20-containers
project (20-containers)

# Create an executable named 'containers' from the source file 'containers.cxx'
add_executable(containers src/containers.cxx)
target_compile_features(containers PRIVATE cxx_auto_type)
