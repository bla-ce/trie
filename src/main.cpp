#include "../includes/trie.h"
#include "../includes/fruits.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Trie *trie{new Trie};

  Node *root{new Node};
  trie->root = root;

  if(fruits_list.size() == 0) {
    exit(-1);
  }

  for(const auto &fruit : fruits_list) {
    trie->insert_word(fruit);
  }

  std::string prefix{};
  std::cout << "Prefix: ";
  std::cin >> prefix;

  std::cout << "\nAuto-suggestions: \n";
  trie->auto_complete(prefix);

  return 0;
}
