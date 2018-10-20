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
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        ll v = a[i] ^ b[j];
        vector<ll> t = a;
        for (int k = 0; k < N; k++) {
          t[k] ^= v;
        }
        sort(t.begin(), t.end());
        if (b == t) {
          int x = 0;
          for (int i = 0; i < L; i++) {
            x += (v >> i) & 1;
          }
          r = min(r, x);
        }
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