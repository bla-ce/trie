#include "../includes/trie.h"
#include <iostream>
#include <string>

void Trie::insert_word(std::string word) {
  if (word == "" || word == "\0" || word == "\n" || word == "\t") {
    exit(-1);
  }

  Node *curr{root};

  for (const char &ch : word) {
    if(curr->children[ch] == nullptr) {
      Node *new_node{new Node};
      new_node->value = ch;

      curr->children[ch] = new_node;
    }

    curr = curr->children[ch];
  }

  curr->is_terminal = true;
}

void Trie::auto_complete(std::string prefix) const {
  Node *curr{root};
  for(const auto &ch : prefix) {
    if(curr == nullptr) {
      return;
    }

    curr = curr->children[ch];
  }

  display_trie(curr, prefix);
}

void Trie::display_trie(Node *root, std::string str) const {
  if(root == nullptr) {
    return;
  }

  if (root->is_terminal) {
    std::cout << str << '\n';
  }


  for (const auto &ch : root->children) {
    if (ch != nullptr) {
      display_trie(ch, str + ch->value);
    }
  }
}
