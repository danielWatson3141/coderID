#include <iostream>
#include <vector>

using namespace std;
const int imx = 1000 * 1000 * 1000;
vector<int>cache_count, cache_cut;
vector <vector <int>> g;
int count(int p, int v) {
	if(cache_count[v] == -1) {
		cache_count[v] = 1;
		for(int i = 0; i < g[v].size(); ++i) {
			if(g[v][i] != p) {
				cache_count[v] += count(v, g[v][i]);
			}
		}
	}
	return cache_count[v];
}
int cut(int p, int v) {
	if(cache_cut[v] == -1) {
		cache_cut[v] = 0;
		int children = g[v].size();
		if(p != -1) --children;
		int all = count(p, v) - 1;
		int res = imx;
		if(children > 2) {
			for(int i = 0; i < g[v].size(); ++i) {
				if(g[v][i] != p) {
					for(int j = i + 1; j < g[v].size(); ++j) {
						if(g[v][j] != p) {
							int k = all - (count(v, g[v][i]) + count(v, g[v][j]));
							k += cut(v, g[v][i]) + cut(v, g[v][j]);
							if(k < res) res = k;
						}
					}
				}
			}
			cache_cut[v] = res;
		} else if(children == 1) {
			for(int i = 0; i < g[v].size(); ++i) {
				if(g[v][i] != p) {
					cache_cut[v] = count(v, g[v][i]);
					break;
				}
			}
		} else if(children == 2) {
			for(int i = 0; i < g[v].size(); ++i) {
				if(g[v][i] != p) {
					cache_cut[v] += cut(v, g[v][i]);
				}
			}
		}
	}
	return cache_cut[v];
}

int solve(int n) {
	int ans = imx;
	for(int i = 0; i < n; ++i) {
		cache_count.assign(1000, -1);
		cache_cut.assign(1000, -1);
		int res = cut(-1, i);
		if(res < ans) ans = res;
	}
	return ans;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cerr << "testcase " << t << endl;
		int n;
		cin >> n;
		g.assign(n, vector<int>());
		for(int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
 		cout << "Case #" << t + 1 << ": " << solve(n) << endl;
	}
}