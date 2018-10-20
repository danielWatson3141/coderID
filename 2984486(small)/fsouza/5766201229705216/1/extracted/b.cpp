#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 1000

typedef long long lint;

using namespace std;

vector <int> adj[MAXN];

int solve(int v, int parent)
{
	int ret = 1;
	vector <int> vals;

	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i];
		if (v2 != parent)
			vals.push_back(solve(v2, v));
	}
	
	sort(vals.rbegin(), vals.rend());

	if (vals.size() >= 2) ret += vals[0] + vals[1];

	return ret;
}

int main(int argc, char ** argv)
{
	int nt;
	
	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) adj[i].clear();

		for (int i = 0; i < n-1; i++) {
			int a, b;
			scanf("%d %d", &a, &b); a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int result = 0;

		for (int i = 0; i < n; i++)
			result = max(result, solve(i, -1));

		printf("Case #%d: %d\n", t+1, n - result);
	}

	return 0;
}
