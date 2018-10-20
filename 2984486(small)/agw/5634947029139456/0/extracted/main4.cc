#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int bin(const std::string& s)
{
  int size = s.size();

  int n = 0;

  for (int i = size - 1, b = 1; i >= 0; i --, b *= 2)
    if (s[i] == '1')
      n |= b;
  
  return n;
}

int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::string s;

  int T, N, L;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> N >> L;

    std::set<int> s1, s2;

    for (int i = 0; i < N; i ++) {
      std::cin >> s;

      s1.insert(bin(s));
    }

    for (int i = 0; i < N; i ++) {
      std::cin >> s;

      s2.insert(bin(s));
    }

    int cm = INF;

    for (int i = 0; i < (1 << L); i ++) {
      std::set<int> s;

      for (const auto& j : s1)
        s.insert(j ^ i);

      if (s == s2)
        cm = std::min(__builtin_popcount(i), cm);
    }

    std::cout << "Case #" << t << ": ";

    if (cm < INF) {
      std::cout << cm << std::endl;
    }
    else {
      std::cout << "NOT POSSIBLE" << std::endl;
    }
  }

  return 0;
}
