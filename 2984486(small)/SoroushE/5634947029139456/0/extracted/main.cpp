#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 200;
string a[MAXN], b[MAXN], c[MAXN];
bool mark[MAXN];

int main() {
	int t;
	cin >> t;
	for (int o = 1; o <= t; o++) {
		int n, l, ans = 1e9;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(b, b + n);
		for (int i = 0; i < n; i++) {
			memset(mark, 0, sizeof mark);
			int cnt = 0;
			for (int j = 0; j < l; j++)
				if (a[0][j] != b[i][j])
					mark[j] = true, cnt++;
			for (int j = 0; j < n; j++) {
				c[j] = a[j];
				for (int k = 0; k < l; k++)
					if (mark[k])
						c[j][k] = '1' + '0' - c[j][k];
			}
			sort(c, c + n);
			bool good = true;
			for (int j = 0; j < n; j++)
				if (c[j] != b[j])
					good = false;
			if (good)
				ans = min(ans, cnt);
		}
		cout << "Case #" << o << ": ";
		if (ans == 1e9)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
