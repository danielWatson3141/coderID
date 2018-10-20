#include "stdafx.h"

int solve(vector<string>& as, vector<string>& bs, int bit, int l) {
	if (bit == l)
		return 0;

	map<string, pair<int, int> > acs;
	map<string, pair<int, int> > bcs;

	for (int i = 0; i < as.size(); ++i) {
		string prefix = as[i].substr(0, bit);
		if (as[i][bit] == '1')
			++acs[prefix].first;
		else
			++acs[prefix].second;
	}
	for (int i = 0; i < bs.size(); ++i) {
		string prefix = bs[i].substr(0, bit);
		if (bs[i][bit] == '1')
			++bcs[prefix].first;
		else
			++bcs[prefix].second;
	}

	bool valid0 = true;
	bool valid1 = true;

	for (auto i = acs.begin(); i != acs.end(); ++i) {
		auto v1 = i->second;
		auto v2 = bcs[i->first];

		if (v1 != v2)
			valid0 = false;
		if (v1.second != v2.first || v1.first != v2.second)
			valid1 = false;
		if (!valid0 && !valid1)
			return -1;
	}

	int bestResult = -1;
	if (valid0) {
		int result = solve(as, bs, bit + 1, l);
		if (result != -1 && (result < bestResult || bestResult == -1))
			bestResult = result;
	}
	if (valid1) {
		for (int i = 0; i < as.size(); ++i) {
			if (as[i][bit] == '1') {
				as[i][bit] = '0';
			} else {
				as[i][bit] = '1';
			}
		}
		int result = solve(as, bs, bit + 1, l);
		for (int i = 0; i < as.size(); ++i) {
			if (as[i][bit] == '1') {
				as[i][bit] = '0';
			} else {
				as[i][bit] = '1';
			}
		}
		if (result != -1 && (result+1 < bestResult || bestResult == -1))
			bestResult = result + 1;
	}

	return bestResult;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t >> ws;

	for (int k = 1; k <= t; ++k) {
		int n, l;
		input >> n >> l;

		vector<string> as(n);
		vector<string> bs(n);

		for (int i = 0; i < n; ++i) {
			input >> as[i];
		}
		for (int i = 0; i < n; ++i) {
			input >> bs[i];
		}

		int numSwitches = solve(as, bs, 0, l);

		output << "Case #" << k << ": ";
		if (numSwitches == -1) {
			output << "NOT POSSIBLE" << endl;
		} else {
			output << numSwitches << endl;
		}
	}


	return 0;
}

