#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 1000 + 10;
int g[maxn], ay[maxn * 2], an[maxn * 2];
int ans, n, m;

void dfs(int x, int fa, int &f, int &size)
{
	size = 1, f = n;
	int h[maxn], s[maxn], k = 0, m1 = n, m2 = n;
	for (int i = g[x]; i; i = an[i])
		if (ay[i] != fa)
		{
			dfs(ay[i], x, h[k], s[k]);
			size += s[k];
			if (m1 > h[k] - s[k])
			{
				m2 = m1;
				m1 = h[k] - s[k];
			}
			else
				if (m2 > h[k] - s[k])
					m2 = h[k] - s[k];
			++k;
		}
	//cout << x << " " << fa << " " << m1 << " " << m2 << endl;
	if (k == 0)
	{
		f = 0;
		return;
	}
	if (k == 1)
	{
		f = size - 1;
		return;
	}
	f = size + m1 + m2 - 1;
}

void add(int x, int y)
{
	ay[++m] = y;
	an[m] = g[x];
	g[x] = m;
}

void solve()
{
	memset(g, 0, sizeof(g));
	m = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	ans = n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp, s;
		dfs(i, 0, tmp, s);
		//cout << tmp << endl;
		if (ans > tmp)
			ans = tmp;
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
