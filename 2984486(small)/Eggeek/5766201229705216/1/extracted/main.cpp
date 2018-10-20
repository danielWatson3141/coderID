#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 1010
vector<int>e[maxn];
//bool isd[maxn];
int n,root,dp[maxn],sz[maxn];
//bool vis[maxn];

int dfs(int cur,int pa) {
	if (dp[cur]!=-1) return dp[cur];
	int sonsize = sz[cur] - 1;
	dp[cur] = sonsize; // del all
	for (int i=0 ; i<(int)e[cur].size() ; i++ ) {
		int u = e[cur][i];
		if (u!=pa) dfs(u,cur);
	}
	for (int i=0 ; i<(int)e[cur].size() ; i++ ) {
		int u = e[cur][i];
		if (u==pa) continue;
		for (int j=0 ; j<(int)e[cur].size() ; j++ ) {
			int v = e[cur][j];
			if (v==pa) continue;
			if (u==v) continue;
			int tmp = sonsize - sz[u] - sz[v];
			dp[cur] = min(dp[cur], tmp+dp[u]+dp[v]);
		}
	}
	return dp[cur];
}

void initsz(int cur,int pa) {
	sz[cur] = 1;
	for (int i=0 ; i<(int)e[cur].size() ; i++ ) {
		int x = e[cur][i];
		if (x!=pa) {
			initsz(x,cur);
			sz[cur] += sz[x];
		}
	}
}

int DP() {
	memset(dp,-1,sizeof(dp));
	initsz(root,-1);
	dfs(root,-1);
	return dp[root];
}

void work() {
	scanf("%d",&n);
	for (int i=0 ; i<=n ; i++ ) if (e[i].size()) e[i].clear();
	for (int i=0 ; i<n-1 ; i++ ) {
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans = n;
	for ( root=1 ; root<=n ; root++ ) {
		int tmp = DP();
		ans = min(tmp,ans);
	}
	printf("%d\n", ans);
}

int main() {
	int cas;
	freopen("test.txt", "r", stdin);
	freopen("ans2.txt","w",stdout);
	scanf("%d",&cas);
	for (int t=1 ; t<=cas ; t++ ) {
		printf("Case #%d: ",t);
		work();
	}
	return 0;
}
