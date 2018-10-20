#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1111;
int a[MAX_N], n, ni;
double x[MAX_N], o[MAX_N];

bool gao(double x[]) {
	double y = 0.0;
	sort(x, x + n);
	for (int i = 0; i < n; i++) {
		y += x[i];
	}
	y /= n;
	double mid = (n - 1) / 2.0 / n;
	double c1 = 0.0, c2 = 0.0, c3 = 0.0;
	for (int i = 0; i < n; i++) {
		mid = i * 1.0 / n;
		c1 += (x[i] - mid) * (x[i] - mid);
		c2 += fabs(x[i] - mid);
		c3 += x[i] - mid;
	}
	if (c1 > 0.4) {
		return false;
	}
	if (fabs(c2) > 16.9) {
		return false;
	}
	if (fabs(c3) > 11) {
		return false;
	}
//	if (fabs(fabs(c2) - fabs(c3)) > 5) {
//		return false;
//	}
	return true;
}

int main() {
	srand(time(NULL));
	int n_case = 0;
	scanf("%d", &n_case);
	//n_case = 120;
	printf("%d %d %d\n", 120, 1000, 2);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n);
		//n = 1000;
		for (int i = 0; i < n; i++) {
			a[i] = i;
			scanf("%d", a + i);
		}
		for (int i = 0; i < n; i++) {
			//int p = (lint)rand() * (n - i) / (1 + RAND_MAX) + i;
			//int p = (lint)rand() * n / (1 + RAND_MAX);
			//swap(a[i], a[p]);
		}
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = i; j < n; j++) {
				if (a[j] <= a[i]) {
					tmp++;
				}
			}
			x[i] = (double)tmp / (n - i);
		}
		sort(x, x + n);
		for (int i = 0; i < n; i++) {
			printf("%.9lf%c", x[i], " \n"[i == n - 1]);
		}
		// printf("Case #%d: %s\n", ca, gao(x) ? "GOOD" : "BAD");
	}
	return 0;
}
