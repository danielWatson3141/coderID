#include <iostream>
#include <vector>
#include <set>

using namespace std;

int cntBits(int v) {
	int ret = 0;
	while (v) {
		ret += v & 1;
		v >>= 1;
	}
	return ret;
}

int good(vector<set<int>> nearby, int v) {
	int edg = nearby.size() - 1;
	for (int i = 0; i < nearby.size(); ++i) {
		if (v&(1 << i)) {
			for (auto n : nearby[i]) {
				nearby[n].erase(i);
			}
			edg -= nearby[i].size();
			nearby[i].clear();
		}
	}
	edg *= 2;
	int two = 0, three = 0, zero = 0;
	for (int i = 0; i < nearby.size(); ++i) {
		if ((v&(1 << i)) == 0) {
			edg -= nearby[i].size();
			if (nearby[i].size() == 2) ++two;
			else if (nearby[i].size() == 3) ++three;
			else if (nearby[i].size() == 0) ++zero;
			else if (nearby[i].size() == 1) {}
			else return false;
		}
	}
	if (edg != 0) return false;
	return ((two + three) == 0 && zero == 1) || (two == 1 && zero == 0);
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N;
		cin >> N;
		vector<set<int>> nearby(N);
		for (int i = 0; i < N - 1; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			nearby[a].insert(b);
			nearby[b].insert(a);
		}
		int ret = N;
		for (int i = 0; i < (1 << N); ++i) {
			if (good(nearby, i) && ret > cntBits(i)) {
				ret = cntBits(i);
			}
		}
		cout << "Case #" << q << ": " << ret << endl;
	}
	return 0;
}