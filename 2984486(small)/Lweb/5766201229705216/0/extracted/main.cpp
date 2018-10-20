//Immanuel
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
int head[1005];
struct Edge
{
    int next,to;
}ed[2005];
int ecnt;

inline void addedge(int u,int v)
{
    ed[ecnt].next=head[u];
    ed[ecnt].to=v;
    head[u]=ecnt++;
}

int cost[1005],sz[1005];

void dfs(int u,int fa)
{
    sz[u]=1; cost[u]=0;
    int cnt=0;
    for(int e=head[u];~e;e=ed[e].next)
    {
        int v=ed[e].to;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        cost[u]+=cost[v];
        ++cnt;
    }
    if(cnt!=0&&cnt!=2)
    {
        if(cnt>2)
        {
            int m1=0,m2=0;
            for(int e=head[u];~e;e=ed[e].next)
            {
                int v=ed[e].to;
                if(v==fa) continue;
                int add=sz[v]-cost[v];
                cost[u]+=add;
                if(add>m1)
                {
                    m2=m1;
                    m1=add;
                }
                else if(add>m2) m2=add;
            }
            cost[u]-=m1+m2;
        }
        else
        {
            for(int e=head[u];~e;e=ed[e].next)
            {
                int v=ed[e].to;
                if(v==fa) continue;
                cost[u]-=cost[v];
                cost[u]+=sz[v];
            }
        }
    }
}

inline int solve(int root)
{
    dfs(root,root);
    return cost[root];
}

int main()
{
    int T;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        int n;
        scanf("%d",&n);
        memset(head,-1,sizeof(head));
        ecnt=0;
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        int ans=INF;
        for(int i=1;i<=n;++i) ans=min(ans,solve(i));
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
