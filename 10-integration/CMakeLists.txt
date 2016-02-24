# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 10-integration
project (10-integration)

# Create an executable named 'integration' from the source file 'integration.cxx'
add_executable(integration src/integration.cxx)
target_compile_features(integration PRIVATE cxx_auto_type)

