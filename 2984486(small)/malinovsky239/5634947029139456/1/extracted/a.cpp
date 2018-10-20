#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 155;

LL dig[2][N];
map<LL, int> cnt;

int cnt1s(LL val) {
	int res = 0;
	while (val) {
		res += (val & 1);
		val /= 2;		
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, l;
		cin >> n >> l;
		bool ok = 1;
		for (int q = 0; q < 2; q++) {
			for (int j = 0; j < n; j++) {
				string num;
				cin >> num;
				dig[q][j] = 0;
				for (int k = 0; k < l; k++)
					dig[q][j] = dig[q][j] * 2 + int(num[k] - '0');
			}
			sort(dig[q], dig[q] + n);
			if (unique(dig[q], dig[q] + n) - dig[q] != n) {
				ok = 0;
			}
		}

		if (!ok) {
			printf("Case #%d: NOT POSSIBLE\n", i + 1);
			continue;
		}

		cnt.clear();
		int res = l + 1;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				LL val = (dig[0][j] ^ dig[1][k]);
				if (!cnt.count(val))
					cnt[val] = 0;
				cnt[val] += 1;
				if (cnt[val] == n) {
					res = min(res, cnt1s(val));				
				}
			}	

		if (res > l) {
			printf("Case #%d: NOT POSSIBLE\n", i + 1);
			continue;
		}

		printf("Case #%d: %d\n", i + 1, res);
		
	}
	return 0;
}
