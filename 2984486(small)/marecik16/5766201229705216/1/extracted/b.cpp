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

const int MAXN = 1100 ;

VI graf[MAXN] ;
int r[MAXN] ;

LL f(int u, int p) {
	r[u]=1 ;
	LL a1=0, a2=0 ;
	int children=0 ;
	FOREACH(q, graf[u]) {
		if(*q == p) continue ;
		children++ ;
		LL x = f(*q, u) ;
		x = r[*q]-x ;
		r[u] += r[*q] ;
//		cout << *q << " " << u << " - " << x << endl ;
		if(x > a2)  swap(x,a2) ;
		if(a2 > a1) swap(a1,a2) ;
	}
//	cout << u << " " << p << " -- " << s << " " << a1 << " " << a2 << " " << children << endl ;
	if(children<=1) return r[u]-1 ;
	else return (r[u]-1)-a1-a2 ;
}			

void solve() {
	int n, i, a, b ;
	cin >> n ;
	REP(i,n+1) graf[i].clear() ;
	REP(i, n-1) {
		cin >> a >> b ;
		graf[a].PB(b) ;
		graf[b].PB(a) ;
	}
	LL ret=INFLL ;
	for(i=1 ; i<=n ; i++) 
		ret = min(ret, f(i, 0)) ;
	cout << ret << endl ;
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

