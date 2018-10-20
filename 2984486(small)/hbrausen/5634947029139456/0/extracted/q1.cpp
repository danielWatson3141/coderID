#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

unsigned int parsebin(string s, int L)
{
	int ret;
	ret = 0;
	for (int j = 0; j < L; ++j) {
		if (s[s.size()-1-j] == '1') {
			ret += 1<<j;
		}
	}
	return ret; 
}

unsigned int countones(unsigned int n)
{
	int ret = 0;
	while (n != 0) {
		if (n & 0x01) ++ret;
		n = n >> 1;
	}
	return ret;
}

int main()
{
	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; ++tc) {
		cout << "Case #" << tc+1 << ": ";
		int N,L;
		cin >> N;
		cin >> L;
		vector<unsigned int> start;
		set<unsigned int> req;
		unsigned int temp;
		string temps;
		for (int i = 0; i < N; ++i) {
			cin >> temps;
			start.push_back(parsebin(temps,L));
		}
		for (int i = 0; i < N; ++i) {
			cin >> temps;
			req.insert(parsebin(temps,L));
		}
		int minones = 1024;
		for (unsigned int flipset = 0; flipset < 1<<L; ++flipset) {
			int workedcount = 0;
			for (int i = 0; i < start.size(); ++i) {
				if (req.count(start[i]^flipset) != 0) ++workedcount;
			}
			if (workedcount == start.size()) {
				if (countones(flipset) < minones) {
					minones = countones(flipset);
				}
			}
		}
		if (minones == 1024) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << minones << endl;
		}
	}
	return 0;
}

