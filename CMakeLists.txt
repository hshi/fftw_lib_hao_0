cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(fftwhao)

#For find module path
set(CMAKE_MODULE_PATH "${MODULE_EXTRA_PATH}" ${CMAKE_MODULE_PATH})

#For definitions
add_definitions(${COMPILER_EXTRA_DEF})

find_package(fftw REQUIRED)
include_directories(${fftw_include_dirs})

include_directories(inc)

add_subdirectory(inc)

add_subdirectory(src)

add_subdirectory(test)
