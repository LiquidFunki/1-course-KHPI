cmake_minimum_required(VERSION 3.17)
project(lab20 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
add_executable(lab20_main src/main.c src/list.c src/data.c)
add_executable(lab20_test test/test.c src/list.c src/data.c)