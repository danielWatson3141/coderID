#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int NMAX=1000;
const int INF=100000;

int N; vector<int> E[NMAX];
int DP[NMAX];//最少砍幾個
int SZ[NMAX];

void dfs(int u,int p)
{
	vector<int>::iterator it;
	SZ[u]=1;
	for(it=E[u].begin();it!=E[u].end();++it)
	{
		if(*it==p)continue;
		dfs(*it,u);
		SZ[u]+=SZ[*it];
	}
	DP[u]=SZ[u]-1;
	int a=INF,b=INF;
	for(it=E[u].begin();it!=E[u].end();++it)
	{
		if(*it==p)continue;
		const int t=DP[*it]-SZ[*it];
		if(t<=a){b=a;a=t;}else if(t<b)b=t;
	}
	if(b!=INF)DP[u]=SZ[u]-1+a+b;
}

int solve(int root)
{
	dfs(root,-1);
	return DP[root];
}

int solve()
{
	int ret=N-1;
	for(int i=0;i<N;i++)ret=min(ret,solve(i));
	return ret;
}

void input()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		input();
		printf("Case #%d: %d\n",t,solve());
		for(int i=0;i<N;i++)vector<int>().swap(E[i]);
	}
	return 0;
}
