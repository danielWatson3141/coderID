#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 1005
#define FAIL 1005
using namespace std;

int testcase, ans, N,L[MAXN],R[MAXN], SIZE[MAXN], dp[MAXN][3];
vector <int> G[MAXN];
bool visit[MAXN];

void root(int x) {
  visit[x] = 1;
  //printf("visit %d\n",x);
  for (vector <int>::iterator it=G[x].begin();it!=G[x].end();++it)
    if(!visit[*it]) {
      L[*it] = R[x];
      R[x] = *it;
      root(*it);
      SIZE[x] += SIZE[*it];
    }
 // printf("L[%d] = %d, R[%d] = %d\n",x,L[x],x,R[x]);
  SIZE[x]++;
}

int cal(int x, int d) {
  if (x == -1) return (d == 0) ? 0 : FAIL;
  if (dp[x][d] != -1) return dp[x][d];
  dp[x][d] = FAIL;
  dp[x][d] = cal(L[x], d) + SIZE[x];
  if (d > 0) {
    int tmp = min(cal(R[x], 2), cal(R[x],0));
    dp[x][d] = min(dp[x][d], cal(L[x], d-1) + tmp);
  }
 // printf("dp[%d][%d] = %d\n",x,d,dp[x][d]);
  return dp[x][d];
}

int main () {
  freopen("B-large.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf ("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf ("%d", &N);
    for (int i=1;i<=N;++i) G[i].clear();
    for (int i=1;i<N;++i) {
      int a,b;
      scanf("%d%d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    ans = N-1;
    for (int src=1;src<=N;++src) {
      //for (int i=1;i<=N;++i) G[i].clear();
      memset(dp,-1,sizeof(dp));
      memset(L,-1,sizeof(L));
      memset(R,-1,sizeof(R));
      memset(SIZE,0,sizeof(SIZE));
      memset(visit,0,sizeof(visit));
      //printf("\n\nroot = %d\n",src);
      root(src);
      ans = min(ans,cal(src,1));
    }
    printf("Case #%d: %d\n",TC, ans);
  }
}
