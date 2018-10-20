#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1111;
const int INF = 1000000;
int head[MAX_N], nxt[MAX_N << 1], to[MAX_N << 1];
int dp[MAX_N], ans, n, e, c[MAX_N];

void addEdge(int u, int v) {
	to[e] = v;
	nxt[e] = head[u];
	head[u] = e++;
}

void gao(int u, int f) {
	int num = 0, m1 = 0, m2 = 0;
	c[u] = 1;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (v == f) continue;
		gao(v, u), num++;
		c[u] += c[v];
		if (m1 < c[v] - dp[v]) {
			m2 = m1;
			m1 = c[v] - dp[v];
		} else if (m2 < c[v] - dp[v]) {
			m2 = c[v] - dp[v];
		}
	}
	if (num <= 1) {
		dp[u] = c[u] - 1;
	} else if (num >= 2) {
		dp[u] = c[u] - 1 - m1 - m2;
	}
}

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d", &n);
		fill(head, head + n + 1, -1), e = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
		}
		ans = INF;
		for (int i = 1; i <= n; i++) {
			gao(i, -1);
			ans = min(ans, dp[i]);
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
