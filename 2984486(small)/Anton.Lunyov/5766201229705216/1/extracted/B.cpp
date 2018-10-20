#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 1010
VI a[N];
int mark[N];
int p[N];
int w[N];

void dfsW(int u) {
  mark[u]=1;
  w[u]=1;
  for(int i=a[u].sz;i--;) {
    int v=a[u][i];
    if(!mark[v]) {
      p[v]=u;
      dfsW(v);
      w[u]+=w[v];
    }
  }
}

int dp[N];
void dfsDP(int u) {
  dp[u] = w[u]-1;
  VI dif;
  for(int i=a[u].sz;i--;) {
    int v = a[u][i];
    if(v==p[u]) continue;
    dfsDP(v);
    dif.pb(w[v]-dp[v]);
  }
  if(dif.sz<2) return;
  sort(all(dif));
  reverse(all(dif));
  dp[u] -= dif[0] + dif[1];
}

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i].cl;
    for(int i=1;i<n;i++) {
      int u,v;
      scanf("%d%d",&u,&v);
      a[u].pb(v);
      a[v].pb(u);
    }
    int res = inf;
    for(int root=1;root<=n;root++) {
      fill(mark,0);
      fill(p,0);
      fill(dp,0);
      dfsW(root);
      dfsDP(root);
      MIN(res, dp[root]);
    }
    printf("%d\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
