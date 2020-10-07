cmake_minimum_required(VERSION 3.5)
project(MyHttpServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(MyHttpServer main.cpp)

add_subdirectory(lib/)