cmake_minimum_required(VERSION 3.9)

find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(
  googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(googletest source_dir binary_dir)

message(STATUS "source_dir = ${source_dir}")
message(STATUS "binary_dir = ${binary_dir}")

set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include CACHE INTERNAL "")
set(GMOCK_INCLUDE_DIRS ${source_dir}/googlemock/include CACHE INTERNAL "")



# The cloning of the above repo doesn't happen until make, however if the dir doesn't
# exist, INTERFACE_INCLUDE_DIRECTORIES will throw an error.
# To make it work, we just create the directory now during config.
file(MAKE_DIRECTORY ${GTEST_INCLUDE_DIRS})
file(MAKE_DIRECTORY ${GMOCK_INCLUDE_DIRS})

message(STATUS "GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")
message(STATUS "GMOCK_INCLUDE_DIRS = ${GMOCK_INCLUDE_DIRS}")

# Prevent overriding the parent project's compiler/linker
# settings on Windows
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
   set(GOOGLETEST_NAME_SUFFIX "d")
endif (${CMAKE_BUILD_TYPE} STREQUAL Debug)

set(GTEST_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_BUILD_TYPE}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${GOOGLETEST_NAME_SUFFIX}${CMAKE_LINK_LIBRARY_SUFFIX} CACHE INTERNAL "")
set(GTEST_LIBRARY gtest)				 

message(STATUS "GTEST_LIBRARY_PATH = ${GTEST_LIBRARY_PATH}")	 

# Create a gtest target to be used as a dependency by test programs
add_library(${GTEST_LIBRARY} STATIC IMPORTED)

# Set googletest properties
set_target_properties(${GTEST_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}"
)
add_dependencies(${GTEST_LIBRARY} googletest)

set(GTEST_MAIN_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_BUILD_TYPE}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${GOOGLETEST_NAME_SUFFIX}${CMAKE_LINK_LIBRARY_SUFFIX} CACHE INTERNAL "")
set(GTEST_MAIN_LIBRARY gtest_main)
message(STATUS "GTEST_MAIN_LIBRARY_PATH = ${GTEST_MAIN_LIBRARY_PATH}")	 


add_library(${GTEST_MAIN_LIBRARY} STATIC IMPORTED)
set_target_properties(${GTEST_MAIN_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GTEST_MAIN_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GTEST_INCLUDE_DIRS}")
add_dependencies(${GTEST_MAIN_LIBRARY} googletest)

set(GMOCK_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_BUILD_TYPE}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock${GOOGLETEST_NAME_SUFFIX}${CMAKE_LINK_LIBRARY_SUFFIX})
set(GMOCK_LIBRARY gmock)
add_library(${GMOCK_LIBRARY} STATIC IMPORTED)
set_target_properties(${GMOCK_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GMOCK_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
add_dependencies(${GMOCK_LIBRARY} googletest)

set(GMOCK_MAIN_LIBRARY_PATH ${binary_dir}/lib/${CMAKE_BUILD_TYPE}/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main${GOOGLETEST_NAME_SUFFIX}${CMAKE_LINK_LIBRARY_SUFFIX})
set(GMOCK_MAIN_LIBRARY gmock_main)

add_library(${GMOCK_MAIN_LIBRARY} STATIC IMPORTED)
set_target_properties(${GMOCK_MAIN_LIBRARY} PROPERTIES
    "IMPORTED_LOCATION" "${GMOCK_MAIN_LIBRARY_PATH}"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    "INTERFACE_INCLUDE_DIRECTORIES" "${GMOCK_INCLUDE_DIRS}")
add_dependencies(${GMOCK_MAIN_LIBRARY} ${GTEST_LIBRARY})
