#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))

vector<int> tree[1010];
int dp[1010][1010];
int nodes[1010][1010];

int CalcNodes(int parent, int node)
{
	int& res = nodes[parent][node];
	if (res < 0)
	{
		res = 1;
		for (int i = 0; i < tree[node].size(); i++)
		{
			if (tree[node][i] != parent) res += CalcNodes(node, tree[node][i]);
		}
	}

	return res;
}

int doit(int parent, int node)
{
	int& res = dp[parent][node];
	if (res == -1)
	{
		vector<int> cost;
		vector<int> nodes;
		for (int i = 0; i < tree[node].size(); i++)
		{
			if (tree[node][i] != parent)
			{
				cost.push_back(doit(node, tree[node][i]));
				nodes.push_back(CalcNodes(node, tree[node][i]));
			}
		}
		if (cost.size() == 0)
		{
			res = 0;
		}
		else if (cost.size() == 1)
		{
			res = nodes[0];
		}
		else
		{
			int nodes_sum = 0;
			for (int i = 0; i < cost.size(); i++)
			{
				nodes_sum += nodes[i];
			}

			res = 1000000;
			for (int i = 0; i < cost.size() - 1; i++)
			{
				for (int j = i + 1; j < cost.size(); j++)
				{
					int r = cost[i] + cost[j] + nodes_sum - nodes[i] - nodes[j];
					res = min(res, r);
				}
			}
		}
	}

	return res;
}

void Solve()
{
	int i, j, k, n, m;

	in_int1(n);
	for (i = 1; i<=n; i++) tree[i].clear();
	for (i = 0; i < n - 1; i++)
	{
		in_int2(j, k);
		tree[j].push_back(k);
		tree[k].push_back(j);
	}

	int best = 1000000;
	memset(dp, -1, sizeof(dp));
	memset(nodes, -1, sizeof(nodes));
	for (i = 1; i <= n; i++)
	{
		int ret = doit(0, i);
		best = min(best, ret);
	}

	printf(" %d", best);
}

int main(int argc, char**argv)
{
	if (argc > 1) freopen(argv[1], "rt", stdin);
	else freopen("input.txt", "rt", stdin);

	freopen("output.txt", "wt", stdout);
	int test;

	in_int1(test);
	for (int step = 1; step <= test; step++)
	{
		printf("Case #%d:", step);
		Solve();
		printf("\n");
	}
	return 0;
}