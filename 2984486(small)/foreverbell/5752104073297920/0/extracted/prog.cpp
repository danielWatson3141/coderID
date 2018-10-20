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

const int nn = 1000;

int rand(int l, int r) {
	int x = rand() % (r - l + 1) + l;
	return x;
}

void gen(int n) {
	int a[nn + 1];
	for (int k = 1; k <= n; ++k) a[k] = k;
	for (int k = 1; k <= n; ++k) {
		int p = rand(k, n);
		swap(a[k], a[p]);
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > i) ++cnt0;
		else ++cnt1;
	}
	printf("%d %d\n", cnt0, cnt1);
	//for (int i = 1; i <= n; ++i) printf("%d%c", a[i], i == n ? '\n' : ' ');
}

const int maxn = 1000 + 10;
int n, a[maxn];

bool good() {
	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (++a[i] > i) ++cnt0;
		else ++cnt1;
	}
	if (cnt0 - cnt1 >= 40) return false;
	int thr = 60, delta = cnt0 - cnt1;
	if (delta < 0) delta = -delta;
	return delta <= thr;
}

int main() {
	// for (int i = 1; i <= 1000; ++i) gen(nn);
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("C-small-attempt4.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
		}
		printf("Case #%d: ", tt);
		if (good()) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}