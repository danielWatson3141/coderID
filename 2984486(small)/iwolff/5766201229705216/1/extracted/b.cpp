#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
 
using namespace std;
 
#define INF 0x3f3f3f3f
#define ll long long
#define MAXN 1010

int mem[MAXN][3],rnd,dp[MAXN][3];
int pai[MAXN],sz[MAXN],sol[MAXN];
vector<int> adj[MAXN];
int help;

int solve(int pos, int r, int t, int *a, int *b) {
	if (pos == t) {
		if (r) return INF;
		return 0;
	}
	
	if (mem[pos][r] == rnd) return dp[pos][r];
	mem[pos][r] = rnd;
	
	dp[pos][r] = a[pos] + solve(pos+1,r,t,a,b);
	if (r) dp[pos][r] = min(dp[pos][r], b[pos] + solve(pos+1,r-1,t,a,b));
	return dp[pos][r];
}

void dfs(int u) {
	int a[MAXN],b[MAXN],t = 0;
	sz[u] = 1;
	for (int i=0; i<int(adj[u].size()); i++) {
		int v = adj[u][i];
		if (v == pai[u]) continue;
		pai[v] = u;
		dfs(v);
		sz[u] += sz[v];
		a[t] = sz[v];
		b[t++] = sol[v];
	}
	
	sol[u] = sz[u]-1;
	if (t) { rnd++; sol[u] = min(sol[u],solve(0,2,t,a,b)); }
	return;
}

int main() {
	int nt,n,nteste=1,ans;
	rnd = 0;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			adj[i].clear();
		for (int i=0; i<n-1; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		ans = n;
		for (int i=0; i<n; i++) {
			pai[i] = -1;
			dfs(i);
			ans = min(ans,sol[i]);
		}
		
		printf("Case #%d: %d\n",nteste++,ans);
	}
	
	return 0;
}
