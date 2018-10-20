#include <bits/stdc++.h>

using namespace std;

int n, l;
string out[11], work[11];
string dev[11];

int main() {
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("A-small-attempt0.out", "wt", stdout);
  int t; cin >> t;
  for(int tst = 1; tst <= t; ++tst) {
    cin >> n >> l;
    for(int i = 0; i < n; ++i)
      cin >> out[i];
    for(int i = 0; i < n; ++i)
      cin >> dev[i];
    sort(dev, dev + n);
    int ans = -1;
    for(int msk = 0; msk < (1 << l); ++msk) {
      for(int i = 0; i < n; ++i) {
        work[i] = out[i];
        for(int j = 0; j < l; ++j) {
          if((msk >> j) & 1)
            work[i][j] = '1' + '0' - work[i][j];
        }
      }
      sort(work, work + n);
      bool valid = 1;
      for(int i = 0; i < n; ++i) {
        if(work[i] != dev[i]) valid = 0;
      }
      if(valid) {
        if(ans == -1 || ans > __builtin_popcount(msk))
          ans = __builtin_popcount(msk);
      }
    }
    printf("Case #%d: ", tst);
    if(ans == -1) puts("NOT POSSIBLE");
    else printf("%d\n", ans);
  }
  return 0;
}
