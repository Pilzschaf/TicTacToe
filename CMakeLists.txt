cmake_minimum_required(VERSION 2.6)
project(tutorial)

add_executable(tutorial main.cpp)

install(TARGETS tutorial RUNTIME DESTINATION bin)
