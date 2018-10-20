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
#define debug(x) //cerr << #x << " = " << x << endl
#define Debug(v) //cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
using namespace std;


typedef long long ll;
typedef pair<ll,ll> PII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<ll,ll> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;


int main(){
  ios_base::sync_with_stdio(false);
  freopen("A-large.out","w",stdout);
  freopen("A-large.in","r",stdin);
  ll casos;
  cin>>casos;
  FORU(cas,casos){
    ll n,l;
    cin>>n>>l;
    VI o(n),e(n);
    string s;
    VI ue(l);
    VI uo(l);
    FOR(i,n){
      cin>>s;
      FOR(j,s.size()) {
        e[i]*=2;
        e[i]+=ll(s[j]-'0');
        ue[j]+=ll(s[j]-'0');
      }
    }
    FOR(i,n){
      cin>>s;
      FOR(j,s.size()) {
        o[i]*=2;
        o[i]+=ll(s[j]-'0');
        uo[j]+=ll(s[j]-'0');
      }
    }
    ll millor=l+1;
    VI he;
    FORU(i,n-1) he.push_back(e[i]);
    sort(he.begin(),he.end());
   // Debug(he);
    FOR(i,n){
      //debug(i);
      ll S=(e[0]^o[i]);
      //debug(S);
      ll uns=0;
      ll SS=S;
      while(SS) {uns+=(SS&1); SS=(SS>>1);}
      //debug(uns);
      if(uns>=millor) continue;
      VI ho;
      FOR(j,n){
        if(j!=i) ho.push_back(o[j]);
      }
      //Debug(ho);
      FOR(j,ho.size()) ho[j]^=S;
      //Debug(ho);
      sort(ho.begin(),ho.end());
      if(ho==he) millor=uns;
    }
    cout<<"Case #"<<cas<<": ";
    if(millor==l+1) cout<<"NOT POSSIBLE"<<endl;
    else cout<<millor<<endl;
  }
  system("pause");
}
