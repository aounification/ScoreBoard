cmake_minimum_required(VERSION 3.10)

file(GLOB SRCS *.cpp)

add_executable(commontest ${SRCS})

include_directories("${GTEST_INCLUDE_DIRS}")

target_link_libraries(commontest PUBLIC
	common
    ${GTEST_LIBRARY_PATH}
	${GTEST_MAIN_LIBRARY_PATH}
)

add_test(
	NAME commontests
    COMMAND commontest
)

