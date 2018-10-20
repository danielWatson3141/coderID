#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int dp[MAXN], sz[MAXN];
vector <int> adj[MAXN];
int n, ans;

int dfs(int t, int par)
{
	int s = adj[t].size();
	if ((!par && s == 0) || (par && s == 1)){
		dp[t] = 0; sz[t] = 1; return 0;
	}
	dp[t] = 0; sz[t] = 1;
	int min1 = -1, min2 = -1;
	for (int i = 0; i < s; i ++){
		int v = adj[t][i];
		if (v != par){
			dfs(v, t);
			sz[t] += sz[v];
			if (sz[v] - dp[v] > min1)
				min2 = min1, min1 = sz[v] - dp[v];
			else if (sz[v] - dp[v] > min2)
				min2 = sz[v] - dp[v];
		}
	}
	dp[t] = sz[t] - 1;
	if (min1 != -1 && min2 != -1)
		dp[t] -= min1 + min2;
	//printf("dp(%d): %d\n", t, dp[t]);
	return dp[t];
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			adj[i].clear();
		for (int i = 1; i < n; i ++){
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = n;
		for (int i = 1; i <= n; i ++){
			memset(dp, -1, sizeof(dp));
			if (dfs(i, 0) < ans)
				ans = dp[i];
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
