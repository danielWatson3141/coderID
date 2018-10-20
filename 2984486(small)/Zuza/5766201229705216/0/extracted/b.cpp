#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1e3 + 123;
const int inf = 1e9;

int n;
vector<int> E[MAXN];

// w, dp
pair<int, int> solve(int x, int dad) {
  int dp[2][3]; REP(a, 2) REP(b, 3) dp[a][b] = inf;
  dp[0][0] = 0;

  int sum_w = 1;

  for (int b : E[x]) {
    if (b == dad) continue;
    int w, val; tie(w, val) = solve(b, x);
    sum_w += w;

    REP(i, 3) dp[1][i] = inf;

    REP(i, 3) dp[1][i] = min(dp[1][i], dp[0][i] + w);
    REP(i, 2) dp[1][i+1] = min(dp[1][i+1], dp[0][i] + val);

    REP(i, 3) dp[0][i] = dp[1][i];
  }

  int ans = min(dp[0][0], dp[0][2]);
  return make_pair(sum_w, ans);
}

int main(void)
{
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    scanf("%d", &n);

    REP(i, n-1) {
      int a, b; scanf("%d %d", &a, &b); --a, --b;
      E[a].push_back(b);
      E[b].push_back(a);
    }

    int ans = inf;
    REP(i, n) {
      int w, dp;
      tie(w, dp) = solve(i, -1);
      ans = min(ans, dp);
    }

    printf("Case #%d: %d\n", tc+1, ans);
    fflush(stdout);

    REP(i, n) E[i].clear();
  }
  return 0;
}
