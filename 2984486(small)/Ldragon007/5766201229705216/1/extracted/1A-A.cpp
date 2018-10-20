#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, d[1010];
bool vis[1010];
vector<int> e[1010];

int work(int t) {
    vis[t] = true;
    int cnt = 0, max1 = 0, max2 = 0;
    for (int i = 0; i < e[t].size(); i ++ )
        if (vis[e[t][i]]) continue;
        else {
            int dd = work(e[t][i]);
            if (dd > max1) {
                max2 = max1;
                max1 = dd;
            }
            else if (dd > max2) {
                max2 = dd;
            }
            cnt ++ ;
        }
    if (cnt < 2) d[t] = 1;
    else d[t] = max1 + max2 + 1;
    return d[t];
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            e[i].clear();
        for (int i = 1; i < n; i ++ ) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = n;
        if (n == 2) {
            ans = 1;
        }
        else {
           for (int i = 1; i <= n; i ++ )
               if (e[i].size() >= 2) {
                   memset(vis, 0, sizeof(vis));
                   memset(d, 0, sizeof(d));
                   ans = min(ans, n - work(i));
               }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
