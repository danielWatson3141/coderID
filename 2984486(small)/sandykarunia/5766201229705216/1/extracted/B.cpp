#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

#define MAXN 1005

int t,n;
int ans;
vector<int> adjList[MAXN];
int son[MAXN];
int parent[MAXN];
vector<int> vec;
queue<int> q;
int dp[MAXN];

void reset()
{
	ans = INF;
	for (int i=0;i<MAXN;i++) adjList[i].clear();
}

void dfs(int node)
{
	for (int i=0;i<adjList[node].size();i++)
	{
		int v = adjList[node][i];
		if (v==parent[node]) continue;
		parent[v] = node;
	//	printf("parent[%d]=%d\n",v,node);
		dfs(v);
	}
}

bool f(int a,int b)
{
	return dp[a]<dp[b];
}

void go(int node)
{
	dp[node] = 1;
	vector<int> anak; anak.clear();
	for (int i=0;i<adjList[node].size();i++)
	{
		int v = adjList[node][i];
		if (v==parent[node]) continue;
		
		anak.PB(v);
	}
	
	if (anak.size()>=2)
	{
		for (int i=0;i<anak.size();i++) if (dp[anak[i]]==0) go(anak[i]);
		sort(anak.begin(),anak.end(),f);
		
		dp[node]+=dp[anak[anak.size()-1]]+dp[anak[anak.size()-2]];
	}
}

void check(int root)
{
	memset(son,0,sizeof(son));
	memset(parent,0,sizeof(parent));
	memset(dp,0,sizeof(dp)); //dp[i] = max node if choose node i
	
	//calc jumlah anak
	dfs(root);
	
//	printf("root:%d\n",root);
//	for (int i=1;i<=n;i++) printf("%d ",son[i]);
//	printf("\n");

	int res=1,cur=root;
	
	vec.clear();
	for (int i=0;i<adjList[cur].size();i++)
	{
		int v = adjList[cur][i];
		if (v==parent[cur]) continue;
		vec.PB(v);
	}
	
	if (vec.size()>=2)
	{
		//pilih
		for (int i=0;i<vec.size();i++) if(dp[vec[i]]==0) go(vec[i]);
		
		sort(vec.begin(),vec.end(),f); //dp[i]<dp[j]
		res+=dp[vec[vec.size()-1]]+dp[vec[vec.size()-2]];
	}
	
	/*
	printf("root:%d\n",root);
	printf("vec: ");
	for (int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
	printf("dp: ");
	for (int i=1;i<=n;i++) printf("%d ",dp[i]); printf("\n");
	printf("res:%d\n\n",res);*/
	
	ans = min(ans,n-res);
}

int main()
{
	OPENR("B-large.in");
	OPENW("B-large.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		reset();
		
		scanf("%d",&n);
		for (int i=0;i<n-1;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			
			adjList[x].PB(y);
			adjList[y].PB(x);
		}
		
		for (int i=1;i<=n;i++) check(i);
		
		printf("Case #%d: %d\n",tc,ans);
	}
	
 	return 0;
}



