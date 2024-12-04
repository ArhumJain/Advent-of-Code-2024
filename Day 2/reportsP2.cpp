#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

bool is_safe(vec<int>& report) {
  int diff = report[1] - report[0];
  bool increasing = diff > 0 ? true : false;
  for (int i=1; i<report.size(); i++) {
    diff = report[i] - report[i-1];
    if ((!increasing && diff > 0) || (increasing && diff < 0) || abs(diff) < 1 || abs(diff) > 3) {
      return false;
    }
  }
  return true;
}

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
    vec<int> removed;
    for (int i=0; i < reports.size(); i++) {
      safeCount++;
      diff = reports[i][1] - reports[i][0];
      increasing = diff > 0 ? true : false;
      int removedSafeCount = 0;
      if (!is_safe(reports[i])) {
        safeCount--;
        for (int j=0; j<reports[i].size(); j++) {
          removed = reports[i];
          removed.erase(removed.begin()+j);
          if (is_safe(removed)) {
            safeCount++;
            break;
          }
        }
      }
    }
    std::cout << safeCount << std::endl;
}
