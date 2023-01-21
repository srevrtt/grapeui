#include <iostream>
#include <string>

#include "include/Lexer.hpp"

void Lexer::skipWhitespace() {
  while (isspace(src[idx])) {
    idx++;
  }
}

std::string Lexer::tokenizeLetters() {
  std::string letters;

  while (isalpha(src[idx]) || src[idx] == '_') {
    letters += src[idx];
    idx++;
  }

  return letters;
}

std::string Lexer::tokenizeString() {
  idx++;
  std::string str = "\"";

  while (idx < src.length() && src[idx] != '"') {
    str += src[idx];
    idx++;
  }

  if (src[idx] == '"') {
    str += '"';
  }

  idx++;

  return str;
}

Lexer::Lexer(std::string src) {
  idx = 0;
  this->src = src;

  skipWhitespace();

  while (idx < src.length()) {
    std::string letters = tokenizeLetters();

    if (src[idx] == '(') {
      tokens.push_back(Token {"$T_LETTERS", letters});
      tokens.push_back(Token {"$T_LPAREN", "("});

      idx++;

      skipWhitespace();
      std::string str = tokenizeString();
      skipWhitespace();

      if (str != "") {
        tokens.push_back(Token {"$T_STRING", str});

        if (src[idx] == ')') {
          tokens.push_back(Token {"$T_RPAREN", ")"});
          idx++;
        }
      } else {
        // TODO: numbers
      }
    }

    if (src[idx] == ';') {
      tokens.push_back(Token {"$T_SEMICOLON", ";"});
    }
    
    idx++;
  }
}

std::vector<Token> Lexer::getTokens() {
  return tokens;
}
