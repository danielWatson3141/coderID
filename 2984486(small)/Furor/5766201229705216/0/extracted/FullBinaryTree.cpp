#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 1005

using namespace std;

typedef pair<int, int> ii;

vector<int> adj[MAX];

ii make_root(int v, int p) {
	vector<int> V;
	int s = 0;
	for (int i = 0; i < adj[v].size(); i++) {
		if (adj[v][i] != p) {
			ii a = make_root(adj[v][i], v);
			s += a.first;
			V.push_back(a.first - a.second);
		}
	}
	int c = s;
	if (V.size() >= 2) {
		sort(V.begin(), V.end());
		for (int i = max(0, int(V.size()) - 2); i < V.size(); i++)
			c -= V[i];
	}
	return ii(s + 1, c);
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int a, b, c, i, n, t;
	scanf("%d", & t);
	for (c = 0; c < t; c++) {
		scanf("%d", & n);
		for (i = 0; i < n; i++)
			adj[i].clear();
		for (i = 0; i < n - 1; i++) {
			scanf("%d %d", & a, & b);
			a--;
			b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = MAX;
		for (i = 0; i < n; i++)
			ans = min(ans, make_root(i, -1).second);
		printf("Case #%d: %d\n", c + 1, ans);
	}
	return 0;
}
