create_test_sourcelist (list_tests_src
    "ListTests.cpp"
    "Constructors.cpp"
    "Push.cpp"
    "Concatenation.cpp"
    "RemoveAt.cpp"
)

add_executable(list_tests ${list_tests_src})
target_link_libraries(list_tests splib)

set (TestsToRun ${list_tests_src})
remove (TestsToRun ListTests.cpp)

foreach (test ${TestsToRun})
    get_filename_component (TName ${test} NAME_WE)
    add_test (NAME "List.${TName}" COMMAND list_tests ${TName})
endforeach ()