#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const double eps = 1e-12;

int n, a[N], c[N][N], p[N][N];

int random(int l, int r) {
	int d = r - l;
	return rand() % d + l;
}

void shuffle(int b) {
	for (int i = 0; i < n; ++i) {
		int k = random(b * i, n);
		swap(a[i], a[k]);
	}
}

void init() {
	srand(time(0));
	n = 1000;
	int T = 100000;
	int m = T / n;
	for (int t = 0; t < T; ++t) {
		for (int i = 0; i < n; ++i) a[i] = i;
		shuffle(0);
		for (int i = 0; i < n; ++i) {
			c[i][a[i]]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j] = 1.0 * abs(c[i][j] - m) / m;
		}
	}
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%d", &n);
		double ans = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			ans *= p[i][a[i]];
		}
		printf("Case #%d: ", cas);
		puts(fabs(ans) < eps ? "GOOD" : "BAD");
	}
}
