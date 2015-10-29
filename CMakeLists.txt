cmake_minimum_required(VERSION 2.8)
project(DEMO)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS "-std=c++0x -g")

#find_package(Boost 1.55.0 CONPONENTS)
include_directories(./)
add_subdirectory(pthread)

add_executable(c++11_atom_vs_mutex.out ./c++11_atom_vs_mutex.cpp)
add_executable(c++11_smart_pointer.out ./c++11_smart_pointer.cpp)
add_executable(sys_inet.out ./sys_inet.cpp)
add_executable(sys_dir.out ./sys_dir.cpp)
add_executable(OO_polymorphism.out ./OO_polymorphism.cpp)


if(UNIX)
	#target_link_libraries()
elseif(WIN32)
elseif(APPLE)
endif(UNIX)

message(STATUS "c++ flag : "${CMAKE_CXX_FLAGS}) 
message(STATUS "this is source dir "${PROJECT_SOURCE_DIR})
message(STATUS "this is binary dir "${PROJECT_BINARY_DIR})
