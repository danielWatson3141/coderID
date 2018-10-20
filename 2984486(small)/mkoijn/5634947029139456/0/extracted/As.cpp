#include<iostream>
#include<complex>
#include<vector>
#include<string>

#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<sstream>
#include<unistd.h>
#include<valarray>
#include<numeric>
#include<algorithm>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>

#include<fstream>
#include<time.h>
using namespace std;

#define NDEBUG
#include<assert.h>
#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MOD(A,B) (((A)%(B)+(B))%(B))
#define MP make_pair
#define FI first
#define SE second
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define RFOREACH(I,C) for(VAR(I,(C).rbegin());I!=(C).rend();I++)
#define ALL(X) (X).begin(),(X).end()
#define SRT(X) sort((X).begin(),(X).end())
#define CLC(ACT,V) (*({ACT;static __typeof(V) ret;ret=(V);&ret;}))
#define FIRST(P,A,B,COND) CLC(VAR(P,A);for(;P<(B);++P)if(COND)break,P)
#define LAST(P,A,B,COND) CLC(VAR(P,B);while((A)<=(--P))if(COND)break,P)
#define EXISTS(P,A,B,COND) (FIRST(P,A,B,COND)<(B))
#define FORALL(P,A,B,COND) (!(EXISTS(P,A,B,!(COND))))
#define EXISTSI(I,C,COND) CLC(VAR(I,(C).begin());for(;I!=(C).end();I++)if(COND)break,I)!=(C).end()
#define FORALLI(I,C,COND) (!(EXISTSI(I,C,!(COND))))
#define PB push_back
#define PF(I,V) V.insert(V.begin(),I)
#define EB(V) V.erase(V.rbegin());
#define EF(V) V.erase(V.begin());
#define SGN(X) (((X)>0)?1:(((X)<0)?-1:0))
#define LD(X) ((ld)(X))
#define LL(X) ((ll)(X))
#define BIT_CHECK(X,N) (X&(1<<N))
#define BIT_SET(X,N) (X|=(1<<N))
#define BIT_CLEAR(X,N) (X&=~(1<<N))
#define BIT_TOGGLE(X,N) (X^=(1<<N))
#define BIT_LOWEST(X) (__builtin_ffsll((unsigned long long)X))
#define BIT_COUNT(X) (__builtin_popcountll((unsigned long long)X))
template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}

typedef vector<string> VS;
typedef vector<int> VI;

inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

int T, N, L;

inline int comp(string d, string g, int m){
  int ret=m;
  FOR(i,0,L-1) if(BIT_CHECK(m,i)){
    if(d[i]==g[i]){
      ret=-1;
      break;
    }
  } else {
    if(d[i]!=g[i]){
      BIT_SET(ret,i);
    }
  }
  return ret;
}

int main(){
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    VI ps=parsei(line);
    N=ps[0], L=ps[1];
    getline(cin, line);
    VS ol=parse(line);
    getline(cin, line);
    VS d=parse(line);
    
    int ret=100;
    SRT(ol);
    
      int m=0;
      do {
        m=0;
        FOR(j,0,N-1){
          int x=comp(d[j],ol[j],m);
          m=x;
          if(x==-1) break;
        }
        if(m!=-1){
          int w=BIT_COUNT(m);
          ret=MIN(ret,w);
        }
      } while (next_permutation(ol.begin(),ol.end()));

    
    if(ret==100){
      printf("Case #%d: NOT POSSIBLE\n", tt);
    } else printf("Case #%d: %d\n", tt, ret);
  }

  return 0;
}

