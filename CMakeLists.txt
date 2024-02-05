cmake_minimum_required(VERSION 3.5)
project(elf_parser)
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(include)

add_executable(elf_parser main.cpp src/test.cpp)