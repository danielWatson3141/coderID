#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
#define pb push_back

vb marked;

int dfs(vvi& g, int from, int v){
	//printf("dfs(%d, %d)\n", from, v);
	int count = 0;
	vi f;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int x = g[v][i];
		if(x != from){
			f.pb(x);
		}
	}
	int sub = 0;
	if(f.size() < 2){
		//printf("return 1;\n");
		return 1;
	}
	else if(f.size() >= 2)
	{
		for (int i = 0; i < f.size(); ++i)
		{
			for (int j = i + 1; j < f.size(); ++j)
			{
				int x = f[i];
				int y = f[j];
				sub = max(sub, dfs(g, v, x) + dfs(g, v, y));
			}
		}
	}
	//printf("return %d\n", sub);
	return 1 + sub;
}

int main(int argc, char const *argv[])
{
	int T, n, a, b;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d", &n);
		vvi g(n + 5);
		for (int i = 0; i < n - 1; ++i)
		{
			scanf("%d %d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			marked = vb(g.size(), false);
			int x = dfs(g, 0, i);
			count = max(count, x);
		}
		printf("Case #%d: %d\n", tt, n - count);
	}
	return 0;
}