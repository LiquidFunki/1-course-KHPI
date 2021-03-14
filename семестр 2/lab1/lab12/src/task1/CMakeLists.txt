cmake_minimum_required(VERSION 3.17)
project(task1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(task1
        lib.c
        lib.h
        main.c)
