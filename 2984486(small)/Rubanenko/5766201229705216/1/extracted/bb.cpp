#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define prev privet1
#define next privet2
#define y1 privet3
#define rank privet4
#define left privet5
#define right privet6
#define y0 privet7

const double pi = 3.141592653589793238;

void ensureLimit(long long n, long long l, long long r)
{
	assert(l <= n && n <= r);
}

int n;
vector<int> g[1111];
int s[1111], f[1111];

void dfs(int v, int p) {
	s[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		if (g[v][i] != p) {
			dfs(g[v][i], v);
			s[v] += s[g[v][i]];
		}
	}
	f[v] = s[v] - 1;
	for (int i = 0; i < g[v].size(); i++) {
		for (int j = i + 1; j < g[v].size(); j++) {
			if (p != g[v][i] && p != g[v][j]) {
				f[v] = min(f[v], f[g[v][i]] + f[g[v][j]] + s[v] - 1 - s[g[v][i]] - s[g[v][j]]);
				}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tcc = 1; tcc <= tc; tcc++) {
		printf("Case #%d: ", tcc);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans = n - 1;
		for (int root = 1; root <= n; root++) {
			dfs(root, 0);
			ans = min(ans, f[root]);
		}
		printf("%d\n", ans);
	}
}
