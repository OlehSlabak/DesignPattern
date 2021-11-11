cmake_minimum_required(VERSION 3.20)
project(Builder_Facets)

set(CMAKE_CXX_STANDARD 23)

add_executable(Builder_Facets main.cpp Person.hpp Person.cpp PersonBuilder.cpp PersonBuilder.hpp PersonAddressBuilder.cpp PersonAddressBuilder.hpp PersonJobBuilder.cpp PersonJobBuilder.hpp)
