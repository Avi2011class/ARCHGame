#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <vector>

#include "Dictionary.h"
#include "Interface.h"

int main() {
  FileDictionary dict("words_dictionary");
  Interface game(dict, std::cin, std::cout, 5);
  if (game.play()) {
    std::cout << "Congratulations!" << std::endl;
  } else {
    std::cout << "You are looser!" << std::endl;
  }

  return EXIT_SUCCESS;
}