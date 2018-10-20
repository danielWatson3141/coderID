#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 20;

vector<int> G[MAX_N];
bool ok[MAX_N];
int N;

bool isFullBin( int cur, int pre ){

  int cnt = 0;
  rep(i,G[cur].size()){
    if( G[cur][i] == pre ) continue;
    if( !ok[G[cur][i]] ) continue;
    cnt++;
  }

  if ( cnt == 0 || cnt == 2 ) {
  rep(i,G[cur].size()){
    if( G[cur][i] == pre ) continue;
    if( !ok[G[cur][i]] ) continue;
    if( !isFullBin(G[cur][i],cur) ) return false;
  }
  return true;
  } else return false;

}

bool vis[MAX_N];
void connected(int cur){
  if(vis[cur])return;
  vis[cur] = true;
  rep(i,G[cur].size()){
    int next = G[cur][i];
    if(!ok[next])continue;
    if(!vis[next])connected(next);
  }
}

int main(){
  int T,CNT = 1;
  cin >> T;
  while( T-- ){
    cin >> N;
    rep(i,N)G[i].clear();
    rep(i,N-1){
      int a,b;
      cin >> a >> b;
      a--,b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    //rep(i,N)ok[i] = true;
    //cout << isFullBin(1,-1) << endl;
    //return 0;
    int ans = IINF;
    rep(i,(1<<N)){

      int cnt = 0;
      int sp = 0;
      rep(j,N){
        if( (i>>j) & 1 ) ok[j] = true,cnt++,sp=j;
        else             ok[j] = false;
        vis[j] = false;
      }

      connected(sp);
      bool ch = true;
      rep(j,N){
        if( ok[j] && !vis[j] ){
          ch = false;
          break;
        }
      }
      if( !ch ) continue;

      bool ye = false;
      rep(root,N){
        if( !ok[root] ) continue;

        if( isFullBin(root,-1) ){
          ye = true;
          break;
        }
      }

      if( ye ){
        ans = min(ans,N-cnt);
      }
    }

    cout << "Case #" << CNT++ << ": " << ans << endl;
  }
  return 0;
}
