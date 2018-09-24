file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE HDRS *.hpp)

# Declare the library
add_library(timehandlers SHARED ${SRCS} ${HDRS})
add_library(timehandlers2 STATIC ${SRCS} ${HDRS})

# include directories exported by myLib
target_include_directories(timehandlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

