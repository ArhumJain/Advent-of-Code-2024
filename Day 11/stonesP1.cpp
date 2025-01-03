#include "../utils/advent.h"
#include <string>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  string line;
  getline(f, line);
  vec<ll> stones = splitLongLong(line);
  for (int i=0; i<25; i++) {
    for (int j=0; j<stones.size(); j++) {
      string stringStone = to_string(stones[j]);
      if (stones[j] == 0) stones[j] = 1;
      else if (stringStone.size()%2 == 0) {
        stones[j] = stoll(stringStone.substr(0, stringStone.size()/2));
        stones.insert(stones.begin() + j + 1,  stoll(stringStone.substr(stringStone.size()/2, stringStone.size()/2)));
        j += 1;
      } else stones[j] *= 2024;
    }
  }
  std::cout << stones.size();
}
