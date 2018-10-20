#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lli;

const int INF = 1 << 29;

int n,m;
vector<lli> v[2];

void solve(){
  int ans = INF;
  
  sort(v[1].begin(), v[1].end());
  for(int i=0;i<(1<<m);i++){
    vector<lli> a;
    a = v[0];
    for(int j=0;j<m;j++){
      if((i & (1 << j)) != 0){
        for(int k=0;k<n;k++)
          a[k] ^= (1 << j);
      }
    }
    sort(a.begin(), a.end());
    bool f = true;
    for(int j=0;j<n;j++) {
      if(a[j] != v[1][j]){
        f = false;
        break;
      }
    }
    if(f){
      ans = min(ans, __builtin_popcount(i));
    }
  }

  if(ans == INF) cout << "NOT POSSIBLE" << endl;
  else cout << ans << endl;
}

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    cin >> n >> m;
    for(int i=0;i<2;i++){
      v[i].clear();
      for(int j=0;j<n;j++){
        string x;
        cin >> x;
        v[i].push_back(0);
        for(int k=0;k<m;k++){
          v[i][j] <<= 1;
          if(x[k] == '1') v[i][j] += 1;
        }
      }
    }
    cout << "Case #" << t << ": " << flush;
    solve();
  }
}
