#include "../utils/advent.h"
#include <_stdio.h>
#include <string>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

umap<int, umap<int, bool> > FORWARD;
int numRules = TEST ? 21 : 1176;
int numUpdates = TEST ? 6 : 184;
int sum = 0;
int main() { 
  int p1, p2; char c;
  for (int i = 0; i < numRules; i++) {
    f >> p1 >> c >> p2;
    FORWARD[p1][p2] = true;
  }
  std::string line; getline(f, line); getline(f, line);
  vec<int> update;
  vec<int> unorderedUpdate;
  while (getline(f, line)) {
    bool ordered = true;
    update = splitInt(line, ",");
    unorderedUpdate = update;
    std::sort(update.begin(), update.end(), [](int a, int b) { return FORWARD[a][b];});
    for (int i = 0; i<unorderedUpdate.size(); i++) {
      if (unorderedUpdate[i] != update[i]) {
        sum += update[(update.size()-1)/2];
        break;
      }
    }
  }
  std::cout << sum << std::endl;
}
