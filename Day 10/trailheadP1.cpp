#include "../utils/advent.h"
#include <iostream>
#include <utility>

using namespace aoc;
using namespace std::complex_literals;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

struct Node {
  int row, col;
  int height;
  uset<Node*> peaks;
  bool explored = false;
  Node(int height, int row, int col) {
    this->height = height;
    this->row = row;
    this->col = col;
  }
};

vec2d<Node*> grid;
void explore(int row, int col) {
  Node* node = grid[row][col];
  node->explored = true;
  if (node->height == 9) {
    node->peaks.insert(node);
    return;
  }
  Node* nextNode;
  for (auto c: CARDINALS) {
    if (row + c.first >= 0 && row + c.first < grid.size() && col + c.second >= 0 && col + c.second < grid[0].size()) {
      nextNode = grid[row + c.first][col + c.second];
      if (nextNode->height == node->height+1) {
        if (!nextNode->explored) explore(row + c.first, col + c.second);
        for (auto i: nextNode->peaks) node->peaks.insert(i);
      }
    }
  }
}

int main() {
  string line;
  float row = 0;
  vec<Node*> trailheads;
  while (getline(f, line)) {
    grid.push_back(vec<Node*>());
    for (int i=0; i<line.size(); i++) {
      grid[row].push_back(new Node(line[i] - '0', row, i));
      if (line[i] == '0') {
        trailheads.push_back(grid[row][i]);
      }
    }
    row++;
  }
  int sum = 0;
  for (Node* trailhead: trailheads) {
    explore(trailhead->row, trailhead->col);
    sum += trailhead->peaks.size();
  }
  std::cout << sum << std::endl;
}
