#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000+5, MAXM = 2000+5;
int T, N, X, Y;
int e, head[MAXN], next[MAXM], v[MAXM];
int d[MAXN], cnt[MAXN];
void addedge(int x, int y) {
	v[e] = y;
	next[e] = head[x]; head[x] = e++;
}
void dfs(int fa, int u) {
	cnt[u] = 1;
	int sons = 0;
	for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa) {
		dfs(u, v[i]);
		cnt[u] += cnt[v[i]];
		sons++;
	}
	if (sons == 0) {
		d[u] = 0;
	} else if (sons == 1) {
		d[u] = cnt[u]-1;
	} else {
		d[u] = INF;
		for (int i = head[u]; i != -1; i = next[i]) if (v[i] != fa) {
			for (int j = next[i]; j != -1; j = next[j]) if (v[j] != fa) {
				d[u] = min(d[u], cnt[u]-1-cnt[v[i]]-cnt[v[j]]+d[v[i]]+d[v[j]]);
			}
		}
	}
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("put.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		e = 0;
		memset(head, -1, sizeof(head));
		scanf("%d", &N);
		for (int i = 1; i < N; i++) {
			scanf("%d%d", &X, &Y);
			addedge(X, Y);
			addedge(Y, X);
		}
		int ans = INF;
		for (int u = 1; u <= N; u++) {
			dfs(0, u);
			ans = min(ans, d[u]);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}