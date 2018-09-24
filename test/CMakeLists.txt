find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/3pl/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)
include_directories(${source_dir}/include)

# Create a libgtest target to be used as a dependency by test programs
add_library(gtestlib SHARED IMPORTED)
add_dependencies(gtestlib gtest)

# Set libgtest properties
set_target_properties(gtestlib PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/Debug/gtestd.lib"
)
#    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"


# Create a libgmock target to be used as a dependency by test programs
add_library(gmocklib SHARED IMPORTED)
add_dependencies(gmocklib gtest)

# Set libgmock properties
set_target_properties(gmocklib PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/Debug/gmockd.lib"
)
#     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"


# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(libtests)
