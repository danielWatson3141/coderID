#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 1111;
const int maxm = 5555;
int e_;
int st[maxn], ve[maxm], nx[maxm];
void init_edge() {
    e_ = 0;
    memset(st, 0, sizeof(st));
}
inline void add(int x, int y) {
    ve[++e_] = y;
    nx[e_] = st[x];
    st[x] = e_;
}
bool visited[maxn];
const int inf = 1000000000;
int f[maxn];
int g[maxn];
int n;
void dfs(int v) {
    visited[v] = true;
    int cnt = 0;
    g[v] = 1;
    int min1 = inf, min2 = inf;
    for (int i = st[v]; i; i = nx[i]) {
        if (visited[ve[i]]) continue;
        dfs(ve[i]);
        g[v] += g[ve[i]];
        cnt += 1;
        if (f[ve[i]] - g[ve[i]]< min1) {
            min2 = min1;
            min1 = f[ve[i]] - g[ve[i]];
        } else if (f[ve[i]] - g[ve[i]]< min2) {
            min2 = f[ve[i]] - g[ve[i]];
        }
    }
    if (cnt < 2) f[v] = g[v] - 1;
    else f[v] = g[v] + min1 + min2 - 1;
}


int main() {
    freopen("bl2014.in", "r", stdin);
    freopen("bl2014.out", "w", stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init_edge();
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        int ans = inf;
        for (int v0 = 1; v0 <= n; ++v0) {
            memset(visited, 0 ,sizeof(visited));
            for (int i = 1; i <= n; ++i) g[i] = f[i] = 0;
            dfs(v0);
            ans = min(ans, f[v0]);
        }
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}
