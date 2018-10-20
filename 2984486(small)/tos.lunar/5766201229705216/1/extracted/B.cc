#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

#define iter(c) __typeof((c).begin())

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define repd(i,n) for(int i=(int)(n); i-->0;)
#define repi(i,a,b) for(int i=(int)(a); i<=(int)(b); i++)
#define times(n) for(int __times=(n); __times-->0;)
#define each(i, c) for (iter(c) i = (c).begin(); i != (c).end(); ++i)

#define all(a) (a).begin(),(a).end()
#define elem(e, c) (find(all(c), (e)) != (c).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define INF 1001001001
#define INFTY (INF<<32LL|INF)
#define EPS 1e-9
#define PI 3.141592653589793

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<double> vd;
typedef vector<string> vs;

template <class T>
void debug(vector<T> v){ each(i,v.size()) cout<<*i<<" "; cout<<endl; }

int nextInt(){ int t; scanf("%d", &t); return t; }
string next(){ string t; cin>>t; return t; }

vvi childs;
// int cnt[1010][1010];
int dp[1010][1010];

void go(int x, int y){
  if(dp[x][y]>=0) return;

  vi foo;
  // cnt[x][y]=1; // x itself
  rep(i,childs[x].size()){
    int z=childs[x][i];
    if(z==y) continue;
    go(z,x);
    // cnt[x][y]+=cnt[z][x];
    foo.pb(dp[z][x]);
  }
  if(foo.size()==0){
    dp[x][y]=1;
  }else if(foo.size()==1){
    dp[x][y]=1;
  }else{
    sort(all(foo));
    dp[x][y]=1+foo[foo.size()-1]+foo[foo.size()-2];
  }
  //cout<<x<<" "<<y<<" "<<cnt[x][y]<<" "<<dp[x][y]<<endl;
  return;
}

int solve(int N, vi &X, vi &Y){
  childs.clear();
  childs.resize(N);
  rep(i,N-1){
    int x=X[i];
    int y=Y[i];
    childs[x].pb(y);
    childs[y].pb(x);
    dp[x][y]=-1;
    dp[y][x]=-1;
  }
  rep(x,N){
    dp[x][N]=-1;
  }
  rep(x,N){
    go(x,N);
  }
  int answer = 0;
  rep(x,N){ // maximum
    if(dp[x][N]>answer) answer=dp[x][N];
  }
  return N-answer;
}

int main(){
  int T=nextInt();
  repi(cases,1,T){
    int N=nextInt();
    vi X,Y;
    rep(i,N-1){
      X.pb(nextInt()-1);
      Y.pb(nextInt()-1);
    }
    cout<<"Case #"<<cases<<": ";
    cout<<solve(N,X,Y);
    cout<<endl;
  }
  return 0;
}
