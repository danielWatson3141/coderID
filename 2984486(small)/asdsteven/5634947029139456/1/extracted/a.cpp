#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, L;
string a[150], b[150];

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
	for (int i = 0; i < N; ++i)
		a[i][x] = a[i][x] == '0' ? '1' : '0';
	sort(a, a + N);
	return ans;
}

int solve() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	sort(a, a + N);
	sort(b, b + N);
	return f(0);
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
