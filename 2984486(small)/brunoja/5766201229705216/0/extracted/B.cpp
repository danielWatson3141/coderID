#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const char lend = '\n';
const int N = 1001;

int n, cnt[N], dp[N][3], V, vis[N][3];
vector<int> adj[N], vet[2];

int solve(int p, int b)
{
	if (p == vet[0].size()) return b == 2 ? 0 : N;
	int& res = dp[p][b];
	if (vis[p][b] == V) return res;
	vis[p][b] = V;
	res = solve(p+1, b)+vet[1][p];
	
	if (b < 2)
	{
		res = min(res, solve(p+1, b+1)+vet[0][p]);
	}
	
	return res;
}

int dfs(int p, int l)
{
	vector<int> use[2];
	for (int i = 0; i < adj[p].size(); ++i)
	{
		int q = adj[p][i];
		if (q == l) continue;
		use[0].push_back(dfs(q, p));
		use[1].push_back(1+cnt[q]);
		cnt[p] += 1+cnt[q];
	}
	vet[0] = use[0];
	vet[1] = use[1];
	if (vet[0].size() == 0) return 0;
	if (vet[0].size() == 1) return vet[1][0];
	++V;
	return solve(0, 0);
}

int main() 
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	
	for (int caso = 1; caso <= t; ++caso)
	{
		cout << "Case #" << caso << ": ";
		cin >> n;
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int res = n-1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				cnt[j] = 0;
			res = min(res, dfs(i, 0));
		}
		cout << res << lend;
	}
}
