/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111
int a[MAXN];

double val[MAXN], valn[MAXN];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  REP(t, T) {
    int N;
    scanf("%d", &N);
    REP(i, N) scanf("%d", a + i);
    REP(i, N) {
      int aa = a[i];
      if (aa <= i) aa += i + N / 2;
      aa -= i + 1;
      double var = N - aa;
      var *= N - i - 1;
      val[t] -= var;
    }
  }

  REP(i, T) valn[i] = val[i];
  sort(valn, valn + T);

  REP(t, T) {
    printf("Case #%d: ", t + 1);
    if (val[t] < valn[T / 2]) printf("BAD\n");
    else printf("GOOD\n");
  }

  return 0;
}
