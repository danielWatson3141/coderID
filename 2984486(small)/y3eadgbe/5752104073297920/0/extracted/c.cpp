#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF = 1 << 29;

int stat[1000][1000];

unsigned int xor128(void) { 
  static unsigned int x = 123456789;
  static unsigned int y = 362436069;
  static unsigned int z = 521288629;
  static unsigned int w = 88675123; 
  unsigned int t;
 
  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

vector<int> gen_wrong(int N) {
  vector<int> A(N);
  rep(i, N)A[i] = i;
  rep(i, N) {
    swap(A[i], A[xor128() % N]);
  }
  return A;
}

vector<int> gen_correct(int N) {
  vector<int> A(N);
  rep(i, N)A[i] = i;
  random_shuffle(A.begin(), A.end());
  return A;
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);

  rep(i, N) {
    cin >> A[i];
  }

  double L = 0;
  rep(i, N) {
    L += log10((double)stat[i][A[i]] / 1000);
  }

  cerr << L << endl;

  cout << (L > 0.5 ? "BAD" : "GOOD") << endl;
}

int main() {
  rep(i, 1000000) {
    vector<int> A = gen_wrong(1000);
    rep(j, 1000) {
      stat[j][A[j]]++;
    }
  }

  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
