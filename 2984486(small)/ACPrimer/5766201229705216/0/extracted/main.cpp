#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
using namespace std;
const int maxn = 16;
int n;
int g[maxn][maxn],d[maxn],dd[maxn];
int vis[maxn];
int dfs(int u)
{
    int t;
    if(dd[u]<2) return 1;
    int q[2];
    q[0]=q[1]=0;
    for(int i=0;i<d[u];i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            dd[v]--;
            t=dfs(v);
            if(t>q[0])
            {
                q[1]=q[0];
                q[0]=t;
            }
            else if(t>q[1])
            {
                q[1]=t;
            }
        }
    }
    return q[0]+q[1]+1;
}
int main()
{
    int T,ncase=0,u,v;
    scanf("%d",&T);
    while(T--){
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            g[u][d[u]]=v;
            g[v][d[v]]=u;
            d[u]++; d[v]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memcpy(dd,d,sizeof(d));
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            int r=dfs(i);
            if(r>ans) ans=r;
            /*if(ans<minAns)
            {
                idx=i;
                minAns=ans;
            }*/
            if(ans==n) break;
        }
        printf("Case #%d: %d\n",++ncase,n-ans);
    }
    return 0;
}

