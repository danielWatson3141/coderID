#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;

int dfs(int v, int p) {
	if (p == -1 && adj[v].size() == 0) return 1;
	if (p != -1 && adj[v].size() == 1) return 1;
	if (p == -1 && adj[v].size() < 2) return 1;
	if (p != -1 && adj[v].size() < 3) return 1;
	int m1 = 0, m2 = 0;
	for (int i = 0; i < adj[v].size(); i++) {
		if (adj[v][i] == p) continue;
		int cnt = dfs(adj[v][i], v);
		if (cnt > m1) {
			m2 = m1;
			m1 = cnt;
		}
		else if (cnt > m2) {
			m2 = cnt;
		}
	}
	return m1 + m2 + 1;
}


int main() {
	ifstream inf("B-large.in");
	ofstream outf("output.txt");

	int T; inf >> T;
	for (int tc = 1; tc <= T; tc++) {
		outf << "Case #" << tc << ": ";
		int N; inf >> N;
		adj.clear();
		adj.resize(N);
		for (int i = 0; i < N - 1; i++) {
			int x, y; inf >> x >> y;
			--x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int m = 0;
		for (int i = 0; i < N; i++) {
			m = max(m, dfs(i, -1));
		}
		outf << N - m << "\n";
	} 
}