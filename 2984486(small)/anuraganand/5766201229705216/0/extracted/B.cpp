#include <bits/stdc++.h>

using namespace std;

vector <int> g[1111];
bool vis[1111];
bool bad[1111];

int N;

int dfs(int u) {
  vis[u] = true;
  int size = 1;
  int max1 = 0, max2 = 0;
  int numChild = 0;
  for(int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if(!vis[v]) {
      numChild++;
      int sub = dfs(v);
      if(max1 < sub) {
        max2 = max1;
        max1 = sub;
      } else if(max2 < sub) {
        max2 = sub;
      }
    }
  }

  if(max2 > 0) {
    return max1 + max2 + 1;
  } else {
    return 1;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);

  for(int testNo = 1; testNo <= tests; testNo++) {

    printf("Case #%d: ", testNo);
    scanf("%d", &N);

    for(int i = 0; i <= N; i++)
      g[i].clear();

    for(int i = 0; i < N - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);

    }


    int ans = N - 1;

    for(int i = 0; i < N; i++) {
      memset(vis, 0, sizeof(vis));
      memset(bad, 1, sizeof(bad));

      int cur = N - dfs(i);

      ans = min(ans, cur);
    }
   
    printf("%d\n", ans);
  }
  return 0;
}