#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define maxn 1005
#define INF 1000000000
vector <int> edge[maxn];
vector <int>::iterator it;
int dep[maxn],num[maxn];
void dfs(int u,int fa)
{
    int sz = edge[u].size();
    vector <int> tmp;
    for(int i=0;i<sz;i++)
    {
        int v = edge[u][i];
        if(v == fa) continue;
        dfs(v,u);
        tmp.push_back(num[v]);
    }
    if((int)tmp.size() > 2)
    {
        sort(tmp.begin(),tmp.end());
        it = tmp.begin();
        it++;
        it++;
        for(;it!=tmp.end();it++)
        {
            num[u]+=*it+1;
        }
    }
	else if((int)tmp.size() == 2)
	{
		for(it=tmp.begin();it!=tmp.end();it++)
        {
            num[u]+=*it;
        }
	}
	else
	{
		for(it=tmp.begin();it!=tmp.end();it++)
        {
            num[u]+=*it+1;
        }
	}
}
int main()
{
    int T,cas=1,n,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(dep,0,sizeof(int)*(n+2));
        for(int i=1;i<=n;i++)
            edge[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int res=INF;
        for(int i=1;i<=n;i++)
        {
            memset(num,0,sizeof(num));
            dfs(i,-1);
            if(num[i]<res) res=num[i];
        }
        printf("Case #%d: %d\n",cas++,res);
    }
    return 0;
}
