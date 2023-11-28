project("student_test")

find_package(Boost COMPONENTS unit_test_framework)

add_executable(${PROJECT_NAME} foundGradesTest.cpp)
target_link_libraries(${PROJECT_NAME} Boost::unit_test_framework ${CMAKE_CURRENT_SOURCE_DIR}/../include/libstudent.a)

target_include_directories(${PROJECT_NAME} PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR} ..)
