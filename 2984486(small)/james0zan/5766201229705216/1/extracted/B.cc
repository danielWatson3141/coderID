#include "stdio.h"
#include "stdlib.h"
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include "stdint.h"

#define pb push_back

using namespace std;

vector<int> edge[1010];


int get(int x, int p) {
  if ((p==-1 && edge[x].size() < 2) || (p!=-1 && edge[x].size() < 3)) return 1;

  vector<int> a;
  for (int i=0; i<edge[x].size(); i++)
    if (edge[x][i] != p) {
      a.pb(get(edge[x][i], x));
    }
  sort(a.begin(), a.end());
  return a[a.size()-1]+a[a.size()-2] + 1;
}

int main() {
  int _N, N, L;
  scanf("%d", &_N);
  for (int TC=1; TC<=_N; TC++) {
    scanf("%d", &N);
    for (int i=0; i<N; i++) edge[i].clear();
    for (int i=1; i<N; i++) {
      int a,b;
      scanf("%d%d", &a, &b);
      a--; b--;
      edge[a].pb(b);
      edge[b].pb(a);
    }
    int ans = 0;
    for (int i=0; i<N; i++) {
      int tmp = get(i, -1);
      //printf("==%d %d\n", i, tmp);
      if (tmp > ans) ans = tmp;
    }

    printf("Case #%d: %d\n", TC, N - ans);
  }
}