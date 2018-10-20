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

int bitcount(long k) {
  if (k < 0) k = -k;
  int s = 0;
  while (k) s += k&1, k >>= 1;
  return s;
}

void solve(int casenum) {
  dprintf("==================================================% 3d\n", casenum);

  int N, L; cin >> N >> L;
  vector<string> outlets(N), devices(N);
  Loop(i, N) { cin >> outlets[i]; }
  Loop(i, N) { cin >> devices[i]; }
  sort(All(devices));

  vector<char> flip(256); flip['0'] = '1'; flip['1'] = '0';
  int best = L+1;
  for (long i = 0; i < (1<<L); ++i) {
    vector<string> oo = outlets;
    for (long k = i, l = 0; k != 0; k >>= 1, l++) {
      if (k&1) {
        Loop(j, N) {
          assert(l < L);
          oo[j][l] = oo[j][l] == '1' ? '0' : '1';
        }
      }
    }
    sort(All(oo));
    if (oo == devices) {
      best = min(best, bitcount(i));
    }
  }

  if (best == L+1) {
    printf("Case #%d: NOT POSSIBLE\n", casenum);
  } else {
    printf("Case #%d: %d\n", casenum, best);
  }
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
// compile-command: "g++ -Wall -g -o A A.cc"
// End:
