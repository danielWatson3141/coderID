#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF = 1000000005;
const int N = 1005;
typedef __int64 ll;
vector<int>E[N];
int dp[N],cnt[N],sz[N];
void dfs(int x,int f)
{
	int i,j;
	sz[x]=1;
	for(i=E[x].size()-1;i>=0;i--)
	{
		j=E[x][i];
		if(j!=f)
		{
			dfs(j,x);
			sz[x]+=sz[j];
		}
	}
	int k=0;
	for(i=E[x].size()-1;i>=0;i--)
	{
		j=E[x][i];
		if(j!=f)
		{
			cnt[k++]=dp[j];
		}
	}
	if(k<2)
	{
		dp[x]=1;
	}
	else
	{
		sort(cnt,cnt+k);
		dp[x]=cnt[k-1]+cnt[k-2]+1;
	}
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int n,i;
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		int ret=0;
		for(i=1;i<=n;i++)
		{
			dfs(i,0);
			//for(int j=1;j<=n;j++)printf("j:%d dp:%d \n",j,dp[j]);
			if(ret<dp[i])ret=dp[i];
		}
		for(i=1;i<=n;i++)E[i].clear();
		printf("Case #%d: %d\n",ca++,n-ret);
	}
    return 0;
}
