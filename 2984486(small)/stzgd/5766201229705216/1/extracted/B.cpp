#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

const int MAXN = 1011;
vector<int> edges[MAXN];
int f[MAXN], sum[MAXN];
int n;

void Init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

void DP(int p, int fa) {
  int cnt = 0, tot = 0;
  sum[p] = 1;
  for (int x : edges[p]) {
    if (x != fa) {
      DP(x, p);
      sum[p] += sum[x];
      tot += sum[x];
      ++cnt;
    }
  }
  f[p] = tot;
  if (cnt < 2) {
    return;
  }
  for (int i = 0; i < edges[p].size(); ++i) {
    if (edges[p][i] == fa) continue;
    for (int j = i + 1; j < edges[p].size(); ++j) {
      if (edges[p][j] == fa) continue;
      if (tot - sum[edges[p][i]] + f[edges[p][i]] - sum[edges[p][j]] + f[edges[p][j]] < f[p]) {
        f[p] = tot - sum[edges[p][i]] + f[edges[p][i]] - sum[edges[p][j]] + f[edges[p][j]];
      }
    }
  }
}

void Work() {
  int ans = INT_MAX;
  for (int root = 1; root <= n; ++root) {
    for (int i = 1; i <= n; ++i) {
      f[i] = 0;
    }
    DP(root, 0);
    if (f[root] < ans)
      ans = f[root];
  }
  printf("%d\n", ans);
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Init();
    Work();
  }
  return 0;
}
