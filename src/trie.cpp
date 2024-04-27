#include "../includes/trie.h"
#include <iostream>
#include <string>

void Trie::insert_word(std::string word) {
  if (word == "" || word == "\0" || word == "\n" || word == "\t") {
    exit(-1);
  }

  std::vector<std::string> words{split(word)};

  Node *curr{root};

  for(const auto &word : words) {
    for (const char &ch : word) {
      if(curr->children[ch] == nullptr) {
        Node *new_node{new Node};
        new_node->value = ch;

        curr->children[ch] = new_node;
      }

      curr = curr->children[ch];
    }

    curr->is_terminal = true;
    curr = root;
  }
}

std::vector<std::string> Trie::split(std::string buffer) {
  std::vector<std::string> words{};

  std::string word{}; 
  for(const char &ch : buffer) {
    if(ch != ' ' && ch != '\t' && ch != '\n') {
      word += ch;
    } else {
      words.push_back(word);
      word = "";
    }
  }

  words.push_back(word);

  return words;
}

void Trie::auto_complete(std::string prefix) const {
  Node *curr{root};
  for(const auto &ch : prefix) {
    if(curr == nullptr) {
      return;
    }

    curr = curr->children[ch];
  }

  std::vector<std::string> suggestions;
  get_suggestions(curr, prefix, suggestions);

  for(const auto &word : suggestions) {
    std::cout << word << '\n';
  }
}

void Trie::get_suggestions(Node *root, std::string str, std::vector<std::string> &suggestions) const {
  if(root == nullptr) {
    return;
  }

  if (root->is_terminal) {
    suggestions.push_back(str);
  }


  for (const auto &ch : root->children) {
    if (ch != nullptr) {
      get_suggestions(ch, str + ch->value, suggestions);
    }
  }
}
