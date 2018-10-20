#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 1010
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
vector<int>ed[N];
int dp[N][2];
int f[N][2];
void dfs(int u,int pre)
{
    int i;
    int ans = 0;
    int o = 0;
    int k = 0;
    for(i = 0 ;i < ed[u].size() ; i++)
    {
        int v = ed[u][i];
        if(v==pre) continue;
        dfs(v,u);
        ans+=dp[v][0];
        k++;
    }
    if(k==0)
    {
        dp[u][0] = 1;
        dp[u][1] = 0;
        return ;
    }
    else if(k==1)
    {
        dp[u][0] = ans+1;
        dp[u][1] = ans;
        return ;
    }
    for(i = 0 ;i <= ed[u].size() ; i++)
    f[i][0] = f[i][1] = f[i][2] = INF;
    for(i = 0; i < ed[u].size() ; i++)
    {
        int v = ed[u][i];
        if(v==pre) {
            continue;
        }
        if(o==0)
        {
            f[o][0] = dp[v][0];
            f[o][1] = dp[v][1];
        }
        else
        {
            f[o][0] = dp[v][0]+f[o-1][0];
            f[o][1] = min(dp[v][0]+f[o-1][1],dp[v][1]+f[o-1][0]);
            f[o][2] = min(dp[v][0]+f[o-1][2],dp[v][1]+f[o-1][1]);
        }
        o++;
    }
    dp[u][1] = f[o-1][2];
    dp[u][0] = ans+1;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,i,j,n;
    int kk=0;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i <= n; i++)
        ed[i].clear();
        for(i = 1 ;i < n ;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        int minz = INF;
        for(i =1 ;i <= n ;i++)
        {
            for(j = 1; j <= n ;j++)
            {
                dp[j][1] = INF;
                dp[j][0] = 0;
            }
            dfs(i,-1);
            minz = min(dp[i][1],minz);
        }
        printf("Case #%d: %d\n",++kk,minz);
    }
    return 0;
}
