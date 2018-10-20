#include <iostream>
#include <map>
#include <vector>
#include <fcntl.h>
#include <unistd.h>

int random(int min, int max) {
  int fd = open("/dev/urandom", O_RDONLY);
  int res;
  read(fd, reinterpret_cast<char*>(res), sizeof(res));

  return res % (max - min) + min;
}

void ApplyP(std::vector<int>& v, const std::map<int, int, std::greater<int>>& p) {
  for (const auto& t: p) {
    int tmp = v[t.first];
    v[t.first] = v[t.second];
    v[t.second] = tmp;
  }
}

int CountP(std::vector<int>& v) {
  size_t size = v.size();
  int res = 0;
  for (size_t i = 0; i < size; ++i) {
    while (v[i] != i) {
      int tmp = v[v[i]];
      v[v[i]] = v[i];
      v[i] = tmp;
      ++res;
    }
  }

  return res;
}

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    int N;
    std::cin >> N;

    std::vector<int> P(1000, 0);
    for (int j = 0; j < N; ++j) std::cin >> P[j];

    uint64_t distance1 = 0, distance2 = 0;
    for (int j = 0; j < 600; ++j) {
      std::map<int, int, std::greater<int>> revert;
      for (int k = 0; k < N; ++k) {
        int p = random(0, N);
        revert.emplace(k, p);
      }

      auto P1 = P;
      ApplyP(P1, revert);
      distance1 += CountP(P1);
    }

    for (int j = 0; j < 600; ++j) {
      std::map<int, int, std::greater<int>> revert;
      for (int k = 0; k < N; ++k) {
        int p = random(k, N);
        revert.emplace(k, p);
      }

      auto P1 = P;
      ApplyP(P1, revert);
      distance2 += CountP(P1);
    }

    distance1 /= 600;
    distance2 /= 600;
    if (distance1 >= distance2) std::cout << "GOOD";
    else std::cout << "BAD";

    std::cout << std::endl;
  }
}

