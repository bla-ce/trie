#include "../includes/node.h"
#include "../includes/trie.h"
#include <iostream>

int main() {
  Node *root{ new Node };

  Trie *trie{ new Trie };
  trie->root = root;

  trie->insert_word("hello");

  Node *curr { trie->root };

  for(const auto &ch : "hello") {
    if(curr->children[ch] != 0) {
      std::cout << curr->children[ch]->value << '\n';
    }

    curr = curr->children[ch];
  } 

  return 0;
}
