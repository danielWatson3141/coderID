#include <cstdio>
#include <cstring>

const int MAXN = 2222;

int cs, tot, h[MAXN], p[MAXN], nxt[MAXN], f[MAXN], s[MAXN];

inline void addedge(int x, int y) {
    p[++tot] = y, nxt[tot] = h[x], h[x] = tot;
}

void dp(int x, int pre) {
    int cnt = s[x] = 0, mn1 = MAXN, mn2 = MAXN;
    for (int k = h[x]; k; k = nxt[k])
        if (p[k] != pre) {
            dp(p[k], x);
            ++cnt;
            if (f[p[k]] - s[p[k]] < mn1)
                mn2 = mn1, mn1 = f[p[k]] - s[p[k]];
            else if (f[p[k]] - s[p[k]] < mn2)
                mn2 = f[p[k]] - s[p[k]];
            s[x] += s[p[k]];
        }
    f[x] = s[x];
    if (cnt > 1 && s[x] + mn1 + mn2 < f[x])
        f[x] = s[x] + mn1 + mn2;
    ++s[x];
}

inline void work() {
    int n;
    scanf("%d", &n);
    memset(h, tot = 0, sizeof h);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    int ans = MAXN;
    for (int i = 1; i <= n; ++i) {
        dp(i, 0);
        if (f[i] < ans)
            ans = f[i];
    }
    printf("Case #%d: %d\n", ++cs, ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        work();
    return 0;
}
