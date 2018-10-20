// File Name: B.cpp
// Author: YangYue
// Created Time: Sat Apr 26 11:09:41 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

const int MaxN = 1000005;
const double eps = 1e-8;
const double DINF = 1e100;
const int INF = 1000000006;
const LL LINF = 1000000000000000005ll;

int n;
int f[1005][2];
vector<int> edge[1005];
int a[1005];
int size[1005];
void dfs(int u, int fa) {
	size[u] = 1;
	for (auto v : edge[u]) if (v != fa) {
		dfs(v, u);
		size[u] += size[v];
	}
	f[u][1] = size[u];
	int tmp = 0;
	int m = 0;
	for (auto v : edge[u]) if (v != fa) {
		tmp += f[v][1];
		a[m++] = f[v][0] - f[v][1];
	}
	sort(a, a + m);
	f[u][0] = tmp;
	if (m >= 2) {
		f[u][0] = min(f[u][0], f[u][0] + a[0] + a[1]);
	}
}
int main()
{
	freopen("in","r",stdin);

	int cases; scanf("%d", &cases);
	int cas = 0;
	while (cases--) {
		printf("Case #%d: ", ++cas);
		scanf("%d", &n);
		int ans = n - 1;
		for (int i = 1; i <= n; ++i) edge[i].clear();
		for (int i = 1; i < n; ++i) {
			int x, y; scanf("%d %d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for (int root = 1; root <= n; ++root) {
			memset(f, -1, sizeof f);
			dfs(root, -1);
			ans = min(ans, f[root][0]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

// hehe ~


