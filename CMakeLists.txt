cmake_minimum_required(VERSION 3.18)
project(stack C)

set(CMAKE_C_STANDARD 11)

add_executable(stack main.c stack.c stack.h)