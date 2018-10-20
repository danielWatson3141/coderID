#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<int> g[1000];
int n, u[1000], f[1000], s[1000];
int cmp(int x, int y) {
	return s[x] - f[x] > s[y] - f[y];
}
void dfs(int n) {
	u[n] = 1, s[n] = 1;
	std::vector<int> tmp;
	for (int i = 0; i < g[n].size(); i++)
		if (!u[g[n][i]]) {
			tmp.push_back(g[n][i]), dfs(g[n][i]);
			s[n] += s[g[n][i]];
		}
	if (tmp.size() < 2) {
		f[n] = s[n]-1;
	} else {
		std::sort(tmp.begin(), tmp.end(), cmp);
		f[n] = s[n]-1 - (s[tmp[0]] - f[tmp[0]]) - (s[tmp[1]] - f[tmp[1]]);
	}
	u[n] = 0;
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		g[x].push_back(y), g[y].push_back(x);
	}
	int ans = ~0U>>1;
	for (int i = 0; i < n; i++) {
		dfs(i);
		if (f[i] < ans) ans = f[i];
	}
	printf("%d\n", ans);
}
int main() {
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; _++)
		printf("Case #%d: ", _), solve();
	return 0;
}
