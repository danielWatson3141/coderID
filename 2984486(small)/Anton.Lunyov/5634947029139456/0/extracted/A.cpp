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

#define N 155
#define M 44

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(cin >> TST;TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n,m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(all(b));
    int res = inf;
    for(int mask=0;mask<bit(m);mask++) {
      int cnt=0;
      for(int j=0;j<m;j++)
        if(mask & bit(j)) cnt++;
      if(res <= cnt) continue;
      vector<string> c(n);
      for(int i=0;i<n;i++) {
        c[i] = a[i];
        for(int j=0;j<m;j++)
          if(mask & bit(j))
            c[i][j] ^= '0'^'1';
      }
      sort(all(c));
      if(b==c) res=cnt;
    }
    if(res==inf) puts("NOT POSSIBLE"); else
      printf("%d\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
