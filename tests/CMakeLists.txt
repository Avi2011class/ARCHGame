add_executable(tests hidden_word_tests.cpp ../src/HiddenWord.cpp
        dictionary_tests.cpp ../src/Dictionary.cpp
        interface_tests.cpp ../src/Interface.cpp)
target_link_libraries(tests gtest gtest_main pthread)
add_test(NAME tests COMMAND tests)