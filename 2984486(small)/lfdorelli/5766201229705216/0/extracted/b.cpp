#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>

typedef long long int LL;
using namespace std;


#define N 1001

vector <int> g[N];
int mask; 
int hei[N], vis[N];
int n, mh, vs;
		

int dfs (int i, int p, int h)
{	
	vis[i] = 1;
	mh = max(mh, h);
	hei[h]++;
	++vs;
	int cnt = 0;
	for (int j = 0; j < g[i].size(); ++j)
	{
		int k = g[i][j];
		if (k == p) continue;
		if ((mask>>k)&1) continue;
		int ret = dfs (k, i, h + 1);
		if (ret == 0) return 0;
		cnt++;
	}
	if (cnt == 2 or cnt == 0) return 1;
	return 0; 
}

int main (void)
{
	int T;
	cin >> T;
	int caso = 1;
	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; ++i) g[i].clear();

		for (int j = 0; j < n-1; ++j)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int res = n;
		for (int d = 0; d < (1<<n); ++d)
		{
			mask = d;
			for (int i = 0; i < n; ++i)
			{
				mh = 0;
				vs = 0;

				if (dfs (i, -1, 0) and vs == n - __builtin_popcount(d)) 
				{
					// cout << "raiz  " << i << " " << dfs(i, -1, 0) << endl;
					// if (__builtin_popcount(d) == 2 and i == 3) 
					// {
					// 	cout << "Raiz " << (i+1) << " = " << vs << " :: " << (n - __builtin_popcount(d)) << endl;
					// 	for (int k = 0; k < n; ++k) cout << ((d>>k)&1);
					// 	cout << endl;
					// }
					res = min(res, __builtin_popcount(d));
				}
			}
		}

		printf("Case #%d: %d\n", caso++, res);
	}	

	return 0;
}