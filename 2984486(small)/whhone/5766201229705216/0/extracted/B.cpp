#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, x, y, es;
int e[1005][1005];
int c[1005];

void connect(int x, int y) {
	e[x][c[x]++] = y;
	e[y][c[y]++] = x;
}

int dfs(int u, int f) {
	int a[1005];
	memset(a, 0, sizeof(a));
	int ch = 0;
	for (int i = 0; i < c[u] ; ++i) {
		if (e[u][i] != f) {
			a[ch++] = dfs(e[u][i], u);	
		}
	}
	
	sort(a, a + ch);
	
	if (ch == 0) return 1;
	else if (ch == 1) return 1;
	else {
		return a[ch-1] + a[ch-2] + 1;
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ", tc);
		scanf("%d", &N);
		memset(e, -1, sizeof(e));
		memset(c, 0, sizeof(c));
		for (int i=1;i<N;++i) {
			scanf("%d%d", &x, &y);
			connect(x, y);
		}
		int mx = 0;
		for (int i=1;i<=N;++i) {
			int t = dfs(i, -1);
			if (t > mx) mx = t;
		}
		printf("%d\n", N - mx);
	}
	return 0;
}