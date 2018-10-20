#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int nTest;
int a[1000];
double f[1010][1010];

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("Output.txt", "w", stdout);

	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++) {
		int n;
		
		scanf("%d", &n);

		double p1 = log(1);
		int k = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			if (a[i] == i) {
				p1 -= log(n - i);
				k++;
			}
		}
		
		double p2 = -log(n)*n;
		if (k) p2 = 1e9;
		f[0][0] = 0;
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (j) f[i][j] = f[i - 1][j - 1];
				if (j < i - 1) {
					f[i][j] = f[i - 1][j + 1] + log(j + 1);
					f[i][j] = f[i][j] + log(1.0 + exp(f[i][j] - f[i - 1][j - 1]));
				}
			}
		}
		for (int j = 0; j <= k; j++)
			p2 += f[n][j];
		//cout << p1 << " " << p2 << endl;
		if (p1 < p2) printf("Case #%d: BAD\n", test);
		else printf("Case #%d: GOOD\n", test);
	}

	return 0;
}