#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 153;
LL a0[N],a1[N],wk;
char s0[N][N],s1[N][N],w[N];
int ST,n,L,ans;
LL trans(char *s) {
    LL ret = 0;
    for (int i = 0; i < L; ++i) ret += ret + (s[i] == '1');
    return ret;
}
bool eql(int i, int j) {
    return (a0[i] ^ wk) == a1[j];
}
void work(int k) {
    int ret = 0;
    for (int i = 0; i < L; ++i) {
        w[i] = s0[k][i] != s1[1][i] ? '1' : '0';
        ret += s0[k][i] != s1[1][i];
    }
    wk = trans(w);
    for (int i = 1,fl; i <= n; ++i) {
        fl = 0;
        for (int j = 1; j <= n && !fl; ++j) fl = eql(i, j);
        if (!fl) return;
    }
    ans = min(ans, ret);
}
int main() {
    scanf("%d", &ST);
    for (int TT = 1; TT <= ST; ++TT) {
        scanf("%d%d", &n, &L);
        for (int i = 1; i <= n; ++i) scanf("%s", s0[i]);
        for (int i = 1; i <= n; ++i) scanf("%s", s1[i]);
        for (int i = 1; i <= n; ++i) a0[i] = trans(s0[i]);
        for (int i = 1; i <= n; ++i) a1[i] = trans(s1[i]);
        ans = L + 1;
        for (int i = 1; i <= n; ++i) work(i);
        printf("Case #%d: ", TT);
        if (ans <= L) printf("%d\n", ans);
        else puts("NOT POSSIBLE");
    }
    return 0;
}
