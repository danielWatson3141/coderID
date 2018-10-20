#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

const int MAXN = 1010;
vector<int> mp[MAXN];
int n;
int siz[MAXN], dp[MAXN];

int solve(int p, int fa) {
  siz[p] = 1;
  int cnt = 0, sonid = 0;
  vector<int> tmp;
  for (int i = 0 ; i < mp[p].size() ; ++i) {
    int j = mp[p][i];
    if (j == fa) continue;
    solve(j, p);
    siz[p] += siz[j];
    ++cnt;
    sonid = j;
    tmp.push_back(siz[j] - dp[j]);
  }
  if (cnt == 0) return dp[p] = 0;
  if (cnt == 1) return dp[p] = siz[sonid];
    sort(tmp.begin(), tmp.end(), greater<int>());
    return dp[p] = siz[p] - 1 - tmp[0] - tmp[1];
}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d",&n);
    for (int i = 0 ; i <= n ; ++i)
      mp[i].clear();
    for (int i = 0 ; i < n - 1 ; ++i) {
      int t1, t2;
      scanf("%d%d", &t1, &t2);
      --t1; --t2;
      mp[t1].push_back(t2);
      mp[t2].push_back(t1);
    }
    int ans = 1e9;
    for (int i = 0 ; i < n ; ++i) {
      int tmp = solve(i, -1);
      // printf("root:%d ans:%d\n", i+1, tmp);
      if (tmp < ans) ans = tmp;
    }
    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}

