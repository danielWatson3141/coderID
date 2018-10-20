#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

const int maxn = 1010;
int n, T, cases, x, y;
vector<int> v[maxn];
int f[maxn], size[maxn];

void dp(int x, int fa) {
	size[x] = 1;
	for (unsigned i = 0; i < v[x].size(); ++i) {
		if (v[x][i] == fa) continue;
		dp(v[x][i], x);
		size[x] += size[v[x][i]];
	}

	if (v[x].size() - (fa > 0) <= 1) f[x] = size[x] - 1;
	else {
		int min1 = 1e9, min2 = 1e9;
		for (unsigned i = 0; i < v[x].size(); ++i) {
			if (v[x][i] == fa) continue;
			int val = f[v[x][i]] - size[v[x][i]];
			if (val < min1) min2 = min1, min1 = val;
			else if (val < min2) min2 = val;
		}
		f[x] = min1 + min2 + size[x] - 1;
	}
}

int main(){
	for (scanf("%d", &T), cases = 1; cases <= T; ++cases) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) v[i].clear();
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			v[x].pb(y); v[y].pb(x);
		}

		int ans = n;
		for (int root = 1; root <= n; ++root) {
			memset(f, 60, sizeof(f));
			memset(size, 0, sizeof(size));
			dp(root, 0);
			if (f[root] < ans) ans = f[root];
		}

		printf("Case #%d: %d\n", cases, ans);
	}
}
