#include <cstdio>
#include <algorithm>
char s[100];
long long a[150], b[150], c[150];
int n, l;
long long toint(char *s) {
	long long t = 0;
	for (int i = 0; i < l; i++) t = (t<<1) + s[i]-48;
	return t;
}
void solve() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++) scanf("%s", s), a[i] = toint(s);
	for (int i = 0; i < n; i++) scanf("%s", s), b[i] = toint(s);
	std::sort(a, a + n);
	int ans = ~0U>>1;
	for (int i = 0; i < n; i++) {
		long long t = a[0] ^ b[i];
		for (int i = 0; i < n; i++) c[i] = b[i] ^ t;
		std::sort(c, c + n);
		int flag = 1;
		for (int i = 0; i < n; i++)
			if (c[i] != a[i]) flag = 0;
		if (flag) {
			int m = __builtin_popcountll(t);
			if (m < ans) ans = m;
		}
	}
	if (ans > l) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}
int main() {
	int _ = 0, T;
	scanf("%d", &T);
	while (T--)
		printf("Case #%d: ", ++_), solve();
	return 0;
}
