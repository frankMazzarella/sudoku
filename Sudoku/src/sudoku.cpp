#include <iostream>
#include <vector>

#include "log.h"

int solution_counter = 0;
int iteration_counter = 0;

bool IsMovePossible(std::vector<std::vector<int>> &puzzle_grid, int row, int col,
                    int num) {
  for (int i = 0; i < 9; i++) {
    if (puzzle_grid[i][col] == num) {
      return false;
    }
  }
  for (int i = 0; i < 9; i++) {
    if (puzzle_grid[row][i] == num) {
      return false;
    }
  }
  int box_row = (row / 3) * 3;
  int box_col = (col / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (puzzle_grid[box_row + i][box_col + j] == num) {
        return false;
      }
    }
  }
  return true;
}

void SolvePuzzle(std::vector<std::vector<int>> &puzzle_grid) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (puzzle_grid[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
          if (IsMovePossible(puzzle_grid, row, col, num)) {
            puzzle_grid[row][col] = num;
            iteration_counter++;
            SolvePuzzle(puzzle_grid);
            puzzle_grid[row][col] = 0;
          }
        }
        return;
      }
    }
  }
  LogPuzzle(puzzle_grid);
  solution_counter++;
  std::cout << "Solution: " << solution_counter << std::endl;
  std::cout << "Iterations: " << iteration_counter << std::endl;
}