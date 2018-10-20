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

vector<int> good(int n) {
  vector<int> res;
  rep(i,0,n) res.pb(i);
  for (int i = 0; i < n; ++i)
    swap(res[i], res[(rand() % (n-i)) + i]);
   return res;
}
vector<int> bad(int n) {
  vector<int> res;
  rep(i,0,n) res.pb(i);
  for (int i = 0; i < n; ++i)
    swap(res[i], res[rand() % n]);
   return res;
}

int tree[1111];
void update_idx(int i, int val, int n) { // v[i] += val
  i++;
  for (; i <= n; i += i & -i) tree[i] += val;
}
int read_prefix(int i) { // get sum v[1..i]
  i++;
  int sum = 0;
  for (; i > 0; i -= i & -i) sum += tree[i];
  return sum;
}

ll inv(const vector<int>& p) {
  clr(tree,0);
  int n = p.size();
  ll ans = 0;
  for (int i = n-1; i >= 0; --i) {
    ans += read_prefix(p[i]-1);
    update_idx(p[i], 1, n);
  }
  return ans;
}
ll inv_brute(vector<int> p) {
  ll res = 0;
  int n = p.size();
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      res += p[i] > p[j];
  return res;
}

ll f(int n, bool dogood) {
  vector<int> x = dogood ? good(n) : bad(n);
  //assert(inv(x) == inv_brute(x));
  return inv(x);
}

double dp[1111][2];
double exp(int n, bool dogood) {
  double& res = dp[n][dogood];
  if(res==res) return res;
  res=0;
  int T = 2000000/n;
  rep(_,0,T) res += f(n,dogood);
  return res / T;
}

#if 0
void run() {
  srand(time(NULL));
  cout << 20 << endl;
  for (int i = 0; i < 10; ++i) {
    int n = 1000;
    vector<int> p = good(n);
    cout << n << endl;
    for (int i = 0; i < n; ++i) cout << p[i] << " ";cout << endl;
  }
  for (int i = 0; i < 10; ++i) {
    int n = 1000;
    vector<int> p = bad(n);
    cout << n << endl;
    for (int i = 0; i < n; ++i) cout << p[i] << " ";cout << endl;
  }
}
#endif
#if 1
void run() {
  srand(time(NULL));
  clr(dp,-1);
  int T; cin >> T;
  double a = exp(1000,1);
  double b = exp(1000,0);
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    int n; cin >> n;
    vector<int> p;
    rep(i,0,n) {
      int x; cin >> x;
      p.pb(x);
    }
    double c = inv(p);
    //cout << c<< endl;
    cout << ((abs(c-a) < abs(c-b))?"GOOD":"BAD") << endl;
  }
  //vector<int> test;
  //test.pb(0);
  //test.pb(1);
  //test.pb(2);
  //cout << solve_exact(test) << endl;
  //test.clear();
  //test.pb(2);
  //test.pb(0);
  //test.pb(1);
  //cout << solve_exact(test) << endl;
}
#endif
