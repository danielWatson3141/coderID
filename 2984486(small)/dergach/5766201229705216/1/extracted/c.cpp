#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pi acos(-1.0)

int n;
vector <int> v[1005];
int used[1005];
int dp[1005];

int solve(int i)
{
	if(v[i].size() < 2) return 1;
	if(dp[i] == -1)
	{
		vector <int> subres;
		for(int j = 0; j < v[i].size(); j++)
			subres.push_back(solve(v[i][j]));
		sort(subres.begin(), subres.end());
		dp[i] = 1 + subres[subres.size()-1] + subres[subres.size()-2];
	}
	return dp[i];
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int res = 0;
		scanf("%d", &n);
		vector <vector <int> > g(n, vector <int> ());
		for(int i = 0; i < n - 1; i++)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			from--; to--;
			g[from].push_back(to);
			g[to].push_back(from);
		}
		for(int root = 0; root < n; root++)
		{
			for(int i = 0; i < n; i++)
				v[i].clear();
			queue <int> q;
			q.push(root);
			memset(used, 0, sizeof(used));
			while(!q.empty())
			{
				int i = q.front(); q.pop();
				used[i] = 1;
				for(int j = 0; j < g[i].size(); j++)
					if(used[g[i][j]] == 0)
					{
						v[i].push_back(g[i][j]);
						q.push(g[i][j]);
					}
			}
			memset(dp, -1, sizeof(dp));
			res = max(res, solve(root));
		}
		printf("Case #%d: %d\n", t, n - res);
	}
	return 0;
}