#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;


vvi g;

struct TDfsResult {
	int size;
	int toDelete;
};


TDfsResult dfs(int v, int from) {
	vector<int> values;
	int totalSize = 0;
	for (int i = 0; i < sz(g[v]); ++i) {
		int to = g[v][i];
		if (to == from) continue;
		TDfsResult res = dfs(to, v);
		totalSize += res.size;
		values.pb(res.toDelete - res.size);
	}

	TDfsResult ans;
	ans.size = totalSize + 1;
	if (sz(values) == 0) {
		ans.toDelete = 0;
		return ans;
	}
	if (sz(values) == 1) {
		ans.toDelete = totalSize;
		return ans;
	}

	sort(all(values));
	int minValues = 0;
	for (int i = 0; i < 2; ++i) {
		minValues += values[i];
	}
	ans.toDelete = totalSize + minValues;
	return ans;
}


void solve() {
	int n;
	cin >> n;

	g.clear();
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].pb(y);
		g[y].pb(x);
	}

	int best = n + 10;
	for (int i = 0; i < n; ++i) {
		TDfsResult now = dfs(i, -1);
		best = min(now.toDelete, best);
	}

	cout << best << endl;
	
}




int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}


    return 0;
}

