#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
const int INF = 1000000;

vector<int> g[MAXN];
int n;

int nsub[MAXN];
bool used[MAXN];
int delv[MAXN];

int dfs(int v) {
	used[v] = true;
	nsub[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!used[u]) 
			nsub[v] += dfs(u);
	}
	return nsub[v];
}

int make_full(int v) {
	used[v] = true;
	vector< pair<int, int> > minv;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!used[u]) {
			int x = make_full(u);
			minv.push_back(make_pair(nsub[u], x));
		}
	}
	if (minv.size() == 0)
		return 0;
	if (minv.size() == 1) {
		return minv[0].first;
	}

	int res = INF;
	for (int i = 0; i < minv.size(); ++i)
		for (int j = i + 1; j < minv.size(); ++j)
			res = min(res, nsub[v] - minv[i].first - minv[j].first + minv[i].second + minv[j].second - 1);
	return res;
}

int try_full(int root) {
	memset(used, 0, sizeof(used));
	memset(nsub, 0, sizeof(nsub));
	
	dfs(root);

	memset(used, 0, sizeof(used));
	return make_full(root);
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	cin >> n;
	for (int i = 0; i < n; ++i)
		g[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int x = 0;
	int res = INF;
	for (int i = 0; i < n; ++i) {
		x = try_full(i);
		res = min(res, x);
	}

	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
