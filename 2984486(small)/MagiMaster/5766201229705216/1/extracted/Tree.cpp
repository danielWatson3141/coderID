#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
	vector<vector<int>> edges;
	
	void addEdge(int i, int j) {
		while(edges.size() <= i || edges.size() <= j)
			edges.push_back(vector<int>());
		edges[i].push_back(j);
		edges[j].push_back(i);
	}

	vector<int> from(int i) {
		return edges[i];
	}

	int degree(int i) {
		return edges[i].size();
	}
};

class TreeTest {
public:
	Tree t;

	// cost, size
	pair<int, int> test(int i, int p = 0) {
		vector<int> ns = t.from(i);

		if(ns.size() == 1) {
			if(p == 0) {
				auto z = test(ns[0], i);
				return make_pair(z.second, z.second + 1);
			} else
				return make_pair(0, 1);
		}

		if(ns.size() == 2) {
			if(p == 0) {
				auto z1 = test(ns[0], i);
				auto z2 = test(ns[1], i);
				return make_pair(z1.first + z2.first, z1.second + z2.second + 1);
			} else if(ns[0] == p) {
				auto z = test(ns[1], i);
				return make_pair(z.second, z.second + 1);
			} else {
				auto z = test(ns[0], i);
				return make_pair(z.second, z.second + 1);
			}
		}

		int size = 0;
		int best1 = 99999, best2 = 99999;
		for(int j = 0; j < ns.size(); ++j) {
			if(ns[j] == p)
				continue;

			auto z = test(ns[j], i);
			size += z.second;
			int d = z.first - z.second;
			if(d < best1) {
				best2 = best1;
				best1 = d;
			} else if(d < best2)
				best2 = d;
		}

		return make_pair(size + best1 + best2, size + 1);
	}

	void go(istream &in, ostream &out) {
		int cases;
		in >> cases;

		for(int i = 1; i <= cases; ++i) {
			int n;
			in >> n;

			t = Tree();
			for(int j = 1; j < n; ++j) {
				int x, y;
				in >> x >> y;
				t.addEdge(x, y);
			}

			int best = 99999;
			for(int j = 1; j < t.edges.size(); ++j) {
				auto z = test(j);
				if(z.first < best)
					best = z.first;
			}

			out << "Case #" << i << ": " << best << endl;
		}
	}
};