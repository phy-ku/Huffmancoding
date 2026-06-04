cmake_minimum_required(VERSION 4.2.2)
project(huffcoding)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(huffcoding
    tree0.cpp
    tree1.cpp
    usetrees.cpp
)