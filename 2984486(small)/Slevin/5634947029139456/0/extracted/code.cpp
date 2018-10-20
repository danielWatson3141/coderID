#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>

#include <memory.h>
using namespace std;

#pragma comment(linker, ”/STACK:108777216“)

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  int res; scanf("%d", &res); return res;
}

class timer {
public:
  timer() : t_(clock()) {}
  void start() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T; cin >> T;

  for (int cs = 0; cs < T; ++cs) {
    int n, l; cin >> n >> l;
    vector<string> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n; ++i) cin >> vb[i];
    sort(all(va));
    sort(all(vb));

    int sol = 1000000;
    for (int j = 0; j < n; ++j) {
      int ssol = 0;
      for (int k = 0; k < l; ++k) {
        if (va[0][k] != vb[j][k]) {
          ++ssol;
        }
      }
      vector<string> vs;
      for (int k = 0; k < n; ++k) {
        string tmp = va[k];
        for (int t = 0; t < l; ++t) {
          tmp[t] = (va[0][t] == vb[j][t]) ^ (tmp[t] == '1') ? '0' : '1';
        }
        vs.push_back(tmp);
      }
      sort(all(vs));
      for (int k = 0; k < n; ++k) {
        if (vs[k] != vb[k]) {
          ssol = -1;
        }
      }
      if (ssol > -1) {
        sol = min(ssol, sol);
      }
    }

    if (sol == 1000000) {
      printf("Case #%d: NOT POSSIBLE\n", cs + 1);
    } else {
      printf("Case #%d: %d\n", cs + 1, sol);
    }
  }

  return 0;
}
