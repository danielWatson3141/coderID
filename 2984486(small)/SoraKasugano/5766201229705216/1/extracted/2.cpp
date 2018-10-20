#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1002;
int f[maxn], g[maxn];
vector<int> e[maxn];
void dfs(int p, int fa) {
	++g[p];
	int c = 0, m1 = 0, m2 = 0;
	for (int i = 0 ; i < e[p].size() ; ++i) {
		int j = e[p][i];
		if (j != fa) {
			++c;
			dfs(j, p);
			g[p] += g[j];
			if (m1 < g[j] - f[j]) m2 = m1, m1 = g[j]-f[j];
			else if (m2 < g[j] - f[j]) m2 = g[j] - f[j];
		}
	}
	if (c >= 2) f[p] = g[p] - 1 - m1 - m2;
	else f[p] = g[p] - 1;
}
int main() {
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int c = 1 ; c <= t ; ++c) {
		int n;
		scanf("%d", &n);
		for (int i = 0 ; i < n ; ++i) e[i].clear();
		for (int i = 0 ; i < n - 1 ; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = 0x3fffffff;
		for (int i = 0 ; i < n ; ++i) {
			memset(f, 0x3f, sizeof f);
			memset(g, 0, sizeof g);
			dfs(i, -1);
			ans = min(ans,f[i]);
		}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
