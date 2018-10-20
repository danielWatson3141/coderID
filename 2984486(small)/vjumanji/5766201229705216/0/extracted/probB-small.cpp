// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define REP(i,n)        FOR(i,0,n)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
// 

typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> pi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

vi g[15];
int n;
inline void reset () {
	REP(i,15) g[i].clear();
}

pi dfs (int node, int par)
{
	int m = sz(g[node]);
	pi ch[m], x; int c = 0, cn = 1;
	REP(i,m) if (g[node][i] != par) {
		x = dfs(g[node][i], node);
		ch[i] = x;
		c++;
		cn += x.first;
	}
	if (c == 0) return pi(1,0);
	if (c == 1) return pi(cn, cn-1);
	int mind = -1;
	REP(i,m) if (g[node][i] != par)
	{
		FOR(j,i+1,m) if (g[node][j] != par){
			int del = ch[i].second + ch[j].second;
			REP(k,m) if (k != i && k != j && (g[node][k] != par)) del += ch[k].first;
			if (mind == -1 || del < mind) mind = del;
		}
	}
	return pi(cn, mind);
}

int main()
{
	int t = rint();
	REP(T,t)
	{
		n = rint();
		reset();
		REP(i,n-1) {
			int x = rint(), y = rint();
			g[x-1].push_back(y-1);
			g[y-1].push_back(x-1);
		}
		int mind = -1;
		REP(r,n)
		{
			pi x = dfs(r,-1);
			if (mind == -1 || x.second < mind) mind = x.second;
		}
		printf("Case #%d: %d\n", T+1, mind);
	}
	return 0;
}
