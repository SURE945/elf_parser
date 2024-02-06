cmake_minimum_required(VERSION 3.5)
project(image_parser)
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(include)

add_executable(image_parser main.cpp 
                        src/test.cpp 
                        src/help.cpp
                        src/elf_header.cpp)