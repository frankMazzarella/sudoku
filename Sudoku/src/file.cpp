#include <fstream>
#include <iostream>

std::string ReadFile(std::string file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cout << "Problem reading " << file_path << std::endl;
    return "";
  }
  std::string input;
  std::string content;
  while (file >> input) {
    content += input;
    if (!file.eof()) {
      content += "\n";
    }
  }
  file.close();
  return content;
}