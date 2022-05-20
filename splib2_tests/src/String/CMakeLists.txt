create_test_sourcelist (string_tests_src
    "StringTests.cpp"
    "Constructors.cpp"
)

add_executable(string_tests ${string_tests_src})
target_link_libraries(string_tests splib)

set (TestsToRun ${string_tests_src})
remove (TestsToRun StringTests.cpp)

foreach (test ${TestsToRun})
    get_filename_component (TName ${test} NAME_WE)
    add_test (NAME "String.${TName}" COMMAND string_tests ${TName})
endforeach ()