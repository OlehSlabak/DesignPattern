cmake_minimum_required(VERSION 3.20)
project(Pimpl_Idiom)

set(CMAKE_CXX_STANDARD 23)

add_executable(Pimpl_Idiom main.cpp Person.cpp Person.hpp pimpl.hpp pimpl.cpp foo.cpp foo.hpp)
