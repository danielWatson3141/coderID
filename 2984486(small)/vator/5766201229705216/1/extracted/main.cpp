#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
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

vector<int> G[1111];

int delp[1111][1111];
int rootp[1111][1111];

int del(int v, int p) {
  int& res = delp[v][p];
  if (res != -1) return res;
  res = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (vv == p) continue;
    res += del(vv,v);
  }
  return res;
}

int root(int v, int p) {
  int& res = rootp[v][p];
  if (res != -1) return res;
  if (G[v].size() == 0 || (G[v].size() == 1 && G[v][0] == p)) return res = 0;
  if (G[v].size() == 1) return res = del(G[v][0],v);
  if (G[v].size() == 2) {
    if (G[v][0] == p) return res = del(G[v][1],v);
    if (G[v][1] == p) return res = del(G[v][0],v);
    return root(G[v][0],v) + root(G[v][1],v);
  }
  set<pair<int,int> > S;
  res = 0;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (vv == p) continue;
    res += del(vv,v);
    S.insert(make_pair(root(vv,v)-del(vv,v),vv));
  }
  res += S.begin()->first;
  S.erase(S.begin());
  res += S.begin()->first;
  return res;
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
    for (int i = 0; i < 1111; i++) { G[i].clear(); }
    memset(delp,255,sizeof(delp));
    memset(rootp,255,sizeof(rootp));
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int x,y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if (n == 1) {
      ans = 0;
    }
    if (n == 2) {
      ans = 1;
    }
    for (int i = 1; i <= n; i++) {
      ans = min(ans,root(i,-1));
    }
    cout << "Case #" << tt+1 << ": ";
    cout << ans << endl;
  }
  TIMESTAMP;
  return 0;
}
