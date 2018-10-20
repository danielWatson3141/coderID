#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1013;
int next[N*10],g[N*10],y_[N*10],f[N*10];
int ST,n,tot,ans;
void ins(int i, int j) {
    next[++tot] = g[i]; g[i] = tot; y_[tot] = j;
}
int dp(int P) {
    int r = y_[P], m0(0), m1(0);
    for (int p = g[r],t; p; p = next[p])
        if (p ^ P ^ 1) {
            t = dp(p);
            if (t > m0) {
                m1 = m0;
                m0 = t;
            } else m1 = max(m1, t);
        }
    f[P] = 1;
    if (m1) f[P] += m0 + m1;
    return f[P];
}
int main() {
    scanf("%d", &ST);
    for (int TT = 1; TT <= ST; ++TT) {
        scanf("%d", &n);
        tot = 1;
        fill(g, g + n + 2, 0);
        for (int i = 1,xt,yt; i < n; ++i) {
            scanf("%d%d", &xt, &yt);
            ins(xt, yt), ins(yt, xt);
        }
        for (int i = 1; i <= n; ++i) ins(n + 1, i);
        fill(f, f + n * 3, 0);
        ans = 1;
        for (int i = n + n; i < n * 3; ++i) ans = max(ans, dp(i));
        printf("Case #%d: %d\n", TT, n - ans);
    }
    return 0;
}
