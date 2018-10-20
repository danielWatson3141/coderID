#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 1005;

vector<int> g[N];
int sz_[N];

int dfs(int v, int from) {
	vector<int> top;
	sz_[v] = 1;
	for (int i = 0; i < sz(g[v]); i++) {
		int to = g[v][i];
		if (to != from) {
			int val = dfs(to, v);
			top.pb(sz_[to] - val);
			sz_[v] += sz_[to];
		}
	}
	int sum = sz_[v] - 1;	
	if (sz(top) >= 2) {
		sort(top.begin(), top.end());				
		reverse(top.begin(), top.end());
		sum -= top[0] + top[1];		
	}	
	return sum;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
			g[j].clear();
		for (int j = 1; j < n; j++) {
			int x, y;
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}
		int res = n + 1;
		for (int j = 1; j <= n; j++) {
			res = min(dfs(j, -1), res);
		}
		printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}
