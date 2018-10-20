#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 1002
#define INF (int)1e9
using namespace std;

// Edge
vector<int>edg[MAXN];

// Dp
int dp[MAXN][MAXN];
bool used[MAXN][MAXN];
int find(int now,int par)
{
	int i,lc;
	int lis[MAXN];
	if(used[now][par]) return dp[now][par];
	lc=0;
	used[now][par]=true;
	for(i=0;i<(int)edg[now].size();i++)
	{
		if(edg[now][i]==par) continue;
		lis[lc++]=find(edg[now][i],now);
	}
	if(!lc) dp[now][par]=0;
	else
	{
		if(lc==1) dp[now][par]=lis[0]+1;
		else
		{
			dp[now][par]=0;
			sort(lis,lis+lc);
			for(i=0;i<lc-2;i++)
				dp[now][par]+=(lis[i]+1);
			for(;i<lc;i++)
				dp[now][par]+=lis[i];
		}
	}
	return dp[now][par];
}

// Main
int main(void)
{
	int tc,cs,n,a,b,ans,i,j,tmp;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}

		// Init
		for(i=1;i<=n;i++)
			for(j=0;j<=n;j++)
				used[i][j]=false;

		// Enumerate root
		ans=n;
		for(i=1;i<=n;i++)
		{
			tmp=find(i,0);
			ans=min(ans,tmp);
		}
		printf("Case #%d: %d\n",cs,ans);

		// Clear
		for(i=1;i<=n;i++) edg[i].clear();
	}
	return 0;
}