cmake_minimum_required(VERSION 3.20)
project(homework_4_1)

add_executable(homework_4_1 main.cpp list.h list_node.h list.cpp)

add_subdirectory (D:/PROGI/Catch2 Catch2-build)

add_executable(homework_4_1_Test test-main.cpp list.h list_node.h list.cpp)

target_link_libraries(homework_4_1_Test PRIVATE Catch2::Catch2)