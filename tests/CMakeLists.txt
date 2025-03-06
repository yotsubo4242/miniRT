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
include_directories(${CMAKE_SOURCE_DIR}/libft/includes)
include_directories(${CMAKE_SOURCE_DIR}/src/list)
include_directories(${CMAKE_SOURCE_DIR}/src/share/include)
include_directories(${CMAKE_SOURCE_DIR}/src/scene/get_next_line)
include_directories(${CMAKE_SOURCE_DIR}/src/scene)
include_directories(${CMAKE_SOURCE_DIR}/minilibx-linux)

# build scene library
file(GLOB_RECURSE SCENE_SOURCES 
	${CMAKE_SOURCE_DIR}/src/scene/*.c
	${CMAKE_SOURCE_DIR}/src/list/*.c
	${CMAKE_SOURCE_DIR}/src/share/*.c
)
add_library(scene OBJECT ${SCENE_SOURCES})

# build test program
add_executable(test_parser test_parser.cpp $<TARGET_OBJECTS:scene>)

# link Google Test library to other link files
target_link_libraries(test_parser gtest_main gtest ft)

# detect tests by not using add_test
gtest_discover_tests(test_parser)
