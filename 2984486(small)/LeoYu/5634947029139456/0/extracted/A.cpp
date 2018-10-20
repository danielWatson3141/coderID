/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

const int INF = 1 << 30;

int N, L;
char a[155][55], b[155][55];
LL	ida[155], idb[155];
map<LL, int>	sum;
int ans, c[55];

inline void	DFS(LL M, int step)
{
	if (step >= ans)	return;
	for (int t = 1; t <= L; ++ t)	if (c[t] == -1)
	{
		for (int ch = 0; ch < 2; ++ ch)
		{
			if (ch)
			{
				for (int i = 1; i <= N; ++ i)	a[i][t] ^= 1;
			}
			
			sum.clear();
			for (int i = 1; i <= N; ++ i)
			{
				if (a[i][t])	sum[ida[i]] ++;
			}
			for (int i = 1; i <= N; ++ i)
			{
				if (b[i][t])
				{
					sum[idb[i]] --;
					if (!sum[idb[i]])	sum.erase(idb[i]);
				}
			}
			if (!sum.size())
			{
				for (int i = 1; i <= N; ++ i)
					ida[i] = ida[i] * 2 + a[i][t];
				for (int i = 1; i <= N; ++ i)
					idb[i] = idb[i] * 2 + b[i][t];
				c[t] = ch;
				DFS(M * 2, step + ch);
				c[t] = -1;
				for (int i = 1; i <= N; ++ i)	ida[i] /= 2;
				for (int i = 1; i <= N; ++ i)	idb[i] /= 2;
			}
			
			if (ch)
			{
				for (int i = 1; i <= N; ++ i)	a[i][t] ^= 1;
			}
		}
		
		return;
	}
	ans = step;
	//for (int i = 1; i <= L; ++ i)	ansc[i] = c[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int __ = read();
	for (int _ = 1; _ <= __; ++ _)
	{
		printf("Case #%d: ", _);
		
		N = read(), L = read();
		for (int i = 1; i <= N; ++ i)
		{
			scanf("%s", a[i] + 1);
			for (int j = 1; j <= L; ++ j)
				a[i][j] -= '0';
		}
		for (int i = 1; i <= N; ++ i)
		{
			scanf("%s", b[i] + 1);
			for (int j = 1; j <= L; ++ j)
				b[i][j] -= '0';
		}
		
		for (int i = 1; i <= N; ++ i)	ida[i] = 0;
		for (int i = 1; i <= N; ++ i)	idb[i] = 0;
		for (int i = 1; i <= L; ++ i)	c[i] = -1;
		
		ans = INF;
		DFS(1, 0);
		if (ans == INF)
		{
			printf("NOT POSSIBLE\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}

	return 0;
}

