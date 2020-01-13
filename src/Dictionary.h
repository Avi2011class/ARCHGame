#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <string>
class Dictionary {
 public:
  virtual std::string get_random_word() const = 0;
};

class FileDictionary : public Dictionary {
 public:
  explicit FileDictionary(const std::string& filename);
  virtual std::string get_random_word() const override;

 private:
  static bool is_word_correct(const std::string& word);

  std::vector<std::string> words_;
  mutable std::mt19937 gen_;
  mutable std::uniform_int_distribution<size_t> indices_distribution_;
};

class SimpleTestingDictionary : public Dictionary {
 public:
  explicit SimpleTestingDictionary(std::string word);
  virtual std::string get_random_word() const override;

 private:
  std::string word_;
};