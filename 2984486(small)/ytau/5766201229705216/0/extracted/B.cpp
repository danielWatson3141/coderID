#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF (int)(1e8)

/*
int T, n, x, y, h[1005], e[2005][2], ew, d[1005], id[1005], idw, w[1005], ans;

void adde(int x, int y) {
	e[ew][0] = y;
	e[ew][1] = h[x];
	h[x] = ew++;
}

int degree(int x) {
	int ret = 0;
	for (int i = h[x]; i != -1; i = e[i][1]) {
		ret++;
	}
	return ret;
}

void dfs(int x) {
	if (d[x] < 3) return;
	if (id[x] == idw) return;
	id[x] = idw;
	for (int i = h[x]; i != -1; i = e[i][1]) {
		int y = e[i][0];
		if (d[y] >= 3 && id[y] == -1) {
			dfs(y);
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		memset(h, -1, sizeof(h));
		ew = 0;
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			x--;
			y--;
			adde(x, y);
			adde(y, x);
		}
		ans = 1;
		for (int i = 0; i < n; ++i) {
			d[i] = degree(i);
		}
		idw = 0;
		memset(id, -1, sizeof(id));
		for (int i = 0; i < n; ++i) {
			if (d[i] >= 3 && id[i] == -1) {
				dfs(i);
				idw++;
			}
		}

		printf("Case #%d: %d\n", tc, n - ans);
	}
	return 0;
}
*/

int T, n, x, y, h[1005], e[2005][2], ew, dp[1005][2], ans;

void adde(int x, int y) {
	e[ew][0] = y;
	e[ew][1] = h[x];
	h[x] = ew++;
}

struct node{
	int m, i;
};

void dfs(int x, int f) {
	dp[x][0] = 1;
	dp[x][1] = -INF;
	node m0[3], m1[2];
	m0[0].m = m0[1].m = m0[2].m = -INF;
	m0[0].i = m0[1].i = m0[2].i = -INF;
	m1[0].m = m1[1].m = -INF;
	m1[0].i = m1[1].i = -INF;
	for (int i = h[x]; i != -1; i = e[i][1]) {
		int y = e[i][0];
		if (y != f) {
			dfs(y, x);
			if (dp[y][0] > m0[0].m) {
				m0[2] = m0[1];
				m0[1] = m0[0];
				m0[0].m = dp[y][0];
				m0[0].i = y;
			}
			else if (dp[y][0] > m0[1].m) {
				m0[2] = m0[1];
				m0[1].m = dp[y][0];
				m0[1].i = y;
			}
			else if (dp[y][0] > m0[2].m) {
				m0[2].m = dp[y][0];
				m0[2].i = y;
			}
			if (dp[y][1] > m1[0].m) {
				m1[1] = m1[0];
				m1[0].m = dp[y][1];
				m1[0].i = y;
			}
			else if (dp[y][1] > m1[1].m) {
				m1[1].m = dp[y][1];
				m1[1].i = y;
			}
		}
	}
	ans = max(ans, 1 + m0[0].m + m0[1].m);
	if (m1[0].i != m0[0].i && m1[0].i != m0[1].i) {
		ans = max(ans, 1 + m1[0].m + m0[0].m + m0[1].m);
	}
	if (m1[0].i != m0[0].i && m1[0].i != m0[2].i) {
		ans = max(ans, 1 + m1[0].m + m0[0].m + m0[2].m);
	}
	if (m1[0].i != m0[1].i && m1[0].i != m0[2].i) {
		ans = max(ans, 1 + m1[0].m + m0[1].m + m0[2].m);
	}
	if (m1[1].i != m0[0].i && m1[1].i != m0[1].i) {
		ans = max(ans, 1 + m1[1].m + m0[0].m + m0[1].m);
	}
	if (m1[1].i != m0[0].i && m1[1].i != m0[2].i) {
		ans = max(ans, 1 + m1[1].m + m0[0].m + m0[2].m);
	}
	if (m1[1].i != m0[1].i && m1[1].i != m0[2].i) {
		ans = max(ans, 1 + m1[1].m + m0[1].m + m0[2].m);
	}
	ans = max(ans, 1 + m1[0].m);
	dp[x][0] = max(dp[x][0], 1 + m0[0].m + m0[1].m);
	if (m1[0].i != m0[0].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[0].m + m0[0].m);
	}
	if (m1[0].i != m0[1].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[0].m + m0[1].m);
	}
	if (m1[0].i != m0[2].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[0].m + m0[2].m);
	}
	if (m1[1].i != m0[0].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[1].m + m0[0].m);
	}
	if (m1[1].i != m0[1].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[1].m + m0[1].m);
	}
	if (m1[1].i != m0[2].i) {
		dp[x][1] = max(dp[x][1], 1 + m1[1].m + m0[2].m);
	}
	dp[x][1] = max(dp[x][1], 1 + m0[0].m);
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		memset(h, -1, sizeof(h));
		ew = 0;
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			x--;
			y--;
			adde(x, y);
			adde(y, x);
		}
		ans = 1;
		dfs(0, -1);
		printf("Case #%d: %d\n", tc, n - ans);
	}
	return 0;
}