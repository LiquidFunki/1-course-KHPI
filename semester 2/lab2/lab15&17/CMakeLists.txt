cmake_minimum_required(VERSION 3.17)
project(lab15_17 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
add_executable(lab15_17_main src/main.c src/lib.c)
add_executable(lab15_17_test test/test.c src/lib.c)