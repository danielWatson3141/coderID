#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1000 + 10;

int chd[N], dp[N], par[N];
vector<int> e[N];
queue<int> que;

void dfs(int u, int p) {
	chd[u] = 1;
	par[u] = p;
	for(int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if(v == p)	continue;

		dfs(v, u);
		chd[u] += chd[v];
	}
	if(e[u].size() == 1 && u != p) {
		dp[u] = 0;
		que.push(u);
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for(int kase = 1; kase <= t; kase++) {
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n-1; i++) {
			int a, b;
			scanf("%d%d", &a, &b);

			e[a].push_back(b);
			e[b].push_back(a);
		}

		int ans = 1000000;
		for(int root = 1; root <= n; root++) {
			dfs(root, root);

			while(!que.empty()) {
				int u = que.front();	que.pop();

				if(e[u].size() < 2 + (u != root)) {
					dp[u] = chd[u] - 1;
					if(u == root)	continue;
					que.push(par[u]);
					continue;
				}

				int mx1 = -1, mx2 = -1;
				for(int i = 0; i < e[u].size(); i++) {
					int v = e[u][i];
					if(v == par[u])	continue;

					if(chd[v] - dp[v] > mx1) {
						mx2 = mx1;
						mx1 = chd[v] - dp[v];
					}
					else if(chd[v] - dp[v] > mx2) {
						mx2 = chd[v] - dp[v];
					}
				}

				dp[u] = chd[u] - mx1 - mx2 - 1;
				if(u != root)	que.push(par[u]);
			}

			ans = min(ans, dp[root]);
		}

		printf("Case #%d: %d\n", kase, ans);

		for(int i = 1; i <= n; i++)	e[i].clear();
	}

	return 0;
}
