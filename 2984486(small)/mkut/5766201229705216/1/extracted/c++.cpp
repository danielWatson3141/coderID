#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class solver {
	int N;
	vector<vector<int> > adj;

public:
	solver(vector<vector<int> >& adj) : N(adj.size()), adj(adj), ans(0) {}

	int solve() {
		for (int a = 0; a < N; a++) {
			ans = max(ans, solve(-1, a));
		}
		return ans;
	}
	int solve(int from, int a) {
		pair<int, int> key = make_pair(from, a);
		if (memo.count(key)) {
			return memo[key];
		}

		if (adj[a].size() >= 3 || (adj[a].size() == 2 && from == -1)) {
			vector<int> sz;
			for (int i = 0; i < adj[a].size(); i++) {
				int b = adj[a][i];
				if (b != from) {
					sz.push_back(solve(a, b));
				}
			}
			sort(sz.begin(), sz.end());
			return memo[key] = sz[sz.size()-1] + sz[sz.size()-2] + 1;
		} else {
			return memo[key] = 1;
		}
	}

private:
	int ans;
	map<pair<int, int>, int> memo;
};

int main() {
	int T; cin >> T;
	for (int No = 1; No <= T; No++) {
		int N; cin >> N;
		vector<vector<int> > adj(N);
		for (int i = 0; i < N-1; i++) {
			int x, y; cin >> x >> y;
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		solver prob(adj);
		int ans = N - prob.solve();
		cout << "Case #" << No << ": " << ans << endl;
	}
	return 0;
}
