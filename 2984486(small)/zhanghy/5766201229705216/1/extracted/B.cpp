#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 2500;


int T,N;
int l,next[maxn],to[maxn],now[maxn],f[maxn];

void add(int x,int y) {
    l++; to[l] = y; next[l] = now[x]; now[x] = l;
    l++; to[l] = x; next[l] = now[y]; now[y] = l;
}

void dfs(int x,int fa) {
    int son = 0;
    for (int i = now[x];i != 0;i = next[i]) {
        if (to[i] != fa) { son++; dfs(to[i],x); }
    }
    if (son == 1) f[x] = 1;
    else {
        int t1 = 0,t2 = 0;
        for (int i = now[x];i != 0;i = next[i]) {
            if (to[i] != fa) {
                if (f[to[i]] > t1) {t2 = t1; t1 = f[to[i]]; }
                else if (f[to[i]] > t2)  t2 = f[to[i]];
            }
        }
        f[x] = t1+t2+1;
    }
}

int main() {
    freopen("B2.in","r",stdin);
    freopen("B2.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d",&N);
        l = 0;
        for (int i = 1;i <= N; i++) now[i] = 0;
        for (int i = 1;i <= N-1; i++) {
            int u,v; scanf("%d%d",&u,&v);
            add(u,v);
        }
        int ans = 0;
        for (int i = 1;i <= N; i++) {
            dfs(i,0);
            ans = max(ans,f[i]);
        }
        ans = N-ans;
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
