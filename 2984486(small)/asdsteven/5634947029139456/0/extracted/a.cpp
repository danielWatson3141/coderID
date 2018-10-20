#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, L;
string a[150], b[150], c[150];

int f(int x) {
	if (x >= L)
		return 0;
	bool k = true;
	for (int i = 0; i < N; ++i)
		if (a[i][x] != b[i][x]) {
			k = false;
			break;
		}
	int ans = 10000;
	if (k)
		ans = min(ans, f(x + 1));
	k = true;
	for (int i = 0; i < N; ++i)
		a[i][x] = a[i][x] == '0' ? '1' : '0';
	sort(a, a + N);
	for (int i = 0; i < N; ++i)
		if (a[i][x] != b[i][x]) {
			k = false;
			break;
		}
	if (k)
		ans = min(ans, 1 + f(x + 1));
	return ans;
}

int solve() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	sort(a, a + N);
	int ans = 10000;
	sort(b, b + N);
	for (int i = 0; i < 1 << L; ++i) {
		int k = 0;
		for (int j = 0; j < N; ++j)
			c[j] = a[j];
		for (int j = 0; j < L; ++j) {
			if (i & 1 << j) {
				++k;
				for (int l = 0; l < N; ++l)
					c[l][j] = c[l][j] == '0' ? '1' : '0';
			}
		}
		bool ff = true;
		sort(c, c + N);
		for (int j = 0; j < N; ++j)
			if (c[j] != b[j])
				ff = false;
		if (ff)
			ans = min(ans, k);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		int ans = solve();
		if (ans == 10000)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}
}
