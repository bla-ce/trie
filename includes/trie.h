#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <fstream>

class Trie {
public:
  Node *root;

  void insert_word(std::string word);
  void display_trie(Node *root, std::string str) const;
  void auto_complete(std::string prefix) const;
private:
};

#endif
