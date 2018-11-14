file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

# Declare the library
add_library(common STATIC ${SRCS} ${HDRS})

# include directories exported by common
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

