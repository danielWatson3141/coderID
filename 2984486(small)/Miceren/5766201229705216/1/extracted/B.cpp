#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1111;
const int INF = 111111;

vector<int> e[N];
int n, size[N], f[N];

void dfs(int x, int fa) {
	int sons = 0, max1 = -INF, max2 = -INF;
	size[x] = 1;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa) {
			continue;
		}
		sons++;
		dfs(y, x);
		size[x] += size[y];
		if (f[y] > max1) {
			max2 = max1;
			max1 = f[y];
		} else if (f[y] > max2) {
			max2 = f[y];
		}
	}
	f[x] = max(0, max1 + max2) + 1;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for(int testCount = 1; testCount <= test; testCount++) {
		printf("Case #%d: ", testCount);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			e[i].clear();
		}		
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans = INF;
		for(int i = 1; i <= n; i++) {
			dfs(i, 0);
			ans = min(ans, n - f[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
