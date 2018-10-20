#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)

int n;
vector<vector<int>> G;

int _root;
int getMaximumBT(int u, int parent) {

	vector<int> childs;

	for(int v : G[u]) if(v != parent) {
		childs.push_back( getMaximumBT(v, u) );
	}

	sort(childs.begin(), childs.end(),
			greater<int>() );

	if(childs.size() < 2) { // leaf node, or single-chain
		return 1;
	}
	else {
		return childs[0] + childs[1] + 1;
	}

}

int go() {
	cin >> n;
	G = vector<vector<int>>(n);
	REP(it, n - 1) {
		int x, y;
		cin >> x >> y;
		-- x; -- y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	int ans = 0;
	for(int root = 0; root < n; ++ root) {
		_root = root;
		int t = getMaximumBT(root, -1);
		ans = max(ans, t);
	}

	return n - ans;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		int ans = go();
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
