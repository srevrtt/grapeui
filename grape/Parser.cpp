#include <iostream>
#include <string>

#include "include/Parser.hpp"
#include "include/Lexer.hpp"

Parser::Parser(Lexer *lex) {
  std::vector<Token> tokens = lex->getTokens();

  int idx = 0;

  while (idx < tokens.size() - 1) {
    // Function
    if (tokens[idx].name == "$T_LETTERS" && tokens[idx + 1].name == "$T_LPAREN") {
      newTkns.push_back(Token {"$PT_FNCALL", tokens[idx].value});
      idx += 2;

      if (tokens[idx].name != "$T_STRING") {
        std::cout << "Error: Expected string inside function call.\n";
        exit(1);
      }

      newTkns.push_back(Token {"$PT_PARAMETER_STRING", tokens[idx].value});
      idx++;

      if (tokens[idx].name != "$T_RPAREN") {
        std::cout << "Error: Missing closing parenthesis around function call parameters.\n";
        exit(1);
      }

      idx++;
    }

    if (tokens[idx].name != "$T_SEMICOLON") {
      std::cout << "Error: Missing a semicolon.\n";
      exit(1);
    }

    newTkns.push_back(Token {"$PT_TERMINATOR", ";"});
  }
}

std::vector<Token> Parser::getTkns() {
  return newTkns;
}
