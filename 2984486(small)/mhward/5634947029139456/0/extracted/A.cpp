#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

vector<int> flips(string& bitsa, string& bitsb) {
	vector<int> flips;
	for (int i = 0; i < bitsa.size(); ++i)
		if (bitsa[i] != bitsb[i])
			flips.push_back(i);
	return flips;
}

bool test(vector<int>& flips, vector<string> from, vector<string>& to) {

	for (int i = 0; i < from.size(); ++i) {
		for (int j = 0; j < flips.size(); ++j) {
			from[i][flips[j]] = (from[i][flips[j]] == '0') ? '1' : '0';
		}

	}
	vector<bool> matched(to.size(), false);
	for (int i = 0; i < from.size(); ++i) {
		for (int j = 0; j < to.size(); ++j)
			if (from[i] == to[j])
				matched[i] = true;
	}
	for (int i = 0; i < matched.size(); ++i)
		if (!matched[i])
			return false;
	return true;
}

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; ++kase) {
		int n, l;
		cin >> n >> l;
		string in;
		vector<string> from;
		vector<string> to;
		for (int j = 0; j < n; ++j) {
			cin >> in;
			from.push_back(in);
		}
		for (int j = 0; j < n; ++j) {
			cin >> in;
			to.push_back(in);
		}
		vector<vector<int> > all_flips;
		for (int i = 0; i < from.size(); ++i)
			for (int j = 0; j < to.size(); ++j)
				all_flips.push_back(flips(from[i], to[j]));

		// cout << "all flips size " << all_flips.size() << endl;
		// for (int i = 0; i < all_flips.size(); ++i) {
		// 	for (int j = 0; j < all_flips[i].size(); ++j) {
		// 		cout << all_flips[i][j];

		// 	}
		// 	cout << endl;
		// }
		// cout << "end all flips" << endl;

		int min = -1;
		for (int i = 0; i < all_flips.size(); ++i) {
			// cout << min << endl;
			if (!test(all_flips[i], from, to))
				continue;
			if (min == -1)
				min = all_flips[i].size();
			else if (all_flips[i].size() < min)
				min = all_flips[i].size();
		}
		if (min == -1)
			printf("Case #%d: NOT POSSIBLE\n", kase);
		else
			printf("Case #%d: %d\n", kase, min);
		
	}
	return 0;
}