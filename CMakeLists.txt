cmake_minimum_required(VERSION 3.17)
project(Euler_Sim)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} src/main.cpp src/physics.hpp src/physics.cpp)

target_link_libraries(${PROJECT_NAME} GL sfml-window sfml-graphics sfml-system)
