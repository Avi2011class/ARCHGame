#pragma once

#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iterator>


class HiddenWord {
public:
    enum class OpenResultCode {
        INCORRECT, SUCCESS, FAIL, REPEAT
    };

    explicit HiddenWord(std::string hidden_string);
    bool is_finished() const;

    OpenResultCode open_symbol(char ch);
    friend std::ostream& operator<<(std::ostream& output_stream, const HiddenWord& data);
    std::string show_answer() const;

private:
    bool is_symbol_opened(char ch) const;
    bool is_symbol_correct(char ch) const;

    std::string hidden_string_;
    std::vector<bool> is_letters_opened_;
    std::unordered_set<char> opened_symbols_;
};
