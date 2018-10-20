#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF = 1 << 29;

int doit(vector<string> A, vector<string> B, int k, int kMax) {
  int n = A.size();
  map<string, int> pA, pB;
  if (k == kMax) return 0;
  
  int ans = INF;
  rep(i, n) {
    pA[A[i].substr(0, k + 1)]++;
    pB[B[i].substr(0, k + 1)]++;
  }
  if (pA == pB) ans = min(ans, doit(A, B, k + 1, kMax));
  
  pB.clear();
  rep(i, n) {
    B[i][k] = (B[i][k] == '0' ? '1' : '0');
    pB[B[i].substr(0, k + 1)]++;
  }
  
  if (pA == pB) ans = min(ans, doit(A, B, k + 1, kMax) + 1);
  
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> outlet(n), device(n);

  rep(i, n) cin >> outlet[i];
  rep(i, n) cin >> device[i];

  int ans = doit(outlet, device, 0, k);
  
  if (ans == INF) {
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
