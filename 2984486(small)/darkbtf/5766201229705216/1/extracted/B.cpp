#include <cstdio>
#include <vector>
#include <algorithm>

int N;
std::vector<int> tree[1001];
std::vector<int> cnt[1001];
int DP[1001], sum[1001];
std::vector<int> tmp;
void go(int v, int par) {
	cnt[v].clear();
	DP[v] = 0;
	for (int i = 0; i < tree[v].size(); ++i) {
		if (tree[v][i] == par) continue;
		go(tree[v][i], v);
		DP[v] += DP[tree[v][i]];
		cnt[v].push_back(sum[tree[v][i]]);
	}
	int sz = cnt[v].size();
	if (sz == 0 || sz == 2) ;
	else if (sz == 1) DP[v] += cnt[v][0];
	else {
		std::sort(cnt[v].begin(), cnt[v].end());
		for (int i = 0; i < sz - 2; ++i)
			DP[v] += cnt[v][i];
	}
	if (sz < 2) sum[v] = 1;
	else sum[v] = cnt[v][sz - 1] + cnt[v][sz - 2] + 1;
	//printf("DP[%d] = %d, sz = %d\n", v, DP[v], sz);
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) tree[i].clear();
		for (int i = 0; i < N - 1; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			tree[a - 1].push_back(b - 1);
			tree[b - 1].push_back(a - 1);
		}
		int ans = 1001;
		for (int i = 0; i < N; ++i) {
			go(i, -1);
			if (DP[i] < ans) ans = DP[i];
		}
		printf("Case #%d: %d\n", t, ans);
	}
	
}