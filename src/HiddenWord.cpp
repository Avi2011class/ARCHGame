//
// Created by alexander on 23.09.19.
//

#include "HiddenWord.h"

HiddenWord::HiddenWord(std::string hidden_string)
    : is_letters_opened_(hidden_string.size(), false) {
  hidden_string_ = std::move(hidden_string);
  for (auto& symbol : hidden_string_) {
    if (!is_symbol_correct(symbol)) {
      throw std::logic_error("Word must contains only a-zA-Z chars");
    }
    symbol = static_cast<char>(std::tolower(symbol));
  }
}

bool HiddenWord::is_finished() const {
  return std::accumulate(is_letters_opened_.begin(), is_letters_opened_.end(),
                         true, std::logical_and<>());
}

bool HiddenWord::is_symbol_opened(char ch) const {
  return opened_symbols_.find(ch) != opened_symbols_.end();
}

HiddenWord::OpenResultCode HiddenWord::open_symbol(char ch) {
  if (!is_symbol_correct(ch)) {
    return OpenResultCode::INCORRECT;
  }

  ch = static_cast<char>(std::tolower(ch));
  if (is_symbol_opened(ch)) {
    return OpenResultCode::REPEAT;
  }

  bool letter_was_found = false;
  for (size_t i = 0; i < hidden_string_.size(); ++i) {
    if (hidden_string_[i] == ch) {
      is_letters_opened_[i] = true;
      letter_was_found = true;
    }
  }

  opened_symbols_.insert(ch);
  return letter_was_found ? OpenResultCode::SUCCESS : OpenResultCode::FAIL;
}

bool HiddenWord::is_symbol_correct(char ch) const { return std::isalpha(ch); }

std::ostream& operator<<(std::ostream& output_stream, const HiddenWord& data) {
  for (size_t i = 0; i < data.hidden_string_.size(); ++i) {
    if (data.is_letters_opened_[i]) {
      output_stream << data.hidden_string_[i];
    } else {
      output_stream << '*';
    }
  }
  return output_stream;
}

std::string HiddenWord::show_answer() const { return hidden_string_; }
