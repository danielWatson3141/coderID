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

const int maxn = 1001;
int n, dp[maxn], size[maxn];
vector<int> G[maxn];

void gao(int u, int pa = -1) {
	int childs = 0;
	size[u] = 1;
	for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
		int v = *it;
		if (v == pa) continue;
		++childs;
		gao(v, u);
		size[u] += size[v];
	}
	if (childs == 1) dp[u] = size[u] - 1;
	else if (childs >= 2) {
		vector<int> deltas;
		int sum = 0;
		for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
			int v = *it;
			if (v == pa) continue;
			sum += size[v]; 
			deltas.push_back(dp[v] - size[v]);
		}
		dp[u] = sum;
		sort(deltas.begin(), deltas.end());
		sum += deltas[0] + deltas[1];
		dp[u] = min(dp[u], sum);
	}
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		// fprintf(stderr, "Case #%d: ", tt);
		printf("Case #%d: ", tt);
		int ret = n;
		for (int root = 1; root <= n; ++root) {
			memset(dp, 0, sizeof(dp));
			memset(size, 0, sizeof(size));
			gao(root);
			ret = min(ret, dp[root]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
