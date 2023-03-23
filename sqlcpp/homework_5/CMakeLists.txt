cmake_minimum_required(VERSION 3.20)

project(homework_5)
add_executable(homework_5 homework_5.cpp)

add_subdirectory(C:/LIB/libpqxx-7.7.4 libpqxx-build) # Укажите путь к libpq++

target_compile_features(homework_5 PRIVATE cxx_std_17) # Включите C++17

target_link_libraries(homework_5 PRIVATE pqxx) # Слинкуйте libpq++ к проекту