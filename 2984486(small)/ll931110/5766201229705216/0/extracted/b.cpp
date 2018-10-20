#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int n, T;
vector<int> adj[1005];
int dp[1005][2];

int rec(int u,int b,int par) {
	if (dp[u][b] >= 0) return dp[u][b];
	if (b == 0) {
		// if b == 0 then we have to delete everything
		int ret = 1;
		for (int i = 0; i < adj[u].size(); i++) if (adj[u][i] != par)
			ret += rec(adj[u][i], 0, u);
		return dp[u][b] = ret;		
	}
	else {
		int ret = 0,diff1 = -1, diff2 = -1;
		for (int i = 0; i < adj[u].size(); i++) if (adj[u][i] != par) {
			ret += rec(adj[u][i], 0, u);
			int tmp = rec(adj[u][i], 0, u) - rec(adj[u][i], 1, u);
			if (tmp > diff1) {
				diff2 = diff1;
				diff1 = tmp;
			}
			else if (tmp > diff2) diff2 = tmp;
		}
		dp[u][b] = ret;
		if (diff2 >= 0) dp[u][b] -= (diff1 + diff2);
		return dp[u][b];
	}
}

int root(int x) {
	memset(dp,-1,sizeof(dp));
	return rec(x, 1, -1);
}

void solveCase(int it) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = n;
	for (int i = 1; i <= n; i++) ret = min(ret,root(i));
	printf("Case #%d: %d\n", it, ret);
}

int main() {
	scanf("%d", &T);
	for (int it = 1; it <= T; it++) solveCase(it);
}
