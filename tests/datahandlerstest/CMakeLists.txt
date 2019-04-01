cmake_minimum_required(VERSION 3.10)

file(GLOB SRCS *.cpp)

add_executable(datahandlerstest ${SRCS})

include_directories("${GTEST_INCLUDE_DIRS}")

target_link_libraries(datahandlerstest PUBLIC
    datahandlers
    ${GTEST_LIBRARY_PATH}
	${GTEST_MAIN_LIBRARY_PATH}
)

add_test(
	NAME datahandlerstests
    COMMAND datahandlerstest
)

