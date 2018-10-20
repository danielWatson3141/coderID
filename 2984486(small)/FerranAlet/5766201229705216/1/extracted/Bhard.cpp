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

VVI v;
VVI res;

int fun(int pos,int pare){
  if(pare!=-1 && res[pos][pare]!=-1) return res[pos][pare];
  int fillp=0,fillg=0;
  for(int i=0;i<v[pos].size();++i) {
    if(v[pos][i]!=pare) {
      int aux=fun(v[pos][i],pos);
      if(aux>fillp){
        if(aux>fillg) {fillp=fillg; fillg=aux;}
        else fillp=aux;
      }
    }
  }
  if(fillp==0) return res[pos][pare]=1;
  else return res[pos][pare]=1+fillp+fillg;
}

int main(){
  ios_base::sync_with_stdio(false);
  freopen("B-large.out","w",stdout);
  freopen("B-large.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n,a,b;
    cin>>n;
    v=VVI (n);
    res= VVI(n, VI(n,-1));
    FOR(i,n-1) {
      cin>>a>>b;
      --a; --b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int millor=0;
    FOR(i,n){
      millor=max(millor,fun(i,-1));
    }
    cout<<"Case #"<<cas<<": "<<n-millor<<endl;
   // cerr<<n-millor<<endl;
  }
  //system("pause");
}
