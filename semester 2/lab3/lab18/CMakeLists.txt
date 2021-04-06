cmake_minimum_required(VERSION 3.17)
project(lab18 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
add_executable(lab18_main src/main.c src/lib.c)
add_executable(lab18_test test/test.c src/lib.c)