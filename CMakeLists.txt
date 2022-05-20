CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

OPTION(SPLIB_BUILD_TESTS "Build tests" ON)

PROJECT(splib2 VERSION 0.1)

SET (CMAKE_C_FLAGS                "-Wall -Wextra -Wpedantic")
SET (CMAKE_C_FLAGS_DEBUG          "-g -D_DEBUG")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os")
SET (CMAKE_C_FLAGS_RELEASE        "-O4")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -Wpedantic")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g -D_DEBUG -fsanitize=address")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/")

SET(CMAKE_CXX_STANDARD 20)

add_subdirectory(submodules)

add_subdirectory(splib2)

if(SPLIB_BUILD_TESTS)
    include(CTest)
    add_subdirectory(splib2_tests)
endif()