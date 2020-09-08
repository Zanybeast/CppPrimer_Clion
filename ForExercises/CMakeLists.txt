cmake_minimum_required(VERSION 3.17)
project(ForExercises)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

add_executable(ForExercises main.cpp Sales_data.h Person.h Screen.h Window_mgr.h X.h Y.h DEBUG.h MyDate.h)