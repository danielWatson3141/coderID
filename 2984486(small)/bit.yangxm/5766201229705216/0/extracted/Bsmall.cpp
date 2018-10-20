#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 32
#define INF 10000000

using namespace std;

int mat[MAX][MAX], deg[MAX];
bool vis[MAX];

int bitCnt(int x) {
    int ret = 0;
    for ( ; x; x >>= 1) ret += (x & 1);
    return ret;
}

int dfs(int n, int x, int pre, int s) {
    int i, c = ~pre ? 1 : 0, ret = 1;

    vis[x] = true;
    for (i = 0; i < n; ++i) {
        if (mat[x][i] && !vis[i]) {
            ret += dfs(n, i, x, s); ++c;
        }
    }
    ++deg[c];

    return ret;
}

int check(int n, int s) {
    int i, cnt, ret = INF;

    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; ++i) {
        if ((s >> i) & 1) vis[i] = true;
    }
    for (i = 0; i < n && vis[i]; ++i);
    if (i == n) return n;
    memset(deg, 0, sizeof(deg));
    cnt = dfs(n, i, -1, s);

    //printf("n = %d, s = %d, c = %d, cnt = %d\n", n, s, bitCnt(s), cnt);

    //for (i = 0; i < n; ++i) {
    //    printf("i = %d, deg = %d\n", i, deg[i]);
    //}

    if (cnt + bitCnt(s) < n) return INF;
    if (cnt == 1) return bitCnt(s);
    for (i = 4; i < n; ++i) {
        if (deg[i]) return INF;
    }
    if (deg[2] != 1) return INF;

    return bitCnt(s);
}

int main() {
    int t, ct = 0, n, x, y, i, ans, s;

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        memset(mat, 0, sizeof(mat));
        scanf("%d", &n);
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &x, &y);
            mat[x - 1][y - 1] = mat[y - 1][x - 1] = 1;
        }
        ans = n; s = (1 << n);
        for (i = 0; i < s; ++i) {
            ans = min(ans, check(n, i));
        }
        printf("Case #%d: %d\n", ++ct, ans);
    }

    return 0;
}
