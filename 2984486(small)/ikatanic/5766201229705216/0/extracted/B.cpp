#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1010;

vector<int> E[MAXN];

int dfs(int x, int dad) {
  int m1 = 0, m2 = 0;
  for (int y: E[x])
    if (y != dad) {
      int m = dfs(y, x);
      if (m >= m1) m2 = m1, m1 = m; else
        if (m > m2) m2 = m;
    }
  
  if (m1 > 0 && m2 > 0) return m1+m2+1;
  return 1;
}
  
int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    int n;
    scanf("%d", &n);
    REP(i, n) E[i].clear();
    REP(i, n-1) {
      int a, b;
      scanf("%d %d", &a, &b); --a, --b;
      E[a].push_back(b);
      E[b].push_back(a);
    }

    int ans = 0;
    REP(i, n)
      ans = max(ans, dfs(i, -1));
    ans = n-ans;

    printf("Case #%d: ", tp);
    printf("%d\n", ans);
  }
  return 0;
}
