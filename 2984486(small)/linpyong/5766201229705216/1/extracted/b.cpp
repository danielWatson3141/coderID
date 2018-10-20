#define PRETEST
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

#define INF 0x4f4f4f4f
#define FILL(a,b) memset(a,b,sizeof(a))
#define SQR(a) ((a) * (a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;

struct node {
  int v;
  node *next;
};

node *g[1010];
node ve[2020];

int counter;
void addedge(int u, int v) {
  node *p = &ve[counter++];
  p->v = v;
  p->next = g[u];
  g[u] = p;
}

int dfs(int u, int f) {
  int m1 = 0, m2 = 0;
  for (node *nd = g[u]; nd != NULL; nd = nd->next) {
    if (nd->v != f) {
      int ret = dfs(nd->v, u);
      if (ret >= m1) {
        m2 = m1;
        m1 = ret;
      } else if (ret > m2) {
        m2 = ret;
      }
    }
  }
  if (m2 == 0) {
    return 1;
  }
  return m1 + m2 + 1;
}

int main(int argc, char *argv[]) {
#ifdef PRETEST
  freopen("b.in", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int z = 1; z <= T; ++z) {
    int n;
    scanf("%d", &n);
    FILL(g, 0);
    counter = 0;
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      addedge(u, v);
      addedge(v, u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = max(ans, dfs(i, -1));
    }
    printf("Case #%d: %d\n", z, n - ans);
  }
  return 0;
}
