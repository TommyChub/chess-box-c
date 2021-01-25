cmake_minimum_required(VERSION 3.17)

project(chess_box_c)

set(CMAKE_C_STANDARD 99)

add_executable(chess_box_c Core/core.c Core/core.h init.c bitboards.c enums.h bitboards.h init.h board.c hashkeys.c board.h)