#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> g[5005];
int n;
int dp[5005];

void DFS(int cur, int fa)
{
    int cnt=0;

    int len=g[cur].size();
    for(int i=0; i<len; i++)
    {
        if (g[cur][i]==fa)
            continue;
        cnt++;
    }
    dp[cur]=1;
    if (cnt<=1)
        return;
    int Max1=0,Max2=0;
    for(int i=0; i<len; i++)
    {
        int son=g[cur][i];
        if (son == fa)
            continue;
        DFS(son, cur);
        if (dp[son]>Max1)
        {
            Max2=Max1;
            Max1=dp[son];
        }
        else if (dp[son]>Max2)
        {
            Max2=dp[son];
        }
    }
    dp[cur]+=Max1+Max2;
}

int main()
{
    int cas,ca=1,ans,node1,node2;

    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i=0; i<=n; i++)
            g[i].clear();
        for (int i=1;i<n;i++)
        {
            scanf("%d%d",&node1,&node2);
            g[node1].push_back(node2);
            g[node2].push_back(node1);
        }
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            memset(dp,0,sizeof(dp));
            DFS(i,0);
            if(ret<dp[i])
               ret=dp[i];
        }
        ans=n-ret;
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}
