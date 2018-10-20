#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

typedef long long int64 ;
typedef unsigned long long uint64 ;
typedef pair<int, int> pint ;
typedef pair<int64, int64> pint64 ;
typedef vector<int> vint ;

#define px first
#define py second

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define REPD(i, n) for (int i = (n) ; i >= 0 ; i --)
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; i ++)
#define FORD(i, a, b) for (int i = (a) ; i >= (b) ; i --)

#define MUL64(x, y) (((int64) (x)) * ((int64) (y)))
#define MULMOD(x, y, modul) (MUL64(x, y) % modul)
#define MUL(x, y) MULMOD(x, y, modul)
#define ADD(reg, val) { reg += val ; if (reg >= modul) reg -= modul ; }

#define SET(v, val) memset(v, val, sizeof(v)) ;
#define SIZE(v) ((int) (v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) { sort(ALL(v)) ; }
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }

//#define BIG
string PROBLEM = "A" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

int n, L;
int64 f [888], d [888];

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> n >> L ;
    REP(i, n) {
      string flow;
      in >> flow;
      f [i] = 0LL;
      REP(l, L) { f [i] = (f [i] << 1) + (flow [l] - '0');}
    }
    REP(i, n) {
      string device;
      in >> device;
      d [i] = 0LL;
      REP(l, L) { d [i] = (d [i] << 1) + (device [l] - '0');}
    }
    sort(d, d + n);
    int ret = -1;
    REP(xf, n) {
      REP(xd, n) {
        int64 ch = f [xf] ^ d [xd];
        int cur = 0 ; REP(i, L) if (ch & (1LL << i)) cur ++;
        vector<int64> v;
        REP(i, n) v.push_back(f [i] ^ ch);
        SORT(v);

        bool ok = true;
        REP(i, n) if (v [i] != d [i]) { ok = false ; break ; }
        if (ok) { if (ret == -1 || ret > cur) ret = cur;}
      }
    }
    out << "Case #" << test << ": " ;
    if (ret == -1) out << "NOT POSSIBLE" ; else out << ret;
    out << endl;
  }

  in.close() ;
  out.close() ;

  return 0;
}
