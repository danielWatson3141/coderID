//B.cpp
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
bool vis[1111];
int degree[1111];
int Orgdegree[1111];
vector<int> adj[1111];
int dfs(int node){
  vis[node]=1;
  int rs=1;
  if(degree[node]==2){
    for(int i=0;i<sz(adj[node]);++i){
      if(!vis[adj[node][i]]){
        degree[adj[node][i]]--;
        rs+=(dfs(adj[node][i]));
      }
    }
  }
  return rs;
}
int main(){
  std::ios_base::sync_with_stdio(0);
  freopen("output.txt","w",stdout);
  freopen("input.txt","r",stdin);
  int tc,n,x,y;
  cin>>tc;
  for(int T=1;T<=tc;++T){
    cin>>n;
    int mn=inf;
    memset(Orgdegree,0,sizeof Orgdegree);
    memset(vis,0,sizeof vis);
    memset(degree,0,sizeof degree);
    for(int i=0;i<n;++i){
      adj[i].clear();
    }
    for(int i=0;i<n-1;++i){
      cin>>x>>y;
      x--;
      y--;
      Orgdegree[x]++;
      Orgdegree[y]++;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    for(int i=0;i<n;++i){
      memset(vis,0,sizeof vis);
      //copy degree
      for(int j=0;j<n;++j){
        degree[j]=Orgdegree[j];
      }
      mn=min(mn,n-dfs(i));

    }
    printf("Case #%d: %d\n",T,mn);
  }
  return 0;
}
