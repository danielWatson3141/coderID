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

void transform(VI& a) {
  int n = a.sz;
  int m = n/2;
  for(int i=0;i<n;i++)
    a[i] = a[i]/m*m + (a[i]+m-1) % m;
}

int cycles(const VI& a) {
  int n = a.sz;
  VI mark(n);
  int cnt=0;
  for(int i=0;i<n;i++) if(!mark[i]) {
    for(int j=i;!mark[j];j=a[j])
      mark[j]=1;
    cnt++;
  }
  return cnt;
}

bool good(VI a) {
  transform(a);
  return cycles(a) < 8;
}

namespace foo {

const int N = 10;
int n;
map<VI, int> prob;
VI a;
void gen(int i) {
  if(i==n) {
    prob[a]++;
    return;
  }
  for(int j=0;j<n;j++) {
    swap(a[i],a[j]);
    gen(i+1);
    swap(a[i],a[j]);
  }
}

void research() {
  freopen("help.txt","w",stdout);
  for(n=4;n<=8;n+=2) {
    int m=n/2;
    printf("\nn=%d\n",n);
    a = VI(n);
    int fac=1,pw=1;
    for(int i=0;i<n;i++) {
      fac *= i+1;
      pw *= n;
      a[i]=i;
    }
    prob.cl;
    gen(0);
    vector<pair<int, VI> > perms;
    for(map<VI, int>::iterator it = prob.begin(); it != prob.end(); ++it)
      perms.pb(mp(it->Y,it->X));
    sort(all(perms));
    reverse(all(perms));
    int wrong=0;
    for(int j=0;j<fac;j++) {
      VI a = perms[j].Y;
      transform(a);
      for(int i=0;i<n;i++) printf("%d ", a[i]);
      bool isGood = perms[j].X * fac < pw;
      int cnt = cycles(a);
      bool guess = cnt < m;
      printf(": %s   %d\n", isGood ? "GOOD" : "BAD ", cycles(a));
      if(isGood!=guess) wrong++;
    }
    fprintf(stderr,"n=%d wrong=%d fact=%d\n",n,wrong,fac);
  }
  exit(0);
}

}

#define N 1010

int main()
{
  //foo::research();
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
  int cnt=0;
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n;
    scanf("%d",&n);
    VI a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    bool isGood = good(a);
    puts(isGood?"GOOD":"BAD");
    if(isGood) cnt++;
	}
  fprintf(stderr,"cnt=%d\n",cnt);
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
