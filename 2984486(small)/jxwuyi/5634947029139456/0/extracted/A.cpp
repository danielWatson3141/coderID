#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

LL outlet[200], charge[200];
int N, L;
char buf[1000];

LL getLL(){
  LL ret=0;
  for(int i=0;i<L;++i)
    ret=(ret<<1)|(buf[i]-'0');
  return ret;
}

int x, y;
LL msk;
const int full = (1 << 20) - 1;

int pop_count(LL m){
  return __builtin_popcount((int)(m >> 20))
      + __builtin_popcount((int)(m & full));
}

int run() {
  scanf("%d %d", &N, &L);
  for(int i=0;i<N;++i){
    scanf("%s", buf);
    outlet[i] = getLL();
  }
  for(int i=0;i<N;++i) {
    scanf("%s", buf);
    charge[i] = getLL();
  }
  
  int ans = -1;
  for(x=0;x<N;++x)
    for(int y=0;y<N;++y){
      LL msk = outlet[x] ^ charge[y];
      map<LL,int> R;
      for(int i=0;i<N;++i)
        R[outlet[i] ^ msk] = 1;
      bool ok=true;
      for(int i=0;i<N && ok;++i)
        if(R[charge[i]] -- <= 0) ok= false;
      if(ok){
        int tmp = pop_count(msk);
        if(tmp < ans||ans<0) ans=tmp;
      }
    }
  return ans;
}

int main() {
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int test;
  scanf("%d", &test);
  for(int no=1;no<=test;++no){
    printf("Case #%d: ", no);
    int ans = run();
    if(ans<0)puts("NOT POSSIBLE");
    else printf("%d\n", ans);
  }
}

