cmake_minimum_required(VERSION 3.16)
project(int2048_2022_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(int2048-2022-main)

add_executable(int2048_2022_main
        "int2048-2022-main/data/Integer 1/1.cpp"
        int2048-2022-main/int2048.h int2048-2022-main/int2048.cpp)
