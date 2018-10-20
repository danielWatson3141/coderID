#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 1004;
FILE *in, *out;
int cs;
int n;
bool a[maxn][maxn];
int cnt[maxn][maxn], m[maxn];

void dfs(int u, int v) {
	if (cnt[u][v] >= 0) return;
	int deg = 0;
	for (int i=1; i <= n; i++) if (i!=u && a[v][i]) deg++;
	if (deg <= 1) { cnt[u][v] = 1; return; }
	int cc = 0;
	for (int i=1; i <= n; i++) if (i!=u && a[v][i]) dfs(v, i);
	for (int i=1; i <= n; i++) if (i!=u && a[v][i]) {
		m[cc++] = cnt[v][i];
	}
	sort(m, m+cc);
	cnt[u][v] = m[cc-1]+m[cc-2] + 1;
}

void solve() {
	memset(cnt, -1, sizeof(cnt));
	for (int i=1; i <= n; i++) dfs(n+1, i);
	int ans = 0;
	for (int i=1; i <= n; i++) if (ans < cnt[n+1][i]) ans = cnt[n+1][i];
	fprintf(out, "%d\n", n-ans);
}

int main()
{
	int T, x, y;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (cs=1; cs <= T; cs++) {
		memset(a, 0, sizeof(a));
		fscanf(in, "%d", &n);
		for (int i=1; i < n; i++) {
			fscanf(in, "%d%d", &x, &y);
			a[x][y] = a[y][x] = true;
		}
		//for (int i=1; i <= n; i++) a[n+1][i] = true;
		fprintf(out, "Case #%d: ", cs);
		solve();
	}
	return 0;
}
