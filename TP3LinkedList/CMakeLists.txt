cmake_minimum_required(VERSION 3.14)
project(TP3LinkedList VERSION 1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_executable(TP3LinkedList
    src/main.c
    src/list.c
    src/list-test.c
)

target_include_directories(TP3LinkedList PRIVATE
    ${CMAKE_SOURCE_DIR}/header
)

target_compile_options(TP3LinkedList PRIVATE
    -Wall
    -Wextra
    -fdiagnostics-color=always
    -g
)