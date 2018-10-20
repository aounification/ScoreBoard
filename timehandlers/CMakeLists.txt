file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

# Declare the library
add_library(timehandlers STATIC ${SRCS} ${HDRS})

# include directories exported by timehandlers
target_include_directories(timehandlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

