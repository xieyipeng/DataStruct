cmake_minimum_required(VERSION 3.14)
project(PostGraduate C)

set(CMAKE_C_STANDARD 99)

add_executable(PostGraduate main.c LinearList/SequenceList.cpp)