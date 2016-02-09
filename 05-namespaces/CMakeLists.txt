# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 05-namespaces
project (05-namespaces)

# Create an executable named 'namespaces' from the source file 'namespaces.cxx'
add_executable(namespaces src/namespaces.cxx)
