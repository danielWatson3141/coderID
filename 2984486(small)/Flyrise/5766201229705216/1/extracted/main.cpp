#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define mp make_pair
#define pb push_back
#define NAME ""

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 1e5 + 3;
const ld pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int p[nmax], sz[nmax], ind;
vector<int> a[nmax];
int t, x, y, n;

int dfs(int v, int par)
{
	sz[v] = 1;
//	if (v == 0 && ind == 5)
//		cerr << "SIZE " << a[v].size() << endl;
	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] != par)
			sz[v] += dfs(a[v][i], v);
	return sz[v];
}

int dfsa(int v, int par)
{
	int d[1000];
//	if (ind == 5)
//		cout << v << endl;
	int ans = sz[v] - 1;
	bool f = false;
	for (int i = 0; i < a[v].size(); i++)
		if (a[v][i] != par)
			d[i] = dfsa(a[v][i], v);
	for (int i = 0; i < a[v].size(); i++)
	{
		if (a[v][i] == par)
			continue;
		for (int j = 0; j < a[v].size(); j++)
		{
			if (a[v][j] == par || i == j)
				continue;
			f = true;
			int ansb = d[i] + d[j] + sz[v] - sz[a[v][i]] - sz[a[v][j]] - 1;
//			if (v == 14 && ind == 5)
//				cerr << ansb << " " << d[i] << " " << d[j] << " " << a[v][j] << endl;
			ans = min(ans, ansb);
		}
	}
//	if (ind == 5)
//		cout << v << " " << ans << endl;
//	if (ind == 5)
//		cout << -v << endl;
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			a[i].clear();
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			a[x].pb(y);
			a[y].pb(x);
		}
		int answer = inf;
		for (int z = 0; z < n; z++)
		{
			ind = z;
			dfs(z, z);
			answer = min(dfsa(z, -1), answer);
		}
		cout << "Case #" << q + 1 << ": " << answer << endl;	
	}
}