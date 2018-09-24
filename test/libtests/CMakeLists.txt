file(GLOB SRCS *.cpp)

include_directories("${binary_dir}/test/3pl/gtest/src/gtest/googletest/include")
include_directories("${binary_dir}/test/3pl/gtest/src/gtest/googlemock/include")

ADD_EXECUTABLE(libtests ${SRCS})

TARGET_LINK_LIBRARIES(libtests
    timehandlers
    gtestlib
)

add_test(NAME libtests COMMAND libtests)