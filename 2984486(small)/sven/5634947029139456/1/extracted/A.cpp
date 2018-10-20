#pragma GCC diagnostic ignored "-Wwrite-strings"
//#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include "stdarg.h"
#include <bitset> //http://stackoverflow.com/questions/4048749/bitwise-operations-on-vectorbool //http://www.drdobbs.com/the-standard-librarian-bitsets-and-bit-v/184401382
#include <numeric> //http://stackoverflow.com/questions/6743003/how-calculate-sum-of-values-in-stdvectorint
#include <iomanip> // cout << fixed << setprecision(8);

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<PII> VPII;
typedef vector<PDD> VPDD;
typedef vector <VI> VVI;
typedef vector<VD> VVD;
typedef vector <string> VS;
typedef vector <bool> VB;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

#define CE cout << endl;
#define CL cout << "--------------------------------------" << endl;
#define ASF assert(false);
#define V vector
#define DQ deque
#define PQ priority_queue

template <class T, class U>
ostream & operator << (ostream &out, const pair<T,U> &A) {
  out << A.ST << "_" << A.ND; return out;
}

template<template<typename, typename> class ContainerT, typename ValueT> //http://cboard.cprogramming.com/cplusplus-programming/145441-stl-container-template-argument.html
ostream & operator << (ostream &out, const ContainerT<ValueT, std::allocator<ValueT> > &A) {
  FORE(i, A) out << *i << " "; return out;
}

template<template<typename, typename> class ContainerT, typename ValueT, typename ValueU> 
ostream & operator << (ostream &out, const ContainerT<pair<ValueT, ValueU>, std::allocator<pair<ValueT, ValueU> > > &A) {
  FORE(i, A) out << *i << " "; return out;
}


#define VA_NARGS_IMPL(_1,_2,_3,_4,_5,_6,_7,_8,N,...) N
#define VA_NARGS(...) VA_NARGS_IMPL(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1)

#define P_(a)                       #a << ": " << a
#define P__(a)                      " | " << P_(a)
#define P1(a)                       cout << P_(a) << endl;
#define P2(a, b)                    cout << P_(a) << P__(b) << endl;
#define P3(a, b, c)                 cout << P_(a) << P__(b) << P__(c) << endl;
#define P4(a, b, c, d)              cout << P_(a) << P__(b) << P__(c) << P__(d) << endl;
#define P5(a, b, c, d, e)           cout << P_(a) << P__(b) << P__(c) << P__(d) << P__(e) << endl;
#define P6(a, b, c, d, e, f)        cout << P_(a) << P__(b) << P__(c) << P__(d) << P__(e) << P__(f) << endl;
#define P7(a, b, c, d, e, f, g)     cout << P_(a) << P__(b) << P__(c) << P__(d) << P__(e) << P__(f) << P__(g) << endl;
#define P8(a, b, c, d, e, f, g, h)  cout << P_(a) << P__(b) << P__(c) << P__(d) << P__(e) << P__(f) << P__(g) << P__(h) << endl;

#define P_IMPL2(count, ...) P ## count (__VA_ARGS__)
#define P_IMPL(count, ...) P_IMPL2(count, __VA_ARGS__) 
#define P(...) P_IMPL(VA_NARGS(__VA_ARGS__), __VA_ARGS__)

template<class T> void mini(T &a, const T &b) {if(b<a)a=b;}
template<class T> void maxi(T &a, const T &b) {if(b>a)a=b;}


int N, L;
int cur;
VS A,B;

bool confirm(VB chk) {
  VS A_(ALL(A));
  FORE(i, A_) REP(j, L) if(chk[j]) ((*i)[j] == '0') ? (*i)[j] = '1' : (*i)[j] = '0';
  set <string> C;
  FORE(i, A_) C.insert(*i);
  FORE(i, B) if(C.find(*i) == C.end()) return false;
  return true;
}

void solve() {
  cur = INT_MAX;
  cin >> N >> L;
  A = VS(N), B = VS(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) REP(j, N) {
    VB flip(L, false);
    REP(k, L) if(A[i][k] != B[j][k]) flip[k] = true;
    int sum = accumulate(ALL(flip), 0);
    if(sum <= cur)
      if(confirm(flip))
        mini(cur, sum);
  }
  if(cur != INT_MAX) cout << cur;
  else cout << "NOT POSSIBLE";
  return;
}

int main() {
  int T; cin >> T; REP(i, T) {
    cout << "Case #" << i+1 << ": "; 
    solve();
    CE
  }
  return 0;
}















