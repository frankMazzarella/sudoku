#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>
#include <vector>

#include "file.h"
#include "sudoku.h"

std::vector<std::vector<int>> build_grid(std::string sudoku_string);

int main() {
  std::string file_path = "C:\\batcave\\cpp\\Sudoku\\Sudoku\\src\\puzzle.txt";
  std::string file_contents = ReadFile(file_path);
  std::vector<std::vector<int>> puzzle_grid = build_grid(file_contents);
  std::chrono::high_resolution_clock::time_point t1 =
      std::chrono::high_resolution_clock::now();
  SolvePuzzle(puzzle_grid);
  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span =
      std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
  std::cout << "This took " << time_span.count() << " seconds" << std::endl;
  std::cin.get();
}

std::vector<std::vector<int>> build_grid(std::string sudoku_string) {
  std::vector<std::vector<int>> puzzle_grid;
  int size = sudoku_string.size();
  puzzle_grid.push_back(std::vector<int>());
  int row = 0;
  for (int i = 0; i < size; i++) {
    if (sudoku_string[i] == '\n') {
      row++;
      puzzle_grid.push_back(std::vector<int>());
    } else {
      int num = sudoku_string[i] - 48;
      puzzle_grid[row].push_back(num);
    }
  }
  return puzzle_grid;
}