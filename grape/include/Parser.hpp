#pragma once

#include "Lexer.hpp"
#include <vector>

class Parser {
private:
  std::vector<Token> newTkns;
public:
  Parser(Lexer *lex);
  std::vector<Token> getTkns();
};
