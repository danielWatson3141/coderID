#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MN = 153;
const int ML = 43;

int N, L;
int a[MN];
int b[MN];
int at[MN];
char used[MN];

char cmp_ab()
{
	int i, j;
	memset(used, 0, sizeof(used));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (used[j]) continue;
			if (at[i] == b[j])
			{
				used[j] = 1;
				break;
			}
		}
		if (j >= N) return 0;
	}
	return 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t;
	int i, j, k;
	char str[ML];
	int rt;
	int cnt;
	int mx;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d%d", &N, &L);
		for (i = 0; i < N; i++)
		{
			scanf("%s", str);
			a[i] = 0;
			for (j = 0; j < L; j++)
			{
				a[i] = (a[i] << 1) + str[j] - '0';
			}
		}
		for (i = 0; i < N; i++)
		{
			scanf("%s", str);
			b[i] = 0;
			for (j = 0; j < L; j++)
			{
				b[i] = (b[i] << 1) + str[j] - '0';
			}
		}
		mx = 0;
		for (i = 0; i < L; i++)
		{
			mx = (mx << 1) + 1;
		}
		rt = -1;
		for (i = 0; i <= mx; i++)
		{
			memcpy(at, a, sizeof(int) * N);
			cnt = 0;
			k = i;
			for (j = 0; j < L; j++)
			{
				if ((k & 1) == 1) cnt++;
				k >>= 1;
			}
			for (j = 0; j < N; j++)
			{
				at[j] ^= i;
			}
			if (cmp_ab() && (rt == -1 || rt > cnt))
				rt = cnt;
		}
		if (rt == -1) printf("NOT POSSIBLE\n");
		else printf("%d\n", rt);
	}
	
	return 0;
}