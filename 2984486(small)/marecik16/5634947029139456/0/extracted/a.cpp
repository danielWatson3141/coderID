#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
#include <gmpxx.h>			// -lgmpxx -lgmp
using namespace std ;
using namespace __gnu_cxx ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template<class T1, class T2> ostream & operator<<(ostream &s, pair<T1,T2> x) { s << "(" << x.FI << "," << x.SE << ")" ; return s ; }
template<class T> ostream & operator<<(ostream &s, const vector<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1, class T2> ostream & operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

const int MAXN = 200100 ;

vector<LL> read(int n, int l) {
	vector<LL> t ;
	while(n--) {
		LL s=0 ;
		int i ;
		REP(i,l) {
			char x ;
			cin >> x ;
			s = s*2 + (x=='1') ;
		}
		t.PB(s) ;
	}
	return t ;
}

map<vector<LL>, int> produce(const vector<LL> &t, int shift, int b) {
	map<vector<LL>, int> M ;
	for(LL mask=0 ; mask<b ; mask++) {
		vector<LL> tmp ;
		FOREACH(q, t)
			tmp.PB(*q ^ (mask<<shift)) ;
		sort(ALL(tmp)) ;
		if(M.find(tmp) == M.end()) M[tmp] = __builtin_popcount(mask) ;
		else M[tmp] = min(M[tmp], __builtin_popcount(mask)) ;
	}
	return M ;
}

void solve() {
	int n, l, a, i ;
	cin >> n >> l ;
	vector<LL> t  = read(n,l) ;
	vector<LL> t2 = read(n,l) ;
	
	map<vector<LL>, int> M  = produce(t,  0, 1<<(l/2)) ;
	map<vector<LL>, int> M2 = produce(t2, l/2, 1<<(l-l/2)) ;
	
//	cout << endl << M << endl << M2 << endl ;
	
	int ret=INF ;
	FOREACH(q, M) {
		map<vector<LL>, int>::iterator it = M2.find(q->FI) ;
		if(it != M2.end())
			ret = min(ret, q->SE + it->SE) ;
	}
	if(ret == INF) cout << "NOT POSSIBLE" << endl ;
	else cout << ret << endl ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		solve() ;
	}
}

