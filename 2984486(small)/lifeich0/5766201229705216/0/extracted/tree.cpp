#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 27;
int next[N+N],g[N],y_[N+N],u[N],u1[N],d[N],ds[N];
int ST,n,ans,tot;
void ins(int i, int j) {
    next[++tot] = g[i]; g[i] = tot; y_[tot] = j;
}
int dfs0(int r) {
    if (u[r] || u1[r]) return 0;
    u1[r] = 1;
    int ret = 1;
    for (int p = g[r]; p; p = next[p]) ret += dfs0(y_[p]);
    return ret;
}
void dfs(int r, int K) {
    if (K >= ans) return ;
    if (r > n) {
        fill(ds, ds + 4, 0);
        fill(u1, u1 + n + 1, 0);
        for (int i = 1,fl = 1; i <= n; ++i)
            if (!u[i]) {
                if (fl) {
                    fl = 0;
                    if (dfs0(i) != n - K) return ;
                }
                if (d[i] > 0 && d[i] < 4) ++ ds[d[i]];
                else return ;
            }
        if (ds[2] != 1) return ;
        ans = K;
        return ;
    }
    dfs(r + 1, K);
    for (int p = g[r]; p; p = next[p]) -- d[y_[p]];
    ++ u[r];
    dfs(r + 1, K + 1);
    -- u[r];
    for (int p = g[r]; p; p = next[p]) ++ d[y_[p]];
}
int main() {
    scanf("%d", &ST);
    for (int TT = 1; TT <= ST; ++TT) {
        scanf("%d", &n);
        tot = 0;
        fill(g, g + n + 1, 0);
        fill(d, d + n + 1, 0);
        for (int i = 1,xt,yt; i < n; ++i) {
            scanf("%d%d", &xt, &yt);
            ins(xt, yt), ins(yt, xt);
            ++ d[xt], ++ d[yt];
        }
        ans = n - 1;
        fill(u, u + n + 1, 0);
        dfs(1, 0);
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}
