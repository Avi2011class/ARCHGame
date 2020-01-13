//
// Created by alexander on 25.09.19.
//

#include "Dictionary.h"

FileDictionary::FileDictionary(const std::string& filename)
    : gen_(std::random_device()()) {
  std::fstream file_stream(filename, std::ios::in);
  if (!file_stream) {
    throw std::runtime_error("Dictionary file \"" + filename +
                             "\" was not found");
  }

  std::string word;
  while (file_stream >> word) {
    if (is_word_correct(word)) {
      words_.emplace_back(std::move(word));
    }
  }
  file_stream.close();
  if (words_.empty()) {
    throw std::logic_error("Dictionary is empty");
  }

  indices_distribution_ =
      std::uniform_int_distribution<size_t>(0, words_.size() - 1);
}

bool FileDictionary::is_word_correct(const std::string& word) {
  if (word.empty()) {
    return false;
  }
  for (const auto& symbol : word) {
    if (!std::isalpha(symbol)) {
      return false;
    }
  }
  return true;
}

std::string FileDictionary::get_random_word() const {
  size_t index = indices_distribution_(gen_);
  return words_[index];
}

SimpleTestingDictionary::SimpleTestingDictionary(std::string word)
    : word_(std::move(word)) {}

std::string SimpleTestingDictionary::get_random_word() const { return word_; }
