#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 1000
using namespace std;

vector<int> adj[MAXN+1];
int n;

int DFS(int x,int p)
{
    vector<int> v;
    int i,y;
    v.clear();
    for(i=0;i<adj[x].size();i++)
    {
        y=adj[x][i];
        if(y!=p)
        {
            v.push_back(DFS(y,x));
        }
    }
    if(v.size()<2)
    {
        return 1;
    }
    sort(v.begin(),v.end(),greater<int>());
    return v[0]+v[1]+1;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int c,t,i,x,y,maxs;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        maxs=0;
        for(i=1;i<=n;i++)
        {
            maxs=max(maxs,DFS(i,0));
        }
        printf("Case #%d: %d\n",c+1,n-maxs);
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}
