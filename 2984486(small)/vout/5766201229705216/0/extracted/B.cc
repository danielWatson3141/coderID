#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1008;
vector<int> edges[MAXN];

int countNode[MAXN];
vector<int> sons[MAXN];
int dp[MAXN];


int dfs(int u, int f) {
	countNode[u] = 1;
	for (int i = 0; i < edges[u].size(); ++i) {
		if (edges[u][i] != f) {
			sons[u].push_back(edges[u][i]);
			countNode[u] += dfs(edges[u][i], u);
		}
	}
	return countNode[u];
}

int gao(int i) {
	if (dp[i] >= 0) return dp[i];
	if(sons[i].size() == 0) {
		return dp[i] = 0;
	} else if (sons[i].size() == 1) {
		// delect all sons
		return dp[i] = countNode[sons[i][0]];
	} else {
		int ret = 0x3f3f3f3f;
		for (int x = 0; x < sons[i].size(); ++x) {
			for (int y = x + 1; y < sons[i].size(); ++y) {
				ret = min(ret, gao(sons[i][x]) + gao(sons[i][y]) + countNode[i] - 1 - countNode[sons[i][x]] - countNode[sons[i][y]]);
			}
		}
		return ret;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int re = 1; re <= T; ++re) {
		int a, b, n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &a, &b);
			edges[a - 1].push_back(b - 1);
			edges[b - 1].push_back(a - 1);
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				sons[j].clear();
			}
			fill(dp, dp + n, -1);
			dfs(i, -1);
			ans = min(ans, gao(i));
		}
		printf("Case #%d: %d\n", re, ans);
	}

	return 0;
}