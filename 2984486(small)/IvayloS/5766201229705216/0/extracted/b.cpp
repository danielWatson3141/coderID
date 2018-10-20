/*
 * b.cpp
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



bool is(const vector<vector<int> >& ne, int mask) {
  int n = (int)ne.size();
  int cnt = 0;
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) {
      continue;
    } else {
      cnt++;
    }
  }
  if (cnt == 0 || cnt == 1) {
    return true;
  }
  vector<int> brn(n, 0);
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) {
      continue;
    }
    for (int j = 0; j < (int)ne[i].size(); ++j) {
      if (mask & (1 << ne[i][j])) {
        continue;
      }
      brn[i]++;
    }
    if (brn[i] == 2) {
      root = i;
    }
  }
  if (root == -1) {
    return false;
  }
  queue<int> tc;
  tc.push(root);
  int br = 1;
  vector<char> vis(n, 0);
  vis[root] = 1;
  while(!tc.empty()) {
    int c = tc.front();tc.pop();
    for (int i = 0; i < (int)ne[c].size(); ++i) {
      if (!vis[ne[c][i]] && (mask & (1 << ne[c][i])) == 0) {
        vis[ne[c][i]] = 1;
        tc.push(ne[c][i]);
        br++;
      }
    }
  }
  if (br != cnt) {
    return false;
  }

  for (int i =0 ; i < n; ++i) {
    if ((mask & (1 << i)) == 0 && i != root && brn[i] != 3 && brn[i] != 1) {
      return false;
    }
  }
  return true;
}
int solve(const vector<vector<int> >& ne) {
  int n = (int)ne.size();
  int ans = n;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (is(ne, mask)) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          ++cnt;
        }
      }
      ans = min(ans, cnt);
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
    int n;
    cin >> n;
    vector<vector<int> > ne(n);
    for (int i = 0; i < n - 1; ++i) {
      int f, t;
      cin >> f >> t;
      f--;
      t--;
      ne[f].push_back(t);
      ne[t].push_back(f);
    }
    cout << "Case #" << it << ": " << solve(ne) << endl;
  }
  return 0;
}

