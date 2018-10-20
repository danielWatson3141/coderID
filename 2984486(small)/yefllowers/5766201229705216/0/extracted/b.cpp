#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> e[1050];
int s[1050];

int dfs(int i, int f) {
	vector<int> a;
	s[i] = 1;
	for (int j = 0; j < (int) e[i].size(); j++) {
		int p = e[i][j];
		if (p == f) continue;
		a.push_back(dfs(p, i));
		s[i] += s[p];
	}
	if (a.size() < 2) return 1;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	return 1 + a[0] + a[1];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 2; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dfs(i, -1));
	cout << (n - ans);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}