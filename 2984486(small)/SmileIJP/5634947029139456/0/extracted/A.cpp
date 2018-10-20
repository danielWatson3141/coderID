#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }


void solve() {
  int n = next< int >();
  int l = next< int >();
  vector< string > a[2];

  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
      a[k].push_back(next< string >());   
    }
  }
  sort(ALL(a[0]));
  int res = l + 10;
  for (int msk = 0; msk < (1 << l); ++msk) {
    vector< string > b;
    for (int i = 0; i < n; ++i) {
      string tmp = a[1][i];
      for (int j = 0; j < l; ++j) {
        if ((msk >> j) % 2 == 1) {
          tmp[j] = tmp[j] == '0' ? '1' : '0';
        }
      }
      b.push_back(tmp);
    }
    sort(ALL(b));
    if (equal(ALL(a[0]), b.begin())) {
      int w = 0;
      for (int j = 0; j < l; ++j) {
        w += (msk >> j) % 2;
      }
      res = min(res, w);
    }
  }
  if (res > l) {
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << res << endl;
  }
}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

