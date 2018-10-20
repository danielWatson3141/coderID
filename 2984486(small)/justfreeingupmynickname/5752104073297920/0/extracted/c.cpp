#include <cstdio>
#define CUTOFF 254693

int t, n, ar[1234], bit[1234];
int qry(int at) {
	int res = 0;
	while (at) {
		res += bit[at];
		at -= (at & -at);
	}
	return res;
}
void upd(int at) {
	while (at <= n) {
		bit[at]++;
		at += (at & -at);
	}
}
int main() {
	int g = 0;
	freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		printf("Case #%d: ", tc);
		scanf("%d", &n);
		int inv = 0;
		for (int i = 0; i < n; i++) scanf("%d", ar+i);
		for (int i = 0; i <= n; i++) bit[i] = 0;
		for (int i = 0; i < n; i++) {
			inv += qry(ar[i]+1);
			upd(ar[i]+1);
		}
		if (inv < CUTOFF) g++;
		printf("%d ", inv);
		puts(inv < CUTOFF ? "GOOD" : "BAD");
	}
	//printf("%d\n", g);

	return 0;
}