// written by Amirmohsen Ahanchi //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include <complex>
#include <cassert>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define dbg(x) "#" << #x << ": " << x 
#define spc << " " <<

using namespace std;

//#define cin fin
//#define cout fout

typedef long long LL;
typedef pair <int, int> PII; 

const int maxN = 1000 + 5;
const int INF = (1<<28);

vector <int> adj[maxN];
int d[maxN], cnt[maxN];

void dfs(int x, int p)
{
	int m1 = INF, m2 = INF;
	cnt[x] = 1;
	int deg = Size(adj[x]);
	for (int i = 0; i < Size(adj[x]); i++)
	{
		int u = adj[x][i];
		if (u == p) {deg--; continue;}
		dfs(u, x);
		if (m1 > d[u]-cnt[u]) m2 = m1, m1 = d[u]-cnt[u];
		else if (m2 > d[u]-cnt[u]) m2 = d[u]-cnt[u];
		cnt[x] += cnt[u];
	}
	d[x] = 0;
//	cerr << x << " " << m1 << " " << m2 << " " << deg <<  endl;
	if (deg == 1)
		d[x] = cnt[x]-1;
	else if (deg >= 2)
		d[x] = cnt[x] + m1+m2-1;
		
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < n-1; i++)
		{
			int u, v; cin >> u >> v; u--; v--;
			adj[u].pb(v); adj[v].pb(u);
		}
		int ans = n-1;
//		dfs(0, -1);
//		cerr << d[0] << endl;
//		return 0;
		for (int i = 0; i < n; i++)
		{
			dfs(i, -1);
//			if (i == 2)
	//			cerr << d[i] << endl;
			ans = min(ans, d[i]);
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
	return 0;
}

