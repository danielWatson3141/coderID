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

#define MAXN 1000
ll init[MAXN], goal[MAXN], temp[MAXN];
int n, l;

ll val(string s) {
	ll ret = 0;
	REP(i, s.length()) {
		ret = 2LL * ret + (ll)(s[i] - '0');
	}
	return ret;
}

int main(){
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		string s;
		scanf("%d%d", &n, &l);
		REP(i, n) {
			cin >> s;
			init[i] = val(s);
		}
		REP(i, n) {
			cin >> s;
			goal[i] = val(s);
		}
		sort(goal, goal + n);
		bool possible = false;
		int ans = l;
		REP(i, n) {
			ll key = goal[0] ^ init[i];
			REP(j, n) {
				temp[j] = init[j] ^ key;
			}
			sort(temp, temp + n);
			bool match = true;
			REP(j, n) {
				if (temp[j] != goal[j]) match = false;
			}
			if (match) {
				int tans = 0;
				REP(i, l) {
					if (key & (1LL << (ll)i)) tans++;
				}
				possible = true;
				if (tans < ans) ans = tans;
			}
		}
		if (possible) {
			printf("Case #%d: %d\n", itc, ans);
		}
		else {
			printf("Case #%d: NOT POSSIBLE\n", itc);
		}
	}
	
	return 0;
}
