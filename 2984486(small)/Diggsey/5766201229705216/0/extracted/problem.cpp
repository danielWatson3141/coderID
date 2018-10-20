#include "stdafx.h"

struct node {
	vector<int> edges;
};

pair<int, int> traverse(vector<node> const& tree, int start, int from) {
	pair<int, int> result(1, 0);
	node const& n = tree[start];
	bool foundR1 = false, foundR2 = false;
	int bestR1 = 0, bestR2 = 0;

	for (int i = 0; i < n.edges.size(); ++i) {
		int m = n.edges[i];
		if (m == from)
			continue;

		auto r = traverse(tree, m, start);
		result.first += r.first;
		result.second += r.first;

		int score = r.first - r.second;

		if (score > bestR1 || !foundR1) {
			bestR2 = bestR1;
			foundR2 = foundR1;
			bestR1 = score;
			foundR1 = true;
		} else if (score > bestR2 || !foundR2) {
			bestR2 = score;
			foundR2 = true;
		}
	}

	if (foundR1 && foundR2) {
		result.second -= (bestR1 + bestR2);
	}

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t >> ws;

	for (int i = 1; i <= t; ++i) {
		int n;
		input >> n;

		vector<node> tree(n);
		for (int j = 1; j < n; ++j) {
			int a, b;
			input >> a >> b;
			--a;
			--b;
			tree[a].edges.push_back(b);
			tree[b].edges.push_back(a);
		}

		int best = 1000000;
		for (int j = 0; j < n; ++j) {
			auto r = traverse(tree, j, -1);
			best = min(best, r.second);
		}

		output << "Case #" << i << ": " << best << endl;
	}


	return 0;
}

