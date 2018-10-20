#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string a[155], b[155];
string c[155], d[155];
int v[155];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int ans = m + n + 100;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < m; j++) tmp += (v[j] = a[0][j] != b[i][j]);
		for (int j = 0; j < n; j++) {
			c[j] = a[j];
			for (int k = 0; k < m; k++)
			if (v[k]) c[j][k] = '0' + '1' - c[j][k];
			d[j] = b[j];
		}
		sort(c, c + n);
		sort(d, d + n);
		int ok = true;
		for (int j = 0; j < n && ok; j++) ok &= c[j] == d[j];
		if (ok) ans = min(ans, tmp);
	}
	if (ans > m) {
		cout << "NOT POSSIBLE";
		return ;
	}
	cout << ans;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}