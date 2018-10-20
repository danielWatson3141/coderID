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
bool adj[1100][1100];
int visit[1100];
int cnt[1100];
int child[1100];
int dfs(int p){
  //cout<<"At "<<p<<endl;
  visit[p]=1;
  cnt[p]=0;
  vector<int> v,nd;
  vector<P> mr;
  for(int i=0;i<n;i++){
    if(adj[p][i] && visit[i]==0){
      //cout<<p+1<<" "<<i+1<<"connected"<<endl;
      v.PB(dfs(i));
      nd.PB(i);
      mr.PB(P(cnt[i]-child[i],i));
      child[p]+=1+child[i];
    }
  }
  SORT(mr);
  if(v.size()==0){
    cnt[p]=0;
  }else if(v.size()==1){
    //cout<<"child"<<p+1<<" "<<nd[0]+1<<endl;
    cnt[p]=1+child[nd[0]];
  }else if(v.size()==2){
    cnt[p]=min(cnt[nd[0]]+cnt[nd[1]],2+child[nd[0]]+child[nd[1]]);
  }else{
    cnt[p]+=cnt[mr[0].second];
    cnt[p]+=cnt[mr[1].second];
    for(int i=2;i<(int)mr.size();i++){
      cnt[p]+=1+child[mr[i].second];
    }
  }
  //cout<<p+1<<" "<<cnt[p]<<endl;
  return cnt[p];
}
int main(){
  cin>>times;
  for(int t=1; t<=times;t++){
    cin>>n;
    int ans=n-1;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)adj[i][j]=false;
    for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;a--;b--;
      adj[a][b]=(adj[b][a]=true);
    }
    for(int rt=0;rt<n;rt++){
      for(int i=0;i<n;i++){
        cnt[i]=-1;
        visit[i]=0;
        child[i]=0;
      }
      visit[rt]=0;
      dfs(rt);
      ans=min(ans,cnt[rt]);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
