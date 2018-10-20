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

vector<vector<int> > ne;
int n;
vector<int> ans;
vector<char> vis;
int dfs(int v) {
  vis[v] = 1;
  int a = 0;
  int b = 0;
  for (int i = 0; i < (int)ne[v].size(); ++i) {
    if (vis[ne[v][i]]) {
      continue;
    }
    int temp = dfs(ne[v][i]);
    if (temp > a && temp > b) {
      if (a > b) {
        b = temp;
      } else {
        a = temp;
      }
    } else {
      if (a > b) {
        if (temp > b) {
          b = temp;
        }
      }
    }
  }
  if (a > 0 && b > 0) {
    return a + b + 1;
  } else {
    return 1;
  }
}
int help(int root) {
  ans.clear();
  ans.resize(n, -1);
  vis.clear();
  vis.resize(n, 0);
  return dfs(root);
}
int solve(const vector<vector<int> >& ne) {
  int n = (int)ne.size();
  int ans = n;
  for (int root = 0; root < n; ++root) {
    ans = min(ans, n - help(root));
  }
  return ans;
}
int main() {
  freopen("google.in", "r", stdin);
  // freopen("b-small.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    cin >> n;
    if (it == 88) {
      cerr << n << endl;
    }
    ne.clear();
    ne.resize(n);
    for (int i = 0; i < n - 1; ++i) {
      int f, t;
      cin >> f >> t;
      if (it == 88) {
            cerr << f << " " << t << endl;
          }
      f--;
      t--;
      ne[f].push_back(t);
      ne[t].push_back(f);
    }
    cout << "Case #" << it << ": " << solve(ne) << endl;
  }
  return 0;
}

