#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int MAXV = 1010;
int n, s[MAXV], dp[MAXV];
vector <int> adj[MAXV];
void solve(int fa,int v){
    s[v] = 1;
    dp[v] = 0;
    int l = adj[v].size(), max1 = -1, max2 = -1 ,u;
    for (int i=0;i<l;i++){
        u = adj[v][i];
        if (u == fa) continue;
        solve(v,u);
        s[v] += s[u];
        if (max1 == -1 || s[u]-dp[u] > max1){
            max2 = max1;
            max1 = s[u] - dp[u];
        }else if (max2 == -1 || s[u] - dp[u] > max2){
            max2 = s[u] - dp[u];
        }
    }
    if (max2 != -1){
        dp[v] = s[v] - 1 - max1 - max2;
    }else{
        dp[v] = s[v] - 1;
    }
    return ;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("B.out","w",stdout);
    int cases; scanf("%d",&cases);
    for (int it=1;it<=cases;it++){
        for (int i=0;i<MAXV;i++) adj[i].clear();
        printf("Case #%d: ",it);
        scanf("%d",&n);
        for (int i=0;i<n-1;i++){
            int v,u;
            scanf("%d%d",&v,&u);
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int res = n;
        for (int i=1;i<=n;i++){
            solve(i,i);
            res = min(res, dp[i]);
            //printf("dp[%d] = %d\n",i,dp[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
