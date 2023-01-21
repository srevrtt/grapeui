#pragma once

#include <string>
#include "Tree.hpp"

namespace Kotlin {
  void genKotlin(Node tree, std::string filepath);
  void traverse(Node node);
}
