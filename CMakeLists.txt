cmake_minimum_required(VERSION 3.22)
project("Pract02")
add_executable(${PROJECT_NAME} Pract02.cpp)
add_library(myLib SHARED Pract02.cpp)
