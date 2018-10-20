#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge {
  int v, next;
} e[10000];
int p[1001], eid;
void mapinit() {
  memset(p, -1, sizeof(p));
  eid = 0;
}
void insert(int x, int y) {
  e[eid].v = y;
  e[eid].next = p[x];
  p[x] = eid++;
}
void insert2(int x, int y) {
  insert(x, y);
  insert(y, x);
}

int g[1001], n, dp[1001], T;
bool vst[1001];

struct max2 {
  int x, y;
  void init() {
    x = -1;
    y = -1;
  }
  void insert(int t) {
    if (t > y) y = t;
    if (y > x) swap(x, y);
  }
};

int dfs(int v) {
  vst[v] = 1;
  max2 t;
  t.init();
  for (int i = p[v]; ~i; i = e[i].next) {
    int u = e[i].v;
    if (!vst[u]) {
      dfs(u);
      g[v] += g[u];
      t.insert(g[u] - dp[u]);
    }
  }
  if (t.y >= 0) {
    dp[v] = g[v] - t.x - t.y;
  } else {
    dp[v] = g[v];
  }
  ++g[v];
  return dp[v];
}

int main() {
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ca) {
    scanf("%d", &n);
    mapinit();
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      insert2(x, y);
    }
    int res = n + 1;
    for (int i = 1; i <= n; ++i) {
      memset(g, 0, sizeof(g));
      memset(vst, 0, sizeof(vst));
      res = min(res, dfs(i));
    }
    printf("Case #%d: %d\n", ca, res);
  }
  return 0;
}
