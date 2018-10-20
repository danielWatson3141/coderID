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
typedef pair<double,int> P;
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
int n;
int ans[1100];
int main(){
  int times;
  cin>>times;
  vector<P> vec;
  for(int t=1; t<=times;t++){
    cin>>n;
    int cnt=0;
    vector<int> v;
    for(int i=0;i<n;i++){
      int a;
      cin>>a;
      v.push_back(a);
    }
    for(int i=0;i<n;i++){
      if(v[v[v[i]]]==i)cnt++;
    }
    vec.push_back(P((double)cnt/(double)n, t));
  }
  SORT(vec);
  for(int i=0;i<(int)vec.size()/2;i++){
    ans[vec[i].second-1]=1;
  }
  for(int t=1; t<=times;t++){
    if(ans[t-1]==1){
      printf("Case #%d: GOOD\n", t);
    }else{
      printf("Case #%d: BAD\n", t);
    }
  }
}
