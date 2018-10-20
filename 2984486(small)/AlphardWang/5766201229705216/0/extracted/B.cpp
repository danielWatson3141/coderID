#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> edges[1200];
bool vis[1200];

void input(){
  scanf("%d", &n);
  for (int i = 1; i <= n; ++ i){
    edges[i].clear();
    vis[i] = false;
  }
  int a, b;
  for (int i = 1; i < n; ++ i){
    scanf("%d%d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

int dfs(int v, bool isroot){
  vis[v] = true;
  int ret, limit = 3, m1 = 0, m2 = 0;
  if (isroot) -- limit;
  if (edges[v].size() < limit){
    ret = 1;
  } else {
    for (int i = 0; i < edges[v].size(); ++ i){
      int vt = edges[v][i];
      if (!vis[vt]){
        int t = dfs(vt, false);
        if (t > m1) {
          m2 = m1;
          m1 = t;
        } else if (t > m2){
          m2 = t;
        }
      }   
    }
    ret = 1 + m1 + m2;
  }
  vis[v] = false;
  return ret;
}

void solve() {
  int ans = 0;
  for (int root = 1; root <= n; ++ root){
    int t = dfs(root, true);
    if (ans < t) ans = t;
  }
  printf("%d\n", n - ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ ca) {
    input();
    printf("Case #%d: ", ca);
    solve();
  }
  return 0;
}
