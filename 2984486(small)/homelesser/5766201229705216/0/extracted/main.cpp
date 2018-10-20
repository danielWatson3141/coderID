#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1005;
const int INF = 2147483647;
int n;
vector<int> g[maxn];
int c[maxn];
int cnt;

int dfs(int src, int cur) {
    c[cur] = 1;
    for (int i = 0; i < g[cur].size(); i++)
        if (g[cur][i] != src)
            c[cur] += dfs(cur, g[cur][i]);
    return c[cur];
}

int rdfs(int src, int cur) {
    int x = INF, y = INF;
    int l, r;
    for (int i = 0; i < g[cur].size(); i++)
        if (g[cur][i] != src) {
            int t = rdfs(cur, g[cur][i]);
            if (t < x) {
                x = t;
                l = c[g[cur][i]];
            } else if (t < y) {
                y = t;
                r = c[g[cur][i]];
            }
        }
    if (x == INF && y == INF) return 0;
    if (y == INF) return c[cur] - 1;
    return x + y + c[cur] - l - r - 1;
}

int main() {
    // freopen("B-small-attempt2.in", "r", stdin);
    //  freopen("small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int ans = INF;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            dfs(0, i);
            ans = min(ans, rdfs(0, i));
        }
        printf("Case #%d: %d\n", cas, ans);

    }
    return 0;
}