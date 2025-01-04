#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");
vec2d<char> grid;
vec2d<bool> explored;
int cost = 0;

bool isEdge(char type, int row, int col) {
  return (gridOutOfBounds(row, col, grid.size(), grid[0].size()) || !(grid[row][col] == type));
}

bool isPartOfRegion(char type, int row, int col) {
  return (!(gridOutOfBounds(row, col, grid.size(), grid[0].size())) && grid[row][col] == type);
}

bool isCorner(char type, int row, int col, pair<int, int> diagonalDirection) {
  if (diagonalDirection == DIAGONALS[0]) {
    return ((isEdge(type, row, col-1) && isEdge(type, row-1, col)) || (isPartOfRegion(type, row, col-1) && isPartOfRegion(type, row-1, col) && !isPartOfRegion(type, row+diagonalDirection.first, col+diagonalDirection.second)));
  } else if (diagonalDirection == DIAGONALS[1]) {
    return ((isEdge(type, row, col+1) && isEdge(type, row-1, col)) || (isPartOfRegion(type, row, col+1) && isPartOfRegion(type, row-1, col) && !isPartOfRegion(type, row+diagonalDirection.first, col+diagonalDirection.second)));
  } else if (diagonalDirection == DIAGONALS[2]) {
    return ((isEdge(type, row, col+1) && isEdge(type, row+1, col)) || (isPartOfRegion(type, row, col+1) && isPartOfRegion(type, row+1, col) && !isPartOfRegion(type, row+diagonalDirection.first, col+diagonalDirection.second)));
  } else {
    return ((isEdge(type, row, col-1) && isEdge(type, row+1, col)) || (isPartOfRegion(type, row, col-1) && isPartOfRegion(type, row+1, col) && !isPartOfRegion(type, row+diagonalDirection.first, col+diagonalDirection.second)));
  }
}

void explore(bool root, int row, int col, int* area, vec<pair<int,int>>* corners) {
  explored[row][col] = true;
  (*area)++;

  for (const auto diagonal: DIAGONALS) {
    if (isCorner(grid[row][col], row, col, diagonal)) (*corners).push_back({row+diagonal.first, col+diagonal.second});
  }

  for (const auto direction: CARDINALS) {
    int nextRow = row + direction.first;
    int nextCol = col + direction.second;
    if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && grid[nextRow][nextCol] == grid[row][col]) {
      if (!explored[nextRow][nextCol]) explore(false, nextRow, nextCol, area, corners);
    }
  }

  if (root) {
    cost += (*corners).size() * (*area); delete area; delete corners;
  }
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
      if (!explored[row][col]) explore(true, row, col, new int(0), new vec<pair<int,int>>());
    }
  }
  std::cout << cost << std::endl;
}
