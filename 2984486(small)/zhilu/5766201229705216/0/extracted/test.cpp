#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

const int SZ = 15;

int N;
int e[SZ][2];
char used[SZ];

char is_bt()
{
	int i;
	int n = 0;
	int en = 0;
	int two = 0, one = 0, three = 0;
	int cnt[SZ];
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < N - 1; i++)
	{
		if ((!used[e[i][0]]) && (!used[e[i][1]]))
		{
			en++;
			cnt[e[i][0]]++;
			cnt[e[i][1]]++;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (used[i]) continue;
		n++;
		if (cnt[i] == 1) one++;
		else if (cnt[i] == 2) two++;
		else if (cnt[i] == 3) three++;
		else return 0;
	}
	if (n - 1 != en || two != 1) return 0;
	return 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t;
	int i, j, k;
	int mx;
	int num;
	int rt;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d", &N);
		for (i = 0; i < N - 1; i++)
		{
			scanf("%d%d", &e[i][0], &e[i][1]);
			e[i][0]--; e[i][1]--;
		}
		mx = 0;
		for (i = 0; i < N; i++)
		{
			mx = (mx << 1) + 1;
		}
		rt = N - 1;
		for (i = 0; i < mx; i++)
		{
			memset(used, 0, sizeof(used));
			num = 0;
			k = i;
			for (j = 0; j < N; j++)
			{
				if ((k & 1) == 1) 
				{
					num++;
					used[j] = 1;
				}
				k >>= 1;
			}
			if (num < rt)
			{
				if (is_bt() && rt > num)
					rt = num;
			}
		}
		printf("%d\n", rt);
	}
	
	return 0;
}