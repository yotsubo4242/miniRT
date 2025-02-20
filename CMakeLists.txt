cmake_minimum_required(VERSION 3.10)

project(miniRT)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(libft)
add_subdirectory(tests)

include_directories(include)
include_directories(libft/includes)
include_directories(src/list)
# cmake -S . 's . bit
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.c")
add_executable(miniRT ${SOURCE_FILES})
target_link_libraries(miniRT ft)
