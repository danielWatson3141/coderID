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

ll outlet[155], device[155];
set<ll> dev;
int N, L;
ll read() {
  ll x = 0;
  rep(i,0,L) {
    char c; cin >> c;
    if (c=='1') x |= 1LL<<i;
  }
  return x;
}

bool check(ll c) {
  set<ll> out;
  rep(i,0,N) out.insert(outlet[i] ^ c);
  return out == dev;
}

void run() {
  int T; cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> N >> L;
    dev.clear();
    rep(i,0,N) outlet[i] = read();
    rep(i,0,N) device[i] = read(), dev.insert(device[i]);
    int ans = 1<<30;
    rep(i,0,N) {
      ll x = device[i] ^ outlet[0];
      if (check(x)) ans = min(ans, __builtin_popcountll(x));
    }
    if (check(0)) ans = 0;
    if (ans == 1<<30) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
  }
}
