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

int main(){
//  ios_base::sync_with_stdio(false);
  freopen("A-small.out","w",stdout);
  freopen("A-small.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n,l;
    cin>>n>>l;
    VI o(n),e(n);
    string s;
    FOR(i,n){
      cin>>s;
      FOR(j,s.size()) {
        e[i]*=2;
        e[i]+=int(s[j]-'0');
      }
    }
    FOR(i,n){
      cin>>s;
      FOR(j,s.size()) {
        o[i]*=2;
        o[i]+=int(s[j]-'0');
      }
    }
    sort(e.begin(),e.end());
    int millor=l+1;
    FOR(S,(1<<l)){
      int uns=0;
      int SS=S;
      while(SS) {uns+=(SS&1); SS=(SS>>1);}
      if(uns>=millor) continue;
      VI oo(n);
      FOR(i,n) oo[i]=o[i]^S;
      sort(oo.begin(),oo.end());
      if(oo==e) millor=uns;
    }
    cout<<"Case #"<<cas<<": ";
    if(millor==l+1) cout<<"NOT POSSIBLE"<<endl;
    else cout<<millor<<endl;
  }
}
