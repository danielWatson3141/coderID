#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int hamming(long long a, long long b, int l) {
	a ^= b;
	int s = 0;
	for (int i = 0; i < l; ++i) {
		s += a & 1LL; a >>= 1;
	}
	return s;
}
long long p(int l) {
	long long r = 1;
	for (int i = 0; i < l; ++i) {
		r *= 2;
	}
	return r;
}
void fu() {
	int n, l; cin >> n >> l;
	long long ll;
	string s;
	vector<long long> vs, vd;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		ll = s[0] - '0';
		for (int j = 1; j < l; ++j) {
			ll <<= 1;
			ll += s[j] - '0';
		}
		vs.push_back(ll);
	}
	for (int i = 0; i < n; ++i) {
		cin >> s;
		ll = s[0] - '0';
		for (int j = 1; j < l; ++j) {
			ll <<= 1;
			ll += s[j] - '0';
		}
		vd.push_back(ll);
	}
	//for (int i = 0; i < n; ++i) cout << vs[i] << ' '; cout << endl;
	//for (int i = 0; i < n; ++i) cout << vd[i] << ' '; cout << endl;
	sort(vs.begin(), vs.end());
	sort(vd.begin(), vd.end());

	int d = 0;
	long long m = p(l);
	while (d < m) {
		bool y = true;
		for (int i = 0; i < n; ++i)
			if (vs[i] != vd[i]) {
				y = false;
				break;
			}
		if (y) {
			int re = 0;
			for (int i = 0; i < l; ++i) {
				re += d & 1; d >>= 1;
			}
			cout << re << endl;
			return;
		}
		for (int i = 0; i < n; ++i)
			vs[i] ^= d;
		++d;
		for (int i = 0; i < n; ++i)
			vs[i] ^= d;
		sort(vs.begin(), vs.end());
	}
	cout << "NOT POSSIBLE" << endl;
}
int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		fu();
	}
}
