#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

template<typename T> inline int sz(const T& x) { return (int)x.size(); }

vi ch;
void dfs(vvi& adj, vi& size, vi& cost, int u, int p) {
	if (p != -1 && sz(adj[u]) <= 1) return;

	for(int i = 0; i < sz(adj[u]); ++i) {
		int v = adj[u][i];
		if(v == p) continue;

		dfs(adj, size, cost, v, u);
		size[u] += size[v];
	}

	ch.clear();
	for(int i = 0; i < sz(adj[u]); ++i) {
		int v = adj[u][i];
		if(v != p) ch.push_back(v);
	}

	if (sz(ch) == 1) {
		cost[u] = size[u] - 1;
	} else if (sz(ch) == 2) {
		cost[u] = cost[ch[0]] + cost[ch[1]];
	} else {
		int best = size[u] - 1;
		for(int i = 0; i < sz(ch) - 1; ++i) {
			for(int j = i+1; j < sz(ch); ++j) {
				int cur = (size[u]-1) - size[ch[i]] + cost[ch[i]] - size[ch[j]] + cost[ch[j]];
				best = min(best, cur);
			}
		}
		cost[u] = best;
	}
}

int main() {
	int tc; cin >> tc;

	for(int t = 1; t <= tc; ++t) {
		int n; cin >> n;
		vvi adj(n);
		
		for(int i = 0; i < n-1; ++i) {
			int u, v; cin >> u >> v; --u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int del = n-1;
		for(int r = 0; r < n; ++r) {
			vi size(n, 1), cost(n, 0);
			dfs(adj, size, cost, r, -1);
			del = min(del, cost[r]);
			//cerr << "root " << r << ", cost: " << cost[r] << endl;
		}
		cout << "Case #" << t << ": " << del << endl;
	}

	return 0;
}
