#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int getV() {
	string s;
	cin >> s;
	int ret = 0;
	for (auto& c : s) ret = ret * 2 + c - '0';
	return ret;
}

int cntBits(int v) {
	int ret = 0;
	while (v) {
		ret += v & 1;
		v >>= 1;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N, L;
		cin >> N >> L;
		vector<int> in(N), out(N);
		for (auto& i : in) i = getV();
		for (auto& i : out) i = getV();
		set<int> sout(out.begin(), out.end());

		int ret = L + 1;
		for (int i = 0; i < (1 << L); ++i) {
			bool ok = true;
			for (auto& v : in) {
				if (sout.find(v^i) == sout.end()) {
					ok = false;
					break;
				}
			}
			if (ok) ret = min(ret, cntBits(i));
		}

		cout << "Case #" << q << ": ";
		if (ret == L + 1) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;
	}
	return 0;
}