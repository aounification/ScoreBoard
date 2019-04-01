cmake_minimum_required(VERSION 3.0)

project(scoreboard)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")

enable_testing()

add_subdirectory(thirdparty)
add_subdirectory(timehandlers)
add_subdirectory(common)
add_subdirectory(datahandlers)
add_subdirectory(tests)

