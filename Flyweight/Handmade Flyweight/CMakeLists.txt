cmake_minimum_required(VERSION 3.20)
project(Handmade_Flyweight)

set(CMAKE_CXX_STANDARD 20)
set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)

include_directories(${Boost_INCLUDE_DIR})

add_executable(Handmade_Flyweight main.cpp)
