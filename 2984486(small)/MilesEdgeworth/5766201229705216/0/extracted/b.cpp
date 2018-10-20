#include <cstdio>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <cstring>
#include <sstream>

const int MAX_N = 1005;
const int MAX = 1000000000;
int N;
std::set<int> adj[MAX_N];

int cache[MAX_N][MAX_N];
int cache2[MAX_N][MAX_N];

int subsize(int n, int par) {
  if (par != -1) {
    if (cache2[n][par] != -1) return cache2[n][par];
  }
  int val = 1;
  for (auto i : adj[n]) {
    if (i != par) {
      val += subsize(i, n);
    }
  }
  if (par != -1) cache2[n][par] = val;
  return val;
}

int dp(int n, int par) {
  if (par != -1) {
    if (cache[n][par] != -1) return cache[n][par];
  }
  int sz = adj[n].size() - (par != -1);
  int to_sub = sz - 2;
  if (to_sub < 0) to_sub = sz;

  if (sz == 0) {
    if (par != -1) cache[n][par] = 0;
    return 0;
  }

  std::vector<std::pair<int, int>> bests;
  for (auto i : adj[n]) {
    if (i != par)
      bests.push_back(std::make_pair(dp(i, n), i));
  }
  std::sort(bests.begin(), bests.end());
  int val = 0;
  for (int i = 0; i < to_sub; ++i) {
    val += subsize(bests[i].second, n);
  }
  int val1 = 0;
  int val2 = 0;
  for (int i = to_sub; i < bests.size(); ++i) {
    val2 += bests[i].first;
    val1 += subsize(bests[i].second, n);
  }
  val += std::min(val1, val2);
  if (par != -1) {
    cache[n][par] = val;
  }
  return val;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      adj[i].clear();
    }
    memset(cache, -1, sizeof(int) * MAX_N * MAX_N);
    memset(cache2, -1, sizeof(int) * MAX_N * MAX_N);
    for (int i = 0; i < N - 1; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--;
      b--;
      adj[a].insert(b);
      adj[b].insert(a);
    }
    int min = MAX;
    for (int i = 0; i < N; ++i) {
      int val = dp(i, -1);
      min = std::min(min, val);
    }
    printf("Case #%d: ", t);
    printf("%d\n", min);
  }
}
