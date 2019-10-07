#include <gtest/gtest.h>
#include "../src/HiddenWord.h"

TEST(HiddenWord, constructor) {
    std::string correct_word_1("qwertyk");
    std::string correct_word_2("HellO");

    std::string incorrect_word_1("123qq");
    std::string incorrect_word_2("hello$");

    EXPECT_NO_THROW(HiddenWord h1(correct_word_1));
    EXPECT_NO_THROW(HiddenWord h2(correct_word_2));
    EXPECT_THROW(HiddenWord h3(incorrect_word_1), std::logic_error);
    EXPECT_THROW(HiddenWord h3(incorrect_word_2), std::logic_error);
}

TEST(HiddenWord, correct_game) {
    std::string word("hello");
    HiddenWord game(word);

    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('h'), HiddenWord::OpenResultCode::SUCCESS);

    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('l'), HiddenWord::OpenResultCode::SUCCESS);

    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('a'), HiddenWord::OpenResultCode::FAIL);

    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('p'), HiddenWord::OpenResultCode::FAIL);

    std::ostringstream output_stream;
    output_stream << game;
    std::string position = output_stream.str();
    EXPECT_EQ(position, "h*ll*");


    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('e'), HiddenWord::OpenResultCode::SUCCESS);

    EXPECT_EQ(game.show_answer(), "hello");

    EXPECT_FALSE(game.is_finished());
    EXPECT_EQ(game.open_symbol('o'), HiddenWord::OpenResultCode::SUCCESS);

    EXPECT_TRUE(game.is_finished());
    output_stream.str("");
    output_stream.clear();

    output_stream << game;
    position = output_stream.str();
    EXPECT_EQ(position, "hello");

}

TEST(HiddenWord, incorrect_game_situations) {
    std::string word("loL");
    HiddenWord game(word);

    EXPECT_FALSE(game.is_finished());

    EXPECT_EQ(game.open_symbol('L'), HiddenWord::OpenResultCode::SUCCESS);
    EXPECT_FALSE(game.is_finished());

    EXPECT_EQ(game.show_answer(), "lol");

    EXPECT_EQ(game.open_symbol('&'), HiddenWord::OpenResultCode::INCORRECT);
    EXPECT_FALSE(game.is_finished());

    EXPECT_EQ(game.open_symbol('l'), HiddenWord::OpenResultCode::REPEAT);
    EXPECT_FALSE(game.is_finished());

    EXPECT_EQ(game.open_symbol('o'), HiddenWord::OpenResultCode::SUCCESS);
    EXPECT_TRUE(game.is_finished());
}