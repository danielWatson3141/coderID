#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 1000 + 10;

int dp[MAXN];
vector<int> adj[MAXN];

void dfs(int x, int par)
{
	vector<int> tmp;

	dp[x] = 1;
	for (int i = 0; i < SZ(adj[x]); i ++)
	{
		int v = adj[x][i];
		if (v == par) continue;
		dfs(v, x);
		tmp.pb(dp[v]);
	}

	sort(ALL(tmp), greater<int>());
	if (SZ(tmp) > 1) dp[x] += tmp[0] + tmp[1];
}

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int o = 1; o <= tc; o ++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i ++) adj[i].clear();
		for (int i = 1; i < n; i ++)
		{
			int x, y;
			cin >> x >> y; x --, y --;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		int ans = 1e9;
		for (int i = 0; i < n; i ++)
		{
			CLR(dp, 0);
			dfs(i, -1);
			ans = min(ans, n - dp[i]);
		}
		
		cout << "Case #" << o << ": ";
		cout << ans << endl;
	}
	return 0;
}

