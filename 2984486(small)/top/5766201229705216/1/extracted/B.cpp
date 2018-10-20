#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e3+10,inf = -1u/2;

int n;
vector<int> Vt[N],V[N];
int child[N],dp[N];

inline void dfs (int u, int p) {
  child[u] = 1;
  for (int i = 0;i < Vt[u].size ();i ++) {
    int v = Vt[u][i];
    if (v != p) {
      dfs (v, u);

      V[u].push_back (v);
      child[u] += child[v];
    }
  }
}

inline int go (int u) {
  int ret;
  if (V[u].size () == 0) {
    ret = 0;
  } else if (V[u].size () == 1) {
    ret = child[V[u][0]];
  } else if (V[u].size () == 2) {
    ret = 0;
    for (int i = 0;i < V[u].size ();i ++) {
      ret += go (V[u][i]);
    }
  } else {
    int sumchild = 0,a = inf,b = inf;
    for (int i = 0;i < V[u].size ();i ++) {
      int v = V[u][i];
      sumchild += child[v];
      int k = go (v)-child[v];

      if (k < a) {
	b = a;
	a = k;
      } else if (k < b) {
	b = k;
      }
    }
    ret = sumchild+a+b;
  }
  return (dp[u] = ret);
}

inline int solve () {
  scanf ("%d", &n);

  for (int i = 1;i <= n;i ++) {
    Vt[i].clear ();
  }

  for (int i = 0;i < n-1;i ++) {
    int u,v;
    scanf ("%d %d", &u, &v);
    Vt[u].push_back (v);
    Vt[v].push_back (u);
  }

  int ans = -1u/2;
  for (int i = 1;i <= n;i ++) {
    for (int j = 1;j <= n;j ++) {
      dp[j] = inf;
      V[j].clear ();
    }
    dfs (i, 0);

    ans = min (ans, go (i));
  }
  return ans;
}

int main () {
  int t;
  scanf ("%d", &t);
  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: %d\n", i, solve ());
  }
}
