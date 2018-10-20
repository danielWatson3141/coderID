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

class NotPossible { };

std::uint64_t read_bin() {
  std::uint64_t n;
  std::string s;
  std::cin >> s;
  std::size_t lenConverted;
  n = std::stoll(s, &lenConverted, 2);
  assert(lenConverted == s.size());
  return n;
}

int calculate_min_flips(const std::vector<uint64_t>& sortedOutlets,
                        const std::vector<uint64_t>& devices) {
  int minFlips = INT_MAX;
  // exhaustiving try flips matching up each device/outlet pair
  for (auto device : devices) {
    for (auto outlet : sortedOutlets) {
      // flip all the devices according to this device/outlet matchup
      auto flipset = device ^ outlet;
      auto nFlips = __builtin_popcountll(flipset);
      if (nFlips >= minFlips)
        continue; // already have a better solution
      std::vector<uint64_t> flippedDevices;
      flippedDevices.reserve(devices.size());
      for (auto otherDevice : devices)
        flippedDevices.push_back(flipset ^ otherDevice);

      // see if this flipset works for all devices
      std::sort(begin(flippedDevices), end(flippedDevices));
      auto outletIt = begin(sortedOutlets);
      bool flipWorks = true;
      for (auto dev : flippedDevices) {
        if (dev != *outletIt) {
          flipWorks = false;
          break;
        }
        ++outletIt;
      }
      if (flipWorks)
        minFlips = nFlips;
    }
  }
  if (minFlips == INT_MAX)
    throw NotPossible();
  return minFlips;
}

int main() {
  std::size_t nTests;
  std::cin >> nTests;
  for (auto i=0u; i<nTests; ++i) {
    std::size_t nDevices;
    std::size_t nBits;
    std::cin >> nDevices >> nBits;

    std::vector<std::uint64_t> outlets;
    for (auto j=0u; j<nDevices; ++j)
      outlets.push_back(read_bin());
    std::vector<std::uint64_t> devices;
    for (auto j=0u; j<nDevices; ++j)
      devices.push_back(read_bin());

    std::cout << "Case #" << (i+1) << ": ";
    try {
      std::sort(begin(outlets), end(outlets));
      auto minFlips = calculate_min_flips(outlets, devices);
      std::cout << minFlips;
    } catch (NotPossible& e) {
      std::cout << "NOT POSSIBLE";
    }
    std::cout << std::endl;
  }
}
