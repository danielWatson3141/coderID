#include <cstdio>
#include <algorithm>
#define N 1010
#define INF 9999
#define PB push_back

using namespace std;

vector<int> G[N];
int dp[N], sub[N];

int DFS(int now, int back){
	int i, p, mx, mxx, cnt, tmp;
	sub[now] = dp[now] = 0;
	mx = mxx = -1;
	for (cnt = i = 0; i < G[now].size(); i++){
		p = G[now][i];
		if (p == back) continue;
		dp[now] += DFS(p, now);
		sub[now] += (sub[p]+1);
		tmp = sub[p] - dp[p] +1;
		if (tmp > mx) mxx = mx, mx = tmp;
		else if (tmp > mxx) mxx = tmp;
		cnt++;
	}
	if (cnt == 1) dp[now] = sub[now];
	else if (cnt > 2) dp[now] = sub[now] - mx - mxx;
	return dp[now];
}

int main(){
	int cas, T, n, i, a, b, ans;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++){
		scanf("%d", &n);
		ans = n;
		for (i = 1; i <= n; i++)
			G[i].clear();
		for (i = 0; i < n-1; i++){
			scanf("%d %d", &a, &b);
			G[a].PB(b);
			G[b].PB(a);
		}
		int tmp = 0;
		for (i = 1; i <= n; i++)
			ans = min(ans, DFS(i, 0));
		printf("Case #%d: %d\n", cas, ans);
	}
}

