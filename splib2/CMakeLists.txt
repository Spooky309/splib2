FILE(GLOB_RECURSE splib_src src/*.cpp)
ADD_LIBRARY(splib SHARED ${splib_src})
TARGET_INCLUDE_DIRECTORIES(splib PUBLIC ./include)

SET(SPLIB_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include/")

TARGET_LINK_LIBRARIES(splib glfw tls)
TARGET_INCLUDE_DIRECTORIES(splib PRIVATE ${glfw_INCLUDE_DIRECTORIES} ${TLS_INCLUDE_DIR})

OPTION(SPLIB_NIGHTMARE_DIFFICULTY "Enable _all_ warnings, promote warnings to errors" ON)
OPTION(SPLIB_BUILD_DOCS "Build documentation" ON)

IF (SPLIB_NIGHTMARE_DIFFICULTY)
        TARGET_COMPILE_OPTIONS(splib PRIVATE -Wall -Wextra -Wpedantic -Werror)
ENDIF ()

INSTALL(TARGETS splib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/splib2)
INSTALL(TARGETS)
INSTALL(DIRECTORY include/splib2 DESTINATION include)

IF (SPLIB_BUILD_DOCS)
        FIND_PACKAGE(Doxygen)
        IF (DOXYGEN_FOUND)
                ADD_SUBDIRECTORY(docs)
        ELSE ()
                MESSAGE(WARNING "Documentation enabled, but Doxygen not found! Not making docs for splib...")
        ENDIF ()
ENDIF ()