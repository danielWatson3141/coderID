#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define INF 1000000000
#define EPS 1e-9

int N;
bool graph[1001][1001];
int dp[1001][1001];
int delCounts[1001][1001];

int del(int cur, int f)
{
	if (f >= 0 && delCounts[cur][f] != -1)
		return delCounts[cur][f];

	int count = 1;
	for (int i = 0; i < N; i++)
	{
		if (cur == i || i == f || !graph[cur][i]) continue;
		count += del(i, cur);
	}
	
	if (f >= 0)
		delCounts[cur][f] = count;

	return count;
}

int choose(int cur, int f)
{
	if (f >= 0 && dp[cur][f] != -1)
		return dp[cur][f];

	int res = del(cur, f);
	int child = 0;
	int childIds[1001];
	for (int i = 0; i < N; i++)
	{
		if (cur == i || i == f || !graph[cur][i]) continue;
		childIds[child++] = i;
	}

	if (child >= 2)
	{
		for (int i = 0; i < child; i++)
		{
			for (int j = i + 1; j < child; j++)
			{
				int now = choose(childIds[i], cur) + choose(childIds[j], cur);
				for (int k = 0; k < child; k++)
				{
					if (k == i || k == j) continue;
					now += del(childIds[k], cur);
				}
				res = min(res, now);
			}
		}
	}
	else if (child == 1)
	{
		res = del(childIds[0], cur);
	}
	else
	{
		res = 0;
	}

	if (f >= 0)
	{
		dp[cur][f] = res;
	}
	return res;
}

void _main()
{
	scanf("%d", &N);
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	memset(dp, 0xff, sizeof(dp));
	memset(delCounts, 0xff, sizeof(delCounts));
	int res = N - 1;
	for (int i = 0; i < N; i++)
	{
		res = min(res, choose(i, -1));
	}
	printf("%d\n", res);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		printf("Case #%d: ", cases);
		_main();
	}
}