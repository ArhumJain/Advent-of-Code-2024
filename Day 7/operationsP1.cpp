#include "../utils/advent.h"
#include <string>

using namespace aoc;

constexpr int TEST = 1;
F f(TEST == 1 ? "test.in" : "main.in");

bool compute(vec<std::string>& nums, ll curr, int index) {
  if (index == nums.size()-1) {
    return (curr == stoll(nums[0]));
  } else if (curr > stoll(nums[0])) return false;
  return (compute(nums, curr + stoll(nums[index+1]), index+1) || compute(nums, curr * stoll(nums[index+1]), index+1));
}

int main() {
  std::string line;
  vec<std::string> nums;
  ll sum = 0;
  while (getline(f, line)) {
    nums = split(line); // Modified main inpute by replacing colons with empty space
    if (compute(nums, stoll(nums[1]), 1)) sum += stoll(nums[0]);
  }
  std::cout << sum << std::endl;
}
