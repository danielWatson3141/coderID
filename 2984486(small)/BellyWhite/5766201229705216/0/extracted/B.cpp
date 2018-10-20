#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[1005];

int dfs(int x, int p) {
	int v[3] = {};
	for (size_t i = 0; i < e[x].size(); ++i) {
		int y = e[x][i];
		if (y == p) continue;
		v[0] = dfs(y, x);
		sort(v, v + 3);
	}
	return v[1] ? v[1] + v[2] + 1 : 1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) e[i].clear();
		for (int a, b, i = 1; i < n; ++i) {
			scanf("%d%d", &a, &b); --a, --b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans = 1;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, dfs(i, -1));
		}
		printf("Case #%d: %d\n", cas, n - ans);
	}
}
