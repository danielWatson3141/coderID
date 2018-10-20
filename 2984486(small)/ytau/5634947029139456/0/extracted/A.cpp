#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int T, n, l, ans;
string s[200], t[200], u[200];

void trans(int z) {
	for (int i = 0; i < n; ++i) {
		u[i] = s[i];
		for (int j = 0; j < l; ++j) {
			if (s[0][j] != t[z][j]) {
				if (u[i][j] == '0') u[i][j] = '1';
				else u[i][j] = '0';
			}
		}
	}
	sort(u, u+n);
}

bool valid() {
	for (int i = 0; i < n; ++i) {
		if (t[i] != u[i]) return false;
	}
	return true;
}

int count(int z) {
	int ret = 0;
	for (int j = 0; j < l; ++j) {
		if (s[0][j] != t[z][j]) ret++;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}
		sort(s, s+n);
		sort(t, t+n);
		ans = 400;
		for (int i = 0; i < n; ++i) {
			trans(i);
			if (valid()) {
				ans = min(ans, count(i));
			}
		}
		printf("Case #%d: ", tc);
		if (ans > l) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}