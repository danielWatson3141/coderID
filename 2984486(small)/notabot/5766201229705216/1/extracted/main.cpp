#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define DB(x) cerr << x << " "
#define DBN(x) cerr << #x << "=" << x << endl
#define DBL cerr << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int maxn = 1010;

int n;
vector<int> adj[maxn];

int calc(int v, int parent) {
  assert(sz(adj[v]) > 0);
  if (parent == -1) {
    if (sz(adj[v]) <= 1) return 1;
  } else {
    if (sz(adj[v]) <= 2) {
      assert(parent == -1 || adj[v][0] == parent || adj[v][1] == parent);
      return 1;
    }
  }
  vector<int> sub;
  for (int u : adj[v]) {
    if (u != parent) sub.pb(calc(u, v));
  }
  sort(begin(sub), end(sub));
  return 1 + sub[sz(sub) - 1] + sub[sz(sub) - 2];
}

void solve(int testcase) {
  DBN(testcase);
  printf("Case #%d: ", testcase);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    adj[i].clear();
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int res = n;
  for (int i = 1; i <= n; ++i) {
    //DBN(calc(i, -1));
    res = min(res, n - calc(i, -1));
  }
  printf("%d\n", res);
}

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
