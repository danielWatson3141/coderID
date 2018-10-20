#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

//ハマったらチェックリスト見ろ!!

char out[10][10];
char in[10][10];

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout << "Case #"<<tc+1<<": ";
    int N, L;
    cin >> N >> L;
    rep(i, N)rep(j, L)cin>>out[i][j];
    rep(i, N)rep(j, L)cin>>in[i][j];
    int ans = 1e9;
    rep(i, (1<<L)){
      bitset<12> B(i);
      vector<vector<char> > IV, OV;
      rep(j, N){
	vector<char> tmpI, tmpO;
	rep(k, L){
	  if(B[k]){
	    if(in[j][k] == '0')tmpI.push_back('1');
	    else tmpI.push_back('0');
	  }
	  else{
	    tmpI.push_back(in[j][k]);
	  }
	  tmpO.push_back(out[j][k]);
	}
	IV.push_back(tmpI);
	OV.push_back(tmpO);
      }
      sort(ALL(IV));
      sort(ALL(OV));
      if(IV == OV){
       ans = min(ans, __builtin_popcount(i));
      }
    }
    if(ans == 1e9)cout << "NOT POSSIBLE" <<endl;
    else cout << ans << endl;
  }
  
  return 0;
}
