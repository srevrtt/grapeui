#pragma once
#include <string>

namespace Utilities {
  std::string readFile(std::string filepath);
  void writeFile(std::string filepath, std::string fileContents);
}
