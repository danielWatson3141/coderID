#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define inf 0x3fffffff
#define vE 4000
#define vN 2000
#define LL long long
struct edge
{
	int u, v;
	int next;
} e[vE];
int used[vN], en, head[vN];
int num[vN];
int degree[vN];
int dp[vN];
int t,n,cas;
void addedge(int u, int v)
{
	e[en].u = u;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
	e[en].u = v;
	e[en].v = u;
	e[en].next = head[v];
	head[v] = en++;
}

int dfs(int s)
{
	used[s]=1;
	int dpt=0;
	vector<int> tsort;
	for(int i=head[s];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(used[v]==1)continue;
		dfs(v);
		num[s]+=num[v]+1;
		tsort.push_back((num[v]+1)-dp[v]);
		degree[s]++;
		dpt+=dp[v];
	}
	if(degree[s]==0)
	{
		dp[s]=0;
		num[s]=0;
		//cout<<dp[s]<<" "<<s<<endl;
		return 0;
	}
	if(degree[s]==2)
	{
		dp[s]=dpt;
		//cout<<dp[s]<<" "<<s<<endl;
		return 0;
	}
	if(degree[s]==1)
	{
		dp[s]=num[s];
		//cout<<dp[s]<<" "<<s<<endl;
		return 0;

	}
	sort(tsort.begin(),tsort.end());
	//cout<<num[s]<<" "<<tsort[tsort.size()-1]<<" "<<tsort[tsort.size()-2]<<" "<<tsort.size()<<endl;
	dp[s]=num[s]-tsort[tsort.size()-1]-tsort[tsort.size()-2];
	//cout<<dp[s]<<" "<<s<<endl;
	return 0;

}
int main()
{

	freopen("dataA.in","r",stdin);
	freopen("dataA.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		memset(degree,0,sizeof(degree));
		en=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));
			memset(degree,0,sizeof(degree));
			memset(dp,0,sizeof(dp));
			memset(num,0,sizeof(num));
			dfs(i);
			int temp=dp[i];
			//cout<<temp<<endl;
			if(ans>temp)ans=temp;
		}
		printf("Case #%d: %d\n",++cas,ans);

	}
	return 0;
}
