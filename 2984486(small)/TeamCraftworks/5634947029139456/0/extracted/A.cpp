#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;

int N,L;
map<string,int> counter;

int calc(vector<string> &cur, vector<string> &next,int np,int cp){
  string cs = cur[cp], ns = next[np];
  string SWAP = "";
  int cost = 0;
  rep(i,L) if( cs[i] != ns[i] ) SWAP += "1", cost++; else SWAP += "0";
  map<string,int> checker;
  rep(i,N){
    string tmp = cur[i];
    rep(j,L) if( SWAP[j] == '1' ) tmp[j] = ((tmp[j]=='1')?'0':'1');
    checker[tmp]++;
  }

  if( checker == counter ) return cost;
  return IINF;
}

int main(){
  int T,CNT = 1;
  cin >> T;
  while(T--){
    cin >> N >> L;
    counter.clear();
    vector<string> cur(N),next(N);
    rep(i,N)cin>>cur[i];
    rep(i,N){
      cin>>next[i];
      counter[next[i]]++;
    }

    cout << "Case #" << CNT++ << ": ";
    int ans = IINF;
    rep(i,N){ // which next do I use?
      rep(j,N){  // which cur do I set to next[i]? 
        int cost = calc(cur,next,i,j);
        ans = min(ans,cost);
      }
    }
    if( ans == IINF ) puts("NOT POSSIBLE");
    else cout << ans << endl;

  }
  return 0;
}
