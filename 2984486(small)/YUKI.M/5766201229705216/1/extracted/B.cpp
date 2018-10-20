#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <queue>
#include <set>

using namespace std;

vector<int> g[1000];
int memo[1000][2];

int dfs(int now, int prev, bool del){
  if(memo[now][del] != -1) return memo[now][del];

  vector<int> costs;
  vector<int> costsdel;

  REP(i,g[now].size()) if(g[now][i] != prev){
    costs.push_back(dfs(g[now][i], now, false));
    costsdel.push_back(dfs(g[now][i], now, true));
  }

  const int c = costs.size();

  if(del){
    int sum = 1;
    REP(i,c) sum += costsdel[i];
    return memo[now][del] = sum;
  }else{
    int sum = accumulate(costsdel.begin(), costsdel.end(), 0);
    vector<int> diffs(c);
    REP(i,c) diffs[i] = costs[i] - costsdel[i];

    sort(diffs.begin(), diffs.end());
    if(c >= 2) sum = min(sum, sum + diffs[0] + diffs[1]);

    return memo[now][del] = sum;
  }
}

int solve(const int n){
  int ans = 10000;
  REP(i,n){
    memset(memo, -1, sizeof(memo));
    ans = min(ans, dfs(i, -1, true));
    ans = min(ans, dfs(i, -1, false));
  }
  return ans;
}

int main(){
  const int c = getInt();
  REP(cc, c){
    const int n = getInt();
    REP(i,n) g[i].clear();

    REP(i,n-1){
      const int a = getInt() - 1;
      const int b = getInt() - 1;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    const int ans = solve(n);
    printf("Case #%d: %d\n", cc + 1, ans);
  }
  return 0;
}
