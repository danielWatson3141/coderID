#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
    int from,to;
};
vector<edge>edges;
vector<int>g[1111];
int n;
int cnt;
int c[1111];
void add(int from,int to)
{
    edges.push_back((edge)
    {
        from,to
    });
    g[from].push_back(edges.size()-1);
}
void dfs(int u,int fa)
{
    int m1=0,m2=0;
    cnt++;
    int size=g[u].size();
    for(int i=0; i<size; i++)
    {
        edge &e=edges[g[u][i]];
        if(e.to==fa)continue;
        dfs(e.to,u);
        if(c[e.to]>m1)
        {
            m2=m1;
            m1=c[e.to];
        }
        else if(c[e.to]>m2)m2=c[e.to];
    }
    if(m2==0)
    {
        c[u]=1;
    }
    else c[u]=m1+m2+1;
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int u,v;
    int ca=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)g[i].clear();
        edges.clear();
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        int ans=n;
        for(int i=1; i<=n; i++)
        {
            memset(c,0,sizeof(c));
            dfs(i,-1);
            //cout<<cnt<<endl;
            //cout<<c[i]<<endl;
            ans=min(ans,n-c[i]);
        }
        printf("Case #%d: %d\n",ca++,ans);
        //cout<<ans<<endl;
    }
    return 0;
}
