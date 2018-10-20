#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// good: 245444 249594
// bad: 239957 240144

typedef pair<int, int> P;
typedef vector<P> Vp;
typedef vector<int> Vi;

int inv(const Vi& v) {
  int n = v.size();
  int res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (v[i] > v[j]) ++res;
  return res;
}

int fun(const Vi& v) {
  int n = v.size();
  int res = 0;
  for (int i = 0; i < 360; ++i) {
    res += v[i]*v[i];
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  Vp ord(tcas);
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
//     Vi u = v;
//     reverse(u.begin(), u.end());
    ord[cas - 1] = P(fun(v), cas - 1);
  }
  sort(ord.begin(), ord.end());
  Vi res(tcas);
  for (int i = 0; i < tcas/2; ++i) res[ord[i].second] = 0;
  for (int i = tcas/2; i < tcas; ++i) res[ord[i].second] = 1;
  for (int cas = 1; cas <= tcas; ++cas)
    cout << "Case #" << cas << ": " << (res[cas - 1] ? "GOOD" : "BAD") << endl;
//   for (int i = 0; i < 100; ++i)
//     cerr << rank[i] << " " << rank[tcas - 1 - i] << endl;
//   cerr << "avg: " << sum/double(tcas) << endl;
}
