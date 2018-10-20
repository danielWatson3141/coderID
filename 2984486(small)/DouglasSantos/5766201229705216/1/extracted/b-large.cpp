#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
#include <complex>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int n;
vector<int> adj[1020];
int memo[1020];
int num;

int calcula(int u) {
  memo[u] = 0;
  vector<int> x;
  REP(i, (int) adj[u].size()) {
    int v = adj[u][i];
    if (memo[v] == -1) {
      x.push_back(calcula(v));
    }
  }
  if (x.size() == 0) return memo[u] = 1;
  if (x.size() == 1) return memo[u] = 1;
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  return memo[u] = x[0] + x[1] + 1;
}

int main()
{	
  int t;
  scanf("%d", &t);
  REP(k, t) {
    scanf("%d", &n);
    REP(i, n) adj[i].clear();
    REP(i, n-1) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int res = 1;
    REP(i, n) {
      memset(memo, -1, sizeof(memo));
      int x = calcula(i);
      //printf("%d %d\n", i+1, x);
      res = max(res, x);
    }
    printf("Case #%d: %d\n", k+1, n-res);
  }
	return 0;
}