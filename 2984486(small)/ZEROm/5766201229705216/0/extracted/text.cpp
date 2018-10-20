#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1005;
vector<int>G[maxn];
int sz[maxn],h;
int dfs(int x,int fa)
{
    int num[maxn]={0};
    for(int i=0;i<G[x].size();++i)
    if(G[x][i]!=fa)
    {
        num[i]=dfs(G[x][i],x);
    }
    sort(num,num+G[x].size());
    if(num[G[x].size()-2]&&G[x].size()>=2)return 1+num[G[x].size()-2]+num[G[x].size()-1];
    return 1;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<n;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ans=max(dfs(i,0),ans);
        }
        printf("Case #%d: %d\n",++Case,n-ans);
    }
}
