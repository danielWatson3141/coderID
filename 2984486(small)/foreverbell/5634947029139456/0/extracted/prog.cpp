#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cassert>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

using namespace std;

const int maxn = 151 + 10;
int n, l;
char outlet[maxn][maxn], device[maxn][maxn];

void read(char *arr) {
	scanf("%s", arr + 1);
}

int check(int a, int b) {
	vector<int> flip;
	for (int i = 1; i <= l; ++i) {
		if (outlet[a][i] != device[b][i]) flip.push_back(i);
	}
	vector<string> sout, sdev;
	for (int i = 1; i <= n; ++i) {
		sdev.push_back(string(device[i] + 1));
	}
	for (int i = 1; i <= n; ++i) {
		static char buf[maxn];
		memset(buf, 0, sizeof(buf));
		for (int j = 1; j <= l; ++j) {
			buf[j] = outlet[i][j];
		}
		for (int x : flip) {
			if (buf[x] == '1') buf[x] = '0';
			else buf[x] = '1';
		}
		sout.push_back(string(buf + 1));
	}
	sort(sout.begin(), sout.end());
	sort(sdev.begin(), sdev.end());
	for (int i = 0; i < n; ++i) {
		if (sout[i] != sdev[i]) return maxint;
	}
	return flip.size();
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; ++i) read(outlet[i]);
		for (int i = 1; i <= n; ++i) read(device[i]);
		int ret = maxint;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				ret = min(ret, check(i, j));
			}
		}
		printf("Case #%d: ", tt);
		if (ret == maxint) puts("NOT POSSIBLE");
		else printf("%d\n", ret);
	}
	return 0;
}
