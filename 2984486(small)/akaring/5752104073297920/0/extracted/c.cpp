#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

bool reply[128];
int n;
int perm[128][1024];

int count_inv(const VI &a) {
  int r = 0;
  REP (i, SZ(a) / 2) {
    for (int j = i + 1; j < SZ(a) / 2; ++j) {
      r += a[i] > a[j];
    }
  }
  return r;
}

VI bad_gen(int n) {
  VI a(n);
  REP (i, n) a[i] = i;
  REP (i, n) {
    swap(a[i], a[rand() % n]);
  }
  return a;
}

void gao(int n) {
  double x = 0, y = 0;
  VI a(n);
  REP (i, n) a[i] = i;
  for (int i = n - 1; i > 0; --i) {
    swap(a[rand() % (i + 1)], a[i]);
  }
  REP (i, 1000) {
    for (int i = n - 1; i > 0; --i) {
      swap(a[rand() % (i + 1)], a[i]);
    }
    x += count_inv(a);
    y += count_inv(bad_gen(n));
  }
  printf("%f %f\n", x, y);
}

double calc(const VI &perm) {
  double o[10] = {};
  REP (i, 10) {
    for (int j = 100 * i; j < 100 * i + 100; ++j) {
      o[i] += perm[j];
    }
  }
  double s = accumulate(o, o + 10, 0.0) * 0.1;
  double r = 0;
  REP (i, 10) {
    r += (s - o[i]) * (s - o[i]);
  }
  return r;
}

int main() {
  /*
  srand(time(0));
  gao(100);
  return 0;
  */

  pair<double, int> ps[128];

  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    scanf("%d", &n);
    VI perm(n);
    REP (i, n) {
      scanf("%d", &perm[i]);
    }
    ps[index] = MP(calc(perm), index);
  }
  sort(ps + 1, ps + n_case + 1);
  for (int i = 1; i <= n_case; ++i) {
    reply[ps[i].Y] = i <= n_case / 2 ? false : true;
  }
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %s\n", index, reply[index] ? "GOOD" : "BAD");
  }
  return 0;
}
