#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000+10;
vector<int> g[N];
int n;
int cnt[N];
void dfs(int u, int fa) {
    cnt[u] = 1;
    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        if (mx1 == -1 || cnt[v] > mx1) {
            mx2 = mx1;
            mx1 = cnt[v];
        }else if (cnt[v] > mx2) mx2 = cnt[v];
    }
    if (mx2 != -1 && mx1 != -1) cnt[u] = 1 + mx1 + mx2;
    else cnt[u] = 1;
}
void solve() {
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        dfs(i,-1);
        if (ans == -1 || n - cnt[i] < ans) ans = n - cnt[i];
    }
    printf("%d\n",ans);
}
int main() {
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas = 0; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) g[i].clear();
        for (int i = 0; i < n-1; i++) {
            int u, v; scanf("%d%d",&u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}
