#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> g[1001];
int n;

int count(int i, int r)
{
	int ret = 1;
	for (int j = 0; j < g[i].size(); ++j)
	{
		if (g[i][j] == r)
			continue;
		ret += count(g[i][j], i);
	}
	return ret;
}

int solve(int i, int r)
{
	if (g[i].size() == 1 && g[i][0] == r)
		return 0;
	else if (g[i].size() == 1 || g[i].size() == 2 && r != 0)
		return count(g[i][0] == r ? g[i][1] : g[i][0], i);
	vector< pair<int, int> > v;
	int rem = 0;
	for (int j = 0; j < g[i].size(); ++j)
	{
		if (g[i][j] == r)
			continue;
		int res = solve(g[i][j], i);
		int c = count(g[i][j], i);
		v.push_back(make_pair(c, res));
		rem += c;
	}
	sort(v.begin(), v.end());
	rem -= v[v.size()-1].first+v[v.size()-2].first;
	rem += v[v.size()-1].second+v[v.size()-2].second;
	return rem;
}

int main()
{
	int t;
	cin >> t;
	for (int x = 1; x <= t; ++x)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 0; i < n-1; ++i)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = n;
		for (int i = 1; i <= n; ++i)
			res = min(res, solve(i, 0));
		cout << "Case #" << x << ": " << res << "\n";
	}
	return 0;
}
