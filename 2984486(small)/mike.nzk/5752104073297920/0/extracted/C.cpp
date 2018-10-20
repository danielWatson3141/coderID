#include <cstdio>
int a[1000];
int main() {
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; _++) {
		printf("Case #%d: ", _);
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x); a[x] = i;
		}
		long long s = 0;
		for (int i = 0; i < n; i++)
			s += i * (i - a[i]);
		if (s < 81000000) puts("BAD");
		else puts("GOOD");
	}
	return 0;
}
