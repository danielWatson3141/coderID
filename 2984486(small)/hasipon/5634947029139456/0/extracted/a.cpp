#include <bits/stdc++.h>
using namespace std;
void func() {
	int N, L;
	cin >> N >> L;
	vector<int> a(N);
	set<int> b;
	for (int i = 0; i < N; ++ i) {
		string s;
		cin >> s;
		for (int j = 0; j < L; ++ j) if (s[j] == '1') a[i] |= 1<<j;
	}
	for (int i = 0; i < N; ++ i) {
		string s;
		cin >> s;
		int x = 0;
		for (int j = 0; j < L; ++ j) if (s[j] == '1') x |= 1<<j;
		b.insert(x);
	}
	int r = 1<<30;
	for (int i = 0; i < (1<<L); ++ i) {
		set<int> c;
		for (int j = 0; j < N; ++ j) c.insert(a[j] ^ i);
		if (b == c) {
			r = min(r, __builtin_popcount(i));
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
