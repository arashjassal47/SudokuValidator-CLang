cmake_minimum_required(VERSION 3.17)
project(SudokuValidator C)

set(CMAKE_C_STANDARD 99)

add_executable(SudokuValidator main.c logic.c logic.h)