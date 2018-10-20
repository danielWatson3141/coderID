#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define pb push_back
using namespace std;

typedef vector<int>::iterator IT;
int f[1005];
vector<int> vec[1005];
int sz[1005];
void dfs(int u, int par){
    sz[u] = 0;
    int res1=1e9, res2=1e9;
    for(IT e = vec[u].begin(); e != vec[u].end(); ++e){
        if(*e == par) continue;
        dfs(*e, u);
        sz[u] += sz[*e];
        if(f[*e]-sz[*e] < res1){
            res2 = res1;
            res1 = f[*e]-sz[*e];
        }
        else if(f[*e]-sz[*e] < res2)
            res2 = f[*e]-sz[*e];
    }

    if(res2!=1e9 && res1+res2<0) f[u] = res1+res2+sz[u];
    else f[u] = sz[u];

    sz[u]++;
}

int main(){
    freopen("1.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tt, i, n, l, r, cal=0;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        for(i=1;i<=n;++i) vec[i].clear();
        for(i=1;i<n;++i){
            scanf("%d%d",&l,&r);
            vec[l].pb(r);
            vec[r].pb(l);
        }

        int ans = n-1;
        for(i=1;i<=n;++i){
            dfs(i, -1);
            if(f[i] < ans) ans = f[i];
        }
        printf("Case #%d: %d\n", ++cal, ans);
    }
    return 0;
}
