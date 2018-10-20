#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = (int)1e3+10;

int _;
vector<int> e[MAXN] ;
int n;
int tot[MAXN] ;
int dp[MAXN] ;

void dfs(int u,int fa){
    tot[u] = 1 ;
    vector<int> te ;
    for (int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if (v==fa) continue ;
        dfs(v,u);
        te.push_back(v) ;
        tot[u] += tot[v] ;
    }
    if ((int)te.size() == 0){
        dp[u] = 0;
        tot[u] = 1 ;
        return ;
    }
    if ((int)te.size() == 1)
    {
        dp[u] = tot[u]-1 ;
        return ;
    }
    for (int i=0;i<te.size();i++)
        for (int j=i+1;j<te.size();j++){
            dp[u] = min(dp[u] , dp[te[i]]+dp[te[j]]+tot[u]-tot[te[i]]-tot[te[j]]-1) ;
    }
}

int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&_);
    int cas=0;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int ans = 0x3f3f3f3f;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) dp[j]=0x3f3f3f3f;
            //cout<<"i="<<i<<endl;
            dfs(i,-1);
            //cout<<i<<" "<<dp[i]<<endl;
            ans = min(ans,dp[i]);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
