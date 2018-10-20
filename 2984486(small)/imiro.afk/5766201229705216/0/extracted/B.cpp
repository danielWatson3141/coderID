// afk_returns
#define BISA using namespace std
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

BISA;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<string> vs;

#define REP(i,s,n) for(int (i)=(s), _n = (n);(i)<_n;(i)++)
#define FOR(i,s,n) for(int (i)=(s), _n = (n);(i)<=_n;(i)++)
#define rep(i,n) REP(i,0,n)

#define All(v) (v).begin(), (v).end()
#define Reversed(v) (v).rbegin(), (v).rend()
#define sz(v) (int) v.size()
#define LB(v,x) (lower_bound(All(v),x) - (v).begin())
#define UB(v,x) (upper_bound(All(v),x) - (v).begin())
#define UNIQUE(v) { sort(All(v)); (v).erase( unique(All(v)), (v).end() ); }

#define SQR(a) ((a)*(a))
#define MX(x,y) (x) = max( (x), (y) )
#define MN(x,y) (x) = min( (x), (y) )

#define mp make_pair
#define pb push_back
#define ji first
#define ro second

#define SI ({int __x_; scanf("%d", &__x_); __x_;})
#if defined (__WIN32__)
char getchar_unlocked() { return getchar(); }
#endif

inline void OPEN(string a, bool out = false) {
	freopen(string(a + ".in").c_str(), "r", stdin);
	if(out) freopen(string(a + ".out").c_str(), "w", stdout);
}

inline int getInt() {
	int ret = 0;
	char x = getchar_unlocked();
	while(x == ' ' || x == '\n' || x == '\t') x = getchar_unlocked();
	
	while(x != ' ' && x != '\n' && x != '\t') {
		ret = (ret*10) + x - '0';
		x = getchar_unlocked();
	}
	
	return ret;
}

#ifdef DEBUGGING
#define debug(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define FOPEN(x) 
#else
#define debug(...)
#define FOPEN(x) OPEN(x,1)
#endif

#define EPS 1e-7

const int MAX = 1005;
vi G[MAX];
int child[MAX], next[MAX], parent[MAX];
int del[MAX], dp[MAX][5];

int runps(int, int);
void parsib(int r) {
	parent[r] = -1;
	memset(parent, -1, sizeof parent);
	memset(child, -1, sizeof child);
	memset(next, -1, sizeof next);
	
	del[r] = runps(r,-1)+1;
}

int runps(int v, int p) {
	
	child[v] = -1;
	parent[v] = p;
	
	int ret = 1;
	rep(i, sz(G[v])) if( G[v][i] != p ) {
		if( child[v] == -1 ) {
			child[v] = G[v][i];	
		} else {
			next[ G[v][i] ] = child[v];
			child[v] = G[v][i];	
		}
		ret += runps(G[v][i], v);
	}
	
	del[v] = ret;
	return ret;
}

int f(int v, int c) {
	if(v == -1) {
		return 0;
		switch(c) {
			case 0: // next nya udah abis
				return 0;
			break;
			case 1: break;
				
			case 2:  // jadi root, tapi gak punya child
				return 0;
			break;
		}
	}
	
	int &ret = dp[v][c];
	if(ret != -1) return ret;
	
	if(c == 0) {
		ret = del[v] + f(next[v], 0);
	} else if(c == 1) {
		// coba milih yang ini dulu ajaa
		ret = f(child[v], 2) + f(next[v], 0);
		
		if(next[v] != -1) {
			// coba skip
			ret = min(ret, del[v] + f(next[v], 1));
		}
	} else {
		// pilih yang ini?
		if(next[v] == -1) { // wah berarti ora iso, harus dihapus!
			ret = del[v];
		} else {
			// ada next nih, berarti bisa milih ini atau enggak
			// tapi gimana kalo dia termasuk last two?
			// ora popo, kan nanti di last one kalo emang nextnya -1 ujung2nya kehapus semuaa
			
			// coba ini dulu!
			ret = f(child[v], 2) + f(next[v], 1);
			ret = min(ret, del[v] + f(next[v], 2));
			// yupyup :)	
		}
	}
	
	return ret;
}

int main() {
	int TC = SI;
	FOR(tc,1,TC) {
		printf("Case #%d: ", tc);
		int m = SI;
		FOR(i,1,m) G[i].clear();
		
		
		FOR(z,1,m-1) {
			int a = SI, b = SI;
			G[a].pb(b);
			G[b].pb(a);	
		}
		
		int mini = m-1;
		/*
		parsib(2); puts("\n*p | *c | *n");
		FOR(i,1,m) printf("%d: %2d %2d %2d\n", i, parent[i], child[i], next[i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", f(2,1)); */
		
		FOR(i,1,m) {
			parsib(i);
			memset(dp, -1, sizeof dp);
			mini = min(mini, f(i,1));
		} 
		
		printf("%d\n", mini);
	}
}
