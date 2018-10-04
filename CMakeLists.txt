cmake_minimum_required(VERSION 3.0)

project(scoreboard)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELEASE} /MT")

enable_testing()

add_subdirectory(thirdparty)
add_subdirectory(timehandlers)
add_subdirectory(tests)

