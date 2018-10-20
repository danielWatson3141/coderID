#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
#include "map"
#include "time.h"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
inline int getint(){
  char c = getchar();
  for(;c<'0'||c>'9';) c = getchar();
  int x = 0;
  for(;c>='0' && c<='9'; c = getchar()) x*=10, x+=c-'0';
  return x;
}
const int maxn = 210;
int n,m,k,x,y,L;
double S, S2;
int a[1000];
void ran1(){
	rep(i,n) a[i] = i;
	rep(i,n){
		int p = rand()%(n-i) + i;
		swap(a[i], a[p]);
	}
	int s = 0;
	int s2 = 0;
	rep(i,n) s += (a[i]>i);
	rep(i,n) s2 += (a[i]-i)*(a[i]-i);
	printf("%d %d\n", s,s2);
	S += s, S2 += s2;
}
void ran2(){
	rep(i,n) a[i] = i;
	rep(i,n){
		int p = rand()%n;
		swap(a[i], a[p]);
	}
	int s = 0;
	int s2 = 0;
	rep(i,n) s += (a[i]>i);
	rep(i,n) s2 += (a[i]-i)*(a[i]-i);
	printf("%d %d\n", s,s2);
	S += s, S2 += s2;
}
int main(int argc, char const *argv[])
{
	int cass = getint();
	int bad = 0;
	repp(cas,1,cass){
		n = getint();
		int s = 0, ss = 0;
		rep(i,n) a[i] = getint();
		rep(i,n) s += (a[i]>i);		
		rep(i,n) ss += (a[i]-i)*(a[i]-i);
		printf("Case #%d: ",cas);
		if(s>n/2+19 || ss < 160214413.58000){
			printf("BAD\n"); bad ++;
		}else printf("GOOD\n");
	}
	//	printf("%d\n", bad);

	/*	
	srand((unsigned int)time(NULL));
	n = 1000;
	S = S2 = 0;
	rep(i, 100) ran1(); 
		printf("%.5lf %.5lf\n", S/100, S2/100); printf("========\n");
	S = S2 = 0;
	rep(i, 100) ran2();	
		printf("%.5lf %.5lf\n", S/100, S2/100); printf("========\n");
	*/
	return 0;
}