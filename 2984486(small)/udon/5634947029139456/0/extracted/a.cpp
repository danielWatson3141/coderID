#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<sstream>
#include <string>
#include <vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef vector<VI > VII;
typedef vector<VL > VLL;
#define INF 1000000010
#define MOD 1000000007
#define EPS 1e-9
#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define sz(a) (a).size()
#define len(a) (a).length()
#define rep(i,n) for(int i=0;i<(int) n;i++)
#define MP make_pair
#define SORT(a) sort(ALL(a))
ll mod(ll a,ll m){return (a%m+m)%m;}
int dx[9]={0,1,0,-1,1,1,-1,-1,0},dy[9]={1,0,-1,0,1,-1,1,-1,0};
int n,t,l,times;
char init[160][160],last[160][160];
int main(){
  cin>>times;
  for(int t=1; t<=times;t++){
    cin>>n>>l;
    int ans=INF;
    for(int i=0;i<n;i++){
      for(int j=0;j<l;j++){
        cin>>init[i][j];
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<l;j++){
        cin>>last[i][j];
      }
    }
    vector<ll> lst;
    for(int i=0;i<n;i++){
      ll t=0LL;
      for(int j=0;j<l;j++){
        if(last[i][j]=='1'){
          t |= (1LL<<(l-1-j));
        }
      }
      lst.push_back(t);
    }
    SORT(lst);
    for(int i=0;i<n;i++){
      int change[160];
      int cnt=0;
      for(int j=0;j<l;j++){
        change[j]=0;
        if(init[0][j]!=last[i][j]){
          change[j]=1;cnt++;
        }
      }
      if(cnt>ans)continue;
      vector<ll> vec;
      for(int j=0;j<n;j++){
        ll t=0LL;
        for(int k=0;k<l;k++){
          if((init[j][k]=='1'&&change[k]==0)
             ||(init[j][k]=='0'&&change[k]==1)){
            t |= (1LL<<(l-1-k));
          }
        }
        vec.push_back(t);
      }
      SORT(vec);
      if(lst==vec){
        ans=min(ans,cnt);
      }
    }
    if(ans==INF){
      printf("Case #%d: NOT POSSIBLE\n", t);
    }else{
      printf("Case #%d: %d\n", t, ans);
    }
  }
  
  return 0;
}
