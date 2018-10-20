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
vector<int> adj[20];
bool used[20];
int num;

bool DFS(int u, int mask) {
  used[u] = true;
  num++;
  int d = 0;
  REP(i, (int) adj[u].size()) {
    int v = adj[u][i];
    if (!(mask & (1 << v))) continue;
    if (used[v]) continue;
    d++;
    if (!DFS(v, mask)) return false;
  }
  return (d == 2) || (d == 0);
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
    int res = INF;
    REP(mask, (1 << n)) {
      int x = __builtin_popcount(mask);
      bool foi = false;
      REP(i, n) {
        if (mask & (1 << i)) {
          memset(used, false, sizeof(used));
          num = 0;
          if (DFS(i, mask) && num == x) {
            foi = true;
            break;
          }
        }
      }
      if (foi) res = min(res, n-x);
    }
    printf("Case #%d: %d\n", k+1, res);
  }
	return 0;
}