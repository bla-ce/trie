#include <string>

#include "../includes/trie.h"

void Trie::insert_word(std::string word) {
  Node *curr{root};

  for (const char &ch : word) {
    Node *new_node{new Node};
    new_node->value = ch;

    curr->children[ch] = new_node;

    curr = curr->children[ch];
  }
}
