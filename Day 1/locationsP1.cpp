#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  vec<int> left;
  vec<int> right;
  int l, r;
  while (f >> l) {
    f >> r;
    left.push_back(l);
    right.push_back(r);
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  int distance = 0;
  for (int i=0; i < left.size(); i++) {
    distance += abs(left[i] - right[i]);
  }
  std::cout << distance << std::endl;
}
