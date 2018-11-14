file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

# Declare the library
add_library(basketball STATIC ${SRCS} ${HDRS})
target_link_libraries(basketball PUBLIC
    timehandlers
)

# include directories exported by basketball
target_include_directories(basketball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

