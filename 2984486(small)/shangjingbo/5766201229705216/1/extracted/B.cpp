#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000;

vector<int> adj[maxn];

int dfs(int u, int fa)
{
	int ret = 1; // only itself
	int max1 = -1, max2 = -1;
	for (int i = 0; i < adj[u].size(); ++ i) {
		int v = adj[u][i];
		if (v == fa) {
			continue;
		}
		
		int current = dfs(v, u);
		if (current > max1) {
			max2 = max1;
			max1 = current;
		} else {
			max2 = max(max2, current);
		}
	}
	
	if (max2 != -1) {
		ret = max(ret, max1 + max2 + 1);
	}
	return ret;
}

int solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		adj[i].clear();
	}
	for (int i = 1; i < n; ++ i) {
		int a, b;
		scanf("%d%d", &a, &b);
		-- a; -- b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int answer = 1;
	for (int i = 0; i < n; ++ i) {
		answer = max(answer, dfs(i, -1));
	}
	return n - answer;
}

int main()
{
	int tests, test = 1;
	for (scanf("%d", &tests); test <= tests; ++ test) {
		int answer = solve();
		printf("Case #%d: %d\n", test, answer);
	}
	return 0;
}
