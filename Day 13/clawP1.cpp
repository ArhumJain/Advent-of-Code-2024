#include "../utils/advent.h"
#include <string>

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  string A;
  string B;
  string p;
  vec<long> buttonA;
  vec<long> buttonB;
  vec<long> prize;
  long total = 0;
  while(getline(f, A)) {
    getline(f, B);
    getline(f, p);
    buttonA = splitLong(A);
    buttonB = splitLong(B);
    prize = splitLong(p);
    long combineX = buttonA[0] + buttonA[1];
    long combineY = buttonB[0] + buttonB[1];
    long combinePrize = prize[0] + prize[1];
    std::cout << buttonA[0] << " " << buttonA[1] << std::endl;
    std::cout << buttonB[0] << " " << buttonB[1] << std::endl;
    std::cout << prize[0] << " " << prize[1] << std::endl;
    int minTokens = 999999;
    for (long a=0; a<=100; a++) {
      for (long b=0; b<=100; b++) {
        if (((combineX * a) + (combineY * b)) == combinePrize) {
          if ((a*3 + b) < minTokens){
            minTokens = a*3 + b;
          }
        }
      }
    }
    if (minTokens != 999999) {
      // std::cout << minTokens << std::endl;
      total += minTokens;
    }
  }
  std::cout << total << std::endl;
}
