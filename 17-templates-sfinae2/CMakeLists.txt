# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 17-templates-sfinae2
project (17-templates-sfinae2)

# Create an executable named 'templates-sfinae2' from the source file 'templates-sfinae2.cxx'
add_executable(templates-sfinae2 src/templates-sfinae2.cxx)
target_compile_features(templates-sfinae2 PRIVATE cxx_auto_type)
target_compile_features(templates-sfinae2 PRIVATE cxx_default_function_template_args)
