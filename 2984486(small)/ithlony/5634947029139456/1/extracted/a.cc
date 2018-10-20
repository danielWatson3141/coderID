#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXL = 200;
const int MAXN = 200;

char s[MAXL];
long long a[MAXN], b[MAXN], c[MAXN];
int n, l;

int count(long long x)
{
	int ret = 0;
	while (x)
	{
		ret += x % 2;
		x /= 2;
	}
	return ret;
}

bool check(long long t)
{
	for (int i = 0; i < n; ++i)
	{
		c[i] = a[i] ^ t;
	}
	sort(c, c + n);
	for (int i = 0; i < n; ++i)
		if (c[i] != b[i])
			return false;
	return true;
}

int solve()
{
	int ret = -1;
	for (int i = 0; i < n; ++i)
	{
		long long t = a[0] ^ b[i];
		int cnt = count(t);
		//cout << t << endl;
		if (!check(t))
			continue;
		if (ret == -1 || cnt < ret)
			ret = cnt;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			a[i] = 0;
			for (int j = 0; j < l; ++j)
				a[i] = a[i] * 2 + s[j] - '0';
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			b[i] = 0;
			for (int j = 0; j < l; ++j)
				b[i] = b[i] * 2 + s[j] - '0';
		}
		sort(b, b + n);
		int ans = solve();
		if (ans == -1)
			printf("Case #%d: NOT POSSIBLE\n", tt);
		else
			printf("Case #%d: %d\n", tt, ans);
	}

	return 0;
}
