
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

#define MAXN 1010
#define INF 100000010

int n;
vector<int> g[MAXN];

inline void input()
{
	scanf("%d", &n);
	REP(i, 1, n) g[i].clear();
	REP(i, 1, n-1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int dp[MAXN], sz[MAXN];

void dfs(int u, int p)
{
	sz[u] = 1;
	dp[u] = 0;
	vector<int> childs;
	FOR(it, g[u]) if(*it != p)
	{
		childs.push_back(*it);
		dfs(*it, u);
		sz[u] += sz[*it];
	}
	if(sz[u] == 1) 
		return ;
	if(SZ(childs) == 1)
	{
		dp[u] = sz[childs[0]];
		return ;
	}
	int mx1 = 0, mx2 = 0;
	FOR(it, childs)
	{
		dp[u] += sz[*it];
		int c = sz[*it] - dp[*it];
		if(c > mx1)
		{
			mx2 = mx1;
			mx1 = c;
		}
		else if(c > mx2) mx2 = c;
	}
	dp[u] -= mx1+mx2;

	childs.clear();
}

inline void solve(int __)
{
	int ans = n;
	REP(i, 1, n)
	{
		fill(dp, dp+1+n, 0);
		fill(sz, sz+1+n, 0);
		dfs(i, -1);
		ans = min(ans, dp[i]);
	}
	printf("Case #%d: %d\n", __, ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	REP(__, 1, t)
	{
		input();
		solve(__);
	}
}
