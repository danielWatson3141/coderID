#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define MAXN 155
using namespace std;

int testcase, fix[MAXN];
int N,L,ans, cnt[MAXN], fixed_val;
string A[MAXN], B[MAXN], tmp[MAXN];

void can(int j, int cur_moves) {
  if (j == L) {
    ans = min(ans,cur_moves);
    return;
  }
  if (cur_moves >= ans) return;
  bool ok = 1;
  for (int i=0;i<N;++i)
    if (A[i][j] != B[i][j]) {
      ok = 0;
      break;
    }
  if (!ok && fix[j]) return;
  if (ok) can(j+1,cur_moves);
  if (fix[j] == 0) {
    for (int i=0;i<N;++i)
      B[i][j] = 1 - (B[i][j] - '0') + '0';
    sort(B,B+N);
    ok = 1;
    for (int i=0;i<N;++i)
      if (A[i][j] != B[i][j]) {
        ok = 0;
        break;
      }
    if (ok) can(j+1,cur_moves+1);
    for (int i=0;i<N;++i)
      B[i][j] = 1 - (B[i][j] - '0') + '0';
  }
}

int main () {
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf ("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d%d",&N,&L);
    ans = L+1; 
    for (int i=0;i<N;++i) cin >> A[i];
    for (int i=0;i<N;++i) cin >> B[i];
    memset(fix,0,sizeof(fix));
    sort(A,A+N);
    fixed_val = 0;
    for (int j=0;j<L;++j) {
      int t1 = 0, t2 = 0;
      for (int i=0;i<N;++i) {
        t1 += A[i][j] == '0';
        t2 += B[i][j] == '0';
      }
      if (! (t1 == t2 || t1 + t2 == N)) {
        goto end;
      }
      if (t1 != t2) {
        fix[j] = 1;
        fixed_val++;
        for (int i=0;i<N;++i)
          B[i][j] =  1 - (B[i][j] - '0') + '0';
      }
    }
    sort(B,B+N); 
    can(0,fixed_val);
    end:;
    if (ans <= L) 
      printf("Case #%d: %d\n",TC,ans);
    else printf("Case #%d: NOT POSSIBLE\n",TC);
  }
}
