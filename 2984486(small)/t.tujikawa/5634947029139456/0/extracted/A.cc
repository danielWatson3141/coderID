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
static const int INF = std::numeric_limits<int>::max();

int main()
{
  int T;

  std::cin >> T;
  for(int test = 1; test <= T; ++test) {
    int N, L;
    std::cin >> N >> L;

    std::vector<std::string> X(N), Y(N);
    for(int i = 0; i < N; ++i) {
      std::cin >> X[i];
    }

    for(int i = 0; i < N; ++i) {
      std::cin >> Y[i];
    }

    std::sort(std::begin(Y), std::end(Y));

    int ans = INF;

    for(int mask = 0; mask < (1 << L); ++mask) {
      auto a = X;

      int flip = 0;
      for(int j = 0; j < L; ++j) {
        if(mask & (1 << j)) {
          ++flip;
          for(int i = 0; i < N; ++i) {
            a[i][j] = a[i][j] == '1' ? '0' : '1';
          }
        }
      }

      std::sort(std::begin(a), std::end(a));

      if(a == Y) {
        ans = std::min(ans, flip);
      }
    }

    std::cout << "Case #" << test << ": ";
    if(ans == INF) {
      std::cout << "NOT POSSIBLE";
    } else {
      std::cout << ans;
    }

    std::cout << std::endl;
  }
}
