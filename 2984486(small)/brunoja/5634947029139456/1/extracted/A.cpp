#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const char lend = '\n';
const int N = 151;
const int L = 51;
int n, l, B[N], G[N][N], vis[N];
map<string, vector<int> > go[N];
char out[N][L], dev[N][L];
set<string> use;

int dfs(int x)
{
	if (!x) return 1;
	vis[x] = 1;
	for (int i = 1; i <= n; ++i) if (G[x][i])
	{
		if (!vis[B[i]] && dfs(B[i]))
		{
			B[i] = x;
			return 1;
		}
	}
	return 0;
}

int solve()
{
	int res = N;
	
	// for each mask
	for (typeof(use.begin()) it = use.begin(); it != use.end(); ++it)
	{
		string now = *it;
		int r = 0;
		for (int i = 0; i < now.size(); ++i)
			r += now[i] == '1';
		if (r >= res) continue;
		memset(B, 0, sizeof B);
		memset(G, 0, sizeof G);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < go[i][now].size(); ++j)
				G[i+1][go[i][now][j]+1] = 1;
		int d = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(vis, 0, sizeof vis);
			d += dfs(i);
		}
		if (d == n) res = r;
	}
	
	return res;
}

int main() 
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	
	for (int caso = 1; caso <= t; ++caso)
	{
		cout << "Case #" << caso << ": ";
		cin >> n >> l;
		for (int i = 0; i < n; ++i)
			cin >> out[i];
		for (int i = 0; i < n; ++i)
			cin >> dev[i];
		use.clear();
		for (int i = 0; i < n; ++i)
		{
			go[i].clear();
			for (int j = 0; j < n; ++j)
			{
				string mask;
				for (int k = 0; k < l; ++k)
				{
					if (out[i][k] != dev[j][k]) mask += '1';
					else mask += '0';
				}
				use.insert(mask);
				go[i][mask].push_back(j);
			}
		}
		int res = solve();
		if (res == N) cout << "NOT POSSIBLE" << lend;
		else cout << res << lend;
	}
}
