#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, sum = 0;
int head[2000], t[2000], nx[2000], dp[2000], cnt;
bool vis[2000];

void dfs(int x) {
	vis[x] = 1;

	int f = 0, s = 0, c = 0;

	for (int e = head[x]; e; e = nx[e]) {
		int y = t[e];
		if (vis[y]) continue;

		dfs(y);

		if (dp[y] > f) s = f, f = dp[y];
		else if (dp[y] > s) s = dp[y];

		++ c;
	}

	if (c >= 2) dp[x] = f + s + 1;
	else dp[x] = 1; 

}
int main() {

	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int _, __ = 1; 
	for (scanf("%d", &_); __ <= _; ++ __ ) {
		printf("Case #%d: ", __);
		scanf("%d", &n);

		memset(head, 0, sizeof head);
		memset(t, 0, sizeof t);
		memset(nx, 0, sizeof nx);
		memset(dp, 0, sizeof dp); 
		//memset(all, 0, sizeof all);

		cnt = 0;

		for (int i = 1; i < n; ++ i) {
			int x, y; scanf("%d%d", &x, &y);

			t[++ cnt] = y, nx[cnt] = head[x], head[x] = cnt;
			t[++ cnt] = x, nx[cnt] = head[y], head[y] = cnt; 
		}

		int ans = 0;

		for (int i = 1; i <= n; ++ i) {
			memset(vis, 0, sizeof vis);
			sum = 0;
			dfs(i); 
			ans = max(ans, dp[i]);

		}

		printf("%d\n", n - ans); 
	}
}