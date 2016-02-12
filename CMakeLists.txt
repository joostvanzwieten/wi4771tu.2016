# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: wi4771tu.2016
project (wi4771tu.2016)

# Output message
message("Build all build targets of the course wi4771tu from 2016")

# Examples
add_subdirectory(01-hello)
add_subdirectory(02-variables-constants)
add_subdirectory(03-pointers)
add_subdirectory(04-passing-arguments)
add_subdirectory(05-namespaces)

# Homework
add_subdirectory(H01-swap)
add_subdirectory(H02-arrays)

# Assignment
