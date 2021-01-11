cmake_minimum_required(VERSION 3.17)

project(chess_box_c)

set(CMAKE_C_STANDARD 99)

add_executable(chess_box_c chessboxcore.c chessboxcore.h)