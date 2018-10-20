#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#define repn(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) repn(i, 0, a)

using namespace std;

const int MAXN = 1011;
vector<int> adj[MAXN];
int dp[MAXN];

int f(int node, int pai) {
	int b1 = -1, b2 = -1;
	int &ans = dp[node];
	if (ans != -1) return ans;
	if (adj[node].size() < 2) 
		return 1;
	rep (i, adj[node].size()) {
		int next = adj[node][i];
		if (next == pai) continue;
		int max_nodes = f(next, node);
		if (b1 <= max_nodes) {
			b2 = b1, b1 = max_nodes;
		} else if (b2 < max_nodes) {
			b2 = max_nodes;
		}
	}
	if (b1 < 0 or b2 < 0) return ans = 1;
	return ans = 1 + b1 + b2;
}

int max_sol(int n) {
	int ans = 0;
	rep (i, n) {
		memset(dp, -1, sizeof dp);
		ans = max(f(i, -1), ans);
	}
	return ans;
}

void solve() {
	rep (i, MAXN) adj[i].clear();
	int n;
	cin >> n;
	rep (i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << n - max_sol(n) << endl;
}

int main() {
	int test = 0;
	cin >> test;
	rep (i, test) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
