#include "../utils/advent.h"
#include <iostream>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  vec<int> left;
  int l, r;
  umap<int, int> right;
  while (f >> l) {
    f >> r;
    right[r]++;
    left.push_back(l);
  }
  int similarity = 0;
  for (int i=0; i < left.size(); i++) {
    similarity += left[i] * right[left[i]];
  }
  std::cout << similarity << std::endl;
}
