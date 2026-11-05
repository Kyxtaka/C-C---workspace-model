cmake_minimum_required(VERSION 3.16)
project(ChainedArray VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_executable(ChainedArray
    src/main.c
    src/SimpleLinkedArray.c
)

target_include_directories(ChainedArray PRIVATE
    ${CMAKE_SOURCE_DIR}/header
)

target_compile_options(ChainedArray PRIVATE
    -fdiagnostics-color=always
    -Wall
    -Wextra
    -g
)