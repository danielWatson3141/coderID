#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

#define dlog printf
//#define dlog(...)

const int inf = 1234;

int N,L;

ll outlet[256];
ll device[256];

ll tobits(char const * buf)
{
  ll ret = 0;
  for (char const * p = buf; *p; ++p) {
    ret <<= 1;
    if (*p == '1') ret ^= 1;
  }
  return ret;
}

vector<ll> ovec, dvec;

void doit(int cas)
{
  scanf(" %d %d", &N, &L);
  assert(1 <= N && N <= 150);
  assert(2 <= L && L <= 40);

  char buf[64];
  FOR(i,N) {
    scanf(" %s", buf);
    outlet[i] = tobits(buf);
  }
  FOR(i,N) {
    scanf(" %s", buf);
    device[i] = tobits(buf);
  }

  int best = inf;

  FOR(i,N) {
    ovec.clear(); dvec.clear();

    ll mask = outlet[0] ^ device[i];

    FOR(j,N) {
      ovec.push_back(outlet[j] ^ mask);
      dvec.push_back(device[j]);
    }

    sort(BEND(ovec)); sort(BEND(dvec));
    if (ovec == dvec) best = min(best, __builtin_popcount(mask));
  }

  printf("Case #%d: ", cas);
  if (best == inf) {
    printf("NOT POSSIBLE");
  } else {
    printf("%d", best);
  }
  printf("\n");
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 100);
  FOR(cas,T) doit(cas+1);
  return 0;
}
