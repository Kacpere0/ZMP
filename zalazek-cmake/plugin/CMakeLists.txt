cmake_minimum_required(VERSION 3.10)

set(PROJ_NAME "plugins_4_program")
project(${PROJ_NAME})

add_compile_options(-Wall -Wextra -pedantic -Wcast-qual -Wmaybe-uninitialized)

add_compile_options(-Werror=return-type)
add_compile_options(-Werror=parentheses)
add_compile_options(-Werror=vla)
add_compile_options(-Werror=array-bounds)

include_directories(${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/../inc)
add_library(Interp4Move MODULE src/Interp4Move.cpp)
add_library(Interp4Rotate MODULE src/Interp4Rotate.cpp)
add_library(Interp4Set MODULE src/Interp4Set.cpp)
add_library(Interp4Pause MODULE src/Interp4Pause.cpp)