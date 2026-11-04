
# Based on what I did in BUT 3 for OpenGL TDS --> Check Kyxtaka (my) github page

#set minimum version of cmake required
cmake_minimum_required(VERSION 3.16)

#set projet name and languages 
project(application VERSION 0.1 LANGUAGES C)

# set up C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
# set binaries executable dir path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# set executable and source file
add_executable(application
    src/main.c
    src/exo1.c
    src/nbmystere.c
)

# set header include directory path
target_include_directories(application PRIVATE
    ${CMAKE_SOURCE_DIR}/header
)


# set gcc compiler compiler options
target_compile_options(application PRIVATE
    -fdiagnostics-color=always
    -Wall
    -Wextra
    -g
)