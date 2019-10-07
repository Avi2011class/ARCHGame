#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>
#include <cctype>
#include <memory>
#include <set>

#include "HiddenWord.h"
#include "Dictionary.h"

class Interface {
public:
    Interface(const Dictionary& dictionary, std::istream& input_stream,
            std::ostream& output_stream, int fails_limit = 5);

    bool play();
    bool is_finished() const;

private:
    std::istream& input_stream_;
    std::ostream& output_stream_;

    HiddenWord hidden_word_;
    bool is_finished_;
    int fails_limit_;

    void process_char();
};
