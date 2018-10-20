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

const int N = 1000;
const int TT = 1000000;
vector<Vi> counts(N, Vi(N));

void solve(int casenum) {
  dprintf("==================================================% 3d\n", casenum);

  int _N; cin >> _N;
  Vi p(N); Loop(i, N) cin >> p[i];

  double lr = 1.0;
  Loop(i, N) {
    lr *= (counts[p[i]][i] / (double)TT) / (1.0 / N);
  }

  printf("Case #%d: %s\n", casenum, lr > 1.0 ? "BAD" : "GOOD");
  fflush(NULL);
}

void test1() {
  Vi p(N);

  for (int t = 0; t <= TT; ++t) {
    Loop(i,N) p[i] = i;
    Loop(i, N) {
      int j = rand()%N;
      swap(p[i], p[j]);
    }
    Loop(i, N) counts[p[i]][i]++;
  }
}

int main(int argc, char** argv) {
  if (getenv("PREPARE") != NULL) {
    Vi p(N);
    int M = 10;
    printf("%d\n", 2*M);
    for (int t = 0; t <= M; ++t) {
      Loop(i,N) p[i] = i;
      Loop(i, N) {
        int j = i + rand()%(N-i);
        swap(p[i], p[j]);
      }
      printf("%d\n", N);
      Loop(i, N) printf("%s%d", i > 0 ? " " : "", p[i]);
      printf("\n");
    }
    for (int t = 0; t <= M; ++t) {
      Loop(i,N) p[i] = i;
      Loop(i, N) {
        int j = rand()%N;
        swap(p[i], p[j]);
      }
      printf("%d\n", N);
      Loop(i, N) printf("%s%d", i > 0 ? " " : "", p[i]);
      printf("\n");
    }
    exit(0);
  }

  test1();

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
// compile-command: "g++ -Wall -g -o C C.cc"
// End:
