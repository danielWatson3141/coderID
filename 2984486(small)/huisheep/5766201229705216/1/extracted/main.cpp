#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1010;
struct node
{
    int v,next;
}e[N<<1];
int pre[N],kk,n,dp[N],sum[N];
int addEdge(int u,int v)
{
    e[kk].v=v; e[kk].next=pre[u]; pre[u]=kk++;
    return 0;
}
int dfs(int u,int fa)
{
    sum[u]=1;
    int cnt=0;
    for(int i=pre[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        sum[u]+=sum[v];
        cnt++;
    }
    if(cnt==1)
    {
        dp[u]=sum[u]-1; return dp[u];
    }
    if(cnt==0)
    {
        dp[u]=0; return 0;
    }
    int m1=-1,m2=-1;
    for(int i=pre[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa) continue;
        if(sum[v]-dp[v]>m1)
        {
            m2=m1; m1=sum[v]-dp[v];
        }
        else if(sum[v]-dp[v]>m2)
            m2=sum[v]-dp[v];
    }
    dp[u]=sum[u]-1-m1-m2;
    return dp[u];
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int tt,ii,i;
    scanf("%d",&tt);
    for(ii=1;ii<=tt;ii++)
    {
        scanf("%d",&n);
        memset(pre,-1,sizeof(pre));
        kk=0;
        for(i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        int ans=N;
        for(i=1;i<=n;i++)
        {
            int tot=dfs(i,0);
            ans=min(ans,tot);
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
