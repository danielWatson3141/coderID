#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN=1005;
int T,Cas=0;

struct node {
  int v, next;
} e[MAXN<<1];

int N, p[MAXN], eid;

void init_adj() {
  memset(p,-1,sizeof(p));
  eid=0;
}

void add_edge(int u,int v) {
  e[eid].v=v;
  e[eid].next=p[u];
  p[u]=eid++;

  e[eid].v=u;
  e[eid].next=p[v];
  p[v]=eid++;
}

int test(int root, int fa=-1) {
  vector<int> child;
  for (int i=p[root];~i;i=e[i].next) {
    int v=e[i].v;
    if (fa==v)
      continue;
    child.push_back(test(v, root));
  }
  int sz=child.size();
  if (sz<=1)
    return 1;
  sort(child.begin(), child.end());
  return child[sz-2]+child[sz-1]+1;
}

int main() {
  int u, v;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    init_adj();
    for (int i=1;i<N;i++) {
      scanf("%d%d", &u,&v);
      add_edge(u,v);
    }
    int least=-1;
    for (int i=1;i<=N;i++) {
      int ans=test(i);
      least=max(least, ans);
    }
    fprintf(stderr, "%d\n", T);
    printf("Case #%d: %d\n", ++Cas, N-least);
  }
}