#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 1001

int n;
int c[MAXN];
int d[MAXN];
vector <int> g[MAXN];

inline void dfs(int v, int pr)
{
	c[v] = 1;
	int t1 = -1, t2 = -1;
	for (int j = 0; j < sz(g[v]); ++j)
	{
		int v2 = g[v][j];
		if (v2 == pr) continue;
		dfs(v2, v);
		c[v] += c[v2];
		if (d[v2] > t1)
		{
			t2 = t1;
			t1 = d[v2];
		}
		else if (d[v2] > t2)
			t2 = d[v2];
	}
	if (t1 == -1 || t2 == -1)
		d[v] = 1;
	else
		d[v] = 1 + t1 + t2;
}

inline void solve()
{
   scanf("%d", &n);
   for (int i = 0; i < n; ++i)
   	g[i].clear();
   for (int i = 1; i < n; ++i)
   {
   	int v1, v2;
   	scanf("%d%d", &v1, &v2);
   	--v1, --v2;
   	g[v1].pb(v2);
   	g[v2].pb(v1);
   }
   int ans = n;
   for (int i = 0; i < n; ++i)
   {
   	for (int j = 0; j < n; ++j)
   		d[j] = c[j] = 0;
		dfs(i, -1);
		ans = min(ans, n - d[i]);
   }
   printf("%d\n", ans);
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}

	return 0;
}
