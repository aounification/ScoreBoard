set(SRCS main.cpp)

add_executable(screen ${SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(screen timeHandlers)

install(TARGETS screen DESTINATION build)