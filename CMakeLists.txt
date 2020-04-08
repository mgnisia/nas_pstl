project(NAS_STL)

cmake_minimum_required(VERSION 3.0)

# SET CXX Standard
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

# Definition of variables
set(RAND randdp)
set(COMMON_DIR ${NAS_STL_SOURCE_DIR}/common)

set(COMPILE_FLAGS -O3 -tbb -mcmodel=large)

# Common Library
add_library(common ${COMMON_DIR}/wtime.cpp 
${COMMON_DIR}/c_${RAND}.cpp
${COMMON_DIR}/c_timers.cpp
${COMMON_DIR}/wtime.cpp
${COMMON_DIR}/c_print_results.cpp)



