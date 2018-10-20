#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------
//#define DBG
#define MAXN 170
#define MAXL 50

int N, L;
int ans;
ull a[ MAXN ];
ull b[ MAXN ];
char tmp[MAXN];

void vprint(ull u) {
	forn(i, L) {
		if(((ull)1 << i) & u) {
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}

void readfile(){
	scanf("%d%d", &N, &L);

	forn(i, N) {
		scanf("%s", tmp);
		forn(j, L) {
			a[i] |= (tmp[j] == '1') ? bit(j) : 0;
		}
	}
	forn(i, N) {
		scanf("%s", tmp);
		forn(j, L) {
			b[i] |= (tmp[j] == '1') ? bit(j) : 0;
		}
	}

}

bool match(int idx){
#ifdef DBG
	printf("Match? %d\n", idx);
	forn(i, N) vprint(a[i]);
	forn(i, N) vprint(b[i]);
#endif
	forn(i, N) {
		if((a[i] & bit(idx)) != (b[i] & bit(idx))) {
//			printf("NO %d\n", idx);
			return false;
		}
	}
	return true;
}

void rec(int idx, int f, int cost){
	if(idx == -1) {
		// check
		ans = min(ans, cost);
		return;
	}

	if(cost >= ans) return;

	if(f == 0) {
		if( match(idx) ) {
#ifdef DBG
			printf("%d flip [%d]\n", idx, cost);
			forn(i, N) vprint(a[i]);
			forn(i, N) vprint(b[i]);
#endif
			rec(idx - 1, 0, cost);
			rec(idx - 1, 1, cost);
		}
	}
	else {

		cost++;
		forn(i, N) {
			a[i] ^= bit(idx);
		}
		sort(a, a + N);

		if( match(idx) ) {
#ifdef DBG
			printf("%d flip [%d]\n", idx, cost);
			forn(i, N) vprint(a[i]);
			forn(i, N) vprint(b[i]);
#endif
			rec(idx - 1, 0, cost);
			rec(idx - 1, 1, cost);
		}

		forn(i, N) {
			a[i] ^= bit(idx);
		}
		sort(a, a + N);
	}
}

void solve(){
	sort(a, a + N);
	sort(b, b + N);
#ifdef DBG
	forn(i, N) vprint(a[i]);
	forn(i, N) vprint(b[i]);
#endif
	rec(L - 1, 0, 0);
	rec(L - 1, 1, 0);
}


int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		ans = INT_MAX;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		readfile();

		solve();

		if(ans == INT_MAX) {
			printf("Case #%d: NOT POSSIBLE\n", casenum++);
		} else {
			printf("Case #%d: %d\n", casenum++, ans);
		}


	}
	return 0;
}
