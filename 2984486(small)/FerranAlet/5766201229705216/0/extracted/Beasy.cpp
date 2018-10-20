//Done by Mycroft Grey
//Fet per Ferran Alet

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<numeric>
#include<set>
#include<sstream>
#include<list>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;

int cont;

bool rooted(VVI &v,int S, int pos, int pare){
  ++cont;
  int fills=0;
  for(int i=0;i<v[pos].size();++i) {
    if(v[pos][i]!=pare && ((1<<v[pos][i])&S)!=0) ++fills;
  }
  if(fills==0) return true;
  if(fills!=2) return false;
  for(int i=0;i<v[pos].size();++i) {
    if(v[pos][i]!=pare && ((1<<v[pos][i])&S)!=0 && !rooted(v,S,v[pos][i],pos)) return false;
  }  
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  freopen("B-small.out","w",stdout);
  freopen("B-small.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n,a,b;
    cin>>n;
    VVI v(n);
    FOR(i,n-1) {
      cin>>a>>b;
      --a; --b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int millor=0;
    for(int S=0;S<(1<<n);++S){
      int uns=0;
      int SS=S;
      while(SS) {uns+=(SS&1); SS=(SS>>1);}
      if(uns<=millor) continue;
      bool ok=false;
      for(int i=0;i<n && !ok;++i) {
        if((S&(1<<i))==0) continue;
        cont=0;
        if(rooted(v,S,i,-1)) {
          if(cont==uns) ok=true;
        }
       // debug(cont);
      }
      //cerr<<S<<' '<<ok<<endl;
      if(ok) {
        millor=uns;
        //cerr<<S<<' '<<uns<<endl;
      }
    }
    cout<<"Case #"<<cas<<": "<<n-millor<<endl;
   // cerr<<n-millor<<endl;
  }
  //system("pause");
}
