cmake_minimum_required(VERSION 3.23)
project(Checkers)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)
add_executable(Checkers main.cpp)

target_link_libraries(Checkers sfml-system sfml-window sfml-graphics)
