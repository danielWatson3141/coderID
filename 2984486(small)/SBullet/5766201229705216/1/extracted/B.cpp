#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)

int f[1111][1111];
int n;
int c[1111], nxt[2222], g[2222], nm;

void addedge(int x, int y){
    g[nm] = y; nxt[nm] = c[x]; c[x] = nm; nm++;
}

int  dfs(int x, int p){
    if (~f[x][p]) return f[x][p];
    int ret = 0;
    f[x][p] = 0;
    for (int k = c[x]; ~k; k = nxt[k]){
        int y = g[k];
        if (y == p) continue;
        int ret2 = dfs(y, x);
        f[x][p] = max((ret2 && ret) ? ret2 + ret : 0, f[x][p]);
        ret = max(ret, ret2);
    }
    f[x][p] += 1;
    return f[x][p];
}

void Fate(int ca){
    scanf("%d", &n);
    
    memset(f, -1, sizeof f);
    memset(c, -1, sizeof c);
    nm = 0;
    REP(i, n - 1){
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    
    int ans = n - 1;
    REP(i, n) ans = min(ans, n - dfs(i, 0));
    printf("Case #%d: %d\n", ca, ans);
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int Ti;
    scanf("%d", &Ti);
    REP(z, Ti) Fate(z);
    //system("pause");
}
