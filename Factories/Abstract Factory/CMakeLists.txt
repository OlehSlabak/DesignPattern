cmake_minimum_required(VERSION 3.20)
project(Abstract_Factory)

set(CMAKE_CXX_STANDARD 23)

add_executable(Abstract_Factory main.cpp hotDrink.hpp hotDrinkFactory.hpp DrinkFactory.hpp)
