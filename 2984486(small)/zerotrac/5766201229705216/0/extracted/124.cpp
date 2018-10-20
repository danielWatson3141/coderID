#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

const int inf=999999999;

vector <int> v[1010];

bool used[1010];
int ncnt[1010],dp[1010];
int T,n,x,y,cs=0;

void Dfs(int node)
{
	used[node]=true;
	int sz=0,nn=0;
	for(int i=0;i<v[node].size();i++)
	{
		int u=v[node][i];
		if(!used[u])Dfs(u),sz++;
		nn+=ncnt[u];
	}
	if(!sz){ncnt[node]=1;return;}	
	ncnt[node]=nn+1;
	if(sz==1){dp[node]=ncnt[node]-1;return;}
	int max1=0,max2=0;
	for(int i=0;i<v[node].size();i++)
	{
		int u=v[node][i];
		if(ncnt[u]-dp[u]>max1)
		{
			max2=max1;
			max1=ncnt[u]-dp[u];
		}
		else if(ncnt[u]-dp[u]>max2)max2=ncnt[u]-dp[u];
	}
	dp[node]=ncnt[node]-max1-max2-1;
}
int main()
{
	freopen("124.in","r",stdin);
	freopen("124.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			v[x].pb(y),v[y].pb(x);
		}
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			memset(used,false,sizeof(used));
			memset(dp,0,sizeof(dp));
			memset(ncnt,0,sizeof(ncnt));
			Dfs(i);
			//cout<<"==============\n";
			//for(int j=1;j<=n;j++)cout<<ncnt[j]<<" "<<dp[j]<<endl;
			//cout<<"==============\n";
			ans=min(ans,dp[i]);
		}
		printf("Case #%d: %d\n",++cs,ans);
	}
	return 0;
}
