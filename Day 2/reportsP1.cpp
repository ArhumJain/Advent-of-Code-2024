#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

vec2d<int> reports;
int main() { 
    std::string line;
    vec<int> report;
    while (getline(f, line)) {
      report = splitInt(line);
      reports.push_back(splitInt(line));
    }
    bool increasing;
    int diff;
    int safeCount = 0;
    for (int i=0; i < reports.size(); i++) {
      safeCount++;
      diff = reports[i][1] - reports[i][0];
      increasing = diff > 0 ? true : false;
      for (int j=1; j<reports[i].size(); j++) {
        diff = reports[i][j] - reports[i][j-1];
        if ((!increasing && diff > 0) || (increasing && diff < 0) || abs(diff) < 1 || abs(diff) > 3) {
            safeCount--;
            break;
        }
      }
    }
    std::cout << safeCount << std::endl;
}
