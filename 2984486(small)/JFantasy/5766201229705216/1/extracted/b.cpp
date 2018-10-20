#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1005;
const int maxe = maxn * 2;

int nbs[maxn], ev[maxe], next[maxe];
int f[maxn], size[maxn];
int n, k;

void addedge(int x, int y) {
  next[++ k] = nbs[x];
  ev[k] = y;
  nbs[x] = k;
}

void init() {
  memset(nbs, 0, sizeof(nbs));
  k = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; ++ i) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
}

void update(int &x1, int &x2, const int &val) {
  if (x1 < val) {
    x2 = x1;
    x1 = val;
  } else if (x2 < val) x2 = val;
}

void dfs(int x, int pnt) {
  size[x] = 1;
  int chds = 0, mx1 = 0, mx2 = 0;
  for (int i = nbs[x]; i; i = next[i]) {
    if (ev[i] == pnt) continue;
    dfs(ev[i], x);
    size[x] += size[ev[i]];
    ++ chds;
    update(mx1, mx2, f[ev[i]]);
  }
  if (chds == 0 || chds == 1) f[x] = 1;
  else f[x] = mx1 + mx2 + 1;
}

void work(int cas) {
  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    dfs(i, 0);
    ans = std::max(ans, f[i]);
  }
  printf("Case #%d: %d\n", cas, n - ans);
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int t = 1; t <= cas; ++ t) {
    init();
    work(t);
  }
  return 0;
}
