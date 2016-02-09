# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 01-hello
project (01-hello)

# Create an executable named 'hello' from the source file 'hello.cxx'
add_executable(hello src/hello.cxx)