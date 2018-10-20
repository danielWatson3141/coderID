#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1024;
const int INF = 1e9;
typedef long long LL;
LL from[MAXN], to[MAXN];
LL tf[MAXN], tt[MAXN];
int n, L;

int cnt_dig(LL diff) {
  int s = 0;
  while (diff) {
    if (diff & 1) ++s;
    diff >>= 1;
  }
  return s;
}

bool check(LL diff) {
  memcpy(tf, from, sizeof(from));
  memcpy(tt, to, sizeof(to));
  for (int i = 0 ; i < n ; ++i)
    tf[i] ^= diff;
  sort(tf, tf+n);
  sort(tt, tt+n);
  for (int i = 0 ; i < n ; ++i)
    if (tf[i] != tt[i]) return false;
  return true;
}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d%d",&n,&L);
    for (int i = 0 ; i < n ; ++i) {
      char buf[128];
      scanf("%s", buf);
      from[i] = 0;
      for (int j = 0 ; buf[j] ; ++j)
        from[i] = from[i] * 2 + (buf[j] - '0');
    }
    for (int i = 0 ; i < n ; ++i) {
      char buf[128];
      scanf("%s", buf);
      to[i] = 0;
      for (int j = 0 ; buf[j] ; ++j)
        to[i] = to[i] * 2 + (buf[j] - '0');
    }
    int best = INF;
    for (int i = 0 ; i < n ; ++i)
      for (int j = 0 ; j < n ; ++j) {
        LL diff = (from[i] ^ to[j]);
        if (check(diff)) {
          int tmp = cnt_dig(diff);
          if (tmp < best) 
            best = tmp;
        }
      }
    printf("Case #%d: ", ca);
    if (best >= INF) printf("NOT POSSIBLE\n");
    else printf("%d\n", best);
  }
  return 0;
}

