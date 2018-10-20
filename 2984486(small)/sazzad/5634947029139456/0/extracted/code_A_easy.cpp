
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <limits>
#include <utility>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;

const int INF=(1<<30)-1;
const long long LINF=(1ll<<62)-1;
const int DIRX[]={-1,0,0,1,-1,-1,1,1}, DIRY[]={0,-1,1,0,-1,1,-1,1};
const double ERR=1e-11, PI=(2*acos(0.0));

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
template<class T> inline T MIN(T a,T b) {return ((a<b)?(a):(b));}
template<class T> inline T MAX(T a,T b) {return ((b<a)?(a):(b));}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> inline T SQR(T x) {return (x*x);}
template<class T> inline T GCD(T a,T b) {T c; while((c=a%b)!=0)a=b,b=c; return b;}
template<class T> inline T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&1)Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> inline T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&1)Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}

#define ALL(X)       (X).begin(),(X).end()
#define SIZE(X)      ((int)(X).size())
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define EACH(X,itr)  for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item))!=(X).end())

typedef unsigned long long ULL;
typedef long long      LL;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL>     VL;
typedef vector<int>    VI;
typedef pair<int,int>  Pii;

multiset<int> a,b,c;

inline int bc(LL x) {
    int r=0;
    while(x) {
        r += x&1ll;
        x>>=1;
    }
    return r;
}

char s[55];
inline LL getNum() {
    scanf(" %s",s);
    LL x=0;
    for(int i=0;s[i];i++) {
        x = x*2 + s[i]-'0';
    }
    return x;
}

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int cases,caseno;
	int n,l,ans;
	LL L,k;
	scanf("%d",&cases);
	for(caseno=1;caseno<=cases;caseno++) {
        scanf(" %d %d",&n,&l);
        a.clear();
        for(int i=0;i<n;i++) a.insert(getNum());
        b.clear();
        for(int i=0;i<n;i++) b.insert(getNum());
        
        L = 1<<l;
        ans = l+1;
        for(k=0;k<L;k++)if(bc(k)<ans) {
            c.clear();
            EACH(a,i) {
                c.insert((*i)^k);
            }
            if(c==b) ans=bc(k);
        }
        printf("Case #%d: ",caseno);
        if(ans>l) printf("NOT POSSIBLE");
        else printf("%d",ans);
        puts("");
	}
	
	return 0;
}
