/*
 * a.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

bool check(const vector<ll>& target, const vector<ll>& source,
    ll mask) {
  vector<ll> temp;
  for (int i = 0; i < (int)source.size(); ++i) {
    temp.push_back(source[i] ^ mask);
  }
  sort(all(temp));
  return temp == target;

}

int solve(const vector<ll>& target, const vector<ll>& source, int n) {
  int ans = -1;
  for (int i = 0; i < (int)target.size(); ++i) {
    for (int j = 0; j < (int)source.size(); ++j) {
      ll mask = target[i] ^ source[j];
      if (check(target, source, mask)) {
        int cnt = 0;
        for (int l = 0; l < n; ++l) {
          if (mask & (1LL << l)) {
            cnt++;
          }
        }
        if (ans == -1 || cnt < ans) {
          ans = cnt;
        }
      }
    }
  }

  return ans;
}
int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n, l;
    cin >> n >> l;
    vector<string> ta(n), tb(n);
    vector<ll> a(n), b(n);
    for (int i = 0; i < (int)a.size(); ++i) {
      cin >> ta[i];
      a[i] = 0;
      for (int j = 0; j < (int)ta[i].size(); ++j) {
        a[i] = a[i] * 2LL + (ta[i][j] == '1');
      }
    }

    for (int i = 0; i < (int)b.size(); ++i) {
      cin >> tb[i];
      b[i] = 0;
      for (int j = 0; j < (int)tb[i].size(); ++j) {
        b[i] = b[i] * 2LL + (tb[i][j] == '1');
      }
    }

    sort(all(b));

    int val = solve(b, a, l);
    cout << "Case #" << it << ": ";
    if (val != -1) {
      cout << val << endl;
    } else {
      cout << "NOT POSSIBLE\n";
    }
  }
  return 0;
}

