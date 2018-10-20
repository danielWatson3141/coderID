#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
int const N = 1010;
int const M = 1001000;
int n, m;
struct edges{ int u, next; } e[M];
int p[N], idx;
void addedge(int u, int v) {
	e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
typedef long long ll;

int s[N], dp[N];
struct node {
	int v, id;
	friend bool operator < (node a, node b) {
		return a.v < b.v;
	}
} tmp[N];
void dfs(int u, int pre) {
	dp[u] = 0;
	s[u] = 1;
	int cc = 0;
	for (int i = p[u]; ~i; i = e[i].next) {
		int v = e[i].u;
		if (v != pre) {
			dfs(v, u);
			dp[u] += dp[v];
			s[u] += s[v];
			++cc;
		}
	}
	int k = 0, ss = 0;
	if (cc == 1 || cc > 2) {
		for (int i = p[u]; ~i; i = e[i].next) {
			int v = e[i].u;
			if (v != pre) {
				tmp[k].v = s[v] - dp[v];
				tmp[k].id = v;
				ss += s[v];
				++k;
			}
		}	
		sort(tmp, tmp + k);
		if (cc == 1) {
			dp[u] = s[tmp[0].id];
		} else {
			dp[u] = ss - tmp[k - 1].v - tmp[k - 2].v;
		}
	}
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large-out.txt", "w", stdout);
	int ca = 1; int T;
	for (scanf("%d", &T); T--; ) {
		int a, b; init();
		scanf("%d", &n);
		rep(i, n - 1) {
			scanf("%d%d", &a, &b);
			addedge(a, b);
			addedge(b, a);
		}
		int ret = n - 1;
		Rep(i, n) {
			dfs(i, -1);
			ret = min(ret, dp[i]);
		}
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}


