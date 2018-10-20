#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
int t, n, l;
long long a[200], b[200];
map<long long, int> mp;

long long input()
{
	char s[100];
	scanf("%s", s);
	long long ret = 0;
	for (int i = 0; i < l; i++)
		ret = ret * 2 + s[i] - '0';
	return ret;
}

int calc(long long k)
{
	int ret = 0;
	while (k)
	{
		ret += k & 1;
		k >>= 1;
	}
	return ret;
}

int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++) a[i] = input();
		for (int i = 1; i <= n; i++) b[i] = input();
		mp.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[a[i] ^ b[j]]++;
		int ret = -1;
		for (map<long long, int>::iterator mpi = mp.begin(); mpi != mp.end(); mpi++)
			if (mpi->second == n)
			{
				if (ret == -1)
					ret = calc(mpi->first);
				else ret = min(calc(mpi->first), ret);
			}
		printf("Case #%d: ", tt);
		if (ret == -1)
			puts("NOT POSSIBLE");
		else printf("%d\n", ret);
	}
	return 0;
}
