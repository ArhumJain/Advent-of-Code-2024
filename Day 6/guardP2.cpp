#include "../utils/advent.h"
#include <iostream>
#include <tuple>
#include <utility>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int rowDir = -1;
int colDir = 0;
void rotate90() {
  if (rowDir == -1 && colDir == 0) {
    rowDir = 0; colDir = 1;
  }
  else if (rowDir == 0 && colDir == 1) {
    rowDir = 1; colDir = 0;
  }
  else if (rowDir == 1 && colDir == 0) {
    rowDir = 0; colDir = -1;
  }
  else if (rowDir == 0 && colDir == -1) {
    rowDir = -1; colDir = 0;
  }
}
int main() {
  vec<std::string> grid;
  vec2d<pair<int, int>> states;
  std::string line;
  int startRow, startCol;
  int row = 0;
  int count = 0;
  while (getline(f, line)) {
    grid.push_back(line);
    states.push_back(vec<pair<int, int>>());
    for (int i = 0; i<line.size(); i++) {
      if (line[i] == '^') {
        startRow = row; startCol = i;
      }
      states[row].push_back(make_pair(0, 0));
    }
    row++;
  }
  print1d(grid, "\n");
  std::cout << startRow << " " << startCol << std::endl;
  bool outOfBound = false;
  char curr = '^';
  while (!outOfBound) {
    while (curr != '#') {
      if (grid[startRow][startCol] != 'X') {
        grid[startRow][startCol] = 'X';
        count++;
      }
      else if (grid[startRow][startCol] == 'X' && (states[startRow][startCol].first != rowDir || states[startRow][startCol].second != colDir)) {

      }
      startRow += rowDir;
      startCol += colDir;
      if (startRow < 0 || startRow >= grid.size() || startCol < 0 || startCol >= grid[0].size()) { outOfBound = true; curr = '#'; } 
      else curr = grid[startRow][startCol];
    }
    startRow -= rowDir; 
    startCol -= colDir;
    curr = '^';
  }
  std::cout << count << std::endl;
}
