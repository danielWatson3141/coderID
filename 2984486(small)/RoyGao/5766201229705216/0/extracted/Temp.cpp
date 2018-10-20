#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int n, l;
int cnt, ans, tmp;
int head[200];
bool vis[200];
int child[200];

struct edge {
	int to, nxt;
}e[10000];

void AddEdge(int u,int v)
{
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

void trav(int u)
{
	vis[u] = true;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!vis[v]) {
			child[u]++;
			trav(v);
		}
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T, cas = 0;
	int a, b;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		cnt = 1;
		memset(head, 0, sizeof head);
		scanf("%d", &n);
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d%d", &a, &b);
			AddEdge(a, b);
			AddEdge(b, a);
		}
		ans = n - 1;
		for (int i = 1; i <= n; ++i) {
			memset(vis, 0, sizeof vis);
			memset(child, 0, sizeof child);
			trav(i);
			tmp = 0;
			for (int j = 1; j <= n; ++j)
				if (child[j] != 0 && child[j] != 2) tmp++;
			ans = min(ans, tmp);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}