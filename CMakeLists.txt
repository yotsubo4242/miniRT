cmake_minimum_required(VERSION 3.10)

project(miniRT)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(libft)
add_subdirectory(tests)
