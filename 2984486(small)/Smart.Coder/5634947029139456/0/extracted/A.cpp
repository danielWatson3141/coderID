//A.cpp
//SmartCoder
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end();i++)
#define present(c,x)  ( (c).find(x) !=(c).end())
#define cpresent(c,x) (find(all(c),x)!= (c).end() )
#define minei(x)  min_element(x.begin(),x.end())-(x).begin()
#define maxei(x)  max_element(x.begin(),x.end())-(x).begin()

#define uns(v)     sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define acusum(x)  accumulate(x.begin(),x.end(),0)
#define acumul(x)  accumulate(x.begin(),x.end(),1, multiplies<int>()); 
#define bits(x)     __builtin_popcount( x )
#define oo INT_MAX
#define inf 1000000000

const double pi=acos(-1.0);
const double eps=1e-11;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char flip(char a){
  if(a=='0') return '1';
  else return '0';
}
int main(){
  //std::ios_base::sync_with_stdio(0);
  freopen("output.txt","w",stdout);
  freopen("input.txt","r",stdin);
  int tc,x,d,N,L;
  string s;
  cin>>tc;
  for(int k=1;k<=tc;++k){
    cin>>N>>L;
    vector<string> Outlet,Device;
    for(int j=0;j<N;++j){
      cin>>s;
      Outlet.pb(s);
    }
    for(int j=0;j<N;++j){
      cin>>s;
      Device.pb(s);
    }
    int mn=inf;
    sort(all(Outlet));
    sort(all(Device));
    for(int i=0;i<1<<L;++i){
      vector<string> OutletTemp=Outlet;
      for(int j=0;j<L;++j){
        if((i&(1<<j))!=0){
          for(int l=0;l<N;++l){
            OutletTemp[l][j]=flip(OutletTemp[l][j]);
          }
        }
      }
      sort(all(OutletTemp));
      sort(all(Device));
      if(OutletTemp==Device) mn=min(mn,bits(i));
    }
    if(mn==inf) printf("Case #%d: NOT POSSIBLE",k);
    else printf("Case #%d: %d",k,mn);
    if(k!=tc)printf("\n");

  }
  return 0;
}
