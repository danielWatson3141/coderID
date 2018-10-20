#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::end;

bool guess_if_bad(const std::vector<uint8_t>& permutation) {
  // very quick. very dirty.
  int badness = 0;
  for (auto i=0u; i<permutation.size(); ++i) {
    auto n = permutation[i];
    if (i == n)
      badness -= 1;

    if (i == n-1)
      badness += 1;
  }
  return badness > 0;
}

int main() {
  std::size_t nTests;
  std::cin >> nTests;
//  assert(nTests == 120);
  for (auto i=0u; i<nTests; ++i) {
    std::size_t nPermutationLength;
    std::cin >> nPermutationLength;
//    assert(nPermutationLength == 1000);

    std::vector<std::uint8_t> permutation;
    for (auto j=0u; j<nPermutationLength; ++j) {
      std::uint8_t b;
      std::cin >> b;
      permutation.push_back(b);
    }
    assert(permutation.size() == nPermutationLength);

    auto isBad = guess_if_bad(permutation);
    auto result = isBad ? "BAD" : "GOOD";
    std::cout << "Case #" << (i+1) << ": " << result << std::endl;
  }
}
