#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, sizeTree[MAXN], dp[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

void Dfs(int u) {
	int numChildren = 0;
	vector<pair<int,int> > children;

	visited[u] = true;
	sizeTree[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		if (!visited[adj[u][i]]) {
			Dfs(adj[u][i]);
			numChildren++;
			sizeTree[u] += sizeTree[adj[u][i]];
			children.push_back(make_pair(sizeTree[adj[u][i]]-dp[adj[u][i]], adj[u][i]));
		}
	}
	if (numChildren == 0)
		dp[u] = 0;
	if (numChildren == 1)
		dp[u] = sizeTree[u]-1;
	if (numChildren >= 2) {
		sort(children.begin(), children.end());

		dp[u] = 0;
		for (int i = 0; i < numChildren-2; i++)
			dp[u] += children[i].first;
		for (int i = 0; i < numChildren; i++)
			dp[u] += dp[children[i].second];
	}
	//printf("dp[%d] = %d, sizeTree[%d] = %d\n", u+1, dp[u], u+1, sizeTree[u]);
}

void Solve() {
	int result = MAXN;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		adj[i].clear();

	for (int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		fill(visited, visited+n, false);
		fill(dp, dp+n, 100000);
		fill(sizeTree, sizeTree+n, 0);

		//printf("\nTrying root %d\n", i+1);
		Dfs(i);

		result = min(result, dp[i]);
	}

	printf("%d\n", result);
}

int main() {
	int q, caseId = 0;
	scanf("%d", &q);
	while (q--) {
		caseId++;
		printf("Case #%d: ", caseId);
		Solve();
	}
	return 0;
}
