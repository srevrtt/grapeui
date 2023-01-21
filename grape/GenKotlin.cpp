#include <iostream>
#include <string>

#include "include/GenKotlin.hpp"
#include "include/Utils.hpp"

int treeIdx;
std::string kotlinSrc;
bool fn = false;

void Kotlin::traverse(Node node) {
  if (fn == true) {
    std::string substr = node.left[0].value;
    substr = substr.substr(22);
    substr.pop_back();

    // TODO: modify for multiple parameters
    kotlinSrc += '"';
    kotlinSrc += substr;
    kotlinSrc += "\")\n";

    fn = false;
  }

  if (node.left[treeIdx].value == "$PT_FNCALL:println") {
    fn = true;
    kotlinSrc += "println(";
  }

  if (node.children.size() > 0 || node.left[treeIdx].value == ";") {
    treeIdx++;
    traverse(node.children[0]);
  }
}

void Kotlin::genKotlin(Node tree, std::string filepath) {
  treeIdx = 0;
  kotlinSrc += "fun main() {\n";

  traverse(tree);
  kotlinSrc += "}";

  Utilities::writeFile(filepath, kotlinSrc);
}
