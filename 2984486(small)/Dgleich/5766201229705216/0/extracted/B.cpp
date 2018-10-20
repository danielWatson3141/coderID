#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1005;

vector <int> E[MAXN];

int f (int x, int dad){
  int maks1, maks2;
  maks1 = maks2 = -10000000;

  for (int i = 0; i < E[x].size(); ++i){
    int y = E[x][i];
    if (dad == y) continue;
    int v = f(y, x);
    if (v >= maks1){
      maks2 = maks1;
      maks1 = v;
    }
    else{
      if (v >= maks2)
	maks2 = v;
      
    }
  }

  return max(1, 1+maks1+maks2);
}

void solve (){
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) E[i].clear();
  for (int i = 0; i < n-1; ++i){
    int x, y; scanf("%d%d", &x, &y); --x; --y;
    E[x].push_back(y);
    E[y].push_back(x);
  }

  int ans = -100000;
  for (int i = 0; i < n; ++i)
    ans = max(ans, f(i, -1));
  printf("%d\n", n-ans);
}

int main (void){
  int tc; scanf ("%d", &tc);
  for (int i = 1; i <= tc; ++i){
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}


