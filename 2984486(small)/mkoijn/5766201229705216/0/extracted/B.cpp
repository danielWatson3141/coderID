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
typedef stack<int> SI;
typedef vector<vector<int> > VVI;

const int INF=0x7f7f7f7f;

inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

int T, N;
VVI g;
VI vis(1000,0);
VI siz(1000,1);
map<int,int> q;
  
inline void dfs1(int r){
  SI s;
  s.push(r);
  q.clear();

  while(!s.empty()){
    int t=s.top();
    //s.pop();
    //if(!vis[t]){
      vis[t]=1;
      int c=0;
      FOR(i,0,SZ(g[t])-1) if(!vis[g[t][i]]) {
        s.push(g[t][i]);
        q[g[t][i]]=t;
        c++;
      }
      if(c==0){
        s.pop();
        int a=0;
        FOR(i,0,SZ(g[t])-1){
          if(q.find(t)==q.end() || g[t][i]!=q[t]) a+=siz[g[t][i]];
        }
        siz[t]+=a;
      }
    /*}
    else {
      s.pop();
    }*/
  }
}

#define DEBUG 0

int rem=0;

inline void dfs2(int r){
  SI s;
  s.push(r);
  VI siz2=siz;
  
  while(!s.empty()){
    int t=s.top();
    //s.pop();
    //if(!vis[t]){
      vis[t]=1;
      int c=0;
      FOR(i,0,SZ(g[t])-1) if(!vis[g[t][i]]) {
        s.push(g[t][i]);
        c++;
      }
      if(c==0){
        s.pop();
        VI pom;
        FOR(i,0,SZ(g[t])-1){
          if(q.find(t)==q.end() || g[t][i]!=q[t]) pom.PB(siz2[g[t][i]]);
        }
        SRT(pom);
        if(SZ(pom)==1){
          rem+=pom[0];
          siz2[t]=1;
          if(DEBUG) printf("usuwamy w %d  %d\n",t,pom[0]);
        } else if(SZ(pom)>1){
          FOR(i,0,SZ(pom)-3){
            rem+=pom[i];
            siz2[t]-=pom[i];
            if(DEBUG) printf("usuwamy w %d  %d\n",t,pom[i]);
          }
        }
      }
    /*}
    else {
      s.pop();
    }*/
  }
  if(DEBUG) {
    FOR(i,0,N-1) printf("%d ", siz2[i]); printf("\n%d\n",rem);
  }
}
int main(){
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    g.clear();
    getline(cin, line);
    VI ps=parsei(line);
    N=ps[0];
    VI pom;
    FOR(i,1,N) g.PB(pom);
    FOR(i,0,N-2){
      getline(cin, line);
      ps=parsei(line);
      g[ps[0]-1].PB(ps[1]-1);
      g[ps[1]-1].PB(ps[0]-1);
      vis[i]=0;
      siz[i]=1;
    }
    vis[N-1]=0;
    siz[N-1]=1;
    

    
   /* FOR(i,0,N-1) printf("%d ", siz[i]); printf("\n");
    FOR(i,0,N-1) printf("%d ", q[i]); printf("\n");*/
    int ret=INF;
    
    FOR(i,0,N-1){
      FOR(j,0,N-1) vis[j]=0;
      FOR(j,0,N-1) siz[j]=1;
      rem=0;
      dfs1(i); q[i]=-1;
      FOR(j,0,N-1) vis[j]=0;
      dfs2(i);
      ret=MIN(ret,rem);
    }
    if(N==2) ret=2;
    printf("Case #%d: %d\n", tt, ret);
  }

  return 0;
}

