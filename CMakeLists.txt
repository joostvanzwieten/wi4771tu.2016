# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

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
add_subdirectory(06-dot-product)
add_subdirectory(07-dot-product-struct)
add_subdirectory(08-dot-product-struct2)
add_subdirectory(09-copy-move)
add_subdirectory(10-integration)
add_subdirectory(11-polymorphism)
add_subdirectory(12-auto-decltype)

# Homework
add_subdirectory(H01-swap)
add_subdirectory(H02-arrays)
add_subdirectory(H04-points-triangles)

# Assignment
