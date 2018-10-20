#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iterator>
#include <valarray>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <tuple>
#include <initializer_list>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef tuple<int, int> tii;
template<typename T> ostream &operator<<(ostream &os, set<T> const &s);template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp);template<typename T> ostream &operator<<(ostream &os, vector<T> const &v);template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v);template<typename T> ostream &operator<<(ostream &os, set<T> const &s);
template<typename T> ostream &operator<<(ostream &os, set<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp) { if (mp.size() == 0) return os << "{}"; os << "{" << endl; decltype(mp.begin()) iter; for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) { --iter; os << "  {" << iter->first << ", " << iter->second << "}," << endl; ++iter; } --iter; os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, vector<T> const &v) { os << '['; rep(i, v.size()-1) os << v[i] << ", "; if (v.size() > 0) os << v[v.size()-1]; cerr << ']'; return os; }
template<typename T, unsigned N, unsigned Last> struct TuplePrinter { static void print(ostream &os, T const& v) { os << std::get<N>(v) << ", "; TuplePrinter<T, N + 1, Last>::print(os, v); } };
template<typename T, unsigned N> struct TuplePrinter<T, N, N> { static void print(ostream &os, T const &v) { os << std::get<N>(v); } };
template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v) { os << "("; TuplePrinter<tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, v); os << ")"; return os; }
template<typename T> void _dbg(T const &t) { cerr << t << endl; }
template<typename T, typename... Args> void _dbg(T const &t, Args... args) { cerr << t << " "; _dbg(args...); }
template<typename... Args> void __dbg(const char *fn, int l, Args... args) { cerr << "[" << fn << ":" << l << "] "; _dbg(args...); }
#define dbg(...) __dbg(__func__, __LINE__, __VA_ARGS__)

const ll infty = 1223372036854775807;
const double eps = 1e-8;

vector<ll> devices;
vector<ll> outlets;
int N, L;

void printNum(ll n) {
  vector<char> vc;
  rep(i, L) {
    vc.pb('0' + (n % 2));
    n /= 2;
  }
  reverse(all(vc));
  rep(i, L) cerr << vc[i]; cerr << endl;
}

ll str2num(string const &s) {
  ll res = 0;
  rep(i, L) {
    res *= 2;
    res += s[i] - '0';
  }
  return res;
}

int popCnt(vector<ll> const &chk, int bit) {
  int res = 0;
  rep(i, chk.size()) if (chk[i] & ((ll)1 << bit)) ++res;
  return res;
}

bool test(ll flip_so_far, int cur) {
  map<ll, int> a, b;
  rep(i, N) {
    ll num = (devices[i]) & ((1 << (cur + 1)) - 1);
    ++a[num];
  }
  rep(i, N) {
    ll num = (outlets[i] ^ flip_so_far) & ((1 << (cur + 1)) - 1);
    ++b[num];
  }
  //dbg(a);
  //dbg(b);
  return a == b;
}

int ck(ll flip_so_far, int cur) {
  dbg(cur);
  printNum(flip_so_far);
  if (cur == L) return 0;
  ll flip = flip_so_far;
  int dp = popCnt(devices, cur);
  int op = popCnt(outlets, cur);
  dbg("dp", dp, "op", op);
  if (dp != op) {
    if (dp != N - op) {
      return -1;
    } else {
      dbg("needs flipping");
      flip |= ((ll)1 << cur);
      if (!test(flip, cur)) {
        return -1;
      } else {
        return 1 + ck(flip, cur+1);
      }
    }
  } else if (dp == N - op) {
    // cannot determine only from the popCnt at this time
    dbg("cannot determine");
    bool ok_f = test(flip, cur), ok_e = test((flip | ((ll)1 << cur)), cur);
    if (ok_f && ok_e) {
      int n = ck(flip | ((ll)1 << cur), cur+1);
      int m = ck(flip, cur+1);
      if (n >= 0 && m >= 0) return min(n+1, m);
      else if (n < 0) return m;
      else return n + 1;
    } else if (ok_f) {
      return ck(flip, cur+1);
    } else if (ok_e) {
      int n = ck(flip | ((ll)1 << cur), cur+1);
      if (n < 0) return -1;
      else return n + 1;
    } else {
      return -1;
    }
  } else {
    dbg("not to flip");
    if (!test(flip, cur)) {
      return -1;
    } else {
      return ck(flip, cur+1);
    }
  }
}

void solve() {
  cin >> N >> L;
  devices.clear(); outlets.clear();
  rep(i, N) {
    string s;
    cin >> s;
    devices.pb(str2num(s));
  }
  rep(i, N) {
    string s;
    cin >> s;
    outlets.pb(str2num(s));
  }
  const int infty = 99999;
  int ans = infty;
  rep(i, (1 << (L+1)) - 1) {
    if (test(i, L)) {
      ans = min(ans, __builtin_popcount(i));
    }
  }
  if (ans == infty) {
    cout << "NOT POSSIBLE";
  } else {
    cout << ans;
  }
}

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  int TT;
  cin >> TT;
  rep(I, TT) {
    cout << "Case #" << I+1 << ": "; solve(); cout << endl;
    //printf("Case #%d: %.10f\n", I+1, solve());
    //cout << "Case #" << I+1 << ": "; solve(); cout << endl;
  }
  return 0;
}
