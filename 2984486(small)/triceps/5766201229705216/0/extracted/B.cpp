#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int, set<int>> Graph;

int CountChild(Graph& g, int p, set<int>& checked)
{
	int n = 1;
	for (auto c : g[p]) {
		if (checked.insert(c).second) {
			n += CountChild(g, c, checked);
		}
	}
	return n;
}

int rec(Graph& g, int p, set<int>& checked)
{
	vector<int> child;

	for (auto c : g[p]) {
		if (checked.insert(c).second) {
			child.push_back(c);
		}
	}

	if (child.empty()) return 0;

	if (child.size() == 1) {
		return CountChild(g, child[0], checked);
	}

	int ret = g.size();
	for (int i = 0; i < child.size(); i++) {
		for (int j = i + 1; j < child.size(); j++) {
			// keep child[i] and child[j]
			auto checked2 = checked;
			int n = rec(g, child[i], checked2) + rec(g, child[j], checked2);
			vector<int> rest;
			for (int k = 0; k < child.size(); k++) {
				if (k != i && k != j) {
					n += CountChild(g, child[k], checked2);
				}
			}
			ret = min(ret, n);
		}
	}
	return ret;
}

int Solve(Graph& g)
{
	int ret = g.size();
	for (auto n : g) {
		set<int> checked;
		checked.insert(n.first);
		int x = rec(g, n.first, checked);
		ret = min(ret, x);
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		Graph g;
		for (int i = 0; i < N - 1; i++) {
			int p, c;
			cin >> p >> c;
			g[p].insert(c);
			g[c].insert(p);
		}
		printf("Case #%d: %d\n", t, Solve(g));
	}

	return 0;
}