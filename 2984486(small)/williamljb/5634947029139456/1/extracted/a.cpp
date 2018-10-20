#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 200, maxl = 50;
long long a[maxn], b[maxn];
map<long long, int> vis, init;
int ans, n, l;
char ch;

int num(long long x)
{
	int ans = 0;
	while (x)
	{
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}

bool same()
{
	for (map<long long, int>::iterator it = vis.begin(); it != vis.end(); ++it)
		if (init[it->first] != it->second)
			return false;
	return true;
}

void solve()
{
	scanf("%d %d", &n, &l);
	init.clear();
	while ((ch = getchar()) != '\n');
	for (int i = 0; i < n; ++i)
	{
		a[i] = 0;
		for (int j = 0; j < l; ++j)
		{
			scanf("%c", &ch);
			while (ch == ' ')
				scanf("%c", &ch);
			a[i] = a[i] * 2 + (ch - '0');
		}
	}
	while ((ch = getchar()) != '\n');
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
		for (int j = 0; j < l; ++j)
		{
			scanf("%c", &ch);
			while (ch == ' ')
				scanf("%c", &ch);
			b[i] = b[i] * 2 + (ch - '0');
		}
		init[b[i]]++;
	}
	ans = ~0u>>1;
	for (int i = 0; i < 1; ++i)
		for (int j = 0; j < n; ++j)
		{
			long long k = a[i] xor b[j];
			vis.clear();
			for (int o = 0; o < n; ++o)
			{
				vis[a[o] xor k]++;
			}
			if (same())
			{
				int tmp = num(k);
				if (ans > tmp)
					ans = tmp;
			}
		}
	if (ans == ~0u>>1)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", ans);
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
