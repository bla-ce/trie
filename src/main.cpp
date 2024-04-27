#include "../includes/fruits.cpp"
#include "../includes/trie.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[]) {
  Trie trie{};

  Node *root{new Node{}};
  trie.root = root;

  assert(fruits_list.size() > 0 && "Sample data is empty");

  for (const auto &fruit : fruits_list) {
    trie.insert_word(fruit);
  }

  std::string prefix{};
  std::cout << "Prefix: ";
  std::cin >> prefix;

  std::cout << "\nAuto-suggestions: \n";
  trie.auto_complete(prefix);

  return 0;
}
