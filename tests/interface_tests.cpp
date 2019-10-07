#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <gtest/gtest.h>

#include "../src/Interface.h"

TEST(Interface, correct_game) {
    std::stringstream input;
    input << "w o r d";
    std::stringstream output;

    SimpleTestingDictionary dict("word");
    Interface game(dict, input, output, 1);
    EXPECT_TRUE(game.play());

    std::string expected_result = "Letter: Well! \"w***\"\n"
                                  "Letter: Well! \"wo**\"\n"
                                  "Letter: Well! \"wor*\"\n"
                                  "Letter: Well! \"word\"\n";
    EXPECT_EQ(output.str(), expected_result);

}

TEST(Interface, correct_game_with_mistakes) {
    std::stringstream input;
    input << "w o r s d";
    std::stringstream output;

    SimpleTestingDictionary dict("word");
    Interface game(dict, input, output, 1);
    EXPECT_TRUE(game.play());

    std::string expected_result = "Letter: Well! \"w***\"\n"
                                  "Letter: Well! \"wo**\"\n"
                                  "Letter: Well! \"wor*\"\n"
                                  "Letter: Fail! you have 0 fail chances\n"
                                  "Letter: Well! \"word\"\n";
    EXPECT_EQ(output.str(), expected_result);
}

TEST(Interface, game_with_incorrect_symbols) {
    std::stringstream input;
    input << "w o r s & d";
    std::stringstream output;

    SimpleTestingDictionary dict("word");
    Interface game(dict, input, output, 1);
    EXPECT_TRUE(game.play());

    std::string expected_result = "Letter: Well! \"w***\"\n"
                                  "Letter: Well! \"wo**\"\n"
                                  "Letter: Well! \"wor*\"\n"
                                  "Letter: Fail! you have 0 fail chances\n"
                                  "Letter: Incorrect letter\n"
                                  "Letter: Well! \"word\"\n";
    EXPECT_EQ(output.str(), expected_result);
}

TEST(Interface, game_with_incorrect_and_repeated_symbols) {
    std::stringstream input;
    input << "w o r s w & d";
    std::stringstream output;

    SimpleTestingDictionary dict("word");
    Interface game(dict, input, output, 1);
    EXPECT_TRUE(game.play());

    std::string expected_result = "Letter: Well! \"w***\"\n"
                                  "Letter: Well! \"wo**\"\n"
                                  "Letter: Well! \"wor*\"\n"
                                  "Letter: Fail! you have 0 fail chances\n"
                                  "Letter: Repeat detected\n"
                                  "Letter: Incorrect letter\n"
                                  "Letter: Well! \"word\"\n";
    EXPECT_EQ(output.str(), expected_result);
}

TEST(Interface, loosed_game) {
    std::stringstream input;
    input << "w o r a s";
    std::stringstream output;

    SimpleTestingDictionary dict("word");
    Interface game(dict, input, output, 1);
    EXPECT_FALSE(game.play());

    std::string expected_result = "Letter: Well! \"w***\"\n"
                                  "Letter: Well! \"wo**\"\n"
                                  "Letter: Well! \"wor*\"\n"
                                  "Letter: Fail! you have 0 fail chances\n"
                                  "Letter: Fail! you have lost your fail chances\n";
    EXPECT_EQ(output.str(), expected_result);
}



