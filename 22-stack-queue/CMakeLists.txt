# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 22-stack-queue
project (22-stack-queue)

# Create an executable named 'stack-queue' from the source file 'stack-queue.cxx'
add_executable(stack-queue src/stack-queue.cxx)
target_compile_features(stack-queue PRIVATE cxx_auto_type)
