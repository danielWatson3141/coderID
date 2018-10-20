#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;

#define loop(i, x) for (int i = 0; i < (x); i++)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))
#define MAXN 150
#define MAXL 40

typedef long long ll;

int codes[MAXN][MAXL];
int devices[MAXN][MAXL];
int crnt[MAXN][MAXL];

int N, L;

bool eq(int a, int b)
{
	loop(i, L)
	{
		if (devices[a][i] != crnt[b][i])
			return false;
	}
	return true;
}

bool hasMatch(int a)
{
	loop(i, N)
	{
		if (eq(a, i))
			return true;
	}
	return false;
}

int works(int a, int b)
{
	bool diffs[MAXL];
	int count = 0;
	
	loop(i, L)
	{
		diffs[i] = (codes[a][i] != devices[b][i]);
		if (diffs[i])
			count++;
	}
	
	loop(i, N)
	{
		loop(j, L)
		{
			if (diffs[j])
				crnt[i][j] = 1 - codes[i][j];
			else
				crnt[i][j] = codes[i][j];
		}
	}
	
	loop(i, N)
	{
		if (!hasMatch(i))
			return -1;
	}
	
	return count;
}

int solve()
{
	int best = INF;
	loop(a, N)
	{
		loop(b, N)
		{
			int w = works(a, b);
			if (w >= 0)
				best = min(best, w);
		}
	}
	
	if (best == INF)
		return -1;
	else
		return best;
}

int main()
{
	int T;
	rint(T);
	
	loop(testcase, T)
	{
		rint(N);
		rint(L);
		
		char buf[MAXL+1];
		
		loop(i, N)
		{
			scanf("%s", buf);
			loop(j, L)
				codes[i][j] = buf[j] - '0';
		}
		loop(i, N)
		{
			scanf("%s", buf);
			loop(j, L)
				devices[i][j] = buf[j] - '0';
		}
		
		int ans = solve();
		
		if (ans < 0)
			printf("Case #%d: NOT POSSIBLE\n", testcase+1);
		else
			printf("Case #%d: %d\n", testcase+1, ans);
	}
}