#include "../utils/advent.h"
#include <utility>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

map<char, vec<pair<int,int>>> antennas;
set<pair<int,int>> antinodes;
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
        if ((*coords)[j].second + diffCol <= cols && (*coords)[j].second + diffCol >= 0 && (*coords)[j].first + diffRow <= rows && (*coords)[j].first + diffRow >= 0) {
          antinodes.insert(make_pair((*coords)[j].first + diffRow, (*coords)[j].second + diffCol));
        }
        if ((*coords)[i].second - diffCol <= cols && (*coords)[i].second - diffCol >= 0 && (*coords)[i].first - diffRow <= rows && (*coords)[i].first - diffRow >= 0) {
          antinodes.insert(make_pair((*coords)[i].first - diffRow, (*coords)[i].second - diffCol));
        }
      }
    }
  }
  std::cout << antinodes.size() << std::endl;
}
