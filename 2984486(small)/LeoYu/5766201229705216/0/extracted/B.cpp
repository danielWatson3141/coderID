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

int N;
vector<int>	edge[1005];
int f[1005];

void	DFS(int x, int fa)
{
	f[x] = 1;
	int m1 = 0, m2 = 0;
	for (int i = 0; i < edge[x].size(); ++ i)
	{
		int y = edge[x][i];
		if (y != fa)
		{
			DFS(y, x);
			if (f[y] > m1)
			{
				m2 = m1;
				m1 = f[y];
			}
			elif (f[y] > m2)
				m2 = f[y];
		}
	}
	if (m1 && m2)	f[x] = max(f[x], 1 + m1 + m2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif

	int __ = read();
	for (int _ = 1; _ <= __; ++ _)
	{
		printf("Case #%d: ", _);
		N = read();
		for (int i = 1; i <= N; ++ i)	edge[i].clear();
		for (int i = 1; i < N; ++ i)
		{
			int x = read(), y = read();
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int	ans = N;
		for (int i = 1; i <= N; ++ i)
		{
			DFS(i, 0);
			ans = min(ans, N - f[i]);
		}
		cout << ans << endl;
	}

	return 0;
}

