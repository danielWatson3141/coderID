#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#define vt vector
#define ll long long

typedef struct node
{
	int btcost, cnt, ind;
	node()
	{
		btcost = 0;
		cnt = 0;
		ind = 0;
	}
};

int count(vt< vt<int> >& g, int p, int v)
{
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
			cnt += 1 + count(g, v, g[v][i]);
	return cnt;
}

bool sortans(node a, node b)
{
		return a.cnt - a.btcost < b.cnt - b.btcost;
}

int dfs(vt< vt<int> >& g, int p, int v)
{
	int nodes = 0;
	vt<int> vert;
	for(int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
		{
			nodes++;
			vert.push_back(g[v][i]);
		}
	if (nodes == 0)
		return 0;
	else if (nodes == 1)
		return 1+count(g, v, vert[0]);
	else if (nodes == 2)
		return dfs(g, v, vert[0]) + dfs(g, v, vert[1]);
	else
	{
		vt< node > ans(nodes);
		for(int i = 0; i < nodes; i++)
		{
			ans[i].ind = vert[i];
			ans[i].btcost = dfs(g, v, ans[i].ind);
			ans[i].cnt = 1 + count(g, v, ans[i].ind);
		}
		sort(ans.begin(), ans.end(), sortans);
		int rem = 0;
		for(int i = 0; i < nodes-2; i++)
			rem += ans[i].cnt;
		return rem + ans[nodes-2].btcost+ ans[nodes-1].btcost;
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int cases = 1; cases <= t; cases++)
	{
		int n;
		cin >> n;
		vt< vt<int> > g(n+1);
		int a, b;
		for(int i = 0; i < n-1; i++)
		{
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans = INT_MAX;
		for(int i = 1; i <= n; i++)
			 ans = min(ans, dfs(g, 0, i));
		cout << "Case #" << cases << ": " << ans << endl;
	}
	return 0;
}