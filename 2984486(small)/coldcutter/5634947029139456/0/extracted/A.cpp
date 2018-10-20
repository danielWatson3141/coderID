#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define bitAt(x, k) (((x) >> (k)) & 1)
typedef long long LL;
typedef long double LD;
const int MOD = 1000000000 + 7;
const int INF = 1000000000;
const double EPS = 1e-9;
const double PI = acos(-1.0);

const int N = 200;

char a[N][50], b[N][50], s[50];
LL va[N], vb[N];
bool flag[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			a[i][j] = s[j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		LL tmp = 0;
		for (int j = 1; j <= m; ++j) {
			tmp = (tmp << 1) + a[i][j] - '0';
		}
		va[i] = tmp;
	}
	sort(va + 1, va + n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			b[i][j] = s[j];
		}
	}
	int ans = INF;
	for (int k = 1; k <= n; ++k) {
		int now = 0;
		for (int j = 1; j <= m; ++j) {
			if (a[1][j] == b[k][j]) {
				flag[j] = 0;
			} else {
				flag[j] = 1;
				++now;
			}
		}
		if (now >= ans) {
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			LL tmp = 0;
			for (int j = 1; j <= m; ++j) {
				tmp = (tmp << 1) + ((b[i][j] - '0') ^ flag[j]);
			}
			vb[i] = tmp;
		}
		sort(vb + 1, vb + n + 1);
		bool xx = 1;
		for (int i = 1; i <= n && xx; ++i) {
			if (va[i] != vb[i]) {
				xx = 0;
			}
		}
		if (xx) {
			ans = min(ans, now);
		}
	}
	if (ans == INF) {
		puts("NOT POSSIBLE");
	} else {
		printf("%d\n", ans);
	}
}

int main() {
	//freopen("A.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		printf("Case #%d: ", kase);
		solve();
	}
	return 0;
}
