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

#define BIG
string PROBLEM = "B" ;

#ifdef BIG
ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif

#define MAXN 1888
#define MAXD 12

int n, dp [MAXN] [MAXN], q [MAXN] [MAXN], inf = 1000888;
vector<int> e [MAXN], c [MAXN];

int g(int u, int pu) {
  int &ret = q [u] [pu];
  if (ret != -1) return ret;
  ret = 1;
  REP(ie, SIZE(e [u])) { int v = e [u] [ie] ; if (v != pu) ret += g(v, u) ; }
  return ret;
}
int f(int u, int pu) {
  int &ret = dp [u] [pu];
  if (ret != -1) return ret;
  ret = inf;
  if (SIZE(e [u]) == 1 && pu < n) ret = 0;
  int total = 0, tmp [SIZE(e [u]) + 1];
  REP(ie, SIZE(e [u])) {
    int v = e [u] [ie];
    tmp [ie] = 0;
    if (v != pu) {
      tmp [ie] = 1 ;
      REP(xe, SIZE(e [v])) {
        int w = e [v] [xe];
        if (w != u) tmp [ie] += g(w, v) ;
      }
    }
    total += tmp [ie];
  }
  ret = min(ret, total);
  REP(ie1, SIZE(e [u])) {
    int v1 = e [u] [ie1];
    if (v1 != pu) {
      FOR(ie2, ie1 + 1, SIZE(e [u])) {
        int v2 = e [u] [ie2];
        if (v2 != pu) {
          int cur = f(v1, u) + f(v2, u) + total - tmp [ie1] - tmp [ie2];
          ret = min(ret, cur);
        }
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false) ;

  int numTests ;
  in >> numTests ;
  FOR(test, 1, numTests + 1) {
    in >> n;
    REP(u, n) e [u].clear();
    REP(i, n - 1) {
      int u, v ;
      in >> u >> v ; u --; v--;
      e [u].push_back(v) ; e [v].push_back(u);
    }
    int ret = inf;
    REP(u, n + 1) REP(v, n + 1) { dp [u] [v] = -1; q [u] [v] = -1 ; }
    REP(u, n) {
      int tmp = f(u, n);
      ret = min(ret, tmp);
    }
    cout << test << ":" << ret << endl;
    out << "Case #" << test << ": " << ret << endl ;
  }

  in.close() ;
  out.close() ;

  return 0;
}
