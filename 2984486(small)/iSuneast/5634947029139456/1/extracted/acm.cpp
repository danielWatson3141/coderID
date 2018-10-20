#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define POW2L(k) (1LL<<(k))
#define INSIDE(a, b) (POW2L(a) & (b))
#define MERGE(a, b) (POW2L(a) | (b))
#define LOWBIT(v) ((v)&(-(v)))
#define INF 0x3f3f3f3f
#define EPS 1e-10
using namespace std;

const double PI = acos(-1.0);

typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long ULL;

template<class T1, class T2> inline bool ChkMax(T1 &a, const T2 &b) { if (a < b) { a = b; return true; } return false; }
template<class T1, class T2> inline bool ChkMin(T1 &a, const T2 &b) { if (a > b) { a = b; return true; } return false; }

#define MAXN 155
#define MOD 

int n, l;
LL g[MAXN];
LL tar[MAXN];
LL tmp[MAXN];
char buf[MAXN];
bool flip[MAXN];

int check(int u, int v) {
	LL gtar = g[u] ^ tar[v];
	int cnt = 0;
	for (int i = 0; i < l; ++i) {
		flip[i] = false; 
		if (INSIDE(i, gtar)) {
			flip[i] = true;
			++cnt;
		}
	}
	for (int i = 0; i < n; ++i) {
		tmp[i] = 0;
		for (int j = 0; j < l; ++j) {
			if (flip[j] && (!INSIDE(j, g[i]))) {
				tmp[i] = MERGE(j, tmp[i]);
			} else if (!flip[j] && INSIDE(j, g[i])) {
				tmp[i] = MERGE(j, tmp[i]);
			}
		}
	}
	sort(tmp, tmp + n);
	bool fade = false;
	for (int j = 0; j < n; ++j) {
		if (tmp[j] != tar[j]) {
			fade = true;
		}
	}
	if (fade) {
		return INF;
	}
	return cnt;
}

void solve() {
	int key = INF;
	for (int i = 0; i < 1; ++i) {
		for (int j = 0; j < n; ++j) {
			ChkMin(key, check(i, j));
		}
	}
	if (key == INF) {
		puts("NOT POSSIBLE");
	} else {
		printf("%d\n", key);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("A-large.in", "r", stdin);
 	freopen("out", "w", stdout);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			g[i] = 0;
			for (int j = 0; j < l; ++j) {
				if (buf[j] == '1') {
					int t = l - 1 - j;
					g[i] |= POW2L(t);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			tar[i] = 0;
			for (int j = 0; j < l; ++j) {
				if (buf[j] == '1') {
					int t = l - 1 - j;
					tar[i] |= POW2L(t);
				}
			}
		}
		sort(tar, tar + n);
		printf("Case #%d: ", cas);
		solve();
	}

	return 0;
}
