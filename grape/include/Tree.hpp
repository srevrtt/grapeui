#pragma once

#include "Lexer.hpp"
#include "Parser.hpp"

#include <vector>

struct Node {
  std::vector<Token> left;
  std::vector<Token> right;

  std::vector<Node> children;

  std::string name;
  std::string value;
};

namespace ParseTree {
  Node gen(std::vector<Token> tokens);
}
