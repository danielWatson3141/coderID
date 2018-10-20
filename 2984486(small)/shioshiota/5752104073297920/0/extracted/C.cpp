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


const int N = 1000;
void good(){
  vector<int> V(N);
  rep(i, N){
    V[i] = i;
  }
  rep(k, N){
    int p = rand()%(N-k) + k;
    swap(V[k], V[p]);
  }
  int cnt = 0;
  rep(i, 500){
    if(V[i] <500)cnt++;
  }
  cout << cnt << endl;
}

void bad(){
  vector<int> V(N);
  rep(i, N){
    V[i] = i;
  }
  rep(k, N){
    int p = rand()%(N);
    swap(V[k], V[p]);
  }
  int cnt = 0;
  rep(i, 500){
    if(V[i] <500)cnt++;
  }
  cout << cnt << endl;
}

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout << "Case #" << tc+1 <<": ";
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n){
      cin >> v[i];
    }
    int cnt = 0;
    rep(i, n/2){
      if(v[i] <500)cnt++;
    }
    if(cnt <= 251){
      cout <<"GOOD" <<endl;
    }
    else cout <<"BAD" <<endl;
  }
  
  
  /*
  cout << "GOOD" <<endl;
  rep(i, 20)good();
  cout << "BAD" <<endl;
  rep(i, 20)bad();
  */
  return 0;
}
