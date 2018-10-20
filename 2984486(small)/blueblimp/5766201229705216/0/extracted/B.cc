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

//#define dlog printf
#define dlog(...)

typedef pair<double, int> pdi;

const int maxN = 1024;
const int none = maxN-1;

int N;
int Xi, Yi;

const int BIG = 3 * maxN;
int weight[BIG];
int opt[BIG];

typedef pair<int,int> arc;
#define head first
#define tail second

int degree[maxN];
vector<arc> arcs;

int do_weight(int ai)
{
  if (weight[ai] != -1) return weight[ai];

  int v = arcs[ai].head;
  int start = std::lower_bound(BEND(arcs), arc(v,0)) - arcs.begin();
  int end = std::lower_bound(BEND(arcs), arc(v+1,0)) - arcs.begin();
  assert(0 <= start);
  assert(start < end);
  assert(end <= SZ(arcs));
  assert( (end-start) == degree[v] + 1);

  int ret = 1;

  FR(i, start, end) {
    int w = arcs[i].tail;
    if (w == none) continue;
    if (w == arcs[ai].tail) continue;

    int aj = std::lower_bound(BEND(arcs), arc(w,v)) - arcs.begin();
    assert(arcs[aj].tail == v && arcs[aj].head == w);
    ret += do_weight(aj);
  }

  return weight[ai] = ret;
}

vector<int> opt_tmp[maxN];
int do_opt(int ai)
{
  if (opt[ai] != -1) return opt[ai];

  int v = arcs[ai].head;
  int start = std::lower_bound(BEND(arcs), arc(v,0)) - arcs.begin();
  int end = std::lower_bound(BEND(arcs), arc(v+1,0)) - arcs.begin();
  assert(0 <= start);
  assert(start < end);
  assert(end <= SZ(arcs));
  assert( (end-start) == degree[v] + 1);

  int all_wt = do_weight(ai) - 1;
  assert(all_wt >= 0);

  vector<int> & my_opt_tmp = opt_tmp[v];
  my_opt_tmp.clear();
  int all_aj_wt = 0;
  FR(i, start, end) {
    int w = arcs[i].tail;
    if (w == none) continue;
    if (w == arcs[ai].tail) continue;

    int aj = std::lower_bound(BEND(arcs), arc(w,v)) - arcs.begin();
    assert(arcs[aj].tail == v && arcs[aj].head == w);
    int aj_wt = do_weight(aj), aj_opt = do_opt(aj);
    assert(aj_opt >= 0);
    assert(aj_opt < aj_wt);
    my_opt_tmp.push_back( aj_opt - aj_wt );
    all_aj_wt += aj_wt;
  }
  assert(all_aj_wt == all_wt);

  int best = all_wt;
  if (my_opt_tmp.size() >= 2) {
    std::partial_sort(my_opt_tmp.begin(), my_opt_tmp.begin()+2, my_opt_tmp.end());
    best += my_opt_tmp[0] + my_opt_tmp[1];
  }
  assert(best >= 0);
  return opt[ai] = best;
}

void doit(int cas)
{
  scanf(" %d", &N);
  assert(2 <= N && N <= 1000);

  memset(degree, 0, sizeof(degree));
  arcs.clear();

  FOR(i,N) arcs.push_back( { i, none } );

  FOR(i,N-1) {
    int Xi, Yi;
    scanf(" %d %d", &Xi, &Yi);
    --Xi; --Yi;

    arcs.push_back( { Xi, Yi } );
    arcs.push_back( { Yi, Xi } );
    ++degree[Xi];
    ++degree[Yi];
  }

  sort(BEND(arcs));

  memset(weight, -1, sizeof(weight));
  memset(opt, -1, sizeof(opt));

  int best = BIG;
  FORI(i,arcs) {
    dlog("Arc %d = %d <- %d\n", i, arcs[i].head, arcs[i].tail);
    dlog("  wt %3d   opt %3d\n", do_weight(i), do_opt(i));

    if (arcs[i].tail == none) {
      assert(do_weight(i) == N);
      best = min(best, do_opt(i));
    }
  }

  assert(0 <= best && best < N);

  printf("Case #%d: %d\n", cas, best);
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 100);
  FOR(cas,T) doit(cas+1);
  return 0;
}
