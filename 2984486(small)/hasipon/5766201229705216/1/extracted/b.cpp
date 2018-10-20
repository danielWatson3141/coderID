#include <bits/stdc++.h>
using namespace std;
struct FullBinaryTree {
	int N;
	vector<vector<int>> G;
	vector<vector<int>> memo;
	int f(int p, int q) {
		if (memo[p][q]) return memo[p][q];
		if (G[q].size() < 3) return memo[p][q] = 1;
		vector<int> a;
		for (int j : G[q]) if (j != p) {
			a.push_back(f(q, j));
		}
		sort(a.rbegin(), a.rend());
		return memo[p][q] = a[0] + a[1] + 1;
	}
	int func() {
		memo = vector<vector<int>>(N, vector<int>(N));
		int r = 1;
		for (int i = 0; i < N; ++ i) if (G[i].size() >= 2) {
			vector<int> a;
			for (int j : G[i]) a.push_back(f(i, j));
			sort(a.rbegin(), a.rend());
			r = max(r, a[0] + a[1] + 1);
		}
		return r;
	}
	void run() {
		cin >> N;
		G = vector<vector<int>>(N);
		for (int i = 0; i < N-1; ++ i) {
			int x, y;
			cin >> x >> y;
			-- x; -- y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		cout << N - func() << endl;
	}
};
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": ";
		FullBinaryTree inst;
		inst.run();
	}
}
