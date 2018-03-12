cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)

project(Bowling)
add_executable(${PROJECT_NAME} "main.cpp" "bowling.cpp")
add_definitions(-Wall -Werror -Wpedantic -Wextra)