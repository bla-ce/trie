#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include <fstream>
#include <vector>

class Trie {
private:
  std::vector<std::string> split(std::string buffer);
  void free_children(Node *node);
public:
  Node *root;

  void insert_word(std::string word);
  void get_suggestions(Node *root, std::string str,
                       std::vector<std::string> &suggestions) const;
  void auto_complete(std::string prefix) const;

  ~Trie();
};

#endif
