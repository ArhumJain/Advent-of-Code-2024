#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

vec<std::string> wordSearch; 
std::string XMAS = "XMAS";
int xmasCount = 0;

bool explore(int row, int col, int row_dir, int col_dir, std::string word) {
  if (word == "XMAS") return true;
  else if ((word[0] != 'X' && word != "") || XMAS.find(word) == std::string::npos || row < 0 || row >= wordSearch.size() || col < 0 || col >= wordSearch[0].size()) return false;
  xmasCount += explore(row + row_dir, col + col_dir, row_dir, col_dir, word+wordSearch[row][col]);
  return false;
}

int main() {
  std::string line;
  while(getline(f, line)) wordSearch.push_back(line);
  for (int row = 0; row < wordSearch.size(); row++) {
    for (int col = 0; col < wordSearch[0].size(); col++) {
      for (auto direction: CONSTANTS::DIRECTIONS) {
        explore(row, col, direction.first, direction.second, "");
      }
    }
  }
  std::cout << xmasCount << std::endl;
}
