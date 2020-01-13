//
// Created by alexander on 25.09.19.
//

#include "Interface.h"

Interface::Interface(const Dictionary& dictionary, std::istream& input_stream,
                     std::ostream& output_stream, int fails_limit)
    : input_stream_(input_stream),
      output_stream_(output_stream),
      hidden_word_(dictionary.get_random_word()),
      is_finished_(false),
      fails_limit_(fails_limit) {}

void Interface::process_char() {
  if (is_finished_) {
    return;
  }

  output_stream_ << "Letter: ";
  char ch;
  input_stream_ >> ch;

  HiddenWord::OpenResultCode code = hidden_word_.open_symbol(ch);
  if (code == HiddenWord::OpenResultCode::SUCCESS) {
    if (hidden_word_.is_finished()) {
      is_finished_ = true;
    }
    output_stream_ << "Well! \"" << hidden_word_ << "\"" << std::endl;
  } else if (code == HiddenWord::OpenResultCode::FAIL) {
    --fails_limit_;
    if (fails_limit_ >= 0) {
      output_stream_ << "Fail! you have " << fails_limit_ << " fail chances"
                     << std::endl;
    } else {
      output_stream_ << "Fail! you have lost your fail chances" << std::endl;
    }
  } else if (code == HiddenWord::OpenResultCode::REPEAT) {
    output_stream_ << "Repeat detected" << std::endl;
  } else if (code == HiddenWord::OpenResultCode::INCORRECT) {
    output_stream_ << "Incorrect letter" << std::endl;
  }

  if (fails_limit_ < 0) {
    is_finished_ = true;
  }
}

bool Interface::is_finished() const { return is_finished_; }

bool Interface::play() {
  while (!is_finished()) {
    process_char();
  }

  return hidden_word_.is_finished();
}
