#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Chaos {
public:
	int test(int i, string s, const unordered_multiset<string> &dev, const vector<string> &soc) {
		string x = "";
		int count = 0;
		for(int j = 0; j < s.length(); ++j) {
			if(s[j] != soc[i][j]) {
				++count;
				x += "1";
			} else
				x += "0";
		}

		unordered_multiset<string> soc_set;
		for(int j = 0; j < soc.size(); ++j) {
			string y = "";
			for(int k = 0; k < s.length(); ++k) {
				if(x[k] == '0')
					y += soc[j][k];
				else if(soc[j][k] == '0')
					y += "1";
				else
					y += "0";
			}

			soc_set.insert(y);
		}

		if(dev == soc_set)
			return count;
		else
			return 9999;
	}

	void go(istream &in, ostream &out) {
		int t;
		in >> t;

		for(int i = 1; i <= t; ++i) {
			int n, l;
			in >> n >> l;

			string s, first = "";
			vector<string> soc;
			unordered_multiset<string> dev;

			for(int j = 0; j < n; ++j) {
				in >> s;
				soc.push_back(s);
			}

			for(int j = 0; j < n; ++j) {
				in >> s;
				dev.insert(s);
				if(j == 0)
					first = s;
			}

			int m = 9999;
			for(int j = 0; j < n; ++j) {
				int x = test(j, first, dev, soc);
				if(x < m)
					m = x;
			}

			if(m < 9999)
				out << "Case #" << i << ": " << m << endl;
			else
				out << "Case #" << i << ": NOT POSSIBLE" << endl;
		}
	}
};