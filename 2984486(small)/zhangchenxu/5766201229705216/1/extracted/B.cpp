#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>edge[1100];
bool cmp(int a,int b)
{
    return a>b;
}
int dfs(int u,int fa)
{
    vector<int>res;
    for(int i=0;i<edge[u].size();i++)
        if(edge[u][i]!=fa)
    {
        res.push_back(dfs(edge[u][i],u));
    }
    if(res.size()==0||res.size()==1)return 1;
    sort(res.begin(),res.end(),cmp);
    return res[0]+res[1]+1;
}
int main()
{
   // freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        if(n==2){printf("Case #%d: 1\n",cas++);continue;}
        int mmax=0;
        for(int i=1;i<=n;i++)
        {
            mmax=max(mmax,dfs(i,-1));
        }
        printf("Case #%d: %d\n",cas++,n-mmax);
    }
}
