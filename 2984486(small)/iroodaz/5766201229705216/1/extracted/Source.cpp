#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

vector <int> adj[1010];

int sz[1010];
int kpc[1010];
int solve(int cur, int par)
{
	vector <int> costs;
	kpc[cur] = 1000000;
	int allsz = sz[cur] - 1;
	int chc = (par == (-1) ? adj[cur].size() : adj[cur].size() - 1);
	for (auto x : adj[cur])
	{
		if (x == par)
			continue;
		solve(x, cur);
	}
	if (!chc)
	{
		kpc[cur] = 0;
		return 0;
	}
	if (chc == 1)
	{
		kpc[cur] = allsz;
		return allsz;
	}
	for (int i = 0; i < adj[cur].size(); i++)
	{
		if (adj[cur][i] == par)
			continue;
		for (int j = i + 1; j < adj[cur].size(); j++)
		{
			if (adj[cur][j] == par)
				continue;
			int val = kpc[adj[cur][i]] + kpc[adj[cur][j]] + allsz - sz[adj[cur][i]] - sz[adj[cur][j]];
			kpc[cur] = min(kpc[cur], val);
		}
	}
	return kpc[cur];
		
}

int getsz(int cur, int par)
{
	sz[cur] = 1;
	for (auto x:adj[cur])
	{
		if (x == par)
			continue;
		sz[cur] += getsz(x, cur);
	}
	return sz[cur];
}

int main()
{
	int T, N,i,j,k,x,y;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		for (i = 0; i < 1010; i++)
			adj[i].clear();
		cin >> N;
		for (i = 0; i < N - 1; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 1000000;
		for (i = 1; i <= N; i++)
		{
			getsz(i, -1);
			ans = min(ans, solve(i, -1));
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
}