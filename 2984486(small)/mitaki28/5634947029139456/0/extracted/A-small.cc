#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const int INF = 1 << 28;

int main() {
    int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, L;
    cin >> N >> L;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < L; j++) {
        char c;
        cin >> c;
        a[i] = (a[i] << 1) | (c == '1');
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < L; j++) {
        char c;
        cin >> c;
        b[i] = (b[i] << 1) | (c == '1');
      }
    }
    sort(b.begin(), b.end());
    int r = INF;
    for (int k = 0; k < (1 << L); k++) {
      vector<ll> t = a;
      for (int i = 0; i < N; i++) {
        t[i] = t[i] ^ k;
      }
      sort(t.begin(), t.end());
      if (b == t) {
        r = min(r, __builtin_popcount(k));
      }
    }
    printf("Case #%d: ", t);
    if (r == INF) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", r);
    }
  }
}