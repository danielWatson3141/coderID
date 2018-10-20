#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 3000;

struct Edge{
	int v;
	int next;
}edge[MAXN];

int dv[MAXN];

int head[MAXN];
int n,size;

int dp[MAXN][MAXN];

void addedge(int u,int v)
{
	dv[u]++;
    edge[size].v=v;
    edge[size].next=head[u];
    head[u]=size++;
}

void init()
{
    size = 0;
    memset(head, -1, sizeof(head));
	memset(dv, 0, sizeof(dv));
	memset(dp, -1, sizeof(dp));
}

int DP(int cnt, int fa)
{
	if (dp[cnt][fa] > -1)
		return dp[cnt][fa];

	if (dv[cnt] <= 1)
		return dp[cnt][fa] = 1;
	if (fa > 0 && dv[cnt] == 2)
		return dp[cnt][fa] = 1;

	int max1 = 0;
	int max2 = 0;
	for (int j = head[cnt]; j != -1; j = edge[j].next)
	{
		int v = edge[j].v;
		if (v != fa)
		{
			int d = DP(v, cnt);
			if (d >= max1)
			{
				max2 = max1;
				max1 = d;
			}
			else if (d >= max2)
			{
				max2 = d;
			}
		}
	}
	return dp[cnt][fa] = max1+max2+1;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for (int nt = 1; nt <= T; ++nt)
	{
		init();
		int N, u, v;
		scanf("%d", &N);
		for (int i = 0; i < N-1; ++i)
		{
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		int ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			int as = DP(i, 0);
			if (as > ans)
				ans = as;
		}
		
		printf("Case #%d: %d\n", nt, N-ans);

		
	}
	return 0;
}