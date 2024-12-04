#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

vec<std::string> wordSearch = readlines(f); 
int xmasCount = 0;

int main() {
  for (int row = 1; row < wordSearch.size()-1; row++) {
    for (int col = 1; col < wordSearch[0].size()-1; col++) {
      if (wordSearch[row][col] == 'A') {
        xmasCount += (((wordSearch[row-1][col-1] == 'M' && wordSearch[row+1][col+1] == 'S') || (wordSearch[row-1][col-1] == 'S' && wordSearch[row+1][col+1] == 'M')) && ((wordSearch[row+1][col-1] == 'M' && wordSearch[row-1][col+1] == 'S') || (wordSearch[row+1][col-1] == 'S' && wordSearch[row-1][col+1] == 'M')));
      }
    }
  }
  std::cout << xmasCount << std::endl;
}
