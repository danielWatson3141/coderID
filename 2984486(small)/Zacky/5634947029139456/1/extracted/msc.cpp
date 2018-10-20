#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
#define MIN(a,b) ((a) < (b) ? (a) : (b))
const int maxn = 102;
const int maxm = 10;
const int inf = 1 << 29;
int mat[maxn][maxn], dp[maxm][1 << maxm], st[maxm][1 << maxm];
int m, n;

void read() {
  scanf("%d%d",&m,&n);
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  memset(st,0,sizeof(st));
  for (int i=0;i<m;i++) {
    for (int j=0;j<(1<<n);j++) {
      int sum = 0;
      for (int k=0;k<n;k++) {
        if (j & (1 << k)) sum += mat[i][k];
      }
      st[i][j] = sum;
      dp[i][j] = inf;
    }
  }
  return;
}

int solve() {
  for (int i=0;i<m;i++) {
    for (int j=0;j<(1<<n);j++) {
      if (i == 0) dp[i][j] = st[i][j];
      if (i == 0 || j == 0) continue;
      for (int k=j;k>0;k=(k-1)&j) {
        for (int p=j;p>0;p=(p-1)&j) {
          if ((p | k) == j) {
            dp[i][j] = MIN(dp[i][j], dp[i-1][p] + st[i][k]);
          }
        }
      }
    }
  }

  return dp[m-1][(1<<n)-1];
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d",&cas);
  for (int i=1; i<=cas; i++) {
    read();
    printf("Case #%d: %d\n", i, solve());
  }
  return 0;
}

