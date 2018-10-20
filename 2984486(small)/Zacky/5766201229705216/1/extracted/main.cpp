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
const int maxn = 1002;
const int mod = 1000000007;
const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const int move[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
int m,n,idx;

int head[maxn],val[maxn],cnt[maxn];
struct node {
  int v;
  int next;
}edge[maxn << 1];

void init() {
  memset(head,-1,sizeof(head));
  idx = 0;
  return;
}

void addedge(int u, int v) {
  edge[idx].v = v;
  edge[idx].next = head[u];
  head[u] = idx++;

  edge[idx].v = u;
  edge[idx].next = head[v];
  head[v] = idx++;
  return;
}

/*
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

void read() {
  scanf("%d",&n);
  int u,v;
  for (int i=1;i<n;i++) {
    scanf("%d%d",&u,&v);
    addedge(u,v);
  }
  return;
}

void preDeal(int r, int p) {
  cnt[r] = 1;
  for (int i=head[r]; i!=-1; i=edge[i].next) {
    if (edge[i].v == p) continue;
    preDeal(edge[i].v, r);
    cnt[r] += cnt[edge[i].v];
  }
  return;
}

void dfs(int r, int p) {
  val[r] = inf;
  bool leave = true;
  for (int i=head[r]; i!=-1; i=edge[i].next) {
    if (edge[i].v == p) continue;
    leave = false;
    dfs(edge[i].v, r);
  }
  if (leave) {
    val[r] = 0;
  } else {
    val[r] = cnt[r] - 1;
    for (int i=head[r]; i!= -1; i=edge[i].next) {
      int u = edge[i].v;
      if (u == p) continue;
      for (int j=edge[i].next; j!= -1; j=edge[j].next) {
        int v = edge[j].v;
        if (v == p) continue;
        //printf("%d %d %d %d\n",r,p,u,v);
        int res = cnt[r] - 1 - cnt[u] - cnt[v] + val[u] + val[v];
        val[r] = MIN(val[r], res);
      }
    }
  }
  return;
}

void solve() {
  int ans = inf;
  for (int i=1;i<=n;i++) {
    preDeal(i, -1);
    dfs(i, -1);
    ans = MIN(ans, val[i]);
  }
  printf("%d\n",ans);
  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("B-small-attempt0.in", "r", stdin);
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
