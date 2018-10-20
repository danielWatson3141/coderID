#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

const int inf = 1 << 29;
const int maxn = 12;
const int mod = 1000000007;
const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const int move[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
//int m,n,idx,l,r,del;
/*
int head[maxn],val[maxn],dep[maxn];
struct node {
  int v;
  int next;
}edge[maxn << 1];

void init() {
  memset(head,-1,sizeof(head));
  memset(val,0,sizeof(val));
  idx = 0;
  return;
}

void addedge(int u, int v) {
  edge[idx].v = v;
  edge[idx].next = head[u];
  head[u] = idx++;
  return;
}


bool judge(int x, int y) {
  if (x >= 0 && y >= 0 && x < m && y < n) {
    return true;
  }
  return false;
}

void read() {
  scanf("%d",&n);
  int p;
  for (int i=2;i<=n;i++) {
    scanf("%d",&p);
    addedge(p, i);
  }
  return;
}

void dfs(int u) {
  if (dep[u] >= l && dep[u] <= r) {
    val[u] = (val[u] + del) % mod;
  }
  for (int i=head[u]; i!= -1; i=edge[i].next) {
    dfs(edge[i].v);
  }
  return;
}
*/

int m,n;
char out[maxn][maxn], in[maxn][maxn], tmp[maxn][maxn];
bool vis[maxn];
void init() {
}

bool judge() {
  memset(vis,false,sizeof(vis));
  for (int i=0;i<n;i++) {
    bool flag = false;
    for (int j=0;j<n;j++) {
      if (vis[j] == false && strcmp(tmp[i], in[j]) == 0) {
        vis[j] = true;
        flag = true;
        break;
      }
    }
    if (!flag) return false;
  }
  return true;
}

void read() {
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++) {
    scanf("%s", out[i]);
  }
  for (int i=0;i<n;i++) {
    scanf("%s", in[i]);
  }
}

int count(int st) {
  int cnt = 0;
  for (int i=0;i<m;i++) {
    if (st & (1 << i)) cnt++;
  }
  return cnt;
}

void solve() {
  int res = inf;
  for (int i=0;i<(1<<m);i++) {
    for (int j=0;j<n;j++) {
      strcpy(tmp[j], out[j]);
    }
    for (int j=0;j<m;j++) {
      if (i & (1 << j)) {
        for (int k=0;k<n;k++) {
          if (tmp[k][j] == '0') tmp[k][j] = '1';
          else tmp[k][j] = '0';
        }
      }
    }
    if (judge()) {
      res = MIN(res, count(i));
    }
  }

  if (res == inf) {
    puts("NOT POSSIBLE");
  } else {
    printf("%d\n",res);
  }

  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("A-small-attempt1.in", "r", stdin);
  //freopen("B-large.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d",&cas);
  for (int i=1;i<=cas;i++) {
    printf("Case #%d: ", i);
    init();
    read();
    solve();
  }
  return 0;
}
