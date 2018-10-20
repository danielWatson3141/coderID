#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>
#include <deque>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define B 33
#define MAX 100
#define eps 1e-7
#define pi 3.14159
#define ull unsigned long long
#define MOD 1000000009

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int t,n,x,y;
vi adj[MAX];
int vis[MAX];
int cut[MAX];

bool dfs(int curr)
{
	int cont = 0;
	for (int i = 0; i < adj[curr].size(); ++i)
	{
		int u = adj[curr][i];
		if (cut[u])
		{
			vis[u] = 1;
		}

		if (!vis[u])
		{
			cont++;
			vis[u] = 1;
			if (!dfs(u))
				return false;
		}
	}

	return cont == 2 || cont == 0;
}

int solve(int curr)
{

	if (curr == (n + 1))
	{
		bool ok = false;

		for (int i = 1; i <= n; ++i)
		{
			if (cut[i])
				continue;

			memset(vis, 0, sizeof vis);
			vis[i] = 1;
			
			if (dfs(i))
				ok = true;
			
			for (int i = 1; i <= n; ++i)
			{
				if (cut[i])
					continue;

				if (!vis[i])
				{
					ok = false;
				}
			}

			if (ok)
				return 0;
		}

		if (!ok)
			return INF;

		return 0;
	}

	cut[curr] = 1;
	int ret = solve(curr + 1) + 1;

	cut[curr] = 0;
	ret = min(ret, solve(curr + 1));

	return ret;
}
int main(void)
{
	ios :: sync_with_stdio(false);
	cin >> t;
	int cases = 0;

	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= n; ++i)
			adj[i].clear();

		memset(cut, 0, sizeof cut);
		memset(vis, 0, sizeof vis);

		for (int i = 0; i < n - 1; ++i)
		{
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		int ret = solve(1);
		cout << "Case #" << ++cases << ": " << ret << "\n";
	}
	return 0;
}