#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1111;
int n, m, a[MAX_N], b[MAX_N];
int vis[MAX_N];

double x[MAX_N], ans[2];
int T, N, K;

double gao() {
	double cc = 0.0;
	double mid = (n - 1) / 2.0 / n;
	for (int i = 0; i < n; i++) {
		mid = i * 1.0 / n;
		cc += fabs(x[i] - mid);
	}
	return cc;
}

int main() {
	FILE * in, * in2;
	in = fopen("out.txt", "r");
	in2 = fopen("in.txt", "r");
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(in, "%d", a + i);
		vis[a[i]] = 0;
	}
	fscanf(in, "%d", &m);
	for (int i = 0; i < m; i++) {
		fscanf(in, "%d", b + i);
		vis[b[i]] = 1;
	}
	fscanf(in2, "%d%d%d", &T, &N, &K);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(in2, "%lf", x + j);
			ans[vis[i]] += gao();
		}
	}
	fprintf(stderr, "%.9lf\t%.9lf\n", ans[0], ans[1]);
	bool aa[2];
	if (ans[0] < ans[1]) {
		aa[0] = true;
		aa[1] = false;
	} else {
		aa[0] = false;
		aa[1] = true;
	}
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: %s\n", i, aa[vis[i]] ? "GOOD" : "BAD");
	}
	return 0;
}
