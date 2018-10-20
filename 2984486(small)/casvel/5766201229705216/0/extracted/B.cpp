#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define MP make_pair
#define INF (1<<30)

using namespace std;

typedef pair <int, int> ii;

vector <vector <int> > AdjList;

int dp[1005][1005];

int f(int p, int u)
{
	if (AdjList[u].size() == 0)
		return 1;

	if (dp[p][u] != -1)
		return dp[p][u];

	dp[p][u] = 1;
	For(i, 0, AdjList[u].size())
	{
		if (AdjList[u][i] == p)
			continue;

		For(j, i+1, AdjList[u].size())
		{
			if (AdjList[u][j] == p)
				continue;

			dp[p][u] = max(dp[p][u], f(u, AdjList[u][i]) + f(u, AdjList[u][j]) + 1);
		}
	}

	return dp[p][u];
}

int main()
{
	int T;
	scanf("%d", &T);

	For(caso, 1, T+1)
	{
		int N;
		scanf("%d", &N);

		AdjList.assign(N+1, vector <int> ());

		For(i, 0, N-1)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		memset(dp, -1, sizeof dp);
		int best = INF;
		For(i, 1, N+1)
			best = min(best, N - f(0, i));
	
		printf("Case #%d: %d\n", caso, best);
	}
	return 0;
}