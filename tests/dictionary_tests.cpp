#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../src/Dictionary.h"

TEST(FileDictionary, correct_case) {
    FileDictionary dict("tests/correct_dict.txt");
    EXPECT_EQ(dict.get_random_word(), "word");
    EXPECT_EQ(dict.get_random_word(), "word");
}

TEST(FileDictionary, file_not_exists) {
    EXPECT_THROW(FileDictionary("tests/blabla_dict.txt"), std::runtime_error);
}

TEST(FileDictionary, incorrect_words) {
    EXPECT_THROW(FileDictionary("tests/incorrect_dict.txt"), std::logic_error);
}

TEST(SimpleTestingDictionary, simple_test) {
    SimpleTestingDictionary dict("word");
    EXPECT_EQ(dict.get_random_word(), "word");
    EXPECT_EQ(dict.get_random_word(), "word");
}