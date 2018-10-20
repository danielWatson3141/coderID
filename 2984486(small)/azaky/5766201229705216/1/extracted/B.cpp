#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 1111
vector<int> adj[MAXN];
int nnode[MAXN], n;

int calc_nnode(int p, int v) {
	int ret = 1;
	FORIT(it, adj[v]) {
		if (*it == p) continue;
		ret += calc_nnode(v, *it);
	}
	return nnode[v] = ret;
}
int calc(int p, int v) {
	vector<int> temp;
	vector<int> size;
	FORIT(it, adj[v]) {
		if (*it == p) continue;
		temp.PB(calc(v, *it));
		size.PB(nnode[*it] - temp.back());
	}
	//0/2 child: already full
	if (SZ(temp) == 0) {
		//printf("calc(%d) = %d\n", v, 0);
		return 0;
	}
	else if (SZ(temp) == 2) {
		return temp[0] + temp[1];
	}
	//1 child: delete immediately
	else if (SZ(temp) == 1) {
		//printf("calc(%d) = %d\n", v, nnode[v] - 1);
		return nnode[v] - 1;
	}
	//else: choose 2 largest tree
	else {
		int max1 = 0, max2 = 0;
		REP(i, SZ(size)) {
			if (size[i] > size[max1]) max1 = i;
		}
		if (max1 == 0) max2++;
		REP(i, SZ(size)) {
			if (i != max1 && size[i] > size[max2]) max2 = i;
		}
		//printf("calc(%d) = %d\n", v, nnode[v] - 1 - (size[max1] + size[max2]));
		return nnode[v] - 1 - (size[max1] + size[max2]);
	}
}

int main(){
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		REP(i, n) adj[i].clear();
		REP(i, n-1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		int ans = n;
		REP(root, n) {
			//printf("ROOT = %d\n", root);
			//create tree with root = root
			//calculate nnode
			calc_nnode(-1, root);
			MN(ans, calc(-1, root));
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	
	GetTime();
	
	return 0;
}
