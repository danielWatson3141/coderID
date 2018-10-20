#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<vector<int>> G;
bool used[1005];

int dfs(int v)
{
	used[v] = true;
	int f = 0;
	int s = 0;
	for (int i = 0; i < G[v].size(); ++i)
	{
		int u = G[v][i];
		if (!used[u])
		{
			int t = dfs(u);
			if (t > s)
				swap(t, s);
			if (s > f)
				swap(f, s);
		}
	}
	used[v] = false;
	if (s != 0)
		return f + s + 1; 
	else
		return 1;
}

void solve()
{
	G.clear();
	int n;
	cin >> n;
	G.resize(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, dfs(i));
	}
	cout << n - ans;
}

void main()
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	
	/*
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; ++i)
	{
		ans[i] = stupid();
	}
	fclose(stdin);
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		if (ans[i] != solve())
			cout << "assadsasadasds";
	}
	*/
}