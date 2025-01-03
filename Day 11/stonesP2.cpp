#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");
int numDigits(ll num){ 
  return floor(log10(num))+1;
}
int main() {
  string line;
  getline(f, line);
  vec<ll> stones = splitLongLong(line);
  map<ll, ll> currCountsTotal;
  for (auto i: stones) currCountsTotal[i]++;
  map<ll, pair<ll, ll>> cache;
  for (int j=0; j<75; j++) {
    map<ll, ll> newCountsTotal;
    for (auto i: currCountsTotal) {
      if (cache[i.first].first == 0) {
        if (i.first == 0) newCountsTotal[1] += i.second;
        else if (numDigits(i.first)%2 == 0) {
          ll half1 = (int) (i.first / pow(10, (numDigits(i.first) / 2)));
          ll half2 = (int) (i.first % (int) pow(10, (numDigits(i.first) / 2))); 
          cache[i.first] = {half1, half2};
          newCountsTotal[half1] += i.second;
          newCountsTotal[half2] += i.second;
        } else newCountsTotal[i.first * 2024] += i.second;
      } else {
        newCountsTotal[cache[i.first].first] += i.second;
        newCountsTotal[cache[i.first].second] += i.second;
      }
    }
    currCountsTotal = newCountsTotal;
  }
  ll sum = 0;
  for (auto i: currCountsTotal) sum += i.second;
  std::cout << sum << std::endl;
}
