#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(int n, int len, vector<string> & a, vector<string> & b)
{
	sort(b.begin(), b.end());
	int ans = len+1;
	for (int i = 0; i < n; i++) {
		vector<bool> same(len);
		for (int j = 0; j < len; j++) {
			same[j] = a[0][j] == b[i][j];
		}
		vector<string> c(a);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < len; k++) {
				if (!same[k]) {
					if (c[j][k] == '0') {
						c[j][k] = '1';
					}
					else {
						c[j][k] = '0';
					}
				}
			}
		}
		sort(c.begin(), c.end());
		if (c == b) {
			ans = min(ans, count(same.begin(), same.end(), false));
		}
	}
	return ans;
}

int main()
{
	int ntest;
	cin >> ntest;
	for (int i = 0; i < ntest; i++) {
		int n, len;
		cin >> n >> len;
		vector<string> a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		vector<string> b(n);
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		int ans = solve(n, len, a, b);
		printf("Case #%d: ", i+1);
		if (ans <= len) {
			printf("%d\n", ans);
		}
		else {
			puts("NOT POSSIBLE");
		}
	}
	return 0;
}
