#include <iostream>
#include <string>
#include <fstream>

#include "include/Utils.hpp"

std::string Utilities::readFile(std::string filepath) {
  std::string line, content;
  std::ifstream file(filepath);

  if (!file.is_open()) {
    std::cout << "Error: Invalid filepath \"" + filepath + "\". Does it exist?" << std::endl;
    exit(1);
  }

  while (std::getline(file, line)) {
    content += line + '\n';
  }

  file.close();
  return content;
}

void Utilities::writeFile(std::string filepath, std::string fileContents) {
  std::ofstream file(filepath);

  if (!file.is_open()) {
    std::cout << "Error: Invalid filepath \"" + filepath + "\"." << std::endl;
    exit(1);
  }

  file << fileContents;
  file.close();
}
