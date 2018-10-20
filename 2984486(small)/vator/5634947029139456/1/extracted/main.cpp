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

long long to_i(const string & s) {
  long long res = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    res *= 2;
    res += (s[i]-'0');
  }
  return res;
}

int ccnt(long long x) {
  int res = 0;
  while (x) {
    res += (int)(x%2);
    x /= 2;
  }
  return res;
}

bool check(const vector<long long> & have, const vector<long long> & need, long long x) {
  vector<long long> h, v = need;
  for (int i = 0; i < (int)have.size(); i++) {
    h.push_back(have[i]^x);
  }
  sort(h.begin(),h.end());
  sort(v.begin(),v.end());
  for (int i = 0; i < (int)h.size(); i++) {
    if (h[i] != v[i]) return false;
  }
  return true;
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n,l;
    vector<long long> have, need;
    cout << "Case #" << tt+1 << ": ";
    cin >> n >> l;
    have.resize(n);
    need.resize(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      have[i] = to_i(s);
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      need[i] = to_i(s);
    }
    if (n%2) {
      long long x = 0;
      for (int i = 0; i < n; i++) {
        x ^= have[i]^need[i];
      }
      if (check(have,need,x)) {
        cout << ccnt(x) << endl;
      } else {
        cout << "NOT POSSIBLE" << endl;
      }
    } else {
      long long ans = 1000000000;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          long long xxx = have[i]^need[j];
          long long x = 0;
          for (int k = 0; k < n; k++) {
            if (k != i) x ^= have[k];
            if (k != j) x ^= need[k];
          }
          if (x == xxx && check(have,need,x)) {
            ans = min(ans,(long long)ccnt(x));
          }
        }
      }
      if (ans != 1000000000) {
        cout << ans << endl;
      } else {
        cout << "NOT POSSIBLE" << endl;
      }
    }
  }
  TIMESTAMP;
  return 0;
}
