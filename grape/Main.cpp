#include <iostream>
#include <string>

#include "include/Utils.hpp"
#include "include/Lexer.hpp"
#include "include/Parser.hpp"
#include "include/Tree.hpp"
#include "include/GenKotlin.hpp"

int main(int argc, char *argv[]) {
  std::string src = Utilities::readFile("../examples/hello.grape");
  Lexer *lex = new Lexer(src);
  Parser *parser = new Parser(lex);
  Node tree = ParseTree::gen(parser->getTkns());
  Kotlin::genKotlin(tree, "../examples/hello.kt");

  return 0;
}
