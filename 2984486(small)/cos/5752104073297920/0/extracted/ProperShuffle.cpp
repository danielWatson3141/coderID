#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))


struct Random {
  unsigned int x;
  unsigned int y;
  unsigned int z;
  unsigned int w; 
  Random() : x(0x34fb2383), y(0x327328fa), z(0xabd4b54a), w(0xa9dba8d1) {
    for (int i = 0; i < 10000; i++) { Xor128(); }
  }
  Random(int s) : x(0x34fb2383), y(0x327328fa), z(0xabd4b54a), w(s) {
    for (int i = 0; i < 10000; i++) { Xor128(); }
  }
  void Seed(int s) {
    *this = Random(s);
  }
  unsigned int Xor128() {
    unsigned int t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
  }
  int next(int r) { return Xor128() % r; }
  int next(int l, int r) { return next(r - l + 1) + l; }
  ll next(ll r) { return (ll)((((unsigned long long)Xor128() << 32) + (unsigned long long)Xor128()) % r); }
  ll next(ll l, ll r) { return next(r - l + 1) + l; }
  double next(double r) { return (double)Xor128() / 0xffffffff * r; }
  double next(double l, double r) { return next(r - l) + l; }
};
Random rnd;

void init();
void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  init();
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

vector<int> good(int n) {
  vector<int> ret(n);
  REP(k, n) { ret[k] = k; }
  REP(k, n) {
    int p = rnd.next(k, n - 1);
    swap(ret[k], ret[p]);
  }
  return ret;
}

vector<int> bad(int n) {
  vector<int> ret(n);
  REP(k, n) { ret[k] = k; }
  REP(k, n) {
    int p = rnd.next(0, n - 1);
    swap(ret[k], ret[p]);
  }
  return ret;
}

int N = 1000;
double matrix[1000][1000];

void init() {
  int CNT = 1000000;
  MEMSET(matrix, 0);
  REP(i, CNT) {
    vector<int> vs = bad(N);
    REP(j, N) {
      matrix[j][vs[j]]++;
    }
  }
  REP(i, N) {
    REP(j, N) {
      matrix[i][j] /= CNT;
    }
  }
}

void PrintVector(const vector<int> &vs) {
  REP(i, vs.size()) {
    if (i != 0) { putchar(' '); }
    printf("%d", vs[i]);
  }
  puts("");
}

bool is_good(const vector<int> &seq) {
  double good_logp = log(1.0 / N) * (N + 0.2);
  double bad_logp = 0.0;
  REP(i, seq.size()) {
    bad_logp += log(matrix[i][seq[i]]);
  }
  //cout << good_logp << " " << bad_logp << endl;
  return good_logp > bad_logp;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> seq(n);
  REP(i, n) {
    int v;
    scanf("%d", &v);
    seq[i] = v;
  }
  if (is_good(seq)) {
      puts("GOOD");
  } else {
      puts("BAD");
  }

  // {
  //   int g = 0;
  //   int b = 0;
  //   REP(i, 1000) {
  //     int n = N;
  //     vector<int> seq(n);
  //     seq = bad(N);
  //     if (is_good(seq)) {
  //       g++;
  //     } else {
  //       b++;
  //     }
  //   }
  //   cout << g << " " << b << endl;
  //   exit(0);
  // }
}
