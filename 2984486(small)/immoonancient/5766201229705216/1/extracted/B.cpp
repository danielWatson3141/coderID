#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int n, m;
int list[maxn];
int edges[maxn * 2];
int next[maxn * 2];

void add_edge(int u, int v)
{
	edges[m] = v;
	next[m] = list[u];
	list[u] = m++;
}

int dfs(int u, int p)
{
//	cerr << u << " " << p << endl;
	
	int best1 = 0, best2 = 0;
	for (int e = list[u]; e; e = next[e])
		if (edges[e] != p)
		{
			int cur = dfs(edges[e], u);
			if (cur > best1)
			{
				best2 = best1;
				best1 = cur;
			}
			else
				best2 = max(best2, cur);
		}
	
	if (best2 == 0)
		return 1;
	else
		return best1 + best2 + 1;
}

int main()
{
	int caseN;
	cin >> caseN;
	for (int caseI = 1; caseI <= caseN; caseI++)
	{
		cin >> n;
		
		fill(list, list + maxn, 0);
		m = 2;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
			add_edge(v, u);
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dfs(i, 0));
			
		cout << "Case #" << caseI << ": " << n - ans << endl;
	}
	
	return 0;
}
