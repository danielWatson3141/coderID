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
#define POW2(k) (1<<(k))
#define POW2L(k) (1ULL<<(k))
#define INSIDE(a, b) (POW2(a) & (b))
#define MERGE(a, b) (POW2(a) | (b))
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

#define MAXN 1003
#define MOD 

vector<int> edge[MAXN];
int st[MAXN], dp[MAXN];
int n;

int dfs(int u, int fa) {
	st[u] = 0;
	dp[u] = 0;

	int cnt = 0;
	int a[2] = {0, 0};
	for (int i = edge[u].size() - 1; i >= 0; --i) {
		int v = edge[u][i];
		if (v == fa) {
			continue;
		}
		dfs(v, u);

		st[u] += st[v];
		++cnt;

		int w = st[v] - dp[v];
		if (a[0] <= w) {
			a[1] = a[0];
			a[0] = w;
		} else if (a[1] < w) {
			a[1] = w;
		}
	}
	
	dp[u] = st[u];	// del all
	if (cnt >= 2) {
		ChkMin(dp[u], st[u] - a[0] - a[1]);
	}
	st[u] ++;
	return dp[u];
}

int solve() {
	int key = n;
	for (int i = 1; i <= n; ++i) {
		ChkMin(key, dfs(i, -1));
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "r", stdin);
 	freopen("out", "w", stdout);
#endif

	int dataset;
	scanf("%d", &dataset);
	for (int cas = 1; cas <= dataset; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			edge[i].clear();
		}
		for (int i = 1, u, v; i < n; ++i) {
			scanf("%d %d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		printf("Case #%d: %d\n", cas, solve());
	}

	return 0;
}
