#include <iostream>
#include <string>

#include "include/Tree.hpp"

std::vector<Token> tokens;
int idx;

Node genNode();

Node genNode() {
  Node node;

  if (tokens[idx].name == "$PT_FNCALL" || tokens[idx].name == "$PT_PARAMETER_STRING") {
    node.left.push_back(Token {"", tokens[idx].name + ":" + tokens[idx].value});
    idx++;
    node.children.push_back(genNode());
  }

  if (tokens[idx].name == "$PT_TERMINATOR") {
    node.left.push_back(Token {"", tokens[idx].value});
    
    if (idx < tokens.size() - 1) {
      idx++;
    }
  }

  return node;
}

Node ParseTree::gen(std::vector<Token> tkns) {
  Node tree;

  idx = 0;
  tokens = tkns;
  tree = genNode();

  return tree;
}
