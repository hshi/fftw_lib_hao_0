cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(fftwhao)

#For find module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "~/lib/Modules")

#For definitions
add_definitions(${COMPILER_EXTRA_DEF})

#For c++ flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#For library
set(lib_all "")

   #Find fftw libary
   find_package(fftw REQUIRED)
   include_directories(${fftw_include_dirs})
   set(lib_all ${fftw_libraries} ${lib_all})

include_directories(inc)

add_subdirectory(inc)

add_subdirectory(src)

add_subdirectory(test)
