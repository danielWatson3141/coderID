#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


struct Edge {
	int v, next;
};

Edge w[2005];
int ww[1005], visit[1005], weight[10005], N, W;


int dfs(int u) {
	visit[u] = weight[u] = 1;
	vector<int> son(0);
	for (int i = ww[u]; i; i = w[i].next) {
		int v = w[i].v;
		if (visit[v]) continue;
		int fv = dfs(v);
		son.push_back(fv - weight[v]);
		weight[u] += weight[v];
	}
	sort(son.begin(), son.end());
	if (son.size() == 0) return 0;
	if (son.size() == 1) return weight[u] - 1;
	return weight[u] + son[0] + son[1] - 1;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int testCaseNum;
	scanf("%d", &testCaseNum);
	for (int testCase = 1; testCase <= testCaseNum; ++testCase) {
		scanf("%d", &N);
		memset(ww, 0, sizeof(ww)); W = 1;
		for (int i = 1, u, v; i < N; ++i) {
			scanf("%d%d", &u, &v);
			w[++W].v = v; w[W].next = ww[u]; ww[u] = W;
			w[++W].v = u; w[W].next = ww[v]; ww[v] = W;
		}
		
		int ans = 1 << 30;
		for (int s = 1; s <= N; ++s) {
			memset(visit, 0, sizeof(visit));
			int now = dfs(s);
			ans = min(ans, now);
		}
		printf("Case #%d: %d\n", testCase, ans);
	}
}