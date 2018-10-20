#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int f(int p, int v, vector<vector<int> > & mem, vector<vector<int> > & adjl)
{
	if (mem[p][v] != 0) {
		return mem[p][v];
	}
	if (adjl[v].size()-(p != 0 ? 1: 0) < 2) {
		return 1;
	}
	int max1 = 1, max2 = 1;
	for (__typeof(adjl[v].begin()) it = adjl[v].begin(); it != adjl[v].end(); ++it) {
		if (*it == p) {
			continue;
		}
		int size = f(v, *it, mem, adjl);
		if (size > max1) {
			max2 = max1;
			max1 = size;
		}
		else if (size > max2) {
			max2 = size;
		}
	}
	return mem[p][v] = max1 + max2 + 1;
}

int main()
{
	int ntest;
	cin >> ntest;
	for (int i = 1; i <= ntest; i++) {
		int n;
		cin >> n;
		vector<vector<int> > adjl(n+1);
		for (int j = 0; j < n-1; j++) {
			int u, v;
			cin >> u >> v;
			adjl[u].push_back(v);
			adjl[v].push_back(u);
		}
		vector<vector<int> > mem(n+1, vector<int>(n+1));
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			ans = max(ans, f(0, j, mem, adjl));
		}
		printf("Case #%d: %d\n", i, n-ans);
	}
	return 0;
}
