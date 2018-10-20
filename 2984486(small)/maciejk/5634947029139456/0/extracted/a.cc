#include<cstdio>
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

LL val(string u) {
	LL x = 0;
	FORE(it, u) { x *= 2; x += (*it - '0');}
		return x;
}

int bitow(LL a) {
	int s = 0;
	fup(i, 0, 50) if (a & (1LL << i)) s++;
	return s;
}

int main(){
	int cas;
	cin >> cas;
	fup(c, 1, cas) {
vector<LL> a, b;
		int n, l;
		cin >> n >> l;
		fup(i, 1, n) { string x; cin >> x; a.PB(val(x)); }
		fup(i, 1, n) { string x; cin >> x; b.PB(val(x)); }
		sort(ALL(b));
		int best = INF;
		FORE(it, a) {
			LL uu = *it ^ b[0];
			vector<LL> u;
			FORE(it2, a) {
				u.PB((*it2)^uu);
			}
			sort(ALL(u));
			if (u == b) {
				mini(best, bitow(uu));
			}

		}

		printf("Case #%d: ", c);
		if (best == INF) printf("NOT POSSIBLE\n");
		else printf("%d\n", best);


	}

    return 0;
}

