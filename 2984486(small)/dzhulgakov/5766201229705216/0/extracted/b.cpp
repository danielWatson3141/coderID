#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024
int n;
VI a[N];

int dfs(int v, int par)
{
	VI ch;
	REP(i,SZ(a[v])) 
	{
		int vv = a[v][i];
		if (vv == par) continue;
		ch.push_back(dfs(vv,v));
	}
	SORT(ch);
	reverse(ALL(ch));
	if (SZ(ch) <= 1) return 1;
	return 1+ch[0]+ch[1];
}

int main(int argc, char **argv)
{
	string FN = "B-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d",&n);
		REP(i,n) a[i].clear();
		REP(i,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			--x,--y;
			a[x].pb(y);
			a[y].pb(x);
		}
		int t = 0;
		REP(root,n)
		{
			t = max(t, dfs(root, -1));
		}
		printf("%d\n",n-t);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}