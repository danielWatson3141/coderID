#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int N;
int edge[1200][1200], es[1200];
int dp[1200];

int solve(int now, int bef){
  int i, j, k;
  vector<int> num;

  rep(k,es[now]){
    i = edge[now][k];
    if(i==bef) continue;
    num.push_back( solve(i, now) );
  }

  dp[now] = 1;
  if(num.size() >= 2){
    sort(num.rbegin(), num.rend());
    dp[now] += num[0] + num[1];
  }

  return dp[now];
}

int main(){
  int i, j, k;
  int res, tmp;
  int T, cnt = 0;

  scanf("%d",&T);
  while(T--){
    fprintf(stderr,"rest %d\n",T);
    printf("Case #%d: ", ++cnt);

    scanf("%d",&N);
    rep(i,N) es[i] = 0;
    rep(i,N-1){
      scanf("%d%d",&j,&k);
      j--; k--;
      edge[j][es[j]++] = k;
      edge[k][es[k]++] = j;
    }

    res = INF;
    rep(i,N){
      rep(j,N) dp[i] = -1;
      tmp = solve(i, -1);
      res = min(res, N-tmp);
    }

    printf("%d\n", res);
  }

  return 0;
}
