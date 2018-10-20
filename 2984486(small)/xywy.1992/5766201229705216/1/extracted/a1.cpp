#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

int T, n, f[1 << 10][2];
std::vector<int> adj[1 << 10];

#define foreach(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)

int dfs(int u, int p) {
    f[u][0] = 1;
    foreach(i, adj[u]) {
        int v = *i;
        if(v == p) {
            continue;
        }
        dfs(v, u);
        f[u][0] += f[v][0];
    }
    f[u][1] = f[u][0] - 1;
    foreach(i, adj[u]) {
        foreach(j, adj[u]) {
            int x = *i, y = *j;
            if(x == y || x == p || y == p || f[x][1] == INT_MAX || f[y][1] == INT_MAX) {
                continue;
            }
            f[u][1] = std::min(f[u][1], f[x][1] + f[y][1] + (f[u][0] - 1 - f[x][0] - f[y][0]));
        }
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &T);
    for(int test = 1; test <= T; ++test) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for(int i = 0, u, v; i < n - 1; ++i) {
            scanf("%d %d", &u, &v);
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            dfs(i, -1);
            ans = std::min(ans, f[i][1]);
        }
        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
