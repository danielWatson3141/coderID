#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
const int oo = 1 << 29;
vector<vector<int > > g;
int n;
bool vis[1024];
int dp[1024];
int DFS(int u,int p){
	dp[u] = 1;
	for (int i = 0; i < g[u].size(); ++i)
		if (g[u][i]!=p)
			dp[u]+=DFS(g[u][i], u);
	return dp[u];
}
int BFS(int u){
	memset(vis, 0, sizeof(vis));
	DFS(u, -1);
	queue<int> q;
	q.push(u);
	vis[u] = true;
	int vs = 0;
	vector<pair<int,int> > add;
	while (!q.empty()){
		for (int it = q.size(); it > 0; --it){
			u = q.front();
			q.pop();
			++vs;
			add.clear();
			for (int i = 0; i < g[u].size(); ++i)
			if (!vis[g[u][i]])
				add.push_back(make_pair(-dp[g[u][i]], g[u][i]));
			sort(add.begin(), add.end());
			if (add.size() < 2)
				continue;
			for (int i = 0; i < 2;++i){
				q.push(add[i].second);
				vis[add[i].second] = true;
			}
		}
	}
	return n-vs;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		printf("Case #%d: ", k);
		scanf("%d", &n);
		g.clear();
		g.resize(n);
		int a, b;
		for (int i = 1; i < n; ++i){
			scanf("%d%d", &a, &b);
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int res = n - 1;
		for (int i = 0; i < n; ++i)
			res = min(res, BFS(i));
		printf("%d\n", res);
	}
	return 0;
}