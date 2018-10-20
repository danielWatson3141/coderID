#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> rec(size_t i, const vector<vector<int> >& e, vector<int>& v) {
	v[i] = true;
	int best1 = 0, best2 = 0;
	int children = 0, count = 0;
	for (size_t j = 0; j < e[i].size(); ++j) {
		if (!v[e[i][j]]) {
			++count;
			pair<int, int> r = rec(e[i][j], e, v);
			children += r.second;
			if (r.first > best1) {
				best2 = best1;
				best1 = r.first;
			} else if (r.first > best2) {
				best2 = r.first;
			}
		}
	}
	if (count < 2) {
		return make_pair(1, children + 1);
	} else {
		return make_pair(1 + best1 + best2, children + 1);
	}
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<vector<int> > e(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y;
			e[x - 1].push_back(y - 1);
			e[y - 1].push_back(x - 1);
		}

		int best = 0;
		for (int i = 0; i < n; ++i) {
			vector<int> v(n, 0);
			pair<int, int> r = rec(i, e, v);
			if (r.first > best) {
				best = r.first;
			}
		}
		cout << "Case #" << test << ": " << (n - best) << endl;
	}
}
