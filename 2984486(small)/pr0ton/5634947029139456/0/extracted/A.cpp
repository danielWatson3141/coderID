#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define ll long long
int N, L;

ll mkLL() {
  string tmp; cin>>tmp;
  ll res = 0;
  for (int i=0; i < L; i++)
    res = (res<<1) + (tmp[i] - '0');
  return res;
}
int bitcount(ll v) {
  if (v == 0) return 0;
  return (v&1) + bitcount(v>>1);
}
int main() {
  int T; cin>>T;
  for (int i=1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    
    cin>>N>>L;
    vector<ll> from(N), to(N);
    set<ll> fset;
    for (int i=0; i < N; i++) {
      from[i] = mkLL();
      fset.insert( from[i] );
    }
    for (int i=0; i < N; i++) to[i] = mkLL();
    int INF = (int)2e9;
    int ans = INF;
    for (int i=0; i < N; i++)
    for (int j=0; j < N; j++) {
      ll diff = from[i] ^ to[j];
      bool valid = true;
      for (int k=0; k < N && valid; k++) {
        if (!fset.count(to[k] ^ diff)) {
          valid = false; 
        }
      }
      if (valid) {
        ans = min(ans, bitcount(diff));
      }
    }
    if (ans >= INF) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
}
