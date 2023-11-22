cmake_minimum_required(VERSION 3.22)
project("FoundGradesTest")

add_executable(${PROJECT_NAME} foundGradesTest.cpp)
target_link_libraries(${PROJECT_NAME} myLib)
