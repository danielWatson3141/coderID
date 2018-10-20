#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;
const int MAXN = 200;
const int MAXL = 50;

int n, L;
llint A[MAXN];
llint B[MAXN];

int solve(int x, llint state) {
  map<llint, int> counter;
  REP(i, n) {
    llint s;

    s = 0;
    REP(j, x) if ( ((A[i]>>j)&1)^((state>>j)&1) ) s |= 1LL << j;
    counter[s]++;

    s = 0;
    REP(j, x) if ( ((B[i]>>j)&1) ) s |= 1LL << j;
    counter[s]--;    
  }
  for (auto p : counter) if (p.second != 0) return inf;
  if (x == L) return 0;

  int mini = inf;
  mini = min(mini, solve(x+1, state));
  mini = min(mini, solve(x+1, state|(1LL<<x)) + 1);
  return mini;
}

int main(void)
{
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    scanf("%d %d", &n, &L);

    REP(i, n) {
      static char buff[MAXL]; scanf("%s", buff);
      A[i] = 0; for (int j = 0; j < L; ++j) if (buff[j] == '1') A[i] |= 1LL << j;
    }
    REP(i, n) {
      static char buff[MAXL]; scanf("%s", buff);
      B[i] = 0; for (int j = 0; j < L; ++j) if (buff[j] == '1') B[i] |= 1LL << j;
    }

    printf("Case #%d: ", tc+1);

    int ans = solve(0, 0LL);
    if (ans >= inf) puts("NOT POSSIBLE");
    else printf("%d\n", ans);
    fflush(stdout);
  }
  return 0;
}
