#include <bits/stdc++.h>
#include <cassert>
using namespace std;
typedef long long ll; typedef long double ld;
#define rep(i,s,e) for (int i=(s),__ee=(e);i<__ee;++i)
#define all(x) begin(x),end(x)
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) ((x).find(y)!=end(x))
#define pb push_back
#define Tu tuple
#define mk make_pair
#define mkt make_tuple
#define fst first
#define snd second
#define _1 get<0>
#define _2 get<1>
#define _3 get<2>
#define _4 get<3>
#define sz(x) ((int)(x).size())
#define tn typename
template <tn T> T read() { T x; cin >> x; return x; }
int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
void run();
int main() {
#ifdef LOCAL
#  define dbg(s, ...) printf(s "\n", __VA_ARGS__)
#else
#  define endl "\n"
#  define dbg(s,...)
#  define FILE "x"
  //freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
  ios::sync_with_stdio(0);
#endif
  cout << fixed << setprecision(16);
  run();
}

int n;
int f[1111], g[1111];
vector<int> adj[1111];
void dfs(int x, int par=-1) {
  g[x] = 1;
  int cnt = 0;
  for (int y: adj[x]) if (y != par) {
    dfs(y, x);
    g[x] += g[y];
    cnt++;
  }
  int a=1<<30, b = 1<<30, ai=-1, bi=-1;
  f[x] = g[x]-1;
  assert(f[x] >= 0);
  if (cnt >= 2) {
    vector<pair<int,int>> res;
    for (int y: adj[x]) if (y != par) {
      res.pb(mk(f[y]-g[y],y));
      if (f[y] <= a) {
        b = a;
        bi = ai;
        a = f[y];
        ai = y;
      } else if (f[y] < b) {
        b = f[y];
        bi = y;
      }
    }
    assert(res.size()>=2);
    sort(all(res));
    assert(ai>=0);
    assert(bi>=0);
    assert(f[ai]==a);
    assert(f[bi]==b);
    //f[x] = min(f[x], g[x] - 1 - g[ai] - g[bi] + a + b);
    f[x] = min(f[x], g[x] - 1 + res[0].fst + res[1].fst);
    assert(f[x] >= 0);
  }
}

void run() {
  int T; cin >> T;
  int tc=1;
  while(T--) {
    cout << "Case #" << tc << ": ";
    cin >> n;
    rep(i,1,n+1) adj[i].clear();
    rep(i,0,n-1) {
      int a, b; cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
      dfs(i);
      ans = min(ans, f[i]);
    }
    assert(ans <= n-1);
    cout << ans << endl;
    ++tc;
  }
}
