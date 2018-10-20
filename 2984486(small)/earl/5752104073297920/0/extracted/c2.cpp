#include <cassert>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

const int N = 1000;
const int ITERS = 200;

int freq[N][N];
int p[N];

void Bootstrap() {
  for (int i=0; i<N; ++i)
    for (int j=0; j<N; ++j)
      freq[i][j] = 0;
  for (int iter = 0; iter < N * ITERS; ++iter) {
    for (int i=0; i<N; ++i) p[i] = i;
    for (int i=0; i<N; ++i)
      swap(p[i], p[lrand48() % N]);
    for (int i=0; i<N ;++i)
      ++freq[i][p[i]];
  }
}

int main() {
  srand48(17);
  Bootstrap();
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    assert(n == N);
    for (int i=0; i<n; ++i) cin >> p[i];
    double score = 1.0;
    for (int i=0; i<n - 1; ++i) {
      score *= freq[i][p[i]];
      score /= ITERS;
    }
    bool bad = score > 1;
    cout << "Case #" << t << ": " << (bad ? "BAD" : "GOOD") << endl;
  }
  return 0;
}
