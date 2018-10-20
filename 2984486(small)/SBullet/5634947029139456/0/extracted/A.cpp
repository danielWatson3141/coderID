#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)

int n, L;
int s[2][155][55];
char st[55];
string f[155], t[155];
int op[55];

bool cks(int op[]){
    REP(i, n) f[i].clear(), t[i].clear();
    REP(i, n) REP(j, L) t[i] += char((s[0][i][j] ^ op[j]) + '0');
    sort(t + 1, t + 1 + n);
    REP(i, n) REP(j, L) f[i] += char(s[1][i][j] + '0');
    sort(f + 1, f + 1 + n);
    REP(i, n) if (f[i] != t[i]) return 0;
    return 1;
}

void Fate(int ca){
    scanf("%d%d", &n, &L);
    REP(i, n){
        scanf("%s", st);
        REP(j, L) s[0][i][j] = st[j - 1] - '0';
    }
    REP(i, n){
        scanf("%s", st);
        REP(j, L) s[1][i][j] = st[j - 1] - '0';
    }
    int ans = L + 1;
    REP(i, n){
        REP(j, L) op[j] = s[0][1][j] ^ s[1][i][j];
        if (cks(op)){
            int cnt = 0;
            REP(j, L) cnt += op[j];
            ans = min(ans, cnt);
        }
    }
    if (ans < L)
        printf("Case #%d: %d\n", ca, ans);
    else printf("Case #%d: NOT POSSIBLE\n", ca);
}

int main(){
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int Ti;
    scanf("%d", &Ti);
    REP(z, Ti) Fate(z);
    //system("pause");
}
