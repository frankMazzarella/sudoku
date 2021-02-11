#include <vector>
#include <iostream>

void LogPuzzle(std::vector<std::vector<int>> &puzzle_grid) {
  for (int row = 0; row < 9; row++) {
    if (row % 3 == 0) {
      std::cout << "-------------------------------" << std::endl;
    }
    for (int col = 0; col < 9; col++) {
      if (col % 3 == 0) {
        std::cout << "|";
      }
      int number = puzzle_grid[row][col];
      if (number == 0) {
        std::cout << "   ";
      } else {
        std::cout << " " << number << " ";
      }
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "-------------------------------" << std::endl;
}