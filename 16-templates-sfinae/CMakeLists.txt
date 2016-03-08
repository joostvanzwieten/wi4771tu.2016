# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 15-templates-sfinae
project (15-templates-sfinae)

# Create an executable named 'templates-sfinae' from the source file 'templates-sfinae.cxx'
add_executable(templates-sfinae src/templates-sfinae.cxx)
target_compile_features(templates-sfinae PRIVATE cxx_auto_type)
target_compile_features(templates-sfinae PRIVATE cxx_default_function_template_args)
