#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> adj[1001];
int ans,dp[1001],sz[1001],t;

void init()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n;++i) adj[i].clear();
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int u,int fa)
{
	sz[u]=1;
	dp[u]=0;
	vector<int> vec;
	for(int i=0;i<adj[u].size();++i)
	{
		int v=adj[u][i];
		if(v==fa) continue;
		vec.push_back(dfs(v,u)-sz[v]);
		sz[u]+=sz[v];
	}
	if(vec.size()<=1) dp[u]=sz[u]-1;
	else 
	{
		sort(vec.begin(),vec.end());
		dp[u]=sz[u]-1+vec[0]+vec[1];
	}
	//cout<<u<<" "<<dp[u]<<endl;
	return dp[u];
}
int ca=1;
void solve()
{
	ans=1000;
	for(int i=1;i<=n;++i) ans=min(ans,dfs(i,-1));
	printf("Case #%d: %d\n",ca++,ans);
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		init();
		solve();
	}
}


