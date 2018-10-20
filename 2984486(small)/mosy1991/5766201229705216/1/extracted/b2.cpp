#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

#define MAXN 1005

vector<int> tr[MAXN];

int n;
int ans;
int f[MAXN][10];
bool vis[MAXN];

void dfs(int k)
{
	f[k][0] = 0;
	f[k][1] = f[k][2] = n + 1;
	for (int i = 0; i < tr[k].size(); ++i)
	{
		int p = tr[k][i];
		if (vis[p]) continue;
		vis[p] = true;
		dfs(p);
		int q = min(f[k][2] + f[p][0], f[k][1] + f[p][2]);
		f[k][2] = min(n + 1, q);
		q = min(f[k][1] + f[p][0], f[k][0] + f[p][2]);
		f[k][1] = min(n + 1, q);
		f[k][0] += f[p][0];
	}
	f[k][2] = min(f[k][2], f[k][0]);
	++f[k][0];
}

void solve()
{
	ans = n - 1;
	for (int i = 1; i <= n; ++i)
	{
		memset(vis, false, sizeof(vis));
		vis[i] = true;
		dfs(i);
		ans = min(ans, f[i][0]);
		ans = min(ans, f[i][2]);
	}
}

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			tr[i].clear();
		for (int i = 0; i < n - 1; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tr[x].push_back(y);
			tr[y].push_back(x);
		}
		solve();
		printf("Case #%d: ", ++cases);
		printf("%d\n", ans);
	}
	return 0;
}
