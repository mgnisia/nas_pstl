project(NAS_STL)

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# SET CXX Standard
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

# Definition of variables
set(COMPILE_FLAGS -O3 -tbb -mcmodel=large)

# Common Library
add_subdirectory(common)

# Kernels
set(kernels
    CG
    # EP
    # FT
    # IS
    # MG
)

foreach(kernel IN LISTS kernels)
message("Adding ${kernel} Kernel")
    add_subdirectory(${kernel})
endforeach()

