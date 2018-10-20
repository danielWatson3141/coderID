#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int T, N, L;
long long dev[155], out[155], tmp[155];
void solve() {	
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		long long x = 0;
		for (int j = 0; j < L; ++j) {
			x <<= 1;
			x += (s[j] == '1');
		}
		out[i] = x;
	}
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		long long x = 0;
		for (int j = 0; j < L; ++j) {
			x <<= 1;
			x += (s[j] == '1');
		}
		dev[i] = x;
	}
	sort(dev, dev + N);
	// cerr << N << " ";
	int ans = L + 1;
	for (int i = 0; i < N; ++i) {
		long long mask = out[0] ^ dev[i];
		for (int j = 0; j < N; ++j) {
			tmp[j] = out[j] ^ mask;
		}
		sort(tmp, tmp + N);
		bool flag = true;
		for (int j = 0; j < N; ++j) {
			if (tmp[j] != dev[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			int c = 0;
			for (int j = 0; j < L; ++j) c += (mask & (1 << j)) ? 1 : 0;
			ans = min(ans, c);
		    // cerr << "mask = " << mask << " ";
		}
	}
	// cerr << "L = " << L << " ans = " << ans << endl;
	if (ans == L + 1) {
		cout << "NOT POSSIBLE" << endl;
	} else {
		cout << ans << endl;
	}
}
int main() {
	// freopen("in", "r", stdin);
	freopen("A-small-attempt9.in", "r", stdin);
	freopen("A-small-attempt9.out", "w", stdout);
	cin >> T;
	for (int _  = 1; _ <= T; ++_) {
		cout << "Case #" << _ << ": ";
		solve();
	}
	return 0;
}