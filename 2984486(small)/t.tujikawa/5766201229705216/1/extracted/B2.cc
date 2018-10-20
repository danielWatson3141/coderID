#include <limits.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>
#include <cassert>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <queue>
#include <iterator>
#include <set>
static const int INF = 2000;

int N;

struct Node {
  std::vector<int> next;
};

std::vector<Node> v;

int check(int x, int parent)
{
  int n = v[x].next.size();

  int ans = 0;

  for(int i = 0; i + 1 < n; ++i) {
    auto a = v[x].next[i];
    if(a == parent) {
      continue;
    }

    for(int j = i + 1; j < n; ++j) {
      auto b = v[x].next[j];
      if(b == parent) {
        continue;
      }

      auto rva = check(a, x);
      auto rvb = check(b, x);

      // std::cout << "OK " << rva + rvb << std::endl;

      ans = std::max(ans, rva + rvb);
    }
  }

  return ans + 1;
}

int main()
{
  int T;

  std::cin >> T;
  for(int test = 1; test <= T; ++test) {
    std::cin >> N;

    v = std::vector<Node>(N);
    for(int i = 0; i < N - 1; ++i) {
      int X, Y;
      std::cin >> X >> Y;
      --X;
      --Y;

      v[X].next.push_back(Y);
      v[Y].next.push_back(X);
    }

    int ans = -1;
    for(int i = 0; i < N; ++i) {
      // std::cout << "root=" << i << std::endl;
      ans = std::max(ans, check(i, -1));
    }

    std::cout << "Case #" << test << ": " << N - ans << std::endl;
  }
}
