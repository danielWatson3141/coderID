#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define MAXN 15
using namespace std;

int testcase;
int N,L,ans;
string A[MAXN], B[MAXN], tmp[MAXN];

int main () {
  freopen("A-small-attempt0.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf ("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d%d",&N,&L);
    ans = L+1; 
    for (int i=0;i<N;++i) cin >> A[i];
    for (int i=0;i<N;++i) cin >> B[i];
    sort(A,A+N);
    for (int z=0;z<(1<<L);++z) {
      for (int i=0;i<N;++i) tmp[i] = B[i];
      int cnt = 0;
      for (int j=0;j<L;++j)
        if ( (z & (1<<j)) > 0) { 
          cnt++;
          for (int i=0;i<N;++i)
            tmp[i][j] = 1 - (tmp[i][j] - '0') + '0';
        }
      sort(tmp,tmp+N);
      bool can = 1;
      for (int i=0;i<N;++i)
        if (A[i] != tmp[i]) {
          can = 0;
          break;
        }
      if (can) ans = min(ans,cnt);
    }
    if (ans != L+1) 
      printf("Case #%d: %d\n",TC,ans);
    else printf("Case #%d: NOT POSSIBLE\n",TC);
  }
}
