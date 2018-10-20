#include <bits/stdc++.h>
using namespace std;

const int
	MAXV = 1 << 10;

int V;
int stSize[MAXV];
vector< int > G[MAXV];
int dp[MAXV];

void dfs(int u, int from = -1)
{
	stSize[u] = 1;
	
	vector< int > childs;
	for (auto v : G[u]) if (v != from)
	{
		dfs(v, u);
		stSize[u] += stSize[v];
		childs.push_back(dp[v]);
	}
	
	dp[u] = 1; // only u
	if (childs.size() >= 2)
	{
		sort(childs.rbegin(), childs.rend());
		dp[u] += childs[0] + childs[1];
	}
}

int main()
{
	int T; cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		printf( "Case #%d: ", test );
		
		cin >> V;
		for (int i = 0; i < V; ++i) G[i].clear();
		
		for (int i = 0; i < V - 1; ++i)
		{
			int u, v; cin >> u >> v;
			--u;
			--v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		int ans = 0;
		for (int i = 0; i < V; ++i)
		{
			dfs(i);
			ans = max(ans, dp[i]);
		}
		
		printf("%d\n", V - ans);
		
	}

	return 0;
}
