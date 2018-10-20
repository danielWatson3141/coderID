#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int test, tt, n, i, a, b, ans, size[2005];
int e[2005], last[2005], succ[2005], sum;

int dfs(int i, int f);

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	while (test--)
	{
		printf("Case #%d: ", ++tt);
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			last[i] = 0;
		sum = 0;
		for (i = 1; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			e[++sum] = b, succ[sum] = last[a], last[a] = sum;
			e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		}
		
		ans = 1;
		for (i = 1; i <= n; i++)
			ans = max(ans, dfs(i, 0));
		printf("%d\n", n - ans);
	}
	
	return 0;
}

int dfs(int i, int f)
{
	int x, s1 = 0, m1 = 0, m2 = 0;
	size[i] = 0;
	for (x = last[i]; x; x = succ[x])
	{
		if (e[x] == f)
			continue;
		m2 = max(dfs(e[x], i), m2);
		size[i] += size[e[x]];
		if (m2 > m1)
			swap(m1, m2);
		s1++;
	}
	
	size[i]++;
	if (s1 <= 1)
		return 1;
	else
		return m1 + m2 + 1;
}

