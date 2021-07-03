cmake_minimum_required(VERSION 3.17)
project(lab7_prog)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")

add_executable(lab7_prog main.cpp Dictionary.h Cell.h MyTimer.cpp)