#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 5000 + 10;

int last[MAXN];
int y[MAXN], pre[MAXN];
int n;
int f[MAXN];

void dfs(int x, int fa)
{
	int cnt = 0;
	for (int i = last[x]; i != 0; i = pre[i])
	{
		if (y[i] == fa)
			continue;
		++cnt;
	}
	f[x] = 1;
	if (cnt <= 1)
		return;
	/*
	if (cnt > 2)
		cerr << "222" << endl;
		*/
	int max1 = 0, max2 = 0;
	for (int i = last[x]; i != 0; i = pre[i])
	{
		if (y[i] == fa)
			continue;
		dfs(y[i], x);
		if (f[y[i]] > max1)
		{
			max2 = max1;
			max1 = f[y[i]];
		}
		else if (f[y[i]] > max2)
		{
			max2 = f[y[i]];
		}
	}
	f[x] += max1 + max2;
}

int solve()
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(f, 0, sizeof(f));
		dfs(i, 0);
		if (f[i] > ans) 
			ans = f[i];
		//cout << f[i] << endl;
	}
	return n - ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d", &n);
		memset(last, 0, sizeof(last));
		for (int i = 1; i < n; ++i)
		{
			int x, yy;
			scanf("%d%d", &x, &yy);
			y[i] = yy;
			pre[i] = last[x];
			last[x] = i;
			y[i + n - 1] = x;
			pre[i + n - 1] = last[yy];
			last[yy] = i + n - 1;
		}
		printf("Case #%d: %d\n", tt, solve());
	}

	return 0;
}
