cmake_minimum_required(VERSION 3.10)

file(GLOB SRCS *.cpp)

add_executable(timehandlerstest ${SRCS})

include_directories("${GTEST_INCLUDE_DIRS}")

target_link_libraries(timehandlerstest PUBLIC
    timehandlers
    ${GTEST_LIBRARY_PATH}
	${GTEST_MAIN_LIBRARY_PATH}
)

add_test(
	NAME timehandlerstests
    COMMAND timehandlerstest
)

