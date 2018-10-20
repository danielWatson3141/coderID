#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T, n, l;
bool t[160];
long long a[160], b[160];

long long convert(char st[])
{
	long long v = 0;
	for (int i = 0; i < l; ++i)
		v = v * 2ll + st[i] - '0';
	return v;
}

int countbit(long long x)
{
	int cnt = 0;
	while (x > 0)
	{
		if (x & 1) ++cnt;
		x >>= 1;
	}
	return cnt;
}

void work()
{
	scanf("%d%d", &n, &l);
	char st[50];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", st);
		a[i] = convert(st);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", st);
		b[i] = convert(st);
	}
	long long x;
	int ans = l + 1;
	for (int i = 0; i < n; ++i)
	{
		memset(t, 0, sizeof(t));
		x = a[0] ^ b[i];
		t[i] = true;
		bool flag = true;
		for (int j = 1; j < n; ++j)
		{
			flag = false;
			for (int k = 0; k < n; ++k)
				if ((!t[k]) && (a[j] ^ b[k]) == x)
				{
					t[k] = flag = true;
					break;
				}	
			if (!flag) break;
		}
		if (flag) ans = min(ans, countbit(x));
	}
	if (ans <= l) printf("%d\n", ans);
	else printf("NOT POSSIBLE\n");
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
