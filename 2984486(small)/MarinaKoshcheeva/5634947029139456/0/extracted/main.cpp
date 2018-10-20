#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 160;
const int MAXL = 50;

int g[MAXN][MAXN];
int mt[MAXN];
bool used[MAXN];
int n, L;

//char outlets[MAXN][MAXL];
//char devices[MAXN][MAXL];
//int ndiff[MAXN][MAXN];
/*
bool dfs(int v) {
	if (used[v])
		return false;
	used[v] = true;
	for (int u = 0; u < n; ++u) if (g[v][u] != -1) {
		if (mt[u] == -1 || dfs(mt[u])) {
			mt[u] = v;
			return true;
		}
	}
	return false;
}

bool check(int x) {
	memset(g, -1, sizeof(g));
	memset(mt, -1, sizeof(mt));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (ndiff[i][j] <= x)
				g[i][j] = 1;

	for (int i = 0; i < n; ++i) {
		memset(used, 0, sizeof(used));
		dfs(i);
	}

	for (int i = 0; i < n; ++i)
		if (mt[i] == -1)
			return false;
	return true;
}

void precalc() {
	memset(ndiff, 0, sizeof(ndiff));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < L; ++k)
				ndiff[i][j] += (outlets[i][k] != devices[j][k]);
		}
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";

	memset(outlets, 0, sizeof(outlets));
	memset(devices, 0, sizeof(devices));

	scanf("%d %d\n", &n, &L);
	for (int i = 0; i < n; ++i) {
		if (i < n - 1)
			scanf("%s", outlets[i]);
		else
			scanf("%s\n", outlets[i]);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%s", devices[i]);
	}

	precalc();

	int left = 0;
	int right = L + 2;
	while (left + 1 < right) {
		int m = (left + right) / 2;
		if (check(m))
			right = m;
		else
			left = m;
	}

	if (left > L)
		cout << "NOT POSSIBLE" << endl;
	else {
		for (int k = left - 1; k <= left + 1; ++k)
			if (check(k)) {
				cout << k << endl;
				break;
			}
	}
}
*/
bool switched[MAXL];
string outlets[MAXN];
string devices[MAXN];
char buf[MAXL];
string swout[MAXN];

bool check() {
	for (int i = 0; i < n; ++i)
		swout[i] = outlets[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < L; ++j)
			if (switched[j]) {
				if (swout[i][j] == '0')
					swout[i][j] = '1';
				else
					swout[i][j] = '0';
			}

	sort(swout, swout + n);

	for (int i = 0; i < n; ++i)
		if (swout[i] != devices[i])
			return false;

	return true;
}

void solve2(int test_id) {
	cout << "Case #" << test_id << ": ";

	memset(outlets, 0, sizeof(outlets));
	memset(devices, 0, sizeof(devices));

	scanf("%d %d\n", &n, &L);
	for (int i = 0; i < n; ++i) {
		if (i < n - 1)
			scanf("%s", buf);
		else
			scanf("%s\n", buf);
		outlets[i] = string(buf);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		devices[i] = string(buf);
	}

	sort(devices,  devices + n);

	int res = L + 1;
	for (int mask = 0; mask < (1 << L); ++mask) {
		memset(switched, 0, sizeof(switched));

		int cnt = 0;
		for (int i = 0; i < L; ++i)
			if (mask & (1 << i)) {
				cnt++;
				switched[i] = true;
			}

		if (check())
			res = min(res, cnt);
	}

	if (res > L)
		cout << "NOT POSSIBLE" << endl;
	else
		cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve2(test_id);
	return 0;
}
