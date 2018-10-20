#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int t, n, sum[1010], f[1010];
vector<int> v[1010], x;

void dfs(int fa, int u)
{
	int s = 0;
	sum[u] = 1;
	for (int i = 0; i < v[u].size(); i++)
		if (fa != v[u][i])
		{
			s++;
			dfs(u, v[u][i]);
			sum[u] += sum[v[u][i]];
		}
	x.clear();
	for (int i = 0; i < v[u].size(); i++)
		if (fa != v[u][i])
		{
			x.push_back(f[v[u][i]] - sum[v[u][i]]);
		}
	f[u] = sum[u] - 1;
	if (s <= 1) return;
	nth_element(x.begin(), x.begin() + 1, x.end());
	f[u] += x[0] + x[1];
}

int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans = n;
		for (int i = 1; i <= n; i++)
		{
			memset(sum, 0, sizeof(sum));
			memset(f, 0, sizeof(f));
			dfs(0, i);
			ans = min(ans, f[i]);
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
