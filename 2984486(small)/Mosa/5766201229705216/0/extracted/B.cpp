#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[1000];
int dp[1000], size[1000];
vector<int> adj[1000];
vector<int> rAdj[1000];

void dfs1(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(int v : adj[u]) {
    if(!vis[v]) {
      rAdj[u].push_back(v);
      dfs1(v);
    }
  }
}

int getSize(int u) {
  int &res = size[u];
  if(res != -1) return res;
  res = 1;
  for(int v : rAdj[u])
    res += getSize(v);
  return res;
}

int solve(int u) {
  if(rAdj[u].empty()) return 0;
  int &res = dp[u];
  if(res != -1) return res;
  res = 10000;
  if(rAdj[u].size() == 1) res = getSize(rAdj[u][0]);
  else if(rAdj[u].size() == 2) {
    res = 0;
    for(int v : rAdj[u]) res += solve(v);
  }else {
    int total = getSize(u) - 1;
    res = total;
    for(int i = 0; i < (int)rAdj[u].size(); ++i) {
      for(int j = i + 1; j < (int)rAdj[u].size(); ++j) {
        int v1 = rAdj[u][i];
        int v2 = rAdj[u][j];
        res = min(res, total - getSize(v1) - getSize(v2) + solve(v1) + solve(v2));
      }
    }
  }
  return res;
}

int main() {
  freopen("B-small-attempt0.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) adj[i].clear();
    for(int i = 1; i < n; ++i) {
      int x, y; scanf("%d %d", &x, &y); --x; --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int ans = n;
    for(int root = 0; root < n; ++root) {
      for(int i = 0; i < n; ++i) {
        rAdj[i].clear();
        vis[i] = 0; dp[i] = size[i] = -1;
      }
      dfs1(root);
      ans = min(ans, solve(root));
    }
    printf("Case #%d: %d\n", tst, ans);
  }
  return 0;
}
