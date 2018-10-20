#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A;
vector<int> e[1001];
int ff[1001], gg[1001];int fff;

int g(int x, int p) {
	if (gg[x] != -1)
		return gg[x];
	gg[x] = 1;
	for (int i = 0; i < e[x].size(); ++i)
		if (e[x][i] != p)
			gg[x] += g(e[x][i], x);
	return gg[x];
}

int f(int x, int p) {
	if (ff[x] != -1)
		return ff[x];
	int k = 0;
	for (int i = 0; i < e[x].size(); ++i)
		if (e[x][i] != p)
			++k;
	if (k == 0) {
		return ff[x] = 0;
	}
	if (k == 1) {
		for (int i = 0; i < e[x].size(); ++i)
			if (e[x][i] != p)
				return ff[x] = g(e[x][i], x);
	}
	if (k == 2) {
		int ans = 0;
		for (int i = 0; i < e[x].size(); ++i)
			if (e[x][i] != p)
				ans += f(e[x][i], x);
		return ff[x] = ans;
	}
	int sum = 0;
	for (int i = 0; i < e[x].size(); ++i)
		if (e[x][i] != p)
			sum += g(e[x][i], x);
	int ans = 1000000;
	for (int i = 0; i < e[x].size(); ++i)
		if (e[x][i] != p)
			for (int j = i + 1; j < e[x].size(); ++j)
				if (e[x][j] != p)
					ans = min(ans, sum - g(e[x][i], x) - g(e[x][j], x) + f(e[x][i], x) + f(e[x][j], x));
	return ff[x] = ans;
}

void dfs(int x, int p) {
	A = min(A, f(x, -1));
//cout << "f(" << x << ") = " << f(x, -1) << endl;
	for (int i = 0; i < e[x].size(); ++i)
		if (e[x][i] != p) {
			gg[x] -= gg[e[x][i]];
			gg[e[x][i]] += gg[x];
			ff[x] = -1;
			ff[e[x][i]] = -1;
			dfs(e[x][i], x);
			ff[x] = -1;
			ff[e[x][i]] = -1;
			gg[e[x][i]] -= gg[x];
			gg[x] += gg[e[x][i]];
		}
}

int solve() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		ff[i] = gg[i] = -1;
		e[i].clear();
	}
	for (int i = 0; i < N - 1; ++i) {
		int X, Y;
		cin >> X >> Y;
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	A = 1000000;
	g(1, -1);
	dfs(1, -1);
	return A;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
		cout << "Case #" << i << ": " << solve() << endl;
}
