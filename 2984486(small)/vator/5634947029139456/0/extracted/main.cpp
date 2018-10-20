#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

// TEMPLATE {{{
#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
//#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& m, const T& s) { if (!OJ) cerr << "\E[91m" << s << "\E[0m"; return m; }
C_ merr;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n,l;
    vector<string> have, need;
    int ans = 1000000000;
    cin >> n >> l;
    have.resize(n);
    need.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> have[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> need[i];
    }
    sort(need.begin(),need.end());
    for (int bit = 0; bit < (1<<l); bit++) {
      vector<string> may = have;
      bool ok = true;
      int cnt = 0;
      for (int i = 0; i < l; i++) {
        if (bit & (1<<i)) {
          cnt++;
          for (int j = 0; j < n; j++) {
            may[j][i] = (may[j][i] == '0' ? '1' : '0');
          }
        }
      }
      sort(may.begin(),may.end());
      for (int i = 0; i < n; i++) {
        if (may[i] != need[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = min(ans,cnt);
      }
    }
    cout << "Case #" << tt+1 << ": ";
    if (ans == 1000000000) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
  TIMESTAMP;
  return 0;
}
