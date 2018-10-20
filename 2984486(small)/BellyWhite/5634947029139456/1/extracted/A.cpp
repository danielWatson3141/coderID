#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool check(vector<LL> a, const vector<LL>& b, LL s) {
	for (int i = 0; i < (int)a.size(); ++i) a[i] ^= s;
	sort(a.begin(), a.end());
	return a == b;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<LL> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			char s[200];
			scanf("%s", s);
			for (int j = 0; j < m; ++j) {
				if (s[j] != '0') a[i] |= 1LL << j;
			}
		}
		for (int i = 0; i < n; ++i) {
			char s[200];
			scanf("%s", s);
			for (int j = 0; j < m; ++j) {
				if (s[j] != '0') b[i] |= 1LL << j;
			}
		}
		sort(b.begin(), b.end());
		int ans = m + 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				LL s = a[i] ^ b[j];
				int c = __builtin_popcountll(s);
				if (c < ans && check(a, b, s)) {
					ans = c;
				}
			}
		}
		printf("Case #%d: ", cas);
		if (ans == m + 1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
}
