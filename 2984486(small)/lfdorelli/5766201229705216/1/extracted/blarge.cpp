#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

typedef long long int LL;
using namespace std;


#define N 1001

vector <int> g[N];
int sz[N];
int n, mh, vs;
		
#define S second
#define F first

int dfs (int i, int p)
{	
	sz[i] = 1;

	vector < pair<int, int> > filhos;
	
	for (int j = 0; j < g[i].size(); ++j)
	{
		int k = g[i][j];
		if (k == p) continue;
		int ret = dfs (k, i);
		filhos.push_back( make_pair(ret, k) );
		sz[i] += sz[k];
	}

	int res;

	if (filhos.size() == 0) res = 0;
	else if (filhos.size() == 1) res = sz[filhos[0].second]; 
	else {
		int tot = 0;
		int m = filhos.size();

		for (int j = 0; j < m; ++j) tot += sz[filhos[j].second];
		
		res = tot;
		for (int j = 0; j < m; ++j)
			for (int k = j + 1; k < m; ++k)
				res = min(res, tot - sz[filhos[j].S] - sz[filhos[k].S] + filhos[j].F + filhos[k].F);
	}
	return res; 
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
		for (int i = 0; i < n; ++i) {
			res = min (res, dfs (i, -1));
		}

		printf("Case #%d: %d\n", caso++, res);
	}	

	return 0;
}