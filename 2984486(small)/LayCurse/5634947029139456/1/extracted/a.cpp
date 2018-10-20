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

vector<int> reader(void){
  int i;
  vector<int> res;
  char buf[1000];
  scanf("%s",buf);
  for(i=0;;i++){
    if(buf[i]=='\0') break;
    res.push_back(buf[i]-'0');
  }
  return res;
}

int main(){
  int i, j, k;
  int T, cnt = 0;
  int N, L;
  int res, tmp;
  char buf[1000];
  vector<int> fst[200], sec[200];
  vector<int> mfst[200], msec[200], modi;

  scanf("%d",&T);
  while(T--){
    fprintf(stderr,"rest %d\n",T);
    printf("Case #%d: ", ++cnt);

    scanf("%d%d",&N,&L);
    rep(i,N) fst[i] = reader();
    rep(i,N) sec[i] = reader();

    res = INF;
    rep(k,N){
      modi = sec[k];
      rep(i,L) modi[i] ^= fst[0][i];

      rep(i,N){
        mfst[i] = fst[i];
        rep(j,L) mfst[i][j] ^= modi[j];
      }
      rep(i,N) msec[i] = sec[i];

      sort(mfst, mfst+N);
      sort(msec, msec+N);

      rep(i,N) if(mfst[i] != msec[i]) break;
      if(i<N) continue;

      tmp = 0;
      rep(i,L) tmp += modi[i];
      res = min(res, tmp);
    }

    if(res==INF) puts("NOT POSSIBLE"); else printf("%d\n",res);
  }

  return 0;
}
