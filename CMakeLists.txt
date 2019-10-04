cmake_minimum_required(VERSION 3.12)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)
set(CMAKE_C_COMPILER /usr/bin/gcc-8)

add_executable(Game src/HiddenWord.cpp
        src/Interface.cpp src/Dictionary.cpp src/main.cpp)

enable_testing()

add_subdirectory(tests)