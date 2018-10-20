#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

int n;
int size[1005];
int best[1005];
int u[3];
vector<int> g[1005];

void go(int x, int p = -1) {
  int sz = g[x].size();
  for (int i = 0; i < sz; ++i)
    if (g[x][i] != p) go(g[x][i], x);
  best[x] = size[x] = 1;
  for (int i = 0; i < sz; ++i)
    if (g[x][i] != p) size[x] += size[g[x][i]];
  u[0] = u[1] = u[2] = 0;
  if ((p == -1 and sz >= 2) or (p != -1 and sz >= 3)) {
    for (int i = 0; i < sz; ++i) {
      if (g[x][i] == p) continue;
      u[2] = best[g[x][i]];
      sort(u, u + 3); reverse(u, u + 3);
    }
    best[x] += u[0] + u[1];
  }
}

int main() {
  freopen("in", "r", stdin); freopen("out", "w", stdout); freopen("log", "w", stderr);
  int tt; scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    for (int i = 0; i < 1005; ++i) g[i].clear();
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y; scanf("%d %d", &x, &y); --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int ans = 0;
    for (int root = 0; root < n; ++root) {
      go(root);
      ans = max(ans, best[root]);
    }
    printf("Case #%d: %d\n", cc, n - ans);
  }
  return 0;
}