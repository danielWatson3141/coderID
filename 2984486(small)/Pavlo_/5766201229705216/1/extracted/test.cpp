#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

const int INF = 1<<20;

vector<int> a[1<<10];
int sz[1<<10];
int n;
int r[1<<10];

int dfsSz(int cur, int par) {
  sz[cur] = 1;
  for (int i = 0 ; i < a[cur].size(); ++i) {
    int nx = a[cur][i];
    if (nx == par) {
      continue;
    }
    sz[cur] += dfsSz(nx, cur);
  }
  return sz[cur];
}

int solve(int cur, int par) {
  vector<int> ans;
  for (int i = 0; i < a[cur].size(); ++i) {
    int nx = a[cur][i];
    if (nx == par) {
      continue;
    }

    ans.push_back(solve(nx, cur) - sz[nx]);
  }

  sort(ans.begin(), ans.end());
  if (ans.empty()) {
    return 0;
  }
  if (ans.size() == 1) {
    return sz[cur] - 1;
  }
  if (ans.size() >= 2) {
    int res = sz[cur] - 1;
    res = min(res, sz[cur] - 1 + ans[0] + ans[1]);
    return res;
  }
  throw -1;
  return INF;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  cin>>tests;
  for (int t = 0; t < tests; ++t) {
    cout << "Case #" << t + 1 << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
      a[i].clear();
    }
    for (int i = 0; i < n-1; ++i) {
      int x,y;
      scanf("%d%d",&x,&y);
      --x;--y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    int res = INF;
    for (int i = 0; i < n; ++i) {
      dfsSz(i, -1);
      res = min(res, solve(i, -1));
      if (res == 0) {
        break;
      }
    }

    if (res >= INF) {
      throw -1;
    }

    cout << res << endl;
  }
  return 0;
}