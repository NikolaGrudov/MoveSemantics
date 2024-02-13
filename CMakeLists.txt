project("Student")

add_library(student STATIC Student.cpp Subject.cpp)
add_executable(${PROJECT_NAME} Pract02.cpp Student.cpp Subject.cpp)
target_include_directories(student PUBLIC ${PROJECT_SOURCE_DIR})
set_target_properties(student PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
