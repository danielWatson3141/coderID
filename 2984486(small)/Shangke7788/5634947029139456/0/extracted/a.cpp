#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 222;
const int INF = 100000;
lint a[MAX_N], b[MAX_N], c[MAX_N];
char s[MAX_N];

lint getX(char *s) {
	lint res = 0;
	while (*s) {
		res = (res << 1) + (*s - '0');
		s++;
	}
	return res;
}
int calc(lint t) {
	int x = 0;
	while (t != 0) {
		x += t & 1;
		t >>= 1;
	}
	return x;
}
int n, l;

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			a[i] = getX(s);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			b[i] = getX(s);
		}
		int ans = INF;
		sort(b, b + n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				lint t = a[i] ^ b[j];
				for (int k = 0; k < n; k++) {
					c[k] = a[k] ^ t;
				}
				sort(c, c + n);
				bool ok = true;
				for (int k = 0; k < n; k++) {
					if (c[k] != b[k]) {
						ok = false;
						break;
					}
				}
				if (ok) ans = min(ans, calc(t));
			}
		}
		if (ans == INF) {
			printf("Case #%d: NOT POSSIBLE\n", ca);
		} else {
			printf("Case #%d: %d\n", ca, ans);
		}
	}
	return 0;
}
