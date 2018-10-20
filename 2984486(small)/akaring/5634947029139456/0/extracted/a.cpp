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

int n, l;
VI input() {
  VI a;
  REP (i, n) {
    char s[16];
    scanf("%s", s);
    int val = 0;
    for (int j = 0; s[j]; ++j) {
      val = (val << 1) + (s[j] - '0');
    }
    a.PB(val);
  }
  return a;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    scanf("%d%d", &n, &l);
    VI a = input();
    VI b = input();
    sort(ALL(b));
    int ans = l + 1;
    REP (mask, 1 << l) {
      VI c = a;
      REP (i, n) {
        c[i] ^= mask;
      }
      sort(ALL(c));
      if (c == b) {
        checkMin(ans, __builtin_popcount(mask));
      }
    }
    printf("Case #%d: ", index);
    if (ans > l) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
