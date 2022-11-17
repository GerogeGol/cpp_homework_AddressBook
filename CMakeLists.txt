cmake_minimum_required(VERSION 3.0.0)
project(HomeWork)

add_library(Lib lib.cpp)

add_executable(main main.cpp)

target_link_libraries(main Lib)
