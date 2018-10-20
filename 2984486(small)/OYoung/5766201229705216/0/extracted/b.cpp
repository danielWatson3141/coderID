#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ans;
bool u[1100];
int f[1100][3];
vector<int> e[1100];

void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) e[i].clear();
	int x, y;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
}

void solve(int x)
{
	u[x] = true; int y, z;
	f[x][0] = 0; f[x][1] = f[x][2] = n + 1;
	for (int i = 0; i < e[x].size(); i++) {
		y = e[x][i]; if (u[y]) continue;
		solve(y);
		z = min(f[x][2] + f[y][0], f[x][1] + f[y][2]);
		f[x][2] = min(n + 1, z);
		z = min(f[x][1] + f[y][0], f[x][0] + f[y][2]);
		f[x][1] = min(n + 1, z);
		f[x][0] += f[y][0];
	}
	f[x][2] = min(f[x][2], f[x][0]);
	++f[x][0];
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int cas, tmp; scanf("%d", &cas);
	for (int t = 1; t <= cas; t++) {
		init(); ans = n + 1;
		for (int i = 1; i <= n; i++) {
			memset(u, 0, sizeof(u));
			solve(i);
			tmp = min(f[i][0], f[i][2]);
			for (int j = 1; j <= n; j++)
				if (!u[j]) ++tmp;
			ans = min(ans, tmp);
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

