#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> g[1000]; // neighbors

// First is total nodes, second is nodes to be cut if selected
pair<int,int> root_cut(int node, int from) {
	vector<pair<int,int> > cuts;
	int total_children = 0;
	for (size_t i=0; i<g[node].size(); i++) {
		if (g[node][i] == from) continue;
		pair<int,int> info = root_cut(g[node][i], node);
		//cout << "Node " << g[node][i] << " from " << node << " has " << info.first << " / " << info.second << "\n";
		total_children += info.first;
		cuts.push_back(info);
	}
	if (cuts.size() == 0) return make_pair(1, 0);
	if (cuts.size() == 1) return make_pair(cuts[0].first + 1, cuts[0].first);
	if (cuts.size() == 2) return make_pair(cuts[0].first + cuts[1].first + 1, cuts[0].second + cuts[1].second);
	// Select 2 from cuts
	pair<int,int> result = make_pair(total_children + 1, total_children);
	for (size_t i=0; i<cuts.size(); i++) {
		for (size_t j=i+1; j<cuts.size(); j++) {
			int ncut = total_children - cuts[i].first - cuts[j].first + cuts[i].second + cuts[j].second;
			if (ncut < result.second) result.second = ncut;
		}
	}
	return result;
}

int solve() {
	// Reset
	int n;
	cin >> n;
	for (int i=0; i<n; i++) g[i].resize(0);
	// Read
	for (int i=0; i<n-1; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	// Solve
	int mincut = n-1;
	for (int root=0; root<n; root++) {
		//cout << "Root " << root << "\n";
		pair<int,int> cut = root_cut(root, -1);
		mincut = min(cut.second, mincut);
		assert(cut.first == n);
	}
	return mincut;
}

int main() {
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		cout << "Case #" << casenum << ": " << solve() << "\n";
	}
	return 0;
}