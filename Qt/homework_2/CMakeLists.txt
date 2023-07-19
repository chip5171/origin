cmake_minimum_required(VERSION 3.14)

project(homework_2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(homework_2
  main.cpp
)
target_link_libraries(homework_2 Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS homework_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

find_package(Qt6 REQUIRED COMPONENTS Network)
target_link_libraries(homework_2 Qt${QT_VERSION_MAJOR}::Network)
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(homework_2 Qt${QT_VERSION_MAJOR}::Sql)
