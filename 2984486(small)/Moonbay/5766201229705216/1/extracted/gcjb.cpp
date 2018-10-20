/*
 * gcjb/win.cpp
 * Created on: 2014-4-26
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int inf = 0x7fffffff;
const int vE = 4000;
const int vN = 2000;
typedef long long LL;
typedef struct Edge {
	int u, v;
	int next;
}Edge;
Edge e[vE];
int used[vN], en, head[vN];
int num[vN];
int degree[vN];
int dp[vN], n;
void inline addedge(int u, int v) {
	e[en].u = u;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
	e[en].u = v;
	e[en].v = u;
	e[en].next = head[v];
	head[v] = en++;
}

int dfs(int s) {
	used[s] = 1;
	int dpt = 0;
	vector<int> tsort;
	for (int i = head[s]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if (used[v] == 1) {
			continue;
		}
		dfs(v);
		num[s] += num[v] + 1;
		tsort.push_back(num[v] - dp[v] + 1);
		degree[s]++;
		dpt += dp[v];
	}
	if (degree[s] == 0) {
		dp[s] = 0;
		num[s] = 0;
		return 0;
	}
	if (degree[s] == 2) {
		dp[s] = dpt;
		return 0;
	}
	if (degree[s] == 1) {
		dp[s] = num[s];
		return 0;

	}
	sort(tsort.begin(), tsort.end());
	dp[s] = num[s] - tsort[tsort.size() - 1] - tsort[tsort.size() - 2];
	return 0;
}

int main() {
	//	freopen("B-large.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d", &n);
		memset(degree, 0, sizeof(degree));
		en = 0;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
		int ans = inf;
		for (int i = 1; i <= n; i++) {
			memset(used, 0, sizeof(used));
			memset(degree, 0, sizeof(degree));
			memset(dp, 0, sizeof(dp));
			memset(num, 0, sizeof(num));
			dfs(i);
			int temp = dp[i];
			if (ans > temp) {
				ans = temp;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

