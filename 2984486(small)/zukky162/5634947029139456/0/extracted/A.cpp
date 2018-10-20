#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<28;

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    int N, L;
    cin >> N >> L;
    vector<string> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<string> v;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        string C(L, ' ');
        for(int k = 0; k < L; ++k) {
          if(A[i][k] == B[j][k]) {
            C[k] = '0';
          } else {
            C[k] = '1';
          }
        }
        v.push_back(C);
      }
    }
    int ans = INF;
    for(int i = 0; i < (int)v.size(); ++i) {
      vector<string> t;
      int cnt = count(v[i].begin(), v[i].end(), '1');
      for(int j = 0; j < N; ++j) {
        string s = A[j];
        for(int k = 0; k < L; ++k) {
          if(v[i][k] == '1') {
            if(s[k] == '0') s[k] = '1';
            else s[k] = '0';
          }
        }
        t.push_back(s);
      }
      sort(t.begin(), t.end());
      if(t == B) {
        ans = min(ans, cnt);
      }
    }
    cout << "Case #" << tc+1 << ": ";
    if(ans == INF) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
