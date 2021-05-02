cmake_minimum_required(VERSION 3.19)
project(algcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(algcpp main.cpp Algorithm.h sorts/Sort.h sorts/InsertSort.h sorts/MergeSort.h)