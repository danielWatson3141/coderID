#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

string a[222], b[222], c[222];
int n, l;

map<char, char> M;

bool chk(int sta) {
	for (int i=0; i<n; ++i) {
		c[i] = a[i];
		for (int j=0; j<l; ++j) {
			if ((sta>>j)&1) c[i][j] = M[c[i][j]];
		}
	}
	sort(c, c+n);
	for (int i=0; i<n; ++i)
		if (b[i] != c[i]) return false;
	return true;
}

int main() {
	M.clear();
	M['0'] = '1';
	M['1'] = '0';
	int _, cas = 0;
	scanf("%d", &_);
	while (_--) {
		scanf("%d%d", &n, &l);
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cin >> b[i];
		sort(b, b+n);
		int ans = 111111;
		for (int sta = 0; sta < (1<<l); ++ sta) {
			if (chk(sta)) ans = min(ans, __builtin_popcount(sta));
		}
		if (ans > 100) {
			printf("Case #%d: NOT POSSIBLE\n", ++cas);	
		} else {
			printf("Case #%d: %d\n", ++cas, ans);
		}
	}
	return 0;
}