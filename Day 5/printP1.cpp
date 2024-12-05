#include "../utils/advent.h"
#include <_stdio.h>
#include <algorithm>
#include <string>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

umap<int, umap<int, bool> > FORWARD;
umap<int, umap<int, bool> > REVERSE;
int numRules = TEST ? 21 : 1176;
int numUpdates = TEST ? 6 : 184;
int sum = 0;
int main() { 
  char c;
  int p1, p2;
  for (int i = 0; i < numRules; i++) {
    f >> p1 >> c >> p2;
    FORWARD[p1][p2] = true;
    REVERSE[p2][p1] = true;
  }
  std::string line; getline(f, line); getline(f, line);
  vec<int> update;
  while (getline(f, line)) {
    update = splitInt(line, ",");
    sum += update[(update.size()-1)/2];
    for (int i=0; i<update.size(); i++) {
      for (int j = i-1; j >= 0; j--) {
        if (!REVERSE[update[i]][update[j]] && FORWARD[update[i]][update[j]]) {
          i = update.size();
          sum -= update[(update.size()-1)/2];
          break;
        }
      }
      for (int j = i+1; j < update.size(); j++) {
        if (!FORWARD[update[i]][update[j]] && REVERSE[update[i]][update[j]]) {
          i = update.size();
          sum -= update[(update.size()-1)/2];
          break;
        }
      }
    }
  }
  std::cout << sum << std::endl;
}
