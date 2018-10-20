#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef short int sint;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define All(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));

const int N = 1010;
vi za[N];
int n, l;

int dfs(int v, int par) {
	multiset<int, greater<int> > zb;
	FOREACH(p, za[v]) if (*p != par) {
		zb.insert(dfs(*p, v));
	}
	if (zb.size() <= 1) return 1;
	else {
		int gora = *zb.begin();
		zb.erase(zb.begin());
		gora += *zb.begin();
		zb.clear();
		//printf("res for: %d, %d   = %d\n", v, par, gora + 1);
		return gora + 1;
	}
}

void solve() {
	scanf("%d", &n);
	REP(i, n-1) {
		wez2(a, b)
		za[a].PB(b);
		za[b].PB(a);
	}
	int najw = 1;
	FOR(i, 1, n) {
		//printf("starting in : %d\n", i);
		int res = dfs(i, -1);
		//printf("  --- res: %d\n", res);
		if (res > najw) najw = res;
	}
	printf("%d\n", n - najw);
	FOR(i, 1, n) za[i].clear();
}

int main() {
	wez(t);
	REP(i, t) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}