cmake_minimum_required(VERSION 3.19)
project(password_manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(password_manager src/main.cpp src/Password.cpp src/Password.h src/utils.cpp src/utils.h)