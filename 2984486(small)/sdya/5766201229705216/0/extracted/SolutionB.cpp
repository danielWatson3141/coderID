#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2000;
const long long inf = 1000000000000000LL;
vector < int > g[maxN];
int n;

long long dp[maxN], sp[maxN];
bool used[maxN];

void dfs(int v) {
	used[v] = true;
	vector < int > children;
	sp[v] = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
			children.push_back(g[v][i]);
			sp[v] += sp[g[v][i]] + 1;
		}
	}

	vector < int > values;
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		values.push_back(dp[u] - (sp[u] + 1));
	}
	sort(values.begin(), values.end());
	if (values.size() >= 2) {
		dp[v] = sp[v] + values[0] + values[1];
	}
	dp[v] = min(dp[v], sp[v]);
}

int calc(int root) {
	for (int i = 1; i <= n; ++i) {
		dp[i] = sp[i] = inf;
		used[i] = false;
	}
	dfs(root);
	return dp[root];
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int res = n - 1;
	for (int i = 1; i <= n; ++i) {
		res = min(res, calc(i));
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}