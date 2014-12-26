cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(fftwhao)

if(NOT DEFINED MPI_HAO)
else()
  add_definitions(-DMPI_HAO=${MPI_HAO})
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
   set(CMAKE_CXX_FLAGS " ")
   set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++11 ${CMAKE_CXX_FLAGS}")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
endif()


# For fftw library
find_library(fftw_lib NAMES libfftw3.a PATHS /opt/fftw/lib/)
string(REPLACE "lib/libfftw3.a" "include" fftw_include ${fftw_lib})
include_directories(${fftw_include})

include_directories(inc)

add_subdirectory(inc)

add_subdirectory(src)

add_subdirectory(test)

