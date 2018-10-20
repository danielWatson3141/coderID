#include <stdio.h>
#include <string.h>
#include <algorithm>
struct Edge {
    int s, t;
}edg[2010];
int edn[1010], ans, vis[1010];
bool cmp (const Edge & a, const Edge & b) {
    return a.s < b.s;
}
int dfs(int v) {
    vis[v] = 1;
    int n1=0, n2=0;
    for (int i=edn[v]; i<edn[v+1]; i++) {
        if (!vis[edg[i].t]) {
            int nas = dfs(edg[i].t);
            if (nas > n2) n2 = nas;
            if (n2 > n1) {n2 = n1; n1 = nas;}
        }
    }
    if (n2 == 0) return 1;
    return 1 + n1 + n2;
}
int main() {
    int cas, n;
    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        scanf("%d", &n);
        memset(edn, 0, sizeof(edn));
        for(int i=0; i<n-1; i++) {
            scanf("%d%d", &edg[i].s, &edg[i].t);
            edn[edg[i].s--]++;
            edn[edg[i].t--]++;
            edg[i+n-1].t = edg[i].s;
            edg[i+n-1].s = edg[i].t;
        }
        std::sort(edg, edg+2*n-2, cmp);
        for (int i=1; i<=n; i++)edn[i] += edn[i-1];
        ans = 0;
        for (int i=0; i<n; i++) {
            memset(vis, 0, sizeof(vis));
            int nas = dfs(i);
            if (nas > ans) ans = nas;
        }
        printf("Case #%d: %d\n", ii+1, n - ans);
    }
    return 0;
}