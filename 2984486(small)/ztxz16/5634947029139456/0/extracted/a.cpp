#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int test, n, l, i, j, k, tt, ans;
char s1[1005][1005], s2[1005][1005];
map <long long, int> s;
map <long long, int> :: iterator it;

int count(long long a);

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d %d", &n, &l);
		for (i = 1; i <= n; i++)
			scanf("%s", s1[i]);
		for (i = 1; i <= n; i++)
			scanf("%s", s2[i]);
		s.clear();
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				long long now = 0;
				for (k = 0; k < l; k++)
					if (s1[i][k] != s2[j][k])
						now |= (1LL << k);
				s[now]++;
			}
		ans = OO;
		for (it = s.begin(); it != s.end(); ++it)
			if (it->second == n)
				ans = min(ans, count(it->first));
		printf("Case #%d: ", ++tt);
		if (ans == OO)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	
	return 0;
}

int count(long long a)
{
	int ret = 0;
	while (a)
	{
		if (a & 1LL)
			ret++;
		a >>= 1;
	}
	
	return ret;
}
