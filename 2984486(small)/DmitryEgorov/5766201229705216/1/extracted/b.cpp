#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

bool u[1100];
vi G[1100];

int dfs (int v)
{
  multiset<int> S;
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      S.insert(dfs(G[v][i]));
  if ((int)S.size()<=1)
    return 1;
  int res=1;
  multiset<int>::iterator it=S.end();
  for (int i=0; i<2; i++)
    it--, res+=(*it);
  return res;
}

void solve (int tst)
{
  cerr<<"tst="<<tst<<endl;
  printf("Case #%d: ", tst);
  int res=0, i, v1, v2, n;
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  for (i=0; i<n; i++)
    res=max(res,dfs(i)), memset(u,0,sizeof(u));
  res=n-res;
  printf("%d\n", res);
  for (i=0; i<n; i++)
    G[i].clear();
}
               
int main()
{
  int tst;
  #ifdef LOCAL
  freopen(TASKNAME"in","r",stdin);
  freopen(TASKNAME"out","w",stdout);
  #endif
  scanf("%d", &tst);
  for (int cnt=1; cnt<=tst; cnt++)
    solve(cnt);  
  TIMESTAMP(end);
  return 0;
}
