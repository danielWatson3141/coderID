#include <bits/stdc++.h>
using namespace std;
void func() {
	int N, L;
	cin >> N >> L;
	vector<long long> a(N);
	set<long long> b;
	for (int i = 0; i < N; ++ i) {
		string s;
		cin >> s;
		long long x = 0;
		for (int j = 0; j < L; ++ j) if (s[j] == '1') x |= 1LL<<j;
		a[i] = x;
	}
	for (int i = 0; i < N; ++ i) {
		string s;
		cin >> s;
		long long x = 0;
		for (int j = 0; j < L; ++ j) if (s[j] == '1') x |= 1LL<<j;
		b.insert(x);
	}
	int r = 1<<30;
	for (long long x : a) for (long long y : b) {
		set<long long> c;
		for (long long z : a) c.insert(x^y^z);
		if (b == c) {
			r = min(r, __builtin_popcountll(x^y));
		}
	}
	if (r == 1<<30) {
		cout << "NOT POSSIBLE" << endl;
	} else {
		cout << r << endl;
	}
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": ";
		func();
	}
}
