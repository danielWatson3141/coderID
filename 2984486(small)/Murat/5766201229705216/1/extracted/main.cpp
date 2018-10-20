#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 1010;

int n;
vector<int> g[N];
int z[N][N][2];

int dfs(int v, int parent, int remove = 0) {
	int &res = z[v][parent][remove];
	if (res != -1) {
		return res;
	}
	vector<int> &gv = g[v];
	if (remove > 0) {
		res = 1;
		forn (i, gv.size()) {
			int to = gv[i];
			if (to == parent)
				continue;
			res += dfs(to, v, remove);
		}
		//printf("remove %d -> %d: %d\n", parent, v, res);
		return res;
	}
	int c = 0;
	int x = -1;
	int y = -1;
	forn (i, gv.size()) {
		int to = gv[i];
		if (to != parent) {
			++c;
			if (c == 1)
				x = to;
			else if (c == 2)
				y = to;
		}
	}
	
	if (c == 0) {
		res = 0;
	} else if (c == 2) {
		res = dfs(x, v) + dfs(y, v);
	} else {
		int total = 0;
		vector<int> cost;
		forn (i, gv.size()) {
			int to = gv[i];
			if (to == parent)
				continue;
			int t = dfs(to, v, 1);
			total += t;
			cost.pb(t - dfs(to, v));
		}
		sort(all(cost));
		res = total;
		if ((int) cost.size() > 2)
			forn (i, min(2, (int) cost.size()))
				res -= cost[int(cost.size()) - 1 - i];
	}
	return res;
}

int main() {
	int tests;
	scanf("%d", &tests);
	for1 (it, tests) {
		scanf("%d", &n);
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			g[x].pb(y);
			g[y].pb(x);
		}
		memset(z, -1, sizeof z);
		int ans = INF;
		forn (i, n) {
			//printf("root %d: %d\n", i, dfs(i, n));
			ans = min(ans, dfs(i, n));
		}
		printf("Case #%d: %d\n", it, ans);
		forn (i, n)
			g[i].clear();
	}
  
    return 0;
}
