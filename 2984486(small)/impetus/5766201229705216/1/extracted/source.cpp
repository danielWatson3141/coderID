#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>

using namespace std;
const int INF = 1000000000;

vector<vector<int> > g;
int n;
int sz[1100];

int dfs(int v, int from)
{
	sz[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != from)
			sz[v] += dfs(g[v][i], v);
	return sz[v];
}

int solve(int v, int from)
{
	int s = 0;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != from)
			s += sz[g[v][i]];
	vector<int> a;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != from)
		{
			int p = solve(g[v][i], v);
			if (p != INF)
				a.push_back(p - sz[g[v][i]]);
		}
	if (a.size() < 2)
		return s;
	sort(a.begin(), a.end());
	return min(s, s + a[0] + a[1]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	cin >> n;
    	g.clear();
    	g.resize(n);
    	for (int i = 0; i < n - 1; i++)
   		{
   			int p, q;
   			cin >> p >> q;
   			p--; q--;
   			g[p].push_back(q);
   			g[q].push_back(p);
   		}
   		int best = INF;
   		for (int i = 0; i < n; i++)
   		{
   			dfs(i, -1);
	   		best = min(best, solve(i, -1));
	   	}
    	cout << "Case #" << tc + 1 << ": " << best << endl;
    }
    return 0;
}