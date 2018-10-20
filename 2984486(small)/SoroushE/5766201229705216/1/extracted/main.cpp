#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
vector<int> ng[MAXN];
int dp[MAXN];

int dfs(int x, int p) {
	vector<int> c;
	for (int i = 0; i < ng[x].size(); i++) {
		int u = ng[x][i];
		if (u != p)
			c.push_back(dfs(u, x));
	}
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	if (c.size() <= 1)
		dp[x] = 1;
	else
		dp[x] = 1 + c[0] + c[1];
	return dp[x];
}

int main() {
	int t;
	cin >> t;
	for (int o = 1; o <= t; o++) {
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			ng[x].push_back(y);
			ng[y].push_back(x);
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			memset(dp, -1, sizeof dp);
			ans = min(ans, n - dfs(i, -1));
		}
		cout << "Case #" << o << ": " << ans << endl;
		for (int i = 0; i < n; i++)
			ng[i].clear();
	}
	return 0;
}
