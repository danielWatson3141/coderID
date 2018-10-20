#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MaxN 2200
int top, g[MaxN], nxt[MaxN], head[MaxN], sz[MaxN], dp[MaxN], deg[MaxN];

void add_edge(int a, int b) {
    g[top] = b, nxt[top] = head[a], head[a] = top++;
}

void dfs(int u, int p) {
    int sons = 0;
    int rec[2] = {-1, -1};
    for (int i = head[u]; i; i = nxt[i]) {
        if (g[i] == p) continue;
        dfs(g[i], u);
        //sz[u] += sz[g[i]];
        ++sons;
        if (dp[g[i]] > rec[1]) rec[1] = dp[g[i]];
        if (rec[1] > rec[0]) swap(rec[0], rec[1]);
    }
    if (sons >= 2) dp[u] = rec[0] + rec[1] + 1;
    else dp[u] = 1;
}

int count_bit(int x) {
    int ret = 0;
    while (x) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
int mask;
int bf(int n) {
    int ret = n-1;
    for (mask = 1; mask < (1<<n); ++mask) {
        int nodes = 0, edges = 0;
        bool has = false;
        bool fail = false;
        for (int i = 1; i <= n; ++i) if (mask&(1<<(i-1))) {
            int dg = 0;
            ++nodes;
            for (int j = head[i]; j; j = nxt[j]) if (mask&(1<<(g[j]-1))) {
                ++dg;
            }
            edges += dg;
            if (dg == 1 || dg == 3) continue;
            if (dg == 2 && !has) has = true;
            else fail = true;
        }
        if ((nodes-1)*2 != edges) fail = true;
        if (!fail && has) ret = min(ret, n-count_bit(mask));
    }
    return ret;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        memset(head, 0, sizeof(head)); top = 1;
        int n;
        scanf("%d", &n);
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            ++deg[a]; ++ deg[b];
            add_edge(a, b);
            add_edge(b, a);
        }
        int ans = n-1;
        for (int i = 1; i <= n; ++i) if (deg[i] >= 2) {
            memset(dp, 0, sizeof(dp));
//            memset(sz, 0, sizeof(sz));
            dfs(i, 0);
            ans = min(ans, n - dp[i]);
        }
//        if (bf(n) != ans) {
//                puts("ERROR");
//        printf("%d < %d\n", bf(n), ans);
//            for (int i = 1; i <= n; ++i) for (int j = head[i]; j; j = nxt[j]) if (i < g[j]) printf("%d %d\n", i, g[j]);
//        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
