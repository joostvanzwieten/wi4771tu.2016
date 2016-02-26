# Include this file either in your ~/.bashrc or source it in every session
# 
# source ~/wi4771tu.2016.git/tudelft.bashrc
#

# Add CMake and GCC to search path
export PATH=/opt/apps/Compilers/cmake-3.4.0/bin:$PATH
export PATH=/opt/apps/Compilers/gcc-5.1.0/bin:$PATH
export C_INCLUDE_PATH=/opt/apps/Compilers/gcc-5.1.0/include
export LD_LIBRARY_PATH=/opt/apps/Compilers/gcc-5.1.0/lib64
export LD_RUN_PATH=/opt/apps/Compilers/gcc-5.1.0/lib64

# Make sure that CMake finds GCC 5.1.0 instead of the system-wide version
export CC=gcc
export CXX=g++
