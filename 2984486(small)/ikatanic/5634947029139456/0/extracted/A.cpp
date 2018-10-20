#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int inf = 1e9;

string a[200], b[200];
char buff[200];

int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    int n, l;
    scanf("%d %d", &n, &l);
    REP(i, n) {
      scanf("%s", buff);
      a[i] = buff;
    }
    REP(i, n) {
      scanf("%s", buff);
      b[i] = buff;
    }

    sort(a, a + n);
    sort(b, b + n);

    int ans = inf;
    REP(i, n) {
      static string c[200];
      int cnt = 0;
      REP(k, l)
        if (a[0][k] != b[i][k]) cnt++;

      REP(j, n) {
        c[j] = a[j];
        REP(k, l)
          if (a[0][k] != b[i][k]) c[j][k] = (c[j][k] == '1' ? '0' : '1');
      }
      sort(c, c + n);
      
      REP(j, n)
        if (c[j] != b[j]) cnt = inf;
      ans = min(ans, cnt);
    }

    printf("Case #%d: ", tp);
    if (ans >= inf) printf("NOT POSSIBLE\n"); else
      printf("%d\n", ans);
  }
  return 0;
}
