#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  std::string instructions;
  int sum = 0;
  while (getline(f, instructions)) {
    std::regex rgx("mul\\(([0-9]?[0-9]?[0-9]),([0-9]?[0-9]?[0-9])\\)");
    auto beg = std::sregex_iterator(instructions.begin(), instructions.end(), rgx);
    auto end = std::sregex_iterator();
    int a, b;
    for (std::sregex_iterator i = beg; i != end; i++) {
      std::stringstream s((*i).str());
      char m;
      s >> m >> m >> m >> m >> a >> m >> b;
      sum += a * b;
    }
  }
  std::cout << sum << std::endl;
}
