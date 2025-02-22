cmake_minimum_required(VERSION 3.10)

project(miniRT)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(libft)
add_subdirectory(tests)

include(ExternalProject)
ExternalProject_Add(
        minilibx
        GIT_REPOSITORY https://github.com/42Paris/minilibx-linux.git
        GIT_TAG master
        PREFIX ${CMAKE_BINARY_DIR}/minilibx
        SOURCE_DIR ${CMAKE_BINARY_DIR}/minilibx/src/minilibx
        CONFIGURE_COMMAND ""
        BUILD_IN_SOURCE 1
        BUILD_COMMAND make -i
        INSTALL_COMMAND ""
        BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/minilibx/src/minilibx/libmlx.a
)
ExternalProject_Get_Property(minilibx SOURCE_DIR)
set(MLX_SOURCE_DIR ${SOURCE_DIR})

add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY IMPORTED_LOCATION ${MLX_SOURCE_DIR}/libmlx.a)

include_directories(include)
include_directories(libft/includes)
include_directories(src/list/include)
include_directories(src/drawing/include)
include_directories(src/share/include)
include_directories(/usr/X11/include)


file(GLOB_RECURSE SOURCE_FILES 
    ${CMAKE_SOURCE_DIR}/src/share/*.c
    ${CMAKE_SOURCE_DIR}/src/scene/*.c
	${CMAKE_SOURCE_DIR}/src/list/*.c
    ${CMAKE_SOURCE_DIR}/src/drawing/*.c
    ${CMAKE_SOURCE_DIR}/src/main.c
)

# src/drawing ディレクトリ内のファイルを除外
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*/src/drawing/.*")

add_executable(miniRT ${SOURCE_FILES})
add_dependencies(miniRT minilibx)

target_link_directories(miniRT PUBLIC /usr/X11/lib)
target_link_libraries(miniRT ft mlx m X11 Xext)
