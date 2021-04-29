cmake_minimum_required(VERSION 3.19)
project(Unscrambler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Unscrambler
        Main.cpp
        Main.h)
