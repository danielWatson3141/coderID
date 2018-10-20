#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
const int INF = 0x7f7f7f7f;
int n;
vector<int> v[N];
int dp[3][N];

void dfs(int u, int rt) {
	dp[0][u] = 0;
	dp[1][u] = dp[2][u] = INF;
	for(int i = 0; i < v[u].size(); i ++) {
		if(v[u][i] == rt) continue;
		dfs(v[u][i],u);
		int x = dp[0][v[u][i]] + 1;
		int y = min(dp[0][v[u][i]],dp[2][v[u][i]]);
		dp[2][u] = min(dp[2][u] + x, dp[1][u] + y);
		dp[1][u] = min(dp[1][u] + x, dp[0][u] + y);
		dp[0][u] += x;
	}
}



int main() {
	//freopen("/Users/asteroid/Desktop/B-large.in", "r", stdin);
	//freopen("/Users/asteroid/Desktop/out.txt", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i ++) v[i].clear();
		for(int i = 1;i < n; i ++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans = INF;
		for(int i =1;i<=n;i++) {
			dfs(i,-1);
			if(dp[0][i] < ans) ans = dp[0][i];
			if(dp[2][i] < ans) ans = dp[2][i];
		}
		printf("Case #%d: %d\n",++cas,ans);
    }
	return 0;
}