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
	map<string, int> P;
	int _, cas = 0;
	scanf("%d", &_);
	while (_--) {
		P.clear();
		scanf("%d%d", &n, &l);
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) cin >> b[i];
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				string s = "";
				for (int k=0; k<l; ++k) {
					if (a[i][k] == b[j][k]) s += "0";
					else s += "1";
				}
				P[s] ++;
			}
		int ans = 111111;
		for (map<string, int>::iterator it = P.begin(); it != P.end(); ++it) {
			if (it -> second == n) {
				string s = it -> first;
				int ret = 0;
				for (int i=0; i<l; ++i) {
					ret += (s[i] == '1');
				}
				ans = min(ans, ret);
			}
		}
		if (ans > 100) {
			printf("Case #%d: NOT POSSIBLE\n", ++cas);	
		} else {
			printf("Case #%d: %d\n", ++cas, ans);
		}
	}
	return 0;
}