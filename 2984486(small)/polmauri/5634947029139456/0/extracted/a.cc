#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> Vll;

const int INF = 1000000000;

ll toll(string s) {
  int n = s.size();
  ll res = 0;
  for (int i = 0; i < n; ++i)
    res |= ll(s[i] - '0')<<i;
  return res;
}

int ones(ll x) {
  int res = 0;
  for (int i = 0; (x>>i) > 0; ++i)
    if ((x>>i)&1) ++res;
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n, m;
    cin >> n >> m;
    Vll v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      v1[i] = toll(s);
    }
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      v2[i] = toll(s);
    }
    sort(v2.begin(), v2.end());
    int res = INF;
    for (int i = 0; i < n; ++i) {
      ll x = v1[0]^v2[i];
      Vll v(n);
      for (int j = 0; j < n; ++j) v[j] = v1[j]^x;
      sort(v.begin(), v.end());
      if (v == v2) res = min(res, ones(x));
    }
    cout << "Case #" << cas << ": ";
    if (res < INF) cout << res << endl;
    else cout << "NOT POSSIBLE" << endl;
  }
}
