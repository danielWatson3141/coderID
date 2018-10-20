#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int n;
VI ed[1024];
int cnt[1024];

void dfs(int u, int par) {
  cnt[u] = 1;
  for (int v: ed[u]) {
    if (v == par) {
      continue;
    }
    if (cnt[v] == -1) {
      dfs(v, u);
      cnt[u] += cnt[v];
    }
  }
}

int gao(int u, int par) {
  VI o;
  int ret = cnt[u] - 1;
  for (int v: ed[u]) {
    o.PB(v == par ? 0 : gao(v, u));
  }
  REP (i, SZ(ed[u])) {
    for (int j = i + 1; j < SZ(ed[u]); ++j) {
      int x = ed[u][i], y = ed[u][j];
      if (x == par || y == par) {
        continue;
      }
      checkMin(ret, cnt[u] - 1 - cnt[x] - cnt[y] + o[i] + o[j]);
    }
  }
  return ret;
}

int work() {
  scanf("%d", &n);
  fill(ed, ed + 1024, VI());
  REP (i, n - 1) {
    int x, y;
    scanf("%d%d", &x, &y);
    ed[x].PB(y);
    ed[y].PB(x);
  }
  int ans = n - 1;
  for (int u = 1; u <= n; ++u) {
    fill(cnt, cnt + 1024, -1);
    dfs(u, -1);
    checkMin(ans, gao(u, -1));
  }
  return ans;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, work());
  }
  return 0;
}
