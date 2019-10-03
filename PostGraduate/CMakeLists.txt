cmake_minimum_required(VERSION 3.14)
project(PostGraduate C)

set(CMAKE_C_STANDARD 99)

add_executable(PostGraduate main.c LinearList/SequenceList.c LinearList/SequenceList.h LinearList/LinkList.c LinearList/LinkList.h LinearList/DLinkList.c LinearList/DLinkList.h LinearList/Stack.c LinearList/Stack.h)