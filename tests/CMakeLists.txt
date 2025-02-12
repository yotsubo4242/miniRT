# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Google Test v1.14.0
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/libft/include)

file(GLOB_RECURSE SCENE_SOURCES ${CMAKE_SOURCE_DIR}/src/scene/*.c)
add_library(scene OBJECT ${SCENE_SOURCES})

add_executable(test_parser test_parser.cpp $<TARGET_OBJECTS:scene>)
target_link_libraries(test_parser gtest_main gtest ft)
gtest_discover_tests(test_parser)
