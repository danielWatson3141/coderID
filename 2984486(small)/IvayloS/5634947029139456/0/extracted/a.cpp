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

int solve(const vector<string>& target, const vector<string>& source) {
  int n = (int)target[0].size();
  int ans = -1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<string> temp;
    for (int i = 0; i < (int)source.size(); ++i) {
      string tmp;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          tmp.push_back((source[i][j] == '1' ? '0' : '1'));
        } else {
          tmp.push_back(source[i][j]);
        }
      }
      temp.push_back(tmp);
    }
    sort(all(temp));

    if (temp == target) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          cnt++;
        }
      }
      if (ans == -1 || cnt < ans) {
        ans = cnt;
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
    vector<string> a(n), b(n);
    for (int i = 0; i < (int)a.size(); ++i) {
      cin >> a[i];
    }

    for (int i = 0; i < (int)b.size(); ++i) {
      cin >> b[i];
    }

    sort(all(b));

    int val = solve(b, a);
    cout << "Case #" << it << ": ";
    if (val != -1) {
      cout << val << endl;
    } else {
      cout << "NOT POSSIBLE\n";
    }
  }
  return 0;
}

