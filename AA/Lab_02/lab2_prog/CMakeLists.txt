cmake_minimum_required(VERSION 3.17)
project(lab2_prog)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(lab2_prog main.cpp Row.cpp Matrix.cpp counter.h counter.cpp)