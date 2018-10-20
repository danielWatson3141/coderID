#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5000;
int adj[maxn],next[maxn],vt[maxn],sum[maxn];
bool pp[maxn];
int f[maxn][3];
int x,y,num,n,all,ca;
void connect(int x,int y)
{
	++all;
	adj[all]=y;
	next[all]=vt[x];
	vt[x]=all;
}
void prepare()
{
	memset(vt,0,sizeof(vt));
	all=0;
}
void dfs(int x)
{
	pp[x]=true;

	int l=vt[x];
	while (l!=0)
	{
		if (!pp[adj[l]])
		{
			dfs(adj[l]);
			sum[x]+=sum[adj[l]];
		}
		l=next[l];
	}

	f[x][0]=sum[x];
	l=vt[x];
	while (l!=0)
	{
		if (!pp[adj[l]])
		{
			int val=min(f[adj[l]][0],f[adj[l]][2]);
			for (int i=2; i>=1; i--) f[x][i]=min(f[x][i],f[x][i-1]-sum[adj[l]]+val);
		}
		l=next[l];
	}
	//cout<<x<<" "<<min(f[x][0],f[x][2])<<endl;
	sum[x]=sum[x]+1;
	pp[x]=false;
}
void solve()
{
	int ans=n+1;
	for (int i=1; i<=n; i++)
	{
		memset(sum,0,sizeof(sum));
		memset(f,10,sizeof(f));
		dfs(i);
		ans=min(ans,min(f[i][0],f[i][2]));

	}

	printf("Case #%d: %d\n",++ca,ans);
}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		prepare();
		scanf("%d",&n);
		for (int i=1; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			connect(x,y);
			connect(y,x);
		}
		solve();
	}
}
int main()
{
	init();
	return 0;
}
