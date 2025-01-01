#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

map<char, vec<pair<int,int>>> antennas;
set<pair<int, int>> antinodes;
int main() {
  std::string line;
  int rows = 0;
  int cols;
  while (getline(f, line)) {
    cols = line.size()-1;
    for (int col = 0; col < line.size(); col++) {
      if (line[col] != '.') {
        antennas[line[col]].push_back(make_pair(rows, col));
      }
    }
    rows++;
  }
  rows--;
  for (const auto &antenna: antennas) {
    const vec<pair<int, int>>* coords = &antenna.second;
    for (int i=0; i<coords->size(); i++) {
      for (int j = i+1; j < coords->size(); j++) {
        int diffRow = (*coords)[j].first - (*coords)[i].first;
        int diffCol = (*coords)[j].second - (*coords)[i].second;
        int currRow = (*coords)[j].first;
        int currCol = (*coords)[j].second;
        while (currCol <= cols && currCol >= 0 && currRow <= rows && currRow >= 0) {
          antinodes.insert(make_pair(currRow, currCol));
          currRow += diffRow;
          currCol += diffCol;
        }
        currRow = (*coords)[i].first;
        currCol = (*coords)[i].second;
        while (currCol <= cols && currCol >= 0 && currRow <= rows && currRow >= 0) {
          antinodes.insert(make_pair(currRow, currCol));
          currRow -= diffRow;
          currCol -= diffCol;
        }
      }
    }
  }
  std::cout << antinodes.size() << std::endl;
}
