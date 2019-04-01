file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

# Declare the library
add_library(datahandlers STATIC ${SRCS} ${HDRS})

# include directories exported by datahandlers
target_include_directories(datahandlers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

