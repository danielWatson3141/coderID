#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#if DEBUG
void print(std::vector<int64_t> array) {
  for (auto element : array) {
    std::cout << element << "\t";
  }
  std::cout << std::endl;
}
#endif

std::vector<std::string> switchFlowsAt(std::vector<std::string> flows, int64_t ith) {
  for (uint32_t i = 0; i < flows.size(); ++i) {
    //std::cout << "pre: " << flow << std::endl;
    flows[i][ith] = flows[i][ith] == '0' ? '1' : '0';
    //std::cout << "post: " << flow << std::endl;
  }
  return flows;
}

std::string stringify(std::vector<std::string> flows) {
  std::string result;
  std::sort(flows.begin(), flows.end());
  for (auto flow : flows) {
    result += flow;
  }
  return result;
}

int64_t solve(std::vector<std::string> initial, const std::string &finalString, int64_t index, int64_t flips) {
  if (initial[0].size() < index) {
    return -1;
  }
  if (stringify(initial).compare(finalString) == 0) {
    return flips;
  }
  auto r0 = solve(switchFlowsAt(initial, index), finalString, index + 1, flips + 1);
  auto r1 = solve(initial, finalString, index + 1, flips);
  if (r0 == -1) {
    return r1;
  } else if (r1 == -1) {
    return r0;
  }
  return r0 <= r1 ? r0 : r1;
}

int main(void) {
  int64_t T;
  std::cin >> T;
  for (int64_t t = 0; t < T; ++t) {
    int64_t N, L;
    std::cin >> N >> L;

    std::vector<std::string> initial;
    for (int64_t n = 0; n < N; ++n) {
      std::string flow;
      std::cin >> flow;
      initial.push_back(flow);
    }

    std::vector<std::string> final;
    for (int64_t n = 0; n < N; ++n) {
      std::string flow;
      std::cin >> flow;
      final.push_back(flow);
    }

    int64_t result = -1;
    result = solve(initial, stringify(final), 0, 0);

    std::cout << "Case #" << t + 1 << ": ";
    if (result == -1) {
      std::cout << "NOT POSSIBLE" << std::endl;
    } else {
      std::cout << result << std::endl;
    }
  }
  return EXIT_SUCCESS;
}

