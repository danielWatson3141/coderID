/*
 * 
 * File:   pBFullBinaryTree.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Apr 25, 2014, 9:20:47 PM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

namespace pBFullBinaryTree {
vector<int> g[1111];
int dp[1111], size[1111];

void rec(int at, int par) {
  static vector<int> vals;
  size[at] = 1;
  for (const int& to : g[at]) {
    if (to != par) {
      rec(to, at);
      size[at] += size[to];
    }
  }
  vals.clear();
  dp[at] = size[at] - 1;
  for (const int& to : g[at])
    if (to != par)
      vals.push_back(dp[to] - size[to]);
  sort(vals.begin(), vals.end());
  if (vals.size() >= 2u)
    dp[at] += vals[0] + vals[1];
}

void solve(int test_num) {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    g[i].clear();
  for (int i = 1, a, b; i < N; i++) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int res = N;
  for (int root = 1; root <= N; root++) {
    rec(root, root);
    res = min(res, dp[root]);
  }
  printf("Case #%d: %d\n", test_num, res);
}

void solve() {
#ifdef AZN
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
#endif
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pBFullBinaryTree::solve();
  return 0;
}
