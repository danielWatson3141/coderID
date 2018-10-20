#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long LL;

LL Read() {
  string buf;
  cin >> buf;
  LL res = 0;
  for (char c : buf)
    res = res * 2 + c - '0';
  return res;
}

int n, l;
LL A[200], B[200], C[200];

int main() {
  int Z;
  cin >> Z;
  for (int z = 1; z <= Z; ++z) {
    cin >> n >> l;
    for (int i = 0; i < n; ++i) A[i] = Read();
    for (int i = 0; i < n; ++i) B[i] = Read();
    
    vector<long long> to_check;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        to_check.push_back(A[i] ^ B[j]);
    sort(to_check.begin(), to_check.end());
    to_check.erase(unique(to_check.begin(), to_check.end()), to_check.end());
    
    int best = l + 1;

    for (LL t : to_check) {
      int count = 0;
      for (int i = 0; i < l; ++i) if ((t >> i)&1) ++count;
      for (int i = 0; i < n; ++i) C[i] = A[i] ^ t;
      sort(B, B+n);
      sort(C, C+n);
      bool ok = true;
      for (int i =0 ;i<n;++i) if (B[i]!=C[i]) ok=false;
      if (ok) best= min(best, count);
    }

    cout << "Case #" << z << ": ";
    if (best > l) cout << "NOT POSSIBLE" << endl; else cout << best << endl;

  }
  return 0;
}
