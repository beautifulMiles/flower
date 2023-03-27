cmake_minimum_required(VERSION 3.22.1)

set(This FlowerDriver)

project(${This} C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    FlowerDriver.h
)
set (Sources
    FlowerDriver.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)