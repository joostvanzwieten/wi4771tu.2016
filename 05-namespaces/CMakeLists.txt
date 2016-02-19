# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 05-namespaces
project (05-namespaces)

# Create an executable named 'namespaces' from the source file 'namespaces.cxx'
add_executable(namespaces src/namespaces.cxx)
