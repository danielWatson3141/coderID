#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
set<int> tree[N];
int del[N], vis[N];

void init() {
	for (int i = 0; i < N; i++) tree[i].clear();
}

void dfs(int u) {
	vis[u] = 1;
	for (auto &v: tree[u]) {
		if (vis[v]) continue;
		if (del[v]) continue;
		dfs(v);
	}
}

int check() {
	set<int> cp[N];
	for (int i = 1; i <= n; i++) cp[i] = tree[i];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (!del[i]) {
			dfs(i); break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (del[i] || vis[i]) cnt++;
	}
	if (cnt != n) return 0;
	for (int i = 1; i <= n; i++) {
		if (del[i]) continue;
		for (int j = 1; j <= n; j++) {
			if (del[j]) cp[i].erase(j);
		}
	}
	int d2 = 0;
	for (int i = 1; i <= n; i++) {
		if (del[i]) continue;
		d2 += (cp[i].size() == 2);
	}
	return d2 == 1;
}

int main() {
	int cas; scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; scanf("%d%d", &u, &v);
			tree[u].insert(v);
			tree[v].insert(u);
		}
		int ans = N;
		for (int i = 0; i < 1 << n; i++) {
			memset(del, 0, sizeof del);
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					del[j + 1] = 1;
					cur++;
				}
			}
			if (check()) {
				ans = min(ans, cur);
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}

