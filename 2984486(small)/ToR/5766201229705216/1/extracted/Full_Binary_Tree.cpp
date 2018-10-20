#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1000000000
vector<int> v[1005];
int dp[1005];
int cnt[1005];
int root;
void dfs(int idx,int p)
{
	int i;
	bool leaf=true;
	int cntL=0;
	int jum;
	vector<int> a,b;
	for(i=0;i<v[idx].size();i++)
	{
		if(v[idx][i]!=p)
		{
			jum=v[idx][i];
			cntL++;
			dfs(v[idx][i],idx);
			a.push_back(cnt[v[idx][i]]);
			b.push_back(dp[v[idx][i]]-cnt[v[idx][i]]);
			leaf=false;
		}
	}
	if(leaf)
	{
		dp[idx]=0;
		cnt[idx]=1;
		return;
	}
	if(cntL==1)
	{
		dp[idx]=cnt[jum];
		cnt[idx]=1+cnt[jum];
		return;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int all=0;
	for(i=0;i<cntL;i++) all+=a[i];
	cnt[idx]=all+1;
	
	int tmpall=all;
	for(i=0;i<2;i++) all+=b[i];
	
	if(tmpall<all) dp[idx]=tmpall;
	else dp[idx]=all;
	
	return;
}
main()
{
 	freopen("B-large.in","r",stdin);
	freopen("xxx.out","w",stdout);
	int t;
	int a,b;
	int n;
	int tcase_=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++) v[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans=INF;
		for(i=1;i<=n;i++)
		{
			//--------------
			root=i;
			dfs(root,-1);
			//printf("%d : %d\n",i,dp[root]);
			if(dp[root]<ans) ans=dp[root];
		}
		printf("Case #%d: %d\n",tcase_++,ans);
	}
}

