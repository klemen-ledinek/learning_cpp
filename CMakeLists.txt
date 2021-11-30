cmake_minimum_required(VERSION 3.0.0)
project(cpp_learning VERSION 0.1.0)

set(SOURCES
    src/main.cpp
    src/add.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
