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
char in[1005];
string tmp[MAX], laptop[MAX], colok[MAX];

int main() {
	int TC = SI;
	FOR(tc,1,TC) {
		printf("Case #%d: ", tc);
		int n, l;
		scanf("%d%d", &n, &l);
		
		rep(i,n) { scanf("%s", in); colok[i] = in; }
		rep(i,n) { scanf("%s", in); laptop[i] = in; }
		
		sort(laptop, laptop+n);
		
		int mini = l+1;
		FOR(bit,0,(1<<l)-1) {
			int cnt = __builtin_popcount(bit);
			debug("OOOOI %d %d\n", cnt, mini);
			if(cnt >= mini) continue;
			
			rep(i,n) tmp[i] = "";
			rep(i,l) {
				if(bit & (1<<i)) {
					rep(j,n) tmp[j] += (colok[j][i] == '1' ? '0' : '1');
				} else {
					rep(j,n) tmp[j] += colok[j][i];	
				}
			}
			
			sort(tmp, tmp+n);
			if(!bit) rep(i,n) { debug("%s\n", tmp[i].c_str()); debug("******************\n"); }
			
			bool ok = 1;
			rep(i,n) if(tmp[i] != laptop[i]) ok = 0;
			if(ok) {
				mini = cnt;	
			}
		}
		
		if(mini <= l) printf("%d\n", mini);
		else puts("NOT POSSIBLE");
	}
}
