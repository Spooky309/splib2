configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" @ONLY)

add_custom_target(splib_docs ALL
                   COMMAND "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
                   WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
                   COMMENT "Generating SPLIB HTML documentation"
                   VERBATIM)