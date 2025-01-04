#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");
vec2d<char> grid;
vec2d<bool> explored;
int cost = 0;
int explore(bool root, int row, int col, int* area) {
  explored[row][col] = true;
  (*area)++;
  int sides = 4;
  int perimeter = 0;
  for (const auto direction: CARDINALS) {
    int nextRow = row + direction.first;
    int nextCol = col + direction.second;
    if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && grid[nextRow][nextCol] == grid[row][col]) {
      sides--;
      if (!explored[nextRow][nextCol]) perimeter += explore(false, nextRow, nextCol, area);
    }
  }
  perimeter += sides;
  if (root) {
    cost += perimeter * (*area); delete area;
  }
  return perimeter;
}

int main() {
  string line;
  int rows = 0;
  while (getline(f, line)) {
    grid.push_back(vec<char>());
    explored.push_back(vec<bool>());
    for (char c: line) {
      grid[rows].push_back(c);
      explored[rows].push_back(false);
    }
    rows++;
  }
  for (int row=0; row<rows; row++) {
    for (int col=0; col<grid[0].size(); col++) {
      if (!explored[row][col]) explore(true, row, col, new int(0));
    }
  }
  std::cout << cost << std::endl;
}
