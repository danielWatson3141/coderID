/*
 * $File: b.cc
 * $Date: Sat Apr 26 10:05:00 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cassert>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

bool satisfy(int d) {
	return d == 0 || d == 2;
}

void erase_from_vec(vector<int> &vec, int v) {
	for (size_t i = 0; i < vec.size(); i ++) {
		if (vec[i] == v) {
			vec.erase(vec.begin() + i);
			return;
		}
	}
	assert(0);
}


int dp(int root, int parent, vector<vector<int>> &g) {
	vector<int> f;
	for (auto &child: g[root])
		if (child != parent)
			f.push_back(dp(child, root, g));
	if (f.size() < 2)
		return 1;
	sort(f.begin(), f.end());
	return f[f.size() - 1] + f[f.size() - 2] + 1;
}

void solve() {
	int N;
	cin >> N;
	vector<vector<int>> g(N);
	vector<int> deg(N);
	for (int i = 0; i < N - 1; i ++) {
		int a, b;
		cin >> a >> b;
		a --, b --;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	for (int i = 0; i < N; i ++) {
		ans = max(ans, dp(i, -1, g));
	}

	printf("%d\n", N - ans);
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++) {
		fprintf(stderr, "%d/%d\n", i, T);
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker
 */

