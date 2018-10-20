#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
#include <cassert>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

#define Loop(i,n) for (int i = 0; i < (int)(n); ++i)
#define Loopa(i,a,b) for (int i = (a); i <= (b); ++i)
#define Loopd(i,a,b) for (int i = (a); i >= (b); --i)
template <typename T, typename Q, typename S>
bool Bounded(const T& x, const Q& a, const S& b) { return a <= x && x <= b; }
#define db(x) #x << " = " << x
#define pdb(x) printf("#x = %d\n",x);
#define All(x) x.begin(),x.end()
template <typename T> int sz(const T& x) { return x.size(); }
template <typename T, typename Q>
bool mem(const T& s, const Q& x) { return s.find(x) != s.end(); }
typedef long double ld;
typedef long long int ll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef pair<int,int> Pii;
typedef vector<Vi> Adj;
typedef vector<bool> Vb;
#define CI(x) x::const_iterator
#define II(x) x::iterator
#define Car(x) (x).first
#define Cdr(x) (x).second
#define Caar(x) (x).first.first
#define Cdar(x) (x).first.second
#define Cadr(x) (x).second.first
#define Cddr(x) (x).second.second
template <typename T>
struct leq_by {
  const vector<T>* v;
  leq_by(const vector<T>& v) : v(&v) { }
  bool operator()(int i, int j) { return v->at(i) < v->at(j); }
};
template <typename T> void read(vector<T>& x) { Loop(i,sz(x)) cin >> x[i]; }
template <typename T> vector<T> readn(int n) { vector<T> x(n); Loop(i,n) cin >> x[i]; return x; }
template <typename T> void umin(T& x, const T& y) { x = min(x, y); }
template <typename T> void umax(T& x, const T& y) { x = max(x, y); }

bool debug = true;
#define dprintf debug && printf
void show(string s, Vi x) {
  if (!debug) return; cout << s << ": "; Loop(i,sz(x)) cout << " " << x[i]; cout << endl;
}

void solve_correct(int casenum) {
  dprintf("==================================================% 3d\n", casenum);



  printf("Case #%d: \n", casenum);
  fflush(NULL);
}

int bitcount(int x) {
  int s = 0;
  for (; x; x >>= 1) s += x&1;
  return s;
}

int uf_get(vector<int>& uf, int i) {
  if (uf[i] == i) return i;
  int j = uf_get(uf, uf[i]);
  return uf[i] = j;
}

void uf_unite(vector<int>& uf, int i, int j) {
  int x = uf_get(uf, i);
  int y = uf_get(uf, j);
  uf[x] = y;
}

bool isFBT(int N, const vector<Pii>& edges, int which) {
  int M = edges.size();
  // dprintf("FBT: %d, %d\n", N, M);
  // for (Pii e : edges) dprintf("(%d, %d)  ", e.first, e.second);
  // dprintf("\n");

  if (edges.empty()) return bitcount(which) == 1;

  vector<int> conn(N);
  Loop(i, N) conn[i] = i;
  for (Pii x : edges) {
    uf_unite(conn, x.first, x.second);
  }
  vector<int> comp;
  Loop(i, N) {
    if (which & (1<<i)) {
      comp.push_back(uf_get(conn, i));
    }
  }
  sort(All(comp));
  if (comp[0] != comp.back()) return false;

  vector<int> deg(N);
  for (Pii x : edges) {
    deg[x.first]++;
    deg[x.second]++;
  }
  vector<int> dd;
  for (int i = 0; i < N; ++i) {
    if (which & (1<<i)) dd.push_back(deg[i]);
  }
  sort(All(dd));
  bool ans = dd[0] >= 1 && dd.back() <= 3 && count(All(dd), 2) == 1;
  // dprintf("-> %s\n", ans ? "true" : "false");
  return ans;
}

void solve(int casenum) {
  dprintf("==================================================% 3d\n", casenum);

  int N; cin >> N;
  vector<Pii> edges;
  Loop(i, N-1) {
    int x, y; cin >> x >> y;
    edges.push_back({x-1,y-1});
  }
  // for (Pii e : edges) dprintf("(%d, %d)  ", e.first, e.second);
  // dprintf("\n");

  int best = N+1;
  for(int which = 0; which < (1<<N); ++which) {
    vector<Pii> ee;
    for (const Pii& e : edges) {
      if ((which & (1<<e.first)) && (which & (1<<e.second))) {
        ee.push_back(e);
      }
    }
    if (isFBT(N, ee, which)) {
      // dprintf("which: 0x%x\n", which);
      // for (int k = which, s = 0; k; k >>= 1, s++)
      //   if (k&1) dprintf("keep %d.\n", s);
      // for (Pii e : ee) dprintf("(%d, %d)  ", e.first, e.second);
      // dprintf("\n");
      best = min(best, N - bitcount(which));
    }
  }

  if (best == N+1) dprintf("IMPOSSIBLE\n");
  printf("Case #%d: %d\n", casenum, best);
  fflush(NULL);
}

int main(int argc, char** argv) {
  if (getenv("NODEBUG") != NULL) debug = false;
  int T; cin >> T;
  if (getenv("CORRECT") != NULL) {
    Loop(i,T) solve_correct(i+1);
  } else {
    Loop(i,T) solve(i+1);
  }
  return 0;
}

// Local variables:
// compile-command: "g++ -Wall -g -o B B.cc"
// End:
