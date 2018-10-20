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
void R( int &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
void R( long long &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
#define MAX 100005
vector <int> adj[1001];
int n;
int dp[1001],sz[1001];
void dfs(int x, int p){
	sz[x]=1;
	int ns=adj[x].size();
	if(ns==1 && p!=-1){dp[x]=0;
	return ;}
	int best1=-1,bi1=-1,best2=-1,bi2=-1;
	for(int i=0;i<ns;++i)
	{
		if(adj[x][i]==p)continue;
		dfs(adj[x][i],x);
		sz[x]+=sz[adj[x][i]];
		if(sz[adj[x][i]]-dp[adj[x][i]]>best1){
			bi2=bi1,best2=best1;
			bi1=adj[x][i],best1=sz[adj[x][i]]-dp[adj[x][i]];}
		else
			if(sz[adj[x][i]]-dp[adj[x][i]]>best2)bi2=adj[x][i],best2=sz[adj[x][i]]-dp[adj[x][i]];
	}
	dp[x]=0;
	if(ns>2 || (ns==2&& p==-1)){if(bi1!=-1)dp[x]+=dp[bi1];
	if(bi2!=-1)dp[x]+=dp[bi2];}
	else bi1=bi2=-1;
	for(int i=0;i<ns;++i){
		if(adj[x][i]==p || adj[x][i]==bi1 || adj[x][i]==bi2)continue;
		dp[x]+=sz[adj[x][i]];
	}
}

int main(){
	freopen("in.in","r",stdin);freopen("out.out","w",stdout);
	int t;
	R(t);
	int cc=0;
	while(t--){
		++cc;
		
	R(n);	
	for(int i=0;i<=n;++i)adj[i].clear();
	int u,v;
	for(int i=0;i<n-1;++i)
		{R(u),R(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int best=n;
	for(int i=1;i<=n;++i)dfs(i,-1),best=min(best,dp[i]);
	printf("Case #%d: %d\n",cc,best);
	}}