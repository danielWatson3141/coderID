#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cstring>
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

vector<int> G[111];
bool uu[111];

void dfs(int v) {
  uu[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (!uu[vv]) dfs(vv);
  }
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    int ans = 1000000000;
    vector<pair<int,int> > E;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int x,y;
      cin >> x >> y;
      E.push_back(make_pair(x,y));
    }
    if (n == 1) {
      ans = 0;
    }
    if (n == 2) {
      ans = 1;
    }
    for (int bit = 0; bit < (1<<n)-1; bit++) {
      int cnt = 0;
      bool u[111] = {};
      bool ok = true;
      int two = 0, three = 0, zero = 0;
      for (int i = 0; i < 111; i++) { G[i].clear(); }
      memset(uu,0,sizeof(uu));
      for (int i = 0; i < n; i++) {
        if (bit & (1<<i)) {
          cnt++;
          u[i+1] = 1;
        }
      }
      for (int i = 0; i < n-1; i++) {
        int x = E[i].first, y = E[i].second;
        if (u[x] || u[y]) continue;
        G[x].push_back(y);
        G[y].push_back(x);
      }
      for (int i = 1; i <= n; i++) {
        if (u[i]) continue;
        if (G[i].size() == 1) zero++;
        if (G[i].size() == 2) two++;
        if (G[i].size() == 3) three++;
      }
      if (two != 1 || two+three+zero != n-cnt) {
        ok = false;
      }
      if (ok) {
        for (int i = 1; i <= n; i++) {
          if (u[i]) continue;
          dfs(i);
          break;
        }
        for (int i = 1; i <= n; i++) {
          if (u[i]) continue;
          if (!uu[i]) ok = false;
        }
      }
      if (ok) {
        ans = min(ans,cnt);
      }
    }
    cout << "Case #" << tt+1 << ": ";
    cout << ans << endl;
  }
  TIMESTAMP;
  return 0;
}
