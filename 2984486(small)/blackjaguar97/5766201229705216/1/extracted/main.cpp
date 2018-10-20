#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
#include<cstdlib>
#include<stdio.h>
#include<set>
#include<cmath>
#include<cstring>
#include<utility>
#include<string>
#include<iomanip>
using namespace std;
#define MAX 100005
vector <int> adj[1001];
int n;
int dp[1001],hajm[1001];
void dfs(int x, int p){
	hajm[x]=1;
	int stuff=adj[x].size();
	if(stuff==1 && p!=-1){dp[x]=0;
	return ;}
	int best1=-1,bi1=-1,best2=-1,bi2=-1;
	for(int i=0;i<stuff;++i)
	{
		if(adj[x][i]==p)continue;
		dfs(adj[x][i],x);
		hajm[x]+=hajm[adj[x][i]];
		if(hajm[adj[x][i]]-dp[adj[x][i]]>best1){
			bi2=bi1,best2=best1;
			bi1=adj[x][i],best1=hajm[adj[x][i]]-dp[adj[x][i]];}
		else
			if(hajm[adj[x][i]]-dp[adj[x][i]]>best2)bi2=adj[x][i],best2=hajm[adj[x][i]]-dp[adj[x][i]];
	}
	dp[x]=0;
	if(stuff>2 || (stuff==2&& p==-1)){if(bi1!=-1)dp[x]+=dp[bi1];
	if(bi2!=-1)dp[x]+=dp[bi2];}
	else bi1=bi2=-1;
	for(int i=0;i<stuff;++i){
		if(adj[x][i]==p || adj[x][i]==bi1 || adj[x][i]==bi2)continue;
		dp[x]+=hajm[adj[x][i]];
	}
}

int main(){
	freopen("in.in","r",stdin);freopen("out.out","w",stdout);
	int t;
	scanf("%d",&t);
	int cc=0;
	while(t--){
		++cc;

	scanf("%d",&n);
	for(int i=0;i<=n;++i)adj[i].clear();
	int u,v;
	for(int i=0;i<n-1;++i)
		{scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int best=n;
	for(int i=1;i<=n;++i)dfs(i,-1),best=min(best,dp[i]);
	printf("Case #%d: %d\n",cc,best);
	}}
