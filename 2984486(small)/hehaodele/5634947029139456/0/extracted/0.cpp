#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
#include "map"
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
long long a[maxn], b[maxn], c[maxn];
map<long long,bool> M;
char s[100];
void get(long long &x){
	scanf("%s", s);
	x = 0;
	rep(i, L) x<<=1, x += s[i]-'0';
}
int my(long long x, int n){
	return ((x>>n)&1);
}
bool chk(){

}
int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		n = getint(), L = getint();
		rep(i, n) get(a[i]);
		rep(i, n) get(b[i]);
		sort(b, b+n);
		int ans = L+1;
		rep(i, n){
			int tot = 0;
			rep(j, L) if( my(a[0],j)!=my(b[i],j) ) tot++;
			bool ok = 1;
			long long dif = a[0]^b[i];
			rep(j, n) c[j] = dif ^ a[j];
			sort(c, c+n);
			rep(j, n) if(c[j]!=b[j]){ok = 0;break;}
			if(ok) ans = min(ans, tot);
		}
		printf("Case #%d: ",cas);
		if(ans < L+1) printf("%d\n", ans); else printf("NOT POSSIBLE\n");
	}
	return 0;
}