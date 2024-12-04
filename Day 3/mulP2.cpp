#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
  std::string instructions;
  std::regex rgx("mul\\(([0-9]?[0-9]?[0-9]),([0-9]?[0-9]?[0-9])\\)|do\\(\\)|don't\\(\\)");
  int sum = 0;
  bool enabled = true;
  while (getline(f, instructions)) {
    auto beg = std::sregex_iterator(instructions.begin(), instructions.end(), rgx);
    auto end = std::sregex_iterator();
    int a, b;
    std::string doInstruction;
    for (std::sregex_iterator i = beg; i != end; i++) {
      std::stringstream s((*i).str());
      char m;
      s >> m;
      if (m == 'd') {
        s >> doInstruction;
        enabled = doInstruction == "o()";
      } else {
        s >> m >> m >> m >> a >> m >> b;
        sum += a * b * enabled;
      }
    }
  }
  std::cout << sum << std::endl;
}
