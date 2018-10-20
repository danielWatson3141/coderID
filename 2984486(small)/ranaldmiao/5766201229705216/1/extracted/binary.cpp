#include <bits/stdc++.h>
using namespace std;
int TC, pre[1005], N, num_child[1005], dp[1005];
vector<int> adjList[1005];
void dfs(int x) {
	num_child[x] = 1;
	int immediate = 0;
	vector<int> v;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (*it == pre[x]) continue;
		pre[*it] = x;
		dfs(*it);
		num_child[x] += num_child[*it];
		++immediate;
		v.push_back(num_child[*it]-dp[*it]); //saved, larger better
	}
	sort(v.begin(), v.end(), greater<int>());
	if (immediate == 0) dp[x] = 0;
	else if (immediate == 1) dp[x] = num_child[x]-1;
	else if (immediate >= 2) {
		dp[x] = num_child[x]-1-v[0]-v[1];
	}
	
}
int main () {
	freopen("binary_large.in", "r", stdin);
	freopen("binary_large.out", "w", stdout);
	scanf("%d", &TC);
	for (int T = 1; T <= TC; ++T) {
		scanf("%d", &N);
		for (int i = 0, a, b; i < N-1; ++i) {
			scanf("%d%d", &a, &b);
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}
		int ans = N;
		for (int root = 1; root <= N; ++root) {
			memset(pre, -1, sizeof(pre));
			memset(dp, -1, sizeof(dp));
			dfs(root);
			ans = min(dp[root], ans);
		}
		printf("Case #%d: %d\n", T, ans);
		
		for (int i = 1; i <= N; ++i) adjList[i].clear();
	}
}
