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
  freopen("Csmall.out","w",stdout);
  freopen("Csmall.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n;
    cin>>n;
    VI v(n);
    FOR(i,n) cin>>v[i];
    ll cont=0;
    FOR(i,n) cont+=i*v[i];
    cout<<"Case #"<<cas<<": ";
    if(cont<252500000) cout<<"GOOD"<<endl;
    else cout<<"BAD"<<endl;
  }
}
