#include <bits/stdc++.h>
using namespace std;
void dfs(const vector<vector<int>>& g, int p, vector<bool>& a) {
	for (int x : g[p]) if (!a[x]) {
		a[x] = true;
		dfs(g, x, a);
	}
}
bool f(const vector<vector<int>>& G, int p) {
	int N = G.size();
	vector<int> a(N, -1);
	int c = 0;
	for (int i = 0; i < N; ++ i) if ((p>>i)&1) a[i] = c++;
	vector<vector<int>> g(c);
	for (int i = 0; i < N; ++ i) if (a[i] >= 0) {
		for (int j : G[i]) if (a[j] >= 0) {
			g[a[i]].push_back(a[j]);
		}
	}
	vector<int> cnt(4);
	for (int i = 0; i < c; ++ i) {
		if (g[i].size() >= 4) return false;
		++ cnt[g[i].size()];
	}
	if (cnt[2] != 1) return false;
	vector<bool> b(c);
	dfs(g, 0, b);
	for (bool bb : b) if (!bb) return false;
	return true;
}
void func() {
	int N;
	cin >> N;
	vector<vector<int>> G(N);
	for (int i = 0; i < N-1; ++ i) {
		int x, y;
		cin >> x >> y;
		-- x; -- y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int r = N-1;
	for (int i = 1; i < (1<<N); ++ i) {
		int rr = N - __builtin_popcount(i);
		if (rr < r && f(G, i)) {
			r = rr;
		}
	}
	cout << r << endl;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": ";
		func();
	}
}
