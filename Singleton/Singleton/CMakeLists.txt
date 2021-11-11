cmake_minimum_required(VERSION 3.20)
project(Singleton)

set(CMAKE_CXX_STANDARD 23)

set(Boost_INCLUDE_DIR c:/mingw/include/)
set(Boost_LIBRARY_DIR c:/mingw/lib/)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Singleton main.cpp)
