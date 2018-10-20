#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int g[MAXN][MAXN];
int fg[MAXN][MAXN];
bool deleted[MAXN];
int n;
bool used[MAXN];

bool dfs(int v) {
	used[v] = true;
	int ch = 0;
	for (int i = 0; i < n; ++i)
		if (!deleted[i] && !used[i] && fg[v][i] == 1)
			ch++;
	if (ch != 0 && ch != 2)
		return false;
	for (int i = 0; i < n; ++i)
		if (!deleted[i] && !used[i] && fg[v][i] == 1)
			dfs(i);
}

bool is_full_tree() {
	memset(fg, 0, sizeof(fg));
	for (int i = 0; i < n; ++i) if (!deleted[i])
		for (int j = 0; j < n; ++j) if (!deleted[j])
			fg[i][j] = g[i][j];

	for (int i = 0; i < n; ++i) if (!deleted[i]) {
		memset(used, 0, sizeof(used));
		bool res = dfs(i);
		for (int j = 0; j < n; ++j)
			if (!deleted[j] && !used[j])
				res = false;
		if (res)
			return true;
	}
	return false;
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	memset(g, 0, sizeof(g));

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x][y] = g[y][x] = 1;
	}

	int res = n + 1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		memset(deleted, 0, sizeof(deleted));
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i)) {
				cnt++;
				deleted[i] = true;
			}

		if (is_full_tree())
			res = min(res, cnt);
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
