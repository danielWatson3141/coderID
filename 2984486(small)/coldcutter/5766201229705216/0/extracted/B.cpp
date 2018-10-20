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
const int N = 1005;

struct Tedge {
	int x, next;
} e[N << 2];

int n, go[N], f[N], tot;

void addEdge(int u, int v) {
	e[++tot].x = v; e[tot].next = go[u]; go[u] = tot;
}

void dfs(int fa, int u) {
	f[u] = 1;
	int count = 0;
	for (int p = go[u]; p; p = e[p].next) {
		if (e[p].x != fa) {
			++count;
			dfs(u, e[p].x);
		}
	}
	if (count < 2) {
		return;
	}
	int mx1 = -1, mx2;
	for (int p = go[u]; p; p = e[p].next) {
		if (e[p].x != fa) {
			if (f[e[p].x] > mx1) {
				mx2 = mx1;
				mx1 = f[e[p].x];
			} else if (f[e[p].x] > mx2) {
				mx2 = f[e[p].x];
			}
		}
	}
	f[u] = mx1 + mx2 + 1;
}

void solve() {
	scanf("%d", &n);
	tot = 0;
	memset(go, 0, sizeof(go));
	for (int i = 1; i < n; ++i) {
		int j, k;
		scanf("%d%d", &j, &k);
		addEdge(j, k);
		addEdge(k, j);
	}
	int ans = n;
	for (int i = 1; i <= n; ++i) {
		dfs(0, i);
		ans = min(ans, n - f[i]);
	}
	printf("%d\n", ans);
}

int main() {
	//freopen("B.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		printf("Case #%d: ", kase);
		solve();
	}
	return 0;
}
