#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nTest;
int n, ret;
vector<int> adj[1010];
int f[1010], c[1010];

void DP(int u, int par) {
	c[u] = 0;
	pair<int, int> choose = make_pair(0, 0);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != par) {
			DP(v, u);
			c[u] += c[v];
			if (choose.first <= c[v] - f[v]) choose = make_pair(c[v] - f[v], choose.first);
			else if (choose.second <= c[v] - f[v]) choose = make_pair(choose.first, c[v] - f[v]);
		}
	}
	f[u] = c[u];
	if (adj[u].size() + (par == 0) > 2)
		f[u] = min(f[u], c[u] - choose.first - choose.second);
	c[u]++;
}

int main() {

	freopen("B-large.in", "r", stdin);
	freopen("Output.txt", "w", stdout);

	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 1; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ret = 1e9;
		for (int root = 1; root <= n; root++) {
			DP(root, 0);
			ret = min(ret, f[root]);
		}
		printf("Case #%d: %d\n", test, ret);
	}

	return 0;
}