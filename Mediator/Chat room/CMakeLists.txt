cmake_minimum_required(VERSION 3.20)
project(Chat_room)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chat_room main.cpp Persone.cpp Persone.hpp ChatRoom.cpp ChatRoom.hpp)
