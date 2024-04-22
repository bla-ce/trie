#ifndef NODE_H
#define NODE_H

#include <array>
#include <string>

class Node {
public:
  Node* children[256];
  bool is_terminal;
  char value;
private:
};

#endif
